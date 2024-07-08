.386
.model flat,stdcall
.stack 4096

.data
	arr dw 1,2,3,4,5
.code
main PROC
	mov edi,offset arr

	mov ecx,0
	mov ecx,5
	mov eax,0
	mov edx,0
    
	mov esi,offset arr
	L1:	
		add ax,[esi+edx]
		add edx,2	
		loop L1
	mov eax,0

main ENDP
end main