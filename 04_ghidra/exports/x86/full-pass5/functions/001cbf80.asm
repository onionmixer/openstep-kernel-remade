0x001cbf80	1	PUSH EBP
0x001cbf81	2	MOV EBP,ESP
0x001cbf83	1	PUSH EBX
0x001cbf84	3	MOV EDX,dword ptr [EBP + 0xc]
0x001cbf87	3	MOV ECX,dword ptr [EBP + 0x10]
0x001cbf8a	2	XOR EBX,EBX
0x001cbf8c	2	MOV EAX,dword ptr [EDX]
0x001cbf8e	2	CMP dword ptr [ECX],EAX
0x001cbf90	2	JNZ 0x001cbfab
0x001cbf92	3	MOV EAX,dword ptr [EDX + 0x4]
0x001cbf95	3	CMP dword ptr [ECX + 0x4],EAX
0x001cbf98	2	JNZ 0x001cbfab
0x001cbf9a	3	MOV EAX,dword ptr [EDX + 0x8]
0x001cbf9d	3	CMP dword ptr [ECX + 0x8],EAX
0x001cbfa0	2	JNZ 0x001cbfab
0x001cbfa2	3	MOV EAX,dword ptr [EDX + 0xc]
0x001cbfa5	3	CMP dword ptr [ECX + 0xc],EAX
0x001cbfa8	2	JNZ 0x001cbfab
0x001cbfaa	1	INC EBX
0x001cbfab	2	MOV EAX,EBX
0x001cbfad	3	MOV EBX,dword ptr [EBP + -0x4]
0x001cbfb0	2	MOV ESP,EBP
0x001cbfb2	1	POP EBP
0x001cbfb3	1	RET
