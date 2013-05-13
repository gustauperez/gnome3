# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	gnome-system-monitor
PORTVERSION=	3.6.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 system monitor program

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop \
		gtkmm-3.0:${PORTSDIR}/x11-toolkits/gtkmm30
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

CONFLICTS=	gnome-system-monitor-2.[0-9]*

LATEST_LINK=	gnome-system-monitor3
USE_XZ=		yes
USES=		gettext pathfix
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomedocutils gnomeprefix intlhack librsvg2 \
		libwnck3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gnome-system-monitor.enums.xml \
		org.gnome.gnome-system-monitor.gschema.xml

.include <bsd.port.mk>
