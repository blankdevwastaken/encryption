#include <iostream>
#include <string>
#include <fstream> 

const std::string alphabetupper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string alphabetlower = "abcdefghijklmnopqrstuvwxyz";
std::string encrypt(std::string plaintext, int key);\
std::string decrypt(std::string ciphertext, int key);
bool check(char tochek)
{
    if (isupper(tochek)) {
        return true;
	}
	else if (islower(tochek)) {
		return false;
	}
	return false; 
}

int main() {
	std::string plaintext;
	std::string choice;
	int key;


	std::cout << "Welcome to the Caesar Cipher program!" << std::endl;
	std::cout << "Please enter if you want to encrypt/decrypt: ";
	std::cin >> choice;
	if (choice == "decrypt") {
		std::string ciphertext;
		std::cout << "Enter the ciphertext: ";
		std::cin >> ciphertext;
		std::cout << "Enter the key: ";
		std::cin >> key;
		std::string plaintext = decrypt(ciphertext, key);
		std::cout << "Decrypted plaintext: " << plaintext << std::endl;
	}
	else {
		std::cout << "Enter the plaintext: ";
		std::cin >> plaintext;
		std::cout << "Enter the key: ";

		std::cin >> key;

		std::string ciphertext = encrypt(plaintext, key);
		std::cout << "Ciphertext: " << ciphertext << std::endl;
		std::ofstream KeyFile("key.txt");
		KeyFile << "Your key is : " << key << std::endl;
		KeyFile.close();
	}
}

std::string encrypt(std::string plaintext, int key) {
    std::string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
		bool type = check(c);
        for (int j = 0; j < 26; j++) {
				if (type && c == alphabetupper[j]) {
					ciphertext += alphabetupper[(j + key) % 26];
					break;
				}
				else if (!type && c == alphabetlower[j]) {
					ciphertext += alphabetlower[(j + key) % 26];
					break;
				}
		}
    }

    return ciphertext;
}
std::string decrypt(std::string ciphertext, int key) {
	std::string plaintext = "";

	for (int i = 0; i < ciphertext.length(); i++) {
		char c = ciphertext[i];
		bool type = check(c);
		for (int j = 0; j < 26; j++) {
				if (type && c == alphabetupper[j]) {
					plaintext += alphabetupper[(j - key + 26) % 26];
					break;
				}
				else if (!type && c == alphabetlower[j]) {
					plaintext += alphabetlower[(j - key + 26) % 26];
					break;
				}
		}
	}

	return plaintext;


}