# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\happy\Myalgorithm\Algorithm\algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1940.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/1940.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/1940.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1940.dir/flags.make

CMakeFiles/1940.dir/BOJ/1940.cpp.obj: CMakeFiles/1940.dir/flags.make
CMakeFiles/1940.dir/BOJ/1940.cpp.obj: C:/Users/happy/Myalgorithm/Algorithm/algorithm/BOJ/1940.cpp
CMakeFiles/1940.dir/BOJ/1940.cpp.obj: CMakeFiles/1940.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1940.dir/BOJ/1940.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/1940.dir/BOJ/1940.cpp.obj -MF CMakeFiles\1940.dir\BOJ\1940.cpp.obj.d -o CMakeFiles\1940.dir\BOJ\1940.cpp.obj -c C:\Users\happy\Myalgorithm\Algorithm\algorithm\BOJ\1940.cpp

CMakeFiles/1940.dir/BOJ/1940.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1940.dir/BOJ/1940.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\happy\Myalgorithm\Algorithm\algorithm\BOJ\1940.cpp > CMakeFiles\1940.dir\BOJ\1940.cpp.i

CMakeFiles/1940.dir/BOJ/1940.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1940.dir/BOJ/1940.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\happy\Myalgorithm\Algorithm\algorithm\BOJ\1940.cpp -o CMakeFiles\1940.dir\BOJ\1940.cpp.s

# Object files for target 1940
1940_OBJECTS = \
"CMakeFiles/1940.dir/BOJ/1940.cpp.obj"

# External object files for target 1940
1940_EXTERNAL_OBJECTS =

1940.exe: CMakeFiles/1940.dir/BOJ/1940.cpp.obj
1940.exe: CMakeFiles/1940.dir/build.make
1940.exe: CMakeFiles/1940.dir/linkLibs.rsp
1940.exe: CMakeFiles/1940.dir/objects1
1940.exe: CMakeFiles/1940.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1940.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\1940.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1940.dir/build: 1940.exe
.PHONY : CMakeFiles/1940.dir/build

CMakeFiles/1940.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1940.dir\cmake_clean.cmake
.PHONY : CMakeFiles/1940.dir/clean

CMakeFiles/1940.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\happy\Myalgorithm\Algorithm\algorithm C:\Users\happy\Myalgorithm\Algorithm\algorithm C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug\CMakeFiles\1940.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1940.dir/depend

