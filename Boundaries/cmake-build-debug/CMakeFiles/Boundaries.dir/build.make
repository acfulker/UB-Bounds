# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/annasholk/CLionProjects/UB-Bounds/Boundaries

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Boundaries.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Boundaries.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Boundaries.dir/flags.make

CMakeFiles/Boundaries.dir/main.cpp.o: CMakeFiles/Boundaries.dir/flags.make
CMakeFiles/Boundaries.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Boundaries.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boundaries.dir/main.cpp.o -c /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/main.cpp

CMakeFiles/Boundaries.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boundaries.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/main.cpp > CMakeFiles/Boundaries.dir/main.cpp.i

CMakeFiles/Boundaries.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boundaries.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/main.cpp -o CMakeFiles/Boundaries.dir/main.cpp.s

CMakeFiles/Boundaries.dir/World.cpp.o: CMakeFiles/Boundaries.dir/flags.make
CMakeFiles/Boundaries.dir/World.cpp.o: ../World.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Boundaries.dir/World.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boundaries.dir/World.cpp.o -c /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/World.cpp

CMakeFiles/Boundaries.dir/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boundaries.dir/World.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/World.cpp > CMakeFiles/Boundaries.dir/World.cpp.i

CMakeFiles/Boundaries.dir/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boundaries.dir/World.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/World.cpp -o CMakeFiles/Boundaries.dir/World.cpp.s

CMakeFiles/Boundaries.dir/Agent.cpp.o: CMakeFiles/Boundaries.dir/flags.make
CMakeFiles/Boundaries.dir/Agent.cpp.o: ../Agent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Boundaries.dir/Agent.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boundaries.dir/Agent.cpp.o -c /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Agent.cpp

CMakeFiles/Boundaries.dir/Agent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boundaries.dir/Agent.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Agent.cpp > CMakeFiles/Boundaries.dir/Agent.cpp.i

CMakeFiles/Boundaries.dir/Agent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boundaries.dir/Agent.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Agent.cpp -o CMakeFiles/Boundaries.dir/Agent.cpp.s

CMakeFiles/Boundaries.dir/Coord.cpp.o: CMakeFiles/Boundaries.dir/flags.make
CMakeFiles/Boundaries.dir/Coord.cpp.o: ../Coord.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Boundaries.dir/Coord.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boundaries.dir/Coord.cpp.o -c /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Coord.cpp

CMakeFiles/Boundaries.dir/Coord.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boundaries.dir/Coord.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Coord.cpp > CMakeFiles/Boundaries.dir/Coord.cpp.i

CMakeFiles/Boundaries.dir/Coord.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boundaries.dir/Coord.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Coord.cpp -o CMakeFiles/Boundaries.dir/Coord.cpp.s

CMakeFiles/Boundaries.dir/Zone.cpp.o: CMakeFiles/Boundaries.dir/flags.make
CMakeFiles/Boundaries.dir/Zone.cpp.o: ../Zone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Boundaries.dir/Zone.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boundaries.dir/Zone.cpp.o -c /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Zone.cpp

CMakeFiles/Boundaries.dir/Zone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boundaries.dir/Zone.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Zone.cpp > CMakeFiles/Boundaries.dir/Zone.cpp.i

CMakeFiles/Boundaries.dir/Zone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boundaries.dir/Zone.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Zone.cpp -o CMakeFiles/Boundaries.dir/Zone.cpp.s

CMakeFiles/Boundaries.dir/Line.cpp.o: CMakeFiles/Boundaries.dir/flags.make
CMakeFiles/Boundaries.dir/Line.cpp.o: ../Line.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Boundaries.dir/Line.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boundaries.dir/Line.cpp.o -c /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Line.cpp

CMakeFiles/Boundaries.dir/Line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boundaries.dir/Line.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Line.cpp > CMakeFiles/Boundaries.dir/Line.cpp.i

CMakeFiles/Boundaries.dir/Line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boundaries.dir/Line.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/Line.cpp -o CMakeFiles/Boundaries.dir/Line.cpp.s

# Object files for target Boundaries
Boundaries_OBJECTS = \
"CMakeFiles/Boundaries.dir/main.cpp.o" \
"CMakeFiles/Boundaries.dir/World.cpp.o" \
"CMakeFiles/Boundaries.dir/Agent.cpp.o" \
"CMakeFiles/Boundaries.dir/Coord.cpp.o" \
"CMakeFiles/Boundaries.dir/Zone.cpp.o" \
"CMakeFiles/Boundaries.dir/Line.cpp.o"

# External object files for target Boundaries
Boundaries_EXTERNAL_OBJECTS =

Boundaries: CMakeFiles/Boundaries.dir/main.cpp.o
Boundaries: CMakeFiles/Boundaries.dir/World.cpp.o
Boundaries: CMakeFiles/Boundaries.dir/Agent.cpp.o
Boundaries: CMakeFiles/Boundaries.dir/Coord.cpp.o
Boundaries: CMakeFiles/Boundaries.dir/Zone.cpp.o
Boundaries: CMakeFiles/Boundaries.dir/Line.cpp.o
Boundaries: CMakeFiles/Boundaries.dir/build.make
Boundaries: CMakeFiles/Boundaries.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Boundaries"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Boundaries.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Boundaries.dir/build: Boundaries

.PHONY : CMakeFiles/Boundaries.dir/build

CMakeFiles/Boundaries.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Boundaries.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Boundaries.dir/clean

CMakeFiles/Boundaries.dir/depend:
	cd /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/annasholk/CLionProjects/UB-Bounds/Boundaries /Users/annasholk/CLionProjects/UB-Bounds/Boundaries /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug /Users/annasholk/CLionProjects/UB-Bounds/Boundaries/cmake-build-debug/CMakeFiles/Boundaries.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Boundaries.dir/depend

