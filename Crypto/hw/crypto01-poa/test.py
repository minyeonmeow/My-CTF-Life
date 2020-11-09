#!/usr/bin/env python3
from pwn import *

def xor(a, b):
    return bytes([x ^ y for x, y in zip(a, b)])

#r = remote("127.0.0.1", 20000)
r = process("./server.py")

enc = bytes.fromhex(r.recvline().strip().partition(b' = ')[2].decode())
print(enc)
def oracle(c):
    r.sendlineafter('cipher = ', c.hex())
    if b'YESSSSSSSS' in r.recvline():
        return True
    else:
        return False

flag = b''
for i in range(16, len(enc), 16):
    ans = b''
    iv, block = enc[i-16:i], enc[i:i+16]
    print('===============================================')
    print(f'iv : {iv}')
    print(f'cipher : {block}')
    for j in range(16):
        for k in range(256):
            # if you change nothing, padding will be correct, but not the case we want
            if j == 0 and k == iv[15]:
                continue
            my_c = iv[:16 - 1 - j] + bytes([k]) + xor(bytes([j + 1] * j), xor(iv[-j:], ans)) + block
            if oracle(my_c):
                print('===============================================')
                print(f'[+] No.{j} byte')
                print(f'[+] k is {k}')
                tmp = bytes([iv[16 - 1 - j] ^ k ^ (j + 1)])
                #print(f'[+] plain : {tmp}')
                print('===============================================')
                if (tmp != b'\x00'):
                    break
                else:
                    print(f'Got it! {tmp}')
                

'''
                ans = bytes([iv[16 - 1 - j] ^ k ^ (j + 1)]) + ans
                print(f'ans = {ans}')
                print(f'k = {k}')
                break
    flag += ans

print(flag)
'''

