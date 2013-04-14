# New ports collection makefile for:   gnome-online-accounts
# Date Created:			15 Sep 2011
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net/gnome-online-accounts/Makefile,v 1.7 2012/06/01 09:24:12 kwm Exp $

PORTNAME=	gnome-online-accounts
PORTVERSION=	3.6.2
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Interface privider to access the user's online accounts.

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	webkitgtk-3.0:${PORTSDIR}/www/webkit-gtk3 \
		json-glib:${PORTSDIR}/devel/json-glib \
		notify:${PORTSDIR}/devel/libnotify \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		secret-1:${PORTSDIR}/security/libsecret \
		rest-0.7:${PORTSDIR}/www/rest

USES=		pathfix
USE_XZ=		yes
USE_GNOME=	gtk30 intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN8=		goa-daemon.8

.include <bsd.port.mk>
