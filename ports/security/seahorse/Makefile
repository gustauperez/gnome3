# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/seahorse/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	seahorse
PORTVERSION=	2.32.0
PORTREVISION=	9
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme \
    		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		gcr:${PORTSDIR}/security/gnome-keyring \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		soup-2.4:${PORTSDIR}/devel/libsoup

CONFLICTS=	libcryptui-3.[0-9]* seahorse-3.[0-9]*

NO_STAGE=	yes
USE_XORG=	sm
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	intlhack gnomeprefix gconf2 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-introspection=no

GCONF_SCHEMAS=	seahorse.schemas
MAN1=		seahorse.1 seahorse-daemon.1

OPTIONS_DEFINE=	LDAP NOTIFY MDNS
OPTIONS_DEFAULT=LDAP NOTIFY MDNS
MDNS_DESC=	mDNS key sharing

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.if ${PORT_OPTIONS:MMDNS}
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--disable-sharing
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
