# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-icon-theme-symbolic/Makefile,v 1.12 2012/12/31 17:16:03 mezz Exp $

PORTNAME=	gnome-icon-theme-symbolic
PORTVERSION=	3.6.2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Symbolic Icons

BUILD_DEPENDS=	icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils

USES=		pathfix pkgconfig
USE_XZ=		yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|(GTK_UPDATE_ICON_CACHE) -q |(GTK_UPDATE_ICON_CACHE) -q -t -f |'g \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
