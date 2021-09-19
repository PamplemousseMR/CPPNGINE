#=======================================
#                PROJECT
#=======================================

cmake_minimum_required(VERSION 3.0)
project("CPPNGINE")

#=======================================
#               LIBRARIES
#=======================================

find_package("Threads" QUIET)

#=======================================
#                SAMPLES
#=======================================

function(add_sample)
    set(options "")
    set(singleValues "")
    set(multipleValues SOURCES HEADERS LINKS)

    cmake_parse_arguments(SAMPLE "${options}" "${singleValues}" "${multipleValues}" ${ARGN})

    get_filename_component(cppngine_current_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)

    add_executable(${cppngine_current_name} ${SAMPLE_SOURCES} ${SAMPLE_HEADERS})
    set_target_properties(${cppngine_current_name} PROPERTIES CXX_STANDARD 14)
    target_link_libraries(${cppngine_current_name} PRIVATE ${SAMPLE_LINKS})
endfunction()

add_subdirectory("Alignas")
add_subdirectory("CastOperator")
add_subdirectory("Decltype")
add_subdirectory("Explicit")
add_subdirectory("Generic")
add_subdirectory("Inline")
add_subdirectory("MoveSemantics")
add_subdirectory("Mutable")
add_subdirectory("Sfinae")
add_subdirectory("STDFunction")
add_subdirectory("STDInitializationLists")
add_subdirectory("STDTuple")
add_subdirectory("Template")
add_subdirectory("ThreadLocal")
add_subdirectory("VirtualInheritance")
