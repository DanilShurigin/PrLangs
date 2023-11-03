#include "modAlphaCipher.h"

modAlphaCipher::modAlphaCipher(const std::string& skey) {
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(skey);
}

std::string modAlphaCipher::encrypt(const std::string& open_text) {
    std::vector<int> work = convert(open_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

std::string modAlphaCipher::decrypt(const std::string& cipher_text) {
    std::vector<int> work = convert(cipher_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

inline std::vector<int> modAlphaCipher::convert(const std::string& s) {
    std::vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}

inline std::string modAlphaCipher::convert(const std::vector<int>& v) {
    std::string result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}