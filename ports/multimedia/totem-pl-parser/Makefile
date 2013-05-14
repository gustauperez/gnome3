# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/multimedia/totem-pl-parser/Makefile,v 1.51 2012/05/29 20:43:31 kwm Exp $

PORTNAME=	totem-pl-parser
PORTVERSION=	3.4.3
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

LIB_DEPENDS=	gmime-2.4.6:${PORTSDIR}/mail/gmime24 \
		soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gnomehier gnomeprefix \
		intlhack introspection:build libxml2 ltverhack
USES=		gettext pathfix
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-libarchive
CONFIGURE_ENV=	ARCHIVE_CFLAGS="-I/usr/include" \
		ARCHIVE_LIBS="-L/usr/lib -larchive"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	QUVI "Enable flash media stream URL support"  off

.include <bsd.port.options.mk>

.if defined(WITH_QUVI)
LIB_DEPENDS+=	quvi.7:${PORTSDIR}/multimedia/libquvi
CONFIGURE_ARGS+=--enable-quvi
.else
CONFIGURE_ARGS+=--enable-quvi=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|pkg_modules libarchive"|pkg_modules"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
