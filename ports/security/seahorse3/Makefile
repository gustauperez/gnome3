# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$

PORTNAME=	seahorse
PORTVERSION=	3.6.3
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme \
    		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		cryptui:${PORTSDIR}/security/libcryptui \
		gcr-3:${PORTSDIR}/security/gcr \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		secret-1:${PORTSDIR}/security/libsecret \
		soup-2.4.1:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

CONFLICTS=	seahorse-2.[0-9]*

LATEST_LINK=	seahorse3
USE_XORG=	sm
USE_LDCONFIG=	yes
USE_XZ=		yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USES=		pathfix
USE_GNOME=	intlhack gnomeprefix gtk30 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.seahorse.gschema.xml \
		org.gnome.seahorse.manager.gschema.xml \
		org.gnome.seahorse.window.gschema.xml
MAN1=		seahorse.1

OPTIONS_DEFINE=	LDAP NOTIFY MDNS
OPTIONS_DEFAULT=NOTIFY

LDAP_DESC=	"Enable LDAP support" on
NOTIFY_DESC=	NOTIFY "Enable libnotify support" on
MDNS_DESC=	MDNS "Enable mDNS key sharing" on

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.if ${PORT_OPTIONS:MMDNS}
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--disable-sharing
.endif

.include <bsd.port.mk>
