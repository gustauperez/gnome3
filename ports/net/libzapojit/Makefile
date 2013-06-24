# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	libzapojit
PORTVERSION=	0.0.2
CATEGORIES=	net deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GLib/GObject wrapper for the Skydrive and Hotmail API

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	goa-1:${PORTSDIR}/net/gnome-online-accounts \
		json-glib-1:${PORTSDIR}/devel/json-glib \
		rest-0.7:${PORTSDIR}/devel/librest

USE_XZ=		yes
USES=		gettext pathfix
USE_GNOME=	gnomeprefix intlhack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>