opcode = [] # 연산자
operand =[] # 숫자
table = []

def init():
  tmp = input().split(" ")
  global opcode
  global operand
  global table
  for i in range(len(tmp)):
    if(i % 2 == 0):
      operand.append(tmp[i])
    else:
      opcode.append(tmp[i])

  size = len(operand)
  table = [[[] for j in range(size)] for i in range(size)]
  for i in range(size):
    table[i][i].append(operand[i])

def makeTable():
  global opcode
  global operand
  global table

  size = len(operand)

  for i in range(1, size):
    for j in range(size-i):
      li = []
      for k in range(i):
        for op1 in table[j][i+j-k-1]:
          for op2 in table[j+i-k][i+j]:
            tmp = eval(str(op1) + opcode[i+j-k-1] + str(op2))
            li.append(tmp)
      tmpMin = min(li)
      tmpMax = max(li)
      table[j][i+j].append(tmpMin)
      table[j][i+j].append(tmpMax)
  return max(table[0][size-1])

def main():
  init()
  maxValue = makeTable()
  print(maxValue)

main()