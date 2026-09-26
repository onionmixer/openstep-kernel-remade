0x001bdcb8	1	PUSH EBP
0x001bdcb9	2	MOV EBP,ESP
0x001bdcbb	1	PUSH ESI
0x001bdcbc	1	PUSH EBX
0x001bdcbd	3	MOV EAX,dword ptr [EBP + 0x8]
0x001bdcc0	3	MOV EDX,dword ptr [EBP + 0xc]
0x001bdcc3	3	MOV ECX,dword ptr [EBP + 0x10]
0x001bdcc6	3	MOV EBX,dword ptr [EBP + 0x14]
0x001bdcc9	7	MOV dword ptr [EAX + 0x4],0x24
0x001bdcd0	7	MOV dword ptr [EAX + 0x14],0x12e
0x001bdcd7	3	MOV dword ptr [EAX + 0x10],EDX
0x001bdcda	6	MOV ESI,dword ptr [0x001e53c8]
0x001bdce0	3	MOV dword ptr [EAX + 0x18],ESI
0x001bdce3	3	MOV dword ptr [EAX + 0x1c],ECX
0x001bdce6	3	MOV dword ptr [EAX + 0x20],EBX
0x001bdce9	3	LEA ESP,[EBP + -0x8]
0x001bdcec	1	POP EBX
0x001bdced	1	POP ESI
0x001bdcee	2	MOV ESP,EBP
0x001bdcf0	1	POP EBP
0x001bdcf1	1	RET
