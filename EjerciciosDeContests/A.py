array = ["B", "Y", "R"]

map = {"B": 0, "Y": 1, "R": 2}
reversedmap = ["B", "Y", "R"]

char = input()
print(reversedmap[(map[char] + 1) % 3])
