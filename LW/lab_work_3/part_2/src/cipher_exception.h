#include <stdexcept>
#include <string>

class CipherError : public std::invalid_argument {
public:
  explicit CipherError(const std::string& msg):
      std::invalid_argument(msg) {  }
  explicit CipherError(const char* msg):
      std::invalid_argument(msg) {  }
};