#!/usr/bin/env python3
import time
import random
from typing import List as 陣列
from io import BufferedReader as 緩衝讀取者
#from forbiddenfruit import curse as 詛咒

整數 = int
#詛咒(整數, "從位元組", 整數.from_bytes) #byte to int
#詛咒(整數, "到位元組", 整數.to_bytes) #int to byte
位元組 = bytes
#詛咒(位元組, "十六進制", 位元組.hex) #byte to hex
#詛咒(位元組, "加入", 位元組.join) # join
#詛咒(緩衝讀取者, "讀取", 緩衝讀取者.read) #read buffer
random.種子 = random.seed #random.seed()
random.給我隨機位元們 = random.getrandbits #random.getrandbits
time.現在 = time.time 
列印 = print
打開 = open
範圍 = range
長度 = len
大端序 = 'big'
讀取位元組 = 'rb'

def 正轉換(資料, 大小=4):
    return [整數.從位元組(資料[索引:索引+大小], 大端序) for 索引 in 範圍(0, 長度(資料), 大小)]
    # int.from_bytes(input(i:i+4), 'big') for i in range(len(input), 4)

def 逆轉換(資料, 大小=4):
    return b''.加入([元素.到位元組(大小, 大端序) for 元素 in 資料])
    # cipherbyte.to_bytes(4, 'big') for cipherbyte in input

def _加密(向量: 陣列[整數], 金鑰: 陣列[整數]):
    累加, 得優塔, 遮罩 = 0, 0xFACEB00C, 0xffffffff
    for 次數 in 範圍(32):
        累加 = 累加 + 得優塔 & 遮罩
        向量[0] = 向量[0] + ((向量[1] << 4) + 金鑰[0] & 遮罩 ^ (向量[1] + 累加) & 遮罩 ^ (向量[1] >> 5) + 金鑰[1] & 遮罩) & 遮罩
        向量[1] = 向量[1] + ((向量[0] << 4) + 金鑰[2] & 遮罩 ^ (向量[0] + 累加) & 遮罩 ^ (向量[0] >> 5) + 金鑰[3] & 遮罩) & 遮罩
    return 向量

def 加密(明文: 位元組, 密鑰: 位元組):
    密文 = b''
    for 索引 in 範圍(0, 長度(明文), 8):
        密文 += 逆轉換(_加密(正轉換(明文[索引:索引+8]), 正轉換(密鑰)))
    return 密文

if __name__ == '__main__':
    旗幟 = 打開('./flag.txt', 讀取位元組).read()  
    assert 長度(旗幟) == 16
    print(random.seed(整數(time.time())))
    print(int(time.time()))
    密鑰 = random.給我隨機位元們(128).to_bytes(16, 大端序)
    #密文 = 加密(旗幟, 密鑰)
    #列印(f'密文 = {密文.十六進制()}')


    '''
    flag = open('flag', 'rb').read()
    assert len(flag) == 16
    random.seed(int(time.time()))
    key = random.getranbit(128).to_bytes(16, 'big')
    cipher = 加密(flag, key)
    print(cipher.hex()
    '''
