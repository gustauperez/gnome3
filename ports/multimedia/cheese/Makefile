# Created by:					FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/multimedia/cheese/Makefile,v 1.68 2012/09/01 23:02:10 mezz Exp $
#

PORTNAME=	cheese
PORTVERSION=	2.32.0
PORTREVISION=	4
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Photobooth-inspired app for taking pictures and videos from webcam

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		hal.1:${PORTSDIR}/sysutils/hal

CONFLICTS=	cheese-3.[0-9]*

USE_XORG=	xxf86vm
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	evolutiondataserver gnomedocutils gnomedesktop gnomeprefix \
		intlhack librsvg2
USES=		gettext pathfix
USE_GSTREAMER=	gconf good ogg theora v4l2 vorbis
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCS=		AUTHORS COPYING ChangeLog NEWS README
GCONF_SCHEMAS=	cheese.schemas

post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor

.include <bsd.port.mk>
