F00776C8: 9de3bf90                 save    %sp, -0x70, %sp
F00776CC: 4000808f                 call    _clock_value
F00776D0: 90102001                 mov     1, %o0
F00776D4: 9407bff0                 add     %fp, var_10, %o2
F00776D8: d427bff4                 st      %o2, [%fp+var_C]
F00776DC: a4100008                 mov     %o0, %l2
F00776E0: a6100009                 mov     %o1, %l3
F00776E4: 40007d29                 call    _splusclock
F00776E8: d427bff0                 st      %o2, [%fp+var_10]
F00776EC: ac100008                 mov     %o0, %l6
F00776F0: 113c04c3a0122320         set     dword_F0130F20, %l0
F00776F8: d0040000                 ld      [%l0], %o0
F00776FC: 80a22000                 cmp     %o0, 0
F0077700: 12bffffe                 bne     loc_F00776F8
F0077704: 01000000                 nop
F0077708: 40007de8                 call    _simple_lock_try
F007770C: 90100010                 mov     %l0, %o0
F0077710: 80a22000                 cmp     %o0, 0
F0077714: 02bffff9                 be      loc_F00776F8
F0077718: 113c04c3                 sethi   %hi(dword_F0130F34), %o0
F007771C: c4022334                 ld      [%o0+%lo(dword_F0130F34)], %g2
F0077720: 92122334                 or      %o0, %lo(dword_F0130F34), %o1
F0077724: 80a08009                 cmp     %g2, %o1
F0077728: 22800021                 be,a    loc_F00777AC
F007772C: 90122334                 bset    %lo(dword_F0130F34), %o0
F0077730: 98100008                 mov     %o0, %o4
F0077734: 9407bff0                 add     %fp, var_10, %o2
F0077738: 96100009                 mov     %o1, %o3
F007773C: d000a018                 ld      [%g2+0x18], %o0
F0077740: 80a20012                 cmp     %o0, %l2
F0077744: 38800019                 bgu,a   loc_F00777A8
F0077748: 113c04c3                 sethi   -0xFECF400, %o0
F007774C: 32800007                 bne,a   loc_F0077768
F0077750: d2008000                 ld      [%g2], %o1
F0077754: d000a01c                 ld      [%g2+0x1C], %o0
F0077758: 80a20013                 cmp     %o0, %l3
F007775C: 18800013                 bgu     loc_F00777A8
F0077760: 113c04c3                 sethi   -0xFECF400, %o0
F0077764: d2008000                 ld      [%g2], %o1
F0077768: d000a004                 ld      [%g2+4], %o0
F007776C: d0226004                 st      %o0, [%o1+4]
F0077770: d200a004                 ld      [%g2+4], %o1
F0077774: d0008000                 ld      [%g2], %o0
F0077778: d0224000                 st      %o0, [%o1]
F007777C: c020a020                 clr     [%g2+0x20]
F0077780: d4208000                 st      %o2, [%g2]
F0077784: d007bff4                 ld      [%fp+var_C], %o0
F0077788: d020a004                 st      %o0, [%g2+4]
F007778C: c4220000                 st      %g2, [%o0]
F0077790: c427bff4                 st      %g2, [%fp+var_C]
F0077794: c4032334                 ld      [%o4+0x334], %g2
F0077798: 80a0800b                 cmp     %g2, %o3
F007779C: 32bfffe9                 bne,a   loc_F0077740
F00777A0: d000a018                 ld      [%g2+0x18], %o0
F00777A4: 113c04c3                 sethi   -0xFECF400, %o0
F00777A8: 90122334                 bset    0x334, %o0
F00777AC: 80a08008                 cmp     %g2, %o0
F00777B0: 02800005                 be      loc_F00777C4
F00777B4: a407bff0                 add     %fp, var_10, %l2
F00777B8: 7ffffbe1                 call    sub_F007673C
F00777BC: 90100002                 mov     %g2, %o0
F00777C0: a407bff0                 add     %fp, var_10, %l2
F00777C4: 113c04c3a212232c         set     dword_F0130F2C, %l1
F00777CC: 273c04c3                 sethi   -0xFECF400, %l3
F00777D0: 2b3c04c3                 sethi   -0xFECF400, %l5
F00777D4: 293c04c3                 sethi   -0xFECF400, %l4
F00777D8: d207bff0                 ld      [%fp+var_10], %o1
F00777DC: 80a24012                 cmp     %o1, %l2
F00777E0: 32800004                 bne,a   loc_F00777F0
F00777E4: d0024000                 ld      [%o1], %o0
F00777E8: 10800006                 ba      loc_F0077800
F00777EC: 84102000                 mov     0, %g2
F00777F0: e4222004                 st      %l2, [%o0+4]
F00777F4: d0024000                 ld      [%o1], %o0
F00777F8: 84100009                 mov     %o1, %g2
F00777FC: d027bff0                 st      %o0, [%fp+var_10]
F0077800: 80a0a000                 cmp     %g2, 0
F0077804: 02800029                 be      loc_F00778A8
F0077808: 92102001                 mov     1, %o1
F007780C: e2208000                 st      %l1, [%g2]
F0077810: 9014e33c                 or      %l3, 0x33C, %o0
F0077814: d6046004                 ld      [%l1+4], %o3
F0077818: 98102001                 mov     1, %o4
F007781C: da04e33c                 ld      [%l3+0x33C], %o5
F0077820: d620a004                 st      %o3, [%g2+4]
F0077824: c422c000                 st      %g2, [%o3]
F0077828: c4246004                 st      %g2, [%l1+4]
F007782C: 9a036001                 inc     %o5
F0077830: da24e33c                 st      %o5, [%l3+0x33C]
F0077834: 173c04c3                 sethi   %hi(dword_F0130F40), %o3
F0077838: d820a020                 st      %o4, [%g2+0x20]
F007783C: d602e340                 ld      [%o3+%lo(dword_F0130F40)], %o3
F0077840: c0252320                 clr     [%l4+0x320]
F0077844: d8056344                 ld      [%l5+0x344], %o4
F0077848: 9602c00d                 add     %o3, %o5, %o3
F007784C: 80a3000b                 cmp     %o4, %o3
F0077850: 26800003                 bl,a    loc_F007785C
F0077854: a0102001                 mov     1, %l0
F0077858: a0102000                 mov     0, %l0
F007785C: 7fffe5e8                 call    _thread_wakeup_prim
F0077860: 94102000                 mov     0, %o2
F0077864: 80a42000                 cmp     %l0, 0
F0077868: 02800006                 be      loc_F0077880
F007786C: a0152320                 or      %l4, 0x320, %l0
F0077870: 90156344                 or      %l5, 0x344, %o0
F0077874: 92102001                 mov     1, %o1
F0077878: 7fffe5e1                 call    _thread_wakeup_prim
F007787C: 94102000                 mov     0, %o2
F0077880: d0040000                 ld      [%l0], %o0
F0077884: 80a22000                 cmp     %o0, 0
F0077888: 12bffffe                 bne     loc_F0077880
F007788C: 01000000                 nop
F0077890: 40007d86                 call    _simple_lock_try
F0077894: 90100010                 mov     %l0, %o0
F0077898: 80a22000                 cmp     %o0, 0
F007789C: 02bffff9                 be      loc_F0077880
F00778A0: d207bff0                 ld      [%fp+var_10], %o1
F00778A4: 30bfffce                 ba,a    loc_F00777DC
F00778A8: 113c04c3                 sethi   %hi(dword_F0130F20), %o0
F00778AC: c0222320                 clr     [%o0+%lo(dword_F0130F20)]
F00778B0: 40007d1d                 call    _splx
F00778B4: 90100016                 mov     %l6, %o0
F00778B8: 81c7e008                 ret
F00778BC: 81e80000                 restore
