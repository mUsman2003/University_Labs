.386
.model flat,stdcall
.stack 4096

.data 

	classroom_1_weight_1 DW 1
	classroom_1_weight_2 DW 2
	classroom_1_weight_3 DW 3
	classroom_1_weight_4 DW 4
	classroom_1_weight_5 DW 5

	sumweight_1 DW 0
	productweight_1 DW 0

	classroom_2_weight_1 DW 2
	classroom_2_weight_2 DW 4
	classroom_2_weight_3 DW 6
	classroom_2_weight_4 DW 8
	classroom_2_weight_5 DW 10

	sumweight_2 DW 0
	productweight_2 DW 0

.code
main PROC
	
	mov ax,classroom_1_weight_1
	add ax,classroom_1_weight_2
	add ax,classroom_1_weight_3
	add ax,classroom_1_weight_4
	add ax,classroom_1_weight_5
	mov sumweight_1,ax

	mov ax,0
	mov ax,classroom_1_weight_1
	mul classroom_1_weight_2
	mul classroom_1_weight_3
	mul classroom_1_weight_4
	mul classroom_1_weight_5
	mov productweight_1,ax

	mov ax,0
	mov ax,classroom_2_weight_1
	add ax,classroom_2_weight_2
	add ax,classroom_2_weight_3
	add ax,classroom_2_weight_4
	add ax,classroom_2_weight_5
	mov sumweight_2,ax

	mov ax,0
	mov ax,classroom_2_weight_1
	mul classroom_2_weight_2
	mul classroom_2_weight_3
	mul classroom_2_weight_4
	mul classroom_2_weight_5
	mov productweight_2,ax



	

main ENDP
END main