F00754B8: 9de3bf98                 save    %sp, -0x68, %sp
F00754BC: 80a62000                 cmp     %i0, 0
F00754C0: 12800004                 bne     loc_F00754D0
F00754C4: 01000000                 nop
F00754C8: 10800032                 ba      locret_F0075590
F00754CC: b0102004                 mov     4, %i0
F00754D0: 400085ae                 call    _splusclock
F00754D4: a4102000                 mov     0, %l2
F00754D8: a2100008                 mov     %o0, %l1
F00754DC: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00754E0: d0040000                 ld      [%l0], %o0
F00754E4: 80a22000                 cmp     %o0, 0
F00754E8: 12bffffe                 bne     loc_F00754E0
F00754EC: 01000000                 nop
F00754F0: 4000866e                 call    _simple_lock_try
F00754F4: 90100010                 mov     %l0, %o0
F00754F8: 80a22000                 cmp     %o0, 0
F00754FC: 02bffff9                 be      loc_F00754E0
F0075500: 01000000                 nop
F0075504: d006208c                 ld      [%i0+0x8C], %o0
F0075508: 90022001                 inc     %o0
F007550C: 80a22001                 cmp     %o0, 1
F0075510: 12800009                 bne     loc_F0075534
F0075514: d026208c                 st      %o0, [%i0+0x8C]
F0075518: d2062040                 ld      [%i0+0x40], %o1
F007551C: a4102001                 mov     1, %l2
F0075520: d006204c                 ld      [%i0+0x4C], %o0
F0075524: 92026001                 inc     %o1
F0075528: d2262040                 st      %o1, [%i0+0x40]
F007552C: 90122002                 bset    2, %o0
F0075530: d026204c                 st      %o0, [%i0+0x4C]
F0075534: c0262020                 clr     [%i0+0x20]
F0075538: 400085fb                 call    _splx
F007553C: 90100011                 mov     %l1, %o0
F0075540: 80a4a000                 cmp     %l2, 0
F0075544: 02800012                 be      loc_F007558C
F0075548: 113c04d0                 sethi   %hi(_active_threads), %o0
F007554C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0075550: 80a60008                 cmp     %i0, %o0
F0075554: 1280000c                 bne     loc_F0075584
F0075558: 90100018                 mov     %i0, %o0
F007555C: 4000858b                 call    _splusclock
F0075560: 01000000                 nop
F0075564: 133c04cf                 sethi   %hi(_need_ast), %o1
F0075568: d4026160                 ld      [%o1+%lo(_need_ast)], %o2
F007556C: 9412a004                 bset    4, %o2
F0075570: d4226160                 st      %o2, [%o1+%lo(_need_ast)]
F0075574: d2026160                 ld      [%o1+%lo(_need_ast)], %o1
F0075578: 400085eb                 call    _splx
F007557C: b0102000                 mov     0, %i0
F0075580: 30800004                 ba,a    locret_F0075590
F0075584: 7fffff4e                 call    _thread_dowait
F0075588: 92102001                 mov     1, %o1
F007558C: b0102000                 mov     0, %i0
F0075590: 81c7e008                 ret
F0075594: 81e80000                 restore
