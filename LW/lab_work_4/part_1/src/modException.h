/**
 * @file modException.h
 * @author Шурыгин Д.Д.
 * @brief Файл с описанием класса ошибок
 * @date 2023-12-25
 */
#include <string>

/**
 * @brief Класс для ошибок
 */
class cipher_error {
private:
  std::wstring msg; ///< Сообщение об ошибке.
public:
  /**
   * @brief Конструктор со строкой.
   * 
   * @param [in] what_arg Сообщение.
   */
  cipher_error(const std::wstring& what_arg): msg(what_arg) {  }
  /**
   * @brief Конструктор с массивом символов.
   * 
   * @param [in] what_arg Сообщение.
   */
  explicit cipher_error(const wchar_t* what_arg): msg(what_arg) {  }
  /**
   * @brief Получить сообщение.
   * 
   * @return std::wstring Сообщение.
   */
  std::wstring what() const { return msg; }
};