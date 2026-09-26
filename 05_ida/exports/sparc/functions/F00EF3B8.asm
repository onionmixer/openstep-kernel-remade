F00EF3B8: 9de3bf98                 save    %sp, -0x68, %sp
F00EF3BC: d0062018                 ld      [%i0+0x18], %o0
F00EF3C0: 80a22000                 cmp     %o0, 0
F00EF3C4: 22800015                 be,a    loc_F00EF418
F00EF3C8: f0062004                 ld      [%i0+4], %i0
F00EF3CC: a4022004                 add     %o0, 4, %l2
F00EF3D0: 1080000d                 ba      loc_F00EF404
F00EF3D4: a0102000                 mov     0, %l0
F00EF3D8: 90020010                 add     %o0, %l0, %o0
F00EF3DC: a32a2002                 sll     %o0, 2, %l1
F00EF3E0: 90100019                 mov     %i1, %o0! __s1
F00EF3E4: 7ffc6372                 call    _strcmp
F00EF3E8: d2048011                 ld      [%l2+%l1], %o1
F00EF3EC: 80a22000                 cmp     %o0, 0
F00EF3F0: 12800004                 bne     loc_F00EF400
F00EF3F4: a0042001                 inc     %l0
F00EF3F8: 1080000c                 ba      locret_F00EF428
F00EF3FC: b0048011                 add     %l2, %l1, %i0
F00EF400: d0062018                 ld      [%i0+0x18], %o0
F00EF404: d0020000                 ld      [%o0], %o0
F00EF408: 80a40008                 cmp     %l0, %o0
F00EF40C: 06bffff3                 bl      loc_F00EF3D8
F00EF410: 912c2001                 sll     %l0, 1, %o0
F00EF414: f0062004                 ld      [%i0+4], %i0
F00EF418: 80a62000                 cmp     %i0, 0
F00EF41C: 32bfffe9                 bne,a   loc_F00EF3C0
F00EF420: d0062018                 ld      [%i0+0x18], %o0
F00EF424: b0102000                 mov     0, %i0
F00EF428: 81c7e008                 ret
F00EF42C: 81e80000                 restore
