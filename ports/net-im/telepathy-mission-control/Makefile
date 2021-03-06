# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	telepathy-mission-control
PORTVERSION=	5.14.0
CATEGORIES=	net-im devel
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-mission-control/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Telepathy component to apps to abstract details of connection managers

LIB_DEPENDS=	libtelepathy.so:${PORTSDIR}/net-im/libtelepathy \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

NO_STAGE=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	gconf2 gnomehack libxslt ltverhack
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
GLIB_SCHEMAS=	im.telepathy.MissionControl.FromEmpathy.gschema.xml

MAN1=		mc-tool.1 mc-wait-for-name.1
MAN8=		mission-control-5.8

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/gtk-doc/html|/${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
