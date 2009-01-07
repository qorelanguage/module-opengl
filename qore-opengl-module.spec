%define module_api %(qore --module-api 2>/dev/null)
%define module_dir %(qore --module-dir 2>/dev/null)

%if 0%{?sles_version}

%define dist .sles{?sles_version}

%else
%if 0%{?suse_version}

%if 0%{?suse_version} == 1110
%define dist .opensuse11_1
%endif

%if 0%{?suse_version} == 1100
%define dist .opensuse11
%endif

%if 0%{?suse_version} == 1030
%define dist .opensuse10_3
%endif

%if 0%{?suse_version} == 1020
%define dist .opensuse10_2
%endif

%if 0%{?suse_version} == 1010
%define dist .suse10_1
%endif

%if 0%{?suse_version} == 1000
%define dist .suse10
%endif

%if 0%{?suse_version} == 930
%define dist .suse9_3
%endif

%endif
%endif

Summary: OpenGL Module for Qore
Name: qore-opengl-module
Version: 0.0.3
Release: 1%{dist}
License: LGPL
Group: Development/Languages
URL: http://www.qoretechnologies.com/qore
Source: http://prdownloads.sourceforge.net/qore/%{name}-%{version}.tar.gz
Source0: %{name}-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root
Requires: /usr/bin/env
Requires: qore-module-api-%{module-api}
BuildRequires: gcc-c++
BuildRequires: qore-devel
%if 0%{?suse_version}
Requires: Mesa
BuildRequires: Mesa-devel
%else
Requires: mesa-libGL
BuildRequires: mesa-libGL-devel
BuildRequires: mesa-libGLU-devel
%endif
BuildRequires: qore

%description
This module provides functionality enabling qore scripts/programs to use OpenGL
functionality.


%if 0%{?suse_version}
%debug_package
%endif

%prep
%setup -q
%ifarch x86_64 ppc64 x390x
c64=--enable-64bit
%endif
./configure RPM_OPT_FLAGS="$RPM_OPT_FLAGS" --prefix=/usr --disable-debug $c64

%build
%{__make}

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/%{module_dir}
mkdir -p $RPM_BUILD_ROOT/usr/share/doc/qore-opengl-module
make install DESTDIR=$RPM_BUILD_ROOT

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
%{module_dir}/opengl-api-%{module_api}.qmod
%doc COPYING README RELEASE-NOTES ChangeLog AUTHORS docs/opengl-module-doc.html

%changelog
* Wed Jan 7 2009 David Nichols <david_nichols@users.sourceforge.net>
- updated to version 0.0.3

* Tue Sep 2 2008 David Nichols <david_nichols@users.sourceforge.net>
- initial spec file for separate opengl release
