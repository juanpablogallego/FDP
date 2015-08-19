project(fdp)

set(CMAKE_CXX_FLAGS "-std=c++0x")

# function_tester.cc PolyTester.cc try_burgers.cc output_fns.cc function_tester.cc 
add_executable(fdp main.cc fdgrid.cc utilities.cc cons_law.cc PolySet.cc Quadratures.cc fegrid.cc initial_condition.cc)

install(TARGETS fdp RUNTIME DESTINATION bin)
