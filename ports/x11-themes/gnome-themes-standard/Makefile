# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	gnome-themes-standard
PORTVERSION=	3.6.2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Standard themes for GNOME

CONFLICTS=	gnome-themes-2.[0-9]*

USES=		gettext pathfix
USE_XZ=		yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gtk30 intlhack librsvg2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
