.386
.model flat,stdcall
.stack 4096

.data 


.code
main PROC
	
	mov dx,0
	mov ax,128
	mov bl,25
	div bl
	

main ENDP
END main