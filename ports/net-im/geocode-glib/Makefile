# Created by: Gustau Perez i Querol <gustau.perez@gmail.com> 
# $FreeBSD$

PORTNAME=	geocode-glib
PORTVERSION=	0.99.0
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	a convenience library for the Yahoo! Place Finder APIs

LIB_DEPENDS=	json-glib-1.0:${PORTSDIR}/devel/json-glib \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

USES=		pathfix
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier gnomedocutils intlhack ltverhack evolutiondataserver3
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|SoupGNOME|Soup|' \
                ${WRKSRC}/geocode-glib/Makefile.in

.include <bsd.port.mk>
