#include <iostream>
#include <string>

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string encrypt(std::string plaintext, int key);

int main() {
    std::string plaintext = "HELLO";
    int key = 3;

    std::string ciphertext = encrypt(plaintext, key);

    std::cout << ciphertext << std::endl;
}

std::string encrypt(std::string plaintext, int key) {
    std::string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];

        for (int j = 0; j < 26; j++) {
            if (c == alphabet[j]) {
                ciphertext += alphabet[(j + key) % 26];
                break;
            }
        }
    }

    return ciphertext;
}
