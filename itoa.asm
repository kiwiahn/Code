
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
	newline db 0ah, 0
	num1 dword 48DAF76Eh
	num2 dword 79DA325Ch
	num3 dword 570DC63Ah
	num4 dword 19BCF455h
	string db 50 dup (?)
	
.code
start proc
	mov eax, dword ptr [num1]
	push eax
	call itoa
	add esp, 04h
	
	push eax
	call StdOut
	
	push offset newline
	call StdOut
	
	mov eax, dword ptr [num2]
	push eax
	call itoa
	add esp, 04h
	
	push eax
	call StdOut
	
	push offset newline
	call StdOut
	
	mov eax, dword ptr [num3]
	push eax
	call itoa
	add esp, 04h
	
	push eax
	call StdOut
	
	push offset newline
	call StdOut
	
	mov eax, dword ptr [num4]
	push eax
	call itoa
	add esp, 04h
	
	push eax
	call StdOut
	
	push offset newline
	call StdOut
	
;;Exit
Exit:
	push 0
	call ExitProcess

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
