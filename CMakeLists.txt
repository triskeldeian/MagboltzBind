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

project( MagboltzBind LANGUAGES CXX Fortran VERSION 11.3)

include(GNUInstallDirs)
include(CTest)

#Requiring c++17
set( CMAKE_CXX_STANDARD 17)    
set( CMAKE_CXX_STANDARD_REQUIRED ON)

#Switch off the compiler extensions so that we reduce the possibility of cross-platform errors
set( CMAKE_CXX_EXTENSIONS OFF )

#Removing the symbols related to inline functions from the DSO. Rely on headers (they are inline)
# set( CMAKE_VISIBILITY_INLINES_HIDDEN TRUE )
# set( CMAKE_CXX_VISIBILITY_PRESET hidden)

add_subdirectory(libMagboltz)

add_subdirectory(cmake)