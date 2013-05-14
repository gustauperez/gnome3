# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD: head/devel/libgsf/Makefile 313549 2013-03-06 22:50:17Z kwm $
#   $MCom: ports/trunk/devel/libgsf/Makefile 18401 2013-04-28 12:15:27Z kwm $

PORTNAME=	libgsf
PORTVERSION=	1.14.26
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extensible I/O abstraction for dealing with structured file formats

USE_XZ=		yes
USE_GMAKE=	yes
USES=		gettext pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20 gnomeprefix intlhack introspection:build \
		libxml2 ltverhack
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gsf.1 gsf-office-thumbnailer.1 gsf-vba-dump.1

.include <bsd.port.mk>
