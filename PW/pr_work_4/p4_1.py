"""
Студент: Шурыгин Д.Д.
Группа: 22ПТ2
"""

def replaceInList(in_list, dictionary):
    return list((dictionary.get(el, el) for el in in_list))

test_list_1 = ['ctf.pnzgu.ru', 'yandex.ru', 'dpo.pnzgu.ru', 'google.com', 'moodle.pnzgu.ru', 'lk.pnzgu.ru']
test_dict_1 = {'ctf.pnzgu.ru': '82.179.90.12', 'ibst.pnzgu.ru': '82.179.90.69', 'beda.pnzgu.ru': '82.179.90.69',
               'lk.pnzgu.ru': '82.179.90.10', 'moodle.pnzgu.ru': '82.179.90.15', 'dpo.pnzgu.ru': '82.179.90.54'}

test_list_2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
test_dict_2 = {1: 'один', 2: 'два', 3: 'три', 4: 'четыре', 5: 'пять', 11: 'одиннадцать'}

test_list_3 = ['поганка', 'мухомор', 'подберезовик', 'груздь', 666]
test_dict_3 = {'поганка': False, 'мухомор': False, 'подберезовик': True, 'груздь': True, 'Рыжик': True}

print(replaceInList(test_list_3, test_dict_3))