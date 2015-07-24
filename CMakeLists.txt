project(fdp)

set(CMAKE_CXX_FLAGS "-std=c++0x")

# function_tester.cc main.cc
add_executable(fdp PolyTester.cc fdgrid.cc utilities.cc cons_law.cc PolySet.cc )

install(TARGETS fdp RUNTIME DESTINATION bin)
