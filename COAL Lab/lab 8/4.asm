;	Q4). Bit Masking
;	Muhammad Usman
;	22i-0900
;	CS-D

;Objective: Given the hexadecimal word 8575h, extract specific values using bitwise masking:
;5 in AL, 75 in AH, 0575 in BX, and 8505 in CX.

.386
.model flat,stdcall
.stack 4096

.data
	
	num dw 8575h

.code
main PROC

	mov eax,0
	mov ebx,0
	mov ecx,0

	mov ax,num
	AND ax,0000111111111111b	;	for bx
	mov bx,ax
	mov ax,num

	AND ax,1111111100001111b	;	for cx
	mov cx,ax

	mov ax,num
	AND ax,0000000000001111b	;   for al

	mov eax,0

main ENDP
end main

