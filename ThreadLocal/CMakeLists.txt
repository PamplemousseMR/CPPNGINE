cppngineTest()

FIND_PACKAGE("Threads")

GET_FILENAME_COMPONENT(cppngine_current_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)

TARGET_LINK_LIBRARIES(${cppngine_current_name} ${CMAKE_THREAD_LIBS_INIT})
