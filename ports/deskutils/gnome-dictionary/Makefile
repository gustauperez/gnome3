# New ports collection makefile for:	gnomeutils2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gnome-dictionary/Makefile,v 1.1 2012/05/31 15:11:22 kwm Exp $
#

PORTNAME=	gnome-dictionary
PORTVERSION=	3.4.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 dictionary lookup application

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc

CONFLICTS=	gnome-utils-2.[0-9]*

USE_XZ=		yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedocutils gtk30
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gnome-dictionary.1
GLIB_SCHEMAS=	org.gnome.dictionary.gschema.xml

.include <bsd.port.mk>
