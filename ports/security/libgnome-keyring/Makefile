# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/security/libgnome-keyring/Makefile,v 1.25 2013/02/15 16:35:39 kwm Exp $

PORTNAME=	libgnome-keyring
PORTVERSION=	3.6.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program that keeps passwords and other secrets

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		gcrypt:${PORTSDIR}/security/libgcrypt

USE_XZ=		yes
USE_GNOME=	glib20 gnomehier gnomeprefix intlhack ltverhack
USE_GMAKE=	yes
USES=		gettext pathfix
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
