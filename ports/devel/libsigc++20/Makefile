# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD: devel/libsigc++20/Makefile 314640 2013-03-19 13:04:30Z eadler $
#   $MCom: ports/trunk/devel/libsigc++20/Makefile 18692 2013-09-22 00:45:30Z kwm $

PORTNAME=	libsigc++
PORTVERSION=	2.3.1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

NO_STAGE=	yes
USE_AUTOTOOLS=	libtool
USE_XZ=		yes
USE_PERL5=	build
LATEST_LINK=	libsigc++20
USE_LDCONFIG=	yes
USES=		gmake pathfix perl5
GNU_CONFIGURE=	yes

PLIST_SUB=	VERSION="2.0" API_VERSION="2.0"

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--enable-documentation=no
.endif

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||; \
		/^SUBDIRS =/s|examples||" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
