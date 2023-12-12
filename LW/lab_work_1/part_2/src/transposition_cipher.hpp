#pragma once

#include <string>
#include <vector>

class TranspositionCipher {
  public:
    TranspositionCipher() = delete;
    TranspositionCipher(unsigned key): key_(key) { };

    std::string encrypt(const std::string& message);
    std::string decrypt(const std::string& message);
  private:
    unsigned key_;
};