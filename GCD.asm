
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
	
.code
start proc
	mov ax, dword ptr [x]
	mov bx, dword ptr [y]
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
	
;;Exit
Exit:
	push 0
	call ExitProcess

GCD proc
	push ebp
	mov ebp, esp
	

	pop ebp
	ret 8
GCD endp
	
start endp
End start
