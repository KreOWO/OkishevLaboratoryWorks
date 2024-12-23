from functs import solve12, vvod, vivod


def lab_1_start():
    print('Выполнение лабораторной работы номер 1')
    a, b, x = vvod('Введите a'), vvod('Введите b'), vvod('Введите x')
    zw = {'z': 0, 'w': 0}
    solve12(zw, a, b, x)
    vivod('z', zw['z'])
    vivod('w', zw['w'])
    print('Завершение выполнения лабораторной работы номер 1\n')
