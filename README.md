# OpenBoard FreeBSD Port

Port of [OpenBoard](https://www.openboard.org/) for FreeBSD.

OpenBoard is an open source interactive whiteboard application designed
primarily for use in schools. It supports digital pens, virtual keyboards,
PDF import, web browsing, video playback, and screen annotations.

## Status

Work in progress — submitted to FreeBSD ports tree (Bug 295104).

## Patches included

- C++20 compatibility: Poppler headers use C++20 features (std::span,
  std::string::starts_with, requires keyword). The upstream CMakeLists.txt
  defaulted to C++17.
- FFmpeg 6.x API updates: avcodec_close() was removed in FFmpeg 6.x,
  replaced by avcodec_free_context().
- FreeBSD platform support (UBPlatformUtils, UBKeyboardPalette): Added
  UBPlatformUtils_freebsd.cpp and UBKeyboardPalette_freebsd.cpp based on
  the Linux equivalents, as the upstream only provided platform specific
  implementations for Linux, macOS and Windows.
- X11 linker fix: The upstream DependencyX11.cmake did not correctly
  resolve libX11 on FreeBSD. Replaced pkgconfig-based detection with
  direct find_library() call.
- QMap initialization fix: Brace-initialized QMap with string literals
  failed to compile under Clang/C++20 on FreeBSD. Rewrote using lambda
  initializer pattern.
- FreeBSD ifdef: UBEmbedController.cpp had Linux-only ifdefs that excluded
  FreeBSD. Added Q_OS_FREEBSD alongside Q_OS_LINUX.
- Podcast/recording support: UBPodcastController.cpp had Linux-only ifdefs
  for FFmpeg encoder initialization and microphone device enumeration.
  Added Q_OS_FREEBSD alongside Q_OS_LINUX in all three affected ifdefs.
- Qt6 QChar conversion: In Qt6, QChar no longer has implicit conversion
  from int. Added explicit QChar() casts in keyboard layout macros.


## Testing

```sh
cd /usr/ports/graphics/openboard
make install
```

Tested on FreeBSD 15.0-CURRENT amd64 with Qt6.