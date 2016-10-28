cmake_minimum_required (VERSION 3.2.0)

SET(CMAKE_COLOR_MAKEFILE ON)
#SET(CMAKE_VERBOSE_MAKEFILE ON)

project (willin CXX)

# Look for deps
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

add_subdirectory(flat)

include_directories(${PROJECT_BINARY_DIR}/flat/include)

add_executable(willin 
	src/Game.cpp
	src/Box.cpp
	src/BigBox.cpp
	)

target_link_libraries(willin flat -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf)
target_compile_options(willin PRIVATE -std=c++14 -Wall)
