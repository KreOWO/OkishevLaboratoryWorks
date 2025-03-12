from packages.lab_1n.main import lab_1n_start


def choice_lab():
    while True:
        newchoice = input('Введите номер лабораторной работы 1; 0 - выход из программы: ')
        if newchoice.isdigit() and (0 <= int(newchoice) <= 5):
            return int(newchoice)
        else:
            print('Неправильный ввод!')


def main():
    while True:
        [exit, lab_1n_start][choice_lab()]()


if __name__ == '__main__':
    main()
