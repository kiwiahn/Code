global _start

section .data

section .bss
    string resb 256

section .text
_start:

    input:
        MOV edx, 256
        MOV ecx, string
        MOV eax, 3
        MOV ebx, 0
        int 80h

    sol:
        MOV ecx, eax
        MOV esi, string
        MOV edi, string
        ADD edi, eax
        dec edi
        dec edi
        shr eax, 1

        .reverse_string:
            MOV bl, [esi]
            MOV bh, [edi]
            MOV [esi], bh
            MOV [edi], bl
            inc esi
            dec edi
            dec eax
            jnz .reverse_string

    output:
        MOV edx, ecx
        MOV ecx, string
        MOV eax, 4
        MOV ebx, 1
        int 80h

        xor ebx, ebx
        MOV eax, 1
        int 80h
