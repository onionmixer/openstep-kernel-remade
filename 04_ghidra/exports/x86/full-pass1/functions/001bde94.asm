0x001bde94	1	PUSH EBP
0x001bde95	2	MOV EBP,ESP
0x001bde97	1	PUSH EDI
0x001bde98	1	PUSH ESI
0x001bde99	1	PUSH EBX
0x001bde9a	3	MOV EDX,dword ptr [EBP + 0x8]
0x001bde9d	3	MOV EAX,dword ptr [EBP + 0xc]
0x001bdea0	3	MOV EBX,dword ptr [EBP + 0x14]
0x001bdea3	3	MOV ESI,dword ptr [EBP + 0x18]
0x001bdea6	3	MOV EDI,dword ptr [EBP + 0x1c]
0x001bdea9	7	MOV dword ptr [EDX + 0x14],0x140
0x001bdeb0	7	MOV dword ptr [EDX + 0x4],0x30
0x001bdeb7	3	MOV dword ptr [EDX + 0x10],EAX
0x001bdeba	6	MOV ECX,dword ptr [0x001e53c8]
0x001bdec0	3	MOV dword ptr [EDX + 0x18],ECX
0x001bdec3	4	MOV AX,word ptr [EDX + 0x1a]
0x001bdec7	4	AND AX,0xf000
0x001bdecb	2	OR AL,0x5
0x001bdecd	4	MOV word ptr [EDX + 0x1a],AX
0x001bded1	3	MOV ECX,dword ptr [EBP + 0x10]
0x001bded4	3	MOV dword ptr [EDX + 0x1c],ECX
0x001bded7	3	MOV dword ptr [EDX + 0x20],EBX
0x001bdeda	3	MOV dword ptr [EDX + 0x24],ESI
0x001bdedd	3	MOV dword ptr [EDX + 0x28],EDI
0x001bdee0	3	MOV ECX,dword ptr [EBP + 0x20]
0x001bdee3	3	MOV dword ptr [EDX + 0x2c],ECX
0x001bdee6	3	LEA ESP,[EBP + -0xc]
0x001bdee9	1	POP EBX
0x001bdeea	1	POP ESI
0x001bdeeb	1	POP EDI
0x001bdeec	2	MOV ESP,EBP
0x001bdeee	1	POP EBP
0x001bdeef	1	RET
