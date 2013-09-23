# New ports collection makefile for:	gnomeutils2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/baobab/Makefile,v 1.1 2012/05/31 15:11:22 kwm Exp $
#

PORTNAME=	baobab
PORTVERSION=	3.6.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 graphical directory tree analyzer

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop

CONFLICTS=	gnome-utils-2.[0-9]*

NO_STAGE=	yes
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack libxml2 gtk30
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		baobab.1
GLIB_SCHEMAS=	org.gnome.baobab.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|inode/directory|inode/directory:1|g' \
		${WRKSRC}/data/baobab.desktop.in.in
	@${REINPLACE_CMD} -e 's|-Wno-unused-but-set-variable||g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
