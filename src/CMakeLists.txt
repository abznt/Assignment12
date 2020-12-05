set(targetName Main)
project(${targetName})

add_subdirectory(poker)

add_executable(${targetName} main.cpp)
target_link_libraries(${targetName} poker)

unset(targetName)