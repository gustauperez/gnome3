# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	libsecret
PORTVERSION=	0.11
CATEGORIES=	security  gnome
MASTER_SITES=	GNOME

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	A library to access the secret service API

BUILD_DEPENDS=	gobject-introspection>=0.9.0:${PORTSDIR}/devel/gobject-introspection \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

USES=		pathfix
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_GMAKE=	yes
USE_XZ=		yes
USE_GNOME=	glib20 gnomehier intltool libxslt:build
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes

MAN1=		secret-tool.1

.include <bsd.port.mk>
