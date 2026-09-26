F0082F44: 9de3bf98                 save    %sp, -0x68, %sp
F0082F48: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0082F4C: e406600c                 ld      [%i1+0xC], %l2
F0082F50: a0122230                 or      %o0, %lo(_vm_page_queue_lock), %l0
F0082F54: e2062024                 ld      [%i0+0x24], %l1
F0082F58: d0040000                 ld      [%l0], %o0
F0082F5C: 80a22000                 cmp     %o0, 0
F0082F60: 12bffffe                 bne     loc_F0082F58
F0082F64: 01000000                 nop
F0082F68: 40004fd0                 call    _simple_lock_try
F0082F6C: 90100010                 mov     %l0, %o0
F0082F70: 80a22000                 cmp     %o0, 0
F0082F74: 02bffff9                 be      loc_F0082F58
F0082F78: 01000000                 nop
F0082F7C: f0066008                 ld      [%i1+8], %i0
F0082F80: 80a60012                 cmp     %i0, %l2
F0082F84: 1a80001a                 bcc     loc_F0082FEC
F0082F88: 113c04f0                 sethi   -0xFEC4000, %o0
F0082F8C: 293c0446                 sethi   -0xFEEE800, %l4
F0082F90: 273c0447                 sethi   -0xFEEE400, %l3
F0082F94: 90100011                 mov     %l1, %o0
F0082F98: 40006ff0                 call    _pmap_extract
F0082F9C: 92100018                 mov     %i0, %o1
F0082FA0: a0920000                 orcc    %o0, %g0, %l0
F0082FA4: 32800005                 bne,a   loc_F0082FB8
F0082FA8: 90100011                 mov     %l1, %o0! char *
F0082FAC: 7ffe4871                 call    _panic
F0082FB0: 90152158                 or      %l4, 0x158, %o0
F0082FB4: 90100011                 mov     %l1, %o0
F0082FB8: 92100018                 mov     %i0, %o1
F0082FBC: 40006f1b                 call    _pmap_change_wiring
F0082FC0: 94102000                 mov     0, %o2
F0082FC4: 40000d22                 call    _vm_phys_to_vm_page
F0082FC8: 90100010                 mov     %l0, %o0
F0082FCC: 400019a1                 call    _vm_page_unwire
F0082FD0: 01000000                 nop
F0082FD4: d004e13c                 ld      [%l3+0x13C], %o0
F0082FD8: b0060008                 add     %i0, %o0, %i0
F0082FDC: 80a60012                 cmp     %i0, %l2
F0082FE0: 0abfffee                 bcs     loc_F0082F98
F0082FE4: 90100011                 mov     %l1, %o0
F0082FE8: 113c04f0                 sethi   -0xFEC4000, %o0
F0082FEC: c0222230                 clr     [%o0+0x230]
F0082FF0: 90100011                 mov     %l1, %o0
F0082FF4: d2066008                 ld      [%i1+8], %o1
F0082FF8: 94100012                 mov     %l2, %o2
F0082FFC: 400072e6                 call    _pmap_pageable
F0083000: 96102001                 mov     1, %o3
F0083004: 81c7e008                 ret
F0083008: 81e80000                 restore
