0x001cce5c	1	PUSH EBP
0x001cce5d	2	MOV EBP,ESP
0x001cce5f	3	MOV EAX,dword ptr [EBP + 0x8]
0x001cce62	3	MOV EDX,dword ptr [EBP + 0xc]
0x001cce65	3	MOV ECX,dword ptr [EAX + 0x1c]
0x001cce68	2	MOV dword ptr [EDX],ECX
0x001cce6a	3	MOV dword ptr [EAX + 0x1c],EDX
0x001cce6d	2	PUSH 0x0
0x001cce6f	1	PUSH EAX
0x001cce70	5	CALL 0x001ccda0
0x001cce75	2	MOV ESP,EBP
0x001cce77	1	POP EBP
0x001cce78	1	RET
