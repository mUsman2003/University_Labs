.386
.model flat,stdcall
.stack 4096

.data
	n1 dd 2
	n2 dd 3

.code
main PROC
	mov ecx,0
	mov ecx,5
	mov eax,1
	L1:	mul n1
		add n1,2
		loop L1
	mov eax,0

	mov ecx,5
	mov eax,1
	L2:	mul n2
		add n2,4
		loop L2
	mov eax,0

main ENDP
end main

