# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	libnotify
PORTVERSION=	0.7.5
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for desktop notifications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
RUN_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_XZ=		yes
USE_GNOME=	glib20 gtk20 intlhack ltverhack
USES=		gettext pathfix
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
