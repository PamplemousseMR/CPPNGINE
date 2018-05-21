CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#------------ project ------------
PROJECT("CPPNGINE")

#------------ variables ------------
SET(cppngine_src_dir "src")
SET(cppngine_header_dir "include")

FUNCTION(cppngineTest)
    #------ find files ------
    FILE(GLOB_RECURSE cppngine_src_files ${cppngine_src_dir}/*)
    FILE(GLOB_RECURSE cppngine_header_files ${cppngine_header_dir}/*)

    #------ create project ------
    GET_FILENAME_COMPONENT(cppngine_current_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)

    INCLUDE_DIRECTORIES(${cppngine_header_dir})
    ADD_EXECUTABLE(${cppngine_current_name} ${cppngine_src_files} ${cppngine_header_files})
ENDFUNCTION()

#------------ cmake variables ------------
IF(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    SET(CMAKE_CXX_FLAGS "-std=c++11 ")
ENDIF()

#------------ create project ------------

#------ find sub directories ------
SET(cppngine_project_dir "")

FILE(GLOB cppngine_glob_dir ./*)
FOREACH(dir ${cppngine_glob_dir})
    IF((IS_DIRECTORY ${dir}) AND (NOT ${dir} MATCHES ".*git"))
        LIST(APPEND cppngine_project_dir ${dir})
    ENDIF()
ENDFOREACH()

#------ generate project for each sub directories ------
FOREACH(dir ${cppngine_project_dir})
    MESSAGE(INFO " generate project : " ${dir})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()
