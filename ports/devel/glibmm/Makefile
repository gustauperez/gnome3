# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD: head/devel/glibmm/Makefile 313633 2013-03-08 10:51:34Z kwm $
#   $MCom: ports/trunk/devel/glibmm/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	glibmm
PORTVERSION=	2.36.0
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib2

USE_XZ=		yes

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_GMAKE=	yes
USES=		gettext pathfix pkgconfig
USE_GNOME=	glib20 ltverhack libsigc++20
USE_PERL5=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static --disable-documentation

post-patch:
.for d in docs examples tests
	@${REINPLACE_CMD} -e '/^SUBDIRS = /s/${d}//' ${WRKSRC}/Makefile.in
.endfor

.include <bsd.port.mk>

.endif