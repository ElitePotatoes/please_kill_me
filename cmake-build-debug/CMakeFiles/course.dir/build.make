# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\elite\CLionProjects\main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\elite\CLionProjects\main\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/course.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/course.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/course.dir/flags.make

CMakeFiles/course.dir/main.c.obj: CMakeFiles/course.dir/flags.make
CMakeFiles/course.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/course.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\course.dir\main.c.obj -c C:\Users\elite\CLionProjects\main\main.c

CMakeFiles/course.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/course.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\main.c > CMakeFiles\course.dir\main.c.i

CMakeFiles/course.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/course.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\main.c -o CMakeFiles\course.dir\main.c.s

CMakeFiles/course.dir/libs/experiments/core_exp/experiments.c.obj: CMakeFiles/course.dir/flags.make
CMakeFiles/course.dir/libs/experiments/core_exp/experiments.c.obj: ../libs/experiments/core_exp/experiments.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/course.dir/libs/experiments/core_exp/experiments.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\course.dir\libs\experiments\core_exp\experiments.c.obj -c C:\Users\elite\CLionProjects\main\libs\experiments\core_exp\experiments.c

CMakeFiles/course.dir/libs/experiments/core_exp/experiments.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/course.dir/libs/experiments/core_exp/experiments.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\libs\experiments\core_exp\experiments.c > CMakeFiles\course.dir\libs\experiments\core_exp\experiments.c.i

CMakeFiles/course.dir/libs/experiments/core_exp/experiments.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/course.dir/libs/experiments/core_exp/experiments.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\libs\experiments\core_exp\experiments.c -o CMakeFiles\course.dir\libs\experiments\core_exp\experiments.c.s

# Object files for target course
course_OBJECTS = \
"CMakeFiles/course.dir/main.c.obj" \
"CMakeFiles/course.dir/libs/experiments/core_exp/experiments.c.obj"

# External object files for target course
course_EXTERNAL_OBJECTS =

course.exe: CMakeFiles/course.dir/main.c.obj
course.exe: CMakeFiles/course.dir/libs/experiments/core_exp/experiments.c.obj
course.exe: CMakeFiles/course.dir/build.make
course.exe: Libs/data_structures/libdata_structures.a
course.exe: Libs/algorithms/libalgorithms.a
course.exe: Libs/discrete_mathematics/libdiscrete_mathematics.a
course.exe: Libs/experiments/libexperiments.a
course.exe: CMakeFiles/course.dir/linklibs.rsp
course.exe: CMakeFiles/course.dir/objects1.rsp
course.exe: CMakeFiles/course.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable course.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\course.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/course.dir/build: course.exe
.PHONY : CMakeFiles/course.dir/build

CMakeFiles/course.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\course.dir\cmake_clean.cmake
.PHONY : CMakeFiles/course.dir/clean

CMakeFiles/course.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\elite\CLionProjects\main C:\Users\elite\CLionProjects\main C:\Users\elite\CLionProjects\main\cmake-build-debug C:\Users\elite\CLionProjects\main\cmake-build-debug C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles\course.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/course.dir/depend

