# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD: devel/dconf/Makefile 313956 2013-03-12 09:45:07Z kwm $
#   $MCom: ports/trunk/devel/dconf/Makefile 18692 2013-09-22 00:45:30Z kwm $

PORTNAME?=	dconf
PORTVERSION=	0.16.1
PORTREVISION=	0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DISTNAME=	dconf-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Configuration database system for GNOME

BUILD_DEPENDS=	vala>=0.18.1:${PORTSDIR}/lang/vala \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus

NO_STAGE=	yes
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	glib20 gnomehier intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DCONF_SLAVE?=	no

.if ${DCONF_SLAVE} == editor
USE_GNOME+=	gtk30
INSTALLS_ICONS=	yes
GLIB_SCHEMAS=	ca.desrt.dconf-editor.gschema.xml
LIB_DEPENDS+=	libdconf.so:${PORTSDIR}/devel/dconf
.else
CONFIGURE_ARGS+=--disable-editor
.endif

.if ${DCONF_SLAVE} == no
MAN1=		dconf-editor.1 dconf-service.1 dconf.1
MAN7=		dconf.7
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/engine/dconf-engine.c \
		${WRKSRC}/bin/dconf-update.c
	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' \
		${WRKSRC}/editor/dconf-model.c
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/editor/dconf-model.vala
	@${REINPLACE_CMD} -e 's|-Wno-unused-but-set-variable||g' \
		${WRKSRC}/bin/Makefile.in \
		${WRKSRC}/client/Makefile.in \
		${WRKSRC}/editor/Makefile.in

post-install:
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/gio/modules
	@${MKDIR} ${PREFIX}/etc/dconf/db
	@${MKDIR} ${PREFIX}/etc/dconf/profile

.include <bsd.port.mk>
