cmake_minimum_required(VERSION 3.10)

project(LabWork7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ADDRESS "Enable AddressSanitizer" OFF)
option(THREAD "Enable ThreadSanitizer" OFF)

if(ADDRESS AND THREAD)
    message(FATAL_ERROR "AddressSanitizer and ThreadSanitizer cannot be used together.")
elseif(ADDRESS)
    message("Address on")
    set(SANITIZER_FLAGS "-fsanitize=address")
elseif(THREAD)
    message("Thread on")
    set(SANITIZER_FLAGS "-fsanitize=thread")
else()
    set(SANITIZER_FLAGS "")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZER_FLAGS}")

set(SRCS
    Main.cpp
)

add_executable(app ${SRCS})
target_link_libraries(app PRIVATE pthread)

