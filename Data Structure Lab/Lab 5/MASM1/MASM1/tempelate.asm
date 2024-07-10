.386
.model flat,stdcall
.stack 4096

.data
  
     valb_1 BYTE 'FN1'
	valb_2 BYTE  0
	valb_3 DB  255			
	valb_3a DB  256		
	valb_4 BYTE -128
	valb_4a BYTE -129		
	valb_4b SBYTE -129			 
	valb_5 BYTE +127
	valb1_6 SBYTE -128
	valb1_7 SBYTE +127     
	valb1_8 SBYTE -2h
     valb_9 SBYTE 'FN2'
.code

main Proc
      mov edi,Offset valb_1 
	 mov al,valb_1 		
main ENDP
END main
