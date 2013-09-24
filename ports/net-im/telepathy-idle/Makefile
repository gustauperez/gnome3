# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	telepathy-idle
PORTVERSION=	0.1.14
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IRC Connection Manager for Telepathy Framework

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib
#LIB_PC_DEPENDS=	gobject-2.0.pc:${PORTSDIR}/devel/glib20 \
#		dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib \
#		telepathy-glib.pc:${PORTSDIR}/net-im/telepathy-glib

#BUILD_DEPENDS=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}
#RUN_DEPENDS=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}

NO_STAGE=	yes
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 libxslt:build

MAN8=		telepathy-idle.8

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -lssl -lcrypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|strnlen(\([^,]*\), [^)]*)|strlen(\1)|' \
		${WRKSRC}/src/idle-connection.c \
		${WRKSRC}/src/idle-parser.c

.include <bsd.port.post.mk>
