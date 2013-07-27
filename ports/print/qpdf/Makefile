# Created by: Dmitry Kazarov <d.y.kazarov@mail.ru>
# $FreeBSD: ports/print/qpdf/Makefile,v 1.1 2013/02/16 23:47:24 svnexp Exp $

PORTNAME=	qpdf
PORTVERSION=	4.0.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	d.y.kazarov@mail.ru
COMMENT=	Command-line tools for transforming and inspecting PDF files

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USES=		gmake pathfix
USE_GCC=	4.6+
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

MAN1=		fix-qdf.1 qpdf.1 zlib-flate.1

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		-e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/make/libtool.mk

	@${REINPLACE_CMD} -e 's|zlib,||' \
		${WRKSRC}/libqpdf.pc.in

.include <bsd.port.mk>
