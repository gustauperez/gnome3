# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evince
PORTVERSION=	2.32.0
PORTREVISION=	10
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 multi-format document viewer

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	poppler-glib.8:${PORTSDIR}/graphics/poppler-glib \
		spectre.1:${PORTSDIR}/print/libspectre
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		yelp:${PORTSDIR}/x11/yelp

CONFLICTS=	evince-3.[0-9]*

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
USES=		gettext gmake pathfix
INSTALLS_OMF=	yes
USE_GNOME=	desktopfileutils gconf2 gnomedocutils gnomeprefix \
		intlhack ltasneededhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml
GCONF_SCHEMAS=	evince-thumbnailer.schemas \
		evince-thumbnailer-ps.schemas

PLIST_SUB+=	VERSION=2.32

MAN1=		evince.1

OPTIONS=	DVI		"Enable DVI viewer support"		off \
		T1LIB		"Enable T1LIB for TYPE1 fonts to DVI (Enables DVI)"	off \
		NAUTILUS	"Enable Nautilus plugin"		on  \
		KEYRING		"Enable Gnome-Keyring without Nautilus" on \
		DBUS		"Enable D-BUS support"			on \
		COMICS		"Enable comic book archives support"	on \
		IMPRESS		"Enable Impress presentations support"	off \
		DJVU		"Enable DJVU support"			off

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) || exists(${LOCALBASE}/lib/libdbus-glib-1.so)
WITH_DBUS=	yes
.endif

.if defined(WITH_DVI) || defined(WITH_T1LIB) || exists(${LOCALBASE}/lib/libkpathsea.a)
USE_TEX=	yes

CONFIGURE_ARGS+=	--enable-dvi
GCONF_SCHEMAS+=	evince-thumbnailer-dvi.schemas
PLIST_SUB+=		DVI=""
. if defined(WITH_T1LIB)
LIB_DEPENDS+=	t1.5:${PORTSDIR}/devel/t1lib

CONFIGURE_ARGS+=	--enable-t1lib
. endif
.else
PLIST_SUB+=		DVI="@comment "
.endif

.if !defined(WITHOUT_NAUTILUS)
USE_GNOME+=		nautilus2
CONFIGURE_ARGS+=	--enable-nautilus
PLIST_SUB+=		NAUTILUS=""
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
RUN_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
.if !defined(WITHOUT_KEYRING)
LIB_DEPENDS+=	gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
.else
CONFIGURE_ARGS+=	--without-keyring
.endif
CONFIGURE_ARGS+=	--disable-nautilus
PLIST_SUB+=		NAUTILUS="@comment "
.endif

.if defined(WITH_IMPRESS)
CONFIGURE_ARGS+=	--enable-impress
PLIST_SUB+=		IMPRESS=""
.else
CONFIGURE_ARGS+=	--disable-impress
PLIST_SUB+=		IMPRESS="@comment "
.endif

.if defined(WITH_DJVU)
LIB_DEPENDS+=		djvulibre:${PORTSDIR}/graphics/djvulibre
CONFIGURE_ARGS+=	--enable-djvu
GCONF_SCHEMAS+=		evince-thumbnailer-djvu.schemas
PLIST_SUB+=		DJVU=""
.else
CONFIGURE_ARGS+=	--disable-djvu
PLIST_SUB+=		DJVU="@comment "
.endif

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
.endif

.if !defined(WITHOUT_COMICS)
RUN_DEPENDS+=		unzip:${PORTSDIR}/archivers/unzip
CONFIGURE_ARGS+=	--enable-comics
GCONF_SCHEMAS+=		evince-thumbnailer-comics.schemas
PLIST_SUB+=		COMICS=""
.else
CONFIGURE_ARGS+=	--disable-comics
PLIST_SUB+=		COMICS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g' \
		-e 's|" == "|" = "|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^DOC_MODULE_VERSION/d' \
		${WRKSRC}/help/reference/libdocument/Makefile.in \
		${WRKSRC}/help/reference/libview/Makefile.in

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
