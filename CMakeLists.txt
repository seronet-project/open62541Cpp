cmake_minimum_required (VERSION 3.5)
project(Open62541Cpp)

set (CMAKE_CXX_STANDARD 17)


#option(CMAKE_POSITION_INDEPENDENT_CODE "Compile with position independent code" ON )

find_package(open62541 REQUIRED)

set(PRJ_DIR ${PROJECT_SOURCE_DIR}/Open62541Cpp)

set(SRC_FILES
		${PRJ_DIR}/UA_ArrayOfVariant.cpp
		${PRJ_DIR}/UA_NodeId.cpp
		${PRJ_DIR}/UA_ObjectType.cpp
		${PRJ_DIR}/UA_Variable.cpp
		${PRJ_DIR}/UA_Method.cpp
		${PRJ_DIR}/UA_Object.cpp
		${PRJ_DIR}/UA_String.cpp
		${PRJ_DIR}/UA_Variant.cpp
		${PRJ_DIR}/UA_DataValue.cpp
		${PRJ_DIR}/UA_Argument.cpp
		${PRJ_DIR}/UA_ArrayOfArgument.cpp
		${PRJ_DIR}/UA_BrowsePath.cpp
		${PRJ_DIR}/UA_RelativPathBase.cpp
		${PRJ_DIR}/UA_RelativPathElement.cpp
		${PRJ_DIR}/UA_QualifiedName.cpp
		Open62541Cpp/Exceptions/OpcUaErrorException.cpp
		)


add_library(Open62541Cpp ${SRC_FILES})
set_target_properties(Open62541Cpp PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(Open62541Cpp PROPERTIES DEBUG_POSTFIX "d")
target_link_libraries(Open62541Cpp PUBLIC open62541::open62541)

target_include_directories(Open62541Cpp INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		$<INSTALL_INTERFACE:include> )


add_subdirectory(tests)
include(CTest)

include(GenerateExportHeader)
set(OPEN62541_CPP_VERSION 0.1.0)

set_property(TARGET Open62541Cpp PROPERTY VERSION ${OPEN62541_CPP_VERSION})
set_property(TARGET Open62541Cpp PROPERTY SOVERSION 3)


# export library (either static or shared depending on BUILD_SHARED_LIBS)
install(TARGETS Open62541Cpp
	EXPORT Open62541CppTargets
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
	)

install(DIRECTORY Open62541Cpp/ DESTINATION include/Open62541Cpp/
	FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h")


set(cmake_configfile_install lib/cmake/Open62541Cpp)
set(target_install_dest_name "${cmake_configfile_install}/Open62541CppTargets.cmake")

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/Open62541CppConfigVersion.cmake"
  VERSION ${OPEN62541_CPP_VERSION}
  COMPATIBILITY AnyNewerVersion
)

configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/Open62541CppConfig.cmake.in"
							  "${CMAKE_CURRENT_BINARY_DIR}/cmake/Open62541CppConfig.cmake"
							  INSTALL_DESTINATION "${cmake_configfile_install}"
							  PATH_VARS target_install_dest_name)

install(EXPORT Open62541CppTargets
		FILE Open62541CppTargets.cmake
		NAMESPACE Open62541Cpp::
		DESTINATION "${cmake_configfile_install}"
		EXPORT_LINK_INTERFACE_LIBRARIES)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cmake/Open62541CppConfig.cmake"
			"${CMAKE_CURRENT_BINARY_DIR}/Open62541CppConfigVersion.cmake"
		DESTINATION "${cmake_configfile_install}")


