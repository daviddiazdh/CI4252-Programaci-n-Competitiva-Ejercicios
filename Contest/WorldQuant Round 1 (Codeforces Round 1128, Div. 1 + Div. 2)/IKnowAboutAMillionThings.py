import sys

def solve():
    input_line = sys.stdin.readline

    first_line = input_line()
    if not first_line:
        return

    t = int(first_line.strip())

    for _ in range(t):
        n = int(input_line().strip())
        a = list(map(int, input_line().split()))

        odds = 0
        evens = 0

        for x in a:
            if x % 2 != 0:
                odds += 1
            else:
                evens += 1

        if (odds == 1 and evens == 1) or (odds == 3 and evens == 0):
            print("Larpity")
        else:
            print("Moggity")

if __name__ == '__main__':
    solve()