--- Source/WebCore/bindings/gobject/WebKitDOMCustom.h.orig	2013-04-13 08:56:32.862747269 +0000
+++ Source/WebCore/bindings/gobject/WebKitDOMCustom.h	2013-04-13 08:56:47.458751834 +0000
@@ -30,6 +30,8 @@
 
 /* Compatibility */
 WEBKIT_API WebKitDOMBlob* webkit_dom_blob_webkit_slice(WebKitDOMBlob* self, gint64 start, gint64 end, const gchar* content_type);
+WEBKIT_API gchar* webkit_dom_html_element_get_class_name(WebKitDOMHTMLElement* element);
+WEBKIT_API void webkit_dom_html_element_set_class_name(WebKitDOMHTMLElement* element, const gchar* value);
 WEBKIT_API void webkit_dom_html_form_element_dispatch_form_change(WebKitDOMHTMLFormElement* self);
 WEBKIT_API void webkit_dom_html_form_element_dispatch_form_input(WebKitDOMHTMLFormElement* self);
 
