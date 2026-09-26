F00689E8: 9de3bf98                 save    %sp, -0x68, %sp
F00689EC: 113c04d0                 sethi   %hi(_page_mask), %o0
F00689F0: 133c04f0                 sethi   %hi(_stackStats), %o1
F00689F4: d80220d8                 ld      [%o0+%lo(_page_mask)], %o4
F00689F8: a21260c0                 or      %o1, %lo(_stackStats), %l1
F00689FC: d204600c                 ld      [%l1+0xC], %o1
F0068A00: 273c04bd                 sethi   %hi(dword_F012F678), %l3
F0068A04: d404e278                 ld      [%l3+%lo(dword_F012F678)], %o2
F0068A08: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0068A0C: 9638000c                 xnor    %g0, %o4, %o3
F0068A10: a00e000b                 and     %i0, %o3, %l0
F0068A14: b0063ff4                 inc     -0xC, %i0
F0068A18: 92027fff                 inc     -1, %o1
F0068A1C: d224600c                 st      %o1, [%l1+0xC]
F0068A20: 9404000a                 add     %l0, %o2, %o2
F0068A24: 9402800c                 add     %o2, %o4, %o2
F0068A28: 92100010                 mov     %l0, %o1
F0068A2C: 940a800b                 and     %o2, %o3, %o2
F0068A30: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F0068A34: 400070ee                 call    _vm_map_pageable
F0068A38: 96102000                 mov     0, %o3
F0068A3C: 113c04f0a41220e0         set     _stack_queue_lock, %l2
F0068A44: 400000e0                 call    _lock_write
F0068A48: 90100012                 mov     %l2, %o0
F0068A4C: 90102002                 mov     2, %o0
F0068A50: d0262008                 st      %o0, [%i0+8]
F0068A54: 113fbb7e                 sethi   -0x1120800, %o0
F0068A58: d2040000                 ld      [%l0], %o1
F0068A5C: 901222ce                 bset    0x2CE, %o0
F0068A60: 80a24008                 cmp     %o1, %o0
F0068A64: 1280001c                 bne     loc_F0068AD4
F0068A68: 90100012                 mov     %l2, %o0
F0068A6C: c0240000                 clr     [%l0]
F0068A70: b0100010                 mov     %l0, %i0
F0068A74: a0102000                 mov     0, %l0
F0068A78: d0046010                 ld      [%l1+0x10], %o0
F0068A7C: 153c04bd                 sethi   %hi(dword_F012F67C), %o2
F0068A80: d202a27c                 ld      [%o2+%lo(dword_F012F67C)], %o1
F0068A84: 90023fff                 inc     -1, %o0
F0068A88: 80a40009                 cmp     %l0, %o1
F0068A8C: 16800010                 bge     loc_F0068ACC
F0068A90: d0246010                 st      %o0, [%l1+0x10]
F0068A94: a4100013                 mov     %l3, %l2
F0068A98: a210000a                 mov     %o2, %l1
F0068A9C: d0062008                 ld      [%i0+8], %o0
F0068AA0: 80a22000                 cmp     %o0, 0
F0068AA4: 12800005                 bne     loc_F0068AB8
F0068AA8: d204a278                 ld      [%l2+0x278], %o1
F0068AAC: 7ffffe36                 call    sub_F0068384
F0068AB0: 90100018                 mov     %i0, %o0
F0068AB4: d204a278                 ld      [%l2+0x278], %o1
F0068AB8: a0042001                 inc     %l0
F0068ABC: d004627c                 ld      [%l1+0x27C], %o0
F0068AC0: 80a40008                 cmp     %l0, %o0
F0068AC4: 06bffff6                 bl      loc_F0068A9C
F0068AC8: b0060009                 add     %i0, %o1, %i0
F0068ACC: 113c04f0901220e0         set     _stack_queue_lock, %o0
F0068AD4: 40000158                 call    _lock_done
F0068AD8: 01000000                 nop
F0068ADC: 81c7e008                 ret
F0068AE0: 81e80000                 restore
