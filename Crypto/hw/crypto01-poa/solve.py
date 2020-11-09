from pwn import *

r = process('./server.py')

r.recvuntil('cipher = ')
cipher = r.recvline().decode() # ...\n -> ...
cipher = bytes.fromhex(cipher)  # hex str to byte



def oracle(cipher):
    r.sendlineafter('cipher = ', cipher.hex())
    if b'YESSSSSSSS' in r.recvline():
        return True
    else:
        return False


b_num = len(cipher)//16 - 1
print(f'block數 : {b_num}')

# padding可能為
# 0x80
# 0x80 0x00 
# 0x80 0x00 ....

# find padding
ans = b''
iv = cipher[-32:-16]
block = cipher[-16:]
for b in range(16):
    for c in range(256):
        if b == 0 and c == iv[-1]:
            continue
        my_c = iv[:15-b] + bytes([c]) + xor(bytes([0] * b), xor(iv[-b:], ans)) + block
        print(my_c.hex())
        if (oracle(my_c)):
            if c==0:
                break
            else:
                ans = bytes([0]) + ans
                break

padding = b'\x80' + ans[:-1]

'''
#find the other byte in the last block
for b in range(len(padding),16):
    for c in range(256):
        if b == 0 and c == iv[-1]:
            continue
        my_c = iv[:15-b] + bytes([c]) + xor(bytes([0] * b), xor(iv[-b:], padding)) + block
        if (oracle(my_c)):
            padding = bytes([iv[15 - b] ^ c ^ (b + 1)]) + padding
            break

print(f'2nd: {padding.hex()}')

# find the other bytes in other blocks
flag = b''
for i in range(16, len(cipher)-16, 16):
    iv, block = cipher[i-16:i], cipher[i:i+16]
    for b in range(16):
        for c in range(256):
            if b == 0 and c == iv[-1]:
                continue
            my_c = iv[:15-b] + bytes([c]) + xor(bytes([0] * b), xor(iv[-b:], padding)) + block
            print(f'{i}, {b}, {c}, {my_c.hex()}')
            print(padding.hex())
            print(len(cipher))
            if (oracle(my_c)):
                padding = bytes([iv[16 - 1 - b] ^ c ^ (b + 1)]) + padding
                break
    flag += padding
print(flag)
'''

r.interactive()



