class TwoNum:
        
    def __init__(self, s = 0, b = 0):
        self.num = [0 for _ in range(2)]
        self.num[0] = int(s) #small
        self.num[1] = int(b) #big

    def operate(self, obj, op):
        s = 0
        if op == '+':
            s = self.num[0] + obj.num[0]
        elif op == '-':
            s = self.num[0] - obj.num[0]
        elif op == '*':
            s = self.num[0] * obj.num[0]
        b = s
        for i in range(0, 2):
            for j in range(0, 2):
                tmp = 0
                if op == '+':
                    tmp = self.num[i] + obj.num[j]
                elif op == '-':
                    tmp = self.num[i] - obj.num[j]
                elif op == '*':
                    tmp = self.num[i] * obj.num[j]
                if s > tmp:
                    s = tmp
                if b < tmp:
                    b = tmp
        return TwoNum(s, b)


    def copy_from(self, obj):
        self.num[0] = obj.num[0]
        self.num[1] = obj.num[1]

class Formula:
    def __init__(self):
        self._number = []
        self._operation = []
    def putNum(self, num):
        self._number.append(num)
    def putOp(self, op):
        self._operation.append(op)
        
    def getBig(self):
        table = []
        size = len(self._number)

        for i in range(0, size):
            temp = []
            for j in range(0, size):
                if i == j:
                    t = TwoNum(self._number[i], self._number[i])
                    temp.append(t)
                else:
                    t = TwoNum()
                    temp.append(t)
            table.append(temp)

        for i in range(size - 2, -1, -1):
            for j in range(i + 1, size):
                self.calculate(i, j, table)
        return table[0][size - 1].num[1]

    def calculate(self, i, j, table):
        tmp = []
        for l in range(i, j):
            tmp.append(table[i][l].operate(table[l + 1][j], self._operation[l]))

        tmpNum = TwoNum(tmp[0].num[0], tmp[0].num[1])
        l = 1
        while l < len(tmp):
            if tmpNum.num[0] > tmp[l].num[0]:
                tmpNum.num[0] = tmp[l].num[0]
            if tmpNum.num[1] < tmp[l].num[1]:
                tmpNum.num[1] = tmp[l].num[1]
            l += 1
        table[i][j].copy_from(tmpNum)

def main():
    formula = Formula()
    Globals.getFormula(formula)
    print(formula.getBig(), end = '')
    print("\n", end = '')

class Globals:
    @staticmethod
    def getFormula(f):
        formula = input()
        i = 0
        for n in formula.split():
            if i % 2 == 0:
                f.putNum(n)
            else:
                f.putOp(n)
            i += 1
main()