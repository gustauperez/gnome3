# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vinagre
PORTVERSION=	3.6.2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC client for the GNOME Desktop

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	gtk-vnc-2:${PORTSDIR}/net/gtk-vnc3 \
    		avahi-core:${PORTSDIR}/net/avahi-app \
		avahi-ui-gtk3:${PORTSDIR}/net/avahi-gtk3 \
		gdbm:${PORTSDIR}/databases/gdbm \
		secret-1:${PORTSDIR}/security/libsecret \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

CONFLICTS=	vinagre-2.[0-9]*

LATEST_LINK=	vinagre3
USE_XZ=		yes
USE_GETTEXT=	yes
USES=		pathfix
USE_GNOME=	gnomeprefix intlhack gtk30 libxml2 vte3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-spice --enable-ssh
CPPFLAGS+=	-I${LOCALBASE}/include  -Wno-format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Vinagre.gschema.xml

MAN1=		vinagre.1

OPTIONS_DEFINE=	TELEPATHY RDP
OPTIONS_DEFAULT=RDP

TELEPATHY_DESC=	Enable telepathy integration
RDP_DESC=	Enable MS Windows remote desktop support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTELEPATHY)
LIB_DEPENDS+=	telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib
PLIST_SUB+=	TELEPATHY=""
.else
CONFIGURE_ARGS+=--without-telepathy
PLIST_SUB+=	TELEPATHY="@comment "
.endif

.if ${PORT_OPTIONS:MRDP}
BUILD_DEPENDS+=	rdesktop:${PORTSDIR}/net/rdesktop
RUN_DEPENDS+=	rdesktop:${PORTSDIR}/net/rdesktop
CONFIGURE_ARGS+=--enable-rdp
PLIST_SUB+=	RDP=""
.else
CONFIGURE_ARGS+=--disable-rdp
PLIST_SUB+=	RDP="@comment "
.endif

post-install:
	@-update-desktop-database > /dev/null
	@-update-mime-database ${PREFIX}/share/mime > /dev/null
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
