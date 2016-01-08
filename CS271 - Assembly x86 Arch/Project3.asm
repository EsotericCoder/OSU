TITLE Project3     (Project3.asm)

; Author: William Kim
; EMail: Kimw@oregonstate.edu
; CS271-400 Project3                 Due Date:11/1/2015
; Description: This program will display my name and the program title
; it will then ask the user to enter their name and an integer in range
; [-100-1]. Then the program will validate the user input and calculate
; the count, accumulate the user inputs and the calculate the average
;**EC- Added line numbers to user integer input

INCLUDE Irvine32.inc

.data

UPPERLIMIT = -1		;constant upper limit for users integer input
LOWERLIMIT = -100	;constant lower limit for users integer input

username	BYTE 21	DUP(0)	;User Name
byteCount	DWORD	?
a			DWORD	?		;Users input number
all			DWORD	?		;Users accumulated input
count		DWORD	?		;Number of user inputs
inputcount	DWORD	1		;output user input count EC
avg			DWORD	?		;average
intro		BYTE    "Program 3 by William Kim",0
greeting	BYTE	"Hello ",0
prompt1		BYTE    "Please enter your name: ", 0
prompt2		BYTE    "Enter a number in the range of [-100-1]: ",0
prompt3		BYTE	"Enter a non-negative number when you are finished to see results.",0
prompt4		BYTE	" Enter number: ",0
invalid		BYTE	"Invalid Input. Enter a number in the range of [-100-1]: ",0
output1		BYTE	"Numbers you entered ",0
output2		BYTE	" valid numbers.",0
output3		BYTE	"The sum of your valid numbers is ",0
output4		BYTE	"The rounded average is ",0		
output5		BYTE	"You did not enter a number!",0
outro		BYTE    "Goodbye ",0
ec			BYTE	"**EC: Number the lines during user input.",0

.code
main PROC

;Introduction and prompt
;Display name
	mov		edx,OFFSET intro
	call	WriteString
	call	Crlf
;Display EC
	mov		edx,OFFSET	ec
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

;Prompt user of rules
	mov		edx,OFFSET prompt2
	call	WriteString
	call	Crlf
	mov		edx,OFFSET prompt3
	call	WriteString
	call	Crlf

;get an integer from user
get:
	mov		eax, inputcount
	call	WriteDec
	mov		edx,OFFSET prompt4
	call	WriteString
	call	ReadInt
	mov		a,eax

;validate user input is less or equal to upper limit
greater:
	mov		eax,a
	cmp		eax,UPPERLIMIT		;Checks if user input is less than 27
	jg		calc				;Jumps to calc

;validate user input is greater or equal to lower limit
less:
	mov		eax,a
	cmp		eax,LOWERLIMIT		;Checks if user input is greater than 0
	jl		invalidinput		;prompt user to enter integer again

;adds users input and then adds 1 to count
	mov		eax, all
	add		eax, a				;adds user input to all numbers
	mov		all, eax
	inc		count				;adds 1 to count
	inc		inputcount
	jmp		get

;display error and prompts user to enter integer again
invalidinput:
	mov		edx,OFFSET invalid
	call	WriteString
	call	ReadInt
	mov		a,eax
	call	Crlf
	jmp		greater

;Calculates and displays the count and average
calc:
	mov		eax,count					;determines if user enter any numbers
	cmp		eax,0						;jumps to noinput if not
	je		noinput

	mov		eax, all
	cdq
	mov		ebx, count
	idiv	ebx
	mov		avg,eax
	mov		edx,OFFSET output1			;display count
	call	WriteString
	mov		eax, count
	call	WriteDec
	mov		edx,OFFSET output2
	call	WriteString
	call	Crlf

	mov		edx,OFFSET output3			;display sum
	call	WriteString
	mov		eax,all
	call	WriteInt
	call	Crlf

	mov		edx,OFFSET output4			;display average
	call	WriteString
	mov		eax, avg
	call	WriteInt
	call	Crlf
	jmp		goodbye

; Displays special msg if no inputs	
noinput:
	mov		edx,OFFSET output3
	call	WriteString
	call	Crlf

;Display goodbye message
goodbye:
	call	Crlf
	mov 	edx,OFFSET outro
	call	WriteString
	mov		edx,OFFSET username
	call	WriteString
	call	Crlf

	exit	; exit to operating system
main ENDP

END main