;	Q2). 2nd largest and 2nd small
;	Muhammad Usman
;	22i-0900
;	CS-D


.386
.model flat,stdcall
.stack 4096

.data
	
	arr db 1,2,3,4,5,6,7,8,9,10
	big1 db ?
	tiny1 db ?
	big2 db ?
	tiny2 db ?

.code
main PROC

	lea esi,arr					;	offset

	mov eax,0
	mov ebx,0
	mov ecx,0
	mov ecx,lengthof arr		;	size of array
	mov eax,[esi]
	mov edx,[esi+1]

	;--------------------------for largest and smallest------------------------------;
	mov big1,al
	mov tiny1,al
	

	l1:	mov ebx,[esi]
		cmp bl,big1
		jae larger
		jmp l2
		larger:	mov big1,bl				;if number in esi greater than previous tiny1 vale then replace with new value esi value
				l2: cmp bl,tiny1
					jb smaller
					jmp l3
					smaller: mov tiny1,bl
					l3:	inc esi
						loop l1

	;--------------------------for 2nd largest and smallest------------------------------;

	lea esi,arr					;	offset
	mov eax,0
	mov ebx,0
	mov ecx,0
	mov ecx,lengthof arr		;	size of array

	mov big2,dl
	mov tiny2,dl

	l4:	mov ebx,[esi]
		cmp bl,big1
		jz l5
		cmp bl,big2
		ja secoundlarge
		jmp l5
		secoundlarge:	mov big2,bl	
						cmp bl,tiny1
						jz l6
						l5:	cmp bl,tiny1
							jz l6 
							cmp bl,tiny2
							jb secoundsamller
							jmp l6
							secoundsamller: mov tiny2,bl
							l6:	inc esi
								loop l4


	mov ax,0

main ENDP
end main

