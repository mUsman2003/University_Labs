.386
.model flat,stdcall
.stack 4096

.data 

	classroom_1_height_1 DW 1
	classroom_1_height_2 DW 2
	classroom_1_height_3 DW 3
	classroom_1_height_4 DW 4
	classroom_1_height_5 DW 5

	sumheight_1 DW 0
	productheight_1 DW 0

	classroom_2_height_1 DW 2
	classroom_2_height_2 DW 4
	classroom_2_height_3 DW 6
	classroom_2_height_4 DW 8
	classroom_2_height_5 DW 10

	sumheight_2 DW 0
	productheight_2 DW 0

.code
main PROC
	
	mov ax,classroom_1_height_1
	add ax,classroom_1_height_2
	add ax,classroom_1_height_3
	add ax,classroom_1_height_4
	add ax,classroom_1_height_5
	mov sumheight_1,ax

	mov ax,0
	mov ax,classroom_1_height_1
	mul classroom_1_height_2
	mul classroom_1_height_3
	mul classroom_1_height_4
	mul classroom_1_height_5
	mov productheight_1,ax

	mov ax,0
	mov ax,classroom_2_height_1
	add ax,classroom_2_height_2
	add ax,classroom_2_height_3
	add ax,classroom_2_height_4
	add ax,classroom_2_height_5
	mov sumheight_2,ax

	mov ax,0
	mov ax,classroom_2_height_1
	mul classroom_2_height_2
	mul classroom_2_height_3
	mul classroom_2_height_4
	mul classroom_2_height_5
	mov productheight_2,ax



	

main ENDP
END main