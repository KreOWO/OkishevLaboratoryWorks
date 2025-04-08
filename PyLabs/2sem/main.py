from lab1 import lab_1_2_start
from lab3 import lab_3_start
from lab4 import lab_4_start
from lab5 import lab_5_start


def choice_lab():
    while True:
        newchoice = input('Введите номер лабораторной работы (1, 3 - 5); 0 - выход из программы: ')
        if newchoice.isdigit() and (int(newchoice) in [0, 1, 3, 4, 5]):
            return int(newchoice)
        else:
            print('Неправильный ввод!')


def main():
    while True:
        [exit, lab_1_2_start, exit, lab_3_start, lab_4_start, lab_5_start][choice_lab()]()


if __name__ == '__main__':
    main()
