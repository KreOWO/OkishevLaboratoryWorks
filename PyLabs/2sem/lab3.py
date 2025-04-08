import pandas as pd
import csv


def calculate_pandas(csv_file):
    df = pd.read_csv(csv_file)
    avg_male_height = df["Male Height in Cm"].mean()
    avg_female_height = df["Female Height in Cm"].mean()
    return avg_male_height, avg_female_height


def filter_countries_pandas(csv_filename):
    df = pd.read_csv(csv_filename)
    df["Male Height in Cm"] = pd.to_numeric(df["Male Height in Cm"], errors="coerce")
    filtered_df = df[(df["Male Height in Cm"] >= 175) & (df["Male Height in Cm"] <= 179)]
    return filtered_df[["Rank", "Country Name", "Male Height in Cm"]]


def find_shortest_countries(csv_filename):
    with open(csv_filename, newline='', encoding='utf-8') as csvfile:
        reader = csv.DictReader(csvfile)
        data = list(reader)

    shortest_male = min(data, key=lambda x: float(x["Male Height in Cm"]))
    shortest_female = min(data, key=lambda x: float(x["Female Height in Cm"]))
    return shortest_male["Country Name"], shortest_female["Country Name"]


def find_shortest_pandas(csv_filename):
    df = pd.read_csv(csv_filename)
    shortest_male = df.nsmallest(1, "Male Height in Cm")[["Country Name", "Male Height in Cm"]].iloc[0]
    shortest_female = df.nsmallest(1, "Female Height in Cm")[["Country Name", "Female Height in Cm"]].iloc[0]
    return shortest_male["Country Name"], shortest_female["Country Name"]


# Допзадачи
# С использованием pandas
def task2p(csv_file):
    # Задача 2: 5 стран с мужчинами выше 180 см
    df = pd.read_csv(csv_file)
    filtered = df[df["Male Height in Cm"] > 180]
    return filtered.nlargest(5, "Male Height in Cm")[["Country Name", "Male Height in Cm"]]


def task4p(csv_file):
    # Задача 4: Топ-5 стран с самыми низкими женщинами
    df = pd.read_csv(csv_file)
    return df.nsmallest(5, "Female Height in Cm")[["Country Name", "Female Height in Cm"]]


def task5p(csv_file, country):
    # Задача 5: Разница между самым высоким мужчиной и женщиной в стране
    df = pd.read_csv(csv_file)

    try:
        row = df[df["Country Name"].str.lower() == country.lower()].iloc[0]
        diff = row["Male Height in Cm"] - row["Female Height in Cm"]
        return f"Разница: {abs(diff):.1f} см"
    except:
        return "Страна не найдена"


def task7p(csv_file):
    # Задача 7: Сортировка стран по убыванию мужского роста
    df = pd.read_csv(csv_file)
    return df.sort_values("Male Height in Cm", ascending=False)[["Country Name", "Male Height in Cm"]]


def task8p(csv_file):
    # Задача 8: Сортировка стран по возрастанию женского роста
    df = pd.read_csv(csv_file)
    return df.sort_values("Female Height in Cm")[["Country Name", "Female Height in Cm"]]


# Без использования pandas
# Чтение CSV файла и преобразование данных
def read_csv_data(csv_filename):
    with open(csv_filename, 'r', encoding='utf-8') as file:
        reader = csv.DictReader(file)
        data = []
        for row in reader:
            processed_row = dict(row)
            processed_row['Male Height in Cm'] = float(processed_row['Male Height in Cm'])
            processed_row['Female Height in Cm'] = float(processed_row['Female Height in Cm'])
            data.append(processed_row)
        return data


def task2(csv_file):
    # Задача 2: 5 стран с мужчинами выше 180 см
    data = read_csv_data(csv_file)
    filtered = [row for row in data if row['Male Height in Cm'] > 180]
    sorted_data = sorted(filtered, key=lambda x: x['Male Height in Cm'], reverse=True)
    return [(row['Country Name'], row['Male Height in Cm']) for row in sorted_data[:5]]


def task4(csv_file):
    # Задача 4: Топ-5 стран с самыми низкими женщинами
    data = read_csv_data(csv_file)
    sorted_data = sorted(data, key=lambda x: x['Female Height in Cm'])
    return [(row['Country Name'], row['Female Height in Cm']) for row in sorted_data[:5]]


def task5(csv_file, country):
    # Задача 5: Разница в росте в указанной стране
    data = read_csv_data(csv_file)

    for row in data:
        if row['Country Name'] == country:
            diff = row['Male Height in Cm'] - row['Female Height in Cm']
            return f"Разница: {abs(diff):.1f} см"
    return "Страна не найдена"


def task7(csv_file):
    # Задача 7: Сортировка по убыванию мужского роста
    data = read_csv_data(csv_file)
    return sorted(data, key=lambda x: x['Male Height in Cm'], reverse=True)


def task8(csv_file):
    # Задача 8: Сортировка по возрастанию женского роста
    data = read_csv_data(csv_file)
    return sorted(data, key=lambda x: x['Female Height in Cm'])


def lab_3_start():
    print('Выполнение лабораторной работы номер 3')
    csv_file = "otherfiles/Height of Male and Female by Country 2022.csv"

    # Расчет среднего роста
    male_avg, female_avg = calculate_pandas(csv_file)
    print(f"Средний рост мужчин: {male_avg:.2f} см")
    print(f"Средний рост женщин: {female_avg:.2f} см\n")

    # Фильтрация стран
    filtered = filter_countries_pandas(csv_file)
    print("Страны с ростом мужчин 175-179 см:")
    print(filtered.to_string(index=False), end="\n\n")

    # Поиск самых низких (csv)
    male_country, female_country = find_shortest_countries(csv_file)
    print(f"Самая низкорослая страна (муж): {male_country}")
    print(f"Самая низкорослая страна (жен): {female_country}\n")

    # Поиск самых низких (pandas)
    male_pd, female_pd = find_shortest_pandas(csv_file)
    print(f"Самая низкорослая страна (pandas, муж): {male_pd}")
    print(f"Самая низкорослая страна (pandas, жен): {female_pd}")

    # Выполнение Допзадач
    # С использованием pandas
    print("\nТоп-5 стран с мужчинами выше 180 см:")
    print(task2p(csv_file).to_string(index=False))

    print("\nТоп-5 стран с самыми низкими женщинами:")
    print(task4p(csv_file).to_string(index=False))

    print("\nПоиск разницы в стране:")
    country = input("Введите название страны: ").strip()
    print(task5p(csv_file, country))

    print("\nВсе страны по убыванию мужского роста:")
    print(task7p(csv_file).to_string(index=False))

    print("\nВсе страны по возрастанию женского роста:")
    print(task8p(csv_file).to_string(index=False))

    # Без pandas
    print("\nТоп-5 стран с мужчинами выше 180 см:")
    for name, height in task2(csv_file):
        print(f"{name}: {height} см")

    print("\nТоп-5 стран с самыми низкими женщинами:")
    for name, height in task4(csv_file):
        print(f"{name}: {height} см")

    print("\nПоиск разницы в стране:")
    print(task5(csv_file, country))

    print("\nВсе страны по убыванию мужского роста:")
    for row in task7(csv_file):
        print(f"{row['Country Name']:^32} {row['Male Height in Cm']:.2f} см")

    print("\nВсе страны по возрастанию женского роста:")
    for row in task8(csv_file):
        print(f"{row['Country Name']:^32} | {row['Female Height in Cm']:.2f} см")