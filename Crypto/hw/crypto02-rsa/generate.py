#!/usr/bin/env python3
import random
from Crypto.Util.number import *
from gmpy2 import next_prime

def pad(data, block_size):
    padlen = block_size - len(data) - 2
    if padlen < 8:
        raise ValueError
    return b'\x00' + bytes([random.randint(1, 255) for _ in range(padlen)]) + b'\x00' + data
    # padding為隨機

FLAG = open('./flag', 'rb').read()

p = getPrime(512)
q1 = next_prime(2 * p) # find next prime > 2p
q2 = next_prime(3 * q1) # find next prime > 3q1

# q1 = 2p + x
# q2 = 3q1 + y = 6p + 3x + y
# p * q1 * q2 = p(2p+x)(6p+3x+y) = 12p^3 + (12x+2y)p^2 + (3x^2+xy)p

n = p * q1 * q2
e = 65537

m = bytes_to_long(pad(FLAG, 192)) # 明文補到192
print(m)
c = pow(m, e, n)
print(f'n = {n}')
print(f'c = {c}')
