#!/usr/bin/env qore

%require-our
%enable-all-warnings

const opts = (
    "help"            : "h,help"
    );

const ordinal = ( "first", "second", "third", "fourth", "fifth", "sixth", 
		  "seventh", "eighth", "ninth", "tenth" );

const spaces = "                                                                        ";

our ($o, $if);

sub usage()
{
    printf(
"usage: %s input_file class_name
  -h,--help                this help text
", basename($ENV."_"));
    exit(1);
}

sub command_line()
{
    my $g = new GetOpt(opts);
    $o = $g.parse(\$ARGV);
    if (exists $o."_ERRORS_")
    {
        printf("%s\n", $o."_ERRORS_"[0]);
        exit(1);
    }
    if ($o.help)
        usage();

    $if = shift $ARGV;

    if (!exists $if)
	usage();
}

sub dlh($l)
{
    my $str;
    foreach my $e in ($l)
	$str += sprintf("(%s) %s, ", $e.type, $e.name);
    return substr($str, 0, -2);
}

sub inlist($val, $list)
{
    foreach my $v in ($list)
        if ($val == $v)
            return True;
    return False;
}

sub main()
{
    command_line();

    # get prototype list
    if (!is_readable($if))
	throw "MISSING-FILE", sprintf("can't read input file '%s'", $if);

    my $f = new File();
    $f.open($if);
    my $x = $f.read(-1);
    $x =~ s/,\n/,/g;

    my $l = split("\n", $x);
    trim $l;

    my $proto = ();

    foreach my $p in ($l) {
	#printf("p=%n\n", $p);
	my $t = $p;
	$t =~ s/ \* /* /g;
	$t =~ s/ & /& /g;
	$t =~ s/const /const^/g;
	$t =~ s/  / /g;
	trim $t;

	# insert a space before "("
	$t =~ s/[~ ]\(/ (/;
	# rearrange " *" to be "* "
	$t =~ s/ \*/* /g;

	my ($rt, $name, $args) = $t =~ x/([a-zA-Z0-9\*<>:&]+) (\w+) \((.*)\)/;
	$rt =~ s/const\^//;
	$rt =~ s/\*//;
	$rt =~ s/&//;
	#printf("args=%n\n", $args);

	my $orig_args = trim($args);
	$args = split(",", $args);
	trim $args;

	if ($orig_args =~ /^( )*void( )*$/) {
	    delete $args;
	    delete $orig_args;
	}

	my $pos = 0;
	foreach my $arg in (\$args)
	{
	    # iterate pos for each iteration of the loop
	    on_exit $pos++;

	    my $is_const = ($arg =~ /const[ ^]/ && $arg !~ /\*/);
	    $arg =~ s/const[ ^]//;

	    my ($ra, $def) = $arg =~ x/(.*)=(.*)/;
	    if (exists $def) {
		$arg = trim($ra);
		trim $def;
		if ($def =~ /\|/)
		    delete $def;
	    }
	    my ($type, $pname) = $arg =~ x/([a-zA-Z0-9\*<>:&]+) (\w+)/;
	    if (!exists $type) {
		$type = $arg;
		if ($type == "int" || $type == "float")
		    $pname = "x";
		else if ($type == "bool")
		    $pname = "b";
		else {
		    $pname = sprintf("arg%d", $pos);
		    #$pname = tolower($arg);
		    #$pname =~ s/\*//g;
		    #$pname =~ s/&//g;
		    #$pname =~ s/.*:://;
		}
		$arg =~ s/&//;
	    }
	    my $ref;
	    if ($type =~ /&/) {
		$type =~ s/&//;
		$ref = True;
	    }
	    $arg = ( "type" : $type, "name" : $pname, "def" : $def, "ref" : $ref, "is_const" : $is_const );

	    my $typename = $type;
	    $typename =~ s/\*//g;
	    $typename =~ s/&//g;
	    if ($type =~ /\*/)
		$arg.is_ptr = True;
	    else if ($type =~ /float/i || $type =~ /double/i || $type == "GLclampf")
		$arg.is_float = True;
	    else if (!$ref && $type =~ /bool/)
		$arg.is_bool = True;
	    else if (!$ref && $type !~ /\*/ && $type !~ /&/)
		$arg.is_int = True;

	    #printf("%N\n", $arg);
	}

	if (!exists $proto.$name) {
	    my $funcname;
            $funcname = "f_" + $name;
	    $proto.$name = ( "funcname" : $funcname, "rt" : $rt, "inst" : () );
	}

	$proto.$name.inst += ( "args" : $args, "orig" : $p, "orig_args" : $orig_args );
    }

    my $of;
    foreach my $p in (keys $proto) {	
	# do function header
	$proto.$p.ok = True;
	my $lo = ();

	my $hdr = ();

	my $name = $p;

	for (my $i; $i < elements $proto.$p.inst; ++$i) {
	    my $inst = $proto.$p.inst[$i];
	    $inst.orig =~ s/ +/ /g;
	    $hdr += sprintf("//%s", $inst.orig);
        }
        $lo += sprintf("static AbstractQoreNode *%s(const QoreListNode *params, ExceptionSink *xsink)", 
		       $proto.$p.funcname);
	$lo += "{";

        my $callstr = $p + "(";
	$lo += do_single_function($name, \$proto.$p, $proto.$p.inst[0], $callstr);

	$lo += "}";

	$proto.$p.code = $hdr + $lo; 
    
	#printf("%-15s %-20s (%s)\n", "(" + $rt + ")", $name, dlh($args));
    }

    $of = stdout;

    foreach my $p in (keys $proto) {
	if (!$proto.$p.ok)
            $of.printf("/*\n");
	foreach my $line in ($proto.$p.code)
	    $of.printf("%s\n", $line);
	if (!$proto.$p.ok)
            $of.printf("*/\n");
	$of.printf("\n");

    }

    foreach my $p in (keys $proto) {    
	$of.printf("   %sbuiltinFunctions.add(\"%-30s %s);\n", $proto.$p.ok ? "" : "//", $p+"\",", $proto.$p.funcname);
    }

}


sub cl_order($l, $r) 
{
    return elements $l.args < $r.args ? 1 : -1;
}

sub all_default($l)
{
    foreach my $arg in ($l)
	if (!exists $arg.def)
	    return False;

    return True;
}

sub do_single_arg($offset, $name, $arg, $i, $ok)
{
    my $lo = ();
    my $os = substr(spaces, 0, $offset);

    if (exists $arg.special) {
	my $c = $arg.special;
	$lo += $c($arg);
    } 
    else
	switch ($arg.type) {
	
	    case "GLuint":
		case "uint": {
		    if (exists $arg.def)
			$lo += sprintf("unsigned %s = !is_nothing(p) ? p->getAsBigInt() : %s;", $arg.name, $arg.def);
		    else
			$lo += sprintf("unsigned %s = p ? p->getAsBigInt() : 0;", $arg.name);
	    }
	    break;

	    case "GLint":
	    case "int": {
		if (exists $arg.def)
		    $lo += sprintf("int %s = !is_nothing(p) ? p->getAsInt() : %s;", $arg.name, $arg.def);
		else
		    $lo += sprintf("int %s = p ? p->getAsInt() : 0;", $arg.name);
		break;
	    }
	    case "bool": {
		if ($arg.def =~ /true/)
		    $lo += sprintf("bool %s = !is_nothing(p) ? p->getAsBool() : true;", $arg.name);
		else
		    $lo += sprintf("bool %s = p ? p->getAsBool() : false;", $arg.name);
		break;
	    }
	    case "double":
	    {
		$lo += sprintf("double %s = p ? p->getAsFloat() : 0.0;", $arg.name);
		break;
	    }
	    case "float": {
		$lo += sprintf("float %s = p ? p->getAsFloat() : 0.0;", $arg.name);
		break;
	    }
	    case "char*": {
		if (exists $arg.def)
		    $lo = sprintf("const char *%s = (p && p->getType() == NT_STRING) ? reinterpret_cast<const QoreStringNode *>(p)->getBuffer() : %s;", $arg.name, trim($arg.def));
		else {
		    $lo += "if (!p || p->getType() != NT_STRING) {";
		    $lo += sprintf("   xsink->raiseException(\"%s-PARAM-ERROR\", \"expecting a string as %s argument to %s()\");", 
				   toupper($name), ordinal[$i], $name);
		    
		    $lo += "   return 0;";
		    $lo += "}";
		    $lo += sprintf("const char *%s = reinterpret_cast<const QoreStringNode *>(p)->getBuffer();", $arg.name);
		}
		break;
	    }
	    case "char": {
		if (exists $arg.def)
		    $lo = sprintf("const char %s = p && p->getType() == NT_STRING ? reinterpret_cast<const QoreStringNode *>(p)->getBuffer()[0] : %s;", $arg.name, trim($arg.def));
		else {
		    $lo += "if (!p || p->getType() != NT_STRING) {";
		    $lo += sprintf("   xsink->raiseException(\"%s-PARAM-ERROR\", \"expecting a string as %s argument to %s()\");", 
				   toupper($name), ordinal[$i], $name);
		    
		    $lo += "   return 0;";
		    $lo += "}";
		    $lo += sprintf("const char %s = reinterpret_cast<const QoreStringNode *>(p)->getBuffer()[0];", $arg.name);
		}
		break;
	    }
   
	  default: {
	      if ($arg.is_int) {
		  my $tn = $arg.type;
		  my $def = $arg.def;
		  if (exists $arg.def)
		      $lo += sprintf("%s %s = !is_nothing(p) ? (%s)p->getAsInt() : %s;", $tn, $arg.name, $tn, $def);
		  else
		      $lo += sprintf("%s %s = (%s)(p ? p->getAsInt() : 0);", $tn, $arg.name, $tn);
	      } 
	      else if ($arg.is_float) {
		  my $tn = $arg.type;
		  my $def = $arg.def;
		  if (exists $arg.def)
		      $lo += sprintf("%s %s = !is_nothing(p) ? (%s)p->getAsFloat() : %s;", $tn, $arg.name, $tn, $def);
		  else
		      $lo += sprintf("%s %s = (%s)(p ? p->getAsFloat() : 0.0);", $tn, $arg.name, $tn);
	      }
	      else if ($arg.is_bool) {
		  my $tn = $arg.type;
		  my $def = $arg.def;
		  if (exists $arg.def)
		      $lo += sprintf("%s %s = !is_nothing(p) ? (%s)p->getAsBool() : %s;", $tn, $arg.name, $tn, $def);
		  else
		      $lo += sprintf("%s %s = (%s)(p ? p->getAsBool() : false);", $tn, $arg.name, $tn);
	      }
	      else {
		  #printf("DEBUG err arg=%n\n", $arg);
		  $lo += sprintf("??? %s %s = p;", $arg.type, $arg.name);
		  $ok = False;
	      }
	      break;
	    }
        }
    
    foreach my $str in (\$lo)
	$str = $os + $str;

    return $lo;
}

sub append_call($cs, $arg)
{
    #if (exists $arg.classname && $arg.type =~ /\*/ && inlist($arg.classname, const_class_list))
	#$cs += sprintf("*(%s), ", exists $arg.get ? $arg.get : $arg.name);
    #else 
    #printf("arg=%n, call=%n\n", $arg, $cs);
    if (($arg.is_class || $arg.is_abstract_class) && !$arg.special_arg && $arg.def == "0")
	$cs += sprintf("%s ? %s : 0, ", $arg.name, exists $arg.get ? $arg.get : $arg.name);
    else
	$cs += sprintf("%s, ", exists $arg.get ? $arg.get : $arg.name);
}

sub do_single_function($name, $func, $inst, $callstr)
{
    my $lo = ();

    # do arguments
    for (my $i = 0; $i < elements $inst.args; ++$i) {
	$lo += sprintf("   %sp = get_param(params, %d);", $i ? "" : "const AbstractQoreNode *", $i);
	
	$lo += do_single_arg(3, $name, $inst.args[$i], $i, \$func.ok, !exists $func.rt);

	append_call(\$callstr, $inst.args[$i]);
    }
    if (elements $inst.args)
	splice $callstr, -2, 2, ")";
    else
	$callstr += ")";

    $lo += do_return_value(3, $func.rt, $callstr, \$func.ok, !exists $func.rt);
    
    return $lo;
}

sub do_return_value($offset, $rt, $callstr, $ok)
{
    my $lo = ();
    my $os = substr(spaces, 0, $offset);

    switch ($rt) {
	case "void": {
	    $lo += sprintf("%s;", $callstr);
	    $lo += "return 0;"; 
	    break;
	}
	case "GLboolean":
	case "bool": {
	    $lo += sprintf("return get_bool_node(%s);", $callstr); 
	    break;
	}
	case =~ m/::/:
	    case "uint":
	    case "ushort":
	    case "short":
	    case "ulong":
	    case "GLint":
	    case "GLuint":
	    case "GLenum":
	    case "int": {
		$lo += sprintf("return new QoreBigIntNode(%s);", $callstr); 
		break;
	}
	case "double":
	case "GLfloat":
	case "GLdouble":
	case "float" : {
		$lo += sprintf("return new QoreFloatNode(%s);", $callstr); 
		break;
	}

	case "char": {
	    $lo += sprintf("const char c_rv = %s;", $callstr);
	    $lo += "QoreStringNode *rv_str = new QoreStringNode();";
	    $lo += "rv_str->concat(c_rv);";
	    $lo += "return rv_str;";
	    break;
	}


      default: {
	  #printf("rt=%s il=%n cs=%n\n", $rt, inlist($rt, qobject_list), $callstr);
	  
	  if ($rt !~ /\*/)
	      $lo += sprintf("??? return new QoreBigIntNode(%s);", $callstr);
	  else
	      $lo += sprintf("??? return %s;", $callstr); 
	  $ok = False;
	  break;
	}
    }

    foreach my $str in (\$lo)
	$str = $os + $str;

    return $lo;
}

main();
