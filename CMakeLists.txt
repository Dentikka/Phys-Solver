cmake_minimum_required(VERSION 3.19)
project(final_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(final_project main.cpp Gas.cpp Holder.cpp Cap.cpp
         Holder_with_cap.cpp Holder_with_partition.cpp)

