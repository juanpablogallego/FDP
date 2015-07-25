project(fdp)

set(CMAKE_CXX_FLAGS "-std=c++0x")

#  main.cc PolyTester.cc
add_executable(fdp function_tester.cc fdgrid.cc utilities.cc cons_law.cc PolySet.cc )

install(TARGETS fdp RUNTIME DESTINATION bin)
