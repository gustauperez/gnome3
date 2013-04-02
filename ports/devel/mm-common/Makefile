# New ports collection makefile for:   mm-common
# Date Created:			27 Aug 2009
# Whom:				Koop Mast<kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/mm-common/Makefile,v 1.15 2011/03/30 22:04:27 kwm Exp $
#

PORTNAME=	mm-common
PORTVERSION=	0.9.6
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common build infrastructure for the GNOME C++ binding libraries

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

USES=		pathfix
USE_XZ=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		mm-common-prepare.1

.include <bsd.port.mk>
