project(leetcode)
cmake_minimum_required( VERSION 3.5 )
set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_CXX_FLAGS "-fsanitize=undefined,address,leak -fno-omit-frame-pointer"leetcode_solutions)
#set(CMAKE_C_FLAGS "-fsanitize=undefined,address,leak -fno-omit-frame-pointer")
#set(CMAKE_Ｌ_FLAGS "-fsanitize=undefined,address,leak -fno-omit-frame-pointer")

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC)

include(FetchContent)
FetchContent_Declare(
        doctest
        GIT_REPOSITORY https://github.com/doctest/doctest.git
        GIT_TAG v2.4.9
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(doctest)
#
#include(FetchContent)
#FetchContent_Declare(
#        backward
#        GIT_REPOSITORY https://github.com/bombela/backward-cpp
#        GIT_TAG v1.6
#        GIT_SHALLOW TRUE
#)
#FetchContent_MakeAvailable(backward)


add_executable(leetcode main.cpp ${SRC})
target_link_libraries(leetcode doctest_with_main )

#target_link_libraries(sort PRIVATE ${OpenCV_LIBS} ${EXTRA_LIBS} ${BACKWARD_ENABLE})


