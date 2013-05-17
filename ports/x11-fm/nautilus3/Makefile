# Created by: ade, archie
# $FreeBSD$
# $MCom$

PORTNAME=	nautilus
PORTVERSION=	3.6.3
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas 
LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif \
		notify.4:${PORTSDIR}/devel/libnotify \
		exempi.3:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICTS=	nautilus-2.[0-9]*

USES=		gettext pathfix
LATEST_LINK=	nautilus3
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils gnomedesktop3 gnomeprefix gvfs intlhack introspection:build \
		libxml2 ltasneededhack ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-pthread"
CONFIGURE_ARGS=	--enable-static --disable-packagekit --disable-tracker

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

MAN1=		nautilus-connect-server.1 nautilus.1

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
