# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/libwnck3/Makefile 18569 2013-06-18 07:58:41Z kwm $

PORTNAME=	libwnck
PORTVERSION=	3.4.5
PORTREVISION?=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

USE_XZ=		yes
NO_STAGE=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification

LATEST_LINK=	libwnck3
USE_XORG=	xres x11
USE_GNOME=	gtk30 intlhack introspection ltverhack referencehack
USES=		bison gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-tools
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

.endif
