.386
.model flat,stdcall
.stack 4096

.data
	
	num dw 6
	Prime db 0
.code
main PROC
	mov esi,offset num
	mov eax,0
	mov ecx,0
	mov ebx,0
	mov cx,num
	l1:	mov ax,num
		dec ecx
		cmp ebx,ecx
		je l2

		div cl
		cmp ah,0
		je l3

		loop l1

		l2:	mov ebx,"P"
			mov Prime,bl
			jmp l4
		l3: mov ebx,"N"
			mov Prime,bl
		l4: mov eax,0

main ENDP
end main

