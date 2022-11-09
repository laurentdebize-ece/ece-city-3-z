cmake_minimum_required(VERSION 3.20)
project(ece_city_3_z C)

set(CMAKE_C_STANDARD 99)

add_executable(ece_city_3_z main.c bibliotheque.c bibliotheque.h graphe.c graphe.h construction.c construction.h banque.c banque.h)

IF(WIN32)
    target_link_libraries(ece_city_3_z  -lmingw32 -lallegro-5.2.8-monolith-md-debug)
ELSE()
    INCLUDE_DIRECTORIES(/usr/local/Cellar/allegro/5.2.8.0_2/include)
    LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.8.0_2/lib)
    file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.8.0_2/lib/*.dylib")
    message("LIBRARIES = ${LIBRARIES}")
    TARGET_LINK_LIBRARIES(ece_city_3_z  ${LIBRARIES})
ENDIF(WIN32)

