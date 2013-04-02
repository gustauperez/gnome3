--- src/procproperties.cpp.orig	2012-10-15 15:44:36.000000000 +0000
+++ src/procproperties.cpp	2013-04-02 08:32:44.485538063 +0000
@@ -26,7 +26,7 @@
 #include <glibtop/procstate.h>
 #if defined (__linux__)
 #include <asm/param.h>
-#elif defined (__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #endif
@@ -114,16 +114,16 @@
 
     get_process_memory_info(info);
 
-#if defined (__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
     struct clockinfo cinf;
     size_t size = sizeof (cinf);
     int HZ;
     int mib[] = { CTL_KERN, KERN_CLOCKRATE };
 
-    if (sysctl (mib, G_N_ELEMENTS (mib), &cinf, &size, NULL, 0) == -1)
+    if (sysctl (mib, 2, &cinf, &size, NULL, 0) == -1)
         HZ = 100;
     else
-        HZ = cinf.hz;
+        HZ = (cinf.stathz ? cinf.stathz : cinf.hz);
 #endif
 
     proc_arg proc_props[] = {
