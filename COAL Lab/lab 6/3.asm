.386
.model flat,stdcall
.stack 4096

.data
	b1 dw 5
	p1 dw 6	

	b2 dw 4
	p2 dw 5
	b3 dw 8
	p3 dw 4
	sum dw ?
.code
main PROC
	mov eax,0
	mov ax,1
	mov cx,p1
	L1:	
		mul b1
		loop L1	
	mov eax,0

	mov eax,0
	mov ax,1
	mov cx,p2
	L2:	
		mul b2
		loop L2	
	mov sum,ax

	mov eax,0
	mov ax,1
	mov cx,p3
	L3:	
		mul b3
		loop L3	
	add sum,ax
	mov eax,0

main ENDP
end main
