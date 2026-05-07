--- cmake/DependencyX11.cmake.orig	2026-05-07 04:48:08.519620000 -0300
+++ cmake/DependencyX11.cmake	2026-05-07 04:50:16.623841000 -0300
@@ -1,18 +1,8 @@
-# Find FFmpeg
+# Find X11
+find_library(X11_LIB X11 PATHS /usr/local/lib /usr/lib)
 
-find_package(X11 QUIET)
-
-if (X11_FOUND)
-    target_link_libraries(${PROJECT_NAME}
-        X11
-    )
+if(X11_LIB)
+    target_link_libraries(${PROJECT_NAME} ${X11_LIB})
 else()
-    find_package(PkgConfig REQUIRED)
-    pkg_check_modules(X11 REQUIRED x11)
-
-    if (X11_FOUND)
-        target_link_libraries(${PROJECT_NAME} 
-            PkgConfig::X11
-        )
-    endif()
+    message(FATAL_ERROR "X11 library not found")
 endif()
