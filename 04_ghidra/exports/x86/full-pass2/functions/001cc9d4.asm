0x001cc9d4	1	PUSH EBP
0x001cc9d5	2	MOV EBP,ESP
0x001cc9d7	1	PUSH EDI
0x001cc9d8	1	PUSH ESI
0x001cc9d9	1	PUSH EBX
0x001cc9da	3	MOV EAX,dword ptr [EBP + 0x8]
0x001cc9dd	3	MOV EDX,dword ptr [EBP + 0xc]
0x001cc9e0	3	MOV EBX,dword ptr [EBP + 0x10]
0x001cc9e3	3	MOV ESI,dword ptr [EBP + 0x14]
0x001cc9e6	3	MOV ECX,dword ptr [EAX + 0xc]
0x001cc9e9	2	JMP 0x001cca0c
0x001cc9ec	2	MOV EDI,dword ptr [EDX]
0x001cc9ee	7	LEA EAX,[EDI*0x8 + 0x0]
0x001cc9f5	2	ADD EAX,ECX
0x001cc9f7	3	CMP dword ptr [EAX],-0x1
0x001cc9fa	2	JZ 0x001cca0c
0x001cc9fc	2	MOV EDI,dword ptr [EAX]
0x001cc9fe	2	MOV dword ptr [EBX],EDI
0x001cca00	3	MOV EAX,dword ptr [EAX + 0x4]
0x001cca03	2	MOV dword ptr [ESI],EAX
0x001cca05	5	MOV EAX,0x1
0x001cca0a	2	JMP 0x001cca15
0x001cca0c	2	DEC dword ptr [EDX]
0x001cca0e	3	CMP dword ptr [EDX],-0x1
0x001cca11	2	JNZ 0x001cc9ec
0x001cca13	2	XOR EAX,EAX
0x001cca15	3	LEA ESP,[EBP + -0xc]
0x001cca18	1	POP EBX
0x001cca19	1	POP ESI
0x001cca1a	1	POP EDI
0x001cca1b	2	MOV ESP,EBP
0x001cca1d	1	POP EBP
0x001cca1e	1	RET
