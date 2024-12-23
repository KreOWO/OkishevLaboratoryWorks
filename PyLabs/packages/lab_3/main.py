import random
from functs import vvod, gen_array, save_to_word, save_to_file, save_to_sqlite, save_to_excel


def choice_task():
    while True:
        newchoice = input('Введите номер задания для выполнения (3, 4, 7, 8, 10 - 13); 100 - выполнение всех заданий и сохранение результатов; 0 - выход из программы: ')
        tasks = [0, 3, 4, 7, 8, 10, 11, 12, 13, 100]
        if newchoice.isdigit() and int(newchoice) in tasks:
            return tasks.index(int(newchoice))
        else:
            print('Неправильный ввод!')


def task_3(arr, auto=False):
    print('Задание 3. Вставка элемента в одномерный массив')
    if not auto:
        insertel, insertind = int(vvod('Введите вставляемый элемент')), int(vvod('Введите индекс вставляемого элемента'))
    else:
        insertel, insertind = random.randint(-100, 100), random.randint(0, len(arr))
    arr.insert(insertind, insertel)
    print('Массив с вставленным элементом: ', arr)
    return arr


def task_4(arr):
    print('Задание 4. Определение массива на убывающую монотонность')
    monot = True
    for i in range(len(arr) - 1):
        if not arr[i] > arr[i+1]:
            monot = False
            break
    print(f'Массив {"не " if not monot else ""}монотонен')
    return monot


def task_7(arr):
    print('Задание 7. Нахождение первого положительного элемента')
    fpolval = 'Отсутствует'
    if max(arr) <= 0:
        print('Все элементы массива не положительные')
        return 0
    for i in arr:
        if i > 0:
            fpolval = arr.index(i)
            print(f'Первый положительный элемент {i} имеет индекс {fpolval}')
            break
    return fpolval


def task_8(arr):
    print('Задание 8. Нахождение первого  элемента')
    fstchetind = 'Отсутствует'
    chethave = False
    for i in arr:
        if i % 2 == 0:
            fstchetind = arr.index(i)
            print(f'Первый четный элемент {i} имеет индекс {fstchetind}')
            chethave = True
            break

    if not chethave:
        print('Все элементы массива нечетные')
    return fstchetind


def task_10(arr):
    print('Задание 10. Сортировка бинарными вставками')
    for i in range(1, len(arr)):
        key = arr[i]
        left = 0
        right = i - 1

        while left <= right:
            mid = left + (right - left) // 2
            if arr[mid] > key:
                right = mid - 1
            else:
                left = mid + 1

        for j in range(i - 1, left - 1, -1):
            arr[j + 1] = arr[j]

        arr[left] = key

    print('Отсортированный массив: ', arr)
    return arr


def task_11(arr):
    print('Задание 11. Сортировка простым выбором')
    for i in range(len(arr)):
        minindex = i

        for j in range(i + 1, len(arr)):
            if arr[j] < arr[minindex]:
                minindex = j

        if minindex != i:
            t = arr[i]
            arr[i] = arr[minindex]
            arr[minindex] = t
    print('Отсортированный массив: ', arr)
    return arr


def task_12(arr):
    print('Задание 12. Сортировка простым обменом (Способ 1)')
    for i in range(len(arr)):
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                t = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = t
    print('Отсортированный массив: ', arr)
    return arr


def task_13(arr):
    print('Задание 13. Сортировка простым обменом (Способ 2)')
    for i in range(len(arr) - 1):
        flag = False

        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                t = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = t
                flag = True

        if not flag:
            break

    print('Отсортированный массив: ', arr)
    return arr


def stop(trash):
    return 'exit'


def complite_and_save_all(genarr):
    saves = input('Сохранить в: word: w, excel: e, SQLite: s, text file: t\n'
                  'Пример ввода: wst (сохранение в word, SQLite, text file)\n'
                  'Ваш ввод: ')

    if 'w' in saves or 'e' in saves or 's' in saves or 't' in saves:
        resmsg = 'Сохранение в '
        tasks = {'3': task_3, '4': task_4, '7': task_7, '8': task_8,
                 '10': task_10, '11': task_11, '12': task_12, '13': task_13}

        for name in tasks.keys():
            task = tasks[name]
            if task == task_3:
                answer = task_3(genarr.copy(), True)
            else:
                answer = task(genarr.copy())

            if 'w' in saves:
                if 'word' not in resmsg:
                    resmsg += 'word, '
                if name == list(tasks.keys())[0]:
                    save_to_word(f'DataBase\PyWord3Lab.docx', f'Сгенерированный массив, задача {name}', genarr)
                save_to_word(f'DataBase\PyWord3Lab.docx', f'Ответ, задача {name}', answer)
            if 'e' in saves:
                if 'excel' not in resmsg:
                    resmsg += 'excel, '
                if name == list(tasks.keys())[0]:
                    save_to_excel(f'DataBase\PyExcel3Lab.xlsx', f'Сгенерированный массив, задача {name}', genarr)
                save_to_excel(f'DataBase\PyExcel3Lab.xlsx', f'Ответ, задача {name}', answer)
            if 's' in saves:
                if 'SQLite' not in resmsg:
                    resmsg += 'SQLite, '
                if name == list(tasks.keys())[0]:
                    save_to_sqlite(f'DataBase\PySQLite3Lab.db', f'Generated_{name}', genarr)
                save_to_sqlite(f'DataBase\PySQLite3Lab.db', f'Answer_{name}', answer)
            if 't' in saves:
                if 'text file' not in resmsg:
                    resmsg += 'text file, '
                if name == list(tasks.keys())[0]:
                    save_to_file(f'DataBase\PyTextFile3Lab.txt', f'Сгенерированный массив, задача {name}', genarr)
                save_to_file(f'DataBase\PyTextFile3Lab.txt', f'Ответ, задача {name}', answer)
        print(resmsg[:-2])
    else:
        print('Данные не сохранены')


def lab_3_start():
    print('Выполнение лабораторной работы номер 3')
    task = 0
    while task != 'exit':
        choice = choice_task()

        arr = gen_array(10, -100, 100)
        print('Сгенерированный массив: ', arr)

        task = [stop, task_3, task_4, task_7, task_8, task_10, task_11, task_12, task_13, complite_and_save_all][choice](arr)
    print('Завершение выполнения лабораторной работы номер 3\n')
