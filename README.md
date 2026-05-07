# OpenBoard FreeBSD Port

Port of [OpenBoard](https://openboard.ch/) for FreeBSD.

## Status
Work in progress — submitted to FreeBSD ports tree.

## Patches included
- C++20 compatibility (Poppler headers require C++20)
- FFmpeg 6.x API updates
- FreeBSD platform support (UBPlatformUtils, UBKeyboardPalette)
- X11 linker fix
- QMap initialization fix

## Testing
```
cd /usr/ports/misc/openboard
```
```
make install
```
