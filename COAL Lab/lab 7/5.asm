.386
.model flat,stdcall
.stack 4096

.data
	
	educationLevel db 2
	yearsOfExperience db 1
	RelevantCertification db 1
	ProgrammingSkills db 1	

	result db 100 dup(0)
	
.code
main PROC
		
	mov esi,offset result

	mov al,educationLevel
	mov bl,yearsOfExperience
	mov cl,RelevantCertification
	mov dl,ProgrammingSkills

	;	for senior SE
	cmp al,3
	jae E1
	jmp S1
	E1:	cmp bl,5
		jae C1
		jmp S1
		C1: cmp cl,1
			jae P1
			jmp S1
			P1: cmp dl,1
				jae Senior
				jmp S1
				Senior:	mov esi,'S'
				    	jmp Exit
	;	for software engineer
	S1:
		cmp al,2
		jae E2
		jmp J1
		E2:	cmp bl,3
			jae P2
			jmp J1
			P2:cmp dl,1
				jae Engineer
				jmp J1
				Engineer:	mov esi,'P'
							jmp Exit
	;	for Juniors
	J1:
		cmp al,2
		jae E3
		jmp N1
		E3:	cmp bl,2
			jae Junior
			jmp N1
			Junior: mov esi,'J'
					jmp Exit
	N1:	
		mov esi,'N'
		jmp Exit

	Exit:
		mov eax,0

main ENDP
end main

