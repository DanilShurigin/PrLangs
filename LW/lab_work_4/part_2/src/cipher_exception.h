/**
 * @file cipher_exception.h
 * @author Шурыгин Д.Д.
 * @brief Файл с классом ошибок.
 * @date 2023-12-25
 */
#include <stdexcept>
#include <string>

/**
 * @brief Класс ошибок.
 */
class CipherError : public std::invalid_argument {
public:
    /**
     * @brief Конструктор со строкой.
     * 
     * @param [in] msg Строка.
     */
  explicit CipherError(const std::string& msg):
      std::invalid_argument(msg) {  }
      /**
       * @brief Конструктор с массивом символов.
       * 
       * @param [in] msg Массив символов.
       */
  explicit CipherError(const char* msg):
      std::invalid_argument(msg) {  }
};