# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/glib-networking/Makefile 18537 2013-06-16 20:08:30Z kwm $

PORTNAME=	glib-networking
PORTVERSION=	2.36.2
CATEGORIES=	net
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Network-related giomodules for glib

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libproxy.so:${PORTSDIR}/net/libproxy
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 intltool
USES=		gettext gmake pathfix pkgconfig
CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e' s|-Wmissing-include-dirs||g' ${WRKSRC}/configure

.include <bsd.port.mk>
