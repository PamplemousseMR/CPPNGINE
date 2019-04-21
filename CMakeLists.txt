#========================================
#	project
#========================================
CMAKE_MINIMUM_REQUIRED(VERSION 3.7)
PROJECT("CPPNGINE" CXX)

#================================================================================
#		init
#================================================================================

#========================================
#	variables
#========================================
SET(cppngine_src_dir "src")
SET(cppngine_header_dir "include")

#========================================
#	compiler specifications
#========================================
SET(CMAKE_CXX_STANDARD 14)
IF (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    IF((CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "3.8.0") AND (CMAKE_CXX_COMPILER_VERSION VERSION_LESS_EQUAL "3.9.1"))
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    ENDIF()
ENDIF()

#================================================================================
#		create
#================================================================================

#========================================
#	create one project by name
#========================================
FUNCTION(cppngineTest)
    SET(cppngine_oneValueArgs NAME)
    CMAKE_PARSE_ARGUMENTS(VAR "" ${cppngine_oneValueArgs} "" ${ARGN})

    #====================
    #	find files
    #====================
    FILE(GLOB_RECURSE cppngine_src_files ${cppngine_src_dir}/*)
    FILE(GLOB_RECURSE cppngine_header_files ${cppngine_header_dir}/*)

    #====================
    #	create project
    #====================
    GET_FILENAME_COMPONENT(cppngine_current_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    SET(cppngine_current_name ${cppngine_current_name} PARENT_SCOPE)
    SET(${VAR_NAME} ${cppngine_current_name} PARENT_SCOPE)

    ADD_EXECUTABLE(${cppngine_current_name} ${cppngine_src_files} ${cppngine_header_files})
    TARGET_INCLUDE_DIRECTORIES(${cppngine_current_name} PRIVATE ${cppngine_header_dir})
ENDFUNCTION()

#========================================
#	find subdirectories
#========================================
SET(cppngine_project_dir "")

FILE(GLOB cppngine_glob_dir ./*)
FOREACH(cppngine_dir ${cppngine_glob_dir})
    IF((IS_DIRECTORY ${cppngine_dir}) AND (NOT ${cppngine_dir} MATCHES ".*git")  AND (NOT ${cppngine_dir} MATCHES ".travis.yml") AND (NOT ${cppngine_dir} MATCHES ".vs"))
        LIST(APPEND cppngine_project_dir ${cppngine_dir})
    ENDIF()
ENDFOREACH()

#========================================
#	create projects
#========================================
FOREACH(cppngine_dir ${cppngine_project_dir})
    MESSAGE(INFO " generate project : " ${cppngine_dir})
    ADD_SUBDIRECTORY(${cppngine_dir})
ENDFOREACH()
