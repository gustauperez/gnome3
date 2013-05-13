# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	libsocialweb
PORTVERSION=	0.25.20
CATEGORIES=	www gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	A personal social data server.

LIB_DEPENDS=	rest-0.7.0:${PORTSDIR}/www/rest \
		json-glib-1.0.0:${PORTSDIR}/devel/json-glib

USE_GNOME=	gconf2 glib20 intlhack libxslt:build
USE_XZ=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gettext pathfix
CONFIGURE_ARGS=	--enable-all-services

.include <bsd.port.mk>
