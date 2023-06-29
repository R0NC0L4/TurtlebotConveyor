# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "conveyor_description_pkg: 3 messages, 0 services")

set(MSG_I_FLAGS "-Iconveyor_description_pkg:/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg;-Istd_msgs:/usr/local/MATLAB/R2022b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(conveyor_description_pkg_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/buttons.msg" NAME_WE)
add_custom_target(_conveyor_description_pkg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "conveyor_description_pkg" "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/buttons.msg" ""
)

get_filename_component(_filename "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/conveyor_state.msg" NAME_WE)
add_custom_target(_conveyor_description_pkg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "conveyor_description_pkg" "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/conveyor_state.msg" ""
)

get_filename_component(_filename "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/desired_conf.msg" NAME_WE)
add_custom_target(_conveyor_description_pkg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "conveyor_description_pkg" "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/desired_conf.msg" ""
)

#
#  langs = gencpp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(conveyor_description_pkg
  "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/buttons.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/conveyor_description_pkg
)
_generate_msg_cpp(conveyor_description_pkg
  "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/conveyor_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/conveyor_description_pkg
)
_generate_msg_cpp(conveyor_description_pkg
  "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/desired_conf.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/conveyor_description_pkg
)

### Generating Services

### Generating Module File
_generate_module_cpp(conveyor_description_pkg
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/conveyor_description_pkg
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(conveyor_description_pkg_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(conveyor_description_pkg_generate_messages conveyor_description_pkg_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/buttons.msg" NAME_WE)
add_dependencies(conveyor_description_pkg_generate_messages_cpp _conveyor_description_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/conveyor_state.msg" NAME_WE)
add_dependencies(conveyor_description_pkg_generate_messages_cpp _conveyor_description_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/desired_conf.msg" NAME_WE)
add_dependencies(conveyor_description_pkg_generate_messages_cpp _conveyor_description_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(conveyor_description_pkg_gencpp)
add_dependencies(conveyor_description_pkg_gencpp conveyor_description_pkg_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS conveyor_description_pkg_generate_messages_cpp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(conveyor_description_pkg
  "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/buttons.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/conveyor_description_pkg
)
_generate_msg_py(conveyor_description_pkg
  "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/conveyor_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/conveyor_description_pkg
)
_generate_msg_py(conveyor_description_pkg
  "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/desired_conf.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/conveyor_description_pkg
)

### Generating Services

### Generating Module File
_generate_module_py(conveyor_description_pkg
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/conveyor_description_pkg
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(conveyor_description_pkg_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(conveyor_description_pkg_generate_messages conveyor_description_pkg_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/buttons.msg" NAME_WE)
add_dependencies(conveyor_description_pkg_generate_messages_py _conveyor_description_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/conveyor_state.msg" NAME_WE)
add_dependencies(conveyor_description_pkg_generate_messages_py _conveyor_description_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/andre/catkin_ws/src/TurtlebotConveyor/matlab_msg_gen_ros1/glnxa64/src/conveyor_description_pkg/msg/desired_conf.msg" NAME_WE)
add_dependencies(conveyor_description_pkg_generate_messages_py _conveyor_description_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(conveyor_description_pkg_genpy)
add_dependencies(conveyor_description_pkg_genpy conveyor_description_pkg_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS conveyor_description_pkg_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/conveyor_description_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/conveyor_description_pkg
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(conveyor_description_pkg_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/conveyor_description_pkg)
  install(CODE "execute_process(COMMAND \"/home/andre/.matlab/R2022b/ros1/glnxa64/venv/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/conveyor_description_pkg\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/conveyor_description_pkg
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(conveyor_description_pkg_generate_messages_py std_msgs_generate_messages_py)
endif()
