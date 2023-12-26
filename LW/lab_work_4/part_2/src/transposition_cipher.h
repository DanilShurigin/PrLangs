/**
 * @file transposition_cipher.hpp
 * @author Шурыгин Д.Д.
 * @brief Файл с описанием класса TranspositionCipher.
 * @date 2023-12-25
 */
#pragma once

#include <string>
#include <vector>

/**
 * @brief Класс для зашифрованиея и расшифрования текста.
 */
class TranspositionCipher {
  public:
    TranspositionCipher() = delete;
    /**
     * @brief Конструктор с ключом.
     * 
     * @param [in] key Ключ (число от 2 и больше).
     * @param [in] symbol Символ-заполнитель пробелов.
     */
    TranspositionCipher(unsigned key, char symbol='-');

    /**
     * @brief Зашифровать текст.
     * 
     * @throw CipherError Ошибка зашифрования.
     * Параметры исключений:
     * @code {.cpp}
     * what = "Empty text"
     * @endcode
     * 
     * @param [in] message Открытый текст.
     * @return std::string Зашифрованное сообщение.
     */
    std::string encrypt(const std::string& message);
    /**
     * @brief Расшифровать текст.
     * 
     * @throw CipherError Ошибка расшифрования.
     * Параметры исключений:
     * @code {.cpp}
     * what = "Empty text"
     *        "Invalid text"
     * @endcode
     * 
     * @param [in] message Зашифрованный текст.
     * @return std::string Расшифрованное сообщение.
     */
    std::string decrypt(const std::string& message);
  private:
    unsigned key_;  ///< Ключ.
    char symbol_;   ///< Символ-заполнитель.

    /**
     * @brief Проверить и получить открытый текст.
     * 
     * @param [in] s Открытый текст.
     * @return std::wstring Обработанная строка.
     */
    std::string getValidOpenText(const std::string & s);
    /**
     * @brief Проверить и получить шифротекст.
     * 
     * @param [in] s Шифротекст. 
     * @return std::wstring Обработанная строка.
     */
    std::string getValidCipherText(const std::string & s);
};