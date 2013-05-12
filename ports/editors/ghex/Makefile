# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghex
PORTVERSION=	2.24.0
PORTREVISION=	6
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 hex editor

CONFLICT=	ghex-3.\*

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomedocutils gnomeprefix intlhack \
		libgnomeprintui libgnomeui \
USES=		gettext pathfix
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	ghex2.schemas

.include <bsd.port.mk>
