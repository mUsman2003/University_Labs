.386
.model flat,stdcall
.stack 4096

.data
	v1 dw 00010011b	;19
	v2 dw 00011001b	;25

	v3 dw 01111101b	;125
	v4 dw 01111101b	;125

	v5 dw 10011011b	;155
	v6 dw 1110b		;14
.code
main PROC
	mov ax,0

	mov ax,v2
	sub ax,v1
	mov ax,0

	mov ax,v4
	sub ax,v3
	mov ax,0

	mov ax,v6
	sub ax,v5
	mov ax,0

main ENDP
end main

