# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-search-tool
PORTVERSION=	3.6.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 file search utilities

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

CONFLICTS=	gnome-utils-2.[0-9]*

USES=		gettext pathfix
USE_XZ=		yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gconf2 gnomedocutils gnomeprefix gtk30 intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gnome-search-tool.1
GLIB_SCHEMAS=	org.gnome.gnome-search-tool.gschema.xml

.include <bsd.port.mk>
