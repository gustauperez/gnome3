# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-themes-standard/Makefile,v 1.22 2012/10/19 17:46:37 kwm Exp $

PORTNAME=	gnome-themes-standard
PORTVERSION=	3.6.0.2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Standard themes for GNOME

CONFLICTS=	gnome-themes-2.[0-9]*

USE_XZ=		yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack gtk30 librsvg2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
