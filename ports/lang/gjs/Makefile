# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/lang/gjs/Makefile,v 1.28 2012/10/18 08:57:51 kwm Exp $

PORTNAME=	gjs
PORTVERSION=	1.34.0
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		cairo:${PORTSDIR}/graphics/cairo \
		mozjs185:${PORTSDIR}/lang/spidermonkey185

CONFLICTS_BUILD=spidermonkey17-1.7.*

USE_XZ=		yes
USES=		gettext pathfix pkgconfig shebangfix
USE_GMAKE=	yes
USE_PYTHON_BUILD=yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	glib20 gnomeprefix introspection:build \
		intlhack ltverhack
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SHEBANG_FILES=	scripts/make-tests

.include <bsd.port.mk>
