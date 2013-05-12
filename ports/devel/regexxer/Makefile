# Created by: Rui Lopes <rui@ruilopes.com>
# $FreeBSD$

PORTNAME=	regexxer
PORTVERSION=	0.10
CATEGORIES=	devel textproc gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	An interactive tool for performing search and replace operations

LIB_DEPENDS=	gtkmm-3.0.1:${PORTSDIR}/x11-toolkits/gtkmm30 \
		gtksourceviewmm-3.0.0:${PORTSDIR}/x11-toolkits/gtksourceviewmm3

USES=		gettext pathfix
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intltool intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.regexxer.gschema.xml

.include <bsd.port.mk>
