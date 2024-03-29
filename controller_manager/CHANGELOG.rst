^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package controller_manager
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.19.6 (2022-10-21)
-------------------
* SPAWNER: Wait for the clock to be available before proceeding (`#432 <https://github.com/ros-controls/ros_control/issues/432>`_)
  This patch is to resolve an issue when the simulated clock is not published right away (coming from a remote gazebo instance for example).
  If the clock is not published right away, the rosservice wait_for_service times out prematurely and the controllers fail to be loaded since the system is not yet ready (no Gazebo clock).
  With no, gazebo system, the clock will be ready immediately and the spawner will proceed.
  Issue: `#431 <https://github.com/ros-controls/ros_control/issues/431>`_
* Contributors: Guillaume Autran

0.19.5 (2021-06-16)
-------------------
* Add wall clock timeout to avoid some deadlock situation when switching mode (`#491 <https://github.com/ros-controls/ros_control/issues/491>`_)
  Co-authored-by: Krishna <chaitanyaradon89@gmail.com>
* Contributors: Bence Magyar

0.19.4 (2020-12-05)
-------------------

0.19.3 (2020-10-11)
-------------------

0.19.2 (2020-08-17)
-------------------

0.19.1 (2020-05-10)
-------------------
* Function specifiers noetic (`#453 <https://github.com/ros-controls/ros_control/issues/453>`_)
  * Add override specifiers & default constructors
  * Delete ControllerBase copy & move ctors
  * Remove unnecessary default constructors
  * Modernize additional constructors
  * Revert ImuSensorHandle::Data::Data() = default
  * Remove unnecessary default overridden constructors
  * Remove semicolon after function body
  Co-authored-by: Matt Reynolds <mtreynolds@uwaterloo.ca>
* Use setuptools instead of distutils (`#429 <https://github.com/ros-controls/ros_control/issues/429>`_)
* Contributors: Bence Magyar, Matt Reynolds

0.19.0 (2020-04-23)
-------------------
* Replace enums with enum classes (`#412 <https://github.com/ros-controls/ros_control/issues/412>`_)
* Contributors: Matt Reynolds

0.18.0 (2020-04-16)
-------------------
* enable spawner to wait indefinitely if requested (`#428 <https://github.com/ros-controls/ros_control/issues/428>`_)
  `rospy.wait_for_service` does not allow for `0` to wait indefinitely.
  Instead, `None` has to be passed explicitly.
  By personal request of three maintainers extended to include documentation
  and the alternative argument --no-timeout.
* Bump CMake version to avoid CMP0048 (`#427 <https://github.com/ros-controls/ros_control/issues/427>`_)
* Contributors: Michael Görner, Shane Loretz

0.17.0 (2020-02-24)
-------------------
* Use auto keyword
* Use default member initializers
* Replace boost with std
* Replace boost mutexes & locks with std
* Replace boost::bind with std::bind
* Contributors: AbhinavSingh, Bence Magyar, Matt Reynolds, suab321321

0.16.0 (2020-01-27)
-------------------
* Use range-based for loops in controller_manager
* Resolve Boost dependency issues
* Update dependencies
  - Dependencies needed to compile are <build_depend>
  - Dependencies used in public headers are <build_export_depend>
  - Dependencies needed to link or run are <exec_depend>
* Merge branch 'melodic-devel' into catkin-lint
* Add ${catkin_EXPORTED_TARGETS} dependencies
* Update package dependencies
* Add missing roscpp & rospy dependencies
* Prefer nullptr for null pointers
* Replace header guard with #pragma once
* Apply consistent style to CMakeLists.txt files
* Apply consistent style to package.xml files
* Fix build error in clang error: non-aggregate type 'std::vector' (aka 'vector >') cannot be initialized with an initializer list
* Multi-update cycle mode switch (`#391 <https://github.com/ros-controls/ros_control/issues/391>`_)
  For more info: https://github.com/pal-robotics-forks/ros_control2/pull/5
  * Added tests for ControllerManager update
  * Mocks for controllers and controller loader in update test
  * Divided in tests with and without controllers
  * Controller state initialized in mock
  * Moved mocks to test class
  * All tests using mock class
  * Test for multiple updates in a single controller
  * Added new switchResult() function to RobotHW interface
  ControllerManager uses this function to wait for the result of the
  doSwitch() before starting the new set of controllers
  * Using ranged based loops
  * Switch is now managed in a separate function
  * Option to start controllers as soon as their joints are ready after a switch
  * Tests for controller_interface API
  * Added new STOPPED, WAITING and ABORTED states to ControllerBase
  * Split manageSwitch() into smaller functions
  * Abort pending controllers in case of switch error
  * Changed default behaviour of new switch param
  This way if it not set it will be the same behaviour as previous version
  * Added timeout parameter to switch controller
  * Removed unnecessary includes
  * Using target_include_directories for the test
  * std::all_of instead of std::count_if
  * Deleted autogenerated file
  * Adapted tests to changes in controller_manager
  * Adapted python implementation to new parameters in SwitchController
  * Added missing parameter description docstring
  * Moved all parameters used for switching to a separate object
  * Moved error messages to controller_base
  * State check functions are now const
  * Removed unnecessary comments
  * Added constants for start_asap and timeout default parameters values
* Remove extra {
* Adding Pal Robotics to copyright notice
  Co-Authored-By: Bence Magyar <bence.magyar.robotics@gmail.com>
* Added constants for start_asap and timeout default parameters values
* Moved error messages to controller_base
* Moved all parameters used for switching to a separate object
* Added missing parameter description docstring
* Adapted python implementation to new parameters in SwitchController
* Deleted autogenerated file
* std::all_of instead of std::count_if
* Cosmetics
* Fixed lincenses
* Removed unnecessary includes
* Added timeout parameter to switch controller
* Changed default behaviour of new switch param
  This way if it not set it will be the same behaviour as previous version
* Abort pending controllers in case of switch error
* Split manageSwitch() into smaller functions
* Added new STOPPED, WAITING and ABORTED states to ControllerBase
* Option to start controllers as soon as their joints are ready after a switch
* Switch is now managed in a separate function
* Using ranged based loops
* Added new switchResult() function to RobotHW interface
  ControllerManager uses this function to wait for the result of the
  doSwitch() before starting the new set of controllers
* Test for multiple updates in a single controller
* All tests using mock class
* Moved mocks to test class
* Controller state initialized in mock
* Divided in tests with and without controllers
* Mocks for controllers and controller loader in update test
* Added tests for ControllerManager update
* fix install destination (`#377 <https://github.com/ros-controls/ros_control/issues/377>`_)
* catch ROSInterruptException
* specify RUNTIME DESTINATION for libraries (`#373 <https://github.com/ros-controls/ros_control/issues/373>`_)
  needed for exporting DLLs on Windows
* use this_thread::sleep_for instead of usleep (`#375 <https://github.com/ros-controls/ros_control/issues/375>`_)
* remove unused pthread.h
* Contributors: Bence Magyar, Gérald Lelong, James Xu, Jordan Palacios, Matt Reynolds, Victor Lopez, jordan-palacios

0.15.1 (2018-09-30)
-------------------
* Updated for compatibility with Python2 or Python3
* Initialize controller_manager node using init_node.
* back to Python3 prints, add '-s to remaining places
* pep8 styling
* added quotes in python code too, also changed python prints to rosconsole
* added quotes for controller name and controller type in warnings and errors
* Contributors: Daniel Ingram, Jasper Güldenstein, Stefan Profanter, Gennaro Raiola, Bence Magyar

0.15.0 (2018-05-28)
-------------------
* boost::shared_ptr -> std::shared_ptr
* Introduce shared_ptr typedefs
* Add controller_group script that allows switching groups easily
* Contributors: Bence Magyar, Enrique Fernández Perdomo, Yong Li

0.14.2 (2018-04-26)
-------------------
* Update maintainers
* Fix catkin_lint errors and warnings
* Remove unused imports, comment and executable flag
* Remove realtime_tools dependency
* Contributors: Bence Magyar

0.14.1 (2018-04-16)
-------------------
* Fix controller_manager_interface and add unit tests.
* Contributors: Yong Li

0.14.0 (2018-03-26)
-------------------
* migrate classloader headers
* refactored controller_manager unspawner
* fix controller_manager list: migrated to new ControllerState with claimed_resources
* remove debug prints from controller_manager script
* Contributors: Mathias Lüdtke

0.13.0 (2017-12-23)
-------------------
* Several spawner-related fixes:
* Remove shutdown_timeout & add deprecation note
* Remove roslib import
* Run wait_for_service on object instead of the hardcoded string version
* Remove wait_for_service and rephrase warning after exception
* Remove sleep(1) as it causes more problems than what it solves
* Contributors: Bence Magyar

0.12.0 (2017-08-05)
-------------------

0.11.5 (2017-06-28)
-------------------
* Fix misspelling revise message
* Contributors: Dave Coleman

0.11.4 (2017-02-14)
-------------------
* controller_manager: drop unused inclusion of tinyxml.h
* Contributors: Dmitry Rozhkov

0.11.3 (2016-12-07)
-------------------

0.11.2 (2016-11-28)
-------------------
* to[to.size-1] to to.back()
* Remove boost from depends declaration to fix cmake warning
* Add Enrique and Bence to maintainer list
* Clean up export leftovers from rosbuild
* Convert to format2, fix dependency in cmake
* Contributors: Bence Magyar

0.11.1 (2016-08-18)
-------------------

0.11.0 (2016-05-23)
-------------------

0.10.1 (2016-04-23)
-------------------

0.10.0 (2015-11-20)
-------------------
* Fix doSwitch execution point
  The doSwitch method needs to be executed in the update() method,  that is, in
  the real-time path, which is where controller switching actually takes place.
* Introduce prepareSwitch, replacement of canSwitch
* Deprecate RobotHW::canSwitch
* Multi-interface controllers
  - C++ API break.
  - Make controller_manager aware of controllers that claim resources from more
  than one hardware interface.
  - Update and extend the corresponding test suite.
* Address -Wunused-parameter warnings
* Contributors: Adolfo Rodriguez Tsouroukdissian, Mathias Lüdtke

0.9.3 (2015-05-05)
------------------
* controller_manager: Add missing rostest dep
* Contributors: Adolfo Rodriguez Tsouroukdissian

0.9.2 (2015-05-04)
------------------
* Add HW interface switch feature
* Contributors: Mathias Lüdtke

0.9.1 (2014-11-03)
------------------
* Update package maintainers
* Contributors: Adolfo Rodriguez Tsouroukdissian

0.9.0 (2014-10-31)
------------------
* Spawner script: adding shutdown timeout to prevent deadlocks
* Documentation fixes
* Contributors: Jonathan Bohren, shadowmanos

0.8.2 (2014-06-25)
------------------

0.8.1 (2014-06-24)
------------------

0.8.0 (2014-05-12)
------------------
* Remove rosbuild artifacts. Fix `#154 <https://github.com/ros-controls/ros_control/issues/154>`_.
* Create README.md
* Contributors: Adolfo Rodriguez Tsouroukdissian

0.7.2 (2014-04-01)
------------------

0.7.1 (2014-03-31)
------------------

0.7.0 (2014-03-28)
------------------
* Add --timeout option to controller spawner
* Use argparse instead of getopt
  It is a much nicer interface
* Contributors: Paul Mathieu

0.6.0 (2014-02-05)
------------------
* Update controller_manager.cpp
  Postfix to prefix increment operator.
* Contributors: Adolfo Rodriguez Tsouroukdissian

0.5.8 (2013-10-11)
------------------
* Fixed additional timeout that was just added
* Merge branch 'hydro-devel' into extended_wait_time
* Extended wait time to 30 seconds for slower computers
* Renamed manifest.xml to prevent conflicts with rosdep
* Fix broken unspawner script.
* Check controller_manager API early. Fast shutdown.
  - Check for all services required by spawner at the beginning, so it can know
  early on that it has all its requisites.
  - Remove service waiting from shutdown to ensure a fast teardown.
  Usecase: A spawner that dies after the controller manager should not wait
  for services to appear as they will never appear, the controllers are already
  stopped. This happens for example when killing a Gazebo session.
* Restore controller stop+unload on node kill.
  - Fixes `#111 <https://github.com/ros-controls/ros_control/issues/111>`_.

0.5.7 (2013-07-30)
------------------
* Update controller_manager.cpp
  getControllerNames now clears names before adding current names.  This fixes a bug in reloadControllerLibrariesSrv where the method is called twice in a row without first clearing the list.
  Steps to reproduce:
  - Spawn controller
  - Stop controller
  - reload-libraries
  controller_manager.cpp:501: bool controller_manager::ControllerManager::reloadControllerLibrariesSrv(controller_manager_msgs::ReloadControllerLibraries::Request&, controller_manager_msgs::ReloadControllerLibraries::Response&): Assertion `controllers.empty()' failed.

* Updated changelogs

0.5.6 (2013-07-29)
------------------

0.5.5 (2013-07-23)
------------------
* Tweaked Changelog

0.5.4 (2013-07-23)
------------------

0.5.3 (2013-07-22)
------------------

0.5.2 (2013-07-22)
------------------

0.5.1 (2013-07-19)
------------------

0.5.0 (2013-07-16)
------------------
* Removed urdf_interface dependencies
* Fix spawner choke when namespace is unspecified.
  Add missing check in conditional.
* Add meta tags to packages not specifying them.
  - Website, bugtracker, repository.
* Making script install target install scripts so that they are executable
* Fix build order.
* Combined exceptions per jbohren
* Reneamed Github repo in documentation to ros-controls
* Better timeout error checking, necessary for Gazebo
* User error checking

0.4.0 (2013-06-25)
------------------
* Version 0.4.0
* 1.0.1
* Fixing failure mode in new catkin cmakelists
* Added namespace argument to spawner script
* Fix package URL in package.xml
* Python install for controller_manager.
* Fix build order dependency.
* adding install targets
* merging CMakeLists.txt files from rosbuild and catkin
* adding hybrid-buildsystem makefiles
* Fix package URLs.
* catkinizing, could still be cleaned up
* Additional log feedback when load_controller fails
  When loading a controller fails bacause its configuration was not found on the
  parameter server, show the namespace where the parameters are expected to help
  debugging.
* Remove unused method. Fixes `#33 <https://github.com/davetcoleman/ros_control/issues/33>`_.
* add option to pass in two nodehandles to a controller: one in the root of the controller manager namespace, and one in the namespace of the controller itself. This copies the behavior used by nodelets and nodes
* Fix typo in rosdoc config files.
* Adding explicit header for recursive mutex
* Removing getControllerByNameImpl
* Switching controller_manager ``controllers_lock_`` to be a recursive lock
* Fixing comment indent
* Adding template parameter doc
* Changing @ commands to \ commands
* More doc in controller manager
* Adding clearer ros warning in controller switching
* Adding lots of inline documentation, rosdoc files
  adding inline doc to robot_hw
  adding inline doc to robot_hw
  adding inline doc to robot_hw
  more doc
  more documentation
  more doc
  more doc
  more doc
  more doc
  formatting
  adding more doc groups in controller manager
  adding more doc groups in controller manager
  Adding doc for controllerspec
  adding hardware interface docs
  adding doc to joint interfaces
  adding rosdoc for controller_interface
  Adding / reformatting doc for controller interface
* don't clear vectors in realtime
* Make public getControllerByName method thread-safe.
  Existing virtual non-threadsafe method has been suffixed with -Impl and pushed
  to protected class scope. In-class uses call getControllerByNameImpl, as the
  lock has already been acquired.
* new interface with time and duration
* add missing include
* remove .svn folder
* Doing resource conflict check on switchControllers call
* Adding in resource/claim infrastructure
* fix command line interface
* clean up publishing controller state
* Controller spec now also copies over type
* Switching to owned interfaces, instead of multiple virtual inheritance
* add scripts for controller manager
* get rid of pr2 stuff
* Controller manager can now register ControllerLoaders
* Controller manager now runs with new ControllerLoader mechanism
* Creating new plugin_loader interface
* Adding debugging printouts
* Namespacing controller_spec
* Fixing copyright header text
* Spawning dummy controller works
* Tweaking inheritance to be virtual so it compiles. dummy app with controller manager compiles
* all pkgs now ported to fuerte
* add missing file
* running controller with casting. Pluginlib still messed up
* add macro
* running version, with latest pluginlib
* compiling version
* compiling version
* first catkin stuff
