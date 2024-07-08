;   Q1). Prime or not
;	Muhammad Usman
;	22i-0900
;	CS-D


.386
.model flat,stdcall
.stack 4096

.data
	
	num dw 11
	Prime db 0
.code
main PROC

	mov esi,offset num

	mov eax,0
	mov ecx,0
	mov ebx,0
	mov cx,num		; num of times the loop should run

	l1:	mov ax,num
		dec ecx		; we need to divid the counter less than the given number bcz it will prove division 
		cmp ebx,ecx
		je l2		; if the reminder is not zero till counter reaches zero then it will store P in memory indicating its a prime number

		div cl
		cmp ah,0
		je l3		; if the reminder is zero before counter reaches zero then it will store NP in memory indicating its Not a prime number

		loop l1

		l2:	mov ebx,"P"
			mov Prime,bl
			jmp l4
		l3: mov ebx,"N"
			mov Prime,bl

		l4: mov eax,0

main ENDP
end main

