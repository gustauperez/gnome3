# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net-im/folks/Makefile,v 1.30 2013/03/12 19:52:18 kwm Exp $

PORTNAME=	folks
PORTVERSION=	0.8.0
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	gee-0.8.2:${PORTSDIR}/devel/libgee \
		gcr:${PORTSDIR}/security/gcr \
		zeitgeist-1.0:${PORTSDIR}/sysutils/libzeitgeist \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib

CONFLICTS=	folks-0.4.[0-9]*

USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USES=		gettext pathfix
USE_GNOME=	evolutiondataserver3 gnomehier intlhack \
		introspection:build ltverhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.freedesktop.folks.gschema.xml

PLIST_SUB=	LIBVER=25 VERSION=37

#OPTIONS=	SOCIALWEB "Enable social web backend" on

#.include <bsd.port.options.mk>

#.if defined(WITH_SOCIALWEB)
#LIB_DEPENDS+=	socialweb.0:${PORTSDIR}/www/libsocialweb
#CONFIGURE_ARGS+=--enable-libsocialweb-backend=yes
#.else
CONFIGURE_ARGS+=--enable-libsocialweb-backend=no
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^build_old_libs=yes|build_old_libs=no|g' \
		${WRKDIR}/gnome-libtool

.include <bsd.port.mk>
