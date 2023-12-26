#include <iostream>

#include "transposition_cipher.h"
#include "cipher_exception.h"

int main() {
  unsigned key;

  std::cout << "Enter key (count of columns): ";
  std::cin >> key;
  try {
    TranspositionCipher cipher(key);

    int operation;
    do {
      std::cout << "Choose an operation: 0 (exit), 1 (encrypt), 2 (decrypt): ";
      std::string message;
      std::cin >> operation;

      if (operation == 0) {
        return 0;
      } else if (operation == 1) {
        std::cout << "Enter message to encrypt: ";
        std::cin >> message;
        std::cout << "Result: " << cipher.encrypt(message) << std::endl;
      } else if (operation == 2) {
        std::cout << "Enter message to decrypt: ";
        std::cin >> message;
        std::cout << "Result: " << cipher.decrypt(message) << std::endl;
      } else {
        std::cout << "Input error. Unknown operation" << std::endl;
        return 1;
      }
    } while (true);
  } catch(const CipherError& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}