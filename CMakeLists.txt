cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# Setting a default build type
set(default_build_type "RelWithDebInfo" )
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  	set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      	STRING "Choose the type of build.")
  	# Set the possible values of build type for cmake-gui
  	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
		"Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

project( MagboltzBind LANGUAGES Fortran VERSION 8.9.5)

include(GNUInstallDirs)

add_subdirectory(libMagboltz)

add_subdirectory(cmake)