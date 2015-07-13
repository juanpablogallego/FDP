project(fdp)

add_executable(fdp main.cc fdgrid.cc utilities.cc cons_law.cc)

install(TARGETS fdp RUNTIME DESTINATION bin)
