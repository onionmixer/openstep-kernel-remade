0x001cce94	1	PUSH EBP
0x001cce95	2	MOV EBP,ESP
0x001cce97	1	PUSH EBX
0x001cce98	3	MOV EBX,dword ptr [EBP + 0x8]
0x001cce9b	3	MOV ECX,dword ptr [EBP + 0xc]
0x001cce9e	3	CMP dword ptr [EBX + 0x1c],ECX
0x001ccea1	2	JNZ 0x001cceac
0x001ccea3	2	MOV ECX,dword ptr [ECX]
0x001ccea5	3	MOV dword ptr [EBX + 0x1c],ECX
0x001ccea8	2	JMP 0x001ccecc
0x001cceac	3	MOV EDX,dword ptr [EBX + 0x1c]
0x001cceaf	2	MOV EAX,dword ptr [EDX]
0x001cceb1	2	TEST EAX,EAX
0x001cceb3	2	JZ 0x001ccecc
0x001cceb5	1	NOP
0x001cceb6	1	NOP
0x001cceb7	1	NOP
0x001cceb8	2	CMP EAX,ECX
0x001cceba	2	JNZ 0x001ccec4
0x001ccebc	2	MOV EAX,dword ptr [EAX]
0x001ccebe	2	MOV dword ptr [EDX],EAX
0x001ccec0	2	JMP 0x001ccecc
0x001ccec4	2	MOV EDX,EAX
0x001ccec6	2	MOV EAX,dword ptr [EAX]
0x001ccec8	2	TEST EAX,EAX
0x001cceca	2	JNZ 0x001cceb8
0x001ccecc	2	PUSH 0x0
0x001ccece	1	PUSH EBX
0x001ccecf	5	CALL 0x001ccda0
0x001cced4	3	MOV EBX,dword ptr [EBP + -0x4]
0x001cced7	2	MOV ESP,EBP
0x001cced9	1	POP EBP
0x001cceda	1	RET
