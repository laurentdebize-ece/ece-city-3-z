cmake_minimum_required(VERSION 3.20)
project(ece_city_3_z C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(raylib)

add_executable(ece_city_3_z main.c bibliotheque.c bibliotheque.h graphe.c graphe.h construction.c construction.h banque.c banque.h affichage.c affichage.h isoConfig.c isoConfig.h menu.h)

target_link_libraries(ece_city_3_z raylib)


