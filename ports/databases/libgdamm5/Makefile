# New ports collection makefile for:    libglademm
# Date created:         1 Oct 2003
# Whom:                 Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/libgdamm5/Makefile,v 1.2 2011/12/17 18:51:18 kwm Exp $
#

PORTNAME=	libgdamm
PORTVERSION=	4.99.6
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgda5 library

LIB_DEPENDS=	glibmm-2.4:${PORTSDIR}/devel/glibmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_AUTOTOOLS=	libtool
USE_XZ=		yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	libgda5 glibmm
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static --disable-documentation

OPTIONS=	BDB "Build the Berkely DB bindings also" off

.include <bsd.port.options.mk>

.if defined(WITH_BDB) || exists(${LOCALBASE}/libdata/pkgconfig/libgda-bdb-5.0.pc)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libgda-bdb-5.0.pc:${PORTSDIR}/databases/libgda5-bdb
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libgda-bdb-5.0.pc:${PORTSDIR}/databases/libgda5-bdb
PLIST_SUB+=	BDB=""
.else
PLIST_SUB+=	BDB=""
.endif

.include <bsd.port.mk>
