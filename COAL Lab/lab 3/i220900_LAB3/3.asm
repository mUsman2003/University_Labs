.386
.model flat,stdcall
.stack 4096

.data 


.code
main PROC
	
	mov dx,0
	mov ax,101000b
	mov bl,111b
	div bl
	

main ENDP
END main