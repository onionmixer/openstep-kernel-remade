0x001aaf84	1	PUSH EBP
0x001aaf85	2	MOV EBP,ESP
0x001aaf87	3	SUB ESP,0x8
0x001aaf8a	1	PUSH EBX
0x001aaf8b	3	MOV EBX,dword ptr [EBP + 0x8]
0x001aaf8e	6	MOV EDX,dword ptr [0x001f921c]
0x001aaf94	1	PUSH EDX
0x001aaf95	3	MOV EDX,dword ptr [EBX + 0x8]
0x001aaf98	1	PUSH EDX
0x001aaf99	5	CALL 0x001ce960
0x001aaf9e	3	MOV EDX,dword ptr [EBX + 0x4]
0x001aafa1	1	PUSH EDX
0x001aafa2	5	CALL 0x0015a614
0x001aafa7	6	MOV EDX,dword ptr [0x001f921c]
0x001aafad	1	PUSH EDX
0x001aafae	3	MOV dword ptr [EBP + -0x8],EBX
0x001aafb1	6	MOV EDX,dword ptr [0x001fa338]
0x001aafb7	3	MOV dword ptr [EBP + -0x4],EDX
0x001aafba	3	LEA EAX,[EBP + -0x8]
0x001aafbd	1	PUSH EAX
0x001aafbe	5	CALL 0x001cea70
0x001aafc3	3	MOV EBX,dword ptr [EBP + -0xc]
0x001aafc6	2	MOV ESP,EBP
0x001aafc8	1	POP EBP
0x001aafc9	1	RET
