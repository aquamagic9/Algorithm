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
include CMakeFiles/english_word_chain.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/english_word_chain.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/english_word_chain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/english_word_chain.dir/flags.make

CMakeFiles/english_word_chain.dir/Programmers/english_word_chain.cpp.obj: CMakeFiles/english_word_chain.dir/flags.make
CMakeFiles/english_word_chain.dir/Programmers/english_word_chain.cpp.obj: C:/Users/happy/Myalgorithm/Algorithm/algorithm/Programmers/english_word_chain.cpp
CMakeFiles/english_word_chain.dir/Programmers/english_word_chain.cpp.obj: CMakeFiles/english_word_chain.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/english_word_chain.dir/Programmers/english_word_chain.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/english_word_chain.dir/Programmers/english_word_chain.cpp.obj -MF CMakeFiles\english_word_chain.dir\Programmers\english_word_chain.cpp.obj.d -o CMakeFiles\english_word_chain.dir\Programmers\english_word_chain.cpp.obj -c C:\Users\happy\Myalgorithm\Algorithm\algorithm\Programmers\english_word_chain.cpp

CMakeFiles/english_word_chain.dir/Programmers/english_word_chain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/english_word_chain.dir/Programmers/english_word_chain.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\happy\Myalgorithm\Algorithm\algorithm\Programmers\english_word_chain.cpp > CMakeFiles\english_word_chain.dir\Programmers\english_word_chain.cpp.i

CMakeFiles/english_word_chain.dir/Programmers/english_word_chain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/english_word_chain.dir/Programmers/english_word_chain.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\happy\Myalgorithm\Algorithm\algorithm\Programmers\english_word_chain.cpp -o CMakeFiles\english_word_chain.dir\Programmers\english_word_chain.cpp.s

# Object files for target english_word_chain
english_word_chain_OBJECTS = \
"CMakeFiles/english_word_chain.dir/Programmers/english_word_chain.cpp.obj"

# External object files for target english_word_chain
english_word_chain_EXTERNAL_OBJECTS =

english_word_chain.exe: CMakeFiles/english_word_chain.dir/Programmers/english_word_chain.cpp.obj
english_word_chain.exe: CMakeFiles/english_word_chain.dir/build.make
english_word_chain.exe: CMakeFiles/english_word_chain.dir/linkLibs.rsp
english_word_chain.exe: CMakeFiles/english_word_chain.dir/objects1
english_word_chain.exe: CMakeFiles/english_word_chain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable english_word_chain.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\english_word_chain.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/english_word_chain.dir/build: english_word_chain.exe
.PHONY : CMakeFiles/english_word_chain.dir/build

CMakeFiles/english_word_chain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\english_word_chain.dir\cmake_clean.cmake
.PHONY : CMakeFiles/english_word_chain.dir/clean

CMakeFiles/english_word_chain.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\happy\Myalgorithm\Algorithm\algorithm C:\Users\happy\Myalgorithm\Algorithm\algorithm C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug C:\Users\happy\Myalgorithm\Algorithm\algorithm\cmake-build-debug\CMakeFiles\english_word_chain.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/english_word_chain.dir/depend

