#ifndef MPAGSCIPHER_COMMANDLINE_HPP
#define MPAGSCIPHER_COMMANDLINE_HPP

#include <string>
#include <vector>

// Declares the command line arguement handling function
bool processCommandLine(const std::vector<std::string>& args,
bool& helpRequested,
bool& versionRequested,
std::string& inputFileName,
std::string& outputFileName,
int& EncryptionKey,
bool& encrypting);

#endif