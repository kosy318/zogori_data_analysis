import sys

inp = input();
tokens = [];
tokens= inp.split(' ');
tokens.insert(0,'0');
N = len(tokens);

dpMax = [[1 for j in range(int(N/2) +1)] for i in range(int(N/2) +1)];
dpMin = [[1 for j in range(int(N/2) +1)] for i in range(int(N/2) +1)];
visited = [[False]*(int(N/2)+1) for i in range(int(N/2)+1)];

def calculator(operand1,operand2,op):
    if (op == "*") :
        return int(operand1) * int(operand2);    
    elif (op == "+") :
        return int(operand1) + int(operand2);
    elif (op == "-") :
        return int(operand1) - int(operand2);    

def makeTable(index1, index2):
    if (index1 == index2): 
        dpMax[index1][index1] = int(tokens[index1 * 2 - 1]);
        dpMin[index1][index1] = int(tokens[index1 * 2 - 1]);
    elif (index2-index1 == 1) :
        dpMax[index1][index2] = calculator(int(tokens[index1 * 2 -1]), int(tokens[index2 * 2 - 1]),tokens[index1 * 2]);
        dpMin[index1][index2] = calculator(int(tokens[index1 * 2 - 1]), int(tokens[index2 * 2 - 1]), tokens[index1 * 2]);
    else :
        gap = index2 - index1;
        big = sys.maxsize * -1;
        absBig = sys.maxsize;
        for i in range(0,gap) :
            if (visited[index1][index1 + i] == False) :
                makeTable(index1, index1 + i);
            if (visited[index1 + i + 1][index2] == False) :
                makeTable(index1 + i + 1, index2);
            big = max(big, calculator(dpMax[index1][index1 + i], dpMax[index1 + i + 1][index2], tokens[(index1 + i) * 2]));
            big = max(big, calculator(dpMin[index1][index1 + i], dpMin[index1 + i + 1][index2], tokens[(index1 + i) * 2]));
            big = max(big, calculator(dpMax[index1][index1 + i], dpMin[index1 + i + 1][index2], tokens[(index1 + i) * 2]));
            big = max(big, calculator(dpMin[index1][index1 + i], dpMax[index1 + i + 1][index2], tokens[(index1 + i) * 2]));
            absBig = min(absBig, calculator(dpMax[index1][index1 + i], dpMax[index1 + i + 1][index2], tokens[(index1 + i) * 2]));   
            absBig = min(absBig, calculator(dpMin[index1][index1 + i], dpMin[index1 + i + 1][index2], tokens[(index1 + i) * 2]));                absBig = min(absBig, calculator(dpMin[index1][index1 + i], dpMin[index1 + i + 1][index2], tokens[(index1 + i) * 2]));
            absBig = min(absBig, calculator(dpMax[index1][index1 + i], dpMin[index1 + i + 1][index2], tokens[(index1 + i) * 2]));
            absBig = min(absBig, calculator(dpMin[index1][index1 + i], dpMax[index1 + i + 1][index2], tokens[(index1 + i) * 2]));   
        dpMax[index1][index2] = big;
        dpMin[index1][index2] = absBig;
    visited[index1][index2] = True;

makeTable(1,int(N/2));   
print(dpMax[1][int(N/2)]);
