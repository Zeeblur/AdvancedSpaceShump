# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/zoe/bin/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/zoe/bin/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zoe/advancedspaceshump

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zoe/advancedspaceshump/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Astral_Insanity_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Astral_Insanity_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Astral_Insanity_main.dir/flags.make

CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o: CMakeFiles/Astral_Insanity_main.dir/flags.make
CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o: ../src/GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zoe/advancedspaceshump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o -c /home/zoe/advancedspaceshump/src/GameObject.cpp

CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zoe/advancedspaceshump/src/GameObject.cpp > CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.i

CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zoe/advancedspaceshump/src/GameObject.cpp -o CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.s

CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o.requires:

.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o.requires

CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o.provides: CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o.requires
	$(MAKE) -f CMakeFiles/Astral_Insanity_main.dir/build.make CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o.provides.build
.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o.provides

CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o.provides.build: CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o


CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o: CMakeFiles/Astral_Insanity_main.dir/flags.make
CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o: ../src/GameState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zoe/advancedspaceshump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o -c /home/zoe/advancedspaceshump/src/GameState.cpp

CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zoe/advancedspaceshump/src/GameState.cpp > CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.i

CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zoe/advancedspaceshump/src/GameState.cpp -o CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.s

CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o.requires:

.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o.requires

CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o.provides: CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o.requires
	$(MAKE) -f CMakeFiles/Astral_Insanity_main.dir/build.make CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o.provides.build
.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o.provides

CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o.provides.build: CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o


CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o: CMakeFiles/Astral_Insanity_main.dir/flags.make
CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o: ../src/PlayState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zoe/advancedspaceshump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o -c /home/zoe/advancedspaceshump/src/PlayState.cpp

CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zoe/advancedspaceshump/src/PlayState.cpp > CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.i

CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zoe/advancedspaceshump/src/PlayState.cpp -o CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.s

CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o.requires:

.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o.requires

CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o.provides: CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o.requires
	$(MAKE) -f CMakeFiles/Astral_Insanity_main.dir/build.make CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o.provides.build
.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o.provides

CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o.provides.build: CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o


CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o: CMakeFiles/Astral_Insanity_main.dir/flags.make
CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o: ../src/StartState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zoe/advancedspaceshump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o -c /home/zoe/advancedspaceshump/src/StartState.cpp

CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zoe/advancedspaceshump/src/StartState.cpp > CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.i

CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zoe/advancedspaceshump/src/StartState.cpp -o CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.s

CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o.requires:

.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o.requires

CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o.provides: CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o.requires
	$(MAKE) -f CMakeFiles/Astral_Insanity_main.dir/build.make CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o.provides.build
.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o.provides

CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o.provides.build: CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o


CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o: CMakeFiles/Astral_Insanity_main.dir/flags.make
CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o: ../src/StateManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zoe/advancedspaceshump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o -c /home/zoe/advancedspaceshump/src/StateManager.cpp

CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zoe/advancedspaceshump/src/StateManager.cpp > CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.i

CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zoe/advancedspaceshump/src/StateManager.cpp -o CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.s

CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o.requires:

.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o.requires

CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o.provides: CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/Astral_Insanity_main.dir/build.make CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o.provides.build
.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o.provides

CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o.provides.build: CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o


CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o: CMakeFiles/Astral_Insanity_main.dir/flags.make
CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zoe/advancedspaceshump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o -c /home/zoe/advancedspaceshump/src/main.cpp

CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zoe/advancedspaceshump/src/main.cpp > CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.i

CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zoe/advancedspaceshump/src/main.cpp -o CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.s

CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o.requires

CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o.provides: CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Astral_Insanity_main.dir/build.make CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o.provides

CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o.provides.build: CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o


# Object files for target Astral_Insanity_main
Astral_Insanity_main_OBJECTS = \
"CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o" \
"CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o" \
"CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o" \
"CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o" \
"CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o" \
"CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o"

# External object files for target Astral_Insanity_main
Astral_Insanity_main_EXTERNAL_OBJECTS =

bin/Astral_Insanity_main: CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o
bin/Astral_Insanity_main: CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o
bin/Astral_Insanity_main: CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o
bin/Astral_Insanity_main: CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o
bin/Astral_Insanity_main: CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o
bin/Astral_Insanity_main: CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o
bin/Astral_Insanity_main: CMakeFiles/Astral_Insanity_main.dir/build.make
bin/Astral_Insanity_main: CMakeFiles/Astral_Insanity_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zoe/advancedspaceshump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable bin/Astral_Insanity_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Astral_Insanity_main.dir/link.txt --verbose=$(VERBOSE)
	/home/zoe/bin/clion-2017.2.2/bin/cmake/bin/cmake -E copy_directory /home/zoe/advancedspaceshump/res /home/zoe/advancedspaceshump/cmake-build-debug/bin/res

# Rule to build all files generated by this target.
CMakeFiles/Astral_Insanity_main.dir/build: bin/Astral_Insanity_main

.PHONY : CMakeFiles/Astral_Insanity_main.dir/build

CMakeFiles/Astral_Insanity_main.dir/requires: CMakeFiles/Astral_Insanity_main.dir/src/GameObject.cpp.o.requires
CMakeFiles/Astral_Insanity_main.dir/requires: CMakeFiles/Astral_Insanity_main.dir/src/GameState.cpp.o.requires
CMakeFiles/Astral_Insanity_main.dir/requires: CMakeFiles/Astral_Insanity_main.dir/src/PlayState.cpp.o.requires
CMakeFiles/Astral_Insanity_main.dir/requires: CMakeFiles/Astral_Insanity_main.dir/src/StartState.cpp.o.requires
CMakeFiles/Astral_Insanity_main.dir/requires: CMakeFiles/Astral_Insanity_main.dir/src/StateManager.cpp.o.requires
CMakeFiles/Astral_Insanity_main.dir/requires: CMakeFiles/Astral_Insanity_main.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/Astral_Insanity_main.dir/requires

CMakeFiles/Astral_Insanity_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Astral_Insanity_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Astral_Insanity_main.dir/clean

CMakeFiles/Astral_Insanity_main.dir/depend:
	cd /home/zoe/advancedspaceshump/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zoe/advancedspaceshump /home/zoe/advancedspaceshump /home/zoe/advancedspaceshump/cmake-build-debug /home/zoe/advancedspaceshump/cmake-build-debug /home/zoe/advancedspaceshump/cmake-build-debug/CMakeFiles/Astral_Insanity_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Astral_Insanity_main.dir/depend
