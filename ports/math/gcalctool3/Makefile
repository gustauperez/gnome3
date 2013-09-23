# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/math/gcalctool3/Makefile,v 1.19 2013/03/09 09:12:38 kwm Exp $

PORTNAME=	gcalctool
PORTVERSION=	6.6.2
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 3 calculator tool based on the old calctool for OpenWindows

CONFLICTS=	gcalctool-5.[0-9]*

BUILD_DEPENDS=	yelp-build:${PORTSDIR}/textproc/yelp-tools \
		itstool:${PORTSDIR}/textproc/itstool

NO_STAGE=	yes
LATEST_LINK=	gcalctool3
USE_XZ=		yes
USES=		bison gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gconf2 gnomeprefix gtk30 intlhack libxml2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gcalccmd.1 gcalctool.1
GLIB_SCHEMAS=	org.gnome.gcalctool.gschema.xml

.include <bsd.port.mk>
