# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/graphics/clutter-gtk3/Makefile,v 1.11 2012/12/10 10:51:04 kwm Exp $

PORTNAME=	clutter-gtk
PORTVERSION=	1.4.0
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ Integration library for Clutter

LIB_DEPENDS=	clutter-1.0:${PORTSDIR}/graphics/clutter

LATEST_LINK=	clutter-gtk3
USE_XZ=		yes
USE_GMAKE=	yes
USES=		gettext pathfix
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gtk30 ltverhack
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
