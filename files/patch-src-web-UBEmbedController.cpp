--- src/web/UBEmbedController.cpp.orig	2026-05-07 05:37:05.570855000 -0300
+++ src/web/UBEmbedController.cpp	2026-05-07 05:37:15.620478000 -0300
@@ -150,7 +150,7 @@
     static const QRegularExpression regExp("[<>:\"/\\\\|?*]");
 #endif
 
-#ifdef Q_OS_LINUX // Defined on X11.
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) // Defined on X11/FreeBSD.
     QString illegalCharList("      < > : \" / \\ | ? * ");
     static const QRegularExpression regExp("[<>:\"/\\\\|?*]");
 #endif
