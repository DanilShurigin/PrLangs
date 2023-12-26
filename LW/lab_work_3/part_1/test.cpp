#include <UnitTest++/UnitTest++.h>

#include "src/modAlphaCipher.h"
#include "src/modException.h"

SUITE(KeyTest) {
  TEST(ValidKey) {
    CHECK(L"БВГБВ" == modAlphaCipher(L"БВГ").encrypt(L"ААААА"));
  }
  TEST(LongKey) {
    CHECK(L"БВГДЕ" == modAlphaCipher(L"BCDEFGHIJK").encrypt(L"ААААА"));
  }
  TEST(LowCaseKey) {
    CHECK(L"БВГБВГ" == modAlphaCipher(L"бвг").encrypt(L"ААААА"));
  }
  TEST(DigitsInKey) {
    CHECK_THROW(modAlphaCipher cp(L"Б1"), cipher_error);
  }
  TEST(PunctuationInKey) {
    CHECK_THROW(modAlphaCipher cp(L"Б,В"), cipher_error);
  }
  TEST(WhitespaceInKey) {
    CHECK_THROW(modAlphaCipher cp(L"Б В"), cipher_error);
  }
  TEST(EmptyKey) {
    CHECK_THROW(modAlphaCipher cp(L""), cipher_error);
  }
  TEST(WeakKey) {
    CHECK_THROW(modAlphaCipher cp(L"ААА"), cipher_error);
  }
}

SUITE(EncryptTest) {
  TEST(UpCaseString) {
    CHECK(L"ЕСФДНПКЮМЭХАЩЛЁВТГЖИРУЙЧЯЗОЬЦШБЪ" == \
                modAlphaCipher{L"Б"}.encrypt(L"ДругмойэльфЯшкебсвёзптицюжныхчащ"));
  }
  TEST(LowCaseString) {
    CHECK(L"ЕСФДНПКЮМЭХАЩЛЁВТГЖИРУЙЧЯЗОЬЦШБЪ" == \
                modAlphaCipher{L"Б"}.encrypt(L"другмойэльфЯшкебсвёзптицюжныхчащ"));
  }
  TEST(StringWithWhitspaceAndPunct) {
    CHECK(L"ЕСФД" == \
                modAlphaCipher{L"Б"}.encrypt(L"Друг мой эльф! Яшке б свёз птиц южных чащ!"));
  }
  TEST(StringWithNumbers) {
    CHECK(L"ОБ" == modAlphaCipher{L"Б"}.encrypt(L"На дворе 2023 год"));
  }
  TEST(EmptyString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.encrypt(L""),cipher_error);
  }
  TEST(NoAlphaString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.encrypt(L"123456789-987654321"),cipher_error);
  }
  TEST(MaxShiftKey) {
    CHECK(L"ГПТВЛНИЬКЫУЮЧЙДАРБЕЖОСЗХЭЁМЪФЦЯШ" == \
                modAlphaCipher(L"Z").encrypt(L"ДРУГМОЙЭЛЬФЯШКЕБСВЁЗПТИЦЮЖНЫХЧАЩ"));
  }
}

SUITE(DecryptText)
{
  TEST(UpCaseString) {
    CHECK(L"ДРУГМОЙЭЛЬФЯШКЕБСВЁЗПТИЦЮЖНЫХЧАЩ" == \
                modAlphaCipher{L"Б"}.decrypt(L"ЕСФДНПКЮМЭХАЩЛЁВТГЖИРУЙЧЯЗОЬЦШБЪ"));
  }
  TEST(LowCaseString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.decrypt(L"ЕсФДнПКЮМЭХАЩЛЁВТГжИРуЙЧЯЗОыЦШБЪ"),cipher_error);
  }
  TEST(WhitespaceString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.decrypt(L"ЕСФДНПКЮМЭХАЩЛЁВТГЖИРУЙЧЯЗОЬЦ_ШБЪ"),cipher_error);
  }
  TEST(DigitsString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.decrypt(L"ОБ КГВЕНА 2023 РОД"),cipher_error);
  }
  TEST(PunctString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.decrypt(L"ВГДЕЁ?"),cipher_error);
  }
  TEST(EmptyString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.decrypt(L""),cipher_error);
  }
  TEST(MaxShiftKey) {
    CHECK(L"ДРУГМОЙЭЛЬФЯШКЕБСВЁЗПТИЦЮЖНЫХЧАЩ" == \
                modAlphaCipher(L"Z").decrypt(L"ЕСФДНПКЮМЭХАЩЛЁВТГЖИРУЙЧЯЗОЬЦШБЪ"));
  }
}

int main() {
  UnitTest::RunAllTests();
  return 0;
}