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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build

# Utility rule file for ELF2UF2Build.

# Include any custom commands dependencies for this target.
include InfoWrite/CMakeFiles/ELF2UF2Build.dir/compiler_depend.make

# Include the progress variables for this target.
include InfoWrite/CMakeFiles/ELF2UF2Build.dir/progress.make

InfoWrite/CMakeFiles/ELF2UF2Build: InfoWrite/CMakeFiles/ELF2UF2Build-complete

InfoWrite/CMakeFiles/ELF2UF2Build-complete: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
InfoWrite/CMakeFiles/ELF2UF2Build-complete: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
InfoWrite/CMakeFiles/ELF2UF2Build-complete: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
InfoWrite/CMakeFiles/ELF2UF2Build-complete: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
InfoWrite/CMakeFiles/ELF2UF2Build-complete: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
InfoWrite/CMakeFiles/ELF2UF2Build-complete: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
InfoWrite/CMakeFiles/ELF2UF2Build-complete: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
InfoWrite/CMakeFiles/ELF2UF2Build-complete: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'ELF2UF2Build'"
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E make_directory /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/CMakeFiles
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E touch /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/CMakeFiles/ELF2UF2Build-complete
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E touch /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-done

InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing build step for 'ELF2UF2Build'"
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/elf2uf2 && $(MAKE)

InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: InfoWrite/elf2uf2/tmp/ELF2UF2Build-cfgcmd.txt
InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Performing configure step for 'ELF2UF2Build'"
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/elf2uf2 && /usr/bin/cmake "-GUnix Makefiles" /home/hexplex0xff/picodev/pico-sdk/tools/elf2uf2
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/elf2uf2 && /usr/bin/cmake -E touch /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure

InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'ELF2UF2Build'"
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E echo_append
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E touch /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download

InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'ELF2UF2Build'"
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/elf2uf2 && /usr/bin/cmake -E echo_append
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/elf2uf2 && /usr/bin/cmake -E touch /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install

InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'ELF2UF2Build'"
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E make_directory /home/hexplex0xff/picodev/pico-sdk/tools/elf2uf2
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E make_directory /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/elf2uf2
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E make_directory /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E make_directory /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2/tmp
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E make_directory /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2/src/ELF2UF2Build-stamp
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E make_directory /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2/src
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E make_directory /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2/src/ELF2UF2Build-stamp
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E touch /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir

InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'ELF2UF2Build'"
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E echo_append
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E touch /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch

InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No update step for 'ELF2UF2Build'"
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E echo_append
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && /usr/bin/cmake -E touch /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update

ELF2UF2Build: InfoWrite/CMakeFiles/ELF2UF2Build
ELF2UF2Build: InfoWrite/CMakeFiles/ELF2UF2Build-complete
ELF2UF2Build: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
ELF2UF2Build: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
ELF2UF2Build: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
ELF2UF2Build: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
ELF2UF2Build: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
ELF2UF2Build: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
ELF2UF2Build: InfoWrite/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
ELF2UF2Build: InfoWrite/CMakeFiles/ELF2UF2Build.dir/build.make
.PHONY : ELF2UF2Build

# Rule to build all files generated by this target.
InfoWrite/CMakeFiles/ELF2UF2Build.dir/build: ELF2UF2Build
.PHONY : InfoWrite/CMakeFiles/ELF2UF2Build.dir/build

InfoWrite/CMakeFiles/ELF2UF2Build.dir/clean:
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite && $(CMAKE_COMMAND) -P CMakeFiles/ELF2UF2Build.dir/cmake_clean.cmake
.PHONY : InfoWrite/CMakeFiles/ELF2UF2Build.dir/clean

InfoWrite/CMakeFiles/ELF2UF2Build.dir/depend:
	cd /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/InfoWrite /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite /home/hexplex0xff/picodev/NanoDrone-Hardware/InfoFlash/build/InfoWrite/CMakeFiles/ELF2UF2Build.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : InfoWrite/CMakeFiles/ELF2UF2Build.dir/depend

