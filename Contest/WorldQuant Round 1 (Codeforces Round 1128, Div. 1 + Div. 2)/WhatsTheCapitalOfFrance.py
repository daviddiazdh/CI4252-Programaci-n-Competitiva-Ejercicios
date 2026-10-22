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

        M = max(a)

        max_k = -1
        for x in a:
            if x < M:
                diff = x ^ M
                k = diff.bit_length() - 1
                if k > max_k:
                    max_k = k

        if max_k == -1:
            print(M)
        else:
            mask = (1 << (max_k + 1)) - 1
            print(M | mask)

if __name__ == '__main__':
    solve()