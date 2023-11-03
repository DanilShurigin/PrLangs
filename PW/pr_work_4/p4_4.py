"""
Студент: Шурыгин Д.Д.
Группа: 22ПТ2
"""

filePath = '/home/kopernik/Downloads/Pract4.files/zadanie3.3.txt'
alphabet = 'АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'

def detectCharFr(filePath):
    fileStr = ''
    with open(filePath, 'r', encoding='UTF8') as file:
        fileStr = file.read()
        fileStr.upper()
        
    chars = list(char for char in fileStr if char in alphabet)
    charFr = {char:chars.count(char)/len(chars) for char in set(chars)}
    return charFr

def printCharFr(charFr, mode):
    '''
        mode = 0 : Сортировка по алфавиту
        mode = 1 : Сортировка по частоте убывания
    '''
    if( 0 > mode > 1 ):print('Ошибка параметра');return

    for (char, fr) in sorted(charFr.items(), key=lambda item: item[mode], reverse=mode):
        print(f"'{char}' : {fr}")

result = detectCharFr(filePath)
printCharFr(result, 0)
print(f'\nСумма частот: {sum((n for _,n in result.items()))}')