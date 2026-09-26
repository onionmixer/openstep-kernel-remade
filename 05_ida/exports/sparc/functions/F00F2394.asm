F00F2394: 9de3bf98                 save    %sp, -0x68, %sp
F00F2398: aa102000                 mov     0, %l5
F00F239C: a4102000                 mov     0, %l2
F00F23A0: 293c04bc                 sethi   -0xFED1000, %l4
F00F23A4: 273c04bc                 sethi   -0xFED1000, %l3
F00F23A8: d0052128                 ld      [%l4+0x128], %o0
F00F23AC: 80a48008                 cmp     %l2, %o0
F00F23B0: 1a800019                 bcc     loc_F00F2414
F00F23B4: d204e124                 ld      [%l3+0x124], %o1
F00F23B8: 912ca001                 sll     %l2, 1, %o0
F00F23BC: 90020012                 add     %o0, %l2, %o0
F00F23C0: a32a2003                 sll     %o0, 3, %l1
F00F23C4: 90024011                 add     %o1, %l1, %o0
F00F23C8: e0022010                 ld      [%o0+0x10], %l0
F00F23CC: 4000014d                 call    sub_F00F2900
F00F23D0: d0024011                 ld      [%o1+%l1], %o0
F00F23D4: 92100008                 mov     %o0, %o1
F00F23D8: d0026018                 ld      [%o1+0x18], %o0
F00F23DC: a0040008                 add     %l0, %o0, %l0
F00F23E0: 80a40018                 cmp     %l0, %i0
F00F23E4: 1880000a                 bgu     loc_F00F240C
F00F23E8: 80a56000                 cmp     %l5, 0
F00F23EC: d002601c                 ld      [%o1+0x1C], %o0
F00F23F0: 90040008                 add     %l0, %o0, %o0
F00F23F4: 80a60008                 cmp     %i0, %o0
F00F23F8: 1a800005                 bcc     loc_F00F240C
F00F23FC: 80a56000                 cmp     %l5, 0
F00F2400: f004e124                 ld      [%l3+0x124], %i0
F00F2404: 10800005                 ba      locret_F00F2418
F00F2408: b0044018                 add     %l1, %i0, %i0
F00F240C: 02bfffe7                 be      loc_F00F23A8
F00F2410: a404a001                 inc     %l2
F00F2414: b0102000                 mov     0, %i0
F00F2418: 81c7e008                 ret
F00F241C: 81e80000                 restore
