F0010844: 9de3bf98                 save    %sp, -0x68, %sp
F0010848: 113c04d0                 sethi   %hi(_active_threads), %o0
F001084C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0010850: d002200c                 ld      [%o0+0xC], %o0
F0010854: e002203c                 ld      [%o0+0x3C], %l0
F0010858: 7ffff71a                 call    _pfind
F001085C: 90102001                 mov     1, %o0! target_task
F0010860: a2920000                 orcc    %o0, %g0, %l1
F0010864: 02800006                 be      loc_F001087C
F0010868: 80a44010                 cmp     %l1, %l0
F001086C: 02800004                 be      loc_F001087C
F0010870: 01000000                 nop
F0010874: 40018c71                 call    _task_suspend
F0010878: d0046068                 ld      [%l1+0x68], %o0
F001087C: 7ffff711                 call    _pfind
F0010880: 90102002                 mov     2, %o0
F0010884: a2920000                 orcc    %o0, %g0, %l1
F0010888: 02800006                 be      loc_F00108A0
F001088C: 80a44010                 cmp     %l1, %l0
F0010890: 22800005                 be,a    loc_F00108A4
F0010894: 113c042c                 sethi   -0xFEF5000, %o0! target_task
F0010898: 40018c68                 call    _task_suspend
F001089C: d0046068                 ld      [%l1+0x68], %o0
F00108A0: 113c042c                 sethi   -0xFEF5000, %o0! char *
F00108A4: 40000f6d                 call    _printf
F00108A8: 90122220                 bset    0x220, %o0
F00108AC: 113c04d3                 sethi   %hi(_allproc), %o0
F00108B0: e2022278                 ld      [%o0+%lo(_allproc)], %l1
F00108B4: 80a46000                 cmp     %l1, 0
F00108B8: 02800014                 be      loc_F0010908
F00108BC: 01000000                 nop
F00108C0: d0546032                 ldsh    [%l1+0x32], %o0
F00108C4: 80a22000                 cmp     %o0, 0
F00108C8: 2280000d                 be,a    loc_F00108FC
F00108CC: e2046008                 ld      [%l1+8], %l1
F00108D0: d0046028                 ld      [%l1+0x28], %o0
F00108D4: 808a2002                 btst    2, %o0
F00108D8: 32800009                 bne,a   loc_F00108FC
F00108DC: e2046008                 ld      [%l1+8], %l1
F00108E0: 80a44010                 cmp     %l1, %l0
F00108E4: 22800006                 be,a    loc_F00108FC
F00108E8: e2046008                 ld      [%l1+8], %l1
F00108EC: 90100011                 mov     %l1, %o0! unsigned int
F00108F0: 40000321                 call    _psignal
F00108F4: 9210200f                 mov     0xF, %o1
F00108F8: e2046008                 ld      [%l1+8], %l1
F00108FC: 80a46000                 cmp     %l1, 0
F0010900: 32bffff1                 bne,a   loc_F00108C4
F0010904: d0546032                 ldsh    [%l1+0x32], %o0
F0010908: 90102000                 mov     0, %o0
F001090C: 131dcd65                 sethi   0x77359400, %o1
F0010910: 4001761f                 call    _ns_sleep
F0010914: 01000000                 nop
F0010918: 90102000                 mov     0, %o0
F001091C: 131dcd65                 sethi   0x77359400, %o1! char *
F0010920: 4001761b                 call    _ns_sleep
F0010924: 01000000                 nop
F0010928: 113c04d3                 sethi   %hi(_allproc), %o0
F001092C: e2022278                 ld      [%o0+%lo(_allproc)], %l1
F0010930: 80a46000                 cmp     %l1, 0
F0010934: 02800014                 be      loc_F0010984
F0010938: 01000000                 nop
F001093C: d0546032                 ldsh    [%l1+0x32], %o0
F0010940: 80a22000                 cmp     %o0, 0
F0010944: 2280000d                 be,a    loc_F0010978
F0010948: e2046008                 ld      [%l1+8], %l1
F001094C: d0046028                 ld      [%l1+0x28], %o0
F0010950: 808a2002                 btst    2, %o0
F0010954: 32800009                 bne,a   loc_F0010978
F0010958: e2046008                 ld      [%l1+8], %l1
F001095C: 80a44010                 cmp     %l1, %l0
F0010960: 22800006                 be,a    loc_F0010978
F0010964: e2046008                 ld      [%l1+8], %l1
F0010968: 90100011                 mov     %l1, %o0! unsigned int
F001096C: 40000302                 call    _psignal
F0010970: 92102009                 mov     9, %o1
F0010974: e2046008                 ld      [%l1+8], %l1
F0010978: 80a46000                 cmp     %l1, 0
F001097C: 32bffff1                 bne,a   loc_F0010940
F0010980: d0546032                 ldsh    [%l1+0x32], %o0
F0010984: 90102000                 mov     0, %o0
F0010988: 130ee6b292126200         set     0x3B9ACA00, %o1
F0010990: 400175ff                 call    _ns_sleep
F0010994: 01000000                 nop
F0010998: 113c04d3                 sethi   %hi(_allproc), %o0
F001099C: e2022278                 ld      [%o0+%lo(_allproc)], %l1
F00109A0: 80a46000                 cmp     %l1, 0
F00109A4: 22800024                 be,a    loc_F0010A34
F00109A8: 113c042c                 sethi   -0xFEF5000, %o0
F00109AC: 293c04d0                 sethi   -0xFECC000, %l4
F00109B0: 273c042c                 sethi   -0xFEF5000, %l3
F00109B4: a4100008                 mov     %o0, %l2
F00109B8: d0546032                 ldsh    [%l1+0x32], %o0
F00109BC: 80a22000                 cmp     %o0, 0
F00109C0: 22800019                 be,a    loc_F0010A24
F00109C4: e2046008                 ld      [%l1+8], %l1
F00109C8: d0046028                 ld      [%l1+0x28], %o0
F00109CC: 808a2002                 btst    2, %o0
F00109D0: 32800015                 bne,a   loc_F0010A24
F00109D4: e2046008                 ld      [%l1+8], %l1
F00109D8: 80a44010                 cmp     %l1, %l0
F00109DC: 32800004                 bne,a   loc_F00109EC
F00109E0: d0046078                 ld      [%l1+0x78], %o0
F00109E4: 10800010                 ba      loc_F0010A24
F00109E8: e2046008                 ld      [%l1+8], %l1
F00109EC: 80a22000                 cmp     %o0, 0
F00109F0: 02800006                 be      loc_F0010A08
F00109F4: d2052260                 ld      [%l4+0x260], %o1
F00109F8: 40018732                 call    _thread_block
F00109FC: 01000000                 nop
F0010A00: 10800009                 ba      loc_F0010A24
F0010A04: e204a278                 ld      [%l2+0x278], %l1
F0010A08: 9014e238                 or      %l3, 0x238, %o0! char *
F0010A0C: 40000f13                 call    _printf
F0010A10: d2246078                 st      %o1, [%l1+0x78]
F0010A14: 90100011                 mov     %l1, %o0
F0010A18: 7fffef4a                 call    _do_exit
F0010A1C: 92102001                 mov     1, %o1
F0010A20: e204a278                 ld      [%l2+0x278], %l1
F0010A24: 80a46000                 cmp     %l1, 0
F0010A28: 32bfffe5                 bne,a   loc_F00109BC
F0010A2C: d0546032                 ldsh    [%l1+0x32], %o0
F0010A30: 113c042c                 sethi   -0xFEF5000, %o0! char *
F0010A34: 40000f09                 call    _printf
F0010A38: 90122240                 bset    0x240, %o0
F0010A3C: 113c04d3                 sethi   %hi(_allproc), %o0
F0010A40: e2022278                 ld      [%o0+%lo(_allproc)], %l1
F0010A44: 80a46000                 cmp     %l1, 0
F0010A48: 02800038                 be      loc_F0010B28
F0010A4C: 113c04d4                 sethi   -0xFECB000, %o0
F0010A50: 2b3fffc0                 sethi   -0x10000, %l5
F0010A54: d0046068                 ld      [%l1+0x68], %o0
F0010A58: e6022038                 ld      [%o0+0x38], %l3
F0010A5C: 92102000                 mov     0, %o1
F0010A60: d004e154                 ld      [%l3+0x154], %o0
F0010A64: 80a24008                 cmp     %o1, %o0
F0010A68: 14800018                 bg      loc_F0010AC8
F0010A6C: a4102000                 mov     0, %l2
F0010A70: d004e14c                 ld      [%l3+0x14C], %o0
F0010A74: a92ca002                 sll     %l2, 2, %l4
F0010A78: e0020014                 ld      [%o0+%l4], %l0
F0010A7C: 80a42000                 cmp     %l0, 0
F0010A80: 0280000b                 be      loc_F0010AAC
F0010A84: 80a40015                 cmp     %l0, %l5
F0010A88: 2280000a                 be,a    loc_F0010AB0
F0010A8C: d004e150                 ld      [%l3+0x150], %o0
F0010A90: 400056b9                 call    _vno_lockrelease
F0010A94: 90100010                 mov     %l0, %o0
F0010A98: d204e14c                 ld      [%l3+0x14C], %o1
F0010A9C: 90100010                 mov     %l0, %o0
F0010AA0: 7fffea90                 call    _closef
F0010AA4: c0224014                 clr     [%o1+%l4]
F0010AA8: 92102001                 mov     1, %o1
F0010AAC: d004e150                 ld      [%l3+0x150], %o0
F0010AB0: c02a0012                 clrb    [%o0+%l2]
F0010AB4: d004e154                 ld      [%l3+0x154], %o0
F0010AB8: a404a001                 inc     %l2
F0010ABC: 80a48008                 cmp     %l2, %o0
F0010AC0: 24bfffed                 ble,a   loc_F0010A74
F0010AC4: d004e14c                 ld      [%l3+0x14C], %o0
F0010AC8: d004e15c                 ld      [%l3+0x15C], %o0
F0010ACC: 80a22000                 cmp     %o0, 0
F0010AD0: 22800006                 be,a    loc_F0010AE8
F0010AD4: d004e160                 ld      [%l3+0x160], %o0
F0010AD8: 40006023                 call    _vn_rele
F0010ADC: c024e15c                 clr     [%l3+0x15C]
F0010AE0: 92102001                 mov     1, %o1
F0010AE4: d004e160                 ld      [%l3+0x160], %o0
F0010AE8: 80a22000                 cmp     %o0, 0
F0010AEC: 02800006                 be      loc_F0010B04
F0010AF0: 80a26000                 cmp     %o1, 0
F0010AF4: 4000601c                 call    _vn_rele
F0010AF8: c024e160                 clr     [%l3+0x160]
F0010AFC: 92102001                 mov     1, %o1
F0010B00: 80a26000                 cmp     %o1, 0
F0010B04: 02800004                 be      loc_F0010B14
F0010B08: 113c04d3                 sethi   %hi(_allproc), %o0
F0010B0C: 10800003                 ba      loc_F0010B18
F0010B10: e2022278                 ld      [%o0+%lo(_allproc)], %l1
F0010B14: e2046008                 ld      [%l1+8], %l1
F0010B18: 80a46000                 cmp     %l1, 0
F0010B1C: 32bfffcf                 bne,a   loc_F0010A58
F0010B20: d0046068                 ld      [%l1+0x68], %o0
F0010B24: 113c04d4                 sethi   -0xFECB000, %o0
F0010B28: 90122150                 bset    0x150, %o0
F0010B2C: 92102000                 mov     0, %o1
F0010B30: 40018133                 call    _thread_wakeup_prim
F0010B34: 94102000                 mov     0, %o2
F0010B38: 90102000                 mov     0, %o0
F0010B3C: 131dcd65                 sethi   0x77359400, %o1
F0010B40: 40017593                 call    _ns_sleep
F0010B44: 01000000                 nop
F0010B48: 113c042c                 sethi   %hi(aContinuing), %o0! "continuing\n"
F0010B4C: 40000ec3                 call    _printf
F0010B50: 90122248                 bset    %lo(aContinuing), %o0! "continuing\n"
F0010B54: 81c7e008                 ret
F0010B58: 81e80000                 restore
