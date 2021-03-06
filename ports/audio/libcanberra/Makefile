# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD: head/audio/libcanberra/Makefile 309632 2012-12-29 20:57:20Z mezz $
#   $MCom: ports/trunk/audio/libcanberra/Makefile 18692 2013-09-22 00:45:30Z kwm $

PORTNAME=	libcanberra
PORTVERSION=	0.28
PORTREVISION=	4
CATEGORIES=	audio devel
MASTER_SITES=	http://0pointer.de/lennart/projects/libcanberra/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL

LIB_DEPENDS=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis

NO_STAGE=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix gnomehier gtk20 ltverhack gconf2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool libltdl
CONFIGURE_ARGS=	--disable-lynx --disable-tdb --disable-alsa
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(SLAVEPORT)
GCONF_SCHEMAS=	libcanberra.schemas
.else
OPTIONS_DEFINE=	PULSEAUDIO GSTREAMER
.endif

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if defined(SLAVEPORT)
USE_GNOME+=	gtk30
LIB_DEPENDS+=	libcanberra.so:${PORTSDIR}/audio/libcanberra
CONFIGURE_ARGS+=--enable-gtk3
.else
CONFIGURE_ARGS+=--disable-gtk3

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSE=""
.else
CONFIGURE_ARGS+=--disable-pulse
PLIST_SUB+=	PULSE="@comment "
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	yes
PLIST_SUB+=	GSTREAMER=""
.else
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.endif # end slaveport

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
