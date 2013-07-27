# New ports collection makefile for:   caribou
# Date created:			10 Juni 2010
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/accessibility/caribou/Makefile,v 1.15 2013/03/13 22:24:42 kwm Exp $
#

PORTNAME=	caribou
PORTVERSION=	0.4.4.2
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome On-Screen keyboard

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	clutter-glx-1.0.0:${PORTSDIR}/graphics/clutter \
		gee.2:${PORTSDIR}/devel/libgee06 \
		xklavier.12:${PORTSDIR}/x11/libxklavier
RUN_DEPENDS=	py*-atspi>=2.1.91:${PORTSDIR}/accessibility/py-atspi

USE_XZ=		yes
USES=		gettext gmake pathfix
MAKE_JOBS_UNSAFE=yes
USE_PYTHON=	yes
USE_XORG=	x11 xtst
USE_GNOME=	intltool gnomedocutils gtk30 intlhack introspection:build \
		libxml2 pygobject3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-gtk2-module=no
GLIB_SCHEMAS=	org.gnome.caribou.gschema.xml \
		org.gnome.antler.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/tools/*.py
#	@${REINPLACE_CMD} -e 's|from gi.repository import GLib|import glib|g' \
#		${WRKSRC}/tools/make_schema.py
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' \
		-e 's|$${BASH_SOURCE\[0\]}|.|g' \
		${WRKSRC}/bin/antler-keyboard.in \
		${WRKSRC}/bin/caribou-preferences.in \
		${WRKSRC}/bin/caribou.in

.include <bsd.port.mk>
