--- macros2/gnome-autogen.sh.orig	2013-07-20 20:39:12.833920646 +0000
+++ macros2/gnome-autogen.sh	2013-07-20 20:39:44.650927269 +0000
@@ -354,6 +354,7 @@
     1.10*) automake_progs="automake-1.12 automake-1.11 automake-1.10" ;;
     1.11*) automake_progs="automake-1.12 automake-1.11" ;;
     1.12*) automake_progs="automake-1.12" ;;
+    1.14*) automake_progs="automake-1.14" ;;
 esac
 version_check automake AUTOMAKE "$automake_progs" $REQUIRED_AUTOMAKE_VERSION \
     "http://ftp.gnu.org/pub/gnu/automake/automake-$REQUIRED_AUTOMAKE_VERSION.tar.gz"
