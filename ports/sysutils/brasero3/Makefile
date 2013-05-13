# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	brasero
PORTVERSION=	3.6.1
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify \
		totem-plparser.17:${PORTSDIR}/multimedia/totem-pl-parser \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3
RUN_DEPENDS=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		cdrdao:${PORTSDIR}/sysutils/cdrdao

CONFLICTS=	brasero-2.[0-9]*

LATEST_LINK=	brasero3
USES=		gettext pathfix
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	sm ice
USE_GNOME=	desktopfileutils gconf2 gnomedocutils gnomehack \
		gnomeprefix gtk30 intlhack libxml2
USE_LDCONFIG=	yes
USE_GSTREAMER1=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-inotify --enable-search=no --enable-playlist=no \
		--enable-introspection=yes
CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_CAM_LIB_H=1
LDFLAGS=	-L${LOCALBASE}/lib

MAN1=		brasero.1
GLIB_SCHEMAS=	org.gnome.brasero.gschema.xml

OPTIONS_DEFINE=	NAUTILUS LIBBURNIA
OPTIONS_DEFAULT=NAUTILUS
NAUTILUS_DESC=	Build nautilus extension
LIBBURNIA_DESC=	Build libburnia plug-ins

PLIST_SUB=	FULL_VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=	nautilus3
CONFIGURE_ARGS+=--enable-nautilus
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=--enable-nautilus=no
.endif

.if ${PORT_OPTIONS:MLIBBURNIA}
LIB_DEPENDS+=	burn.4:${PORTSDIR}/devel/libburn \
    		isofs.6:${PORTSDIR}/devel/libisofs
CONFIGURE_ARGS+=--enable-libburnia
PLIST_SUB+=	LIBBURNIA=""
.else
PLIST_SUB+=	LIBBURNIA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    	${WRKSRC}/libbrasero-burn/burn-process.c

.include <bsd.port.mk>
