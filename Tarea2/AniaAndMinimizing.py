entry = list(map(int, input().split()))

n = entry[0]
k = entry[1]

number = int(input())

index = 0
first = True
iter = 0
number_str = list(str(number))

if(len(number_str) == 1 and k != 0):
    print(0)

elif(k == 0):
    print(number)

else:

    for i in number_str:
        if i == '0':
            index += 1
            continue

        if first:
            min = '1'
            first = False
        else: 
            min = '0'

        if(i != min):
            number_str[index] = min

            if(iter == k - 1):
                break

            iter += 1
        index += 1

    output_number = int("".join(number_str))

    print(output_number)