0x001b248c	1	PUSH EBP
0x001b248d	2	MOV EBP,ESP
0x001b248f	1	PUSH EBX
0x001b2490	3	MOV EBX,dword ptr [EBP + 0x8]
0x001b2493	6	MOV EDX,dword ptr [EBX + 0x168]
0x001b2499	7	MOV dword ptr [EDX + 0x44],0x1
0x001b24a0	2	PUSH 0x1
0x001b24a2	6	MOV ECX,dword ptr [0x001f998c]
0x001b24a8	1	PUSH ECX
0x001b24a9	1	PUSH EBX
0x001b24aa	5	CALL 0x001ce960
0x001b24af	6	MOV EDX,dword ptr [EBX + 0x1e4]
0x001b24b5	6	ADD EDX,dword ptr [EBX + 0x1f8]
0x001b24bb	6	MOV dword ptr [EBX + 0x1ec],EDX
0x001b24c1	6	MOV EDX,dword ptr [EBX + 0x1e8]
0x001b24c7	6	ADC EDX,dword ptr [EBX + 0x1fc]
0x001b24cd	6	MOV dword ptr [EBX + 0x1f0],EDX
0x001b24d3	6	MOV EDX,dword ptr [EBX + 0x1d4]
0x001b24d9	6	ADD EDX,dword ptr [EBX + 0x1f8]
0x001b24df	6	MOV dword ptr [EBX + 0x1dc],EDX
0x001b24e5	6	MOV EDX,dword ptr [EBX + 0x1d8]
0x001b24eb	6	ADC EDX,dword ptr [EBX + 0x1fc]
0x001b24f1	6	MOV dword ptr [EBX + 0x1e0],EDX
0x001b24f7	3	MOV EBX,dword ptr [EBP + -0x4]
0x001b24fa	2	MOV ESP,EBP
0x001b24fc	1	POP EBP
0x001b24fd	1	RET
