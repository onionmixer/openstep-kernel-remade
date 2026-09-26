F0082EC8: 9de3bf98                 save    %sp, -0x68, %sp
F0082ECC: d0062024                 ld      [%i0+0x24], %o0
F0082ED0: e206600c                 ld      [%i1+0xC], %l1
F0082ED4: 96102000                 mov     0, %o3
F0082ED8: d2066008                 ld      [%i1+8], %o1
F0082EDC: 4000732e                 call    _pmap_pageable
F0082EE0: 94100011                 mov     %l1, %o2
F0082EE4: e0066008                 ld      [%i1+8], %l0
F0082EE8: 80a40011                 cmp     %l0, %l1
F0082EEC: 1a800014                 bcc     locret_F0082F3C
F0082EF0: 253c0447                 sethi   -0xFEEE400, %l2
F0082EF4: 90100018                 mov     %i0, %o0
F0082EF8: 92100010                 mov     %l0, %o1
F0082EFC: 400000d2                 call    _vm_fault_wire_fast
F0082F00: 94100019                 mov     %i1, %o2
F0082F04: 80a22000                 cmp     %o0, 0
F0082F08: 02800009                 be      loc_F0082F2C
F0082F0C: d004a13c                 ld      [%l2+0x13C], %o0
F0082F10: 90100018                 mov     %i0, %o0
F0082F14: 92100010                 mov     %l0, %o1
F0082F18: 94102000                 mov     0, %o2
F0082F1C: 96102001                 mov     1, %o3
F0082F20: 7ffff8db                 call    _vm_fault
F0082F24: 98102000                 mov     0, %o4
F0082F28: d004a13c                 ld      [%l2+0x13C], %o0
F0082F2C: a0040008                 add     %l0, %o0, %l0
F0082F30: 80a40011                 cmp     %l0, %l1
F0082F34: 0abffff1                 bcs     loc_F0082EF8
F0082F38: 90100018                 mov     %i0, %o0
F0082F3C: 81c7e008                 ret
F0082F40: 81e80000                 restore
