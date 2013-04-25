--- src/libexchangemapi/e-mapi-cal-utils.c.orig	2013-04-25 07:27:35.123845464 +0000
+++ src/libexchangemapi/e-mapi-cal-utils.c	2013-04-25 07:27:47.075845821 +0000
@@ -462,6 +462,7 @@
 	gchar *start = NULL, *end = NULL;
 	time_t start_date, end_date;
 	icalcomponent *icalcomp = NULL;
+	int daylight = 0;
 
 	if (!bin)
 		return;
