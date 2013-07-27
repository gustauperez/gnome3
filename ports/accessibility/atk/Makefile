# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD: head/accessibility/atk/Makefile 313633 2013-03-08 10:51:34Z kwm $
#   $MCom: ports/trunk/accessibility/atk/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	atk
PORTVERSION=	2.8.0
PORTREVISION?=	0
CATEGORIES=	accessibility devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME accessibility toolkit (ATK)

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	glib20 gnomehier introspection:build \
		ltverhack referencehack
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	AUTOCONF=${TRUE} AUTOMAKE=${TRUE}

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/tests docs//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
