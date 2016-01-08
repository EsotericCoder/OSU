TITLE Project2     (Project2.asm)

; Author: William Kim
; EMail: Kimw@oregonstate.edu
; CS271-400 Project 2                 Due Date:10/18/2015
; Description: This program will display my name and the program title
; it will then ask the user to enter their name and an integer in range
; [1-46]. Then the program will validate the user input and calulate and 
; display all of the fibonacci numbers. Then displaying a parting msg.

INCLUDE Irvine32.inc

.data

UPPERLIMIT = 26		;constant upper limit for users integer input
LOWERLIMIT = 1		;constant lower limit for users integer input
NL1 = 6			;add space on 5
NL2 = 11			;add space on 10
NL3 = 16			;add space on 15
NL4 = 21			;add space on 20
NL5 = 26			;add space on 25

username	BYTE 21	DUP(0)	;User Name
byteCount	DWORD	?
a			DWORD	?		;User input number
pre1		DWORD	?		;Hold the previous value
pre2		DWORD	?		;Hold two space back
intro		BYTE    "Program 2 by William Kim",0
greeting	BYTE	"Hello ",0
prompt1		BYTE    "Please enter your name: ", 0
prompt2		BYTE    "Enter a number in the range of [1-26]: ",0
invalid		BYTE	"Invalid Input. Enter a number in the range of [1-26]: ",0
spaces		BYTE    "     ",0		;blank spaces inbetween numbers 
one			BYTE	"1", 0			;Displays only when 1 is selected
two			BYTE	"1     1     ",0 ;Displays only when 2 is selected
outro		BYTE    "Goodbye!",0

.code
main PROC
;Introduction and prompt
;Display name
	mov		edx,OFFSET intro
	call	WriteString
	call	Crlf
;Display prompt1 to get users name
	mov		edx,OFFSET prompt1
	call	WriteString					;Tells user to enter name
	mov		edx,OFFSET username
	mov		ecx,SIZEOF username
	call	ReadString					;Gets users name
	mov		byteCount,eax

;Display greeting to user
	mov		edx,OFFSET greeting
	call	WriteString					;Displayes Hello
	mov		edx,OFFSET username
	call	WriteString
	call	Crlf

;get an integer from user
	
	mov		edx,OFFSET prompt2
	call	WriteString
	call	ReadInt
	mov		a,eax

;validate user input is less or equal to upper limit (26)
greater:
	mov		eax,a
	cmp		eax,UPPERLIMIT		;Checks if user input is less than 27
	jg		invalidinput		;prompt user to enter integer again

;validate user input is greater or equal to lower limit (1)
less:
	mov		eax,a
	cmp		eax,LOWERLIMIT		;Checks if user input is greater than 0
	jl		invalidinput		;prompt user to enter integer again
	je		only1				;jumps to only1 to print out 1
	cmp		eax,2				;compare if userinput is 2
	je		only2				;jumps to only2 to print out 1     1
	jmp		fib

only1:
	mov		edx,OFFSET one
	call	WriteString
	call	Crlf
	jmp		goodbye

only2:
	mov		edx,OFFSET two
	call	WriteString
	call	Crlf
	jmp		goodbye
	

;display error and prompts user to enter integer again
invalidinput:
	mov		edx,OFFSET invalid
	call	WriteString
	call	ReadInt
	mov		a,eax
	call	Crlf
	jmp		greater


;Initialize the loop
fib:
	
	mov		ebx,1			;Initialize all variable to start at position 3
	mov		pre1,1
	mov		pre2,1
	mov		ecx,a			;Set counter for loop
	sub		ecx,2			;Adjusting for the first two output
	mov		edx,OFFSET two		;output the first two
	call	WriteString

;Loop to calculate and display fibonacci sequence
L1:
	mov		eax,pre1
	add		eax,pre2
	mov		edx,pre1
	mov		pre2,edx
	mov		pre1,eax
	call	WriteDec
	mov		edx,OFFSET spaces
	call	WriteString
	cmp		ecx,NL1				;these are used to add newline every fifth
	je		addline				;fibonacci number
	cmp		ecx,NL2
	je		addline
	cmp		ecx,NL3
	je		addline
	cmp		ecx,NL4
	je		addline
	cmp		ecx,NL5
	je		addline
	loop	L1		
	
jmp goodbye		;Skip addline and go to goodbye when loop completes

;adds a newline and continues back at loop L1
addline:
		call	Crlf
		loop	L1

;Display goodbye message
goodbye:
	call	Crlf
	mov 	edx,OFFSET outro
	call	WriteString
	call	Crlf

	exit	; exit to operating system
main ENDP

END main