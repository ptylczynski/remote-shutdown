cmake_minimum_required(VERSION 3.17)
project(project_rewrite C)

set(CMAKE_C_STANDARD 11)

add_executable(project_rewrite main.c server.h utils/simple-message.h utils/stringops.h)

SET(CMAKE_CXX_FLAGS -pthread)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)