global _start

section .data
    max  EQU 1000000
    min  EQU 10
    new  db 0xa, 0xd
    len  equ  $ -new

section .bss
    arr resd   max
    string resb max
    index   resb    10

section .text

_start:

input:
    MOV ecx,    string
    MOV edx,    max
    MOV eax,    3
    MOV ebx,    0
    int 80h

find_num:
    MOV esi,    string
    MOV edi,    0

loop_1:
    MOV ebx,    0

next_char:
    cmp byte[esi], 0xa
    je           insection_sort
    MOVZX   eax,    byte[esi]
    SUB al,     48
    inc         esi
    imul ebx,   10
    ADD ebx,    eax
    cmp byte[esi],  ' '
    je          save_to_array
    jmp         next_char

save_to_array:
    MOV dword[arr + edi * 4],  ebx
    inc         edi
    inc         esi
    jmp         loop_1

insection_sort:
    MOV dword[arr + edi * 4], ebx
    inc         edi
    MOV dword[arr + edi * 4], 0
    MOV edi,    0

loop1:
    MOV esi,    edi
    jz          print
    inc         esi
    cmp dword[arr + esi * 4], 0
    jz          print
    MOV eax,    dword[arr + edi * 4]

loop2:
    MOV ebx,    dword[arr + esi * 4]
    cmp eax,    ebx
    jg          swap_func
    inc         esi
    cmp dword[arr + esi * 4], 0
    jnz         loop2
    inc         edi
    jmp         loop1

print:
    MOV edi,    0

print_loop:
    xor eax,    eax
    MOV eax,    dword[arr + edi * 4]
    lea esi,    [index]
    ADD esi,    10
    MOV byte[esi], 0
    MOV ebx,    10

itoa:
    xor edx,    edx
    div         ebx
    ADD dl,     48
    dec         esi
    MOV byte[esi],  dl
    test eax,   eax
    jne         itoa
    MOV eax,    esi
    ; ADD eax,    48
    ; MOV dword[index], eax
output:
    MOV ecx,    eax
    MOV edx,    10
    MOV eax,    4
    MOV ebx,    1
    int 80h

    MOV ecx,    new
    MOV edx,    len
    MOV eax,    4
    MOV ebx,    1
    int 80h

    inc         edi
    cmp byte[arr + edi * 4], 0
    je          exit
    jmp         print_loop


exit:
    xor ebx,    ebx
    MOV eax,    1
    int 80h

swap_func:
    MOV ecx,    eax
    MOV edx,    ebx
    MOV dword[arr + edi * 4], edx
    MOV dword[arr + esi * 4], ecx
    MOV eax,    dword[arr + edi * 4] 
    jmp         loop2
