# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/libgnome-media-profiles/Makefile,v 1.1 2011/04/16 07:42:13 kwm Exp $

PORTNAME=	libgnome-media-profiles
PORTVERSION=	3.0.0
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library that contains code to manage media profiles

CONFLICTS=	gnome-media-2.[0-9]*

USE_GNOME=	gconf2 gnomedocutils gtk30 intlhack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GSTREAMER=	yes
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
USES=		gettext pathfix

GCONF_SCHEMAS=	gnome-media-profiles.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|gladeui-3.0|gladeui-5.0|g' ${WRKSRC}/configure

.include <bsd.port.mk>
