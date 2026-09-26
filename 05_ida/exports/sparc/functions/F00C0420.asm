F00C0420: 9de3bf80                 save    %sp, -0x80, %sp
F00C0424: d0062124                 ld      [%i0+0x124], %o0! id
F00C0428: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C042C: 4000c511                 call    _objc_msgSend
F00C0430: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C0434: d206a008                 ld      [%i2+8], %o1
F00C0438: 91326016                 srl     %o1, 22, %o0
F00C043C: a00a2004                 and     %o0, 4, %l0
F00C0440: 11008000                 sethi   0x2000000, %o0
F00C0444: 808a4008                 btst    %o0, %o1
F00C0448: 32800002                 bne,a   loc_F00C0450
F00C044C: a0142001                 bset    1, %l0
F00C0450: 912a6008                 sll     %o1, 8, %o0
F00C0454: 913a2018                 sra     %o0, 24, %o0
F00C0458: d027bfec                 st      %o0, [%fp+var_14]
F00C045C: d806a008                 ld      [%i2+8], %o4
F00C0460: d41e8000                 ldd     [%i2], %o2
F00C0464: 992b2010                 sll     %o4, 16, %o4
F00C0468: 993b2018                 sra     %o4, 24, %o4
F00C046C: d827bfe8                 st      %o4, [%fp+var_18]
F00C0470: 9b2aa008                 sll     %o2, 8, %o5
F00C0474: 9932e018                 srl     %o3, 24, %o4
F00C0478: 9213400c                 or      %o5, %o4, %o1
F00C047C: 9132a018                 srl     %o2, 24, %o0
F00C0480: d806212c                 ld      [%i0+0x12C], %o4
F00C0484: 80a32000                 cmp     %o4, 0
F00C0488: 12800004                 bne     loc_F00C0498
F00C048C: a2100009                 mov     %o1, %l1
F00C0490: 10800003                 ba      loc_F00C049C
F00C0494: 98102002                 mov     2, %o4
F00C0498: 9824400c                 sub     %l1, %o4, %o4
F00C049C: 80a32001                 cmp     %o4, 1
F00C04A0: 1880000b                 bgu     loc_F00C04CC
F00C04A4: 153c0483                 sethi   %hi(dword_F0120CC8), %o2
F00C04A8: d002a0c8                 ld      [%o2+%lo(dword_F0120CC8)], %o0
F00C04AC: 80a22000                 cmp     %o0, 0
F00C04B0: 02800007                 be      loc_F00C04CC
F00C04B4: 133c0504                 sethi   %hi(paUnlock), %o1
F00C04B8: d0062124                 ld      [%i0+0x124], %o0! id
F00C04BC: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00C04C0: 4000c4ec                 call    _objc_msgSend
F00C04C4: c022a0c8                 clr     [%o2+%lo(dword_F0120CC8)]
F00C04C8: 30800030                 ba,a    locret_F00C0588
F00C04CC: 90100018                 mov     %i0, %o0! id
F00C04D0: 9407bfec                 add     %fp, var_14, %o2
F00C04D4: 133c0504                 sethi   %hi(paScalepointerin), %o1
F00C04D8: d20262e8                 ld      [%o1+%lo(paScalepointerin)], %o1! SEL
F00C04DC: 073c0483                 sethi   %hi(dword_F0120CC8), %g3
F00C04E0: c400e0c8                 ld      [%g3+%lo(dword_F0120CC8)], %g2
F00C04E4: 9607bfe8                 add     %fp, var_18, %o3
F00C04E8: da062130                 ld      [%i0+0x130], %o5
F00C04EC: 8400a001                 inc     %g2
F00C04F0: 4000c4e0                 call    _objc_msgSend
F00C04F4: c420e0c8                 st      %g2, [%g3+%lo(dword_F0120CC8)]
F00C04F8: d0062134                 ld      [%i0+0x134], %o0
F00C04FC: 80a22000                 cmp     %o0, 0
F00C0500: 12800007                 bne     loc_F00C051C
F00C0504: e226212c                 st      %l1, [%i0+0x12C]
F00C0508: 808c2005                 btst    5, %l0
F00C050C: 3280000e                 bne,a   loc_F00C0544
F00C0510: a0102004                 mov     4, %l0
F00C0514: 1080000d                 ba      loc_F00C0548
F00C0518: d0062124                 ld      [%i0+0x124], %o0
F00C051C: 80a22001                 cmp     %o0, 1
F00C0520: 3280000a                 bne,a   loc_F00C0548
F00C0524: d0062124                 ld      [%i0+0x124], %o0
F00C0528: 900c2004                 and     %l0, 4, %o0
F00C052C: 80a00008                 cmp     %g0, %o0
F00C0530: 90402000                 addc    %g0, 0, %o0
F00C0534: 808c2001                 btst    1, %l0
F00C0538: 32800002                 bne,a   loc_F00C0540
F00C053C: 90122004                 bset    4, %o0
F00C0540: a0100008                 mov     %o0, %l0
F00C0544: d0062124                 ld      [%i0+0x124], %o0! id
F00C0548: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C054C: 4000c4c9                 call    _objc_msgSend
F00C0550: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C0554: 113c0504                 sethi   %hi(paOwner_0), %o0! id
F00C0558: d2022298                 ld      [%o0+%lo(paOwner_0)], %o1! SEL
F00C055C: 4000c4c5                 call    _objc_msgSend
F00C0560: 90100018                 mov     %i0, %o0! id
F00C0564: d607bfec                 ld      [%fp+var_14], %o3
F00C0568: d807bfe8                 ld      [%fp+var_18], %o4
F00C056C: 94100010                 mov     %l0, %o2
F00C0570: c41e8000                 ldd     [%i2], %g2
F00C0574: 133c0504                 sethi   %hi(paRelativepointe), %o1
F00C0578: d20262ec                 ld      [%o1+%lo(paRelativepointe)], %o1! SEL
F00C057C: c623a05c                 st      %g3, [%sp+0x80+var_24]
F00C0580: 4000c4bc                 call    _objc_msgSend
F00C0584: 9a100002                 mov     %g2, %o5
F00C0588: 81c7e008                 ret
F00C058C: 81e80000                 restore
