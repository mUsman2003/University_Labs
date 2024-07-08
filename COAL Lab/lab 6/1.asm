.386
.model flat,stdcall
.stack 4096

.data
	v1 dw 10000111b	;135
	v2 dw 10000010b	;130

	v3 dw 0111111111111111b	;32767
	v4 dw 1000000000000000b	;32768

.code
main PROC
	mov ax,0

	mov ax,v1
	add ax,v2
	mov ax,0

	mov ax,v3
	add ax,v4
	mov ax,0

main ENDP
end main

