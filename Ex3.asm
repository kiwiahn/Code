global _start

section .data
    msg db  "ngu si", 0xa
    len equ $ -msg
    newline db 0xa, 0xd
    lennewline  equ $ -newline

section .bss
    root    resb    10000
    string  resb    10000
    index   resb    20
section .text

_start:

input:
    MOV edx,    10000
    MOV ecx,    root
    MOV eax,    3
    MOV ebx,    0
    int 80h

    MOV edx,    10000
    MOV ecx,    string
    MOV eax,    3
    MOV ebx,    0
    int 80h

find_index:
    MOV esi,    root
    MOV edi,    0
    MOV eax,    esi
    jmp loop_1
loop_0:
    inc         esi
    inc         edi
    cmp byte[esi], 0xa
    je  exit
    MOV eax,    esi
loop_1:
    xor edx,    edx
    MOV edx,    string
next_digit:
    MOV bl,     byte[eax]
    cmp byte[edx],  bl
    je          next_digit_string
    inc         eax
    cmp byte[eax],  0xa
    je          exit
    jmp         loop_0

done:
itoa:
    MOV eax,    edi
    ; ADD eax,    48
    ; MOV [index], eax
    lea ecx,    [index]
    ADD ecx,    10
    MOV byte[ecx], 0
    MOV ebx,    10

.next_digit:
    xor edx,    edx
    div         ebx
    ADD dl,     48
    dec         ecx
    MOV byte[ecx],  dl
    test eax,   eax
    jnz         .next_digit
    MOV eax,    ecx

print:
    MOV ecx,    eax
    MOV edx,    10
    MOV eax,    4
    MOV ebx,    1
    int 80h

    MOV ecx,    newline
    MOV edx,    lennewline
    MOV eax,    4
    MOV ebx,    1
    int 80h

    jmp loop_0


next_digit_string:
    inc     eax
    inc     edx
    cmp byte[edx],  0xa
    je      done
    jmp     next_digit

exit:
    xor ebx,    ebx
    MOV eax,    1
    int 80h

; MOV edx, len
; MOV ecx, msg
; MOV eax, 4
; MOV ebx, 1
; int 80h
