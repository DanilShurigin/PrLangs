#pragma once

#include <string>
#include <vector>

class TranspositionCipher {
  public:
    TranspositionCipher() = delete;
    TranspositionCipher(unsigned key, char symbol='-');

    std::string encrypt(const std::string& message);
    std::string decrypt(const std::string& message);
  private:
    unsigned key_;
    char symbol_;

    std::string getValidOpenText(const std::string & s);
    std::string getValidCipherText(const std::string & s);
};