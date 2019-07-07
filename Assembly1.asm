; *************************************************************************
; 32-bit Windows Standard Application
; Nobita4x4m
; *************************************************************************
     
.686					; Enable 80686+ instruction set
.model flat, stdcall	; Flat, 32-bit memory model (not used in 64-bit)
option casemap: none	; Case sensitive syntax

; *************************************************************************
; MASM32 proto types for Win32 functions and structures
; *************************************************************************  

WinMain proto :DWORD, :DWORD, :DWORD, :DWORD

include F:\masm32\include\windows.inc
include F:\masm32\include\user32.inc
include F:\masm32\include\kernel32.inc
include F:\masm32\include\masm32.inc
         
; *************************************************************************
; MASM32 object libraries
; *************************************************************************  
includelib F:\masm32\lib\user32.lib
includelib F:\masm32\lib\kernel32.lib
includelib F:\masm32\lib\msvcrt.lib

; *************************************************************************
; Our data section. 
; *************************************************************************
.data
ClassName db "SimpleWinClass", 0
AppName	db "Simple Caculator", 0
MenuName db "First Menu", 0
ButtonClassName db "Button", 0
ClearButtonClassName db "Button", 0
EditClassName db "Edit", 0

Button0 db "0", 0
Button1 db "1", 0 
Button2 db "2", 0 
Button3 db "3", 0 
Button4 db "4", 0 
Button5 db "5", 0 
Button6 db "6", 0 
Button7 db "7", 0 
Button8 db "8", 0
Button9 db "9", 0

ButtonPlus db "+", 0   
ButtonMinus db "-", 0
ButtonMultiply db "X", 0
ButtonDivide db "/", 0
ButtonClear db "AC", 0
ButtonEqual db "=", 0
  

; *************************************************************************
; Our data unitialised section
; *************************************************************************
.data?
hInstance HINSTANCE ?
CommandLine LPSTR ?
hwndButton HWND ?
hwndClear HWND ?
hwndEdit HWND ?
buffer db 512 dup(?)
Para1 db 20 dup(?)
Para2 db 20 dup(?)
idx db 20 dup(0)
K	db 20 dup(0)
Caculate db 20 dup(0)
result db 512 dup(?)

; *************************************************************************
; Constants. 
; *************************************************************************
.Const

EditID equ 21

ButtonZeroID equ 0
ButtonOneID equ 1
ButtonTwoID equ 2
ButtonThreeID equ 3
ButtonFourID equ 4
ButtonFiveID equ 5
ButtonSixID equ 6
ButtonSevenID equ 7
ButtonEightID equ 8
ButtonNineID equ 9

ButtonPlusID equ 10
ButtonMinusID equ 11
ButtonMultiplyID equ 12
ButtonDivideID equ 13
ButtonClearID equ 14
ButtonEqualID equ 15

IDM_ZERO equ 0
IDM_ONE equ 1
IDM_TWO equ 2
IDM_THREE equ 3
IDM_FOUR equ 4
IDM_FIVE equ 5
IDM_SIX equ 6
IDM_SEVEN equ 7
IDM_EIGHT equ 8
IDM_NINE equ 9

IDM_PLUS equ 10
IDM_MINUS equ 11
IDM_MULTIPLY equ 12
IDM_DIVIDE equ 13
IDM_CLEAR equ 14
IDM_EQUAL equ 15


; *************************************************************************
; Marcos. 
; *************************************************************************


; *************************************************************************
; Our executable assembly code starts here in the .code section
; *************************************************************************
.code

start:
	;xor esi, esi
	xor edi, edi
	
	push NULL
	call GetModuleHandle
	
	mov hInstance, eax
	call GetCommandLine
	
	mov CommandLine, eax
	push SW_SHOWDEFAULT
	push CommandLine
	push NULL
	push hInstance
	call WinMain
    
	; Exit APP
    push 0
	call ExitProcess

;The Main fuction for the app

WinMain proc hInst:HINSTANCE, hPrevInst:HINSTANCE, CmdLine:LPSTR, CmdShow:DWORD

	; LOCAL wc:WNDCLASSEX tells MASM to allocate memory from the stack the size of WNDCLASSEX structure for the variable named wc.
    Local wc:WNDCLASSEX   		; 4 - An instance of the window class
    Local msg:MSG            	; A message from and to the window
    Local hwnd:HWND				; The handle to the window
    
    Mov   wc.cbSize,SIZEOF WNDCLASSEX    		; The size of this instance of the window struct
    Mov   wc.style, CS_HREDRAW or CS_VREDRAW  	; The style of the window
    Mov   wc.lpfnWndProc, Offset WndProc     	; The point to the window procedure
    Mov   wc.cbClsExtra, NULL         			; The number of extra bytes to allocate following the window-class structure. The system initializes the bytes to zero.
    Mov   wc.cbWndExtra, NULL  					; The number of extra bytes to allocate following the window instance. The system initializes the bytes to zero
    Push  hInst   								; Push the instance that contains the window procedure for the class onto the stack
    Pop   wc.hInstance							; A handle to the instance that contains the window procedure for the class.
    Mov   wc.hbrBackground, COLOR_BTNFACE + 1  	; A handle to the class background brush.
    ; A color value must be one of the standard system colors (the value 1 must be added to the chosen color)
    Mov   wc.lpszMenuName, Offset MenuName    	; Pointer to a null-terminated character string that specifies the resource name of the class menu
    Mov   wc.lpszClassName, Offset ClassName 	; A pointer to a null-terminated string created by a previous call to the RegisterClassEx function
    
	Push IDI_APPLICATION    	; Push default application icon vlaue onto stack
	Push NULL					; A handle to an instance of the module whose executable file contains the icon to be loaded. This parameter must be NULL when a standard icon is being loaded
	Call LoadIcon				; Load standard application icon
	
    Mov wc.hIcon, Eax           ; Load Icon into window instance
    Mov wc.hIconSm, Eax         ; Load small icon into app instance
    
	Push IDC_ARROW              ; Push standard arrow icon value onto stack
	Push NULL                   ; A handle to an instance of the module whose executable file contains the cursor to be loaded. NULL if using standard cursors
	Call LoadCursor				; Loads the specified cursor resource from the executable file associated with an application instance.
    
	Mov wc.hCursor, Eax			; Load cursor handle into app instance
    
    Lea Ecx, wc                 ; Load Effetive Address of wc object into Ecx Register
    Push Ecx	                ; Push value of wc address onto stack from Ecx register
    Call RegisterClassEx		; 5 - Regisater the window instance
    
	; Create the window using the newly created app instance wc
    Push NULL                  	; Optional pointer to a data structure passed to the window. This is used by MDI window to pass the CLIENTCREATESTRUCT data.
    Push hInst               	; The instance handle for the program module creating the window.
    Push NULL              		; A handle to the window's menu. NULL if the default class menu is to be used.
    Push NULL               	; A handle to the window's parent window if it exists, NULL if not
    Push 500					; The height of the window - CW_USEDEFAULT tells windows to decide
    Push 350                 	; The width of the window - CW_USEDEFAULT tells windows to decide
    Push CW_USEDEFAULT          ; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
    Push CW_USEDEFAULT         	; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
    Push WS_OVERLAPPEDWINDOW   	; Style of the window - The most common window style is WS_OVERLAPPEDWINDOW.
    Push Offset AppName       	; Address of the ASCIIZ string containing the name of the window. It'll be shown on the title bar of the window
    Push Offset ClassName   	; Address of the ASCIIZ string containing the name of window class you want to use as template for this window
    Push WS_EX_CLIENTEDGE   	; Extended Window Stye - The window has a border with a sunken edge.
    Call CreateWindowEx			; 6 - Creatw Window Object 
    
    Mov	hwnd, Eax           	; Copy created window handle to hwnd object
    
    Push SW_SHOWNORMAL         	; Activates and displays a window. Use this value if window is displayed for the first time
    Push hwnd           		; Push the created window handle onto the stack
    Call ShowWindow				; 7 - Display the window on screem
    
    Push hwnd					; Push the created window handle onto the stack
	Call UpdateWindow			; 8 - Update the window using associated window handle
    
    ; Enter a while loop that waits for and responds to messages sent to and from the window such as keyboard input
	.WHILE TRUE					; While GetMessage returns TRUE
		
		Push 0             		; The integer value of the highest message value to be retrieved from the range of retrieved messages
		Push 0                	; The integer value of the lowest message value to be retrieved from the range of retrieved messages
		Push NULL              	; Window handle whose messages are to be retrieved. If NULL messages for all current thread windows and any messages for windows whose hend is NULL
		Lea Ecx, msg          	; Load Effective Address of msg Object
		Push Ecx                ; Push address of msg Object onto stack
		Call GetMessage   		; Acquires next message from windows, loads into msg object and runs WndProc
        
        .BREAK .IF (!Eax)  		; Break if GetMessage returns FALSE
        
        Lea Ecx, msg            ; Load Effective Address of msg Object
		Push Ecx                ; Push address of msg Object onto stack
        Call TranslateMessage  	; Transaltes keyboard input and generates a new message (WM_CHAR). This message contains the ASCII value for the key pressed. You can omit this call if your program doesn't process keystrokes.
        
        Lea Ecx, msg            ; Load Effective Address of msg Object
		Push Ecx                ; Push address of msg Object onto stack
        Call DispatchMessage   	; DispatchMessage sends the message data to the window procedure responsible for the specific window the message is for. In our case, EditBox when we type and Button when we press the button
        
    .ENDW
    
    Mov     Eax, msg.wParam  	; Return value from WNDCLASSEX loaded into Eax for return to app
    Ret                       	; Return
    
WinMain endp

WndProc proc hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM

	;WndProc rns as part of the GetMessage Call
    .IF uMsg==WM_DESTROY     	; User clses app
    	
   		Push NULL
   		Call PostQuitMessage	; Posts the WM_QUIT message to the message loop causing GetMessage() to return FALSE and stop processing messages
    
	.ELSEIF uMsg==WM_CREATE		; Called when Main window s creatd - create Controls attached to main window
    	
		;Display Screen
		Push NULL              	; Optional pointer to a data structure passed to the window. This is used by MDI window to pass the CLIENTCREATESTRUCT data.
    	Push hInstance       	; The instance handle for the program module creating the window.
    	Push EditID             ; A handle to the window's menu. NULL if the default class menu is to be used.
    	Push hWnd            	; A handle to the window's parent window if it exists, NULL if not
    	Push 60               	; The height of the window - CW_USEDEFAULT tells windows to decide
    	Push 240             	; The width of the window - CW_USEDEFAULT tells windows to decide
    	Push 35                	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
    	Push 40                	; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
    	Push WS_CHILD or WS_VISIBLE or WS_BORDER or ES_LEFT or ES_AUTOHSCROLL 	; Style of the window
    	Push NULL             	; Address of the ASCIIZ string containing the name of the window.
    	Push Offset EditClassName 	; Address of the ASCIIZ string containing the name of window class you want to use as template for this window
    	Push WS_EX_CLIENTEDGE 	; Extended Window Stye - The window has a border with a sunken edge.
    	Call CreateWindowEx     ; Create the Edit Box
    	
        Mov  hwndEdit, Eax     	; Move handle for EditBox into hwndEdit HWND Object
        
       	;Push hwndEdit
		;Call SetFocus 	; Give Edit Box Focus upon App starting
        
       	;Number 0
 	Number0:
	 	mov esi, ButtonZeroID       	
	 	mov eax, hWnd
        mov edx, 300               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 40            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset Button0
		call Create_Button
        
        		        
		;Number 1
 	Number1:
	 	mov esi, ButtonOneID       	
	 	mov eax, hWnd
        mov edx, 240               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 40            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset Button1
		call Create_Button
		
		;Number 2
	Number2:	
 		mov esi, ButtonTwoID       	
	 	mov eax, hWnd
        mov edx, 240               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 100            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset Button2
		call Create_Button
		
		;Number 3
	Number3:
	 	mov esi, ButtonThreeID       	
	 	mov eax, hWnd
        mov edx, 240               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 160            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset Button3
		call Create_Button
	 	
		;Number 4
	Number4:
	 	mov esi, ButtonFourID       	
	 	mov eax, hWnd
        mov edx, 180               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 40            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset Button4
		call Create_Button
		
		;Number 5
	Number5:
	 	mov esi, ButtonFiveID       	
	 	mov eax, hWnd
        mov edx, 180               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 100            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset Button5
		call Create_Button
		
		;Number 6
	Number6:
	 	mov esi, ButtonSixID       	
	 	mov eax, hWnd
        mov edx, 180               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 160            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset Button6
		call Create_Button
		
		;Number 7
 	Number7:
	 	mov esi, ButtonSevenID       	
	 	mov eax, hWnd
        mov edx, 120               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 40            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset Button7
		call Create_Button
		
		;Number 8
	Number8:	
	 	mov esi, ButtonEightID       	
	 	mov eax, hWnd
        mov edx, 120               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 100            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset Button8
		call Create_Button 
	
        ;Number 9
 	Number9:
	 	mov esi, ButtonNineID       	
	 	mov eax, hWnd
        mov edx, 120               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 160            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset Button9
		call Create_Button
        
        ;Plus
  	Plus_Bt:
	 	mov esi, ButtonPlusID       	
	 	mov eax, hWnd
        mov edx, 120               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 220            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset ButtonPlus
		call Create_Button
        
        ;Minus
  	Minus_Bt:
	 	mov esi, ButtonMinusID       	
	 	mov eax, hWnd
        mov edx, 180               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 220            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset ButtonMinus
		call Create_Button
        
        ;Multiply
  	Multiply_Bt:
	 	mov esi, ButtonMultiplyID       	
	 	mov eax, hWnd
        mov edx, 240               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 220            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset ButtonMultiply
		call Create_Button
        
        ;Divide
  	Divide_Bt:
	 	mov esi, ButtonDivideID       	
	 	mov eax, hWnd
        mov edx, 300               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 220            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset ButtonDivide
		call Create_Button
        
        ;Clear
  	Clear_Bt:
	 	mov esi, ButtonClearID       	
	 	mov eax, hWnd
        mov edx, 300               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 100            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset ButtonClear
		call Create_Button
        
        ;Equal
  	Equal_Bt:
	 	mov esi, ButtonEqualID       	
	 	mov eax, hWnd
        mov edx, 300               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov edi, 160            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
        mov ecx, offset ButtonEqual
		call Create_Button
                
    
	.ELSEIF uMsg==WM_COMMAND   	; Window receives a message from Windows
		mov eax, wParam
		.IF lParam == 0
			.IF ax == IDM_ZERO
			ZERO:
				xor ebx, ebx
				mov bl, 30h
				call Display_Number	
			
				
			.ELSEIF ax == IDM_ONE
		 	ONE:
				xor ebx, ebx
				mov bl, 31h
				call Display_Number

   	
    		.ELSEIF ax == IDM_TWO
		 	TWO:
				xor ebx, ebx
				mov bl, 32h
				call Display_Number
				
				
			.ELSEIF ax == IDM_THREE
			THREE:
				xor ebx, ebx
				mov bl, 33h
				call Display_Number
			
			
			.ELSEIF ax == IDM_FOUR
			FOUR:
				xor ebx, ebx
				mov bl, 34h
				call Display_Number
			
			
			.ELSEIF ax == IDM_FIVE
			FIVE:
				xor ebx, ebx
				mov bl, 35h
				call Display_Number
				
			
			.ELSEIF ax == IDM_SIX
		 	SIX:
				xor ebx, ebx
				mov bl, 36h
				call Display_Number
				
			.ELSEIF ax == IDM_SEVEN
			SEVEN:
				xor ebx, ebx
				mov bl, 37h
				call Display_Number
			
			
			.ELSEIF ax == IDM_EIGHT
			EIGHT:
				xor ebx, ebx
				mov bl, 38h
				call Display_Number
				
			
			.ELSEIF ax == IDM_NINE
			NINE:
				xor ebx, ebx
				mov bl, 39h
				call Display_Number
				
	
	;Plus
	        .ELSEIF ax == IDM_PLUS
	        Plus:
				mov esi, 1					   				      				
				call Create_Parameter
			
			.ELSEIF ax == IDM_MINUS
			
			Minus:
				mov esi, 2
				call Create_Parameter
			
			.ELSEIF ax == IDM_MULTIPLY
			Multiply:
				mov esi, 3
				call Create_Parameter
			
			.ELSEIF ax == IDM_DIVIDE
			Divide:
				mov esi, 4
				call Create_Parameter
			
			.ELSEIF ax == IDM_CLEAR
			Clear:	
				mov ecx, offset K
				mov byte ptr [ecx], 0
				mov ecx, offset idx
				mov byte ptr [ecx], 0
				
				;memset fuction	
				mov eax, 0
				lea edi, buffer
				mov ecx, 512
				mov ebx, ecx
				rep stosb
				
				;Clear text on screen
				Push NULL              	; Push NULL onto stack
				Push hwndEdit         	; Push handle of Edit Box onto stack
				Call SetWindowText  	; Clear EditBox Text
			
			.ELSEIF ax == IDM_EQUAL
			Equal:
				;Get text from screen for parameter2
			    Push 20                ; Push chosen size of buffer for Edit Box text onbto stack
				Push Offset Para2      ; Push address of Parameter1 for Edit Box text onto stack
				Push hwndEdit         	; Push handle of Edit Box onto stack
				Call GetWindowText	 	; Save Text to Parameter1
			
				mov ecx, offset Caculate
				mov dl, byte ptr [ecx]
				cmp dl, 1
				jz Plus_Caculate
				cmp dl, 2
				jz Minus_Caculate
				cmp dl, 3
				jz Multiply_Caculate
				cmp dl, 4
				jz Divide_Caculate
			
			
			Plus_Caculate:
				call Plus_Process
				jmp Done
			
			Minus_Caculate:
				call Minus_Process
				jmp Done
				
			Multiply_Caculate:
				call Multiply_Process
				jmp Done
			
			Divide_Caculate:
				call Divide_Process
				jmp Done
			
			Done:
				push offset result
				push hwndEdit
				call SetWindowText
				
				;memset fuction	
				mov eax, 0
				lea edi, Para1
				mov ecx, 20
				mov ebx, ecx
				rep stosb
				
				;memset fuction	
				mov eax, 0
				lea edi, Para2
				mov ecx, 20
				mov ebx, ecx
				rep stosb		
				
				Push 20                ; Push chosen size of buffer for Edit Box text onbto stack
				Push Offset Para1      ; Push address of Parameter1 for Edit Box text onto stack
				Push hwndEdit         	; Push handle of Edit Box onto stack
				Call GetWindowText	 	; Save Text to Parameter1
				
				;memset fuction	
				mov eax, 0
				lea edi, buffer
				mov ecx, 512
				mov ebx, ecx
				rep stosb
				
				;memset fuction	
				mov eax, 0
				lea edi, result
				mov ecx, 512
				mov ebx, ecx
				rep stosb
				
				;reset idx
				mov esi, offset idx
  				mov byte ptr [esi], 0
  				
				
			.ELSE					; Any other message ID
            
            	Push hWnd        	; Push handle to main window onto stack
            	Call DestroyWindow 	; Sends WM_DESTROY and WM_NCDESTROY messages to the window to deactivate and destroy it
            	
            .ENDIF
	
       
       	.ELSE 
       		.IF ax == ButtonZeroID
       			shr eax, 16
       			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_ZERO	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                
	     		.ENDIF
     		.ELSEIF ax == ButtonOneID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_ONE	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
            
			.ELSEIF ax == ButtonTwoID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_TWO	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF    
           
            .ELSEIF ax == ButtonThreeID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_THREE	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           
           	.ELSEIF ax == ButtonFourID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_FOUR	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           
           	.ELSEIF ax == ButtonFiveID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_FIVE	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           
           	.ELSEIF ax == ButtonSixID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_SIX	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           
           	.ELSEIF ax == ButtonSevenID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_SEVEN	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           
           	.ELSEIF ax == ButtonEightID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_EIGHT	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           
      		.ELSEIF ax == ButtonNineID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_NINE	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           
           ;Button for caculate
           
           	.ELSEIF ax == ButtonPlusID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_PLUS	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           
		 	.ELSEIF ax == ButtonMinusID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_MINUS	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           
            .ELSEIF ax == ButtonMultiplyID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_MULTIPLY	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           	
           	.ELSEIF ax == ButtonDivideID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_DIVIDE	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           	
           	.ELSEIF ax == ButtonClearID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_CLEAR	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           	
           	.ELSEIF ax == ButtonEqualID
     			shr eax, 16
     			.IF ax == BN_CLICKED
       				Push 0            	; lParam
                    Push IDM_EQUAL	; wParam
                    Push WM_COMMAND		; The message to be sent
                    Push hWnd          	; The handle to the window that will recieve the message
                    Call SendMessage    ; Send the message WM_COMMAND with lParam = 0 and wParam = IDM_GETTEXT to the main window
                .ENDIF
           	
       	    .ENDIF
   	    .ENDIF
    .ELSE
    	Push lParam             ; lParam
    	Push wParam             ; wParam
    	Push uMsg               ; The message to be processed
    	Push hWnd         		; Push the handle to the main window onto the stack
    	Call DefWindowProc		; Calls the default window procedure to provide default processing for any window messages that an application does not process
    	
        Ret                     ; Returns from the WndProc function
        
    .ENDIF
    
     Xor Eax, Eax   ; Set Eax to 0 
     
    Ret    			; Returns from the WndProc function
    
WndProc endp

Create_Parameter proc
	xor edx, edx
	mov edx, esi
	mov ecx, offset Caculate
	mov byte ptr [ecx],  dl; ID of plus
	
	;check amount of current parameters        	
	xor edx, edx
	mov ecx, offset K
	mov dl, byte ptr [ecx]
	mov edi, edx
	cmp dl, 0
	jz 	Take_Parameter
	jmp Get_out ; if we have one, we will exit
	        	
Take_Parameter:
	Push 20                ; Push chosen size of buffer for Edit Box text onbto stack
	Push Offset Para1      ; Push address of Parameter1 for Edit Box text onto stack
	Push hwndEdit         	; Push handle of Edit Box onto stack
	Call GetWindowText	 	; Save Text to Parameter1
	            
;	Push MB_OK             	; Push type oif butons for message box onto sack
;	Push Offset AppName    	; Push address of application name onto stack
;	Push Offset Para1   	; Push address of buffer for Edit Box text onto stack
;	Push NULL               ; Push handle to parent window onto stack
;	Call MessageBox			; MessageBox buffer

					
;take amount current parameter
	mov edx, edi
	inc edx
	mov ecx, offset K
	mov byte ptr [ecx], dl
;restart index
   				
	mov ecx, offset idx
	mov byte ptr [ecx], 0
   			
;memset fuction	
	mov eax, 0
	lea edi, buffer
	mov ecx, 512
	mov ebx, ecx
	rep stosb    
Get_out:
	;Clear text on screen
	Push NULL              	; Push NULL onto stack
	Push hwndEdit         	; Push handle of Edit Box onto stack
	Call SetWindowText  	; Clear EditBox Text
	ret
Create_Parameter endp

Display_Number proc          ; display numbers on screen and save them to buffer
	
	xor edx, edx
 	mov esi, offset idx
  	mov dl, byte ptr [esi]
			
	mov ecx, offset buffer
	mov byte ptr[ecx + edx], bl
	inc edx
	mov byte ptr [esi], dl
				
	push offset buffer
	push hwndEdit
	call SetWindowText

	ret
Display_Number endp 

Create_Button proc
	
	Push NULL              	; Optional pointer to a data structure passed to the window. This is used by MDI window to pass the CLIENTCREATESTRUCT data.
 	Push hInstance         	; The instance handle for the program module creating the window.
  	Push esi          	; A handle to the window's menu. NULL if the default class menu is to be used.
   	Push eax             	; A handle to the window's parent window if it exists, NULL if not
   	Push 60               	; The height of the window - CW_USEDEFAULT tells windows to decide
    Push 60               	; The width of the window - CW_USEDEFAULT tells windows to decide
    Push edx               	; The Y coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
    Push edi            		; The X coordinate of the upper left corner of the window - CW_USEDEFAULT tells windows to decide
    Push WS_CHILD or WS_VISIBLE or BS_DEFPUSHBUTTON 	; Style of the window
    Push ecx 	; Address of the ASCIIZ string containing the name of the window.
    Push Offset ButtonClassName  	; Address of the ASCIIZ string containing the name of window class you want to use as template for this window
    Push NULL              	; Extended Window Stye - The window has a border with a sunken edge.
    Call CreateWindowEx   	; Create the Button	

	ret
Create_Button endp

Plus_Process proc

	mov ecx, offset Para1
	call Ascii_to_Int
	mov edi, esi
	
	mov ecx, offset Para2
	call Ascii_to_Int
	
	add edi, esi
	mov ecx, offset result
	
	call Int_to_Ascii
	
	ret
Plus_Process endp

Minus_Process proc

	mov ecx, offset Para1
	call Ascii_to_Int
	mov edi, esi
	
	mov ecx, offset Para2
	call Ascii_to_Int
	
	mov ecx, offset result
	cmp edi, esi
	jg	Positive
	jz	Equal_Minus
	;Negative
	mov byte ptr [ecx], 2Dh
	inc ecx
	sub esi, edi
	mov edi, esi
	jmp Do_Minus

Equal_Minus:
	mov byte ptr [ecx], 30h
	ret

Positive:
	sub edi, esi

Do_Minus:
	call Int_to_Ascii 
	
	ret
Minus_Process endp

Multiply_Process proc
 	mov ecx, offset Para1
	call Ascii_to_Int
	mov edi, esi
	
	mov ecx, offset Para2
	call Ascii_to_Int
	
	xor ebx, ebx
	mov ecx, offset result
	
	xor edx, edx
	mov eax, edi
	mul esi
	mov ebx, eax
	cmp edx, 0
	jz  Is_32bit_Num
	mov edi, edx      ;We had bug here and we must to change Hex to Dec to get true res
	call Int_to_Ascii

Is_32bit_Num:
	mov edi, ebx
	call Int_to_Ascii	
		
	ret
Multiply_Process endp

Divide_Process proc
    mov ecx, offset Para1
	call Ascii_to_Int
	mov edi, esi
	
	mov ecx, offset Para2
	call Ascii_to_Int
	
	mov eax, edi
	div esi
	
	mov ecx, offset result
	mov edi, eax
	call Int_to_Ascii
	
	
	ret
Divide_Process endp

Ascii_to_Int proc
	xor eax, eax
	mov esi, 10
	xor ebx, ebx
Atoi_loop:
	mov bl, byte ptr [ecx]
	xor bh, bh
	cmp bl, 0
	jz Done_Atoi
	sub bl, 30h
	mul esi
	add eax, ebx
	inc ecx
	jmp Atoi_loop

Done_Atoi:
	xor esi, esi
	mov esi, eax	
	ret
Ascii_to_Int endp

Int_to_Ascii proc

	mov eax, edi
	xor edx, edx
	mov esi, 10
	push 69

Itoa_loop:
	cmp eax, 0
	jz	Save_to_result
	div esi
	push edx
	xor edx, edx
	jmp Itoa_loop

Save_to_result:
	pop edx
	cmp edx, 69
	jz Done_Itoa
	add dl, 30h
	mov byte ptr [ecx], dl
	inc ecx
	jmp Save_to_result

Done_Itoa:
	;mov byte ptr [ecx], 0
	ret
Int_to_Ascii endp
	

end start


