0x001cb8ac	1	PUSH EBP
0x001cb8ad	2	MOV EBP,ESP
0x001cb8af	3	SUB ESP,0xc
0x001cb8b2	1	PUSH EDI
0x001cb8b3	1	PUSH ESI
0x001cb8b4	1	PUSH EBX
0x001cb8b5	3	MOV EDX,dword ptr [EBP + 0x8]
0x001cb8b8	2	MOV EAX,dword ptr [EDX]
0x001cb8ba	3	MOV ECX,dword ptr [EBP + 0xc]
0x001cb8bd	1	PUSH ECX
0x001cb8be	3	MOV EDX,dword ptr [EDX + 0x10]
0x001cb8c1	1	PUSH EDX
0x001cb8c2	2	MOV EAX,dword ptr [EAX]
0x001cb8c4	2	CALL EAX
0x001cb8c6	3	MOV ECX,dword ptr [EBP + 0x8]
0x001cb8c9	2	XOR EDX,EDX
0x001cb8cb	3	DIV dword ptr [ECX + 0x8]
0x001cb8ce	2	MOV EBX,EDX
0x001cb8d0	7	LEA EAX,[EBX*0x8 + 0x0]
0x001cb8d7	2	MOV EDI,EAX
0x001cb8d9	3	ADD EDI,dword ptr [ECX + 0xc]
0x001cb8dc	2	MOV ESI,dword ptr [EDI]
0x001cb8de	1	PUSH ECX
0x001cb8df	5	CALL 0x001cdefc
0x001cb8e4	3	MOV dword ptr [EBP + -0x4],EAX
0x001cb8e7	3	ADD ESP,0xc
0x001cb8ea	2	TEST ESI,ESI
0x001cb8ec	6	JZ 0x001cba91
0x001cb8f2	3	CMP ESI,0x1
0x001cb8f5	2	JNZ 0x001cb940
0x001cb8f7	3	MOV EDX,dword ptr [EBP + 0xc]
0x001cb8fa	3	CMP dword ptr [EDI + 0x4],EDX
0x001cb8fd	2	JZ 0x001cb920
0x001cb8ff	3	MOV ECX,dword ptr [EBP + 0x8]
0x001cb902	2	MOV EAX,dword ptr [ECX]
0x001cb904	3	MOV EDX,dword ptr [EDI + 0x4]
0x001cb907	1	PUSH EDX
0x001cb908	3	MOV ECX,dword ptr [EBP + 0xc]
0x001cb90b	1	PUSH ECX
0x001cb90c	3	MOV EDX,dword ptr [EBP + 0x8]
0x001cb90f	3	MOV EDX,dword ptr [EDX + 0x10]
0x001cb912	1	PUSH EDX
0x001cb913	3	MOV EAX,dword ptr [EAX + 0x4]
0x001cb916	2	CALL EAX
0x001cb918	2	TEST EAX,EAX
0x001cb91a	6	JZ 0x001cba91
0x001cb920	3	MOV ECX,dword ptr [EDI + 0x4]
0x001cb923	3	MOV dword ptr [EBP + 0xc],ECX
0x001cb926	3	MOV EDX,dword ptr [EBP + 0x8]
0x001cb929	3	DEC dword ptr [EDX + 0x4]
0x001cb92c	2	DEC dword ptr [EDI]
0x001cb92e	7	MOV dword ptr [EDI + 0x4],0x0
0x001cb935	3	MOV EAX,dword ptr [EBP + 0xc]
0x001cb938	5	JMP 0x001cba93
0x001cb940	3	MOV EBX,dword ptr [EDI + 0x4]
0x001cb943	3	CMP ESI,0x2
0x001cb946	6	JNZ 0x001cba87
0x001cb94c	3	MOV ECX,dword ptr [EBP + 0xc]
0x001cb94f	2	CMP dword ptr [EBX],ECX
0x001cb951	2	JZ 0x001cb972
0x001cb953	3	MOV EDX,dword ptr [EBP + 0x8]
0x001cb956	2	MOV EAX,dword ptr [EDX]
0x001cb958	2	MOV ECX,dword ptr [EBX]
0x001cb95a	1	PUSH ECX
0x001cb95b	3	MOV EDX,dword ptr [EBP + 0xc]
0x001cb95e	1	PUSH EDX
0x001cb95f	3	MOV ECX,dword ptr [EBP + 0x8]
0x001cb962	3	MOV ECX,dword ptr [ECX + 0x10]
0x001cb965	1	PUSH ECX
0x001cb966	3	MOV EAX,dword ptr [EAX + 0x4]
0x001cb969	2	CALL EAX
0x001cb96b	3	ADD ESP,0xc
0x001cb96e	2	TEST EAX,EAX
0x001cb970	2	JZ 0x001cb980
0x001cb972	3	MOV EDX,dword ptr [EBX + 0x4]
0x001cb975	3	MOV dword ptr [EDI + 0x4],EDX
0x001cb978	2	MOV ECX,dword ptr [EBX]
0x001cb97a	3	MOV dword ptr [EBP + 0xc],ECX
0x001cb97d	2	JMP 0x001cb9b7
0x001cb980	3	MOV EDX,dword ptr [EBP + 0xc]
0x001cb983	3	CMP dword ptr [EBX + 0x4],EDX
0x001cb986	2	JZ 0x001cb9ac
0x001cb988	3	MOV ECX,dword ptr [EBP + 0x8]
0x001cb98b	2	MOV EAX,dword ptr [ECX]
0x001cb98d	3	MOV EDX,dword ptr [EBX + 0x4]
0x001cb990	1	PUSH EDX
0x001cb991	3	MOV ECX,dword ptr [EBP + 0xc]
0x001cb994	1	PUSH ECX
0x001cb995	3	MOV EDX,dword ptr [EBP + 0x8]
0x001cb998	3	MOV EDX,dword ptr [EDX + 0x10]
0x001cb99b	1	PUSH EDX
0x001cb99c	3	MOV EAX,dword ptr [EAX + 0x4]
0x001cb99f	2	CALL EAX
0x001cb9a1	3	ADD ESP,0xc
0x001cb9a4	2	TEST EAX,EAX
0x001cb9a6	6	JZ 0x001cba91
0x001cb9ac	2	MOV ECX,dword ptr [EBX]
0x001cb9ae	3	MOV dword ptr [EDI + 0x4],ECX
0x001cb9b1	3	MOV EDX,dword ptr [EBX + 0x4]
0x001cb9b4	3	MOV dword ptr [EBP + 0xc],EDX
0x001cb9b7	1	PUSH EBX
0x001cb9b8	5	CALL 0x0015ab30
0x001cb9bd	3	MOV ECX,dword ptr [EBP + 0x8]
0x001cb9c0	3	DEC dword ptr [ECX + 0x4]
0x001cb9c3	2	DEC dword ptr [EDI]
0x001cb9c5	3	MOV EAX,dword ptr [EBP + 0xc]
0x001cb9c8	5	JMP 0x001cba93
0x001cb9d0	3	MOV EDX,dword ptr [EBP + 0xc]
0x001cb9d3	2	CMP dword ptr [EBX],EDX
0x001cb9d5	2	JZ 0x001cb9fa
0x001cb9d7	3	MOV ECX,dword ptr [EBP + 0x8]
0x001cb9da	2	MOV EAX,dword ptr [ECX]
0x001cb9dc	2	MOV EDX,dword ptr [EBX]
0x001cb9de	1	PUSH EDX
0x001cb9df	3	MOV ECX,dword ptr [EBP + 0xc]
0x001cb9e2	1	PUSH ECX
0x001cb9e3	3	MOV EDX,dword ptr [EBP + 0x8]
0x001cb9e6	3	MOV EDX,dword ptr [EDX + 0x10]
0x001cb9e9	1	PUSH EDX
0x001cb9ea	3	MOV EAX,dword ptr [EAX + 0x4]
0x001cb9ed	2	CALL EAX
0x001cb9ef	3	ADD ESP,0xc
0x001cb9f2	2	TEST EAX,EAX
0x001cb9f4	6	JZ 0x001cba84
0x001cb9fa	2	MOV EBX,dword ptr [EBX]
0x001cb9fc	3	MOV dword ptr [EBP + 0xc],EBX
0x001cb9ff	3	CMP dword ptr [EDI],0x1
0x001cba02	2	JZ 0x001cba1c
0x001cba04	2	PUSH 0x4
0x001cba06	2	MOV EAX,dword ptr [EDI]
0x001cba08	1	DEC EAX
0x001cba09	1	PUSH EAX
0x001cba0a	3	MOV ECX,dword ptr [EBP + -0x4]
0x001cba0d	1	PUSH ECX
0x001cba0e	5	CALL 0x001cdf1c
0x001cba13	3	ADD ESP,0xc
0x001cba16	2	MOV EBX,EAX
0x001cba18	2	JMP 0x001cba1e
0x001cba1c	2	XOR EBX,EBX
0x001cba1e	2	MOV EAX,dword ptr [EDI]
0x001cba20	1	DEC EAX
0x001cba21	2	CMP EAX,ESI
0x001cba23	2	JZ 0x001cba3e
0x001cba25	2	MOV EAX,dword ptr [EDI]
0x001cba27	2	SUB EAX,ESI
0x001cba29	7	LEA EAX,[EAX*0x4 + 0xfffffffc]
0x001cba30	1	PUSH EAX
0x001cba31	3	MOV EDX,dword ptr [EDI + 0x4]
0x001cba34	1	PUSH EDX
0x001cba35	1	PUSH EBX
0x001cba36	5	CALL 0x00101504
0x001cba3b	3	ADD ESP,0xc
0x001cba3e	2	TEST ESI,ESI
0x001cba40	2	JZ 0x001cba6b
0x001cba42	3	SHL ESI,0x2
0x001cba45	3	MOV dword ptr [EBP + -0x8],ESI
0x001cba48	1	PUSH ESI
0x001cba49	2	MOV ECX,dword ptr [EDI]
0x001cba4b	3	SHL ECX,0x2
0x001cba4e	3	MOV dword ptr [EBP + -0xc],ECX
0x001cba51	2	MOV EAX,ECX
0x001cba53	3	ADD EAX,dword ptr [EDI + 0x4]
0x001cba56	3	SUB EAX,dword ptr [EBP + -0x8]
0x001cba59	1	PUSH EAX
0x001cba5a	2	ADD ECX,EBX
0x001cba5c	3	SUB ECX,dword ptr [EBP + -0x8]
0x001cba5f	3	ADD ECX,-0x4
0x001cba62	1	PUSH ECX
0x001cba63	5	CALL 0x00101504
0x001cba68	3	ADD ESP,0xc
0x001cba6b	3	MOV EDX,dword ptr [EDI + 0x4]
0x001cba6e	1	PUSH EDX
0x001cba6f	5	CALL 0x0015ab30
0x001cba74	3	MOV ECX,dword ptr [EBP + 0x8]
0x001cba77	3	DEC dword ptr [ECX + 0x4]
0x001cba7a	2	DEC dword ptr [EDI]
0x001cba7c	3	MOV dword ptr [EDI + 0x4],EBX
0x001cba7f	3	MOV EAX,dword ptr [EBP + 0xc]
0x001cba82	2	JMP 0x001cba93
0x001cba84	3	ADD EBX,0x4
0x001cba87	1	DEC ESI
0x001cba88	3	CMP ESI,-0x1
0x001cba8b	6	JNZ 0x001cb9d0
0x001cba91	2	XOR EAX,EAX
0x001cba93	3	LEA ESP,[EBP + -0x18]
0x001cba96	1	POP EBX
0x001cba97	1	POP ESI
0x001cba98	1	POP EDI
0x001cba99	2	MOV ESP,EBP
0x001cba9b	1	POP EBP
0x001cba9c	1	RET
