# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/gnome-themes/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-themes
PORTVERSION=	2.32.1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of themes and icons for GNOME2

BUILD_DEPENDS=	gtk-engines2>=2.15.0:${PORTSDIR}/x11-themes/gtk-engines2 \
		icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=	gtk-engines2>=2.15.0:${PORTSDIR}/x11-themes/gtk-engines2

CONFLICTS=	clearlooks-metacity-0.* gnome-themes-standard-3.[0-9]*

NO_STAGE=	yes
USE_BZIP2=	yes
USES=		gettext gmake pathfix
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack metacity gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
