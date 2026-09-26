F00838B4: 9de3bf98                 save    %sp, -0x68, %sp
F00838B8: 80a6a000                 cmp     %i2, 0
F00838BC: 22800043                 be,a    locret_F00839C8
F00838C0: b0102001                 mov     1, %i0
F00838C4: a2062010                 add     %i0, 0x10, %l1
F00838C8: 253c04f3                 sethi   -0xFEC3400, %l2
F00838CC: 293c04f3                 sethi   -0xFEC3400, %l4
F00838D0: 273c04f3                 sethi   -0xFEC3400, %l3
F00838D4: d0044000                 ld      [%l1], %o0
F00838D8: 80a22000                 cmp     %o0, 0
F00838DC: 12bffffe                 bne     loc_F00838D4
F00838E0: 01000000                 nop
F00838E4: 40004d71                 call    _simple_lock_try
F00838E8: 90100011                 mov     %l1, %o0
F00838EC: 80a22000                 cmp     %o0, 0
F00838F0: 02bffff9                 be      loc_F00838D4
F00838F4: 90100018                 mov     %i0, %o0
F00838F8: 92100019                 mov     %i1, %o1
F00838FC: 4000160c                 call    _vm_page_alloc_sequential
F0083900: 94102001                 mov     1, %o2
F0083904: a0920000                 orcc    %o0, %g0, %l0
F0083908: 12800023                 bne     loc_F0083994
F008390C: 01000000                 nop
F0083910: c0262010                 clr     [%i0+0x10]
F0083914: 80a6e000                 cmp     %i3, 0
F0083918: 12800004                 bne     loc_F0083928
F008391C: a014a020                 or      %l2, 0x20, %l0
F0083920: 1080002a                 ba      locret_F00839C8
F0083924: b0102000                 mov     0, %i0
F0083928: d0040000                 ld      [%l0], %o0
F008392C: 80a22000                 cmp     %o0, 0
F0083930: 12bffffe                 bne     loc_F0083928
F0083934: 01000000                 nop
F0083938: 40004d5c                 call    _simple_lock_try
F008393C: 90100010                 mov     %l0, %o0
F0083940: 80a22000                 cmp     %o0, 0
F0083944: 02bffff9                 be      loc_F0083928
F0083948: 90152018                 or      %l4, 0x18, %o0
F008394C: 92102000                 mov     0, %o1
F0083950: 7fffb5ab                 call    _thread_wakeup_prim
F0083954: 94102000                 mov     0, %o2
F0083958: 9014e000                 or      %l3, 0, %o0
F008395C: 9214a020                 or      %l2, 0x20, %o1
F0083960: 7fffb617                 call    _thread_sleep
F0083964: 94102000                 mov     0, %o2
F0083968: a0062010                 add     %i0, 0x10, %l0
F008396C: d0040000                 ld      [%l0], %o0
F0083970: 80a22000                 cmp     %o0, 0
F0083974: 12bffffe                 bne     loc_F008396C
F0083978: 01000000                 nop
F008397C: 40004d4b                 call    _simple_lock_try
F0083980: 90100010                 mov     %l0, %o0
F0083984: 80a22000                 cmp     %o0, 0
F0083988: 02bffff9                 be      loc_F008396C
F008398C: 90100018                 mov     %i0, %o0
F0083990: 30bfffda                 ba,a    loc_F00838F8
F0083994: c0262010                 clr     [%i0+0x10]
F0083998: 400017e1                 call    _vm_page_zero_fill
F008399C: 90100010                 mov     %l0, %o0
F00839A0: d0042020                 ld      [%l0+0x20], %o0
F00839A4: 13200000                 sethi   0x80000000, %o1
F00839A8: 922a0009                 andn    %o0, %o1, %o1
F00839AC: 113c0447                 sethi   %hi(_page_size), %o0
F00839B0: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F00839B4: d2242020                 st      %o1, [%l0+0x20]
F00839B8: b4a68008                 subcc   %i2, %o0, %i2
F00839BC: 12bfffc6                 bne     loc_F00838D4
F00839C0: b2064008                 add     %i1, %o0, %i1
F00839C4: b0102001                 mov     1, %i0
F00839C8: 81c7e008                 ret
F00839CC: 81e80000                 restore
