--- gcr/gcr-collection.c.orig	2013-05-05 20:09:37.986148675 +0000
+++ gcr/gcr-collection.c	2013-05-05 20:10:25.562821284 +0000
@@ -65,7 +65,7 @@
 		/**
 		 * GcrCollection::added:
 		 * @self: the collection
-		 * @object: (type GLib.Object): object that was added
+		 * @object: (type GObject.Object): object that was added
 		 *
 		 * This signal is emitted when an object is added to the collection.
 		 */
@@ -77,7 +77,7 @@
 		/**
 		 * GcrCollection::removed:
 		 * @self: the collection
-		 * @object: (type GLib.Object): object that was removed
+		 * @object: (type GObject.Object): object that was removed
 		 *
 		 * This signal is emitted when an object is removed from the collection.
 		 */
@@ -117,7 +117,7 @@
  *
  * Get a list of the objects in this collection.
  *
- * Returns: (transfer container) (element-type GLib.Object): a list of the objects
+ * Returns: (transfer container) (element-type GObject.Object): a list of the objects
  *          in this collection, which should be freed with g_list_free()
  */
 GList*
