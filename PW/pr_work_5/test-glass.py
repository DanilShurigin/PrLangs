'''
    Программа для тестирования класса Glass
    Класс Glass должен быть в файле glass.py в этом же каталоге
    В нем должны быть реализованы методы:
    Glass.__init__(self, volume)       - инициализировать
    Glass.fill(self, liquid, amount)   - наполнить жидкостью
    Glass.look(self)                   - посмотреть, что налито
    Glass.drink(self, amount)          - отпить содержимое
'''
from unittest import TestCase
from p5_0 import Glass

test = TestCase()

graneniy = Glass(250)

test.assertIsNone(graneniy.look(), msg='новый стакан не пуст')
graneniy.fill('вода', 100)
graneniy.fill('вода', 100)
with test.assertRaises(OverflowError, msg='переполнение не зафиксировано'):
    graneniy.fill('вода', 100) 
with test.assertRaises(ValueError, msg='смешивание жидкостей не зафиксировано'):
    graneniy.fill('вино', 100) 
test.assertEqual(graneniy.look(), 'вода', msg='в стакане должна быть вода')
test.assertTrue(graneniy.drink(150), msg='жидкости должно было хватить')
test.assertEqual(graneniy.look(), 'вода', msg='в стакане должна быть вода')
test.assertTrue(graneniy.drink(50), msg='жидкости должно было хватить')
test.assertIsNone(graneniy.look(), msg='в стакане должно быть пусто')
graneniy.fill('вино', 100)
test.assertEqual(graneniy.look(), 'вино', msg='в стакане должно быть вино')
test.assertFalse(graneniy.drink(150), msg='жидкости должно было не хватить')
test.assertIsNone(graneniy.look(), msg='в стакане должно быть пусто')

print('Все тесты пройдены')
