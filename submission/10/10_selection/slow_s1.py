# input
N, T, k = map(int, input().split())
works = []

for i in range(N):
    c, d = map(int, input().split())
    works.append([c, d])

# solve: First, Greedy. Second, Find.
works.sort(key=lambda x: (-x[0], x[1]))

limit = [0] + [k]*T
selected_minimum = [1e90]*(T+1)
unselected_works = []
first_maximal = 0

# greedy & classification
for i in range(N):
    is_unselected = True
    cost, day = works[i]
    while is_unselected and day > 0:
        if limit[day] > 0:
            first_maximal += cost
            selected_minimum[day] = min(selected_minimum[day], cost)
            is_unselected = False
            limit[day] -= 1
        day -= 1

    if is_unselected:
        unselected_works.append(works[i])

# find
second_maximal = first_maximal - min(selected_minimum[1:])

for unselected in unselected_works:
    cost, day = unselected
    minimum = min(selected_minimum[1:day+1])
    diff = minimum - cost
    if diff > 0:
        second_maximal = max(second_maximal, first_maximal-diff)

# print
print(first_maximal, second_maximal)
