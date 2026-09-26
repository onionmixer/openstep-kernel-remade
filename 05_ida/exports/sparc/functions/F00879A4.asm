F00879A4: 9de3bf98                 save    %sp, -0x68, %sp
F00879A8: 80a62000                 cmp     %i0, 0
F00879AC: 02800020                 be      locret_F0087A2C
F00879B0: 01000000                 nop
F00879B4: e0060000                 ld      [%i0], %l0
F00879B8: 80a60010                 cmp     %i0, %l0
F00879BC: 0280001c                 be      locret_F0087A2C
F00879C0: 273c04f0                 sethi   -0xFEC4000, %l3
F00879C4: d0042018                 ld      [%l0+0x18], %o0
F00879C8: 80a64008                 cmp     %i1, %o0
F00879CC: 18800014                 bgu     loc_F0087A1C
F00879D0: e4042008                 ld      [%l0+8], %l2
F00879D4: 80a2001a                 cmp     %o0, %i2
F00879D8: 3a800012                 bcc,a   loc_F0087A20
F00879DC: a0100012                 mov     %l2, %l0
F00879E0: d0042024                 ld      [%l0+0x24], %o0
F00879E4: 40005785                 call    _pmap_remove_all
F00879E8: a214e230                 or      %l3, 0x230, %l1
F00879EC: d0044000                 ld      [%l1], %o0
F00879F0: 80a22000                 cmp     %o0, 0
F00879F4: 12bffffe                 bne     loc_F00879EC
F00879F8: 01000000                 nop
F00879FC: 40003d2b                 call    _simple_lock_try
F0087A00: 90100011                 mov     %l1, %o0
F0087A04: 80a22000                 cmp     %o0, 0
F0087A08: 02bffff9                 be      loc_F00879EC
F0087A0C: 01000000                 nop
F0087A10: 4000065a                 call    _vm_page_free
F0087A14: 90100010                 mov     %l0, %o0
F0087A18: c024e230                 clr     [%l3+0x230]
F0087A1C: a0100012                 mov     %l2, %l0
F0087A20: 80a60010                 cmp     %i0, %l0
F0087A24: 32bfffe9                 bne,a   loc_F00879C8
F0087A28: d0042018                 ld      [%l0+0x18], %o0
F0087A2C: 81c7e008                 ret
F0087A30: 81e80000                 restore
