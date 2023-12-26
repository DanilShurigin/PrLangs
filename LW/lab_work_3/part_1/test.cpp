#include <UnitTest++/UnitTest++.h>

#include "src/modAlphaCipher.h"
#include "src/modException.h"

SUITE(KeyTest) {
  TEST(ValidKey) {
    CHECK(L"БВГБВ" == modAlphaCipher(L"БВГ").encrypt(L"ААААА"));
  }
  TEST(LongKey) {
    CHECK(L"BCDEF" == modAlphaCipher(L"BCDEFGHIJK").encrypt(L"AAAAA"));
  }
  TEST(LowCaseKey) {
    CHECK(L"BCDBC" == modAlphaCipher(L"bcd").encrypt(L"AAAAA"));
  }
  TEST(DigitsInKey) {
    CHECK_THROW(modAlphaCipher cp(L"B1"), cipher_error);
  }
  TEST(PunctuationInKey) {
    CHECK_THROW(modAlphaCipher cp(L"B,C"), cipher_error);
  }
  TEST(WhitespaceInKey) {
    CHECK_THROW(modAlphaCipher cp(L"B C"), cipher_error);
  }
  TEST(EmptyKey) {
    CHECK_THROW(modAlphaCipher cp(L""), cipher_error);
  }
  TEST(WeakKey) {
    CHECK_THROW(modAlphaCipher cp(L"AAA"), cipher_error);
  }
}

SUITE(EncryptTest)
{
  TEST(UpCaseString) {
    CHECK(L"UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZEPH" == \
                modAlphaCipher{L"Б"}.encrypt(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG"));
  }
  TEST(LowCaseString) {
    CHECK(L"UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZEPH" == \
                modAlphaCipher{L"Б"}.encrypt(L"thequickbrownfoxjumpsoverthelazydog"));
  }
  TEST(StringWithWhitspaceAndPunct) {
    CHECK(L"UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZEPH" == \
                modAlphaCipher{L"Б"}.encrypt(L"THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG!!!"));
  }
  TEST(StringWithNumbers) {
    CHECK(L"IBQQZOFXZFBS" == modAlphaCipher{L"Б"}.encrypt(L"Happy New 2019 Year"));
  }
  TEST(EmptyString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.encrypt(L""),cipher_error);
  }
  TEST(NoAlphaString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.encrypt(L"1234+8765=9999"),cipher_error);
  }
  TEST(MaxShiftKey) {
    CHECK(L"SGDPTHBJAQNVMENWITLORNUDQSGDKZYXCNF" == \
                modAlphaCipher(L"Z").encrypt(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG"));
  }
}

SUITE(DecryptText)
{
  TEST(UpCaseString) {
    CHECK(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG" == \
                modAlphaCipher{L"Б"}.decrypt(L"UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZEPH"));
  }
  TEST(LowCaseString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.decrypt(L"uifRVJDLCSPXOGPYKVNQTPWFSUIFMBAZEPH"),cipher_error);
  }
  TEST(WhitespaceString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.decrypt(L"UIF RVJDL CSPXO GPY KVNQT PWFS UIF MBAZ EPH"),cipher_error);
  }
  TEST(DigitsString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.decrypt(L"IBQQZOFX2019ZFBS"),cipher_error);
  }
  TEST(PunctString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.decrypt(L"IFMMP,XPSME"),cipher_error);
  }
  TEST(EmptyString) {
    CHECK_THROW(modAlphaCipher{L"Б"}.decrypt(L""),cipher_error);
  }
  TEST(MaxShiftKey) {
    CHECK(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG" == \
                modAlphaCipher(L"Z").decrypt(L"SGDPTHBJAQNVMENWITLORNUDQSGDKZYXCNF"));
  }
}

int main() {
  UnitTest::RunAllTests();
  return 0;
}