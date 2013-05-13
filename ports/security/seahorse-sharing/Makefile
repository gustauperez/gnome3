# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$
#   $MCom: ports/security/seahorse-sharing/Makefile,v 1.1 2011/10/18 22:59:34 kwm Exp $
#

PORTNAME=	seahorse-sharing
PORTVERSION=	3.2.1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Seahorse PGP public key sharing using DNS-SD and HKP.

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	gpgme.19:${PORTSDIR}/security/gpgme \
		avahi-glib.1:${PORTSDIR}/net/avahi-app \
		soup-2.4.1:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		seahorse>=3.2.1:${PORTSDIR}/security/seahorse3

USE_XZ=		yes
USES=		gettext pathfix
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

MAN1=		seahorse-sharing.1

.include <bsd.port.mk>
