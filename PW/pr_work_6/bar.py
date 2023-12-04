#!/bin/env=python3

from glass import Glass

def menu(question, choices):
  '''реализация меню
     question - вопрос, что выбирать
     choices - контейнер с вариантами выбора
     возвращает выбранный элемент контейнера
  '''
  print(question)
  for n, c in enumerate(choices, 1):
      print(f'{n}. {c}')
  res = int(input('Ваш выбор >> '))
  if not 1 <= res <= len(choices):
      raise ValueError(f'Choice {res} not in menu')
  return tuple(choices)[res - 1]

def ask_volume(question, *, min_vol=1, max_vol=500):
  '''реализация целочисленного запроса
      question - вопрос, что ввоить
      min_vol, max_vol - диапазон вводимых значений
      возвращает веденное значение
  '''
  amount = int(input(f'{question} ({min_vol}-{max_vol}) '))
  if not min_vol <= amount <= max_vol:
      raise ValueError(f'The value should be {min_vol}-{max_vol}, not {amount}')
  return amount

def drink():
  'действие "отпить" в баре'
  liquid = glass.look()
  if liquid is None:
      print('В стакане пусто')
  else:
      print(f'В стакане {liquid}.', end=' ')
      if glass.drink(ask_volume('Сколько отопьете?', max_vol=glass.volume_)):
          print('Глык...глык...глык: Хорошо пошло !')
      else:
          print('Глык...глык: Маловато будет')
  return True

def fill():
  'действие "налить" в баре'
  liquid = menu('Что будете пить?', liquids)
  glass.fill(liquid, ask_volume('Cколько налить?', max_vol=glass.volume_))
  print('Готово!!!')
  return True

def bye():
  'действие "уйти" из бара'
  print('Заходите еще')
  return False

# варианты стаканов
glasses = {
  'Мерзавчик': Glass(125),
  'Чайный': Glass(200),
  'Граненый': Glass(250),
  'Кока-кольный': Glass(330)
  }

# варианты жидкостей
liquids = ('Вода с газом', 'Вода без газа',
           'Сок березовый', 'Мед липовый',
           'Керосин', 'Электролит',
           'Отвар коры дуба') 

# варианты действий в баре
actions = {'Налить': fill, 'Отпить': drink, 'Свалить': bye}

######################## main ########################
if __name__ == '__main__':
  print('Добро пожаловать в бар "На халяву"')
  glass = glasses[menu('Выберите стакан:', glasses.keys())]
  in_bar = True
  while in_bar:
      in_bar = actions[menu('Выберите действие:', actions.keys())]()
      print('-' * 20)

