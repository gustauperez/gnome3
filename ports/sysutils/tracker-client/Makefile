# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	tracker
PORTVERSION=	0.14.4
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	-client

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		poppler-glib.8:${PORTSDIR}/graphics/poppler-glib \
		exif.12:${PORTSDIR}/graphics/libexif \
		wv-1.2.4:${PORTSDIR}/textproc/wv \
		gmime-2.6:${PORTSDIR}/mail/gmime26 \
		qdbm.14:${PORTSDIR}/databases/qdbm \
		exempi.3:${PORTSDIR}/textproc/exempi \
		hal.1:${PORTSDIR}/sysutils/hal \
		totem-plparser.17:${PORTSDIR}/multimedia/totem-pl-parser \
		raptor.3:${PORTSDIR}/textproc/raptor \
		ogg:${PORTSDIR}/audio/libogg \
		iptcdata.3:${PORTSDIR}/graphics/libiptcdata \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid
RUN_DEPENDS=	xdg-desktop-icon:${PORTSDIR}/devel/xdg-utils \
		o3totxt:${PORTSDIR}/converters/o3read \
		pdftotext:${PORTSDIR}/graphics/poppler-utils \
		w3m:${PORTSDIR}/www/w3m

USES=		gettext gmake pathfix
USE_XZ=		yes
USE_FAM=	yes
WANT_FAM_SYSTEM=gamin
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intltool ltasneededhack ltverhack
USE_LDCONFIG=	yes
USE_GSTREAMER=	core
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/tracker
CONFIGURE_ARGS=	--enable-video-extractor=gstreamer \
		--enable-file-monitoring=fam \
		--with-session-bus-services-dir=${LOCALBASE}/share/dbus-1/services \
		--enable-external-qdbm --enable-libexif --enable-libvorbis \
		--enable-libiptcdata

.include <bsd.port.pre.mk>

.if defined(TRACKER_SLAVE)
LIB_DEPENDS+=	trackerclient:${PORTSDIR}/sysutils/tracker-client
. if ${TRACKER_SLAVE}=="gnome"
PKGNAMESUFFIX=	-gnome
LIB_DEPENDS+=	tracker-gtk:${PORTSDIR}/sysutils/tracker-libtrackergtk
BUILD_WRKSRC=	${WRKSRC}/src/tracker-applet
INSTALL_WRKSRC=	${WRKSRC}/src/tracker-applet
EXTRA_WRKSRC=	src/tracker-preferences src/tracker-search-tool
BUILD_DEPENDS+=	${LOCALBASE}/libexec/deskbar-applet/deskbar-applet:${PORTSDIR}/deskutils/deskbar-applet
RUN_DEPENDS+=	${LOCALBASE}/libexec/deskbar-applet/deskbar-applet:${PORTSDIR}/deskutils/deskbar-applet
USE_GNOME+=	gnomedesktop libgsf
MAN1+=		tracker-applet.1 tracker-search-tool.1 tracker-preferences.1
CONFIGURE_ARGS+=--enable-deskbar-applet \
		--with-deskbar-applet-handler-dir=${LOCALBASE}/libexec/deskbar-applet/handlers
. endif
. if defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="libtrackergtk"
PKGNAMESUFFIX=	-libtrackergtk
USE_GNOME+=	libgsf
BUILD_WRKSRC=	${WRKSRC}/src/libtracker-gtk
INSTALL_WRKSRC=	${BUILD_WRKSRC}
. endif
.else
MAN1+=	tracker-control.1 tracker-extract.1 \
	tracker-import.1 tracker-stats.1 \
	tracker-info.1 tracker-miner-fs.1 \
	tracker-search.1 tracker-sparql.1 \
	tracker-store.1 tracker-tag.1 \
	tracker-writeback.1
CONFIGURE_ARGS+=	--disable-libtrackergtk --disable-gui \
			--disable-trackerapplet --disable-gsf \
			--disable-preferences   --disable-deskbar-applet \
			--disable-tracker-applet --disable-tracker-preferences \
			--disable-libgsf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng15|' ${WRKSRC}/configure

post-build:
.if defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="libtrackergtk"
	@(cd ${WRKSRC}/src/tracker-extract && ${MAKE} libextract-msoffice.la)
.elif defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="gnome"
. for dir in ${EXTRA_WRKSRC}
	@(cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
. endfor
.endif

post-install:
.if defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="libtrackergtk"
	${MKDIR} ${PREFIX}/lib/tracker/extract-modules
	@(cd ${WRKSRC}/src/tracker-extract && for f in .a .la .so ; \
	do ${INSTALL_DATA} .libs/libextract-msoffice$${f} \
		${PREFIX}/lib/tracker/extract-modules ; done)
.elif defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="gnome"
. for dir in ${EXTRA_WRKSRC}
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
. endfor
. for man in ${MAN1}
	@(cd ${WRKSRC} && ${INSTALL_DATA} docs/manpages/${man} ${PREFIX}/man/man1/${man})
. endfor
.endif

.include <bsd.port.post.mk>
