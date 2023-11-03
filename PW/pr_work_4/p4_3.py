"""
Студент: Шурыгин Д.Д.
Группа: 22ПТ2
"""

filePath = '/home/kopernik/Downloads/Pract4.files/zadanie3.1.txt'
alphabet = 'АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'

def detectCharFr(filePath):
    fileStr = ''
    with open(filePath, 'r', encoding='UTF8') as file:
        fileStr = file.read()
        fileStr.upper()
        
    chars = list(char for char in fileStr if char in alphabet)
    charFr = {char:chars.count(char)/len(chars) for char in set(chars)}
    return charFr

result = detectCharFr(filePath)

print(*result.items(), sep='\n')
print(f'\nСумма частот: {sum((n for _,n in result.items()))}')