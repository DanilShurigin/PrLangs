#include <string>

class cipher_error {
private:
  std::wstring msg;
public:
  cipher_error(const std::wstring& what_arg): msg(what_arg) {  }
  explicit cipher_error(const wchar_t* what_arg): msg(what_arg) {  }
  std::wstring what() const { return msg; }
};