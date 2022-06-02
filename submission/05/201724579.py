precision = 7

import math
from itertools import combinations

A = list(map(lambda x: int(x), input().split()))
B = list(map(lambda x: int(x), input().split()))
C = list(map(lambda x: int(x), input().split()))
D = list(map(lambda x: int(x), input().split()))

# reference: https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/ 
def onSegment(p, q, r):
  if ((q[0] <= max(p[0], r[0])) and (q[0] >= min(p[0], r[0])) and
      (q[1] <= max(p[1], r[1])) and (q[1] >= min(p[1], r[1]))):
    return True
  return False


def orientation(p, q, r):
  val = (float(q[1] - p[1]) * (r[0] - q[0])) - (float(q[0] - p[0]) * (r[1] - q[1]))
  if (val > 0): return 1
  elif (val < 0): return 2
  else: return 0

def doIntersect(p1,q1,p2,q2):
     
    o1 = orientation(p1, q1, p2)    
    o2 = orientation(p1, q1, q2)
    o3 = orientation(p2, q2, p1)
    o4 = orientation(p2, q2, q1)

    if ((o1 != o2) and (o3 != o4)): return True
    if ((o1 == 0) and onSegment(p1, p2, q1)): return True 
    if ((o2 == 0) and onSegment(p1, q2, q1)): return True
    if ((o3 == 0) and onSegment(p2, p1, q2)): return True
    if ((o4 == 0) and onSegment(p2, q1, q2)): return True
    return False  

def main():
  is_intersect = True
  for i in range(3):
    x = i % 3
    y = (i + 1) % 3
    if not doIntersect([A[x], A[y]],[B[x], B[y]],[C[x], C[y]],[D[x], D[y]]):
      is_intersect = False
      break
  if is_intersect:
    print(0)
    return

  middle = [0, 0, 0]

  minPoint = C.copy()

  dist1 = 0
  dist2 = 0
  dist3 = 0
  dist4 = 0
  prevDist1 = 0
  prevDist2 = 1
  
  while True:
    newPoint1 = A.copy()
    newPoint2 = B.copy()
    newPoint3 = C.copy()
    newPoint4 = D.copy()
    # find minimize point A,B line
    while True:
      dist1 = 0
      dist2 = 0
      for i in range(3):
        dist1 += (newPoint1[i] - minPoint[i]) ** 2
        dist2 += (newPoint2[i] - minPoint[i]) ** 2
        middle[i] = (newPoint1[i] + newPoint2[i]) / 2
      dist1 = round(dist1, precision)
      dist2 = round(dist2, precision)
      if dist1 == dist2:
        minPoint = middle.copy()
        break
      elif dist1 < dist2:
        newPoint2 = middle.copy()
      else:
        newPoint1 = middle.copy()

    # find minimize point C,D line
    while True:
      dist3 = 0
      dist4 = 0
      for i in range(3):
        dist3 += (newPoint3[i] - minPoint[i]) ** 2
        dist4 += (newPoint4[i] - minPoint[i]) ** 2
        middle[i] = (newPoint3[i] + newPoint4[i]) / 2
      dist3 = round(dist3, precision)
      dist4 = round(dist4, precision)
      if dist3 == dist4 and (dist3 + dist4 <= dist1 + dist2):
        minPoint = middle.copy()
        break
      elif dist3 < dist4:
        newPoint4 = middle.copy()
      else:
        newPoint3 = middle.copy()
    if prevDist1 == dist3 and prevDist2 == dist4:
      break
    prevDist1 = dist3
    prevDist2 = dist4
  dist3 = round(math.sqrt(dist3), precision - 1)
  print(str(math.ceil(dist3)))

main()