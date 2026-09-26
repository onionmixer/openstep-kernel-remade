0x0015beb4	1	PUSH EBP
0x0015beb5	2	MOV EBP,ESP
0x0015beb7	1	PUSH EBX
0x0015beb8	3	MOV ECX,dword ptr [EBP + 0xc]
0x0015bebb	4	CMP dword ptr [EBP + 0x8],0x0
0x0015bebf	2	JNZ 0x0015bec8
0x0015bec1	5	MOV EAX,0x16
0x0015bec6	2	JMP 0x0015bee3
0x0015bec8	6	MOV EDX,dword ptr [0x001dee50]
0x0015bece	1	NOP
0x0015becf	1	NOP
0x0015bed0	2	MOV EBX,dword ptr [EDX]
0x0015bed2	2	MOV dword ptr [ECX],EBX
0x0015bed4	3	MOV EBX,dword ptr [EDX + 0x4]
0x0015bed7	3	MOV dword ptr [ECX + 0x4],EBX
0x0015beda	3	MOV EAX,dword ptr [EDX + 0x8]
0x0015bedd	2	CMP dword ptr [ECX],EAX
0x0015bedf	2	JNZ 0x0015bed0
0x0015bee1	2	XOR EAX,EAX
0x0015bee3	3	MOV EBX,dword ptr [EBP + -0x4]
0x0015bee6	2	MOV ESP,EBP
0x0015bee8	1	POP EBP
0x0015bee9	1	RET
