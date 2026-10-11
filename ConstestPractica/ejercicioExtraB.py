S = input()
T = input()

n = len(S)

firstChar = S[0]

def check(index):
    i = 1
    while(i != 0):
        if(S[i] != T[(i + index) % n]):
            return False
        i = (i + 1) % n
    return True

index = 0
found = False
for t in T:
    if t == firstChar:
        if check(index):
            print("Yes")
            found = True
            break
    index += 1

if not found:
    print("No")
