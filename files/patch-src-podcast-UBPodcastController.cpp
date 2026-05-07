--- src/podcast/UBPodcastController.cpp.orig	2026-05-07 18:16:26.852473000 -0300
+++ src/podcast/UBPodcastController.cpp	2026-05-07 18:16:32.432392000 -0300
@@ -64,7 +64,7 @@
 #elif defined(Q_OS_OSX)
     #include "ffmpeg/UBFFmpegVideoEncoder.h"
     #include "ffmpeg/UBMicrophoneInput.h"
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     #include "ffmpeg/UBFFmpegVideoEncoder.h"
     #include "ffmpeg/UBMicrophoneInput.h"
 #endif
@@ -315,7 +315,7 @@
         mVideoEncoder = new UBWindowsMediaVideoEncoder(this);  //deleted on stop
 #elif defined(Q_OS_OSX)
         mVideoEncoder = new UBFFmpegVideoEncoder(this);
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         mVideoEncoder = new UBFFmpegVideoEncoder(this);
 #endif
 
@@ -780,7 +780,7 @@
     devices = UBWaveRecorder::waveInDevices();
 #elif defined(Q_OS_OSX)
     devices = UBMicrophoneInput::availableDevicesNames();
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     devices = UBMicrophoneInput::availableDevicesNames();
 #endif
 
