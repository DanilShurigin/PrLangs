#include <UnitTest++/UnitTest++.h>

#include "src/transposition_cipher.hpp"
#include "src/cipher_exception.h"

SUITE(KeyTest) {
  TEST(ValidKey) {
    CHECK_EQUAL("A-AAAA", TranspositionCipher(3).encrypt("AAAAA"));
  }
  TEST(LongKey) {
    CHECK_THROW(TranspositionCipher(-10).encrypt("AAAAA"), CipherError);
  }
  TEST(LowCaseKey) {
    CHECK_THROW(TranspositionCipher(0).encrypt("AAAAA"), CipherError);
  }
}

SUITE(EncryptTest)
{
  TEST(UpCaseString) {
    CHECK_EQUAL("UROPRAG-QBFMELO-EKNUVED-HCWJOHY-TIOXSTZ-",
                TranspositionCipher{5}.encrypt("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG"));
  }
  TEST(LowCaseString) {
    CHECK_EQUAL("UROPRAG-QBFMELO-EKNUVED-HCWJOHY-TIOXSTZ-",
                TranspositionCipher{5}.encrypt("thequickbrownfoxjumpsoverthelazydog"));
  }
  TEST(StringWithWhitspaceAndPunct) {
    CHECK_EQUAL("UROPRAG-QBFMELO-EKNUVED-HCWJOHY-TIOXSTZ-",
                TranspositionCipher{5}.encrypt("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG!!!"));
  }
  TEST(StringWithNumbers) {
    CHECK_EQUAL("YE-PY-PW-AERHNA", TranspositionCipher{5}.encrypt("Happy New 2023 Year"));
  }
  TEST(EmptyString) {
    CHECK_THROW(TranspositionCipher{5}.encrypt(""), CipherError);
  }
  TEST(NoAlphaString) {
    CHECK_THROW(TranspositionCipher{5}.encrypt("1234+8765=9999"), CipherError);
  }
}

SUITE(DecryptText)
{
  TEST(UpCaseString) {
    CHECK_EQUAL("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",
                TranspositionCipher{5}.decrypt("UROPRAG-QBFMELO-EKNUVED-HCWJOHY-TIOXSTZ-"));
  }
  TEST(LowCaseString) {
    CHECK_THROW(TranspositionCipher{5}.decrypt("UropRAG-QBFMELO-EKNuveD-HCwJOHY-TIOXSTz-"), CipherError);
  }
  TEST(DigitsString) {
    CHECK_THROW(TranspositionCipher{5}.decrypt("HappyNew2023Year"), CipherError);
  }
  TEST(PunctString) {
    CHECK_THROW(TranspositionCipher{5}.decrypt("UROPRAG.QBFMELO.EKNUVED.HCWJOHY.TIOXSTZ-"), CipherError);
  }
  TEST(EmptyString) {
    CHECK_THROW(TranspositionCipher{5}.decrypt(""), CipherError);
  }
}

int main() {
  UnitTest::RunAllTests();
  return 0;
}