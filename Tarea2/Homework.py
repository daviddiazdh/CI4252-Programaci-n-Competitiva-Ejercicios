from collections import defaultdict

string = input()
k = int(input())

if len(string) <= k:
    print(0)
    print("")

else:

    letters_array = defaultdict(int)
    black_list = defaultdict(int)

    for c in string:
        letters_array[c] += 1

    sorted_letters = sorted(letters_array.items(), key = lambda x : x[1])

    distinct_letters = len(sorted_letters)

    for char, frecuency in sorted_letters:
        if(k < frecuency):
            break
        k -= frecuency
        distinct_letters -= 1
        black_list[char] = frecuency

    print(distinct_letters)

    for c in string:
        if(not(black_list) or black_list[c] == 0):
            print(c, end="")
        else:
            black_list[c] -= 1

    print("")