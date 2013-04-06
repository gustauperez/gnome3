--- Source/ThirdParty/gtest/include/gtest/internal/gtest-port.orig.h	2013-04-06 09:31:58.109275655 +0200
+++ Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h	2013-04-06 09:32:20.806273328 +0200
@@ -253,7 +253,13 @@
 
 // <regex.h> is not available on Windows.  Use our own simple regex
 // implementation instead.
-#define GTEST_USES_SIMPLE_RE 1
+#include <regex.h>  // NOLINT
+#include <strings.h>  // NOLINT
+#include <sys/types.h>  // NOLINT
+#include <time.h>  // NOLINT
+#include <unistd.h>  // NOLINT
+
+#define GTEST_USES_POSIX_RE 1
 
 #else
 
