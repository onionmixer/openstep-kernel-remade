F00706FC: 9de3bf88                 save    %sp, -0x78, %sp
F0070700: a207bff0                 add     %fp, var_10, %l1
F0070704: 113c04f1                 sethi   %hi(dword_F013C40C), %o0
F0070708: f022200c                 st      %i0, [%o0+%lo(dword_F013C40C)]
F007070C: 273c04bf                 sethi   -0xFED0400, %l3
F0070710: 113c04bea0122130         set     unk_F012F930, %l0
F0070718: 293c04c1                 sethi   -0xFECFC00, %l4
F007071C: 113c04bfa4122328         set     unk_F012FF28, %l2
F0070724: 133c04bf                 sethi   %hi(dword_F012FF24), %o1
F0070728: d0026324                 ld      [%o1+%lo(dword_F012FF24)], %o0
F007072C: 80a22000                 cmp     %o0, 0
F0070730: 32800009                 bne,a   loc_F0070754
F0070734: 92100011                 mov     %l1, %o1
F0070738: b0100009                 mov     %o1, %i0
F007073C: 7fffffa2                 call    sub_F00705C4
F0070740: 01000000                 nop
F0070744: d0062324                 ld      [%i0+0x324], %o0
F0070748: 80a22000                 cmp     %o0, 0
F007074C: 02bffffc                 be      loc_F007073C
F0070750: 92100011                 mov     %l1, %o1! void *
F0070754: d004e31c                 ld      [%l3+0x31C], %o0! void *
F0070758: 94102008                 mov     8, %o2! size_t
F007075C: 400090ed                 call    _bcopy
F0070760: 90020010                 add     %o0, %l0, %o0
F0070764: d2044000                 ld      [%l1], %o1
F0070768: 11004000                 sethi   0x1000000, %o0
F007076C: 808a4008                 btst    %o0, %o1
F0070770: 12800022                 bne     loc_F00707F8
F0070774: 113c04f1                 sethi   -0xFEC3C00, %o0
F0070778: 91326010                 srl     %o1, 16, %o0
F007077C: 133c04be                 sethi   %hi(unk_F012F92C), %o1
F0070780: d40a612c                 ldub    [%o1+%lo(unk_F012F92C)], %o2
F0070784: 920a20ff                 and     %o0, 0xFF, %o1
F0070788: 9002bfff                 add     %o2, -1, %o0
F007078C: 80a24008                 cmp     %o1, %o0
F0070790: 32800008                 bne,a   loc_F00707B0
F0070794: d00c6001                 ldub    [%l1+1], %o0
F0070798: d0052114                 ld      [%l4+0x114], %o0
F007079C: d204a5f0                 ld      [%l2+0x5F0], %o1
F00707A0: 40008ff4                 call    _kdp_en_send_pkt
F00707A4: 90020012                 add     %o0, %l2, %o0
F00707A8: 10800014                 ba      loc_F00707F8
F00707AC: 113c04f1                 sethi   -0xFEC3C00, %o0
F00707B0: 80a2000a                 cmp     %o0, %o2
F00707B4: 22800007                 be,a    loc_F00707D0
F00707B8: 920425f0                 add     %l0, 0x5F0, %o1
F00707BC: 113c0440                 sethi   %hi(aKdpBadSequence), %o0! "kdp: bad sequence %d (want %d)\n"
F00707C0: 7ffff60e                 call    _safe_prf
F00707C4: 90122268                 bset    %lo(aKdpBadSequence), %o0! "kdp: bad sequence %d (want %d)\n"
F00707C8: 1080000c                 ba      loc_F00707F8
F00707CC: 113c04f1                 sethi   -0xFEC3C00, %o0
F00707D0: d004e31c                 ld      [%l3+0x31C], %o0
F00707D4: 9407bfee                 add     %fp, var_12, %o2
F00707D8: 7ffffc95                 call    _kdp_packet
F00707DC: 90020010                 add     %o0, %l0, %o0
F00707E0: 80a22000                 cmp     %o0, 0
F00707E4: 02800005                 be      loc_F00707F8
F00707E8: 113c04f1                 sethi   -0xFEC3C00, %o0
F00707EC: 7ffffe49                 call    sub_F0070110
F00707F0: d017bfee                 lduh    [%fp+var_12], %o0
F00707F4: 113c04f1                 sethi   -0xFEC3C00, %o0
F00707F8: d0022010                 ld      [%o0+0x10], %o0
F00707FC: 80a22000                 cmp     %o0, 0
F0070800: 12bfffc9                 bne     loc_F0070724
F0070804: c02425f4                 clr     [%l0+0x5F4]
F0070808: 81c7e008                 ret
F007080C: 81e80000                 restore
