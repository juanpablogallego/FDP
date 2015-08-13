project(fdp)

set(CMAKE_CXX_FLAGS "-std=c++0x")

# function_tester.cc PolyTester.cc try_burgers.cc output_fns.cc main.cc Quadratures.cc
add_executable(fdp function_tester.cc fdgrid.cc utilities.cc cons_law.cc PolySet.cc )

install(TARGETS fdp RUNTIME DESTINATION bin)
