# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/gnome-media/Makefile,v 1.164 2012/09/01 23:02:08 mezz Exp $
#

PORTNAME=	gnome-media
PORTVERSION=	3.4.0
PORTREVISION=	4
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the GNOME 3 desktop

BUILD_DEPENDS=	xml2po:${PORTSDIR}/textproc/gnome-doc-utils
LIB_DEPENDS=	libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra \
		libgnome-media-profiles-3.0.so:${PORTSDIR}/multimedia/libgnome-media-profiles \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique

CONFLICTS=	gnome-media-2.[0-9]* 

USE_XZ=		yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gconf2 gnomeprefix gnomehack gtk20 gtk30 \
			intlhack libxml2
USE_GSTREAMER=	gconf good
USES=		gettext gmake
CONFIGURE_ARGS=	--disable-gstmix \
		--enable-gstprops
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnome-sound-recorder.schemas

OPTIONS_DEFINE=PULSEAUDIO

PULSEAUDIO_DESC=	Enable Pulse Audio support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--enable-pulseaudio
PLIST_SUB+=	PULSE=""
.else
CONFIGURE_ARGS+=--disable-pulseaudio
PLIST_SUB+=	PULSE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|have_gladeui=true|have_gladeui=false|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
