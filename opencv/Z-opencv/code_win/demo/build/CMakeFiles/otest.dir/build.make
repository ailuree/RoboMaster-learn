# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = D:/cmake-3.20/cmake-3.20.0-rc1-windows-x86_64/bin/cmake.exe

# The command to remove a file.
RM = D:/cmake-3.20/cmake-3.20.0-rc1-windows-x86_64/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo/build

# Include any dependencies generated for this target.
include CMakeFiles/otest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/otest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/otest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/otest.dir/flags.make

CMakeFiles/otest.dir/detect.cpp.obj: CMakeFiles/otest.dir/flags.make
CMakeFiles/otest.dir/detect.cpp.obj: CMakeFiles/otest.dir/includes_CXX.rsp
CMakeFiles/otest.dir/detect.cpp.obj: ../detect.cpp
CMakeFiles/otest.dir/detect.cpp.obj: CMakeFiles/otest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/otest.dir/detect.cpp.obj"
	D:/mingw-opencv/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/otest.dir/detect.cpp.obj -MF CMakeFiles/otest.dir/detect.cpp.obj.d -o CMakeFiles/otest.dir/detect.cpp.obj -c G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo/detect.cpp

CMakeFiles/otest.dir/detect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/otest.dir/detect.cpp.i"
	D:/mingw-opencv/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo/detect.cpp > CMakeFiles/otest.dir/detect.cpp.i

CMakeFiles/otest.dir/detect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/otest.dir/detect.cpp.s"
	D:/mingw-opencv/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo/detect.cpp -o CMakeFiles/otest.dir/detect.cpp.s

# Object files for target otest
otest_OBJECTS = \
"CMakeFiles/otest.dir/detect.cpp.obj"

# External object files for target otest
otest_EXTERNAL_OBJECTS =

otest.exe: CMakeFiles/otest.dir/detect.cpp.obj
otest.exe: CMakeFiles/otest.dir/build.make
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_gapi452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_highgui452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_ml452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_objdetect452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_photo452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_stitching452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_video452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_videoio452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_dnn452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_imgcodecs452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_calib3d452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_features2d452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_flann452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_imgproc452.dll.a
otest.exe: D:/opencv-4.5.2/opencv/MingwBuild/install/x64/mingw/lib/libopencv_core452.dll.a
otest.exe: CMakeFiles/otest.dir/linklibs.rsp
otest.exe: CMakeFiles/otest.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable otest.exe"
	D:/cmake-3.20/cmake-3.20.0-rc1-windows-x86_64/bin/cmake.exe -E rm -f CMakeFiles/otest.dir/objects.a
	D:/mingw-opencv/mingw64/bin/ar.exe cr CMakeFiles/otest.dir/objects.a @CMakeFiles/otest.dir/objects1.rsp
	D:/mingw-opencv/mingw64/bin/g++.exe -Wl,--whole-archive CMakeFiles/otest.dir/objects.a -Wl,--no-whole-archive -o otest.exe -Wl,--out-implib,libotest.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/otest.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/otest.dir/build: otest.exe
.PHONY : CMakeFiles/otest.dir/build

CMakeFiles/otest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/otest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/otest.dir/clean

CMakeFiles/otest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo/build G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo/build G:/temp/vgd/1-A-2025/Train_2025/opencv/Z-opencv/code_win/demo/build/CMakeFiles/otest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/otest.dir/depend

