from functs import gen_array


def bininsertionssort(arr):
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
    return arr


def countchets(arr):
    counter = 0
    for i in arr:
        if i % 2 == 0:
            counter += 1

    return counter


def dop_task_start():
    arrlen = int(input('Введите количество элементов массива: '))
    arr = gen_array(arrlen, -100, 100)
    arrless15 = [i for i in arr if i >= 15]
    chetnum = countchets(arrless15)
    newarr = [i for i in arrless15 if i < chetnum]
    newarrsorted = bininsertionssort(newarr.copy())
    print('Исходный массив:', arr)
    print('Массив с элементами >= 15 (arrless15):', arrless15)
    print(f'Количество четных элементов arrless15 (chetnum): {chetnum}')
    print('Массив с элементами из arrless15, которые < chetnum (newarr):', newarr)
    print('Отсортированный бинарными вставками newarr:', newarrsorted)
