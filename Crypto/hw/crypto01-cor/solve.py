#!/usr/bin/env python3
from functools import reduce
from itertools import product
from string import printable

class LFSR:
    def __init__(self, init, feedback):
        self.state = init
        self.feedback = feedback
    def getbit(self):
        nextbit = reduce(lambda x, y: x ^ y, [i & j for i, j in zip(self.state, self.feedback)])
        self.state = self.state[1:] + [nextbit]
        return nextbit

class MYLFSR:
    def __init__(self, inits):
        inits = [[int(i) for i in f"{int.from_bytes(init, 'big'):016b}"] for init in inits]
        self.l1 = LFSR(inits[0], [int(i) for i in f'{39989:016b}'])
        self.l2 = LFSR(inits[1], [int(i) for i in f'{40111:016b}'])
        self.l3 = LFSR(inits[2], [int(i) for i in f'{52453:016b}'])
    def getbit(self):
        x1 = self.l2.getbit()
        x2 = self.l2.getbit()
        x3 = self.l3.getbit()
        return (x1 & x2) ^ ((not x1) & x3)  
    def getbyte(self):
        b = 0
        for i in range(8):
            b = (b << 1) + self.getbit()
        return bytes([b])

def xor(a, b):
    return bytes([i ^ j for i, j in zip(a, b)])

output = [1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1]

# cal similarity between xi & output
cnt1 = 0
cnt2 = 0
cnt3 = 0
for x1, x2, x3 in list(product([0,1], repeat=3)):
    out = (x1 & x2) ^ ((not x1) & x3)
    if (x1 == out):
        cnt1 += 1
    if (x2 == out):
        cnt2 += 1
    if (x3 == out):
        cnt3 += 1
print(f'x1:{cnt1/8}')
print(f'x2:{cnt2/8}')		
print(f'x3:{cnt3/8}')

# cal similarity between 2 lists
def correlation(a,b):
    cnt = 0
    for i, j in zip(a,b):
        if (i == j):
            cnt += 1
    return cnt

#brute force R3 (by cmp x3 with output)
for R3 in list(product([0,1], repeat=16)):
    R3 = [R3[i] for i in range(16)]
    lfsr = MYLFSR([[0]*16, [0]*16, R3])
    x3 = []
    for i in range(100):
        x3.append(lfsr.l3.getbit())
    if (correlation(x3, output) >= 70):
        print(f'R3 : {R3}')
        R3_ = chr(int('0b' + ''.join([str(i) for i in R3[:8]]), 2)) + chr(int('0b' + ''.join([str(i) for i in R3[8:]]), 2))
        print(f'R3_ : {R3_}')
        
#brute force R2
for R2 in list(product([0,1], repeat=16)):
    R2 = [R2[i] for i in range(16)]
    if (R2[0] or R2[8]):
        continue
    lfsr = MYLFSR([[0]*16, R2 , [0]*16])
    x2 = []
    for i in range(100):
        x2.append(lfsr.l2.getbit())
    if (correlation(x2, output) >= 70):
        #print(f'x2 : {x2}')
        print(f'R2 : {R2}')
        R2_ = chr(int('0b' + ''.join([str(i) for i in R2[:8]]), 2)) + chr(int('0b' + ''.join([str(i) for i in R2[8:]]),2))
        print(f'R2_ : {R2_}')

#R2 = [0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1] # Vi
#R2 = [0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1] # ui
#R3 = [0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0] # hj

for i in printable:
    for j in printable:
        FLAG = bytes(i.encode()) + bytes(j.encode())
        lfsr = MYLFSR([FLAG, b'ui', b'hj'])
        x1 = [lfsr.l1.getbit() for _ in range(100)]
        x2 = [lfsr.l2.getbit() for _ in range(100)]
        x3 = [lfsr.l3.getbit() for _ in range(100)]
        out = [((x1[i] & x2[i]) ^ ((not x1[i]) & x3[i])) for i in range(100)]
        if correlation(out, output) == 100:
            print(FLAG + b'ui' + b'hj')
