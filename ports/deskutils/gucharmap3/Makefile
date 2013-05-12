# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gucharmap
PORTVERSION=	3.6.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Unicode/ISO10646 character map and font viewer

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

CONFLICTS=	gucharmap-2.[0-9]*

USES=		gettext pathfix
LATEST_LINK=	gucharmap3
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomedocutils gtk30 intlhack
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-Bsymbolic
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Charmap.enums.xml org.gnome.Charmap.gschema.xml

.include <bsd.port.mk>
