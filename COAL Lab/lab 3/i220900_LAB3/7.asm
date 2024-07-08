.386
.model flat,stdcall
.stack 4096

.data 
var1 DW 10
var2 DW 14
var3 DW 12
var4 DW 15

var5 DB 3
var6 DB 5
var7 DB 4
var8 DB 7

score DW 0
balls DW 0
str1 dw 0
str2 dw 0
str3 dw 0
str4 dw 0


.code
main PROC
	
	mov ax,var1
	mov bl,var5
	mov score,ax
	div bl 
	mov cl,100
	mul cl
	mov str1,ax

	mov ax,var2
	mov bl,var6
	mov score,ax
	div bl
	mov cl,100
	mul cl
	mov str2,ax

	mov ax,var3
	mov bl,var7
	mov score,ax
	div bl
	mov cl,100
	mul cl
	mov str3,ax

	mov ax,var4
	mov bl,var8
	mov score,ax
	div bl
	mov cl,100
	mul cl
	mov str4,ax


	

main ENDP
END main