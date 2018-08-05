# Install script for directory: /home/remus/Scrivania/teb-planner_ws/src/teb_planner

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/remus/Scrivania/teb-planner_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/remus/Scrivania/teb-planner_ws/build/teb_planner/catkin_generated/installspace/teb_planner.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/teb_planner/cmake" TYPE FILE FILES
    "/home/remus/Scrivania/teb-planner_ws/build/teb_planner/catkin_generated/installspace/teb_plannerConfig.cmake"
    "/home/remus/Scrivania/teb-planner_ws/build/teb_planner/catkin_generated/installspace/teb_plannerConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/teb_planner" TYPE FILE FILES "/home/remus/Scrivania/teb-planner_ws/src/teb_planner/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/teb_planner" TYPE DIRECTORY FILES
    "/home/remus/Scrivania/teb-planner_ws/src/teb_planner/launch"
    "/home/remus/Scrivania/teb-planner_ws/src/teb_planner/cfg"
    "/home/remus/Scrivania/teb-planner_ws/src/teb_planner/maps"
    "/home/remus/Scrivania/teb-planner_ws/src/teb_planner/stage"
    "/home/remus/Scrivania/teb-planner_ws/src/teb_planner/scripts"
    REGEX "/\\.svn$" EXCLUDE)
endif()

