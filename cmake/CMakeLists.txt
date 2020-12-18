# This is a valid destination common to both Win and Unix
# where find_package can locate the config files
set(CMAKE_INSTALL_DIR share/${PROJECT_NAME}/cmake)

# Configuring the package for exporting
include(CMakePackageConfigHelpers)
	
# Creating the target export file
install( EXPORT "${PROJECT_NAME}Targets" 
	FILE  "${PROJECT_NAME}Targets.cmake"
	NAMESPACE MagboltzBind::
    DESTINATION "${CMAKE_INSTALL_DIR}")
    
# Creates the versioning file
set( VersionFilePath "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake" )
write_basic_package_version_file(
	${VersionFilePath}
	VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

# Prepares the configuration file
set( ConfigFileName "${PROJECT_NAME}Config.cmake" )  
configure_package_config_file( 
    "${ConfigFileName}.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${ConfigFileName}"
    INSTALL_DESTINATION "${CMAKE_INSTALL_DIR}"
)  

# Installs the configuration file
install( FILES "${CMAKE_CURRENT_BINARY_DIR}/${ConfigFileName}" 
	"${VersionFilePath}"
	DESTINATION "${CMAKE_INSTALL_DIR}")