from lab1 import lab_1n_start
from lab3 import lab_3_start


def choice_lab():
    while True:
        newchoice = input('Введите номер лабораторной работы (1, 2, 3); 0 - выход из программы: ')
        if newchoice.isdigit() and (0 <= int(newchoice) <= 5):
            return int(newchoice)
        else:
            print('Неправильный ввод!')


def main():
    while True:
        [exit, lab_1n_start, exit, lab_3_start][choice_lab()]()


if __name__ == '__main__':
    main()
