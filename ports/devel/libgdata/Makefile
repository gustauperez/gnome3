# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgdata
PORTVERSION=	0.13.2
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

BUILD_DEPENDS=	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		liboauth.so:${PORTSDIR}/net/liboauth
RUN_DEPENDS=	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss

CONFLICTS=	libgdata-0.6.*

NO_STAGE=	ye=	yes
USE_XZ=		yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	glib20 gnomeprefix intltool introspection:build ltverhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-ca-certs=${LOCALBASE}/share/certs/ca-root-nss.crt

.include <bsd.port.mk>
