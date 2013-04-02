# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD: x11-toolkits/gtksourceview3/Makefile 314655 2013-03-19 15:15:31Z kwm $
#   $MCom: ports/x11-toolkits/gtksourceview3/Makefile,v 1.21 2012/05/31 11:57:38 kwm Exp $

PORTNAME=	gtksourceview
PORTVERSION=	3.6.1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A text widget that adds syntax highlighting to the GtkTextView widget

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		pathfix
USE_GNOME=	gnomeprefix gtk30 libxml2 intlhack ltverhack referencehack
CONFIGURE_ARGS=	--enable-compile-warnings=no --enable-glade-catalog=no \
		--enable-introspection
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|--warn-all||g' \
		${WRKSRC}/gtksourceview/Makefile.in

.include <bsd.port.mk>

.endif