0x001caf40	1	PUSH EBP
0x001caf41	2	MOV EBP,ESP
0x001caf43	1	PUSH EBX
0x001caf44	3	MOV EDX,dword ptr [EBP + 0xc]
0x001caf47	3	MOV ECX,dword ptr [EBP + 0x10]
0x001caf4a	2	XOR EBX,EBX
0x001caf4c	2	MOV EAX,dword ptr [EDX]
0x001caf4e	2	CMP dword ptr [ECX],EAX
0x001caf50	2	JNZ 0x001caf6b
0x001caf52	3	MOV EAX,dword ptr [EDX + 0x4]
0x001caf55	3	CMP dword ptr [ECX + 0x4],EAX
0x001caf58	2	JNZ 0x001caf6b
0x001caf5a	3	MOV EAX,dword ptr [EDX + 0x8]
0x001caf5d	3	CMP dword ptr [ECX + 0x8],EAX
0x001caf60	2	JNZ 0x001caf6b
0x001caf62	3	MOV EAX,dword ptr [EDX + 0xc]
0x001caf65	3	CMP dword ptr [ECX + 0xc],EAX
0x001caf68	2	JNZ 0x001caf6b
0x001caf6a	1	INC EBX
0x001caf6b	2	MOV EAX,EBX
0x001caf6d	3	MOV EBX,dword ptr [EBP + -0x4]
0x001caf70	2	MOV ESP,EBP
0x001caf72	1	POP EBP
0x001caf73	1	RET
