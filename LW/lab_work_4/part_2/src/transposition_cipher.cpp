#include "transposition_cipher.h"
#include <iostream>
#include "cipher_exception.h"

TranspositionCipher::TranspositionCipher(unsigned key, char symbol) {
  if (key < 2)
    throw CipherError("Invalid key");
  key_ = key;
  symbol_ = symbol;
}

std::string TranspositionCipher::encrypt(const std::string& message) {
  std::string cleaned_text = getValidOpenText(message);

  int message_length = cleaned_text.size();

  int on_table_length = (message_length/key_ + 1) * key_;

  std::string encrypted_message(on_table_length, symbol_);

  int rows = on_table_length / key_;

  for (int i=0; i<message_length; ++i) {
    int trp_i = rows * (key_ - (1 + (i % key_))) + (i / key_);
    encrypted_message.at(trp_i) = cleaned_text.at(i);
  }
  return encrypted_message;
}

std::string TranspositionCipher::decrypt(const std::string& message) {
  int message_length = getValidCipherText(message).size();
  int on_table_length = (message_length/key_ + (message_length % key_ != 0)) * key_;

  std::string decrypted_message(on_table_length, ' ');

  int rows = on_table_length / key_;

  for (int i=0; i<message_length; ++i) {
    int trp_i = key_ * (i % rows) + key_ - ((i / rows) + 1);
    if (message.at(i) == symbol_) {
      continue;
    }
    decrypted_message.at(trp_i) = message.at(i);
  }
  return decrypted_message;
}

std::string TranspositionCipher::getValidOpenText(const std::string & s) {
    std::string tmp;
    for (auto c:s) {
        if (isalpha(c)) {
            if (islower(c))
                tmp.push_back(toupper(c));
            else
                tmp.push_back(c);
        }
    }

    if (tmp.empty())
        throw CipherError("Empty open text");
    
    return tmp;
}

std::string TranspositionCipher::getValidCipherText(const std::string & s) {
    if (s.empty())
        throw CipherError("Empty cipher text");
    
    for (auto c:s) {
        if (c == symbol_)
          continue;
        if (!iswupper(c))
          throw CipherError(std::string("Invalid cipher text ")+s);
    }

    return s;
}