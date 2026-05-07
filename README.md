# OpenBoard FreeBSD Port

Port of [OpenBoard](https://openboard.ch/) for FreeBSD.

## Status
Work in progress — submitted to FreeBSD ports tree.
Tested on FreeBSD 15.0-CURRENT amd64.

## Patches included
- C++20 compatibility: Poppler headers use C++20 features (std::span, std::string::starts_with, requires keyword). The upstream CMakeLists.txt defaulted to C++17.
- FFmpeg 6.x API updates: avcodec_close() was removed in FFmpeg 6.x, replaced by avcodec_free_context(). Also updated AVCodecContext::channels to ch_layout.nb_channels.
- FreeBSD platform support (UBPlatformUtils, UBKeyboardPalette): Added UBPlatformUtils_freebsd.cpp and UBKeyboardPalette_freebsd.cpp based on the Linux equivalents, as the upstream only provided platform specific implementations for Linux, macOS and Windows.
- X11 linker fix: The upstream DependencyX11.cmake did not correctly resolve libX11 on FreeBSD. Replaced pkgconfig-based detection with direct find_library() call.
- QMap initialization fix: Brace-initialized QMap with string literals failed to compile under Clang/C++20 on FreeBSD. Rewrote using lambda initializer pattern.
- FreeBSD ifdef: UBEmbedController.cpp had Linux-only ifdefs that excluded FreeBSD. Added Q_OS_FREEBSD alongside Q_OS_LINUX.
- Podcast/recording support: UBPodcastController.cpp had Linux-only ifdefs for FFmpeg encoder initialization and microphone device enumeration, causing the podcast feature to be unavailable on FreeBSD. Added Q_OS_FREEBSD alongside Q_OS_LINUX in all three affected ifdefs.

## Testing
```
cd /usr/ports/misc/openboard
```
```
make install
```
