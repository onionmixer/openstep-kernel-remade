0x001cea70	5	MOV EAX,[0x001e5604]
0x001cea75	2	AND EAX,EAX
0x001cea77	6	JZ 0x001ceb00
0x001cea7d	4	MOV EAX,dword ptr [ESP + 0x4]
0x001cea81	4	MOV ECX,dword ptr [ESP + 0x8]
0x001cea85	3	MOV EAX,dword ptr [EAX + 0x4]
0x001cea88	1	PUSH EDI
0x001cea89	3	MOV EAX,dword ptr [EAX + 0x20]
0x001cea8c	1	PUSH ESI
0x001cea8d	3	LEA EDI,[EAX + 0x8]
0x001cea90	3	MOV ESI,dword ptr [EAX]
0x001cea93	2	MOV EDX,ECX
0x001cea95	2	AND EDX,ESI
0x001cea97	3	MOV EAX,dword ptr [EDI + EDX*0x4]
0x001cea9a	2	OR EAX,EAX
0x001cea9c	2	JZ 0x001cead0
0x001cea9e	3	CMP ECX,dword ptr [EAX]
0x001ceaa1	2	JNZ 0x001ceac6
0x001ceaa3	4	MOV EDI,dword ptr [ESP + 0xc]
0x001ceaa7	3	MOV EAX,dword ptr [EAX + 0x8]
0x001ceaaa	3	MOV ESI,dword ptr [EDI]
0x001ceaad	4	MOV dword ptr [ESP + 0xc],ESI
0x001ceab1	1	POP ESI
0x001ceab2	1	POP EDI
0x001ceab3	2	JMP EAX
0x001ceac6	1	INC EDX
0x001ceac7	2	JMP 0x001cea95
0x001cead0	4	MOV EDI,dword ptr [ESP + 0xc]
0x001cead4	3	MOV ESI,dword ptr [EDI]
0x001cead7	4	MOV dword ptr [ESP + 0xc],ESI
0x001ceadb	3	MOV EAX,dword ptr [EDI + 0x4]
0x001ceade	1	POP ESI
0x001ceadf	1	POP EDI
0x001ceae0	1	PUSH ECX
0x001ceae1	1	PUSH EAX
0x001ceae2	5	CALL 0x001cd868
0x001ceae7	3	ADD ESP,0x8
0x001ceaea	2	JMP EAX
0x001ceb00	5	MOV ECX,0x1
0x001ceb05	6	LEA EAX,[0x1e55ac]
0x001ceb0b	2	XCHG dword ptr [EAX],ECX
0x001ceb0d	3	CMP ECX,0x0
0x001ceb10	2	JNZ 0x001ceb0b
0x001ceb12	4	MOV EAX,dword ptr [ESP + 0x4]
0x001ceb16	4	MOV ECX,dword ptr [ESP + 0x8]
0x001ceb1a	3	MOV EAX,dword ptr [EAX + 0x4]
0x001ceb1d	1	PUSH EDI
0x001ceb1e	3	MOV EAX,dword ptr [EAX + 0x20]
0x001ceb21	1	PUSH ESI
0x001ceb22	3	LEA EDI,[EAX + 0x8]
0x001ceb25	3	MOV ESI,dword ptr [EAX]
0x001ceb28	2	MOV EDX,ECX
0x001ceb2a	2	AND EDX,ESI
0x001ceb2c	3	MOV EAX,dword ptr [EDI + EDX*0x4]
0x001ceb2f	2	OR EAX,EAX
0x001ceb31	2	JZ 0x001ceb70
0x001ceb33	3	CMP ECX,dword ptr [EAX]
0x001ceb36	2	JNZ 0x001ceb65
0x001ceb38	4	MOV EDI,dword ptr [ESP + 0xc]
0x001ceb3c	3	MOV EAX,dword ptr [EAX + 0x8]
0x001ceb3f	3	MOV ESI,dword ptr [EDI]
0x001ceb42	4	MOV dword ptr [ESP + 0xc],ESI
0x001ceb46	1	POP ESI
0x001ceb47	1	POP EDI
0x001ceb48	10	MOV dword ptr [0x001e55ac],0x0
0x001ceb52	2	JMP EAX
0x001ceb65	1	INC EDX
0x001ceb66	2	JMP 0x001ceb2a
0x001ceb70	4	MOV EDI,dword ptr [ESP + 0xc]
0x001ceb74	3	MOV ESI,dword ptr [EDI]
0x001ceb77	4	MOV dword ptr [ESP + 0xc],ESI
0x001ceb7b	3	MOV EAX,dword ptr [EDI + 0x4]
0x001ceb7e	1	POP ESI
0x001ceb7f	1	POP EDI
0x001ceb80	1	PUSH ECX
0x001ceb81	1	PUSH EAX
0x001ceb82	5	CALL 0x001cd868
0x001ceb87	3	ADD ESP,0x8
0x001ceb8a	10	MOV dword ptr [0x001e55ac],0x0
0x001ceb94	2	JMP EAX
