# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	epiphany-extensions
PORTVERSION=	3.6.0
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of add-ons for the Epiphany web browser

BUILD_DEPENDS=	epiphany>=3.6.0:${PORTSDIR}/www/epiphany3
LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3
RUN_DEPENDS=	epiphany>=3.6.0:${PORTSDIR}/www/epiphany3

CONFLICTS=	epiphany-extensions-2.[0-9]*

NO_STAGE=	yes
LATEST_LINK=	epiphany-extensions3
USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	gnomeprefix intlhack
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.epiphanyextensions.gschema.xml

EPHY_EXTENSIONS=really-all
EPHY_VERSION=	${PORTVERSION:R}

PLIST_SUB=	VERSION=${EPHY_VERSION} EPHY_VERSION=3.6

OPTIONS_DEFINE=	OPENSP
OPENSP_DESC=	OpenSP SGML support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSP}
CONFIGURE_ARGS+=	--enable-opensp=yes
LIB_DEPENDS+=		osp:${PORTSDIR}/textproc/opensp
.else
CONFIGURE_ARGS+=	--disable-opensp
.endif

CONFIGURE_ARGS+=--with-extensions="${EPHY_EXTENSIONS}"

post-patch:
	@${REINPLACE_CMD} -e 's|$$($$PKG_CONFIG --variable=extensionsdir epiphany-$$_epiphany_api_version)|${PREFIX}/lib/epiphany/${PORTVERSION:R}/extensions|g' \
		-e 's|$$($$PKG_CONFIG --variable=icondir epiphany-$$EPIPHANY_API_VERSION)|${PREFIX}/share/epiphany/icons|g' \
		${WRKSRC}/configure
# temp disable until autoscroller and permissions gets updated to new API.
	@${REINPLACE_CMD} -e 's|auto-scroller||g' -e 's|permissions||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
