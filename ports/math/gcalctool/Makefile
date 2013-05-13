# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/math/gcalctool/Makefile,v 1.146 2013/03/09 09:12:38 kwm Exp $

PORTNAME=	gcalctool
PORTVERSION=	5.32.2
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 2 calculator tool based on the old calctool for OpenWindows

CONFLICTS=	gcalctool-6.[0-9]*

USE_BZIP2=	yes
USES=		bison gettext pathfix
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gconf2 gnomedocutils gnomeprefix gtk20 intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gcalctool.1
GLIB_SCHEMAS=	org.gnome.gcalctool.gschema.xml

.include <bsd.port.mk>
