#!/usr/bin/env python3
import os
from Crypto.Cipher import AES

key = os.urandom(16)
with open('flag', 'rb') as f:
    flag = f.read()

class PaddingError(Exception):
    pass

def pad(data):
    padlen = 16 - len(data) % 16
    return data + int('1' + '0' * (padlen * 8 - 1), 2).to_bytes(padlen, 'big')
    # data + 10...0(bit)

def unpad(data):
    for i in range(len(data) - 1, len(data) - 1 - 16, -1): # 由最後一byte往前找
        if data[i] == 0x80:  # [raw_data] + '10000000(bit)'
            return data[:i]  # ret [raw_data]
        elif data[i] != 0x00: # if no 00 exist >> 代表padding錯誤
            raise PaddingError
    raise PaddingError

def encrypt(plain):
    # random iv
    iv = os.urandom(16)
    # encrypt
    aes = AES.new(key, AES.MODE_CBC, iv) 
    cipher = aes.encrypt(pad(plain))
    return iv + cipher #cipher前16byte為iv

def decrypt(cipher):
    # split iv, cipher
    iv, cipher = cipher[:16], cipher[16:]
    # decrypt
    aes = AES.new(key, AES.MODE_CBC, iv) 
    plain = aes.decrypt(cipher)
    return unpad(plain)

def main():
    print(f'cipher = {encrypt(flag).hex()}')
    #cipher = encrypt(flag).hex()
    #c_len = len(cipher)
    #b_num = c_len//16
    #iv = cipher[:16]
    #print(f'iv: {iv}')
    #print(f'len: {c_len}')
    #for i in range(16, c_len,16):
    #    print(cipher[i:i+16])

    while True:
        try:
            decrypt(bytes.fromhex(input('cipher = ')))
            print('YESSSSSSSS')
        except PaddingError:
            print('NOOOOOOOOO')
        except:
            return

if __name__ == '__main__':
    main()
