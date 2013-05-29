--- utils/cups-browsed.c.old	2013-05-28 12:13:55.837170788 +0000
+++ utils/cups-browsed.c	2013-05-28 12:14:21.931314225 +0000
@@ -23,6 +23,9 @@
 
 #include <ctype.h>
 #include <errno.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#endif /* __FreeBSD__ */
 #include <ifaddrs.h>
 #if defined(__OpenBSD__)
 #include <sys/socket.h>
