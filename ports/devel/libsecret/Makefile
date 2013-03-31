# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	libsecret
PORTVERSION=	0.11
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	GObject collection library

BUILD_DEPENDS=	gobject-introspection>=0.9.0:${PORTSDIR}/devel/gobject-introspection \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_GMAKE=	yes
USE_XZ=		yes
USE_GNOME=	glib20 gnomehier gnomehack intltool
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes

MAN1=		secret-tool.1

.include <bsd.port.mk>
