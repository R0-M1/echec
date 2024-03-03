cmake_minimum_required(VERSION 3.10) 

project(Echec)

file(GLOB SOURCE_FILES ./src/*.cpp)
file(GLOB HEADER_FILES ./src/*.h)

add_executable(MyExecutable ${SOURCE_FILES} ${HEADER_FILES})


# La bibliotheque SFML sera Statique c'est a dire qu'elle est incluse dans les fichiers du projet.
# C'est pour éviter d'installer SFML sur chaque ordinateur.
# Le code ci dessous indique a cmake comment trouver la bibliotheque.
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES TRUE)
#target_include_directories(MyExecutable PRIVATE ${CMAKE_SOURCE_DIR}/SFML/include)
#include_directories(${SFML_INCLUDE_DIR})

find_package(SFML COMPONENTS audio graphics window system network REQUIRED)
target_link_libraries(MyExecutable sfml-network sfml-audio sfml-graphics sfml-window sfml-system)