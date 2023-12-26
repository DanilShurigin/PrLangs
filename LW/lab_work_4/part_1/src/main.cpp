#include <iostream>
#include <cctype>

#include "modAlphaCipher.h"
#include "modException.h"

using namespace std;

// проверка, чтобы строка состояла только из прописных букв
bool isValid(const wstring& s) {
    for(auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}

int main(int argc, char **argv) {
    locale loc("ru_RU.UTF-8");
    locale::global(loc);

    wstring key;
    wstring text;
    unsigned op;

    wcout<<"Cipher ready. Input key: ";
    wcin>>key;

    try {
        modAlphaCipher cipher(key);

        do {
            wcout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
            wcin>>op;

            if (op > 2) {
                wcout<<"Illegal operation\n";
            } else if (op >0) {
                wcout<<"Cipher ready. Input text: ";
                wcin>>text;
                
                if (op==1) {
                    wcout<<"Encrypted text: "<<cipher.encrypt(text)<<endl;
                } else {
                    wcout<<"Decrypted text: "<<cipher.decrypt(text)<<endl;
                }
            }
        } while (op!=0);
    } catch(const cipher_error& e) {
        wcout << e.what() << endl;
    }
    return 0;
}