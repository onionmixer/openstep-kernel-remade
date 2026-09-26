F000FB48: 9de3bf98                 save    %sp, -0x68, %sp
F000FB4C: 273c04cf                 sethi   %hi(dword_F0133DDC), %l3
F000FB50: d404e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o2
F000FB54: 9014e1dc                 or      %l3, %lo(dword_F0133DDC), %o0
F000FB58: d0023ffc                 ld      [%o0-4], %o0
F000FB5C: e202a024                 ld      [%o2+0x24], %l1
F000FB60: d2046004                 ld      [%l1+4], %o1
F000FB64: 80a26000                 cmp     %o1, 0
F000FB68: 16800005                 bge     loc_F000FB7C
F000FB6C: e0020000                 ld      [%o0], %l0
F000FB70: 90102016                 mov     0x16, %o0
F000FB74: 1080004e                 ba      locret_F000FCAC
F000FB78: d02aa038                 stb     %o0, [%o2+0x38]
F000FB7C: 7ffffbe9                 call    _get_posix_proc
F000FB80: d0542030                 ldsh    [%l0+0x30], %o0
F000FB84: d2044000                 ld      [%l1], %o1
F000FB88: 80a26000                 cmp     %o1, 0
F000FB8C: 02800025                 be      loc_F000FC20
F000FB90: a4100008                 mov     %o0, %l2
F000FB94: d0542030                 ldsh    [%l0+0x30], %o0
F000FB98: 80a24008                 cmp     %o1, %o0
F000FB9C: 02800022                 be      loc_F000FC24
F000FBA0: 96100012                 mov     %l2, %o3
F000FBA4: 7ffffa47                 call    _pfind
F000FBA8: 90100009                 mov     %o1, %o0
F000FBAC: a0920000                 orcc    %o0, %g0, %l0
F000FBB0: 02800007                 be      loc_F000FBCC
F000FBB4: d204e1dc                 ld      [%l3+0x1DC], %o1
F000FBB8: 7ffffa2e                 call    _inferior
F000FBBC: 01000000                 nop
F000FBC0: 80a22000                 cmp     %o0, 0
F000FBC4: 12800005                 bne     loc_F000FBD8
F000FBC8: d204e1dc                 ld      [%l3+0x1DC], %o1
F000FBCC: 90102003                 mov     3, %o0
F000FBD0: 10800037                 ba      locret_F000FCAC
F000FBD4: d02a6038                 stb     %o0, [%o1+0x38]
F000FBD8: 7ffffbd2                 call    _get_posix_proc
F000FBDC: d0542030                 ldsh    [%l0+0x30], %o0
F000FBE0: 96100008                 mov     %o0, %o3
F000FBE4: d002e010                 ld      [%o3+0x10], %o0
F000FBE8: d204a010                 ld      [%l2+0x10], %o1
F000FBEC: d4022008                 ld      [%o0+8], %o2
F000FBF0: d0026008                 ld      [%o1+8], %o0
F000FBF4: 80a28008                 cmp     %o2, %o0
F000FBF8: 12800026                 bne     loc_F000FC90
F000FBFC: d204e1dc                 ld      [%l3+0x1DC], %o1
F000FC00: d0042028                 ld      [%l0+0x28], %o0
F000FC04: 80a22000                 cmp     %o0, 0
F000FC08: 36800008                 bge,a   loc_F000FC28
F000FC0C: d002e010                 ld      [%o3+0x10], %o0
F000FC10: d204e1dc                 ld      [%l3+0x1DC], %o1
F000FC14: 9010200d                 mov     0xD, %o0
F000FC18: 10800025                 ba      locret_F000FCAC
F000FC1C: d02a6038                 stb     %o0, [%o1+0x38]
F000FC20: 96100012                 mov     %l2, %o3
F000FC24: d002e010                 ld      [%o3+0x10], %o0
F000FC28: d0022008                 ld      [%o0+8], %o0
F000FC2C: d0022004                 ld      [%o0+4], %o0
F000FC30: 80a20010                 cmp     %o0, %l0
F000FC34: 22800016                 be,a    loc_F000FC8C
F000FC38: 113c04cf                 sethi   -0xFECC400, %o0
F000FC3C: d2046004                 ld      [%l1+4], %o1
F000FC40: 80a26000                 cmp     %o1, 0
F000FC44: 12800004                 bne     loc_F000FC54
F000FC48: d0542030                 ldsh    [%l0+0x30], %o0
F000FC4C: 10800014                 ba      loc_F000FC9C
F000FC50: d0246004                 st      %o0, [%l1+4]
F000FC54: 80a24008                 cmp     %o1, %o0
F000FC58: 02800012                 be      loc_F000FCA0
F000FC5C: 90100010                 mov     %l0, %o0
F000FC60: 7ffffa80                 call    _pgfind
F000FC64: 90100009                 mov     %o1, %o0
F000FC68: 92920000                 orcc    %o0, %g0, %o1
F000FC6C: 02800008                 be      loc_F000FC8C
F000FC70: 113c04cf                 sethi   -0xFECC400, %o0
F000FC74: d004a010                 ld      [%l2+0x10], %o0
F000FC78: d2026008                 ld      [%o1+8], %o1
F000FC7C: d0022008                 ld      [%o0+8], %o0
F000FC80: 80a24008                 cmp     %o1, %o0
F000FC84: 02800006                 be      loc_F000FC9C
F000FC88: 113c04cf                 sethi   -0xFECC400, %o0
F000FC8C: d20221dc                 ld      [%o0+0x1DC], %o1
F000FC90: 90102001                 mov     1, %o0
F000FC94: 10800006                 ba      locret_F000FCAC
F000FC98: d02a6038                 stb     %o0, [%o1+0x38]
F000FC9C: 90100010                 mov     %l0, %o0
F000FCA0: d2046004                 ld      [%l1+4], %o1
F000FCA4: 7ffffa84                 call    _enterpgrp
F000FCA8: 94102000                 mov     0, %o2
F000FCAC: 81c7e008                 ret
F000FCB0: 81e80000                 restore
