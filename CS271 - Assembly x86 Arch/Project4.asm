TITLE Project4     (Project4.asm)

; Author: William Kim
; EMail: Kimw@oregonstate.edu
; CS271-400 Project4                 Due Date:11/8/2015
; Description: This program will display my name and the program title
; it will then ask the user to enter an integer in range [1-400]
; Then the program will print out the composite.

INCLUDE Irvine32.inc

.data

UPPERLIMIT = 400		;constant upper limit for users integer input
LOWERLIMIT = 1			;constant lower limit for users integer input
OUTPUTLIMIT = 10		;constant outputs per line


a			DWORD	?		;Users input number
count		DWORD	?		;counter for loop
count2		DWORD	?		;counter for nested loop
count3		DWORD	?		;output counter
temp		DWORD	?		;will hold temp value for 1 less
composite	DWORD	?		;composite found 0=false, 1=true
intro		BYTE    "Program 3 by William Kim",0
greeting	BYTE	"Hello ",0
prompt1		BYTE	"Enter the number of composite numbers you would like to see.",0
prompt2		BYTE	"I'll accept orders for up to 400 composites",0
prompt3		BYTE    "Enter the number of composites to delete [1 .. 400]: ",0
invalid		BYTE	"Out of range, Try again.",0
outro		BYTE    "Results certified by William. Goodbye. ",0
space		BYTE	" ",0
spaces		BYTE	"   ",0

.code

main PROC
	call	introduction
	call	getUserData
	call	showComposites
	call	farewell
	exit	; exit to operating system
main ENDP

;Introduction Procedure
introduction PROC
;Display name
	mov		edx,OFFSET intro
	call	WriteString
	call	Crlf
ret
introduction ENDP

;get user data procedure
getUserData PROC
	;Prompt user of rules
		mov		edx,OFFSET prompt1
		call	WriteString
		call	Crlf
		mov		edx,OFFSET prompt2
		call	WriteString
		call	Crlf
		call	validate
		ret
getUserData ENDP

;get an integer from user and validate
validate PROC
	;get an integer from user and validate
	get:
		call	Crlf
		mov		edx,OFFSET prompt3
		call	WriteString
		call	ReadInt
		mov		a,eax

	;validate user input is less or equal to upper limit
	greater:
		mov		eax,a
		cmp		eax,UPPERLIMIT		;Checks if user input is less than 27
		jg		invalidinput

	;validate user input is greater or equal to lower limit
	less:
		mov		eax,a
		cmp		eax,LOWERLIMIT		;Checks if user input is greater than 0
		jl		invalidinput		;prompt user to enter integer again

	ret

	;display error and prompts user to enter integer again
	invalidinput:
		mov		edx,OFFSET invalid
		call	WriteString
		call	Crlf
		mov		edx,OFFSET prompt3
		call	WriteString
		call	ReadInt
		mov		a,eax
		call	Crlf
		jmp		greater
validate ENDP

;Finds and displays composite numbers
showComposites PROC
	mov ecx, a
	L1:
		mov		count, ecx					;Store first loop count
		mov		composite,0					;Initialize composite found to false
		inc		count2						;starting count from 1
		mov     ecx, count2					;set nested loop to starting count
	L2:
		cmp		ecx, 1						;skip if 1
		je		theEnd
		cmp		ecx, 2						;skip if 2
		je		theEnd
		mov		temp, ecx					;move number to temp
		dec		temp						;dec so that it does not divide by itself
		mov		edx, 0		
		mov		eax, count2					;divide number being evaluated but integers less than it
		div		temp
		cmp		edx, 0 
		je		callcomp					;jump
		jg		theEnd

	;Will call isComposite procedure
	callcomp:
		call	isComposite	

	;the end
	theEnd:
		Loop	L2
		mov		ecx, count				;put back outer loop counter
		Loop	L1
	ret
showComposites ENDP

isComposite PROC
	
	cmp		composite, 1				;Skips output if already printed
	je		skip
	mov		eax, count2					;Outputs compsite
	call	WriteDec
	mov		composite, 1				;Set composite already found to true
	mov		edx,OFFSET spaces			;Add spaces
	call	WriteString
	inc		count3						;Add to number of output count
	mov		edx, 0		
	mov		eax, count3					;divide number being evaluated but integers less than it
	mov		ebx, OUTPUTLIMIT
	div		ebx							;adds newline every 10 outputs
	cmp		edx, 0						
	jg		skip			
	call	Crlf		
	skip:
	ret
isComposite ENDP


;Display goodbye message
farewell PROC
	call	Crlf
	mov 	edx,OFFSET outro
	call	WriteString
	call	Crlf
	ret
farewell ENDP

END main