# OpenBoard FreeBSD Port

Port of [OpenBoard](https://www.openboard.org/) for FreeBSD.

OpenBoard is an open source interactive whiteboard application designed
primarily for use in schools. It supports digital pens, virtual keyboards,
PDF import, web browsing, video playback, and screen annotations.

## Status

Submitted to FreeBSD ports tree ([Bug 295104](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=295104)).
The current version in this repository reflects the refactored port
provided by the FreeBSD committer during review.

## Patches included

- **C++20 standard**: Poppler headers require C++20 features (std::span,
  std::string::starts_with, requires keyword). Upstream defaults to C++17.
- **X11 detection**: Replaced pkgconfig-based detection with direct
  find_library() using LOCALBASE.
- **FreeBSD platform support**: Patched UBPlatformUtils_linux.cpp and
  CMakeLists.txt files in src/frameworks and src/gui to compile the
  Linux platform code on FreeBSD as well (CMAKE_SYSTEM_NAME matches
  "FreeBSD|Linux"), with FreeBSD-specific ifdefs where needed (DBus
  onboard integration is disabled on FreeBSD).
- **FreeBSD ifdefs**: Added Q_OS_FREEBSD alongside Q_OS_LINUX in
  UBEmbedController.cpp and UBPodcastController.cpp.
- **Poppler 26.4+ compatibility**: Updated XPDFRenderer.cpp to handle
  the API change in recent Poppler versions.

## Testing

```sh
cd /usr/ports/graphics/openboard
make install
```

Tested on FreeBSD 15.0-CURRENT amd64 with Qt6.

## Acknowledgments

Thanks to the FreeBSD committer who reviewed and refactored the initial
submission, providing a much cleaner port structure.
