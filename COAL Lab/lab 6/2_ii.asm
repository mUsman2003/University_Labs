.386
.model flat,stdcall
.stack 4096

.data
	arr dd 11 dup(?)

.code
main PROC
	mov edi,offset arr

	mov ecx,0
	mov ecx,11
	mov eax,0
	mov esi,offset arr

	L1:	mov [esi+eax],eax
		inc eax
		inc eax
		loop L1

main ENDP
end main

