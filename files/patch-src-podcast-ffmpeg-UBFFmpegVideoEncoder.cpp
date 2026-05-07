--- src/podcast/ffmpeg/UBFFmpegVideoEncoder.cpp.orig	2026-05-07 05:42:15.041004000 -0300
+++ src/podcast/ffmpeg/UBFFmpegVideoEncoder.cpp	2026-05-07 05:42:18.667365000 -0300
@@ -747,7 +747,7 @@
     avio_close(mOutputFormatContext->pb);
 
 #if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(61, 3, 100)
-    avcodec_close(mVideoCodecContext);
+    avcodec_free_context(&mVideoCodecContext);
 #else
     avcodec_free_context(&mVideoCodecContext);
 #endif
@@ -755,7 +755,7 @@
 
     if (mShouldRecordAudio) {
 #if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(61, 3, 100)
-        avcodec_close(mAudioCodecContext);
+        avcodec_free_context(&mAudioCodecContext);
 #else
         avcodec_free_context(&mAudioCodecContext);
 #endif
