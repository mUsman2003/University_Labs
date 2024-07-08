.386
.model flat,stdcall
.stack 4096

.data
	array db 50 dup(1)

.code
main PROC
	mov esi,offset array
	mov eax,1
	mov ebx,0
	mov ecx,50

	l1:	
		test eax,1
		jnz l2
		jmp l3
		l2:
			mov [esi+ebx],eax
			inc ebx
		l3:
			inc eax
			inc eax

		loop l1	

	mov eax,0

main ENDP
end main

