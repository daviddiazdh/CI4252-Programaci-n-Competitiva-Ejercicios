import sys

def Verity():
    input_line = sys.stdin.readline

    first_line = input_line()
    if not first_line:
        return

    t = int(first_line.strip())

    for _ in range(t):
        line = input_line().strip()
        if not line:
            continue
            
        parts = line.split()
        n = int(parts[0])
        m = int(parts[1]) # Siempre 0

        for _ in range(m):
            input_line()

        # No se requieren detectores
        if n == 1:
            print(0)
        else:
            k = (n + 1) // 2
            print(k)

            for j in range(1, k + 1):
                u_j = j
                v_j = j + k - 1
                print(f"{u_j} {v_j}")

if __name__ == '__main__':
    Verity()