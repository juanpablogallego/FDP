project(fdp)

set(CMAKE_CXX_FLAGS "-std=c++0x")

#PolyTester.cc
add_executable(fdp  fdgrid.cc utilities.cc cons_law.cc PolySet.cc main.cc)

install(TARGETS fdp RUNTIME DESTINATION bin)
