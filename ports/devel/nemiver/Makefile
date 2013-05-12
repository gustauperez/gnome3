# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	nemiver
PORTVERSION=	0.9.3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A standalone graphical debugger that integrates with GNOME

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		${LOCALBASE}/lib/libboost_regex.a:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	gtop-2:${PORTSDIR}/devel/libgtop \
		gtkmm-3:${PORTSDIR}/x11-toolkits/gtkmm30

USE_XZ=		yes
USES=		gettext pathfix
USE_GNOME=	gconf2 glibmm gnomedocutils gnomeprefix gtk30 \
		gtksourceviewmm3 intlhack vte3
USE_GMAKE=	yes
USE_GCC=	4.6+
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	nemiver-dbgperspective.schemas \
		nemiver-workbench.schemas
MAN1=		nemiver.1

.include <bsd.port.mk>
