# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	grilo-plugins
PORTVERSION=	0.2.3
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Grilo is a framework focused on making media discovery and browsing

LIB_DEPENDS=	grilo-0.2:${PORTSDIR}/net/grilo
RUN_DEPENDS=	grl-inspect-0.2:${PORTSDIR}/net/grilo

USES=		pathfix
USE_PKGCONFIG=	build
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier intlhack glib20 ltverhack libxml2
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
