# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/devhelp3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	devhelp
PORTVERSION=	3.6.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Developer help browser for GNOME 3

LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3

CONFLICTS=	devhelp-2.[0-9]*

NO_STAGE=	yes
LATEST_LINK=	devhelp3
USE_XZ=		yes
USE_XORG=	x11
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gconf2 gnomeprefix gtk30 intlhack
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	devhelp.schemas
CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|gedit-plugin||g' ${WRKSRC}/misc/Makefile.in

.include <bsd.port.mk>
