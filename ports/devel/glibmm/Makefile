# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD: head/devel/glibmm/Makefile 313633 2013-03-08 10:51:34Z kwm $
#   $MCom: ports/trunk/devel/glibmm/Makefile 18692 2013-09-22 00:45:30Z kwm $

PORTNAME=	glibmm
PORTVERSION=	2.36.2
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib2

USE_XZ=		yes
NO_STAGE=	yes

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USES=		gettext gmake pathfix perl5 pkgconfig
USE_GNOME=	glib20 ltverhack libsigc++20
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static --disable-documentation

post-patch:
.for d in docs examples tests
	@${REINPLACE_CMD} -e '/^SUBDIRS = /s/${d}//' ${WRKSRC}/Makefile.in
.endfor

.include <bsd.port.mk>

.endif
