cmake_minimum_required (VERSION 2.8)
project (vstats)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")

#Bring the headers
include_directories(include)

#Set Sources
file(GLOB SOURCES "src/*.c")

add_executable(vstats ${SOURCES})

target_link_libraries(vstats -lcurl -lpcap)
