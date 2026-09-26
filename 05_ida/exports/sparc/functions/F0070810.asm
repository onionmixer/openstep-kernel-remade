F0070810: 9de3bf88                 save    %sp, -0x78, %sp
F0070814: 113c0440                 sethi   %hi(aWaitingForRemo), %o0! "Waiting for remote debugger connection."...
F0070818: 7ffff5f8                 call    _safe_prf
F007081C: 90122288                 bset    %lo(aWaitingForRemo), %o0! "Waiting for remote debugger connection."...
F0070820: 113c0440                 sethi   %hi(aTypeCToContinu), %o0! "(Type 'c' to continue or 'r' to reboot)"...
F0070824: 7ffff5f5                 call    _safe_prf
F0070828: 901222b8                 bset    %lo(aTypeCToContinu), %o0! "(Type 'c' to continue or 'r' to reboot)"...
F007082C: 113c04be                 sethi   %hi(unk_F012F92C), %o0
F0070830: c02a212c                 clrb    [%o0+%lo(unk_F012F92C)]
F0070834: a407bff0                 add     %fp, var_10, %l2
F0070838: 2b3c0440                 sethi   -0xFEF0000, %l5
F007083C: 293c0440                 sethi   -0xFEF0000, %l4
F0070840: 273c04bf                 sethi   -0xFED0400, %l3
F0070844: 113c04bea2122130         set     unk_F012F930, %l1
F007084C: 133c04bf                 sethi   %hi(dword_F012FF24), %o1
F0070850: d0026324                 ld      [%o1+%lo(dword_F012FF24)], %o0
F0070854: 80a22000                 cmp     %o0, 0
F0070858: 32800017                 bne,a   loc_F00708B4
F007085C: 92100012                 mov     %l2, %o1
F0070860: a0100009                 mov     %o1, %l0
F0070864: 400133d0                 call    _kmtrygetc
F0070868: 01000000                 nop
F007086C: 80a22063                 cmp     %o0, 0x63 ! 'c'
F0070870: 02800005                 be      loc_F0070884
F0070874: 80a22072                 cmp     %o0, 0x72 ! 'r'
F0070878: 02800005                 be      loc_F007088C
F007087C: 01000000                 nop
F0070880: 30800007                 ba,a    loc_F007089C
F0070884: 1080002c                 ba      loc_F0070934
F0070888: 901562e8                 or      %l5, 0x2E8, %o0
F007088C: 7ffff5db                 call    _safe_prf
F0070890: 901522f8                 or      %l4, 0x2F8, %o0
F0070894: 40008f9d                 call    _kdp_reboot
F0070898: 01000000                 nop
F007089C: 7fffff4a                 call    sub_F00705C4
F00708A0: 01000000                 nop
F00708A4: d0042324                 ld      [%l0+0x324], %o0
F00708A8: 80a22000                 cmp     %o0, 0
F00708AC: 02bfffee                 be      loc_F0070864
F00708B0: 92100012                 mov     %l2, %o1! void *
F00708B4: d004e31c                 ld      [%l3+0x31C], %o0! void *
F00708B8: 94102008                 mov     8, %o2! size_t
F00708BC: 40009095                 call    _bcopy
F00708C0: 90020011                 add     %o0, %l1, %o0
F00708C4: d2048000                 ld      [%l2], %o1
F00708C8: 113fc000                 sethi   -0x1000000, %o0
F00708CC: 808a4008                 btst    %o0, %o1
F00708D0: 12800013                 bne     loc_F007091C
F00708D4: 113c04f1                 sethi   -0xFEC3C00, %o0
F00708D8: d00ca001                 ldub    [%l2+1], %o0
F00708DC: 133c04be                 sethi   %hi(unk_F012F92C), %o1
F00708E0: d20a612c                 ldub    [%o1+%lo(unk_F012F92C)], %o1
F00708E4: 80a20009                 cmp     %o0, %o1
F00708E8: 3280000d                 bne,a   loc_F007091C
F00708EC: 113c04f1                 sethi   -0xFEC3C00, %o0
F00708F0: 920465f0                 add     %l1, 0x5F0, %o1
F00708F4: d004e31c                 ld      [%l3+0x31C], %o0
F00708F8: 9407bfee                 add     %fp, var_12, %o2
F00708FC: 7ffffc4c                 call    _kdp_packet
F0070900: 90020011                 add     %o0, %l1, %o0
F0070904: 80a22000                 cmp     %o0, 0
F0070908: 02800005                 be      loc_F007091C
F007090C: 113c04f1                 sethi   -0xFEC3C00, %o0
F0070910: 7ffffe00                 call    sub_F0070110
F0070914: d017bfee                 lduh    [%fp+var_12], %o0
F0070918: 113c04f1                 sethi   -0xFEC3C00, %o0
F007091C: d0022008                 ld      [%o0+8], %o0
F0070920: 80a22000                 cmp     %o0, 0
F0070924: 02bfffca                 be      loc_F007084C
F0070928: c02465f4                 clr     [%l1+0x5F4]
F007092C: 113c044090122308         set     aConnectedToRem, %o0! "Connected to remote debugger.\n"
F0070934: 7ffff5b1                 call    _safe_prf
F0070938: 01000000                 nop
F007093C: 81c7e008                 ret
F0070940: 81e80000                 restore
