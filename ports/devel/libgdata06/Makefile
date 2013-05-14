# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgdata
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

LIB_DEPENDS=	soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome

CONFLICTS=	libgdata-0.10.*

LATEST_LINK=	libgdata06
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		gettext pathfix
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	glib20 intltool introspection ltverhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--with-html-dir="${PREFIX}/share/doc"

.include <bsd.port.mk>
