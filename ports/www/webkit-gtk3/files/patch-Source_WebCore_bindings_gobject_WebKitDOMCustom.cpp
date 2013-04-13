--- Source/WebCore/bindings/gobject/WebKitDOMCustom.cpp.orig	2013-04-13 12:40:26.003819947 +0000
+++ Source/WebCore/bindings/gobject/WebKitDOMCustom.cpp	2013-04-13 12:44:00.202972136 +0000
@@ -49,6 +49,18 @@
     return webkit_dom_blob_slice(self, start, end, content_type);
 }
 
+gchar*
+webkit_dom_html_element_get_class_name(WebKitDOMHTMLElement* element)
+{
+    return webkit_dom_element_get_class_name(WEBKIT_DOM_ELEMENT(element));
+}
+
+void
+webkit_dom_html_element_set_class_name(WebKitDOMHTMLElement* element, const gchar* value)
+{
+    webkit_dom_element_set_class_name(WEBKIT_DOM_ELEMENT(element), value);
+}
+
 void
 webkit_dom_html_form_element_dispatch_form_change(WebKitDOMHTMLFormElement* self)
 {
