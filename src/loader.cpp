
#include "loader.h"

#include <iostream>
#include <cstdio>


std::string readRomName() {

	std::FILE* fp = std::fopen("../config/load_rom.txt", "r");

	char buffer[256];
	char file_buf[256];

	fgets(buffer, sizeof(buffer), fp);

	int i;
	int j = 0;
	for (i = 9; i < 256; ++i) {
		if (buffer[i] == '.' && buffer[i + 1] == 'g' && buffer[i + 2] == 'b')
			break;

		file_buf[j++] = buffer[i];
	}

	file_buf[j++] = '.';
	file_buf[j++] = 'g';
	file_buf[j++] = 'b';
	file_buf[j++] = '\0';

	puts(file_buf);

	return std::string(file_buf);
}


std::vector<BYTE> readRom(std::string rom_name) {
	std::string path = "../roms/" + rom_name;
	std::cout << "Opening path: " << path << std::endl;
    FILE* p = fopen(path.c_str(), "rb");
    
    fseek(p, 0, SEEK_END);
    long size = ftell(p);
    fseek(p, 0, SEEK_SET);

    std::vector<BYTE> buff;    
    buff.resize(size);

    fread(&buff[0], 1, size, p);
    fclose(p);

    return buff;
}