# Creates a Magboltz executable directly from the fortran sources to manually calculate
# a set of gas properties
set( exename "MagboltzRun")
set( fullver ${PROJECT_VERSION})
add_executable( ${exename} src/magboltz.f)
set_target_properties( ${exename} PROPERTIES LINKER_LANGUAGE Fortran)
install( TARGETS ${exename} EXPORT "${PROJECT_NAME}Targets"
         RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# Creates a library with the magboltz fortran sources and additional c++ functions
# The library has C headers and linkage to provide bindings for other languages and tools

set( libname "magboltz")
set( lib_fullver ${PROJECT_VERSION})
set( lib_apiver 1 )
add_library(${libname} SHARED "" )
target_sources( ${libname} PRIVATE
                src/magboltz.f)

# Sets the API version of the library
set_property( TARGET ${libname} PROPERTY SOVERSION ${lib_apiver} )
#Install the header files
install( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} ) 
#Install the library
install( TARGETS ${libname} EXPORT "${PROJECT_NAME}Targets"
         LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
         ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
         RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
         )
#Install the header files
install( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} )         
target_include_directories(${libname} PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>	
   $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
         
if(BUILD_TESTING)
    add_subdirectory(test)
endif()