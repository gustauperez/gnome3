# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/libsecret/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libsecret
PORTVERSION=	0.15
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access the secret service API

BUILD_DEPENDS=	docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

NO_STAGE=	yes
USE_XZ=		yes
USE_GNOME=	gnomehier glib20 libxslt:build intltool introspection:build
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-introspection

MAN1=		secret-tool.1

.include <bsd.port.mk>
