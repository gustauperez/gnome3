# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	drwright
PORTVERSION=	3.2.5
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 RSI prevention tool

LIB_DEPENDS=	canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		notify.4:${PORTSDIR}/devel/libnotify

USE_XZ=		yes
USE_GNOME=	gnomecontrolcenter3 gtk30 intlhack
USE_XORG=	x11 xscrnsaver
USE_GMAKE=	yes
USES=		gettext pathfix
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.settings-daemon.plugins.typing-break.gschema.xml

.include <bsd.port.mk>
