set( exename "MagboltzRun")
set( fullver ${PROJECT_VERSION})
add_executable( ${exename} src/magboltz.f)
set_target_properties( ${exename} PROPERTIES LINKER_LANGUAGE Fortran)
install( TARGETS ${exename} EXPORT "${PROJECT_NAME}Targets"
         RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})