# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	libepc
PORTVERSION=	0.4.4
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	The Easy Publish and Consume library

LIB_DEPENDS=	uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		gnutls.47:${PORTSDIR}/security/gnutls \
		avahi-ui-gtk3.0:${PORTSDIR}/net/avahi-gtk3

USE_XZ=		yes
USE_GMAKE=	yes
USES=		gettext pathfix
USE_GNOME=	gnomeprefix gtk30
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
