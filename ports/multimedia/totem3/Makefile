# Created by: Hendrik Scholz <hendrik@scholz.net>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/totem3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	totem
PORTVERSION=	3.6.3
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A gstreamer-based video player for the GNOME 3 Desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	libgdata.so.13:${PORTSDIR}/devel/libgdata \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libclutter-gst-2.0.so:${PORTSDIR}/multimedia/clutter-gst \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3 \
		libpeas-1.0.so:${PORTSDIR}/devel/libpeas \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		gnome-settings-daemon>=2.91.0:${PORTSDIR}/sysutils/gnome-settings-daemon3 \
		gnome-icon-theme-symbolic>=2.91.0:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic

CONFLICTS=	totem-2.[0-9]*

NO_STAGE=	yes
LATEST_LINK=	totem3
USE_PYTHON=	yes
USE_XORG=	x11 xproto xtst ice sm
USE_XZ=		yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack gtk30 libxml2 nautilus3 ltverhack \
		pygobject3 gnomedocutils gnomehier introspection:build
USE_GSTREAMER1=	core good bad soup ugly
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-lXrandr" \
		BROWSER_PLUGIN_DIR="${WEBPLUGINS_DIR}"
CONFIGURE_ARGS=	--with-plugins="${TOTEM_PLUGINS}"

MAN1=		totem.1 totem-video-thumbnailer.1
GLIB_SCHEMAS=	org.gnome.totem.enums.xml \
		org.gnome.totem.gschema.xml \
		org.gnome.totem.plugins.opensubtitles.gschema.xml


OPTIONS_DEFINE=	LIRC BROWSER_PLUGINS PUBLISH
BROWSER_PLUGINS_DESC=	Plugins for gecko browser
PUBLISH_DESC=	Publish (network playlist) plugin
TRACKER_DESC=	Tracker local search plugin

OPTIONS_DEFAULT=BROWSER_PLUGINS

# check configure script for allowed_plugins="..." for new plugins
TOTEM_PLUGINS=	brasero-disc-recorder chapters dbusservice im-status gromit \
		iplayer media-player-keys ontop opensubtitles properties \
		screensaver screenshot sidebar-test skipto youtube

# pythonconsole samplepython
# vala rotation sample-vala
# nautilus save-file
# iplayer zeitgeist-dp grilo

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPUBLISH}
LIB_DEPENDS+=	libepc-1.0.so:${PORTSDIR}/www/libepc
PLIST_SUB+=	PUBLISH=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} publish
GLIB_SCHEMAS=	org.gnome.totem.enums.xml \
		org.gnome.totem.gschema.xml \
		org.gnome.totem.plugins.publish.gschema.xml \
		org.gnome.totem.plugins.opensubtitles.gschema.xml
.else
PLIST_SUB+=	PUBLISH="@comment "
.endif

#.if defined(WITH_TRACKER)
#LIB_DEPENDS+=	tracker-gtk:${PORTSDIR}/sysutils/tracker-libtrackergtk
#TOTEM_PLUGINS:=	${TOTEM_PLUGINS} tracker
#PLIST_SUB+=	TRACKER=""
#.else
PLIST_SUB+=	TRACKER="@comment "
#.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=	liblirc_client.so:${PORTSDIR}/comms/lirc
PLIST_SUB+=	LIRC=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} lirc
.else
PLIST_SUB+=	LIRC="@comment "
.endif

.if ${PORT_OPTIONS:MBROWSER_PLUGINS}
CONFIGURE_ARGS+=--enable-browser-plugins \
		--enable-gmp-plugin \
		--enable-narrowspace-plugin
PLIST_SUB+=	BROWSER_PLUGINS=""

USE_WEBPLUGINS=		webkit-gtk3
WEBPLUGINS_FILES=	libtotem-cone-plugin.so libtotem-gmp-plugin.so \
			libtotem-mully-plugin.so \
			libtotem-narrowspace-plugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.else
CONFIGURE_ARGS+=--disable-browser-plugins \
		--disable-basic-plugin \
		--disable-gmp-plugin \
		--disable-narrowspace-plugin
PLIST_SUB+=	BROWSER_PLUGINS="@comment "
.endif

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/cd0
.endif

pre-everything::
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"

post-patch:
	@${CP} -f ${FILESDIR}/pkg-message.in ${PKGMESSAGE}
#	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
#		${WRKSRC}/src/backend/bacon-video-widget-gst-0.10.c

post-install:
#	${MKDIR} ${PREFIX}/share/vala/vapi
#	${INSTALL_DATA} ${WRKSRC}/bindings/vala/totem.vapi ${PREFIX}/share/vala/vapi
#	${INSTALL_DATA} ${WRKSRC}/bindings/vala/totem.deps ${PREFIX}/share/vala/vapi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
