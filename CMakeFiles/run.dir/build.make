# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/pi/raspi_project_16

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/raspi_project_16

# Include any dependencies generated for this target.
include CMakeFiles/run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run.dir/flags.make

CMakeFiles/run.dir/src/main.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/raspi_project_16/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/main.cpp.o -c /home/pi/raspi_project_16/src/main.cpp

CMakeFiles/run.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/raspi_project_16/src/main.cpp > CMakeFiles/run.dir/src/main.cpp.i

CMakeFiles/run.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/raspi_project_16/src/main.cpp -o CMakeFiles/run.dir/src/main.cpp.s

CMakeFiles/run.dir/src/dispatchEventService.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/dispatchEventService.cpp.o: src/dispatchEventService.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/raspi_project_16/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run.dir/src/dispatchEventService.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/dispatchEventService.cpp.o -c /home/pi/raspi_project_16/src/dispatchEventService.cpp

CMakeFiles/run.dir/src/dispatchEventService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/dispatchEventService.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/raspi_project_16/src/dispatchEventService.cpp > CMakeFiles/run.dir/src/dispatchEventService.cpp.i

CMakeFiles/run.dir/src/dispatchEventService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/dispatchEventService.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/raspi_project_16/src/dispatchEventService.cpp -o CMakeFiles/run.dir/src/dispatchEventService.cpp.s

CMakeFiles/run.dir/src/event.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/event.cpp.o: src/event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/raspi_project_16/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/run.dir/src/event.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/event.cpp.o -c /home/pi/raspi_project_16/src/event.cpp

CMakeFiles/run.dir/src/event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/event.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/raspi_project_16/src/event.cpp > CMakeFiles/run.dir/src/event.cpp.i

CMakeFiles/run.dir/src/event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/event.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/raspi_project_16/src/event.cpp -o CMakeFiles/run.dir/src/event.cpp.s

CMakeFiles/run.dir/src/events_def.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/events_def.cpp.o: src/events_def.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/raspi_project_16/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/run.dir/src/events_def.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/events_def.cpp.o -c /home/pi/raspi_project_16/src/events_def.cpp

CMakeFiles/run.dir/src/events_def.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/events_def.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/raspi_project_16/src/events_def.cpp > CMakeFiles/run.dir/src/events_def.cpp.i

CMakeFiles/run.dir/src/events_def.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/events_def.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/raspi_project_16/src/events_def.cpp -o CMakeFiles/run.dir/src/events_def.cpp.s

CMakeFiles/run.dir/src/ledEventHandler.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/ledEventHandler.cpp.o: src/ledEventHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/raspi_project_16/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/run.dir/src/ledEventHandler.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/ledEventHandler.cpp.o -c /home/pi/raspi_project_16/src/ledEventHandler.cpp

CMakeFiles/run.dir/src/ledEventHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/ledEventHandler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/raspi_project_16/src/ledEventHandler.cpp > CMakeFiles/run.dir/src/ledEventHandler.cpp.i

CMakeFiles/run.dir/src/ledEventHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/ledEventHandler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/raspi_project_16/src/ledEventHandler.cpp -o CMakeFiles/run.dir/src/ledEventHandler.cpp.s

CMakeFiles/run.dir/src/soundEventHandler.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/soundEventHandler.cpp.o: src/soundEventHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/raspi_project_16/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/run.dir/src/soundEventHandler.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/soundEventHandler.cpp.o -c /home/pi/raspi_project_16/src/soundEventHandler.cpp

CMakeFiles/run.dir/src/soundEventHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/soundEventHandler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/raspi_project_16/src/soundEventHandler.cpp > CMakeFiles/run.dir/src/soundEventHandler.cpp.i

CMakeFiles/run.dir/src/soundEventHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/soundEventHandler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/raspi_project_16/src/soundEventHandler.cpp -o CMakeFiles/run.dir/src/soundEventHandler.cpp.s

CMakeFiles/run.dir/src/ws2811EventHandler.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/ws2811EventHandler.cpp.o: src/ws2811EventHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/raspi_project_16/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/run.dir/src/ws2811EventHandler.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/ws2811EventHandler.cpp.o -c /home/pi/raspi_project_16/src/ws2811EventHandler.cpp

CMakeFiles/run.dir/src/ws2811EventHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/ws2811EventHandler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/raspi_project_16/src/ws2811EventHandler.cpp > CMakeFiles/run.dir/src/ws2811EventHandler.cpp.i

CMakeFiles/run.dir/src/ws2811EventHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/ws2811EventHandler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/raspi_project_16/src/ws2811EventHandler.cpp -o CMakeFiles/run.dir/src/ws2811EventHandler.cpp.s

CMakeFiles/run.dir/src/cameraEventHandler.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/cameraEventHandler.cpp.o: src/cameraEventHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/raspi_project_16/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/run.dir/src/cameraEventHandler.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/cameraEventHandler.cpp.o -c /home/pi/raspi_project_16/src/cameraEventHandler.cpp

CMakeFiles/run.dir/src/cameraEventHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/cameraEventHandler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/raspi_project_16/src/cameraEventHandler.cpp > CMakeFiles/run.dir/src/cameraEventHandler.cpp.i

CMakeFiles/run.dir/src/cameraEventHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/cameraEventHandler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/raspi_project_16/src/cameraEventHandler.cpp -o CMakeFiles/run.dir/src/cameraEventHandler.cpp.s

# Object files for target run
run_OBJECTS = \
"CMakeFiles/run.dir/src/main.cpp.o" \
"CMakeFiles/run.dir/src/dispatchEventService.cpp.o" \
"CMakeFiles/run.dir/src/event.cpp.o" \
"CMakeFiles/run.dir/src/events_def.cpp.o" \
"CMakeFiles/run.dir/src/ledEventHandler.cpp.o" \
"CMakeFiles/run.dir/src/soundEventHandler.cpp.o" \
"CMakeFiles/run.dir/src/ws2811EventHandler.cpp.o" \
"CMakeFiles/run.dir/src/cameraEventHandler.cpp.o"

# External object files for target run
run_EXTERNAL_OBJECTS =

run: CMakeFiles/run.dir/src/main.cpp.o
run: CMakeFiles/run.dir/src/dispatchEventService.cpp.o
run: CMakeFiles/run.dir/src/event.cpp.o
run: CMakeFiles/run.dir/src/events_def.cpp.o
run: CMakeFiles/run.dir/src/ledEventHandler.cpp.o
run: CMakeFiles/run.dir/src/soundEventHandler.cpp.o
run: CMakeFiles/run.dir/src/ws2811EventHandler.cpp.o
run: CMakeFiles/run.dir/src/cameraEventHandler.cpp.o
run: CMakeFiles/run.dir/build.make
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_gapi.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_stitching.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_aruco.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_barcode.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_bgsegm.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_bioinspired.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_ccalib.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_dnn_objdetect.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_dnn_superres.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_dpm.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_face.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_freetype.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_fuzzy.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_hfs.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_img_hash.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_intensity_transform.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_line_descriptor.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_mcc.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_quality.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_rapid.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_reg.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_rgbd.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_saliency.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_stereo.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_structured_light.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_superres.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_surface_matching.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_tracking.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_videostab.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_wechat_qrcode.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_xfeatures2d.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_xobjdetect.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_xphoto.so.4.5.5
run: /usr/local/lib/libwiringPi.so
run: /usr/local/lib/libpigpio.so
run: /usr/local/lib/libcpptimer.a
run: /usr/local/lib/libws2811.a
run: /usr/lib/arm-linux-gnueabihf/librt.so
run: /usr/local/lib/arm-linux-gnueabihf/libglog.so
run: /usr/lib/arm-linux-gnueabihf/libpthread.so
run: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.a
run: /usr/lib/arm-linux-gnueabihf/libboost_system.a
run: /usr/lib/arm-linux-gnueabihf/libboost_thread.a
run: /usr/local/lib/libraspicam.so
run: /usr/local/lib/libraspicam_cv.so
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_shape.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_highgui.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_datasets.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_plot.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_text.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_ml.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_phase_unwrapping.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_optflow.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_ximgproc.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_video.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_videoio.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_imgcodecs.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_objdetect.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_calib3d.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_dnn.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_features2d.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_flann.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_photo.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_imgproc.so.4.5.5
run: /usr/local/lib/arm-linux-gnueabihf/libopencv_core.so.4.5.5
run: /usr/lib/arm-linux-gnueabihf/libboost_atomic.a
run: CMakeFiles/run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/raspi_project_16/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run.dir/build: run

.PHONY : CMakeFiles/run.dir/build

CMakeFiles/run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run.dir/clean

CMakeFiles/run.dir/depend:
	cd /home/pi/raspi_project_16 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/raspi_project_16 /home/pi/raspi_project_16 /home/pi/raspi_project_16 /home/pi/raspi_project_16 /home/pi/raspi_project_16/CMakeFiles/run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run.dir/depend

