# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build

# Include any dependencies generated for this target.
include src/CMakeFiles/pkgverify.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/pkgverify.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/pkgverify.dir/flags.make

src/CMakeFiles/pkgverify.dir/main.cpp.o: src/CMakeFiles/pkgverify.dir/flags.make
src/CMakeFiles/pkgverify.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/pkgverify.dir/main.cpp.o"
	cd /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pkgverify.dir/main.cpp.o -c /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/src/main.cpp

src/CMakeFiles/pkgverify.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pkgverify.dir/main.cpp.i"
	cd /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/src/main.cpp > CMakeFiles/pkgverify.dir/main.cpp.i

src/CMakeFiles/pkgverify.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pkgverify.dir/main.cpp.s"
	cd /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/src/main.cpp -o CMakeFiles/pkgverify.dir/main.cpp.s

src/CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.o: src/CMakeFiles/pkgverify.dir/flags.make
src/CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.o: src/pkgverify_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.o"
	cd /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.o -c /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src/pkgverify_autogen/mocs_compilation.cpp

src/CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.i"
	cd /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src/pkgverify_autogen/mocs_compilation.cpp > CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.i

src/CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.s"
	cd /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src/pkgverify_autogen/mocs_compilation.cpp -o CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.s

# Object files for target pkgverify
pkgverify_OBJECTS = \
"CMakeFiles/pkgverify.dir/main.cpp.o" \
"CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.o"

# External object files for target pkgverify
pkgverify_EXTERNAL_OBJECTS =

src/pkgverify: src/CMakeFiles/pkgverify.dir/main.cpp.o
src/pkgverify: src/CMakeFiles/pkgverify.dir/pkgverify_autogen/mocs_compilation.cpp.o
src/pkgverify: src/CMakeFiles/pkgverify.dir/build.make
src/pkgverify: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.11.3
src/pkgverify: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.11.3
src/pkgverify: src/CMakeFiles/pkgverify.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable pkgverify"
	cd /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pkgverify.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/pkgverify.dir/build: src/pkgverify

.PHONY : src/CMakeFiles/pkgverify.dir/build

src/CMakeFiles/pkgverify.dir/clean:
	cd /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src && $(CMAKE_COMMAND) -P CMakeFiles/pkgverify.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/pkgverify.dir/clean

src/CMakeFiles/pkgverify.dir/depend:
	cd /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11 /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/src /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src /media/bobo/ff9ec359-e856-4f4d-9e23-d1d6d97f8c6f/work/gitcode/github/exam_app/zuoda/dev_exam_app_B/exam11/build/src/CMakeFiles/pkgverify.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/pkgverify.dir/depend
