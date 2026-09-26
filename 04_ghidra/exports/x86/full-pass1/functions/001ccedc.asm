0x001ccedc	1	PUSH EBP
0x001ccedd	2	MOV EBP,ESP
0x001ccedf	3	MOV EAX,dword ptr [EBP + 0x8]
0x001ccee2	3	MOV ECX,dword ptr [EBP + 0xc]
0x001ccee5	3	CMP dword ptr [EAX + 0x24],ECX
0x001ccee8	2	JNZ 0x001ccef4
0x001cceea	2	MOV ECX,dword ptr [ECX]
0x001cceec	3	MOV dword ptr [EAX + 0x24],ECX
0x001cceef	2	MOV ESP,EBP
0x001ccef1	1	POP EBP
0x001ccef2	1	RET
0x001ccef4	3	MOV EDX,dword ptr [EAX + 0x24]
0x001ccef7	2	MOV EAX,dword ptr [EDX]
0x001ccef9	2	TEST EAX,EAX
0x001ccefb	2	JZ 0x001ccf14
0x001ccefd	1	NOP
0x001ccefe	1	NOP
0x001cceff	1	NOP
0x001ccf00	2	CMP EAX,ECX
0x001ccf02	2	JNZ 0x001ccf0c
0x001ccf04	2	MOV EAX,dword ptr [EAX]
0x001ccf06	2	MOV dword ptr [EDX],EAX
0x001ccf08	2	MOV ESP,EBP
0x001ccf0a	1	POP EBP
0x001ccf0b	1	RET
0x001ccf0c	2	MOV EDX,EAX
0x001ccf0e	2	MOV EAX,dword ptr [EAX]
0x001ccf10	2	TEST EAX,EAX
0x001ccf12	2	JNZ 0x001ccf00
0x001ccf14	2	MOV ESP,EBP
0x001ccf16	1	POP EBP
0x001ccf17	1	RET
