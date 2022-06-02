def cal_append(a: int, b: int):
    return a + b


def cal_subtract(a: int, b: int):
    return a - b


def cal_multiply(a: int, b: int):
    return a * b


def calculate_1(a: int, b: int, op: str):
    functions = {'+': cal_append(a, b),
                 '-': cal_subtract(a, b),
                 '*': cal_multiply(a, b)}
    return functions[op]


nums_and_ops = input().split()
nums = []
ops = []

count = 0
for obj in nums_and_ops:
    if count % 2 == 0:
        nums.append(int(obj))
    else:
        ops.append(obj)
    count += 1

maxTable = [[0 for i in range(len(nums))] for j in range(len(nums))]
minTable = [[0 for i in range(len(nums))] for j in range(len(nums))]


def calculate_2(left: int, right: int, mid: int, find_max: bool):
    if ops[mid] == '+':
        if find_max:
            return maxTable[left][mid] + maxTable[mid + 1][right]
        else:
            return minTable[left][mid] + minTable[mid + 1][right]
    elif ops[mid] == '-':
        if find_max:
            return maxTable[left][mid] - minTable[mid + 1][right]
        else:
            return minTable[left][mid] - maxTable[mid + 1][right]
    else:
        if find_max:
            return max(max
                       (maxTable[left][mid] * maxTable[mid + 1][right],
                        maxTable[left][mid] * minTable[mid + 1][right]), max
                       (minTable[left][mid] * maxTable[mid + 1][right],
                        minTable[left][mid] * minTable[mid + 1][right]))
        else:
            return min(min
                       (maxTable[left][mid] * maxTable[mid + 1][right],
                        maxTable[left][mid] * minTable[mid + 1][right]), min
                       (minTable[left][mid] * maxTable[mid + 1][right],
                        minTable[left][mid] * minTable[mid + 1][right]))


for i in range(len(nums)):
    maxTable[i][i] = minTable[i][i] = nums[i]
    if i < len(nums) - 1:
        maxTable[i][i + 1] = minTable[i][i + 1] = calculate_1(nums[i],
                                                              nums[i + 1],
                                                              ops[i])

for gap in range(2, len(nums)):
    for i in range(0, len(nums) - gap):
        max_num = -(10 ** 30)
        min_num = 10 ** 30
        for ii in range(i, i + gap):
            max_num = max(max_num, calculate_2(i, i + gap, ii, True))
            min_num = min(min_num, calculate_2(i, i + gap, ii, False))
        maxTable[i][i + gap] = max_num
        minTable[i][i + gap] = min_num

print(maxTable[0][len(nums) - 1])
