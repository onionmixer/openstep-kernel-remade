0x0012dbdc	1	PUSH EBP
0x0012dbdd	2	MOV EBP,ESP
0x0012dbdf	1	PUSH ESI
0x0012dbe0	1	PUSH EBX
0x0012dbe1	3	MOV ESI,dword ptr [EBP + 0x8]
0x0012dbe4	3	MOV EBX,dword ptr [EBP + 0xc]
0x0012dbe7	1	PUSH EBX
0x0012dbe8	5	CALL 0x0011ea88
0x0012dbed	3	MOV AX,word ptr [ESI]
0x0012dbf0	4	MOV word ptr [EBX + 0x4],AX
0x0012dbf4	4	MOV AX,word ptr [ESI + 0x4]
0x0012dbf8	4	MOV word ptr [EBX + 0x6],AX
0x0012dbfc	4	MOV AX,word ptr [ESI + 0x8]
0x0012dc00	4	MOV word ptr [EBX + 0x8],AX
0x0012dc04	3	MOV EAX,dword ptr [ESI + 0xc]
0x0012dc07	3	MOV dword ptr [EBX + 0x18],EAX
0x0012dc0a	3	MOV EAX,dword ptr [ESI + 0x10]
0x0012dc0d	3	MOV dword ptr [EBX + 0x20],EAX
0x0012dc10	3	MOV EAX,dword ptr [ESI + 0x14]
0x0012dc13	3	MOV dword ptr [EBX + 0x24],EAX
0x0012dc16	3	MOV EAX,dword ptr [ESI + 0x18]
0x0012dc19	3	MOV dword ptr [EBX + 0x28],EAX
0x0012dc1c	3	MOV ESI,dword ptr [ESI + 0x1c]
0x0012dc1f	3	MOV dword ptr [EBX + 0x2c],ESI
0x0012dc22	3	LEA ESP,[EBP + -0x8]
0x0012dc25	1	POP EBX
0x0012dc26	1	POP ESI
0x0012dc27	2	MOV ESP,EBP
0x0012dc29	1	POP EBP
0x0012dc2a	1	RET
