F00CFA74: 9de3bf98                 save    %sp, -0x68, %sp
F00CFA78: 912e6018                 sll     %i1, 24, %o0
F00CFA7C: 80a22000                 cmp     %o0, 0
F00CFA80: 12800003                 bne     loc_F00CFA8C
F00CFA84: 960621a8                 add     %i0, 0x1A8, %o3
F00CFA88: 960621b0                 add     %i0, 0x1B0, %o3
F00CFA8C: d402c000                 ld      [%o3], %o2
F00CFA90: 80a2c00a                 cmp     %o3, %o2
F00CFA94: 12800006                 bne     loc_F00CFAAC
F00CFA98: a410000a                 mov     %o2, %l2
F00CFA9C: 113c03ed                 sethi   %hi(aSdthreaddequeu), %o0! "sdThreadDequeue: Empty queue!\n"
F00CFAA0: 7fffd995                 call    _IOLog
F00CFAA4: 90122258                 bset    %lo(aSdthreaddequeu), %o0! "sdThreadDequeue: Empty queue!\n"
F00CFAA8: 3080009e                 ba,a    locret_F00CFD20
F00CFAAC: d404a02c                 ld      [%l2+0x2C], %o2
F00CFAB0: 80a2c00a                 cmp     %o3, %o2
F00CFAB4: d204a030                 ld      [%l2+0x30], %o1
F00CFAB8: 02800003                 be      loc_F00CFAC4
F00CFABC: 9010000b                 mov     %o3, %o0
F00CFAC0: 9002a02c                 add     %o2, 0x2C, %o0 ! ','
F00CFAC4: d2222004                 st      %o1, [%o0+4]
F00CFAC8: 80a2c009                 cmp     %o3, %o1
F00CFACC: 02800003                 be      loc_F00CFAD8
F00CFAD0: 9010000b                 mov     %o3, %o0
F00CFAD4: 9002602c                 add     %o1, 0x2C, %o0 ! ','
F00CFAD8: d4220000                 st      %o2, [%o0]
F00CFADC: 912e6018                 sll     %i1, 24, %o0
F00CFAE0: 80a22000                 cmp     %o0, 0
F00CFAE4: 02800016                 be      loc_F00CFB3C
F00CFAE8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CFAEC: d00621c0                 ld      [%i0+0x1C0], %o0! id
F00CFAF0: 40008760                 call    _objc_msgSend
F00CFAF4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CFAF8: d00621c4                 ld      [%i0+0x1C4], %o0
F00CFAFC: 90022001                 inc     %o0
F00CFB00: d02621c4                 st      %o0, [%i0+0x1C4]
F00CFB04: d0048000                 ld      [%l2], %o0
F00CFB08: 80a22004                 cmp     %o0, 4
F00CFB0C: 32800008                 bne,a   loc_F00CFB2C
F00CFB10: d00621c0                 ld      [%i0+0x1C0], %o0
F00CFB14: 90102001                 mov     1, %o0
F00CFB18: d02e21c8                 stb     %o0, [%i0+0x1C8]
F00CFB1C: 90100018                 mov     %i0, %o0
F00CFB20: 7fffe22f                 call    _volCheckEjecting
F00CFB24: 92102002                 mov     2, %o1
F00CFB28: d00621c0                 ld      [%i0+0x1C0], %o0! id
F00CFB2C: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00CFB30: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00CFB34: 4000874f                 call    _objc_msgSend
F00CFB38: d40621c4                 ld      [%i0+0x1C4], %o2
F00CFB3C: d2048000                 ld      [%l2], %o1
F00CFB40: 80a26007                 cmp     %o1, 7! switch 8 cases
F00CFB44: 18800069                 bgu     def_F00CFB58! jumptable F00CFB58 default case
F00CFB48: 113c033e                 sethi   %hi(jpt_F00CFB58), %o0
F00CFB4C: 90122360                 bset    %lo(jpt_F00CFB58), %o0
F00CFB50: 932a6002                 sll     %o1, 2, %o1
F00CFB54: d0024008                 ld      [%o1+%o0], %o0
F00CFB58: 81c20000                 jmp     %o0! switch jump
F00CFB5C: 01000000                 nop
F00CFB80: d00621a8                 ld      [%i0+0x1A8], %o0! jumptable F00CFB58 case 5
F00CFB84: a00621a8                 add     %i0, 0x1A8, %l0
F00CFB88: 80a40008                 cmp     %l0, %o0
F00CFB8C: 02800026                 be      loc_F00CFC24! jumptable F00CFB58 case 6
F00CFB90: 2f3c0504                 sethi   -0xFEBF000, %l7
F00CFB94: ac103bb2                 mov     -0x44E, %l6
F00CFB98: aa102010                 mov     0x10, %l5
F00CFB9C: 293c0505                 sethi   -0xFEBEC00, %l4
F00CFBA0: 273c0504                 sethi   -0xFEBF000, %l3
F00CFBA4: e2040000                 ld      [%l0], %l1
F00CFBA8: d404602c                 ld      [%l1+0x2C], %o2
F00CFBAC: 80a4000a                 cmp     %l0, %o2
F00CFBB0: d2046030                 ld      [%l1+0x30], %o1! SEL
F00CFBB4: 02800003                 be      loc_F00CFBC0
F00CFBB8: 90100010                 mov     %l0, %o0
F00CFBBC: 9002a02c                 add     %o2, 0x2C, %o0 ! ','
F00CFBC0: d2222004                 st      %o1, [%o0+4]
F00CFBC4: 80a40009                 cmp     %l0, %o1
F00CFBC8: 02800003                 be      loc_F00CFBD4
F00CFBCC: 90100010                 mov     %l0, %o0
F00CFBD0: 9002602c                 add     %o1, 0x2C, %o0 ! ','
F00CFBD4: d4220000                 st      %o2, [%o0]
F00CFBD8: d00621b8                 ld      [%i0+0x1B8], %o0! id
F00CFBDC: 40008725                 call    _objc_msgSend
F00CFBE0: d205e244                 ld      [%l7+0x244], %o1
F00CFBE4: d0046014                 ld      [%l1+0x14], %o0
F00CFBE8: 80a22000                 cmp     %o0, 0
F00CFBEC: 02800003                 be      loc_F00CFBF8
F00CFBF0: ec246028                 st      %l6, [%l1+0x28]
F00CFBF4: ea222020                 st      %l5, [%o0+0x20]
F00CFBF8: 90100018                 mov     %i0, %o0! id
F00CFBFC: d2052380                 ld      [%l4+0x380], %o1! SEL
F00CFC00: 4000871c                 call    _objc_msgSend
F00CFC04: 94100011                 mov     %l1, %o2
F00CFC08: d00621b8                 ld      [%i0+0x1B8], %o0! id
F00CFC0C: 40008719                 call    _objc_msgSend
F00CFC10: d204e000                 ld      [%l3], %o1
F00CFC14: d0040000                 ld      [%l0], %o0
F00CFC18: 80a40008                 cmp     %l0, %o0
F00CFC1C: 32bfffe3                 bne,a   loc_F00CFBA8
F00CFC20: e2040000                 ld      [%l0], %l1
F00CFC24: c024a028                 clr     [%l2+0x28]! jumptable F00CFB58 case 6
F00CFC28: 90100018                 mov     %i0, %o0! id
F00CFC2C: 133c0505                 sethi   %hi(paSdiocomplete), %o1
F00CFC30: d2026380                 ld      [%o1+%lo(paSdiocomplete)], %o1! SEL
F00CFC34: 4000870f                 call    _objc_msgSend
F00CFC38: 94100012                 mov     %l2, %o2
F00CFC3C: 1080002c                 ba      loc_F00CFCEC
F00CFC40: 912e6018                 sll     %i1, 24, %o0
F00CFC44: 113c0504                 sethi   %hi(paUnlock), %o0! jumptable F00CFB58 case 4
F00CFC48: e0022244                 ld      [%o0+%lo(paUnlock)], %l0
F00CFC4C: d00621b8                 ld      [%i0+0x1B8], %o0! id
F00CFC50: 40008708                 call    _objc_msgSend
F00CFC54: 92100010                 mov     %l0, %o1
F00CFC58: d00621c0                 ld      [%i0+0x1C0], %o0! id
F00CFC5C: 133c0503                 sethi   %hi(paLockwhen), %o1
F00CFC60: d20263f8                 ld      [%o1+%lo(paLockwhen)], %o1! SEL
F00CFC64: 40008703                 call    _objc_msgSend
F00CFC68: 94102001                 mov     1, %o2
F00CFC6C: d00621c0                 ld      [%i0+0x1C0], %o0
F00CFC70: 10800005                 ba      loc_F00CFC84
F00CFC74: 92100010                 mov     %l0, %o1
F00CFC78: d00621b8                 ld      [%i0+0x1B8], %o0! jumptable F00CFB58 cases 0-3
F00CFC7C: 133c0504                 sethi   %hi(paUnlock), %o1
F00CFC80: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00CFC84: 400086fb                 call    _objc_msgSend
F00CFC88: 01000000                 nop
F00CFC8C: 90100018                 mov     %i0, %o0! id
F00CFC90: 133c0505                 sethi   %hi(paDosdbuf), %o1
F00CFC94: d2026370                 ld      [%o1+%lo(paDosdbuf)], %o1! SEL
F00CFC98: 400086f6                 call    _objc_msgSend
F00CFC9C: 94100012                 mov     %l2, %o2
F00CFCA0: d00621b8                 ld      [%i0+0x1B8], %o0! id
F00CFCA4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CFCA8: 400086f2                 call    _objc_msgSend
F00CFCAC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CFCB0: 1080000f                 ba      loc_F00CFCEC
F00CFCB4: 912e6018                 sll     %i1, 24, %o0
F00CFCB8: d00621b8                 ld      [%i0+0x1B8], %o0! jumptable F00CFB58 case 7
F00CFCBC: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00CFCC0: 400086ec                 call    _objc_msgSend
F00CFCC4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00CFCC8: c024a028                 clr     [%l2+0x28]
F00CFCCC: 90100018                 mov     %i0, %o0! id
F00CFCD0: 133c0505                 sethi   %hi(paSdiocomplete), %o1
F00CFCD4: d2026380                 ld      [%o1+%lo(paSdiocomplete)], %o1! SEL
F00CFCD8: 400086e6                 call    _objc_msgSend
F00CFCDC: 94100012                 mov     %l2, %o2
F00CFCE0: 7fffe94f                 call    _IOExitThread
F00CFCE4: 01000000                 nop
F00CFCE8: 912e6018                 sll     %i1, 24, %o0! jumptable F00CFB58 default case
F00CFCEC: 80a22000                 cmp     %o0, 0
F00CFCF0: 0280000c                 be      locret_F00CFD20
F00CFCF4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CFCF8: d00621c0                 ld      [%i0+0x1C0], %o0! id
F00CFCFC: 400086dd                 call    _objc_msgSend
F00CFD00: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CFD04: d00621c0                 ld      [%i0+0x1C0], %o0! id
F00CFD08: d40621c4                 ld      [%i0+0x1C4], %o2
F00CFD0C: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00CFD10: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00CFD14: 9402bfff                 inc     -1, %o2
F00CFD18: 400086d6                 call    _objc_msgSend
F00CFD1C: d42621c4                 st      %o2, [%i0+0x1C4]
F00CFD20: 81c7e008                 ret
F00CFD24: 81e80000                 restore
