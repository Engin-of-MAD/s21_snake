# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/roach/CLionProjects/untitled2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roach/CLionProjects/untitled2

# Include any dependencies generated for this target.
include models/UnionModule/CMakeFiles/UnionLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include models/UnionModule/CMakeFiles/UnionLib.dir/compiler_depend.make

# Include the progress variables for this target.
include models/UnionModule/CMakeFiles/UnionLib.dir/progress.make

# Include the compile flags for this target's objects.
include models/UnionModule/CMakeFiles/UnionLib.dir/flags.make

models/UnionModule/CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.o: models/UnionModule/CMakeFiles/UnionLib.dir/flags.make
models/UnionModule/CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.o: models/UnionModule/UnionLib_autogen/mocs_compilation.cpp
models/UnionModule/CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.o: models/UnionModule/CMakeFiles/UnionLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/roach/CLionProjects/untitled2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object models/UnionModule/CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.o"
	cd /home/roach/CLionProjects/untitled2/models/UnionModule && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT models/UnionModule/CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.o -MF CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.o -c /home/roach/CLionProjects/untitled2/models/UnionModule/UnionLib_autogen/mocs_compilation.cpp

models/UnionModule/CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.i"
	cd /home/roach/CLionProjects/untitled2/models/UnionModule && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roach/CLionProjects/untitled2/models/UnionModule/UnionLib_autogen/mocs_compilation.cpp > CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.i

models/UnionModule/CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.s"
	cd /home/roach/CLionProjects/untitled2/models/UnionModule && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roach/CLionProjects/untitled2/models/UnionModule/UnionLib_autogen/mocs_compilation.cpp -o CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.s

models/UnionModule/CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.o: models/UnionModule/CMakeFiles/UnionLib.dir/flags.make
models/UnionModule/CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.o: models/UnionModule/src/BaseBoardModel.cpp
models/UnionModule/CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.o: models/UnionModule/CMakeFiles/UnionLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/roach/CLionProjects/untitled2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object models/UnionModule/CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.o"
	cd /home/roach/CLionProjects/untitled2/models/UnionModule && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT models/UnionModule/CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.o -MF CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.o.d -o CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.o -c /home/roach/CLionProjects/untitled2/models/UnionModule/src/BaseBoardModel.cpp

models/UnionModule/CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.i"
	cd /home/roach/CLionProjects/untitled2/models/UnionModule && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roach/CLionProjects/untitled2/models/UnionModule/src/BaseBoardModel.cpp > CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.i

models/UnionModule/CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.s"
	cd /home/roach/CLionProjects/untitled2/models/UnionModule && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roach/CLionProjects/untitled2/models/UnionModule/src/BaseBoardModel.cpp -o CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.s

models/UnionModule/CMakeFiles/UnionLib.dir/src/Timer.cpp.o: models/UnionModule/CMakeFiles/UnionLib.dir/flags.make
models/UnionModule/CMakeFiles/UnionLib.dir/src/Timer.cpp.o: models/UnionModule/src/Timer.cpp
models/UnionModule/CMakeFiles/UnionLib.dir/src/Timer.cpp.o: models/UnionModule/CMakeFiles/UnionLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/roach/CLionProjects/untitled2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object models/UnionModule/CMakeFiles/UnionLib.dir/src/Timer.cpp.o"
	cd /home/roach/CLionProjects/untitled2/models/UnionModule && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT models/UnionModule/CMakeFiles/UnionLib.dir/src/Timer.cpp.o -MF CMakeFiles/UnionLib.dir/src/Timer.cpp.o.d -o CMakeFiles/UnionLib.dir/src/Timer.cpp.o -c /home/roach/CLionProjects/untitled2/models/UnionModule/src/Timer.cpp

models/UnionModule/CMakeFiles/UnionLib.dir/src/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/UnionLib.dir/src/Timer.cpp.i"
	cd /home/roach/CLionProjects/untitled2/models/UnionModule && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roach/CLionProjects/untitled2/models/UnionModule/src/Timer.cpp > CMakeFiles/UnionLib.dir/src/Timer.cpp.i

models/UnionModule/CMakeFiles/UnionLib.dir/src/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/UnionLib.dir/src/Timer.cpp.s"
	cd /home/roach/CLionProjects/untitled2/models/UnionModule && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roach/CLionProjects/untitled2/models/UnionModule/src/Timer.cpp -o CMakeFiles/UnionLib.dir/src/Timer.cpp.s

# Object files for target UnionLib
UnionLib_OBJECTS = \
"CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.o" \
"CMakeFiles/UnionLib.dir/src/Timer.cpp.o"

# External object files for target UnionLib
UnionLib_EXTERNAL_OBJECTS =

models/UnionModule/libUnionLib.so: models/UnionModule/CMakeFiles/UnionLib.dir/UnionLib_autogen/mocs_compilation.cpp.o
models/UnionModule/libUnionLib.so: models/UnionModule/CMakeFiles/UnionLib.dir/src/BaseBoardModel.cpp.o
models/UnionModule/libUnionLib.so: models/UnionModule/CMakeFiles/UnionLib.dir/src/Timer.cpp.o
models/UnionModule/libUnionLib.so: models/UnionModule/CMakeFiles/UnionLib.dir/build.make
models/UnionModule/libUnionLib.so: models/UnionModule/CMakeFiles/UnionLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/roach/CLionProjects/untitled2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libUnionLib.so"
	cd /home/roach/CLionProjects/untitled2/models/UnionModule && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UnionLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
models/UnionModule/CMakeFiles/UnionLib.dir/build: models/UnionModule/libUnionLib.so
.PHONY : models/UnionModule/CMakeFiles/UnionLib.dir/build

models/UnionModule/CMakeFiles/UnionLib.dir/clean:
	cd /home/roach/CLionProjects/untitled2/models/UnionModule && $(CMAKE_COMMAND) -P CMakeFiles/UnionLib.dir/cmake_clean.cmake
.PHONY : models/UnionModule/CMakeFiles/UnionLib.dir/clean

models/UnionModule/CMakeFiles/UnionLib.dir/depend:
	cd /home/roach/CLionProjects/untitled2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roach/CLionProjects/untitled2 /home/roach/CLionProjects/untitled2/models/UnionModule /home/roach/CLionProjects/untitled2 /home/roach/CLionProjects/untitled2/models/UnionModule /home/roach/CLionProjects/untitled2/models/UnionModule/CMakeFiles/UnionLib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : models/UnionModule/CMakeFiles/UnionLib.dir/depend

