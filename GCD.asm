.386
.model flat, stdcall
option casemap:none

include E:\masm32\include\windows.inc
include E:\masm32\include\user32.inc
include E:\masm32\include\kernel32.inc
include E:\masm32\include\masm32.inc
         
; *************************************************************************
; MASM32 object libraries
; *************************************************************************  
includelib E:\masm32\lib\user32.lib
includelib E:\masm32\lib\kernel32.lib
includelib E:\masm32\lib\msvcrt.lib
includelib E:\masm32\lib\masm32.lib


.data
	x word 360
	y word 150
	string db 20 dup(0)
	
.code
start proc
	xor eax, eax
	xor ebx, ebx
	mov ax, word ptr [x]
	mov bx, word ptr [y]
	test eax, eax
	jns check_y
	neg ax
check_y:
	test ebx, ebx
	jns Find_GCD
	neg bx
	
Find_GCD:
	push ebx
	push eax
	call GCD
	add esp, 08h
	
	push eax
	call itoa
	
	push eax
	call StdOut
	
;;Exit
Exit:
	push 0
	call ExitProcess

GCD proc
	push ebp
	mov ebp, esp
	mov eax, [ebp + 08h]
	mov ebx, [ebp + 0Ch]
loop_GCD:
	xor edx, edx
	div ebx
	mov eax, ebx
	mov ebx, edx
	cmp ebx, 0
	jnz loop_GCD
	
	pop ebp
	ret 8
GCD endp

itoa proc
	push ebp
	mov ebp, esp
	xor eax, eax
	mov eax, [ebp + 08h]
	mov ecx, offset string
	push 69h
	mov ebx, 10
	
		
loop_itoa:
	xor edx, edx
	div ebx
	add dl, 30h
	xor dh, dh
	push edx
	cmp eax, 0
	jnz loop_itoa
	

done_itoa:
	xor ebx, ebx
	pop ebx
	cmp ebx, 69h
	jz 	OutHere
	mov byte ptr [ecx], bl
	inc ecx
	jmp done_itoa

OutHere:	
	mov eax, offset string
	pop ebp
	ret
itoa endp
	
start endp
End start
