--- src/libexchangemapi/e-mapi-defs.h.orig	2013-04-25 07:29:26.957838132 +0000
+++ src/libexchangemapi/e-mapi-defs.h	2013-04-25 07:29:32.797836687 +0000
@@ -213,6 +213,7 @@
 #endif
 
 /* RECURRENCE (APPOINTMENTS/MEETINGS/TASKS) */
+/*
 typedef enum {
     rectypeNone = 0,
     rectypeDaily = 1,
@@ -220,7 +221,7 @@
     rectypeMonthly = 3,
     rectypeYearly = 4
 } OlRecurrenceType;
-
+*/
 typedef enum {
     olApptNotRecurring = 0,
     olApptMaster = 1,
