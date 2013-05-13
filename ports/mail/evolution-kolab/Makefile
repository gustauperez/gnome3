# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evolution-kolab
PORTVERSION=	3.6.4
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Kolab groupware connector for evolution 3

BUILD_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3 \
		gperf>=3.0.3:${PORTSDIR}/devel/gperf
LIB_DEPENDS=	gmime-2.6:${PORTSDIR}/mail/gmime26
RUN_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3

EVO_VER=	3.4.1
USE_XZ=		yes
USES=		gettext pathfix
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_SQLITE=	yes
MAKE_JOBS_UNSAFE=yes
USE_GNOME=	 gconf2 gnomeprefix intlhack libxml2 ltasneededhack 
CONFIGURE_ENV=	ac_cv_path_GPERF=${LOCALBASE}/bin/gperf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

VERSION=	3.6
PLIST_SUB=	VERSION=${VERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,prefix}/doc/evolution_kolab,prefix}/share/doc/evolution_kolab,g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
