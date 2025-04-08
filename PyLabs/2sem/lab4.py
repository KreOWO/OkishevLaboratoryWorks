import random


def rnd(n, m):
    return [[random.randint(-100, 100) for _ in range(m)] for _ in range(n)]


def print_matrix(matrix):
    for row in matrix:
        print(" ".join(f"{num:5d}" for num in row))


def sum_digits(n):
    return sum(int(d) for d in str(abs(n)))


def sum_divisible_by_3(matrix):
    total = 0
    for row in matrix:
        for num in row:
            if sum_digits(num) % 3 == 0:
                total += num
    return total


def gen_new(matrix, num):
    ret = []
    for row in matrix:
        for i in row:
            if i > num:
                ret.append(i)
    return ret


def lab_4_start():
    print('Выполнение лабораторной работы номер 4')
    n = int(input("Введите количество строк: "))
    m = int(input("Введите количество столбцов: "))

    matrix = rnd(n, m)
    print("\nСгенерированная матрица:")
    print_matrix(matrix)

    sum_task = sum_divisible_by_3(matrix)
    print(f"\nСумма элементов с суммой цифр кратной 3: {sum_task}")

    arr_task = gen_new(matrix, sum_task)
    print(f"\nЭлементы матрицы, большие чем {sum_task}: ")
    print(arr_task)
