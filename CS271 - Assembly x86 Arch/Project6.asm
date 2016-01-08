TITLE Project6     (Project6.asm)

; Author: William Kim
; EMail: Kimw@oregonstate.edu
; CS271-400 Project6                 Due Date:12/06/2015
; Description: This program will display my name and the program title
; it will then ask the user to enter 10 unsigned decimal integers.
; Then the program will display a list of the integers, their sum, and their
; average value.

INCLUDE Irvine32.inc

getString MACRO buffer, buffer1, buffer2, buffer3
	push	edx
	push	ecx
     mov  edx, buffer
     call WriteString
     mov  edx, buffer1
     mov  ecx,(buffer2)-1
     call ReadString
     mov  buffer3,eax
	pop	edx
	pop	ecx
ENDM

displayString MACRO buffer
	push		edx
     mov		edx, buffer 
     call		WriteString
	pop		edx
ENDM

.data				
intro		BYTE		"Program 6 by William Kim",0
prompt1		BYTE		"Please provide 10 unsigned decimal integers.",0
prompt2		BYTE		"Each number needs to be small enough to fit inside a 32 bit register.",0
prompt3		BYTE		"After you have finished inputting the raw numbers I will display a list",0
prompt4		BYTE		"of the integers, their sum, and their average value.",0
prompt		BYTE		"Please enter an unsigned number: ",0
invalid		BYTE		"ERROR: You did not enter an unsigned number or your number was too big.",0
retry		BYTE		"Please try again: ",0
list			BYTE		"You entered the following numbers: ",0
sumMsg		BYTE		"The sum of these numbers is: ",0
avgMsg		BYTE		"The average is: ",0
outro		BYTE		"Thanks for playing!",0
input		DWORD	?
sum			DWORD	?
array1		DWORD	10	DUP(?)
array2		BYTE		10	DUP(?)			
array3		BYTE		20   DUP(?)	

.code

main PROC

     push		OFFSET intro
     push		OFFSET prompt1
     push		OFFSET prompt2
     push		OFFSET prompt3
     push		OFFSET prompt4
     call		Introduction

	push		OFFSET retry
     push		OFFSET invalid
     push		OFFSET prompt
	push		SIZEOF array2
     push		OFFSET array2
	push		OFFSET array1
     push		OFFSET input
     call		ReadVal

	push		OFFSET outro
	push		OFFSET sumMsg
	push		sum
     push		OFFSET avgMsg
     push		OFFSET list
     push		OFFSET array1
     push		OFFSET array3
     call		WriteVal 

     exit ; exit to Operating System
main ENDP

;Intro
Introduction PROC

     push ebp
     mov  ebp,esp
     pushad
	displayString [ebp+24]
     call CrLf
     displayString [ebp+20]
     call CrLf
     displayString [ebp+16]
     call CrLf
     displayString [ebp+12]
     call CrLf
     displayString [ebp+8]
     call CrLf
	call CrLf
     popad
     pop  ebp
	ret  20

Introduction ENDP

;Read user input and converts string to int
ReadVal PROC

     push		ebp
     mov		ebp,esp
     mov		esi,[ebp+16]
     mov		edi,[ebp+12]
     mov		ecx,10					
L1:
     pushad
Get:
     getString [ebp+24], [ebp+16], [ebp+20], [ebp+8]
Get2:
	mov		edx,0
     mov		ecx,[ebp+8]					
     cld

;Validation checking
Counter:
     lodsb
     cmp  al,0
     je   quit
     cmp  al,48 ; if less than 0
     jl   error
     cmp  al,57 ; if greater than 9
     jg   error         
;Converting back to ASCII     
     sub  al,48
     push eax               
     push ecx
     mov  eax,edx         
     mov  ecx,10
     mul  ecx
	cmp  edx,0
     mov  edx,eax
     pop  ecx
     pop  eax
	jnz  error
     push ebx
     movsx ebx,al
     add  edx,ebx
     pop  ebx
     loop Counter
;Store number into array
     mov  [edi],edx
	popad
	add  edi,4
     loop L1
	jmp quit
;Displays error message and prompts user try again
error:
     displayString [ebp+28]
     call CrLf
	getString [ebp+32], [ebp+16], [ebp+20], [ebp+8]
	mov  esi,[ebp+16]
     jmp  get
quit:
     pop  ebp
     ret  20
ReadVal ENDP

;Converts int back into string and outputs numbers, sum, and avg
WriteVal PROC
     push ebp
     mov  ebp,esp
     mov  esi,[ebp+12]
     mov  edi,[ebp+8] 
     pushad   
     mov  ecx, 10 
;This outer loop loops through all number in the integer array
L1:
     push ecx
     mov  ebx,1000000000			; Max 10 digit (divide by 10 to loop through number)
	push	ecx
	push eax
	mov  eax,[esi]				;Loads int to eax
	mov	ecx, [ebp+24]			;loads @sum to ecx
	add	ecx, eax				;Add int to sum
	mov	[ebp+24], ecx			;Store updated sum
	pop  eax
	pop  ecx

;This loops through the numbers of the integer and determines where to go next
L2: 
     mov  eax,[esi]				; Load int to eax
     cmp  eax,0				; If the number is 0, just store it          
     je   StoreZero 
     cmp  eax,ebx				; Compare again max (ebx) number of digits
     jae  Store				
     mov  eax,ebx
     mov  ebx,10
     mov  edx,0
     div  ebx
     mov  ebx,eax
     jmp  L2
;Stores the integer
Store:
     mov  edx,0
     div  ebx
     add  eax,48
     cld
     stosb
     cmp  ebx,100
     jge  ThreeDigit
	cmp	ebx,10
	jge  TwoDigit
     cmp  edx,0
     je   Space
;Adds a space
Space:
     mov  al,' '
     stosb
     add  esi,4
     pop  ecx
     loop L1
     jmp   quit
;Store int = 0
StoreZero:
     add  eax,48
     cld
     stosb
     jmp  Space

;Handles number higher than or equal to three digits
ThreeDigit:
     push ecx
     mov  ecx,edx
     mov  eax,ebx
     mov  ebx,10
     mov  edx,0
     div  ebx
     mov  ebx,eax
     mov  eax,ecx
     pop  ecx
     mov  edx,0
     div  ebx
     add  eax,48
     cld
     stosb
     cmp  ebx,10
     je   TwoDigit
     jmp  ThreeDigit
;Handles number that are two digits
TwoDigit:
	mov  eax,ebx
     push ecx
     mov  ecx,edx 
     mov  edx,0
     mov  ebx,10
     div  ebx
     mov  ebx,eax
     mov  eax,ecx
     pop  ecx
     mov  edx,0
     div  ebx
     add  eax,48
     cld
     stosb
;Handles last digit
OneDigit:
     cmp  edx,0 
     je   Space
     mov  eax,edx
     add  eax,48 
     cld
     stosb
     jmp  Space
quit:
	;Display list of numbers
	displayString [ebp+16]
     call CrLf
     displayString [ebp+8]
	call crlf
	call Crlf

	;Display sum
	displayString [ebp+28]
	push eax
	mov eax,[ebp+24]
	call WriteDec
	call Crlf
	call Crlf

	;Display average, calc avg by div sum by 10
	displayString [ebp+20]
	push ebx
	mov	ebx,0
	mov	ecx,10
	div  ecx
	call	WriteDec
	call Crlf

	pop ebx
	pop eax
     popad
     pop  ebp
     ret  12
WriteVal ENDP

END main