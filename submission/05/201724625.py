import math

grad = 0.00001

def read_data():
    ret = [list(map(int, input().split())) for _ in range(4)]
    return ret

def process(data):
    compare_line = [data[0], data[1]]
    present_point = data[2]
    
    while(True):
        resultA, next_point = search(present_point, compare_line)
        present_point = next_point
        compare_line = [data[2], data[3]]
        resultB, next_point = search(present_point, compare_line)
        present_point = next_point
        compare_line = [data[0], data[1]]
        if(-grad <= resultA - resultB <= grad):
            break
    
    if(resultA < grad):
        return 0
    else:
        return math.ceil(resultA)

def search(present_point, compare_line):
    left = compare_line[0]
    right = compare_line[1]
    
    while(True):
        mid_right = get_divide_point(left, right, 1+grad, 1)
        mid_left = get_divide_point(left, right, 1-grad, 1)
        
        if(get_distance(mid_right, present_point) < get_distance(mid_left , present_point)):
            right = get_divide_point(left, right, 1, 1)
        else:
            left = get_divide_point(left, right, 1, 1)
        compare_line = [left, right]
        
        if(get_distance(compare_line[0], compare_line[1]) <= grad):
            return get_distance(present_point, compare_line[0]), compare_line[0]

def get_distance(point1, point2):
    distance = math.sqrt((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2 + (point1[2] - point2[2])**2)
    return distance

def get_divide_point(point1, point2, divide1, divide2):
    divide_point = [(point1[i]*divide1 + point2[i]*divide2)/(divide1 + divide2) for i in range(3)]
    return divide_point

def main():
    inp_data = read_data()
    answer = process(inp_data)
    print(answer)

if __name__== "__main__":
    main()
