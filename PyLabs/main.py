from packages.lab_1.main import lab_1_start
from packages.lab_2.main import lab_2_start
from packages.lab_3.main import lab_3_start
from packages.dop_task.main import dop_task_start
from packages.lab_5.main import lab_5_start


def choice_lab():
    while True:
        newchoice = input('Введите номер лабораторной работы (1 - 3, 5); 4 - допзадачи; 0 - выход из программы: ')
        if newchoice.isdigit() and (0 <= int(newchoice) <= 5):
            return int(newchoice)
        else:
            print('Неправильный ввод!')


def main():
    while True:
        [exit, lab_1_start, lab_2_start, lab_3_start, dop_task_start, lab_5_start][choice_lab()]()


if __name__ == '__main__':
    main()
