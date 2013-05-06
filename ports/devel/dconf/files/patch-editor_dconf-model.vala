--- editor/dconf-model.vala.orig	2012-11-01 15:03:15.000000000 +0000
+++ editor/dconf-model.vala	2013-05-06 07:24:07.000000000 +0000
@@ -341,8 +341,10 @@
         return (Key)iter.user_data;
     }
 
-    public bool get_iter(ref Gtk.TreeIter iter, Gtk.TreePath path)
+    public bool get_iter(out Gtk.TreeIter iter, Gtk.TreePath path)
     {
+	iter = Gtk.TreeIter ();
+
         if (path.get_depth() != 1)
             return false;
 
@@ -391,8 +393,10 @@
         return true;
     }
 
-    public bool iter_children(ref Gtk.TreeIter iter, Gtk.TreeIter? parent)
+    public bool iter_children(out Gtk.TreeIter iter, Gtk.TreeIter? parent)
     {
+	iter = Gtk.TreeIter ();
+
         if (parent != null || directory.keys.length() == 0)
             return false;
         set_iter(ref iter, directory.keys.nth_data(0));
@@ -412,8 +416,10 @@
             return 0;
     }
 
-    public bool iter_nth_child(ref Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
+    public bool iter_nth_child(out Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
     {
+	iter = Gtk.TreeIter ();
+
         if (parent != null)
             return false;
 
@@ -423,8 +429,10 @@
         return true;
     }
 
-    public bool iter_parent(ref Gtk.TreeIter iter, Gtk.TreeIter child)
+    public bool iter_parent(out Gtk.TreeIter iter, Gtk.TreeIter child)
     {
+	iter = Gtk.TreeIter ();
+
         return false;
     }
 
@@ -479,8 +487,10 @@
         return (SchemaValue)iter.user_data;
     }
 
-    public bool get_iter(ref Gtk.TreeIter iter, Gtk.TreePath path)
+    public bool get_iter(out Gtk.TreeIter iter, Gtk.TreePath path)
     {
+	iter = Gtk.TreeIter ();
+
         if (path.get_depth() != 1)
             return false;
 
@@ -513,8 +523,10 @@
         return true;
     }
 
-    public bool iter_children(ref Gtk.TreeIter iter, Gtk.TreeIter? parent)
+    public bool iter_children(out Gtk.TreeIter iter, Gtk.TreeIter? parent)
     {
+	iter = Gtk.TreeIter ();
+
         if (parent != null || schema_enum.values.length() == 0)
             return false;
         set_iter(ref iter, schema_enum.values.nth_data(0));
@@ -534,8 +546,10 @@
             return 0;
     }
 
-    public bool iter_nth_child(ref Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
+    public bool iter_nth_child(out Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
     {
+	iter = Gtk.TreeIter ();
+
         if (parent != null)
             return false;
 
@@ -545,8 +559,10 @@
         return true;
     }
 
-    public bool iter_parent(ref Gtk.TreeIter iter, Gtk.TreeIter child)
+    public bool iter_parent(out Gtk.TreeIter iter, Gtk.TreeIter child)
     {
+	iter = Gtk.TreeIter ();
+
         return false;
     }
 
@@ -639,8 +655,10 @@
             return (Directory)iter.user_data;
     }
 
-    public bool get_iter(ref Gtk.TreeIter iter, Gtk.TreePath path)
+    public bool get_iter(out Gtk.TreeIter iter, Gtk.TreePath path)
     {
+	iter = Gtk.TreeIter ();
+
         if (!iter_nth_child(out iter, null, path.get_indices()[0]))
             return false;
 
@@ -679,8 +697,10 @@
         return true;
     }
 
-    public bool iter_children(ref Gtk.TreeIter iter, Gtk.TreeIter? parent)
+    public bool iter_children(out Gtk.TreeIter iter, Gtk.TreeIter? parent)
     {
+	iter = Gtk.TreeIter ();
+
         Directory directory = get_directory(parent);
         if (directory.children.length() == 0)
             return false;
@@ -698,8 +718,10 @@
         return (int) get_directory(iter).children.length();
     }
 
-    public bool iter_nth_child(ref Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
+    public bool iter_nth_child(out Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
     {
+	iter = Gtk.TreeIter ();
+
         Directory directory = get_directory(parent);
         if (n >= directory.children.length())
             return false;
@@ -707,8 +729,10 @@
         return true;
     }
 
-    public bool iter_parent(ref Gtk.TreeIter iter, Gtk.TreeIter child)
+    public bool iter_parent(out Gtk.TreeIter iter, Gtk.TreeIter child)
     {
+	iter = Gtk.TreeIter ();
+
         Directory directory = get_directory(child);
         if (directory.parent == root)
             return false;
