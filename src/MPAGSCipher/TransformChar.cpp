
// Include to handle strings
#include <string>
// For std::isalpha and std::isupper
#include <cctype>
// 
#include "transformChar.hpp"

/*
A function mapping an input charater to exclusively upper case alphabetic strings
Non-alphanumeric chars return the empty string

INPUTS:
char in_char: the character to be mapped

OUTPUTS:
string : the mapped equivalent of the inout or an empty string
*/
std::string transformChar( const char in_char ) 
{
  // Uppercase alphabetic characters
  if (std::isalpha(in_char)) {
    std::string in_char_as_string(1, std::toupper(in_char));
    return in_char_as_string;
  }

  // Transliterate digits to English words
  switch (in_char) 
  {
    case '0':
	    return "ZERO";
    case '1':
	    return "ONE";
    case '2':
	    return "TWO";
    case '3':
	    return "THREE";
    case '4':
	    return "FOUR";
    case '5':
	    return "FIVE";
    case '6':
	    return "SIX";
    case '7':
	    return "SEVEN";
    case '8':
	    return "EIGHT";
    case '9':
	    return"NINE";
  }

  // Handles all other cases, all needing removal
  return "";
}