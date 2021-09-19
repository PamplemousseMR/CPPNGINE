set(cppngine_src main.cpp)
set(cppngine_header
    firstChild.hpp
    root.hpp
    secondChild.hpp
    virtualInheritance.hpp)

add_sample(SOURCES ${cppngine_src} HEADERS ${cppngine_header})
