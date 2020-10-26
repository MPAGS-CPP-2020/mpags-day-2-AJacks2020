// Required Includes
#include <iostream>
#include <string>
#include <vector>


/*
A function handling the command line arguements

INPUTS:
vector<string> (const ref) args             : The provided command line arguements
bool           (ref)       helpRequested    : A variable signifying if help is requested
bool           (ref)       versionRequested : A variable signifying if the version is requested
string         (ref)       inputFileName    : A string to store the input file location
string         (ref)       outputFileName   : A string to store the output file location

OUTPUTS:
bool           (local)     UNNAMED          : A bool dictating whether the program needs to continue
*/
bool processCommandLine(const std::vector<std::string>& args,
bool& helpRequested,
bool& versionRequested,
std::string& inputFileName,
std::string& outputFileName,
int& EncryptionKey,
bool& encrypting)
{

  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nArgs {args.size()};
  
  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  for (size_type i {1}; i < nArgs; ++i) {
    if (args[i] == "-h" || args[i] == "--help") {
      helpRequested = true;
    }
    else if (args[i] == "--version") {
      versionRequested = true;
    }
    else if (args[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nArgs-1) {
	      std::cerr << "[error] -i requires a filename argument" << std::endl;
	      // exit main with non-zero return to indicate failure
	      return false;
      }
      else {
	      // Got filename, so assign value and advance past it
	      inputFileName = args[i+1];
	      ++i;
      }
    }
    else if (args[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nArgs-1) {
	      std::cerr << "[error] -o requires a filename argument" << std::endl;
	      // exit main with non-zero return to indicate failure
	      return false;
      }
      else {
	      // Got filename, so assign value and advance past it
	      outputFileName = args[i+1];
	      ++i;
      }
    }
    // NEW COMMAND LINE STUFF GOES HERE                                     HERE HERE HERE
    else if(args[i] == "-key") {
      if (i == nArgs-1) {
	      std::cerr << "[error] -key requires a key to be specified" << std::endl;
	      return false;
      }
      else {
	      // Converts the encryption key to an int
	      EncryptionKey = std::stoi( args[i+1] );
	      ++i;
      }
    }
    else if(args[i] == "-encrypt") {
      if (i == nArgs-1) {
	      std::cerr << "[error] Encryption or decryption must be specified" << std::endl;
	      return false;
      }
      else {
        if(args[i+1] == "true" || args[i+1] == "True" || args[i+1] == "1") {
          encrypting = true;
        }
	      else if(args[i+1] == "false" || args[i+1] == "False" || args[i+1] == "0") {
          encrypting = false;
        }
        else {
          std::cerr << "[error] Encryption must be indicated to be true of false" << std::endl;
	      return false;
        }
	      ++i;
      }
    }
    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      return false;
    }
  }

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return false;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return false;
  }
  // Have successfully reached the end with no problems, return true (continue the program)
  return true;
}