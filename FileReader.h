#ifndef FILE_READER_INTERFACE_H
#define FILE_READER_INTERFACE_H

#include <string>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string getFileContents(const char* filename);

#endif // FILE_READER_INTERFACE_H
