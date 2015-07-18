project(fdp)

set(CMAKE_CXX_FLAGS "-std=c++0x")

add_executable(fdp  fdgrid.cc utilities.cc cons_law.cc PolySet.cc PolyTester.cc)

install(TARGETS fdp RUNTIME DESTINATION bin)
