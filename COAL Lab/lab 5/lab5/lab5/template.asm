.386
.model flat,stdcall
.stack 4096

.data
	base dw 3
	power dw 9	; roll no 0900
.code
main PROC
	mov eax,3
	mov ecx,0
	mov cx,power
	mov bx,base
	mov dx,base
	L1:	
		mul bx
		loop L1	

main ENDP
end main

