# New ports collection Makefile for:	libgcrypt
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD: ports/security/libgcrypt/Makefile,v 1.56 2012/11/17 06:01:06 svnexp Exp $

PORTNAME=	libpwquality
PORTVERSION=	1.2.1
CATEGORIES=	security
MASTER_SITES=	https://fedorahosted.org/releases/l/i/libpwquality/

MAINTAINER=	gnome@freebsd.org
COMMENT=	This is a libpwquality library for password quality checking

BUILD_DEPENDS=	cracklib-check:${PORTSDIR}/security/cracklib
LIB_DEPENDS=	crack:${PORTSDIR}/security/cracklib

USES=		pathfix
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_GNOME=	intltool
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--disable-pam \
		--disable-nls
#CONFIGURE_ENV+=	 ac_cv_header_libintl_h=no 
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

.include <bsd.port.mk>
