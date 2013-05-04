# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD: head/devel/gobject-introspection/Makefile 314706 2013-03-20 02:39:49Z mezz $
#   $MCom: ports/trunk/devel/gobject-introspection/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	gobject-introspection
PORTVERSION=	1.36.0
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generate interface introspection data for GObject libraries

# we need cairo otherwise the generated Cairo gir is broken
BUILD_DEPENDS=	cairo-trace:${PORTSDIR}/graphics/cairo
LIB_DEPENDS=	ffi:${PORTSDIR}/devel/libffi

USES=		bison pathfix pkgconfig gettext
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier glib20 ltverhack
USE_PYTHON=	-2.7
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-tests

# Force it to put the .cache in ${WRKSRC} instead of ~/.cache. ports/143260
MAKE_ENV=	HOME=${WRKDIR}

MAN1=		g-ir-compiler.1 g-ir-generate.1 g-ir-scanner.1

.include <bsd.port.mk>