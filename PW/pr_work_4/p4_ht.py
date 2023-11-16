"""
Студент: Шурыгин Д.Д.
Группа: 22ПТ2
Полиалфавитное шифрование
"""

# Random lib
from random import seed, randrange

# Предустановленные алфавиты
alphabets = {
    '_ru': 'АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ',
    '_en': 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
}

# Создание гаммы шифра
def createGamma(key, textLength:int, lowerBound:int, upperBound:int):
    seed(key)
    return list(randrange(lowerBound, upperBound) for i in range(textLength))

# Приведение текста к стандартному виду
def cleanText(text:str, alphabet:str):
    text = text.upper()
    return ''.join(char for char in text if char in alphabet)

# Полиалфавитный шифр
def code(text:str, alphabet:str, key, opType:str):
    cleanedText = cleanText(text, alphabet)

    cleanedTextLength = len(cleanedText)
    alphabetLength = len(alphabet)

    if( opType == 'encode' ):
        fun = lambda t_ind, g_ind: (t_ind + g_ind) % alphabetLength
    elif( opType == 'decode' ):
        fun = lambda t_ind, g_ind: (t_ind - g_ind) % alphabetLength
    else:
        return '<Unknown operation>'

    gamma = createGamma(key, cleanedTextLength, 0, alphabetLength)
    # Список индексов символов начального текста
    textInd = list(alphabet.index(char) for char in cleanedText)
    # Сдвиг по ключам из gamma
    newTextInd = map(fun, textInd, gamma)
    # Объединение списка в прописной текст
    newText = ''.join(alphabet[ind] for ind in newTextInd)
    
    return newText

# Зашифрование
def encode(text:str, alphabet:str, key):
    return code(text, alphabet, key, 'encode')
# Расшифрование
def decode(text:str, alphabet:str, key):
    return code(text, alphabet, key, 'decode')

# Изменить алфавит
def changeAlphabet():
    print('RU -> _ru | EN -> _en | castom')
    inpLine = input('ALPHABET > ')
    if( inpLine in '_ru_en' ):
        return alphabets[inpLine]
    return inpLine.upper()

alphabet = ''
isFirst = True

while( True ):
    if( isFirst ):
        alphabet = changeAlphabet()
        isFirst = False
    else:
        inpLine = input('\n(< any_key+Enter > to continue or < q+Enter > to exit) ')
        if( inpLine == 'q' ): break
    
    print('\nOPERATIONS:\n0 - Change alphabet\n1 - Encode message\n2 - Decode message\n')
    inpCommand = input('> ')

    if( inpCommand == '0' ):
        alphabet = changeAlphabet
        continue

    if( inpCommand in '12' ):
        if( len(alphabet) == 0 ):
            print('Alphabet is empty')
            continue

        try:
            inpText = input('TEXT:\t')
            key = int(input('KEY:\t'))
        except ValueError:
            print('<Input error>')
            continue

        if( inpCommand == '1' ):
            print(f"RESULT:\t{encode(inpText, alphabet, key)}")
        elif( inpCommand == '2' ):
            print(f"RESULT:\t{decode(inpText, alphabet, key)}")
        continue

    print("<Unknown operation>")
    
