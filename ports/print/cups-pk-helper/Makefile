# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/print/cups-pk-helper/Makefile,v 1.8 2012/09/01 23:02:11 mezz Exp $

PORTNAME=	cups-pk-helper
PORTVERSION=	0.2.0
CATEGORIES=	print
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A helper that makes system-config-printer use PolicyKit

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		cups.2:${PORTSDIR}/print/cups-client \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 intlhack
USES=		gettext pathfix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/libs

.include <bsd.port.mk>
