# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	gnome-backgrounds
PORTVERSION=	3.6.1
CATEGORIES=	x11-themes graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of backgrounds for GNOME

USES=		gettext pathfix
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
