# New ports collection makefile for:    json-glib
# Date created:         		25 December 2008
# Whom:                 		Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: devel/json-glib/Makefile 313633 2013-03-08 10:51:34Z kwm $
#   $MCom: ports/devel/json-glib/Makefile,v 1.22 2012/09/01 23:02:09 mezz Exp $
#

PORTNAME=	json-glib
PORTVERSION=	0.15.2
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JSON (RFC 4627) interface for Glib

BUILD_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection

USES=		gmake pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	glib20 gnomeprefix ltverhack
USE_PKGCONFIG=	build
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
