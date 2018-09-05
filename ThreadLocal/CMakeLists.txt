cppngineTest(NAME cppngine_project_name)

FIND_PACKAGE("Threads" QUIET)

TARGET_LINK_LIBRARIES(${cppngine_project_name} ${CMAKE_THREAD_LIBS_INIT})