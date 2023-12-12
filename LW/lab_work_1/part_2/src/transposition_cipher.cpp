#include "transposition_cipher.hpp"
#include <iostream>

std::string TranspositionCipher::encrypt(const std::string& message) {
  int message_length = message.size();
  int on_table_length = (message_length/key_ + 1) * key_;

  std::string encrypted_message(on_table_length, '-');

  int rows = on_table_length / key_;

  for (int i=0; i<message_length; ++i) {
    int trp_i = rows * (key_ - (1 + (i % key_))) + (i / key_);
    encrypted_message.at(trp_i) = message.at(i);
  }
  return encrypted_message;
}

std::string TranspositionCipher::decrypt(const std::string& message) {
  int message_length = message.size();
  int on_table_length = (message_length/key_ + (message_length % key_ != 0)) * key_;

  std::string decrypted_message(on_table_length, ' ');

  int rows = on_table_length / key_;

  for (int i=0; i<message_length; ++i) {
    int trp_i = key_ * (i % rows) + key_ - ((i / rows) + 1);
    if (message.at(i) == '-') {
      continue;
    }
    decrypted_message.at(trp_i) = message.at(i);
  }
  return decrypted_message;
}