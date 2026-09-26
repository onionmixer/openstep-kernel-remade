F0047258: 9de3bf98                 save    %sp, -0x68, %sp
F004725C: d016608a                 lduh    [%i1+0x8A], %o0
F0047260: d206606c                 ld      [%i1+0x6C], %o1
F0047264: 90023fff                 inc     -1, %o0
F0047268: 80a24018                 cmp     %o1, %i0
F004726C: 12800005                 bne     loc_F0047280
F0047270: d036608a                 sth     %o0, [%i1+0x8A]
F0047274: c026606c                 clr     [%i1+0x6C]
F0047278: 10800003                 ba      loc_F0047284
F004727C: a2102000                 mov     0, %l1
F0047280: e2060000                 ld      [%i0], %l1
F0047284: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0047288: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F004728C: 213c043c                 sethi   %hi(dword_F010F39C), %l0
F0047290: d404239c                 ld      [%l0+%lo(dword_F010F39C)], %o2
F0047294: 4000f17c                 call    _kmem_free
F0047298: 92100018                 mov     %i0, %o1
F004729C: 333c04eb                 sethi   %hi(_fifo_alloc), %i1
F00472A0: d2066128                 ld      [%i1+%lo(_fifo_alloc)], %o1
F00472A4: 9014239c                 or      %l0, %lo(dword_F010F39C), %o0
F00472A8: d0022004                 ld      [%o0+4], %o0
F00472AC: 80a24008                 cmp     %o1, %o0
F00472B0: 06800004                 bl      loc_F00472C0
F00472B4: 90166128                 or      %i1, %lo(_fifo_alloc), %o0
F00472B8: 7fff2ecc                 call    _wakeup
F00472BC: 01000000                 nop
F00472C0: d0066128                 ld      [%i1+0x128], %o0
F00472C4: d204239c                 ld      [%l0+0x39C], %o1
F00472C8: 90220009                 sub     %o0, %o1, %o0
F00472CC: d0266128                 st      %o0, [%i1+0x128]
F00472D0: 81c7e008                 ret
F00472D4: 91e80011                 restore %g0, %l1, %o0
