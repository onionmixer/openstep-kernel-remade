F0021F40: 9de3bf90                 save    %sp, -0x70, %sp
F0021F44: 90102001                 mov     1, %o0
F0021F48: 9207bff4                 add     %fp, var_C, %o1
F0021F4C: 94102001                 mov     1, %o2
F0021F50: 7ffff1a7                 call    _socreate
F0021F54: 96102000                 mov     0, %o3
F0021F58: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F0021F5C: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0021F60: d02a6038                 stb     %o0, [%o1+0x38]
F0021F64: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F0021F68: d04a2038                 ldsb    [%o0+0x38], %o0
F0021F6C: 80a22000                 cmp     %o0, 0
F0021F70: 1280006a                 bne     locret_F0022118
F0021F74: a614a1dc                 or      %l2, %lo(dword_F0133DDC), %l3
F0021F78: 90102001                 mov     1, %o0
F0021F7C: 9207bff0                 add     %fp, var_10, %o1
F0021F80: 94102001                 mov     1, %o2
F0021F84: 7ffff19a                 call    _socreate
F0021F88: 96102000                 mov     0, %o3
F0021F8C: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0021F90: d02a6038                 stb     %o0, [%o1+0x38]
F0021F94: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F0021F98: d04a2038                 ldsb    [%o0+0x38], %o0
F0021F9C: 80a22000                 cmp     %o0, 0
F0021FA0: 1280005c                 bne     loc_F0022110
F0021FA4: 01000000                 nop
F0021FA8: 7fffa50f                 call    _falloc
F0021FAC: 01000000                 nop
F0021FB0: a2920000                 orcc    %o0, %g0, %l1
F0021FB4: 02800055                 be      loc_F0022108
F0021FB8: d004a1dc                 ld      [%l2+0x1DC], %o0
F0021FBC: ee022030                 ld      [%o0+0x30], %l7
F0021FC0: 90102001                 mov     1, %o0
F0021FC4: d0246008                 st      %o0, [%l1+8]
F0021FC8: d004fffc                 ld      [%l3-4], %o0
F0021FCC: d0020000                 ld      [%o0], %o0
F0021FD0: d0022014                 ld      [%o0+0x14], %o0
F0021FD4: 2d000010                 sethi   0x4000, %l6
F0021FD8: 808a0016                 btst    %l6, %o0
F0021FDC: 02800004                 be      loc_F0021FEC
F0021FE0: 11000008                 sethi   0x2000, %o0
F0021FE4: 90122001                 bset    1, %o0
F0021FE8: d0246008                 st      %o0, [%l1+8]
F0021FEC: aa102002                 mov     2, %l5
F0021FF0: ea34600c                 sth     %l5, [%l1+0xC]
F0021FF4: 113c042da8122190         set     _socketops, %l4
F0021FFC: d007bff4                 ld      [%fp+var_C], %o0
F0022000: e8246014                 st      %l4, [%l1+0x14]
F0022004: d0246018                 st      %o0, [%l1+0x18]
F0022008: d004a1dc                 ld      [%l2+0x1DC], %o0
F002200C: d204fffc                 ld      [%l3-4], %o1
F0022010: d0022030                 ld      [%o0+0x30], %o0
F0022014: d202614c                 ld      [%o1+0x14C], %o1
F0022018: 912a2002                 sll     %o0, 2, %o0
F002201C: 7fffa4f2                 call    _falloc
F0022020: e2224008                 st      %l1, [%o1+%o0]
F0022024: a0920000                 orcc    %o0, %g0, %l0
F0022028: 22800033                 be,a    loc_F00220F4
F002202C: c034600e                 clrh    [%l1+0xE]
F0022030: 90102002                 mov     2, %o0
F0022034: d0242008                 st      %o0, [%l0+8]
F0022038: d004fffc                 ld      [%l3-4], %o0
F002203C: d0020000                 ld      [%o0], %o0
F0022040: d0022014                 ld      [%o0+0x14], %o0
F0022044: 808a0016                 btst    %l6, %o0
F0022048: 02800004                 be      loc_F0022058
F002204C: 11000008                 sethi   0x2000, %o0
F0022050: 90122002                 bset    2, %o0
F0022054: d0242008                 st      %o0, [%l0+8]
F0022058: ea34200c                 sth     %l5, [%l0+0xC]
F002205C: d007bff0                 ld      [%fp+var_10], %o0
F0022060: e8242014                 st      %l4, [%l0+0x14]
F0022064: d0242018                 st      %o0, [%l0+0x18]
F0022068: d204a1dc                 ld      [%l2+0x1DC], %o1
F002206C: d404fffc                 ld      [%l3-4], %o2
F0022070: d2026030                 ld      [%o1+0x30], %o1
F0022074: d402a14c                 ld      [%o2+0x14C], %o2
F0022078: 932a6002                 sll     %o1, 2, %o1
F002207C: e0228009                 st      %l0, [%o2+%o1]
F0022080: d404a1dc                 ld      [%l2+0x1DC], %o2
F0022084: d602a030                 ld      [%o2+0x30], %o3
F0022088: d622a034                 st      %o3, [%o2+0x34]
F002208C: d404a1dc                 ld      [%l2+0x1DC], %o2
F0022090: d207bff4                 ld      [%fp+var_C], %o1
F0022094: 4000030e                 call    _unp_connect2
F0022098: ee22a030                 st      %l7, [%o2+0x30]
F002209C: 932a2018                 sll     %o0, 24, %o1
F00220A0: d404a1dc                 ld      [%l2+0x1DC], %o2
F00220A4: 80a26000                 cmp     %o1, 0
F00220A8: 1280000b                 bne     loc_F00220D4
F00220AC: d02aa038                 stb     %o0, [%o2+0x38]
F00220B0: d207bff0                 ld      [%fp+var_10], %o1
F00220B4: d0126006                 lduh    [%o1+6], %o0
F00220B8: d407bff4                 ld      [%fp+var_C], %o2
F00220BC: 90122020                 bset    0x20, %o0 ! ' '
F00220C0: d0326006                 sth     %o0, [%o1+6]
F00220C4: d012a006                 lduh    [%o2+6], %o0
F00220C8: 90122010                 bset    0x10, %o0
F00220CC: 10800013                 ba      locret_F0022118
F00220D0: d032a006                 sth     %o0, [%o2+6]
F00220D4: c034200e                 clrh    [%l0+0xE]
F00220D8: d004a1dc                 ld      [%l2+0x1DC], %o0
F00220DC: d204fffc                 ld      [%l3-4], %o1
F00220E0: d0022034                 ld      [%o0+0x34], %o0
F00220E4: d202614c                 ld      [%o1+0x14C], %o1
F00220E8: 912a2002                 sll     %o0, 2, %o0
F00220EC: c0224008                 clr     [%o1+%o0]
F00220F0: c034600e                 clrh    [%l1+0xE]
F00220F4: 113c04cf                 sethi   %hi(_active_u), %o0
F00220F8: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00220FC: d202214c                 ld      [%o0+0x14C], %o1
F0022100: 912de002                 sll     %l7, 2, %o0
F0022104: c0224008                 clr     [%o1+%o0]
F0022108: 7ffff1cf                 call    _soclose
F002210C: d007bff0                 ld      [%fp+var_10], %o0
F0022110: 7ffff1cd                 call    _soclose
F0022114: d007bff4                 ld      [%fp+var_C], %o0
F0022118: 81c7e008                 ret
F002211C: 81e80000                 restore
