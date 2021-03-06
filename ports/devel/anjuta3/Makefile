# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/anjuta3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	anjuta
PORTVERSION=	3.4.3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

BUILD_DEPENDS=	glade>=3.12.0:${PORTSDIR}/devel/glade \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libgladeui-2.so:${PORTSDIR}/devel/glade \
		libgdl-3.so:${PORTSDIR}/x11-toolkits/gdl3
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		autogen:${PORTSDIR}/devel/autogen \
		automake-1.12:${PORTSDIR}/devel/automake \
		autoconf-2.69:${PORTSDIR}/devel/autoconf \
		libtool>=2.4:${PORTSDIR}/devel/libtool \
		gdb>=7.3:${PORTSDIR}/devel/gdb \
		yelp>=3.0.0:${PORTSDIR}/x11/yelp3

CONFLICTS=	anjuta-2.[0-9]*

NO_STAGE=yes
LATEST_LINK=	anjuta3
USE_XZ=		yes
USES=		bison gettext gmake pathfix perl5 pkgconfig shared-mime-info
INSTALLS_ICONS=	yes
USE_PYTHON=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix vte3 gtksourceview3 libgda5 libwnck3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-symbol-db-shm=/tmp \
		--disable-packagekit \
		--enable-introspection=yes
DOCSDIR=	share/doc/libanjuta
GLIB_SCHEMAS=	org.gnome.anjuta.code-analyzer.gschema.xml \
		org.gnome.anjuta.cpp.gschema.xml \
		org.gnome.anjuta.cvs.gschema.xml \
		org.gnome.anjuta.document-manager.gschema.xml \
		org.gnome.anjuta.file-manager.gschema.xml \
		org.gnome.anjuta.gschema.xml \
		org.gnome.anjuta.js.gschema.xml \
		org.gnome.anjuta.plugins.build.gschema.xml \
		org.gnome.anjuta.plugins.debug-manager.gschema.xml \
		org.gnome.anjuta.plugins.message-manager.gschema.xml \
		org.gnome.anjuta.plugins.run.gschema.xml \
		org.gnome.anjuta.plugins.sourceview.gschema.xml \
		org.gnome.anjuta.python.gschema.xml \
		org.gnome.anjuta.snippets.gschema.xml \
		org.gnome.anjuta.symbol-db.gschema.xml \
		org.gnome.anjuta.terminal.gschema.xml \
		org.gnome.anjuta.tools.gschema.xml

MAN1=		anjuta.1 anjuta-launcher.1

OPTIONS_DEFINE=	SVN DEVHELP GRAPHVIZ VALA
OPTIONS_DEFAULT=DEVHELP GRAPHVIZ
SVN_DESC=	Subversion plugin
DEVHELP_DESC=	Devhelp plugin
GRAPHVIZ_DESC=	Inheritance plugin
VALA_DESC=	Vala support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSVN}
BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
LIB_DEPENDS+=	libapr-1.so:${PORTSDIR}/devel/apr1
LIB_DEPENDS+=	libneon.so:${PORTSDIR}/www/neon29
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
PLIST_SUB+=	SVN=""
.else
CONFIGURE_ARGS+=--disable-plugin-subversion
PLIST_SUB+=	SVN="@comment "
.endif

.if ${PORT_OPTIONS:MDEVHELP}
LIB_DEPENDS+=	libdevhelp-3.so:${PORTSDIR}/devel/devhelp3
PLIST_SUB+=	DEVHELP=""
.else
CONFIGURE_ARGS+=--disable-plugin-devhelp
# XXX Even if we disable the devhelp plugin it gets build and installed.
# See if versions beyond 2.26.1.0 still do this.
#PLIST_SUB+=	DEVHELP="@comment "
PLIST_SUB+=	DEVHELP=""
.endif

.if ${PORT_OPTIONS:MGRAPHVIZ}
CONFIGURE_ARGS+=--enable-graphviz
BUILD_DEPENDS+=	neato:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS+=	neato:${PORTSDIR}/graphics/graphviz
PLIST_SUB+=	GRAPHVIZ=""
.else
CONFIGURE_ARGS+=--disable-graphviz
PLIST_SUB+=	GRAPHVIZ="@comment "
.endif

.if ${PORT_OPTIONS:MVALA}
CONFIGURE_ARGS+=--enable-vala
BUILD_DEPENDS+=	vala>=0.14.0:${PORTSDIR}/lang/vala
RUN_DEPENDS+=	vala>=0.14.0:${PORTSDIR}/lang/vala
PLIST_SUB+=	VALA=""
.else
CONFIGURE_ARGS+=--disable-vala
PLIST_SUB+=	VALA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"make|"gmake|g' \
		${WRKSRC}/plugins/build-basic-autotools/plugin.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/libanjuta/anjuta-utils.c

.include <bsd.port.mk>
