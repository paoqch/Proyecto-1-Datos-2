# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/richmond/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/richmond/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/richmond/Desktop/Proyecto Final/Pro-Prueba/Pro-Pruebas/C_IDE"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/richmond/Desktop/Proyecto Final/Pro-Prueba/Pro-Pruebas/C_IDE/cmake-build-debug"

# Utility rule file for C_IDE_autogen.

# Include the progress variables for this target.
include CMakeFiles/C_IDE_autogen.dir/progress.make

CMakeFiles/C_IDE_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/richmond/Desktop/Proyecto Final/Pro-Prueba/Pro-Pruebas/C_IDE/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target C_IDE"
	/home/richmond/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/bin/cmake/linux/bin/cmake -E cmake_autogen "/home/richmond/Desktop/Proyecto Final/Pro-Prueba/Pro-Pruebas/C_IDE/cmake-build-debug/CMakeFiles/C_IDE_autogen.dir/AutogenInfo.json" Debug

C_IDE_autogen: CMakeFiles/C_IDE_autogen
C_IDE_autogen: CMakeFiles/C_IDE_autogen.dir/build.make

.PHONY : C_IDE_autogen

# Rule to build all files generated by this target.
CMakeFiles/C_IDE_autogen.dir/build: C_IDE_autogen

.PHONY : CMakeFiles/C_IDE_autogen.dir/build

CMakeFiles/C_IDE_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/C_IDE_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/C_IDE_autogen.dir/clean

CMakeFiles/C_IDE_autogen.dir/depend:
	cd "/home/richmond/Desktop/Proyecto Final/Pro-Prueba/Pro-Pruebas/C_IDE/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/richmond/Desktop/Proyecto Final/Pro-Prueba/Pro-Pruebas/C_IDE" "/home/richmond/Desktop/Proyecto Final/Pro-Prueba/Pro-Pruebas/C_IDE" "/home/richmond/Desktop/Proyecto Final/Pro-Prueba/Pro-Pruebas/C_IDE/cmake-build-debug" "/home/richmond/Desktop/Proyecto Final/Pro-Prueba/Pro-Pruebas/C_IDE/cmake-build-debug" "/home/richmond/Desktop/Proyecto Final/Pro-Prueba/Pro-Pruebas/C_IDE/cmake-build-debug/CMakeFiles/C_IDE_autogen.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/C_IDE_autogen.dir/depend
