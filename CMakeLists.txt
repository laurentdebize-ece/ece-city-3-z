cmake_minimum_required(VERSION 3.20)
project(ece_city_3_z C)

set(CMAKE_C_STANDARD 99)

add_executable(ece_city_3_z main.c bibliotheque.c bibliotheque.h)

target_link_libraries(ece_city_3_z -lmingw32 -lallegro-5.0.10-monolith-md-debug)