0x001babbc	1	PUSH EBP
0x001babbd	2	MOV EBP,ESP
0x001babbf	3	SUB ESP,0x8
0x001babc2	1	PUSH EBX
0x001babc3	3	MOV EBX,dword ptr [EBP + 0x8]
0x001babc6	6	MOV EDX,dword ptr [0x001f921c]
0x001babcc	1	PUSH EDX
0x001babcd	3	MOV EDX,dword ptr [EBX + 0x8]
0x001babd0	1	PUSH EDX
0x001babd1	5	CALL 0x001ce960
0x001babd6	6	MOV EDX,dword ptr [0x001f921c]
0x001babdc	1	PUSH EDX
0x001babdd	3	MOV dword ptr [EBP + -0x8],EBX
0x001babe0	6	MOV EDX,dword ptr [0x001fa540]
0x001babe6	3	MOV dword ptr [EBP + -0x4],EDX
0x001babe9	3	LEA EAX,[EBP + -0x8]
0x001babec	1	PUSH EAX
0x001babed	5	CALL 0x001cea70
0x001babf2	3	MOV EBX,dword ptr [EBP + -0xc]
0x001babf5	2	MOV ESP,EBP
0x001babf7	1	POP EBP
0x001babf8	1	RET
