n = int(input())

while n > 0:

    k = int(input())
    s = input()

    cant_unos = s.count('1')

    if cant_unos == 1:
        print(0)
    elif cant_unos == 2:
        print(1)
    else:
        min_index = s.find('1')
        max_index = s.rfind('1')
        print(max_index - min_index)

    n -= 1
