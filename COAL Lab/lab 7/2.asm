.386
.model flat,stdcall
.stack 4096

.data
	array db 0,1,2,3,4,5,6,7,8,9
	num1 db 2
	num2 db 5
	var db 2 dup(0)

.code
main PROC

	mov esi,offset array
	mov ecx,10
	mov eax,0
	mov ebx,0

	l1:	mov ebx,[esi+eax]
		cmp bl,num1			;loop1 start
		je l2				;true
		inc eax
		loop l1						;loop1 end

		jmp l3				;for fail
		
		l2:	mov ecx,10
			mov eax,0

			l4:	mov ebx,[esi+eax]
				cmp bl,num2	;loop2 start
				je Found
				inc eax
				loop l4				;loop2 end

				jmp l3

				Found:	mov esi,offset array
						mov eax,0
						mov ebx,46h
						mov [esi+eax],ebx
						inc eax
						mov ebx,0
						mov [esi+eax],ebx
						jmp l5					

		l3:	mov esi,offset array
			mov eax,0
			mov ebx,4eh
			mov [esi+eax],ebx
			inc eax
			mov ebx,46h
			mov [esi+1],ebx

		l5:	mov eax,0

main ENDP
end main

