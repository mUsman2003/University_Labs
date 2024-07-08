.386
.model flat,stdcall
.stack 4096

.data
	array db 2,5,4
	num db 0


.code
main PROC

	mov esi,offset array
	mov ecx,lengthof array
	dec ecx
	mov ebx,[esi+ecx]
	mov num,bl
	dec ecx
	l1:	mov ebx,[esi+ecx]
		cmp bl,num
		ja l2
		loop l1

		jmp l3

		l2: mov ebx,[esi+ecx]
			mov num,bl

		l3:	mov eax,0
	

main ENDP
end main

