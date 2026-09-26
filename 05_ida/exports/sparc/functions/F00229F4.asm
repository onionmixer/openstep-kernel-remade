F00229F4: 9de3bf98                 save    %sp, -0x68, %sp
F00229F8: a2100018                 mov     %i0, %l1
F00229FC: d0544000                 ldsh    [%l1], %o0
F0022A00: 80a22001                 cmp     %o0, 1
F0022A04: 02800006                 be      loc_F0022A1C
F0022A08: 80a22002                 cmp     %o0, 2
F0022A0C: 22800009                 be,a    loc_F0022A30
F0022A10: 113c042f                 sethi   -0xFEF4400, %o0
F0022A14: 1080000e                 ba      loc_F0022A4C
F0022A18: b0102000                 mov     0, %i0
F0022A1C: 113c042f                 sethi   %hi(_unpst_sendspace), %o0
F0022A20: d202212c                 ld      [%o0+%lo(_unpst_sendspace)], %o1
F0022A24: 113c042f                 sethi   %hi(_unpst_recvspace), %o0
F0022A28: 10800005                 ba      loc_F0022A3C
F0022A2C: d4022130                 ld      [%o0+%lo(_unpst_recvspace)], %o2
F0022A30: d2022134                 ld      [%o0+0x134], %o1! size_t
F0022A34: 113c042f                 sethi   %hi(_unpdg_recvspace), %o0
F0022A38: d4022138                 ld      [%o0+%lo(_unpdg_recvspace)], %o2
F0022A3C: 7ffff68e                 call    _soreserve
F0022A40: 90100011                 mov     %l1, %o0
F0022A44: 10800005                 ba      loc_F0022A58
F0022A48: b0100008                 mov     %o0, %i0
F0022A4C: 113c042f                 sethi   %hi(aUnpAttackBadSo), %o0! "unp_attack: bad so_type"
F0022A50: 7fffc9c8                 call    _panic
F0022A54: 90122140                 bset    %lo(aUnpAttackBadSo), %o0! "unp_attack: bad so_type"
F0022A58: 80a62000                 cmp     %i0, 0
F0022A5C: 1280000a                 bne     locret_F0022A84
F0022A60: 01000000                 nop
F0022A64: 40011583                 call    _kalloc
F0022A68: 90102024                 mov     0x24, %o0! void *
F0022A6C: a0100008                 mov     %o0, %l0
F0022A70: 4001c8fa                 call    _bzero
F0022A74: 92102024                 mov     0x24, %o1 ! '$'
F0022A78: e0246008                 st      %l0, [%l1+8]
F0022A7C: e2240000                 st      %l1, [%l0]
F0022A80: b0102000                 mov     0, %i0
F0022A84: 81c7e008                 ret
F0022A88: 81e80000                 restore
