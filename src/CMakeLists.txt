cmake_minimum_required(VERSION 2.6)
project(gb_emu)

Find_Package(SDL REQUIRED)

ADD_DEFINITIONS ( -Wall -std=c++11 -g )


include_directories(${SDL_INCLUDE_DIR})
set(LIBS ${LIBS} ${SDL_LIBRARY})
link_libraries(${LIBS})

add_executable(gbemu.out main.cpp cpu.cpp mmu.cpp gpu.cpp render.cpp opcodes.cpp debug.cpp loader.cpp)

