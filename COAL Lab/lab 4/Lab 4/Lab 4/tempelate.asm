.386
.model flat, stdcall
.stack 4096

.data
    arr DD 12345678h
    var DB ?
    var2 byte 12h


.code
    main PROC

    mov EAX, arr
    mov var, AL

    mov AX,0
    mov BL,var
    mov AL,var2
    MUL BL

main ENDP
end main