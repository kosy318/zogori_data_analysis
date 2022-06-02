import numpy as np
import math

def solution():
    a = np.array(list(map(int, input().split())))
    b = np.array(list(map(int, input().split())))
    c = np.array(list(map(int, input().split())))
    d = np.array(list(map(int, input().split())))

    vectorA = b - a
    vectorB = d - c
    normA = np.linalg.norm(vectorA)
    normB = np.linalg.norm(vectorB)
    norm_vecA = vectorA / normA
    norm_vecB = vectorB / normB
    productAB = np.cross(norm_vecA, norm_vecB)
    denominator = np.linalg.norm(productAB) ** 2

    #exception handling

    if not denominator:
        cosineA = np.dot(norm_vecA, c-a)
        cosineB = np.dot(norm_vecA, d-a)

        if cosineA<= 0 and 0>=cosineB and np.absolute(cosineB) > np.absolute(cosineA):
            return np.linalg.norm(a - c)
        elif cosineA<= 0 and 0>=cosineB:
            return np.linalg.norm(a - d)
        elif normA<=cosineB and cosineA>=normA and np.absolute(cosineB)>np.absolute(cosineA):
            return np.linalg.norm(b - c)
        elif normA<=cosineB and cosineA>=normA:
            return np.linalg.norm(b - d)
        else:
            return np.linalg.norm(cosineA * norm_vecA + a - c)

    #projection point
    endA_to_endB = c - a
    determinA = np.linalg.det([endA_to_endB, norm_vecB, productAB])
    determinB = np.linalg.det([endA_to_endB, norm_vecA, productAB])
    det_denomA = determinA / denominator
    det_denomB = determinB / denominator
    projecA = a + norm_vecA * det_denomA
    projecB = c + norm_vecB * det_denomB

    #projection check
    if 0>det_denomA:
        projecA=a
    elif det_denomA>normA:
        projecA=b
    else:
        pass

    if 0>det_denomB:
        projecB=c
    elif normB<det_denomB:
        projecB=d
    else:
        pass

    if det_denomA>normA or det_denomA<0:
        dotAB=np.dot(norm_vecB, projecA-c)
        if 0>dotAB:
            dotAB = 0
        elif normB<dotAB:
            dotAB = normB
        else:
            pass
        projecB=c+norm_vecB * dotAB

    if det_denomB>normB or det_denomB<0:
        dotAB=np.dot(norm_vecA, projecB-a)
        if 0>dotAB:
            dotAB=0
        elif normA< dotAB and dotAB > normA:
            dotAB=normA
        else:
            pass
        projecA=a+norm_vecA*dotAB

    return np.linalg.norm(projecA-projecB)

answer=solution()
if answer<1:
    answer = round(answer)
else:
    answer = math.ceil(answer)
print(answer)