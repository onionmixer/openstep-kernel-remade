F0074754: 9de3bf98                 save    %sp, -0x68, %sp
F0074758: 80a62000                 cmp     %i0, 0
F007475C: 02800034                 be      locret_F007482C
F0074760: 01000000                 nop
F0074764: 40008909                 call    _splusclock
F0074768: a0062020                 add     %i0, 0x20, %l0 ! ' '
F007476C: a2100008                 mov     %o0, %l1
F0074770: d0040000                 ld      [%l0], %o0
F0074774: 80a22000                 cmp     %o0, 0
F0074778: 12bffffe                 bne     loc_F0074770
F007477C: 01000000                 nop
F0074780: 400089ca                 call    _simple_lock_try
F0074784: 90100010                 mov     %l0, %o0
F0074788: 80a22000                 cmp     %o0, 0
F007478C: 02bffff9                 be      loc_F0074770
F0074790: 01000000                 nop
F0074794: d0062024                 ld      [%i0+0x24], %o0
F0074798: 90023fff                 inc     -1, %o0
F007479C: 80a22000                 cmp     %o0, 0
F00747A0: 04800006                 ble     loc_F00747B8
F00747A4: d0262024                 st      %o0, [%i0+0x24]
F00747A8: c0262020                 clr     [%i0+0x20]
F00747AC: 4000895e                 call    _splx
F00747B0: 90100011                 mov     %l1, %o0
F00747B4: 3080001e                 ba,a    locret_F007482C
F00747B8: 90102001                 mov     1, %o0
F00747BC: d0262024                 st      %o0, [%i0+0x24]
F00747C0: 113c04f2a0122168         set     _reaper_lock, %l0
F00747C8: d0040000                 ld      [%l0], %o0
F00747CC: 80a22000                 cmp     %o0, 0
F00747D0: 12bffffe                 bne     loc_F00747C8
F00747D4: 01000000                 nop
F00747D8: 400089b4                 call    _simple_lock_try
F00747DC: 90100010                 mov     %l0, %o0
F00747E0: 80a22000                 cmp     %o0, 0
F00747E4: 02bffff9                 be      loc_F00747C8
F00747E8: 01000000                 nop
F00747EC: 213c04d4a0142150         set     _reaper_queue, %l0
F00747F4: e0260000                 st      %l0, [%i0]
F00747F8: d2042004                 ld      [%l0+4], %o1
F00747FC: d2262004                 st      %o1, [%i0+4]
F0074800: f0224000                 st      %i0, [%o1]
F0074804: f0242004                 st      %i0, [%l0+4]
F0074808: 133c04f2                 sethi   %hi(_reaper_lock), %o1
F007480C: c0226168                 clr     [%o1+%lo(_reaper_lock)]
F0074810: c0262020                 clr     [%i0+0x20]
F0074814: 40008944                 call    _splx
F0074818: 90100011                 mov     %l1, %o0
F007481C: 90100010                 mov     %l0, %o0
F0074820: 92102000                 mov     0, %o1
F0074824: 7ffff1f6                 call    _thread_wakeup_prim
F0074828: 94102000                 mov     0, %o2
F007482C: 81c7e008                 ret
F0074830: 81e80000                 restore
