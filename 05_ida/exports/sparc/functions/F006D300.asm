F006D300: 9de3bf98                 save    %sp, -0x68, %sp
F006D304: d0060000                 ld      [%i0], %o0
F006D308: e0022024                 ld      [%o0+0x24], %l0
F006D30C: 80a42000                 cmp     %l0, 0
F006D310: 02800052                 be      locret_F006D458
F006D314: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F006D318: b0122230                 or      %o0, %lo(_vm_page_queue_lock), %i0
F006D31C: d0060000                 ld      [%i0], %o0
F006D320: 80a22000                 cmp     %o0, 0
F006D324: 12bffffe                 bne     loc_F006D31C
F006D328: 01000000                 nop
F006D32C: 4000a6df                 call    _simple_lock_try
F006D330: 90100018                 mov     %i0, %o0
F006D334: 80a22000                 cmp     %o0, 0
F006D338: 02bffff9                 be      loc_F006D31C
F006D33C: 01000000                 nop
F006D340: b0042010                 add     %l0, 0x10, %i0
F006D344: d0060000                 ld      [%i0], %o0
F006D348: 80a22000                 cmp     %o0, 0
F006D34C: 12bffffe                 bne     loc_F006D344
F006D350: 01000000                 nop
F006D354: 4000a6d5                 call    _simple_lock_try
F006D358: 90100018                 mov     %i0, %o0
F006D35C: 80a22000                 cmp     %o0, 0
F006D360: 02bffff9                 be      loc_F006D344
F006D364: 113c04d0                 sethi   %hi(_page_mask), %o0
F006D368: d40220d8                 ld      [%o0+%lo(_page_mask)], %o2
F006D36C: 90068019                 add     %i2, %i1, %o0
F006D370: 9238000a                 xnor    %g0, %o2, %o1
F006D374: b20e4009                 and     %i1, %o1, %i1
F006D378: 9002000a                 add     %o0, %o2, %o0
F006D37C: b40a0009                 and     %o0, %o1, %i2
F006D380: 80a6401a                 cmp     %i1, %i2
F006D384: 1a800032                 bcc     loc_F006D44C
F006D388: 90100010                 mov     %l0, %o0
F006D38C: 27200000                 sethi   0x80000000, %l3
F006D390: 25100000                 sethi   0x40000000, %l2
F006D394: 233c04f0                 sethi   -0xFEC4000, %l1
F006D398: 40006f00                 call    _vm_page_lookup
F006D39C: 92100019                 mov     %i1, %o1
F006D3A0: 92920000                 orcc    %o0, %g0, %o1
F006D3A4: 02800025                 be      loc_F006D438
F006D3A8: 113c0447                 sethi   -0xFEEE400, %o0
F006D3AC: d0026020                 ld      [%o1+0x20], %o0
F006D3B0: 808a0013                 btst    %l3, %o0
F006D3B4: 0280001e                 be      loc_F006D42C
F006D3B8: 90120012                 bset    %l2, %o0
F006D3BC: d0226020                 st      %o0, [%o1+0x20]
F006D3C0: 90100009                 mov     %o1, %o0
F006D3C4: 40000e44                 call    _assert_wait
F006D3C8: 92102000                 mov     0, %o1
F006D3CC: c0242010                 clr     [%l0+0x10]
F006D3D0: c0246230                 clr     [%l1+0x230]
F006D3D4: 400014bb                 call    _thread_block
F006D3D8: b0146230                 or      %l1, 0x230, %i0
F006D3DC: d0060000                 ld      [%i0], %o0
F006D3E0: 80a22000                 cmp     %o0, 0
F006D3E4: 12bffffe                 bne     loc_F006D3DC
F006D3E8: 01000000                 nop
F006D3EC: 4000a6af                 call    _simple_lock_try
F006D3F0: 90100018                 mov     %i0, %o0
F006D3F4: 80a22000                 cmp     %o0, 0
F006D3F8: 02bffff9                 be      loc_F006D3DC
F006D3FC: 01000000                 nop
F006D400: b0042010                 add     %l0, 0x10, %i0
F006D404: d0060000                 ld      [%i0], %o0
F006D408: 80a22000                 cmp     %o0, 0
F006D40C: 12bffffe                 bne     loc_F006D404
F006D410: 01000000                 nop
F006D414: 4000a6a5                 call    _simple_lock_try
F006D418: 90100018                 mov     %i0, %o0
F006D41C: 80a22000                 cmp     %o0, 0
F006D420: 02bffff9                 be      loc_F006D404
F006D424: 80a6401a                 cmp     %i1, %i2
F006D428: 30800007                 ba,a    loc_F006D444
F006D42C: 40006fd3                 call    _vm_page_free
F006D430: 90100009                 mov     %o1, %o0
F006D434: 113c0447                 sethi   -0xFEEE400, %o0
F006D438: d002213c                 ld      [%o0+0x13C], %o0
F006D43C: b2064008                 add     %i1, %o0, %i1
F006D440: 80a6401a                 cmp     %i1, %i2
F006D444: 0abfffd5                 bcs     loc_F006D398
F006D448: 90100010                 mov     %l0, %o0
F006D44C: c0242010                 clr     [%l0+0x10]
F006D450: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F006D454: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F006D458: 81c7e008                 ret
F006D45C: 81e80000                 restore
