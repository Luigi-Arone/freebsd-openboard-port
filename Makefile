PORTNAME=	openboard
DISTVERSION=	1.7.7
CATEGORIES=	misc education

MAINTAINER=	larone426@gmail.com
COMMENT=	Open source interactive whiteboard application
WWW=		https://www.openboard.org

LICENSE=	GPLv3

LIB_DEPENDS=	libpoppler.so:graphics/poppler \
		libpoppler-cpp.so:graphics/poppler \
		libquazip1-qt5.so:archivers/quazip \
		libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg

USES=		cmake:noninja qt:5 pkgconfig desktop-file-utils \
		shared-mime-info compiler:c++20-lang xorg perl5 ssl gl

USE_PERL5=	build

USE_QT=		concurrent core dbus declarative gui location multimedia \
		network printsupport svg uitools webchannel webengine \
		widgets xml linguisttools:build buildtools:build

USE_GL=		gl

USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	OpenBoard-org
GH_PROJECT=	OpenBoard
GH_TAGNAME=	v${DISTVERSION}

CMAKE_ARGS=	-DQT_VERSION=5 \
		-DCMAKE_EXE_LINKER_FLAGS="-L${LOCALBASE}/lib" \
		-DX11_LIBRARIES="${LOCALBASE}/libX11.so" \
		-DX11_INCLUDE_DIR="${LOCALBASE}"

post-extract:
	${CP} ${FILESDIR}/UBPlatformUtils_freebsd.cpp \
		${WRKSRC}/src/frameworks/
	${CP} ${FILESDIR}/UBKeyboardPalette_freebsd.cpp \
		${WRKSRC}/src/gui/

.include <bsd.port.mk>
