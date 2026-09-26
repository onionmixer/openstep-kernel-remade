F0067348: 9de3bf98                 save    %sp, -0x68, %sp
F006734C: 80a62000                 cmp     %i0, 0
F0067350: 12800004                 bne     loc_F0067360
F0067354: 80a66002                 cmp     %i1, 2
F0067358: 1080003f                 ba      locret_F0067454
F006735C: b0102004                 mov     4, %i0
F0067360: 0280000f                 be      loc_F006739C
F0067364: 80a66002                 cmp     %i1, 2
F0067368: 14800007                 bg      loc_F0067384
F006736C: 80a66003                 cmp     %i1, 3
F0067370: 80a66001                 cmp     %i1, 1
F0067374: 02800022                 be      loc_F00673FC
F0067378: a006206c                 add     %i0, 0x6C, %l0 ! 'l'
F006737C: 10800036                 ba      locret_F0067454
F0067380: b0102004                 mov     4, %i0
F0067384: 0280001d                 be      loc_F00673F8
F0067388: 80a66004                 cmp     %i1, 4
F006738C: 0280001c                 be      loc_F00673FC
F0067390: a0062074                 add     %i0, 0x74, %l0 ! 't'
F0067394: 10800030                 ba      locret_F0067454
F0067398: b0102004                 mov     4, %i0
F006739C: f0062088                 ld      [%i0+0x88], %i0
F00673A0: b2062008                 add     %i0, 8, %i1
F00673A4: d0064000                 ld      [%i1], %o0
F00673A8: 80a22000                 cmp     %o0, 0
F00673AC: 12bffffe                 bne     loc_F00673A4
F00673B0: 01000000                 nop
F00673B4: 4000bebd                 call    _simple_lock_try
F00673B8: 90100019                 mov     %i1, %o0
F00673BC: 80a22000                 cmp     %o0, 0
F00673C0: 02bffff9                 be      loc_F00673A4
F00673C4: 01000000                 nop
F00673C8: d006200c                 ld      [%i0+0xC], %o0
F00673CC: 80a22000                 cmp     %o0, 0
F00673D0: 12800005                 bne     loc_F00673E4
F00673D4: 01000000                 nop
F00673D8: c0262008                 clr     [%i0+8]
F00673DC: 1080001e                 ba      locret_F0067454
F00673E0: b0102005                 mov     5, %i0
F00673E4: 7fffcf16                 call    _ipc_port_copy_send
F00673E8: d0062044                 ld      [%i0+0x44], %o0
F00673EC: c0262008                 clr     [%i0+8]
F00673F0: 10800015                 ba      loc_F0067444
F00673F4: d0268000                 st      %o0, [%i2]
F00673F8: a0062070                 add     %i0, 0x70, %l0 ! 'p'
F00673FC: b2062064                 add     %i0, 0x64, %i1 ! 'd'
F0067400: d0064000                 ld      [%i1], %o0
F0067404: 80a22000                 cmp     %o0, 0
F0067408: 12bffffe                 bne     loc_F0067400
F006740C: 01000000                 nop
F0067410: 4000bea6                 call    _simple_lock_try
F0067414: 90100019                 mov     %i1, %o0
F0067418: 80a22000                 cmp     %o0, 0
F006741C: 02bffff9                 be      loc_F0067400
F0067420: 01000000                 nop
F0067424: d0062068                 ld      [%i0+0x68], %o0
F0067428: 80a22000                 cmp     %o0, 0
F006742C: 02800008                 be      loc_F006744C
F0067430: 01000000                 nop
F0067434: 7fffcf02                 call    _ipc_port_copy_send
F0067438: d0040000                 ld      [%l0], %o0
F006743C: c0262064                 clr     [%i0+0x64]
F0067440: d0268000                 st      %o0, [%i2]
F0067444: 10800004                 ba      locret_F0067454
F0067448: b0102000                 mov     0, %i0
F006744C: c0262064                 clr     [%i0+0x64]
F0067450: b0102005                 mov     5, %i0
F0067454: 81c7e008                 ret
F0067458: 81e80000                 restore
