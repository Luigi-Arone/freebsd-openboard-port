--- src/podcast/ffmpeg/UBFFmpegVideoEncoder.cpp.orig	2026-03-23 11:30:46 UTC
+++ src/podcast/ffmpeg/UBFFmpegVideoEncoder.cpp
@@ -747,7 +747,7 @@ void UBFFmpegVideoEncoder::finishEncoding()
     avio_close(mOutputFormatContext->pb);
 
 #if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(61, 3, 100)
-    avcodec_close(mVideoCodecContext);
+    avcodec_free_context(&mVideoCodecContext);
 #else
     avcodec_free_context(&mVideoCodecContext);
 #endif
@@ -755,7 +755,7 @@ void UBFFmpegVideoEncoder::finishEncoding()
 
     if (mShouldRecordAudio) {
 #if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(61, 3, 100)
-        avcodec_close(mAudioCodecContext);
+        avcodec_free_context(&mAudioCodecContext);
 #else
         avcodec_free_context(&mAudioCodecContext);
 #endif
