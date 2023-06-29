# Install script for directory: /home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/conveyor_description_pkg/msg" TYPE FILE FILES
    "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/buttons.msg"
    "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/conveyor_state.msg"
    "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/desired_conf.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/conveyor_description_pkg/cmake" TYPE FILE FILES "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/build/conveyor_description_pkg/catkin_generated/installspace/conveyor_description_pkg-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/devel/include/conveyor_description_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/home/andre/.matlab/R2022b/ros1/glnxa64/venv/bin/python3" -m compileall "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/devel/lib/python3/dist-packages/conveyor_description_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/devel/lib/python3/dist-packages/conveyor_description_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/build/conveyor_description_pkg/catkin_generated/installspace/conveyor_description_pkg.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/conveyor_description_pkg/cmake" TYPE FILE FILES "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/build/conveyor_description_pkg/catkin_generated/installspace/conveyor_description_pkg-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/conveyor_description_pkg/cmake" TYPE FILE FILES
    "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/build/conveyor_description_pkg/catkin_generated/installspace/conveyor_description_pkgConfig.cmake"
    "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/build/conveyor_description_pkg/catkin_generated/installspace/conveyor_description_pkgConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/conveyor_description_pkg" TYPE FILE FILES "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/include/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/devel/lib/libconveyor_description_pkg_matlab.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libconveyor_description_pkg_matlab.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libconveyor_description_pkg_matlab.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libconveyor_description_pkg_matlab.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/m/" TYPE DIRECTORY FILES "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/m/" FILES_MATCHING REGEX "/[^/]*\\.m$")
endif()

