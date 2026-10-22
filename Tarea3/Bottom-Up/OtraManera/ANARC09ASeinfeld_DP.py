# Misma lógica que en el Bottom-Up entregado, pero con Python
# Spoiler: Obtuvo TLE.

i = 0
while True:
    case = input().strip()
    if "-" in case:
        break
    else:
        n = len(case)
        dp = [0] + [float('inf')] * n
        for row, char in enumerate(case):
            next_dp = [float('inf')] * (n + 1)
            for bal in range(row + 1):
                if dp[bal] == float('inf'):
                    continue
    
                costo_open = 0 if char == '{' else 1
                next_dp[bal + 1] = min(next_dp[bal + 1], dp[bal] + costo_open)
    
                if bal > 0:
                    costo_close = 0 if char == '}' else 1
                    next_dp[bal - 1] = min(next_dp[bal - 1], dp[bal] + costo_close)
    
            dp = next_dp
    
        print(f"{i + 1}. {dp[0]}")
        i += 1