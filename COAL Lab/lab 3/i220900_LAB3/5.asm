.386
.model flat,stdcall
.stack 4096

.data 


.code
main PROC
	
	mov dx,0
	mov ax,0c8h
	mov bl,21h
	div bl
	

main ENDP
END main