// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// For std::isalpha and std::isupper
#include <cctype>

// Includes functions located elsewhere
#include "processCommandLine.hpp"
#include "transformChar.hpp"
#include "runCaesarCipher.hpp"

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{

                                  /* COMMAND LINE ARGS SECTION */

  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};
  int key;
  bool encrypting;

  // Handles the command line arguements and decides wether to continue
  bool continueProgram {processCommandLine(cmdLineArgs, helpRequested, versionRequested, 
                                            inputFile, outputFile, key, encrypting)};
  // Ends the program if there is a problem with inputs or help (or version) requested
  if (!continueProgram)
  {
    // From a customer service perspective, this is probably bad wording
    std::cout << "PROGRAM ABANDONED" << std::endl;
    return 1;
  }

                                  /* INPUT AND PROCESS SECTION */

  // Initialise variables for processing input text
    char inputChar {'x'};
    std::string outputText {""};

  // Read in user input from stdin/file
  if (!inputFile.empty()) {
    std::ifstream in_file {inputFile};
    bool ok_to_read = in_file.good();

     // If file opened successfully, reads from it: if not, reports the error
    if(ok_to_read) {
      // Loop over each character from file
      while(in_file >> inputChar) {
        // Transliterates then appends the characters 
        outputText += transformChar( inputChar );
      }
    }
    else {
      std::cerr << "Error reading input file" << std::endl;
      return 1;
    }    
  }
  else {
    // Loop over each character from user input
    // (until Return then CTRL-D (EOF) pressed)
    while(std::cin >> inputChar) {
      // Transliterates then appends the characters 
      outputText += transformChar( inputChar );
    }

  }
                                    /* RUNNING THE CIPHER */
  std::cout << outputText << std::endl;                         
  outputText = runCaesarCipher(outputText, key, encrypting);

                                      /* OUTPUT SECTION */

  // Output the transliterated text
  if (!outputFile.empty()) {
    std::ofstream out_file {outputFile};
    bool ok_to_write = out_file.good();

    // If file opened successfully, writes to it: if not, reports the error
    if(ok_to_write) {
      out_file << outputText;
    }
    else {
      std::cerr << "Error writing to output file" << std::endl;
      return 1;
    }
  }
  else {
    std::cout << outputText << std::endl; //variable needs to become stores the output
  }

  return 0;
}
