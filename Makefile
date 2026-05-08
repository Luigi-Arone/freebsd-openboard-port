PORTNAME=	openboard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.7
CATEGORIES=	graphics education

MAINTAINER=	larone426@gmail.com
COMMENT=	Open source interactive whiteboard application
WWW=		https://www.openboard.org

LICENSE=	GPLv3

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libpoppler.so:graphics/poppler \
		libpoppler-cpp.so:graphics/poppler \
		libquazip1-qt6.so:archivers/quazip \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg

USES=		cmake:noninja compiler:c++20-lang desktop-file-utils gl \
		perl5 pkgconfig qt:6 shared-mime-info ssl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	OpenBoard-org
GH_PROJECT=	OpenBoard

USE_GL=		gl

USE_QT=		5compat base declarative multimedia positioning svg \
		tools webchannel webengine

USE_XORG=	x11

CMAKE_ARGS=	-DQT_VERSION=6 \
		-DCMAKE_EXE_LINKER_FLAGS="-L${LOCALBASE}/lib"

post-extract:
	${CP} ${FILESDIR}/UBPlatformUtils_freebsd.cpp \
		${WRKSRC}/src/frameworks/
	${CP} ${FILESDIR}/UBKeyboardPalette_freebsd.cpp \
		${WRKSRC}/src/gui/

.include <bsd.port.mk>
