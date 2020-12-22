global _start
section .text

_start:
    mov rcx, 6
    mov rsi, source
    mov rdi, target
    cld
    rep movsb

section .data

source: db    'hello',0
target: times 6 db 1
