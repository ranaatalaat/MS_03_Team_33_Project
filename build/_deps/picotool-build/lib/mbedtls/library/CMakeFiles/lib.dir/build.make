# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\X-J\Desktop\Raspberry-Pi-Pico-master\FreeRTOS_Blink\build\_deps\picotool-src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\X-J\Desktop\Raspberry-Pi-Pico-master\FreeRTOS_Blink\build\_deps\picotool-build

# Utility rule file for lib.

# Include any custom commands dependencies for this target.
include lib/mbedtls/library/CMakeFiles/lib.dir/compiler_depend.make

lib/mbedtls/library/CMakeFiles/lib: lib/mbedtls/library/libmbedcrypto.a
lib/mbedtls/library/CMakeFiles/lib: lib/mbedtls/library/libmbedx509.a
lib/mbedtls/library/CMakeFiles/lib: lib/mbedtls/library/libmbedtls.a

lib/mbedtls/library/CMakeFiles/lib.dir/codegen:
.PHONY : lib/mbedtls/library/CMakeFiles/lib.dir/codegen

lib: lib/mbedtls/library/CMakeFiles/lib
lib: lib/mbedtls/library/CMakeFiles/lib.dir/build.make
.PHONY : lib

# Rule to build all files generated by this target.
lib/mbedtls/library/CMakeFiles/lib.dir/build: lib
.PHONY : lib/mbedtls/library/CMakeFiles/lib.dir/build

lib/mbedtls/library/CMakeFiles/lib.dir/clean:
	cd /d C:\Users\X-J\Desktop\Raspberry-Pi-Pico-master\FreeRTOS_Blink\build\_deps\picotool-build\lib\mbedtls\library && $(CMAKE_COMMAND) -P CMakeFiles\lib.dir\cmake_clean.cmake
.PHONY : lib/mbedtls/library/CMakeFiles/lib.dir/clean

lib/mbedtls/library/CMakeFiles/lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\X-J\Desktop\Raspberry-Pi-Pico-master\FreeRTOS_Blink\build\_deps\picotool-src C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library C:\Users\X-J\Desktop\Raspberry-Pi-Pico-master\FreeRTOS_Blink\build\_deps\picotool-build C:\Users\X-J\Desktop\Raspberry-Pi-Pico-master\FreeRTOS_Blink\build\_deps\picotool-build\lib\mbedtls\library C:\Users\X-J\Desktop\Raspberry-Pi-Pico-master\FreeRTOS_Blink\build\_deps\picotool-build\lib\mbedtls\library\CMakeFiles\lib.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/mbedtls/library/CMakeFiles/lib.dir/depend

