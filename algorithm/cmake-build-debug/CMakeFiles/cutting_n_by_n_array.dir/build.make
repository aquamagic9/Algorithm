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
include CMakeFiles/cutting_n_by_n_array.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cutting_n_by_n_array.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cutting_n_by_n_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cutting_n_by_n_array.dir/flags.make

CMakeFiles/cutting_n_by_n_array.dir/Programmers/cutting_n_by_n_array.cpp.obj: CMakeFiles/cutting_n_by_n_array.dir/flags.make
CMakeFiles/cutting_n_by_n_array.dir/Programmers/cutting_n_by_n_array.cpp.obj: C:/Users/happy/Myalgorithm/Algorithm/algorithm/Programmers/cutting_n_by_n_array.cpp
CMakeFiles/cutting_n_by_n_array.dir/Programmers/cutting_n_by_n_array.cpp.obj: CMakeFiles/cutting_n_by_n_array.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cutting_n_by_n_array.dir/Programmers/cutting_n_by_n_array.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cutting_n_by_n_array.dir/Programmers/cutting_n_by_n_array.cpp.obj -MF CMakeFiles\cutting_n_by_n_array.dir\Programmers\cutting_n_by_n_array.cpp.obj.d -o CMakeFiles\cutting_n_by_n_array.dir\Programmers\cutting_n_by_n_array.cpp.obj -c C:\Users\happy\Myalgorithm\Algorithm\algorithm\Programmers\cutting_n_by_n_array.cpp

CMakeFiles/cutting_n_by_n_array.dir/Programmers/cutting_n_by_n_array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutting_n_by_n_array.dir/Programmers/cutting_n_by_n_array.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\happy\Myalgorithm\Algorithm\algorithm\Programmers\cutting_n_by_n_array.cpp > CMakeFiles\cutting_n_by_n_array.dir\Programmers\cutting_n_by_n_array.cpp.i

CMakeFiles/cutting_n_by_n_array.dir/Programmers/cutting_n_by_n_array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutting_n_by_n_array.dir/Programmers/cutting_n_by_n_array.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\happy\Myalgorithm\Algorithm\algorithm\Programmers\cutting_n_by_n_array.cpp -o CMakeFiles\cutting_n_by_n_array.dir\Programmers\cutting_n_by_n_array.cpp.s

# Object files for target cutting_n_by_n_array
cutting_n_by_n_array_OBJECTS = \
"CMakeFiles/cutting_n_by_n_array.dir/Programmers/cutting_n_by_n_array.cpp.obj"

# External object files for target cutting_n_by_n_array
cutting_n_by_n_array_EXTERNAL_OBJECTS =

cutting_n_by_n_array.exe: CMakeFiles/cutting_n_by_n_array.dir/Programmers/cutting_n_by_n_array.cpp.obj
cutting_n_by_n_array.exe: CMakeFiles/cutting_n_by_n_array.dir/build.make
cutting_n_by_n_array.exe: CMakeFiles/cutting_n_by_n_array.dir/linkLibs.rsp
cutting_n_by_n_array.exe: CMakeFiles/cutting_n_by_n_array.dir/objects1
cutting_n_by_n_array.exe: CMakeFiles/cutting_n_by_n_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cutting_n_by_n_array.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cutting_n_by_n_array.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cutting_n_by_n_array.dir/build: cutting_n_by_n_array.exe
.PHONY : CMakeFiles/cutting_n_by_n_array.dir/build

CMakeFiles/cutting_n_by_n_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cutting_n_by_n_array.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cutting_n_by_n_array.dir/clean

CMakeFiles/cutting_n_by_n_array.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\happy\Myalgorithm\Algorithm\algorithm C:\Users\happy\Myalgorithm\Algorithm\algorithm C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug\CMakeFiles\cutting_n_by_n_array.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cutting_n_by_n_array.dir/depend

