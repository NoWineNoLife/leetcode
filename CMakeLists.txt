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


find_package(GTest)
include_directories(${Test_INCLUDE_DIRS})

add_executable(leetcode main.cpp ${SRC})
target_link_libraries(leetcode PRIVATE ${EXTRA_LIBS} GTest::GTest)

#target_link_libraries(sort PRIVATE ${OpenCV_LIBS} ${EXTRA_LIBS})


