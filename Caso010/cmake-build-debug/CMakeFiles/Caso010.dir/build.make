# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\gollo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.32\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\gollo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.32\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Caso010.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Caso010.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Caso010.dir/flags.make

CMakeFiles/Caso010.dir/main.c.obj: CMakeFiles/Caso010.dir/flags.make
CMakeFiles/Caso010.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Caso010.dir/main.c.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Caso010.dir\main.c.obj   -c "C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010\main.c"

CMakeFiles/Caso010.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Caso010.dir/main.c.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010\main.c" > CMakeFiles\Caso010.dir\main.c.i

CMakeFiles/Caso010.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Caso010.dir/main.c.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010\main.c" -o CMakeFiles\Caso010.dir\main.c.s

# Object files for target Caso010
Caso010_OBJECTS = \
"CMakeFiles/Caso010.dir/main.c.obj"

# External object files for target Caso010
Caso010_EXTERNAL_OBJECTS =

Caso010.exe: CMakeFiles/Caso010.dir/main.c.obj
Caso010.exe: CMakeFiles/Caso010.dir/build.make
Caso010.exe: CMakeFiles/Caso010.dir/linklibs.rsp
Caso010.exe: CMakeFiles/Caso010.dir/objects1.rsp
Caso010.exe: CMakeFiles/Caso010.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Caso010.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Caso010.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Caso010.dir/build: Caso010.exe

.PHONY : CMakeFiles/Caso010.dir/build

CMakeFiles/Caso010.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Caso010.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Caso010.dir/clean

CMakeFiles/Caso010.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010" "C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010" "C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010\cmake-build-debug" "C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010\cmake-build-debug" "C:\Users\gollo\Documents\Universidad\2019 Semestre II\Analisis de Algoritmos\Caso-010\Caso010\cmake-build-debug\CMakeFiles\Caso010.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Caso010.dir/depend

