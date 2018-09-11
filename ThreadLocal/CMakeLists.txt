IF((NOT APPLE) OR (APPLE AND (XCODE_VERSION VERSION_GREATER 7.3.0)) )

    cppngineTest(NAME cppngine_project_name)

    FIND_PACKAGE("Threads" QUIET)

    TARGET_LINK_LIBRARIES(${cppngine_project_name} ${CMAKE_THREAD_LIBS_INIT})

ENDIF()
