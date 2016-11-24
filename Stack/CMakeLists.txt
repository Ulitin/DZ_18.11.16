file(GLOB CPPS "*.cpp")
file(GLOB HPPS "*.h")

include_directories(../include)

add_executable(stack ${CPPS} ${HPPS})
target_link_libraries(stack code)