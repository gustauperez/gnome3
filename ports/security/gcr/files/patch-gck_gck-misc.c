--- gck/gck-misc.c.orig	2013-05-05 20:06:05.931166952 +0000
+++ gck/gck-misc.c	2013-05-05 20:07:17.315684569 +0000
@@ -261,7 +261,7 @@
 
 /**
  * gck_list_unref_free: (skip)
- * @reflist: (element-type GLib.Object): list of Gobject reference counted pointers
+ * @reflist: (element-type GObject.Object): list of Gobject reference counted pointers
  *
  * Free a list of GObject based pointers. All objects in the list
  * will be unreffed and then the list itself will be freed.
@@ -279,13 +279,13 @@
 
 /**
  * gck_list_ref_copy: (skip)
- * @reflist: (element-type GLib.Object): list of GObject reference counted
+ * @reflist: (element-type GObject.Object): list of GObject reference counted
  *           objects
  *
  * Copy a list of GObject based pointers. All objects
  * in the list will be reffed and the list will be copied.
  *
- * Return value: (transfer full) (element-type GLib.Object): the copied and
+ * Return value: (transfer full) (element-type GObject.Object): the copied and
  *               reffed list, when done, free it with gck_list_unref_free ()
  **/
 GList *
