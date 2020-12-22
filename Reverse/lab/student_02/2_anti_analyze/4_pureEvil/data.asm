global    _start

section .text

_start:
push 0 
jmp Message
messageBuf db "Hello",0 
Message:
mov rax, 1
mov rdi, 1
mov rsi, messageBuf
mov rdx, 6
syscall
mov rax, 0x3c 
syscall
