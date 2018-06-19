cppngineTest()

FIND_PACKAGE("Threads" QUIET)

LINK_LIBRARIES(${cppngine_current_name} PRIVATE ${CMAKE_THREAD_LIBS_INIT})
