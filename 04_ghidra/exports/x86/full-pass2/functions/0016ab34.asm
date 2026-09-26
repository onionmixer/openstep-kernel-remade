0x0016ab34	1	PUSH EBP
0x0016ab35	2	MOV EBP,ESP
0x0016ab37	3	SUB ESP,0x24
0x0016ab3a	1	PUSH EDI
0x0016ab3b	1	PUSH ESI
0x0016ab3c	1	PUSH EBX
0x0016ab3d	7	MOV dword ptr [EBP + -0x8],0x0
0x0016ab44	7	MOV dword ptr [EBP + -0xc],0x1f6e00
0x0016ab4b	7	MOV dword ptr [EBP + -0x10],0x1
0x0016ab52	5	JMP 0x0016ad5f
0x0016ab58	4	ADD dword ptr [EBP + -0xc],0x4
0x0016ab5c	3	MOV EDI,dword ptr [EBP + -0xc]
0x0016ab5f	2	MOV EAX,dword ptr [EDI]
0x0016ab61	3	LEA ECX,[EAX + 0x8]
0x0016ab64	3	MOV dword ptr [EBP + -0x4],ECX
0x0016ab67	3	MOV EBX,dword ptr [EAX + 0x8]
0x0016ab6a	2	TEST EBX,EBX
0x0016ab6c	6	JZ 0x0016ad5c
0x0016ab72	1	NOP
0x0016ab73	1	NOP
0x0016ab74	3	MOV EDI,dword ptr [EBX + 0x4]
0x0016ab77	3	MOV dword ptr [EBP + -0x24],EDI
0x0016ab7a	6	CMP dword ptr [0x001e0d0c],EDI
0x0016ab80	6	JA 0x0016ad4c
0x0016ab86	5	MOV EAX,[0x001e89ec]
0x0016ab8b	3	LEA EDX,[EAX + EBX*0x1]
0x0016ab8e	2	NOT EAX
0x0016ab90	2	AND EDX,EAX
0x0016ab92	3	MOV dword ptr [EBP + -0x14],EDX
0x0016ab95	2	MOV EDX,EDI
0x0016ab97	2	ADD EDX,EBX
0x0016ab99	2	AND EDX,EAX
0x0016ab9b	3	MOV dword ptr [EBP + -0x18],EDX
0x0016ab9e	3	CMP dword ptr [EBP + -0x14],EDX
0x0016aba1	6	JNC 0x0016ad4c
0x0016aba7	3	MOV ECX,dword ptr [EBP + -0x14]
0x0016abaa	6	CMP dword ptr [0x001f6e28],ECX
0x0016abb0	6	JA 0x0016ad4c
0x0016abb6	6	CMP dword ptr [0x001f6e24],EDX
0x0016abbc	6	JC 0x0016ad4c
0x0016abc2	3	MOV EDI,dword ptr [EBP + -0xc]
0x0016abc5	2	MOV EDX,dword ptr [EDI]
0x0016abc7	3	MOV EAX,dword ptr [EDX + 0x10]
0x0016abca	3	MOV ESI,dword ptr [EDX + 0x18]
0x0016abcd	3	MOV EDI,dword ptr [EBP + -0x24]
0x0016abd0	2	MOV ECX,EAX
0x0016abd2	2	SHR EDI,CL
0x0016abd4	3	MOV dword ptr [EBP + -0x20],EDI
0x0016abd7	2	CMP EDI,ESI
0x0016abd9	2	JLE 0x0016abde
0x0016abdb	3	MOV dword ptr [EBP + -0x20],ESI
0x0016abde	3	MOV EAX,dword ptr [EBP + -0x20]
0x0016abe1	3	SHL EAX,0x4
0x0016abe4	3	ADD EAX,dword ptr [EDX + 0x14]
0x0016abe7	3	LEA ECX,[EAX + -0x10]
0x0016abea	3	MOV dword ptr [EBP + -0x1c],ECX
0x0016abed	3	CMP dword ptr [EAX + -0x10],EBX
0x0016abf0	2	JNZ 0x0016ac30
0x0016abf2	3	CMP dword ptr [EBP + -0x20],ESI
0x0016abf5	2	JGE 0x0016ac14
0x0016abf7	2	MOV EAX,dword ptr [EBX]
0x0016abf9	2	TEST EAX,EAX
0x0016abfb	2	JZ 0x0016ac0b
0x0016abfd	3	MOV ESI,dword ptr [EBP + -0x24]
0x0016ac00	3	CMP dword ptr [EAX + 0x4],ESI
0x0016ac03	2	JZ 0x0016ac0b
0x0016ac05	2	MOV EAX,dword ptr [EAX]
0x0016ac07	2	TEST EAX,EAX
0x0016ac09	2	JNZ 0x0016ac00
0x0016ac0b	3	MOV EDI,dword ptr [EBP + -0x1c]
0x0016ac0e	2	MOV dword ptr [EDI],EAX
0x0016ac10	2	JMP 0x0016ac30
0x0016ac14	2	MOV EAX,dword ptr [EBX]
0x0016ac16	2	TEST EAX,EAX
0x0016ac18	2	JZ 0x0016ac2b
0x0016ac1a	3	MOV ESI,dword ptr [EDX + 0x4]
0x0016ac1d	1	NOP
0x0016ac1e	1	NOP
0x0016ac1f	1	NOP
0x0016ac20	3	CMP dword ptr [EAX + 0x4],ESI
0x0016ac23	2	JNC 0x0016ac2b
0x0016ac25	2	MOV EAX,dword ptr [EAX]
0x0016ac27	2	TEST EAX,EAX
0x0016ac29	2	JNZ 0x0016ac20
0x0016ac2b	3	MOV ECX,dword ptr [EBP + -0x1c]
0x0016ac2e	2	MOV dword ptr [ECX],EAX
0x0016ac30	2	MOV EAX,EBX
0x0016ac32	3	ADD EAX,dword ptr [EBX + 0x4]
0x0016ac35	3	CMP dword ptr [EBP + -0x18],EAX
0x0016ac38	6	JZ 0x0016acdc
0x0016ac3e	3	MOV EDX,dword ptr [EBP + -0x18]
0x0016ac41	2	SUB EAX,EDX
0x0016ac43	3	MOV dword ptr [EDX + 0x4],EAX
0x0016ac46	2	MOV EAX,dword ptr [EBX]
0x0016ac48	2	MOV dword ptr [EDX],EAX
0x0016ac4a	2	TEST EAX,EAX
0x0016ac4c	2	JZ 0x0016ac51
0x0016ac4e	3	MOV dword ptr [EAX + 0x8],EDX
0x0016ac51	3	CMP dword ptr [EBP + -0x14],EBX
0x0016ac54	2	JNZ 0x0016ac60
0x0016ac56	3	MOV EDI,dword ptr [EBP + -0x4]
0x0016ac59	2	MOV dword ptr [EDI],EDX
0x0016ac5b	3	MOV dword ptr [EDX + 0x8],EDI
0x0016ac5e	2	JMP 0x0016aca7
0x0016ac60	3	MOV ECX,dword ptr [EBP + -0x14]
0x0016ac63	2	SUB ECX,EBX
0x0016ac65	3	MOV dword ptr [EBX + 0x4],ECX
0x0016ac68	2	MOV dword ptr [EBX],EDX
0x0016ac6a	3	MOV dword ptr [EDX + 0x8],EBX
0x0016ac6d	3	MOV EDI,dword ptr [EBP + -0xc]
0x0016ac70	2	MOV EAX,dword ptr [EDI]
0x0016ac72	3	INC dword ptr [EAX + 0xc]
0x0016ac75	2	MOV ESI,dword ptr [EDI]
0x0016ac77	3	MOV EAX,dword ptr [ESI + 0x10]
0x0016ac7a	3	MOV ECX,dword ptr [ESI + 0x18]
0x0016ac7d	3	MOV dword ptr [EBP + -0x24],ECX
0x0016ac80	3	MOV EDI,dword ptr [EBX + 0x4]
0x0016ac83	2	MOV ECX,EAX
0x0016ac85	2	SHR EDI,CL
0x0016ac87	2	MOV EAX,EDI
0x0016ac89	3	CMP dword ptr [EBP + -0x24],EAX
0x0016ac8c	2	JGE 0x0016ac91
0x0016ac8e	3	MOV EAX,dword ptr [EBP + -0x24]
0x0016ac91	3	SHL EAX,0x4
0x0016ac94	3	MOV ESI,dword ptr [ESI + 0x14]
0x0016ac97	2	ADD ESI,EAX
0x0016ac99	3	MOV EAX,dword ptr [ESI + -0x10]
0x0016ac9c	2	TEST EAX,EAX
0x0016ac9e	2	JZ 0x0016aca4
0x0016aca0	2	CMP EBX,EAX
0x0016aca2	2	JNC 0x0016aca7
0x0016aca4	3	MOV dword ptr [ESI + -0x10],EBX
0x0016aca7	3	MOV ECX,dword ptr [EBP + -0xc]
0x0016acaa	2	MOV EBX,dword ptr [ECX]
0x0016acac	3	MOV EAX,dword ptr [EBX + 0x10]
0x0016acaf	3	MOV ESI,dword ptr [EBX + 0x18]
0x0016acb2	3	MOV EDI,dword ptr [EDX + 0x4]
0x0016acb5	2	MOV ECX,EAX
0x0016acb7	2	SHR EDI,CL
0x0016acb9	2	MOV EAX,EDI
0x0016acbb	2	CMP EAX,ESI
0x0016acbd	2	JLE 0x0016acc1
0x0016acbf	2	MOV EAX,ESI
0x0016acc1	3	SHL EAX,0x4
0x0016acc4	3	MOV EBX,dword ptr [EBX + 0x14]
0x0016acc7	2	ADD EBX,EAX
0x0016acc9	3	MOV EAX,dword ptr [EBX + -0x10]
0x0016accc	2	TEST EAX,EAX
0x0016acce	2	JZ 0x0016acd4
0x0016acd0	2	CMP EDX,EAX
0x0016acd2	2	JNC 0x0016ad34
0x0016acd4	3	MOV dword ptr [EBX + -0x10],EDX
0x0016acd7	2	JMP 0x0016ad34
0x0016acdc	3	CMP dword ptr [EBP + -0x14],EBX
0x0016acdf	2	JZ 0x0016ad1c
0x0016ace1	3	MOV EAX,dword ptr [EBP + -0x14]
0x0016ace4	2	SUB EAX,EBX
0x0016ace6	3	MOV dword ptr [EBX + 0x4],EAX
0x0016ace9	3	MOV ECX,dword ptr [EBP + -0xc]
0x0016acec	2	MOV EDX,dword ptr [ECX]
0x0016acee	3	MOV ESI,dword ptr [EDX + 0x10]
0x0016acf1	3	MOV EDI,dword ptr [EDX + 0x18]
0x0016acf4	3	MOV dword ptr [EBP + -0x24],EDI
0x0016acf7	2	MOV ECX,ESI
0x0016acf9	2	SHR EAX,CL
0x0016acfb	2	CMP EAX,EDI
0x0016acfd	2	JLE 0x0016ad02
0x0016acff	3	MOV EAX,dword ptr [EBP + -0x24]
0x0016ad02	3	SHL EAX,0x4
0x0016ad05	3	MOV ESI,dword ptr [EDX + 0x14]
0x0016ad08	2	ADD ESI,EAX
0x0016ad0a	3	MOV EAX,dword ptr [ESI + -0x10]
0x0016ad0d	2	TEST EAX,EAX
0x0016ad0f	2	JZ 0x0016ad15
0x0016ad11	2	CMP EBX,EAX
0x0016ad13	2	JNC 0x0016ad34
0x0016ad15	3	MOV dword ptr [ESI + -0x10],EBX
0x0016ad18	2	JMP 0x0016ad34
0x0016ad1c	2	MOV EAX,dword ptr [EBX]
0x0016ad1e	3	MOV EDI,dword ptr [EBP + -0x4]
0x0016ad21	2	MOV dword ptr [EDI],EAX
0x0016ad23	2	TEST EAX,EAX
0x0016ad25	2	JZ 0x0016ad2c
0x0016ad27	2	MOV EAX,dword ptr [EBX]
0x0016ad29	3	MOV dword ptr [EAX + 0x8],EDI
0x0016ad2c	3	MOV ECX,dword ptr [EBP + -0xc]
0x0016ad2f	2	MOV EAX,dword ptr [ECX]
0x0016ad31	3	DEC dword ptr [EAX + 0xc]
0x0016ad34	3	MOV EDX,dword ptr [EBP + -0x14]
0x0016ad37	3	MOV EDI,dword ptr [EBP + -0x18]
0x0016ad3a	2	SUB EDI,EDX
0x0016ad3c	3	MOV dword ptr [EDX + 0x4],EDI
0x0016ad3f	3	MOV ECX,dword ptr [EBP + -0x8]
0x0016ad42	2	MOV dword ptr [EDX],ECX
0x0016ad44	3	MOV dword ptr [EBP + -0x8],EDX
0x0016ad47	2	JMP 0x0016ad4f
0x0016ad4c	3	MOV dword ptr [EBP + -0x4],EBX
0x0016ad4f	3	MOV EDI,dword ptr [EBP + -0x4]
0x0016ad52	2	MOV EBX,dword ptr [EDI]
0x0016ad54	2	TEST EBX,EBX
0x0016ad56	6	JNZ 0x0016ab74
0x0016ad5c	3	INC dword ptr [EBP + -0x10]
0x0016ad5f	3	MOV ECX,dword ptr [EBP + -0x10]
0x0016ad62	6	CMP dword ptr [0x001f6e20],ECX
0x0016ad68	6	JG 0x0016ab58
0x0016ad6e	2	XOR EAX,EAX
0x0016ad70	6	XCHG dword ptr [0x001f6df4],EAX
0x0016ad76	2	JMP 0x0016ad91
0x0016ad78	2	MOV EDI,dword ptr [EBX]
0x0016ad7a	3	MOV dword ptr [EBP + -0x8],EDI
0x0016ad7d	3	MOV ECX,dword ptr [EBX + 0x4]
0x0016ad80	1	PUSH ECX
0x0016ad81	1	PUSH EBX
0x0016ad82	6	MOV EDI,dword ptr [0x001dfcec]
0x0016ad88	1	PUSH EDI
0x0016ad89	5	CALL 0x00173e90
0x0016ad8e	3	ADD ESP,0xc
0x0016ad91	3	MOV EBX,dword ptr [EBP + -0x8]
0x0016ad94	2	TEST EBX,EBX
0x0016ad96	2	JNZ 0x0016ad78
0x0016ad98	3	LEA ESP,[EBP + -0x30]
0x0016ad9b	1	POP EBX
0x0016ad9c	1	POP ESI
0x0016ad9d	1	POP EDI
0x0016ad9e	2	MOV ESP,EBP
0x0016ada0	1	POP EBP
0x0016ada1	1	RET
