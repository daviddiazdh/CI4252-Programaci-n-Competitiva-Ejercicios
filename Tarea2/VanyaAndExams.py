entry = list(map(int, input().split()))

n = entry[0]
r = entry[1]
min_avg = entry[2]

greedy_exams = []

grade = 0
sum = 0
for i in range(0,n):
    grade_result = list(map(int, input().split()))

    grade = grade_result[0]
    essays = grade_result[1]

    sum += grade

    greedy_exams.append([grade, essays])

target_sum = n * min_avg

if(sum < target_sum):

    needed_points = target_sum - sum

    greedy_exams_sorted = sorted(greedy_exams, key = lambda x: x[1])

    essays_done = 0
    for grade, essays in greedy_exams_sorted:

        can_add = r - grade
        take = min(can_add, needed_points)
        essays_done += essays * take
        needed_points -= take

        if(needed_points == 0):
            break

    print(essays_done)

else:
    print(0)