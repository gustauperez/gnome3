# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD: ports/mail/libmapi/Makefile,v 1.12 2013/02/24 13:49:00 svnexp Exp $

PORTNAME=	libmapi
PORTVERSION=	2.0
CATEGORIES=	mail
MASTER_SITES=	http://tracker.openchange.org/attachments/download/${DOWNLOADCODE}/
DISTNAME=	openchange-${PORTVERSION}-${CODENAME}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Open Source implementation of Microsoft Exchange protocols

BUILD_DEPENDS=	samba4>=4.0.1:${PORTSDIR}/net/samba4 \
		p5-Parse-Pidl>=4.0.1:${PORTSDIR}/devel/p5-Parse-Pidl
LIB_DEPENDS=	ical:${PORTSDIR}/devel/libical \
		popt:${PORTSDIR}/devel/popt \
		tdb:${PORTSDIR}/databases/tdb \
		talloc:${PORTSDIR}/devel/talloc
RUN_DEPENDS=	samba4>=4.0.1:${PORTSDIR}/net/samba4

CODENAME=	QUADRANT
DOWNLOADCODE=	220

USE_GMAKE=	yes
USE_SQLITE=	3
USES=		pkgconfig
USE_PYTHON=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-D__USE_BSD
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-samba=${LOCALBASE}
CONFIGURE_ENV=	ac_cv_path_DOXYGEN=""

OPTIONS_DEFINE=	BOOST
OPTIONS_DEFAULT=BOOST
BOOST_DESC=	libmapi C++ library (needs boost)

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--disable-pymapi
#  --enable-openchange-qt4 Compile OpenChange Qt4 wrapper.

.if ${PORT_OPTIONS:MBOOST}
LIB_DEPENDS+=	boost_thread:${PORTSDIR}/devel/boost-libs
PLIST_SUB+=	BOOST=""
.else
CONFIGURE_ENV+=	ov_cv_boost_thread=""
PLIST_SUB+=	BOOST="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		-e 's|--parent|-p|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${LOCALBASE}/bin/python|g' \
		${WRKSRC}/pyopenchange/mapistore/gen_errors.py
	@${REINPLACE_CMD} -e 's|-lpthread|-pthread|g' \
		${WRKSRC}/doc/examples/Makefile ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|sed -i |sed -i "" |g' \
		${WRKSRC}/config.mk.in

post-install:
	@${MKDIR} ${PREFIX}/share/openchange
	cd ${WRKSRC}/apidocs/html/ && ${COPYTREE_SHARE} . ${PREFIX}/share/openchange/

.include <bsd.port.mk>
