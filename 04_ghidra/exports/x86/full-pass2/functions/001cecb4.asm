0x001cecb4	1	PUSH EBP
0x001cecb5	2	MOV EBP,ESP
0x001cecb7	1	PUSH EBX
0x001cecb8	3	MOV EAX,dword ptr [EBP + 0xc]
0x001cecbb	3	MOV EDX,dword ptr [EBP + 0x10]
0x001cecbe	2	XOR EBX,EBX
0x001cecc0	3	MOV ECX,dword ptr [EAX + 0x8]
0x001cecc3	3	MOV EDX,dword ptr [EDX + 0x8]
0x001cecc6	2	MOV AL,byte ptr [ECX]
0x001cecc8	2	CMP byte ptr [EDX],AL
0x001cecca	2	JNZ 0x001cecdc
0x001ceccc	1	PUSH EDX
0x001ceccd	1	PUSH ECX
0x001cecce	5	CALL 0x00101e7c
0x001cecd3	2	TEST EAX,EAX
0x001cecd5	2	JNZ 0x001cecdc
0x001cecd7	5	MOV EBX,0x1
0x001cecdc	2	MOV EAX,EBX
0x001cecde	3	MOV EBX,dword ptr [EBP + -0x4]
0x001cece1	2	MOV ESP,EBP
0x001cece3	1	POP EBP
0x001cece4	1	RET
