
#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <vector>

#include "types.h"

std::string readRomName();
std::vector<BYTE> readRom(std::string rom_name);


#endif