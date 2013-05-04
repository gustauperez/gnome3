# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD: head/devel/libsoup/Makefile 313633 2013-03-08 10:51:34Z kwm $
#   $MCom: ports/trunk/devel/libsoup/Makefile 18399 2013-04-27 22:33:43Z kwm $

PORTNAME=	libsoup
PORTVERSION=	2.42.2
PORTREVISION?=	0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A SOAP (Simple Object Access Protocol) implementation in C

BUILD_DEPENDS=	glib-networking>=2.29.18:${PORTSDIR}/net/glib-networking
LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	glib-networking>=2.29.18:${PORTSDIR}/net/glib-networking

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

USES=		pathfix gettext
USE_GNOME=	gnomehier glib20 libxml2 ltverhack referencehack intltool
USE_SQLITE=	3
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-more-warnings
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="2.4"

.if defined(SOUP_SLAVE)
USE_SQLITE=	yes
LIB_DEPENDS+=	soup-2.4:${PORTSDIR}/devel/libsoup \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring
CONFIGURE_ARGS+=--with-gnome
.else
BUILD_DEPENDS+=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
CONFIGURE_ARGS+=--without-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

.if defined(SOUP_SLAVE)
do-build:
	cd ${WRKSRC}/libsoup && ${GMAKE} libsoup-gnome-2.4.la

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.la ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.so ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/libsoup/.libs/libsoup-gnome-2.4.so.1 ${PREFIX}/lib/
	cd ${WRKSRC}/libsoup && ${GMAKE} install-libsoupgnomeincludeHEADERS
.endif

post-install:
.if defined(SOUP_SLAVE)
	@${MKDIR} ${PREFIX}/libdata/pkgconfig
	@${INSTALL_DATA} ${WRKSRC}/libsoup-gnome-2.4.pc \
		${PREFIX}/libdata/pkgconfig/
.else
	@${INSTALL_DATA} ${WRKSRC}/libsoup/soup-connection.h \
	    	${PREFIX}/include/libsoup-2.4/libsoup/soup-connection.h
.endif

.include <bsd.port.mk>

.endif