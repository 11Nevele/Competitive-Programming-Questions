#include <iostream>
#include <string>
#include <vector>
#include <bitset>

// Function to encrypt/decrypt a string using XOR with a key
std::string xorEncryptDecrypt(const std::string& data, const std::string& key) {
    std::string output = data;
    for (size_t i = 0; i < data.length(); ++i) {
        output[i] = data[i] ^ key[i];
    }
    return output;
}

int main()
{
    std::string string1, string2;

    std::cout << "Enter the first string: ";
    std::getline(std::cin, string1);

    std::cout << "Enter the second string (the key, must be same length): ";
    std::getline(std::cin, string2);

    if (string1.length() != string2.length()) {
        std::cout << "Error: The two strings must have the same length." << std::endl;
        return 1; // Exit with an error code
    }

    // Encrypt the string
    std::string encrypted_string = xorEncryptDecrypt(string1, string2);
    std::cout << "Encrypted string (binary): ";
    for (char c : encrypted_string) {
        std::cout << std::bitset<8>(c) << ' ';
    }
    std::cout << std::endl;

    // Decrypt the string
    std::string decrypted_string = xorEncryptDecrypt(encrypted_string, string2);
    std::cout << "Decrypted string: " << decrypted_string << std::endl;

    return 0;
}