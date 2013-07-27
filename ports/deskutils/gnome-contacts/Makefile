# Created by:				Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-contacts
PORTVERSION=	3.6.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Contacts manager for gnome

BUILD_DEPENDS=	vala>=0.14.0:${PORTSDIR}/lang/vala \
		${LOCALBASE}/libdata/pkgconfig/gcr-3.pc:${PORTSDIR}/security/gcr \
		${LOCALBASE}/libdata/pkgconfig/cheese.pc:${PORTSDIR}/multimedia/cheese3 
LIB_DEPENDS=	goa-1.0.0:${PORTSDIR}/net/gnome-online-accounts \
		folks.25:${PORTSDIR}/net-im/folks \
		cheese.7:${PORTSDIR}/multimedia/cheese3 \
		notify.4:${PORTSDIR}/devel/libnotify

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	evolutiondataserver3 gtk30 gnomedesktop3 intlhack
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Contacts.gschema.xml

.include <bsd.port.mk>
