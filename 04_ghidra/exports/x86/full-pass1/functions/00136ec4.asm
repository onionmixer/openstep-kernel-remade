0x00136ec4	1	PUSH EBP
0x00136ec5	2	MOV EBP,ESP
0x00136ec7	3	SUB ESP,0x30
0x00136eca	1	PUSH EBX
0x00136ecb	3	MOV EDX,dword ptr [EBP + 0x8]
0x00136ece	3	MOV ECX,dword ptr [EBP + 0xc]
0x00136ed1	3	MOV EAX,dword ptr [EBP + 0x10]
0x00136ed4	7	MOV dword ptr [EBP + -0x2c],0x1
0x00136edb	7	MOV dword ptr [EBP + -0x28],0x0
0x00136ee2	3	MOV EBX,dword ptr [EDX + 0x20]
0x00136ee5	3	MOV dword ptr [EBP + -0x24],EBX
0x00136ee8	3	MOV EBX,dword ptr [EDX + 0x24]
0x00136eeb	3	MOV dword ptr [EBP + -0x20],EBX
0x00136eee	3	MOV EBX,dword ptr [EDX + 0x28]
0x00136ef1	3	MOV dword ptr [EBP + -0x1c],EBX
0x00136ef4	7	MOV dword ptr [EBP + -0x18],0x0
0x00136efb	3	MOV dword ptr [EBP + -0x14],EAX
0x00136efe	3	MOV dword ptr [EBP + -0x10],ECX
0x00136f01	3	MOV ECX,dword ptr [EDX + 0x8]
0x00136f04	3	LEA EAX,[EBP + -0x30]
0x00136f07	1	PUSH EAX
0x00136f08	1	PUSH EDX
0x00136f09	3	MOV EAX,dword ptr [ECX + 0xc]
0x00136f0c	2	CALL EAX
0x00136f0e	3	MOV EBX,dword ptr [EBP + -0x34]
0x00136f11	2	MOV ESP,EBP
0x00136f13	1	POP EBP
0x00136f14	1	RET
