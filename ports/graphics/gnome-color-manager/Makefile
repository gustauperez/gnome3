# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-color-manager
PORTVERSION=	3.6.0
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A session framework for the GNOME desktop to manage color profiles

BUILD_DEPENDS=	docbook2man:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410 \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	lcms2:${PORTSDIR}/graphics/lcms2 \
		colord:${PORTSDIR}/graphics/colord \
		colord-gtk:${PORTSDIR}/graphics/colord-gtk \
		canberra-gtk3:${PORTSDIR}/audio/libcanberra-gtk3 \
		exif:${PORTSDIR}/graphics/libexif

USE_XZ=		yes
USE_XORG=	xrandr
USES=		gettext pathfix pkgconfig
USE_GNOME=	desktopfileutils gnomedesktop3 gnomedocutils gnomeprefix \
		gtk30 intlhack vte3
USE_GMAKE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-clutter=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gcm-calibrate.1 gcm-import.1 gcm-inspect.1 gcm-picker.1 \
		gcm-viewer.1

OPTIONS_DEFINE=	RAW
OPTIONS_DEFAULT=RAW

RAW_DESC=	Enable RAW EXIF support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRAW}
LIB_DEPENDS+=	exiv2:${PORTSDIR}/graphics/exiv2
CONFIGURE_ARGS+=--enable-exiv=yes
PLIST_SUB+=	RAW=""
.else
CONFIGURE_ARGS+=--enable-exiv=no
PLIST_SUB+=	RAW="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wclobbered||g ; s|-Wempty-body||g ; \
		s|-Wignored-qualifiers||g ; s|-Wtype-limits||g ; \
		s|-Wmissing-parameter-type||g' \
			${WRKSRC}/configure

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
