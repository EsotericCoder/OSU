TITLE Project5     (Project5.asm)

; Author: William Kim
; EMail: Kimw@oregonstate.edu
; CS271-400 Project4                 Due Date:11/22/2015
; Description: This program will display my name and the program title
; it will then ask the user to enter an integer in range [10-200]
; Then the program will store random numbers in an array and print them out.
; Then the array will be sorted and printed out.

INCLUDE Irvine32.inc

.data

HI			 = 999		;upper limit
LO			 = 100		;lower limit
MIN			 = 10		;min number of requests
MAX			 = 200		;max number of requests
OUTPUTLIMIT	 = 10		;constant outputs per line


array		DWORD	MAX		DUP(?)
request		DWORD	?		;Users input number
intro		BYTE		"Program 5 by William Kim",0
prompt1		BYTE		"This program generates random numbers in the range [100 ... 999], ",0
prompt2		BYTE		"displays the original list, sorts the list, and calculates the",0
prompt3		BYTE		"median value. Finally, it displays the list sorted in descending order.",0
unsorted		BYTE		"The unsorted random numbers:",0
sorted		BYTE		"The sorted list:",0
median		BYTE		"The median is ",0
prompt		BYTE		"How many numbers should be generated? [10 .. 200]: ",0
invalid		BYTE		"Invalid input",0

.code

main PROC
	call	Randomize
	call	introduction

	push	OFFSET prompt
	push	OFFSET invalid
	push	OFFSET request
	call	getData

	push	OFFSET array
	push	request
	call	fillArray

	push	OFFSET array
	push	request
	push	OFFSET unsorted
	call	displayList

	push	OFFSET array
	push	request
	call	sortList

	push	OFFSET array
	push	request
	push	OFFSET median	
	call	displayMedian
	
	push	OFFSET array
	push	request
	push	OFFSET sorted	
	call	displayList

	exit	; exit to operating system
main ENDP

;Introduction Procedure to let user what the application does
introduction PROC
;Display name
	mov		edx,OFFSET intro
	call		WriteString
	call		Crlf
	mov		edx,OFFSET prompt1
	call		WriteString
	call		Crlf
	mov		edx,OFFSET prompt2
	call		WriteString
	call		Crlf
	mov		edx,OFFSET prompt3
	call		WriteString
	call		Crlf
ret
introduction ENDP

;get user data procedure
getData PROC

	push		ebp
	mov		ebp, esp

;get an integer from user and validate
get:
	call		Crlf
	mov		edx,[ebp+16]
	call		WriteString
	call		ReadInt

;validate user input is less or equal to upper limit
greater:
	cmp		eax,MAX						;Checks if user input is less than 200
	jg		invalidinput

;validate user input is greater or equal to lower limit
less:
	cmp		eax,MIN						;Checks if user input is greater than 10
	jl		invalidinput					;prompt user to enter integer again
	jmp		inputGood						;User input is good

;display error and prompts user to enter integer again
invalidinput:
	mov		edx,[ebp+12]					;Display Invalid Message
	call	WriteString
	call	Crlf
	mov		edx,[ebp+16]					;Prompt user to add a new number
	call	WriteString
	call	ReadInt
	call	Crlf
	jmp		greater

inputGood:
	mov		ebx,[ebp+8]					;@request in ebx
	mov		[ebx],eax						;store user input in request
	pop		ebp
	ret		8

getData ENDP

;Fills array with random numbers
fillArray PROC
	push	ebp
	mov		ebp,esp
	mov		edi,[ebp+12]					;@array in edi
	mov		ecx,[ebp+8]					;value of request in ecx
;Generate a random number between 100-999 and store in array
L1:
	mov		eax,HI
	sub		eax,LO
	inc		eax
	call	RandomRange
	add		eax,LO
	mov		[edi],eax
	add		edi,4
	loop	L1

	pop		ebp
	ret		8

fillArray ENDP

;Sorts the list in descending order
sortList PROC
	push		ebp
	mov		ebp,esp

	mov		edi,[ebp+12]					;@array in edi
	mov		ecx,[ebp+8]					;value of request in ecx
	dec		ecx							;dec count by 1
	mov		ebx,0						;clear ebx register
outer:
	mov		eax,ebx	
	mov		edx,eax
	inc		edx
	push		ecx
	mov		ecx,[ebp+8]
inner:
	mov		esi,[edi+edx*4]
	cmp		esi,[edi+eax*4]
	jle		skip							;skip if less than
	mov		eax,edx
skip:
	inc		edx							;increment
	cmp		edx,ecx
	jb		inner
	push		[edi+ebx*4]					;handles the swap
	push		[edi+eax*4]
	pop		[edi+ebx*4]
	pop		[edi+eax*4]
	pop		ecx							;restore counter
	inc		ebx							;increments
	loop		outer						;outer loop

	pop		ebp							;restore ebp
	ret		8	
sortList ENDP

;Displays the middle number
displayMedian PROC

	push		ebp
	mov		ebp,esp
	mov		edx,[ebp+8]					;output string
	call		WriteString
	mov		edx,0						;clear edx
	mov		edi,[ebp+16]					;@array in edi
	mov		eax,[ebp+12]					;request in eax
	mov		ebx,2						;set div denominator
	div		ebx							;divide
	cmp		edx,0
	je		evenNum
;Odd number of requests just get the middle number in array
oddNum:
	mov		eax,[edi+4*eax]
	jmp		displayM
;Even number of requests get both middle numbers and finds the average
evenNum:
	mov		edx,eax
	dec		edx
	mov		edx, [edi+4*edx]
	mov		eax, [edi+4*eax]
	add		eax,edx
	mov		edx,0
	div		ebx
;Prints out the middle number
displayM:
	call		WriteDec
	call		Crlf
	call		Crlf
	pop		ebp
	ret		8

displayMedian ENDP

;Displays the array
displayList	PROC
	push		ebp
	mov		ebp,esp
	mov		edx,[ebp+8]					;output string
	call		WriteString
	call		Crlf
	mov		ecx,[ebp+12]					;loop count set to request
	mov		edi,[ebp+16]					;@array
;print out number and add a space
more:
	mov		eax,[edi]
	call		WriteDec
	mov		al,' '
	call		WriteChar
	add		edi,4
	
;adds newline every 10 outputs
	mov		edx, 0
	mov		eax,[ebp+12]
	inc		eax
	sub		eax, ecx					
	mov		ebx, OUTPUTLIMIT
	div		ebx							
	cmp		edx, 0						
	jg		skip							;adds a new line	
	call	Crlf		
		
skip:
	loop		more
	call		Crlf
	call		Crlf
	pop		ebp
	ret		8
displayList ENDP

END main