# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /home/user/admin/softwares/clion2022/clion-2022.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/user/admin/softwares/clion2022/clion-2022.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/admin/repositories/cpp-lang/algorithm-training

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/admin/repositories/cpp-lang/algorithm-training/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/algorithm_training_2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/algorithm_training_2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/algorithm_training_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algorithm_training_2.dir/flags.make

CMakeFiles/algorithm_training_2.dir/main2.cpp.o: CMakeFiles/algorithm_training_2.dir/flags.make
CMakeFiles/algorithm_training_2.dir/main2.cpp.o: ../main2.cpp
CMakeFiles/algorithm_training_2.dir/main2.cpp.o: CMakeFiles/algorithm_training_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/admin/repositories/cpp-lang/algorithm-training/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algorithm_training_2.dir/main2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/algorithm_training_2.dir/main2.cpp.o -MF CMakeFiles/algorithm_training_2.dir/main2.cpp.o.d -o CMakeFiles/algorithm_training_2.dir/main2.cpp.o -c /home/user/admin/repositories/cpp-lang/algorithm-training/main2.cpp

CMakeFiles/algorithm_training_2.dir/main2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algorithm_training_2.dir/main2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/admin/repositories/cpp-lang/algorithm-training/main2.cpp > CMakeFiles/algorithm_training_2.dir/main2.cpp.i

CMakeFiles/algorithm_training_2.dir/main2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algorithm_training_2.dir/main2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/admin/repositories/cpp-lang/algorithm-training/main2.cpp -o CMakeFiles/algorithm_training_2.dir/main2.cpp.s

CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.o: CMakeFiles/algorithm_training_2.dir/flags.make
CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.o: ../src/main/clang/bin_tree_attempt/three_ele_method.cpp
CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.o: CMakeFiles/algorithm_training_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/admin/repositories/cpp-lang/algorithm-training/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.o -MF CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.o.d -o CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.o -c /home/user/admin/repositories/cpp-lang/algorithm-training/src/main/clang/bin_tree_attempt/three_ele_method.cpp

CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/admin/repositories/cpp-lang/algorithm-training/src/main/clang/bin_tree_attempt/three_ele_method.cpp > CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.i

CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/admin/repositories/cpp-lang/algorithm-training/src/main/clang/bin_tree_attempt/three_ele_method.cpp -o CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.s

# Object files for target algorithm_training_2
algorithm_training_2_OBJECTS = \
"CMakeFiles/algorithm_training_2.dir/main2.cpp.o" \
"CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.o"

# External object files for target algorithm_training_2
algorithm_training_2_EXTERNAL_OBJECTS =

algorithm_training_2: CMakeFiles/algorithm_training_2.dir/main2.cpp.o
algorithm_training_2: CMakeFiles/algorithm_training_2.dir/src/main/clang/bin_tree_attempt/three_ele_method.cpp.o
algorithm_training_2: CMakeFiles/algorithm_training_2.dir/build.make
algorithm_training_2: CMakeFiles/algorithm_training_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/admin/repositories/cpp-lang/algorithm-training/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable algorithm_training_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/algorithm_training_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algorithm_training_2.dir/build: algorithm_training_2
.PHONY : CMakeFiles/algorithm_training_2.dir/build

CMakeFiles/algorithm_training_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/algorithm_training_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/algorithm_training_2.dir/clean

CMakeFiles/algorithm_training_2.dir/depend:
	cd /home/user/admin/repositories/cpp-lang/algorithm-training/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/admin/repositories/cpp-lang/algorithm-training /home/user/admin/repositories/cpp-lang/algorithm-training /home/user/admin/repositories/cpp-lang/algorithm-training/cmake-build-debug /home/user/admin/repositories/cpp-lang/algorithm-training/cmake-build-debug /home/user/admin/repositories/cpp-lang/algorithm-training/cmake-build-debug/CMakeFiles/algorithm_training_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/algorithm_training_2.dir/depend

