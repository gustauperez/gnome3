# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpwquality
PORTVERSION=	1.2.1
CATEGORIES=	security
MASTER_SITES=	https://fedorahosted.org/releases/l/i/libpwquality/

MAINTAINER=	gnome@freebsd.org
COMMENT=	Library for generating random passwords and quality checking

LIB_DEPENDS=	libcrack.so:${PORTSDIR}/security/cracklib

NO_STAGE=	yes
USES=		gettext gmake pathfix
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--disable-pam
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
# configure needs to be fixed
CONFIGURE_ENV+=	LIBS="-lintl"

MAN1=	pwmake.1 pwscore.1
MAN5=	pwquality.conf.5

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
CONFIGURE_ARGS+=--enable-python-bindings
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python-bindings
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.mk>
