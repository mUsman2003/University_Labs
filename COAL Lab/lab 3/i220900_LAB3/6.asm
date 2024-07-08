.386
.model flat,stdcall
.stack 4096

.data 
var1 DW 48
var2 DW 143
var3 DW 32
var4 DW 57
score DW 0
avg DB 0


.code
main PROC
	
	mov ax,var1
	add ax,var2
	add ax,var3
	add ax,var4

	mov score,ax
	mov bl,4
	div bl
	mov avg,al
	

main ENDP
END main