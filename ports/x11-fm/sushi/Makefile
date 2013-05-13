# Created by:	Gustau Pérez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#

PORTNAME=	sushi
PORTVERSION=	3.6.1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A tool similar to Gloobus Preview that provides quick file previews

BUILD_DEPENDS=	gcr>=3.4.1:${PORTSDIR}/security/gcr \
		${LOCALBASE}/libdata/pkgconfig/libmusicbrainz5.pc:${PORTSDIR}/audio/libmusicbrainz5 \
		${LOCALBASE}/libdata/pkgconfig/evince-document-3.0.pc:${PORTSDIR}/graphics/evince3
LIB_DEPENDS=	gcr:${PORTSDIR}/security/gcr \
		gjs.0:${PORTSDIR}/lang/gjs \
		clutter-gtk-1.0:${PORTSDIR}/graphics/clutter-gtk3 \
		clutter-gst-2.0:${PORTSDIR}/multimedia/clutter-gst \
		webkitgtk-3.0.0:${PORTSDIR}/www/webkit-gtk3 \
		musicbrainz5.0:${PORTSDIR}/audio/libmusicbrainz5
RUN_DEPENDS=	nautilus:${PORTSDIR}/x11-fm/nautilus3 \
		${LOCALBASE}/libdata/pkgconfig/evince-document-3.0.pc:${PORTSDIR}/graphics/evince3

USES=		gettext pathfix
INSTALLS_ICONS=	yes
USE_XZ=		yes
USE_GMAKE=	yes
USE_GCC=	4.6
USE_GNOME=	gnomeprefix gtksourceview3 intlhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CXX=		g++46
CPP=		gpp46
CC=		gcc46
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
