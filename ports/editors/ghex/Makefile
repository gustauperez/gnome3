# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/editors/ghex/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	ghex
PORTVERSION=	2.24.0
PORTREVISION=	6
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 hex editor

CONFLICT=	ghex-3.\*

NO_STAGE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomedocutils gnomeprefix intlhack libgnomeui libgnomeprintui
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	ghex2.schemas

.include <bsd.port.mk>
