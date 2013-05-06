--- src/daemon.c.orig	2013-03-12 22:42:05.000000000 +0000
+++ src/daemon.c	2013-05-03 16:59:58.694839493 +0000
@@ -77,6 +77,7 @@
         "games",
         "man",
         "at",
+        "saned",
         NULL
 };
 
@@ -409,7 +410,11 @@
 
         /* Every iteration */
         fp = *state;
+#ifdef HAVE_FGETPWENT
         pwent = fgetpwent (fp);
+#else
+	pwent = getpwent ();
+#endif
         if (pwent != NULL) {
                 return pwent;
         }
@@ -1135,20 +1140,18 @@
 
         sys_log (context, "create user '%s'", cd->user_name);
 
-        argv[0] = "/usr/sbin/useradd";
-        argv[1] = "-m";
-        argv[2] = "-c";
-        argv[3] = cd->real_name;
+        argv[0] = "/usr/sbin/pw";
+        argv[1] = "useradd";
+        argv[2] = cd->user_name;
+        argv[3] = "-m";
+        argv[4] = "-c";
+        argv[5] = cd->real_name;
         if (cd->account_type == ACCOUNT_TYPE_ADMINISTRATOR) {
-                argv[4] = "-G";
-                argv[5] = ADMIN_GROUP;
-                argv[6] = "--";
-                argv[7] = cd->user_name;
+                argv[6] = "-G";
+                argv[7] = "wheel";
                 argv[8] = NULL;
         }
         else if (cd->account_type == ACCOUNT_TYPE_STANDARD) {
-                argv[4] = "--";
-                argv[5] = cd->user_name;
                 argv[6] = NULL;
         }
         else {
@@ -1355,16 +1358,15 @@
         g_remove (filename);
         g_free (filename);
 
-        argv[0] = "/usr/sbin/userdel";
+        argv[0] = "/usr/sbin/pw";
         if (ud->remove_files) {
-                argv[1] = "-f";
-                argv[2] = "-r";
-                argv[3] = "--";
-                argv[4] = pwent->pw_name;
-                argv[5] = NULL;
+                argv[1] = "userdel";
+                argv[2] = pwent->pw_name;
+                argv[3] = "-r";
+                argv[4] = NULL;
         }
         else {
-                argv[1] = "--";
+                argv[1] = "userdel";
                 argv[2] = pwent->pw_name;
                 argv[3] = NULL;
         }
