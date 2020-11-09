from pwn import *
from Crypto.Util.number import * # for long_to_bytes()

#r = process("./server.py")
r = remote('140.112.31.97', 30001)

n = int(r.recvline()[4:])
c = int(r.recvline()[4:])
e = 65537

def oracle(x): # return 3^k*m % 3
    r.sendline(str(x))
    remainder = int(r.recvline()[8:])
    return remainder

L = 0 # lower bound
H = 1 # higher bound
i = 0 # 第幾round

while (n * H // (3**i)) - (n * L // (3**i)) >= 2:
    i += 1
    s = c * pow(3, i*e, n) % n # 算(3^ie)c

    m = oracle(s) #傳給server,m為回傳值,i.e.(3^i)*m % 3
    L *= 3
    H *= 3

    if m == 0:
        H -= 2
    elif m == (-n % 3):
        L += 1
        H -= 1
    else:               # -2n % 3
        L += 2

print(long_to_bytes(n * L // (3**i)))
print(long_to_bytes(n * H // (3**i)))

r.interactive()