// Required Includes
#include <iostream>
#include <string>

/* CHANGE THIS
A function implementing the caesar cipher

INPUTS:
string (const ref) plaintext  : The string to be encrypted
int    (const val) key        : The encryption key
bool   (val)       Encrypt    : bool signifying if encrypting or decrypting

OUTPUTS:
string             ciphertext : The encrypted text
*/
std::string runCaesarCipher(const std::string& plaintext, const int key, const bool Encrypt) {

    // Handles decryption as the inverse of the encryption
    if(!Encrypt) {
        return runCaesarCipher(plaintext, (-1)*key, true);
    }

   // Defines required variables
    int numerical_char;
    typedef std::string::size_type size_type;
    const size_type nChars {plaintext.size()};
    std::string crypted_string {""};
    std::string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    // Loops over the characters in the plaintext, encrypting one at a time 
    for (size_type j{0}; j < nChars; ++j) {

        // Maps each letter to a int, in order, i.e. A=0, B=1, C=2, ...
        numerical_char = (int) plaintext[j] - 65;
        // Applies the cyclic shift according to the key
        numerical_char = (numerical_char + key + 26)%26;   // Add the 26 to accound for negative keys
        //
        crypted_string += alphabet[numerical_char];
    }
    return crypted_string;
}