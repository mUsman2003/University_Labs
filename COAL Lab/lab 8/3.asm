;	Q3). Loop through the array and isolate the negative elements.
;	Muhammad Usman
;	22i-0900
;	CS-D


.386
.model flat,stdcall
.stack 4096

.data
	
	arr db 132,43,56,178,219,2,36,98,12,22
	negarr db 10 dup(?)

.code
main PROC

	lea esi,arr
	lea edi,negarr
	mov ecx,lengthof arr
	mov eax,0

	l1:	mov al,[esi]
		Test al,10000000b			;checking if msb is 1
		jnz Neg1
		jmp l2
		Neg1:	mov [edi],al		;mov value to negarr
				inc edi
				l2:	inc esi
					loop l1
					

	mov eax,0

main ENDP
end main

