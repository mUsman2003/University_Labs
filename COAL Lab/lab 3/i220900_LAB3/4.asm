.386
.model flat,stdcall
.stack 4096

.data 


.code
main PROC
	
	mov dx,0
	mov ax,0abh
	mov bl,14h
	div bl
	

main ENDP
END main