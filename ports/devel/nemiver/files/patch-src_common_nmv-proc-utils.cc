--- src/common/nmv-proc-utils.cc.orig	2013-04-26 17:32:37.319388257 +0000
+++ src/common/nmv-proc-utils.cc	2013-04-26 17:32:55.733724655 +0000
@@ -28,15 +28,9 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <signal.h>
-#if defined(_GNU_SOURCE)
-# include <pty.h>
-#elif defined(__FreeBSD__)
-# include <sys/types.h>
-# include <sys/ioctl.h>
-# include <libutil.h>
-#elif defined(__OpenBSD__)
-#include <util.h>
-#endif
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <libutil.h>
 #include <termios.h>
 #include <vector>
 #include <memory>
