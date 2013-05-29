# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cups-filters
PORTVERSION=	1.0.34
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/${PORTNAME}/
#DISTNAME=	${PORTNAME}-1.0-20130529

#WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Backends, filters, and other software previously part of CUPS

BUILD_DEPENDS=	cupsd:${PORTSDIR}/print/cups-base
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		cups.2:${PORTSDIR}/print/cups-client \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		ijs.1:${PORTSDIR}/print/libijs \
		poppler:${PORTSDIR}/graphics/poppler \
		lcms.1:${PORTSDIR}/graphics/lcms \
		qpdf:${PORTSDIR}/print/qpdf
RUN_DEPENDS=	cupsd:${PORTSDIR}/print/cups-base

CUPS_PDFTOPS?=	${LOCALBASE}/libexec/xpdf/pdftops

OPTIONS_SINGLE=			PDFTOPS
OPTIONS_SINGLE_PDFTOPS=		GHOSTSCRIPT XPDF

OPTIONS_DEFAULT=		GHOSTSCRIPT

GHOSTSCRIPT_DESC=	Build pdftops with GHOSTSCRIPT
XPDF_DESC=		Build pdftops with XPDF

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	glib20 intlhack
USES=		gettext pathfix
USE_GCC=	4.6+
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ZLIB_CFLAGS="-I/usr/include" \
		ZLIB_LIBS="-L/usr/lib -lz"
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-long-long
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXPDF}
BUILD_DEPENDS+=		${CUPS_PDFTOPS}:${PORTSDIR}/graphics/xpdf
RUN_DEPENDS+=		${CUPS_PDFTOPS}:${PORTSDIR}/graphics/xpdf
CONFIGURE_ARGS+=	--with-pdftops=xpdftops --with-pdftops-path=${CUPS_PDFTOPS}
.else
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--with-pdftops=gs --with-pdftops-path=${LOCALBASE}/bin/gs --with-gs-path=${LOCALBASE}/bin/gs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|endian.h|sys/endian.h|' \
		${WRKSRC}/configure

	@${REINPLACE_CMD} -e 's|"-ldl"|""|g; \
		s|"-ldl |"|g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
