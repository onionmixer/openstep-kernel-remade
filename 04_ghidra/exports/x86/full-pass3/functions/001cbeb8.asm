0x001cbeb8	1	PUSH EBP
0x001cbeb9	2	MOV EBP,ESP
0x001cbebb	3	SUB ESP,0x4
0x001cbebe	1	PUSH EDI
0x001cbebf	3	MOV EDX,dword ptr [EBP + 0xc]
0x001cbec2	3	MOV EAX,dword ptr [EBP + 0x8]
0x001cbec5	1	PUSH EAX
0x001cbec6	2	XOR CL,CL
0x001cbec8	3	MOV EDI,dword ptr [EBP + 0x8]
0x001cbecb	2	MOV AL,CL
0x001cbecd	1	CLD
0x001cbece	5	MOV ECX,0xffffffff
0x001cbed3	2	SCASB.REPNE ES:EDI
0x001cbed5	2	NOT ECX
0x001cbed7	3	MOV dword ptr [EBP + -0x4],ECX
0x001cbeda	1	PUSH ECX
0x001cbedb	1	PUSH EDX
0x001cbedc	3	MOV EDX,dword ptr [EDX + 0x4]
0x001cbedf	3	MOV dword ptr [EBP + -0x4],EDX
0x001cbee2	2	CALL EDX
0x001cbee4	3	ADD ESP,0x8
0x001cbee7	2	MOV EDX,EAX
0x001cbee9	1	PUSH EDX
0x001cbeea	5	CALL 0x00101b48
0x001cbeef	2	MOV EDX,EAX
0x001cbef1	3	MOV EDI,dword ptr [EBP + -0x8]
0x001cbef4	2	MOV ESP,EBP
0x001cbef6	1	POP EBP
0x001cbef7	1	RET
