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
include Libs/data_structures/CMakeFiles/data_structures.dir/depend.make
# Include the progress variables for this target.
include Libs/data_structures/CMakeFiles/data_structures.dir/progress.make

# Include the compile flags for this target's objects.
include Libs/data_structures/CMakeFiles/data_structures.dir/flags.make

Libs/data_structures/CMakeFiles/data_structures.dir/bitsets/bitsets.c.obj: Libs/data_structures/CMakeFiles/data_structures.dir/flags.make
Libs/data_structures/CMakeFiles/data_structures.dir/bitsets/bitsets.c.obj: ../libs/data_structures/bitsets/bitsets.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Libs/data_structures/CMakeFiles/data_structures.dir/bitsets/bitsets.c.obj"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\bitsets\bitsets.c.obj -c C:\Users\elite\CLionProjects\main\libs\data_structures\bitsets\bitsets.c

Libs/data_structures/CMakeFiles/data_structures.dir/bitsets/bitsets.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/bitsets/bitsets.c.i"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\libs\data_structures\bitsets\bitsets.c > CMakeFiles\data_structures.dir\bitsets\bitsets.c.i

Libs/data_structures/CMakeFiles/data_structures.dir/bitsets/bitsets.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/bitsets/bitsets.c.s"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\libs\data_structures\bitsets\bitsets.c -o CMakeFiles\data_structures.dir\bitsets\bitsets.c.s

Libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.obj: Libs/data_structures/CMakeFiles/data_structures.dir/flags.make
Libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.obj: ../libs/data_structures/unordered_array_set/unordered_array_set.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object Libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.obj"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.obj -c C:\Users\elite\CLionProjects\main\libs\data_structures\unordered_array_set\unordered_array_set.c

Libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.i"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\libs\data_structures\unordered_array_set\unordered_array_set.c > CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.i

Libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.s"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\libs\data_structures\unordered_array_set\unordered_array_set.c -o CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.s

Libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.obj: Libs/data_structures/CMakeFiles/data_structures.dir/flags.make
Libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.obj: ../libs/data_structures/ordered_array_set/ordered_array_set.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object Libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.obj"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.obj -c C:\Users\elite\CLionProjects\main\libs\data_structures\ordered_array_set\ordered_array_set.c

Libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.i"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\libs\data_structures\ordered_array_set\ordered_array_set.c > CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.i

Libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.s"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\libs\data_structures\ordered_array_set\ordered_array_set.c -o CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.s

Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector/vector.c.obj: Libs/data_structures/CMakeFiles/data_structures.dir/flags.make
Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector/vector.c.obj: ../libs/data_structures/vector/vector/vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector/vector.c.obj"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\vector\vector\vector.c.obj -c C:\Users\elite\CLionProjects\main\libs\data_structures\vector\vector\vector.c

Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/vector/vector/vector.c.i"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\libs\data_structures\vector\vector\vector.c > CMakeFiles\data_structures.dir\vector\vector\vector.c.i

Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/vector/vector/vector.c.s"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\libs\data_structures\vector\vector\vector.c -o CMakeFiles\data_structures.dir\vector\vector\vector.c.s

Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector_void/vector_void.c.obj: Libs/data_structures/CMakeFiles/data_structures.dir/flags.make
Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector_void/vector_void.c.obj: ../libs/data_structures/vector/vector_void/vector_void.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector_void/vector_void.c.obj"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\vector\vector_void\vector_void.c.obj -c C:\Users\elite\CLionProjects\main\libs\data_structures\vector\vector_void\vector_void.c

Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector_void/vector_void.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/vector/vector_void/vector_void.c.i"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\libs\data_structures\vector\vector_void\vector_void.c > CMakeFiles\data_structures.dir\vector\vector_void\vector_void.c.i

Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector_void/vector_void.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/vector/vector_void/vector_void.c.s"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\libs\data_structures\vector\vector_void\vector_void.c -o CMakeFiles\data_structures.dir\vector\vector_void\vector_void.c.s

Libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.obj: Libs/data_structures/CMakeFiles/data_structures.dir/flags.make
Libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.obj: ../libs/data_structures/matrix/matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object Libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.obj"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\matrix\matrix.c.obj -c C:\Users\elite\CLionProjects\main\libs\data_structures\matrix\matrix.c

Libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/matrix/matrix.c.i"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\libs\data_structures\matrix\matrix.c > CMakeFiles\data_structures.dir\matrix\matrix.c.i

Libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/matrix/matrix.c.s"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\libs\data_structures\matrix\matrix.c -o CMakeFiles\data_structures.dir\matrix\matrix.c.s

Libs/data_structures/CMakeFiles/data_structures.dir/point/point.c.obj: Libs/data_structures/CMakeFiles/data_structures.dir/flags.make
Libs/data_structures/CMakeFiles/data_structures.dir/point/point.c.obj: ../libs/data_structures/point/point.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object Libs/data_structures/CMakeFiles/data_structures.dir/point/point.c.obj"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\point\point.c.obj -c C:\Users\elite\CLionProjects\main\libs\data_structures\point\point.c

Libs/data_structures/CMakeFiles/data_structures.dir/point/point.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/point/point.c.i"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\libs\data_structures\point\point.c > CMakeFiles\data_structures.dir\point\point.c.i

Libs/data_structures/CMakeFiles/data_structures.dir/point/point.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/point/point.c.s"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\libs\data_structures\point\point.c -o CMakeFiles\data_structures.dir\point\point.c.s

Libs/data_structures/CMakeFiles/data_structures.dir/line/line.c.obj: Libs/data_structures/CMakeFiles/data_structures.dir/flags.make
Libs/data_structures/CMakeFiles/data_structures.dir/line/line.c.obj: ../libs/data_structures/line/line.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object Libs/data_structures/CMakeFiles/data_structures.dir/line/line.c.obj"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\line\line.c.obj -c C:\Users\elite\CLionProjects\main\libs\data_structures\line\line.c

Libs/data_structures/CMakeFiles/data_structures.dir/line/line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/line/line.c.i"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\libs\data_structures\line\line.c > CMakeFiles\data_structures.dir\line\line.c.i

Libs/data_structures/CMakeFiles/data_structures.dir/line/line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/line/line.c.s"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\libs\data_structures\line\line.c -o CMakeFiles\data_structures.dir\line\line.c.s

Libs/data_structures/CMakeFiles/data_structures.dir/circle/circle.c.obj: Libs/data_structures/CMakeFiles/data_structures.dir/flags.make
Libs/data_structures/CMakeFiles/data_structures.dir/circle/circle.c.obj: ../libs/data_structures/circle/circle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object Libs/data_structures/CMakeFiles/data_structures.dir/circle/circle.c.obj"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\circle\circle.c.obj -c C:\Users\elite\CLionProjects\main\libs\data_structures\circle\circle.c

Libs/data_structures/CMakeFiles/data_structures.dir/circle/circle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/circle/circle.c.i"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\libs\data_structures\circle\circle.c > CMakeFiles\data_structures.dir\circle\circle.c.i

Libs/data_structures/CMakeFiles/data_structures.dir/circle/circle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/circle/circle.c.s"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\libs\data_structures\circle\circle.c -o CMakeFiles\data_structures.dir\circle\circle.c.s

Libs/data_structures/CMakeFiles/data_structures.dir/fraction/fraction.c.obj: Libs/data_structures/CMakeFiles/data_structures.dir/flags.make
Libs/data_structures/CMakeFiles/data_structures.dir/fraction/fraction.c.obj: ../libs/data_structures/fraction/fraction.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object Libs/data_structures/CMakeFiles/data_structures.dir/fraction/fraction.c.obj"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\fraction\fraction.c.obj -c C:\Users\elite\CLionProjects\main\libs\data_structures\fraction\fraction.c

Libs/data_structures/CMakeFiles/data_structures.dir/fraction/fraction.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/fraction/fraction.c.i"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elite\CLionProjects\main\libs\data_structures\fraction\fraction.c > CMakeFiles\data_structures.dir\fraction\fraction.c.i

Libs/data_structures/CMakeFiles/data_structures.dir/fraction/fraction.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/fraction/fraction.c.s"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elite\CLionProjects\main\libs\data_structures\fraction\fraction.c -o CMakeFiles\data_structures.dir\fraction\fraction.c.s

# Object files for target data_structures
data_structures_OBJECTS = \
"CMakeFiles/data_structures.dir/bitsets/bitsets.c.obj" \
"CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.obj" \
"CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.obj" \
"CMakeFiles/data_structures.dir/vector/vector/vector.c.obj" \
"CMakeFiles/data_structures.dir/vector/vector_void/vector_void.c.obj" \
"CMakeFiles/data_structures.dir/matrix/matrix.c.obj" \
"CMakeFiles/data_structures.dir/point/point.c.obj" \
"CMakeFiles/data_structures.dir/line/line.c.obj" \
"CMakeFiles/data_structures.dir/circle/circle.c.obj" \
"CMakeFiles/data_structures.dir/fraction/fraction.c.obj"

# External object files for target data_structures
data_structures_EXTERNAL_OBJECTS =

Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/bitsets/bitsets.c.obj
Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.obj
Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.obj
Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector/vector.c.obj
Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/vector/vector_void/vector_void.c.obj
Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.obj
Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/point/point.c.obj
Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/line/line.c.obj
Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/circle/circle.c.obj
Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/fraction/fraction.c.obj
Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/build.make
Libs/data_structures/libdata_structures.a: Libs/data_structures/CMakeFiles/data_structures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\elite\CLionProjects\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C static library libdata_structures.a"
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && $(CMAKE_COMMAND) -P CMakeFiles\data_structures.dir\cmake_clean_target.cmake
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\data_structures.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Libs/data_structures/CMakeFiles/data_structures.dir/build: Libs/data_structures/libdata_structures.a
.PHONY : Libs/data_structures/CMakeFiles/data_structures.dir/build

Libs/data_structures/CMakeFiles/data_structures.dir/clean:
	cd /d C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures && $(CMAKE_COMMAND) -P CMakeFiles\data_structures.dir\cmake_clean.cmake
.PHONY : Libs/data_structures/CMakeFiles/data_structures.dir/clean

Libs/data_structures/CMakeFiles/data_structures.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\elite\CLionProjects\main C:\Users\elite\CLionProjects\main\libs\data_structures C:\Users\elite\CLionProjects\main\cmake-build-debug C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures C:\Users\elite\CLionProjects\main\cmake-build-debug\Libs\data_structures\CMakeFiles\data_structures.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Libs/data_structures/CMakeFiles/data_structures.dir/depend

