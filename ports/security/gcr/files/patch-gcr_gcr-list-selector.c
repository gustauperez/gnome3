--- gcr/gcr-list-selector.c.orig	2013-05-05 20:11:00.811143670 +0000
+++ gcr/gcr-list-selector.c	2013-05-05 20:11:30.144141192 +0000
@@ -396,7 +396,7 @@
  *
  * Get a list of selected objects.
  *
- * Returns: (transfer container) (element-type GLib.Object): the list of
+ * Returns: (transfer container) (element-type GObject.Object): the list of
  *          selected objects, to be released with g_list_free()
  */
 GList*
@@ -409,7 +409,7 @@
 /**
  * gcr_list_selector_set_selected:
  * @self: The selector
- * @selected: (element-type GLib.Object): the list of objects to select
+ * @selected: (element-type GObject.Object): the list of objects to select
  *
  * Select certain objects in the selector.
  */
