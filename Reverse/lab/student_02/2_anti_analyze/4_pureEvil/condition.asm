global    _start

section .text

_start:

mov esi, messageBuf 
mov al, "H"
cmp BYTE [esi], al
jz always 
db 0E8h

always:
jmp Message
mov rax, 1
mov rdi, 1
mov rsi, messageNOBuf
mov rdx, 6
syscall
mov rax, 0x3c 
syscall


Message:
mov rax, 1
mov rdi, 1
mov rsi, messageBuf
mov rdx, 6
syscall
mov rax, 0x3c 
syscall


section .data 
messageBuf  db "Hello",0 
messageNOBuf  db "Bello",0 
