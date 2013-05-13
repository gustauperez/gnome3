# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	libwnck
PORTVERSION=	3.4.4
PORTREVISION?=	0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

CONFLICTS=	libwnck-2.[0-9]*

LATEST_LINK=	libwnck3
USE_XORG=	xres x11
USE_GMAKE=	yes
USE_GNOME=	gtk30 intlhack ltverhack referencehack
USES=		bison gettext pathfix
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

.endif
