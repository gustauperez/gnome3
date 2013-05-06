--- gcr/gcr-collection-model.c.orig	2013-05-05 20:08:01.147157928 +0000
+++ gcr/gcr-collection-model.c	2013-05-05 20:08:53.041229032 +0000
@@ -1587,7 +1587,7 @@
  *
  * Get a list of checked/selected objects.
  *
- * Returns: (transfer container) (element-type GLib.Object): a list of selected
+ * Returns: (transfer container) (element-type GObject.Object): a list of selected
  *          objects, which should be freed with g_list_free()
  */
 GList *
@@ -1611,7 +1611,7 @@
 /**
  * gcr_collection_model_set_selected_objects:
  * @self: the collection model
- * @selected: (element-type GLib.Object): a list of objects to select
+ * @selected: (element-type GObject.Object): a list of objects to select
  *
  * Set the checked/selected objects.
  */
