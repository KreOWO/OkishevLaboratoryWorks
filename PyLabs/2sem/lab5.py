import random
import pickle
import shelve


def rnd(n, m):
    return [[random.randint(-10, 10) for _ in range(m)] for _ in range(n)]


def avg_and_zeros(matrix):
    # Вычисление среднего значения и количества нулей
    total = 0
    count = 0
    zeros = 0

    for row in matrix:
        for num in row:
            total += num
            count += 1
            if num == 0:
                zeros += 1

    return total / count if count != 0 else 0, zeros


def print_matrix(matrix):
    for row in matrix:
        print(' '.join(f"{num:4}" for num in row))


def save_to_binary(filename, a, avg_value, zero_count):
    # Сохранение данных в бинарный файл
    data = {"matrix": a, "average": avg_value, "zero_count": zero_count}
    with open(filename, "wb") as file:
        pickle.dump(data, file)


def load_from_binary(filename):
    # Загрузка данных из бинарного файла
    with open(filename, "rb") as file:
        data = pickle.load(file)
    return data["matrix"], data["average"], data["zero_count"]


def save_to_shelve(filename, a, avg_value, zero_count):
    # Сохранение данных в shelve
    with shelve.open(filename) as db:
        db["matrix"] = a
        db["average"] = avg_value
        db["zero_count"] = zero_count


def load_from_shelve(filename):
    # Загрузка данных из shelve
    with shelve.open(filename) as db:
        matrix = db.get("matrix", [])
        average = db.get("average", 0)
        zero_count = db.get("zero_count", 0)
    return matrix, average, zero_count


def lab_5_start():
    print('Выполнение лабораторной работы номер 5')
    # Основная программа
    n = int(input("Введите количество строк: "))
    m = int(input("Введите количество столбцов: "))

    matrix = rnd(n, m)
    print("\nСгенерированная матрица:")
    print_matrix(matrix)

    average, zeros = avg_and_zeros(matrix)

    # Работа с бинарным файлом
    save_to_binary("database/matrix_data.bin", matrix, average, zeros)
    loaded_matrix, loaded_average, loaded_zeros = load_from_binary("database/matrix_data.bin")

    print("\nЗагруженные данные из бинарного файла:")
    print_matrix(loaded_matrix)
    print(f"\nСреднее арифметическое: {loaded_average:.2f}")
    print(f"Количество нулевых элементов: {loaded_zeros}")

    # Работа с shelve
    save_to_shelve("database/matrix_shelve", matrix, average, zeros)
    loaded_matrix, loaded_average, loaded_zeros = load_from_shelve("database/matrix_shelve")

    print("\nЗагруженные данные из shelve:")
    print_matrix(loaded_matrix)
    print(f"\nСреднее арифметическое: {loaded_average:.2f}")
    print(f"Количество нулевых элементов: {loaded_zeros}")
