# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	zeitgeist
PORTVERSION=	0.8.2
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Event logging framework - engine

BUILD_DEPENDS=	rapper:${PORTSDIR}/textproc/raptor2 \
		${PYTHON_SITELIBDIR}/rdflib/__init__.py:${PORTSDIR}/textproc/py-rdflib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus

USE_GNOME=	intlhack pygobject
USE_GMAKE=	yes
USE_PYTHON=	yes
FETCH_ARGS=	-Fpr
GNU_CONFIGURE=	yes
USES=		gettext pathfix
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=	zeitgeist-daemon.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/extra/rdfxml2py

.include <bsd.port.mk>
