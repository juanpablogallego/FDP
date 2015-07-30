project(fdp)

set(CMAKE_CXX_FLAGS "-std=c++0x")

#  main.cc function_tester.cc 
add_executable(fdp PolyTester.cc fdgrid.cc utilities.cc cons_law.cc PolySet.cc Quadratures.cc)

install(TARGETS fdp RUNTIME DESTINATION bin)
