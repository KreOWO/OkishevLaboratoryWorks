from functs import gen_array, save_to_word, save_to_file, save_to_sqlite, save_to_excel


def get_index_maxind(arr):
    maxchet = min(arr) - 1
    maxind = -1
    for i in range(len(arr)):
        if (arr[i] % 2 == 0) and arr[i] > maxchet:
            maxchet = arr[i]
            maxind = i
    return [maxind, maxchet]


def fill_newarr(arr, maxind):
    newarr = []
    for i in range(len(arr)):
        if arr[i] < maxind:
            newarr.append(i)
    return newarr



def lab_2_start():
    print('Выполнение лабораторной работы номер 2')
    arr = gen_array(10, -100, 100)
    print('Сгенерированный массив: ', arr)
    maxind, maxchet = get_index_maxind(arr)
    newarr = []
    if maxind >= 0:
        newarr = fill_newarr(arr, maxind)
        print(f'Индекс максимального четного элемента ({maxchet}): {maxind}\nНовый массив: ', newarr)
    else:
        print('Все числа в массиве нечётные!')

    saves = input('Сохранить в: word: w, excel: e, SQLite: s, text file: t\n'
                  'Пример ввода: wst (сохранение в word, SQLite, text file)\n'
                  'Ваш ввод: ')

    if saves:
        resmsg = 'Сохранение в '
        if 'w' in saves:
            resmsg += 'word, '
            save_to_word(f'DataBase\PyWord2Lab.docx', 'Сгенерированный массив', arr)
            save_to_word(f'DataBase\PyWord2Lab.docx', 'Индекс максимального четного элемента', maxind)
            save_to_word(f'DataBase\PyWord2Lab.docx', 'Новый массив', newarr)
        if 'e' in saves:
            resmsg += 'excel, '
            save_to_excel(f'DataBase\PyExcel2Lab.xlsx', 'Сгенерированный массив', arr)
            save_to_excel(f'DataBase\PyExcel2Lab.xlsx', 'Индекс максимального четного элемента', maxind)
            save_to_excel(f'DataBase\PyExcel2Lab.xlsx', 'Новый массив', newarr)
        if 's' in saves:
            resmsg += 'SQLite, '
            save_to_sqlite(f'DataBase\PySQLite2Lab.db', 'Generated_array', arr)
            save_to_sqlite(f'DataBase\PySQLite2Lab.db', 'Index_of_max_chet_value', maxind)
            save_to_sqlite(f'DataBase\PySQLite2Lab.db', 'Result_array', newarr)
        if 't' in saves:
            resmsg += 'text file, '
            save_to_file(f'DataBase\PyTextFile2Lab.txt', 'Сгенерированный массив', arr)
            save_to_file(f'DataBase\PyTextFile2Lab.txt', 'Индекс максимального четного элемента', maxind)
            save_to_file(f'DataBase\PyTextFile2Lab.txt', 'Новый массив', newarr)
        print(resmsg[:-2])
    else:
        print('Данные не сохранены')

    print('Завершение выполнения лабораторной работы номер 2\n')

