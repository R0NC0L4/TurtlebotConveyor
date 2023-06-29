#ifndef CONVEYOR_DESCRIPTION_PKG__VISIBILITY_CONTROL_H_
#define CONVEYOR_DESCRIPTION_PKG__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CONVEYOR_DESCRIPTION_PKG_EXPORT __attribute__ ((dllexport))
    #define CONVEYOR_DESCRIPTION_PKG_IMPORT __attribute__ ((dllimport))
  #else
    #define CONVEYOR_DESCRIPTION_PKG_EXPORT __declspec(dllexport)
    #define CONVEYOR_DESCRIPTION_PKG_IMPORT __declspec(dllimport)
  #endif
  #ifdef CONVEYOR_DESCRIPTION_PKG_BUILDING_LIBRARY
    #define CONVEYOR_DESCRIPTION_PKG_PUBLIC CONVEYOR_DESCRIPTION_PKG_EXPORT
  #else
    #define CONVEYOR_DESCRIPTION_PKG_PUBLIC CONVEYOR_DESCRIPTION_PKG_IMPORT
  #endif
  #define CONVEYOR_DESCRIPTION_PKG_PUBLIC_TYPE CONVEYOR_DESCRIPTION_PKG_PUBLIC
  #define CONVEYOR_DESCRIPTION_PKG_LOCAL
#else
  #define CONVEYOR_DESCRIPTION_PKG_EXPORT __attribute__ ((visibility("default")))
  #define CONVEYOR_DESCRIPTION_PKG_IMPORT
  #if __GNUC__ >= 4
    #define CONVEYOR_DESCRIPTION_PKG_PUBLIC __attribute__ ((visibility("default")))
    #define CONVEYOR_DESCRIPTION_PKG_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CONVEYOR_DESCRIPTION_PKG_PUBLIC
    #define CONVEYOR_DESCRIPTION_PKG_LOCAL
  #endif
  #define CONVEYOR_DESCRIPTION_PKG_PUBLIC_TYPE
#endif
#endif  // CONVEYOR_DESCRIPTION_PKG__VISIBILITY_CONTROL_H_
// Generated 29-Jun-2023 12:03:46
// Copyright 2019-2020 The MathWorks, Inc.
