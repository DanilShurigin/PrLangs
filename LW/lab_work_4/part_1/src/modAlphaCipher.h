/**
 * @file modAlphaCipher.h
 * @author Шурыгин Д.Д.
 * @brief Файл с описание класса modAlphaCipher.
 * @date 2023-12-25
 */
#pragma once

#include <vector>
#include <string>
#include <map>

/**
 * @brief Класс для зашифрования и расшифрования текста.
 */
class modAlphaCipher {
    private:
        std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< алфавит по порядку
        std::map <char,int> alphaNum; ///< ассоциативный массив "номер по символу"
        std::vector <int> key; // ключ
        /**
         * @brief Преобразовать строку в вектор.
         * 
         * @param [in] s Строка.
         * @return std::vector<int> Вектор индексов.
         */
        std::vector<int> convert(const std::wstring& s);
        /**
         * @brief Преобразовать вектор в строку.
         * 
         * @param [in] v Вектор индексов.
         * @return std::vector<int> Строка.
         */
        std::wstring convert(const std::vector<int>& v);
        /**
         * @brief Проверить и получить ключ.
         * 
         * @param [in] s Строка-ключ.
         * @return std::wstring Обработанный ключ.
         */
        std::wstring getValidKey(const std::wstring & s);
        /**
         * @brief Проверить и получить открытый текст.
         * 
         * @param [in] s Открытый текст.
         * @return std::wstring Обработанная строка.
         */
        std::wstring getValidOpenText(const std::wstring & s);
        /**
         * @brief Проверить и получить шифротекст.
         * 
         * @param [in] s Шифротекст. 
         * @return std::wstring Обработанная строка.
         */
        std::wstring getValidCipherText(const std::wstring & s);
    public:
        modAlphaCipher()=delete;
        /**
         * @brief Конструктор с ключом.
         * 
         * @param [in] skey Ключ. 
         */
        modAlphaCipher(const std::wstring& skey);
        /**
         * @brief Зашифровать текст.
         * 
         * @param [in] open_text Открытый текст. 
         * @return std::wstring Зашифрованный текст.
         */
        std::wstring encrypt(const std::wstring& open_text);
        /**
         * @brief Расшифровать текст.
         * 
         * @param [in] cipher_text Зашифрованный текст 
         * @return std::wstring Открытый текст.
         */
        std::wstring decrypt(const std::wstring& cipher_text);
};