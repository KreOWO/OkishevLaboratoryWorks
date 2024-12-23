def get_data():
    comps_len = int(input('Введите количество компаний: '))
    data = {}
    for i in range(comps_len):
        name = input(f'Введите название компании {i + 1}/{comps_len}: ')
        date = int(input(f'Введите год основания компании {name}: '))
        country = input(f'Введите страну основании компании компании {name}: ')
        data[name] = {'date': date, 'country': country}
    return data


def earlier1995(data: dict):
    counter = 0
    for name, info in data.items():
        if info['date'] < 1995:
            counter += 1

    return counter


def americancomps(data: dict):
    american = {}
    for name, info in data.items():
        if info['country'] == 'Америка':
            american[name] = info

    return american


def middlecreationdate(data: dict):
    sumalldates = 0
    for name, info in data.items():
        sumalldates += info['date']

    return sumalldates / len(data)


def lab_5_start():
    data = get_data()
    earl = earlier1995(data)
    american = americancomps(data)
    midcreatedate = middlecreationdate(american)
    print(f'Компаний, основанных ранее 1995 года: {earl}')
    print(f'Компаний, основанных в Америке: {len(american)}')
    print(f'Cредний год основания компаний, основанных в Америке: {midcreatedate}')