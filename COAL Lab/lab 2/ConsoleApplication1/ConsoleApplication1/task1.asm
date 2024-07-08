.386						;32 processor 
.model flat,stdcall			;telling about model
.stack 4096					;storage allocation

.code
main PROC					;start of code
;--------------------------- Q1 --------------------------;
	mov ax,4
	mov bx,5
	add ax,bx

	mov ax,6
	mov bx,9
	add ax,bx

	mov ax,149
	mov bx,200	
	add ax,bx

	mov ax,302
	mov bx,150
	add ax,bx

	mov ax,3050
	mov bx,4150
	add ax,bx
;--------------------------- Q2 --------------------------;
	mov ax,34
	mov bx,16
	sub ax,bx

	mov ax,40
	mov bx,29
	sub ax,bx

	mov ax,50
	mov bx,30
	sub ax,bx

	mov ax,84
	mov bx,44
	sub ax,bx
	
	mov ax,891
	mov bx,200
	sub ax,bx
;--------------------------- Q3 --------------------------;
	mov ax,100
	mov bx,50
	mov cx,40
	sub cx,bx
	add cx,ax
	
	mov ax,80
	mov bx,45
	mov cx,25
	add ax,bx
	sub ax,cx

	mov ax,400
	mov bx,50
	mov cx,40
	sub ax,cx
	sub bx,ax

	mov ax,300
	mov bx,12
	mov cx,25
	sub bx,cx
	add ax,bx
;--------------------------- Q4 --------------------------;
	mov ax,10
	mov bx,20
	mov cx,140
	add ax,bx
	sub cx,ax
	mov dx,cx

	mov ax,80
	mov bx,45
	mov cx,25
	add bx,cx
	sub ax,bx
	mov dx,ax

	mov ax,400
	mov bx,50
	mov cx,40
	sub bx,ax
	add bx,cx
	mov dx,bx

	mov ax,300
	mov bx,12
	mov cx,25
	add ax,bx
	sub ax,cx
	mov dx,ax
;--------------------------- Q5 --------------------------;
	mov ax,100
	mov bx,50
	mov cx,ax
	mov dx,bx

	add ax,ax
	add ax,ax
	add ax,cx

	add bx,bx
	add bx,dx

	add ax,bx

	mov ax,80
	mov bx,45

	add ax,ax
	add ax,ax

	add bx,bx

	add ax,bx

	mov ax,400
	mov bx,50
	mov cx,ax

	add ax,ax
	add ax,ax
	add cx,cx
	add ax,cx

	sub ax,bx

	mov ax,300
	mov bx,12
	mov cx,ax

	add ax,ax
	add ax,cx

	add bx,bx

	sub ax,bx
;--------------------------- Q6 --------------------------;
	mov bx,20
	mov cx,140
	mov ax,cx
	
	add cx,cx
	add cx,ax

	add bx,bx

	sub cx,bx

	mov bx,45
	mov cx,25

	add bx,bx

	sub cx,bx

	mov bx,50
	mov cx,40
	
	add cx,cx
	add cx,bx

	mov bx,12
	mov cx,25
	mov ax,bx

	add bx,bx
	add bx,ax

	add cx,cx
	add cx,cx

	sub cx,bx

;--------------------------- Q7 --------------------------;
	mov ax,125
	mov bx,45
	mov cx,40

	mov dx,ax
	add ax,ax
	add ax,ax
	add ax,dx

	add bx,bx
	add bx,bx

	add ax,bx
	sub ax,cx

	mov ax,150
	mov bx,155
	mov cx,45

	mov dx,cx
	add cx,cx
	add cx,dx

	add ax,ax
	add ax,ax

	add bx,bx

	add ax,bx
	add ax,cx

	mov ax,50
	mov bx,400
	mov cx,60

	mov dx,ax
	add dx,dx
	add ax,ax
	add ax,ax
	add ax,dx

	mov dx,cx
	add cx,cx
	add cx,dx

	add ax,cx
	sub ax,bx

	mov ax,600
	mov bx,120
	mov cx,40

	mov dx,ax
	add ax,ax
	add ax,dx

	add bx,bx

	add cx,cx
	add cx,cx

	sub ax,bx
	add ax,cx

	mov ax,0
	mov bx,0
	mov cx,0
	mov dx,0


main ENDP					;end of code
end main					;end of code life

