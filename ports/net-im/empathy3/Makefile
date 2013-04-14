# New ports collection makefile for:	empathy
# Date created:		2007-10-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-im/empathy3/Makefile,v 1.32 2012/07/02 14:47:52 kwm Exp $

PORTNAME=	empathy
PORTVERSION=	3.6.2
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME IM client based around telepathy

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		${LOCALBASE}/libdata/pkgconfig/clutter-gst-2.0.pc:${PORTSDIR}/multimedia/clutter-gst \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		itstool:${PORTSDIR}/textproc/itstool \
    		${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control
LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant \
		geocode-glib:${PORTSDIR}/net-im/geocode-glib \
		goa-1.0:${PORTSDIR}/net/gnome-online-accounts \
		pulse.0:${PORTSDIR}/audio/pulseaudio \
		telepathy.2:${PORTSDIR}/net-im/libtelepathy \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		telepathy-farstream.3:${PORTSDIR}/net-im/telepathy-farstream \
		telepathy-logger.2:${PORTSDIR}/net-im/telepathy-logger \
		folks-telepathy.25:${PORTSDIR}/net-im/folks \
		notify.4:${PORTSDIR}/devel/libnotify \
		gcr-3:${PORTSDIR}/security/gcr \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		clutter-gst-2.0:${PORTSDIR}/multimedia/clutter-gst \
		webkitgtk-3.0.0:${PORTSDIR}/www/webkit-gtk3 \
		soup-2.4:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
    		${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control

CONFLICTS=	empathy-2.[0-9]*

USES=		pathfix
LATEST_LINK=	empathy3
USE_GMAKE=	yes
USE_XZ=		yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME=	evolutiondataserver3 gnomeprefix ltverhack
USE_GSTREAMER1=	yes
USE_AUTOTOOLS=	libtool
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_PYTHON=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-Werror \
		--enable-goa \
		--enable-gst-1.0=yes \
		--enable-location=no

GLIB_SCHEMAS=	org.gnome.Empathy.gschema.xml

MAN1=		empathy.1 empathy-accounts.1

OPTIONS_DEFINE=	JABBER MSN IRC SALUT HAZE MAP CHEESE
OPTIONS_DEFAULT=JABBER     IRC            MAP
JABBER_DESC=	Enable jabber (XMPP) client support
MSN_DESC=	Enable MSN client support (broken)
IRC_DESC=	Enable IRC client support
SALUT_DESC=	Enable link-local (serverless) XMPP support
HAZE_DESC=	Enable libpurple protocol integration (broken)
MAP_DESC=	Enable graphical map support
CHEESE_DESC=	Enable cheese camera support
NST_DESC=	Enable Nautilus SendTo plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJABBER}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-gabble:${PORTSDIR}/net-im/telepathy-gabble
.endif

.if ${PORT_OPTIONS:MMSN}
BROKEN=		conflict in dependancies
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-butterfly:${PORTSDIR}/net-im/telepathy-butterfly
.endif

.if ${PORT_OPTIONS:MIRC}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-idle:${PORTSDIR}/net-im/telepathy-idle
.endif

.if ${PORT_OPTIONS:MSALUT}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-salut:${PORTSDIR}/net-im/telepathy-salut
.endif

.if !defined(WITHOUT_HAZE)
BROKEN=		conflict in dependancies
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-haze:${PORTSDIR}/net-im/telepathy-haze
.endif

#.${PORT_OPTIONS:MNST}
#BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/nautilus-sendto.pc:${PORTSDIR}/deskutils/nautilus-sendto
#RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/nautilus-sendto.pc:${PORTSDIR}/deskutils/nautilus-sendto
#CONFIGURE_ARGS+=--enable-nautilus-sendto=yes
#PLIST_SUB+=	NST=""
#.else
CONFIGURE_ARGS+=--enable-nautilus-sendto=no
PLIST_SUB+=	NST="@comment "
#.endif

.if ${PORT_OPTIONS:MMAP}
LIB_DEPENDS+=	champlain-0.12.0:${PORTSDIR}/graphics/libchamplain
CONFIGURE_ARGS+=--enable-map
PLIST_SUB+=	MAP=""
.else
CONFIGURE_ARGS+=--disable-map
PLIST_SUB+=	MAP="@comment "
.endif

.if ${PORT_OPTIONS:MCHEESE}
LIB_DEPENDS+=	cheese-gtk:${PORTSDIR}/multimedia/cheese3
CONFIGURE_ARGS+=--with-cheese
.else
CONFIGURE_ARGS+=--without-cheese
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|clutter-gst-1.0|clutter-gst-2.0|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
