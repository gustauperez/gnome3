# New ports collection makefile for:	telepathy-haze
# Date created:		2007-10-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net-im/telepathy-haze/Makefile,v 1.7 2012/06/13 00:59:50 mezz Exp $
#

PORTNAME=	telepathy-haze
PORTVERSION=	0.7.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-haze/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libpurple connection manager for telepathy

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	purple.10:${PORTSDIR}/net-im/libpurple \
		idn.17:${PORTSDIR}/dns/libidn \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib

USE_PKGCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN8=		telepathy-haze.8

.include <bsd.port.mk>
