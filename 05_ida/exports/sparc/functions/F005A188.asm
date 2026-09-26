F005A188: 9de3bf88                 save    %sp, -0x78, %sp
F005A18C: a2100018                 mov     %i0, %l1
F005A190: a0046008                 add     %l1, 8, %l0
F005A194: d0040000                 ld      [%l0], %o0
F005A198: 80a22000                 cmp     %o0, 0
F005A19C: 12bffffe                 bne     loc_F005A194
F005A1A0: 01000000                 nop
F005A1A4: 4000f341                 call    _simple_lock_try
F005A1A8: 90100010                 mov     %l0, %o0
F005A1AC: 80a22000                 cmp     %o0, 0
F005A1B0: 02bffff9                 be      loc_F005A194
F005A1B4: 01000000                 nop
F005A1B8: d004600c                 ld      [%l1+0xC], %o0
F005A1BC: 80a22000                 cmp     %o0, 0
F005A1C0: 12800005                 bne     loc_F005A1D4
F005A1C4: 80a6a012                 cmp     %i2, 0x12
F005A1C8: c0246008                 clr     [%l1+8]
F005A1CC: 1080005e                 ba      locret_F005A344
F005A1D0: b0102010                 mov     0x10, %i0
F005A1D4: 02800009                 be      loc_F005A1F8
F005A1D8: 90100011                 mov     %l1, %o0
F005A1DC: 92100019                 mov     %i1, %o1
F005A1E0: 9407bff4                 add     %fp, var_C, %o2
F005A1E4: 40000644                 call    _ipc_right_reverse
F005A1E8: 9607bff0                 add     %fp, var_10, %o3
F005A1EC: 80a22000                 cmp     %o0, 0
F005A1F0: 12800049                 bne     loc_F005A314
F005A1F4: 90100011                 mov     %l1, %o0
F005A1F8: 90100011                 mov     %l1, %o0
F005A1FC: 9207bff4                 add     %fp, var_C, %o1
F005A200: 7fffe630                 call    _ipc_entry_get
F005A204: 9407bff0                 add     %fp, var_10, %o2
F005A208: 80a22000                 cmp     %o0, 0
F005A20C: 02800008                 be      loc_F005A22C
F005A210: 01000000                 nop
F005A214: 7fffe793                 call    _ipc_entry_grow_table
F005A218: 90100011                 mov     %l1, %o0
F005A21C: b0920000                 orcc    %o0, %g0, %i0
F005A220: 22bfffe7                 be,a    loc_F005A1BC
F005A224: d004600c                 ld      [%l1+0xC], %o0
F005A228: 30800047                 ba,a    locret_F005A344
F005A22C: d0064000                 ld      [%i1], %o0
F005A230: 80a22000                 cmp     %o0, 0
F005A234: 12bffffe                 bne     loc_F005A22C
F005A238: 01000000                 nop
F005A23C: 4000f31b                 call    _simple_lock_try
F005A240: 90100019                 mov     %i1, %o0
F005A244: 80a22000                 cmp     %o0, 0
F005A248: 02bffff9                 be      loc_F005A22C
F005A24C: 01000000                 nop
F005A250: d0066008                 ld      [%i1+8], %o0
F005A254: 80a22000                 cmp     %o0, 0
F005A258: 06800009                 bl      loc_F005A27C
F005A25C: d207bff4                 ld      [%fp+var_C], %o1
F005A260: c0264000                 clr     [%i1]
F005A264: d407bff0                 ld      [%fp+var_10], %o2
F005A268: 7fffe704                 call    _ipc_entry_dealloc
F005A26C: 90100011                 mov     %l1, %o0
F005A270: c0246008                 clr     [%l1+8]
F005A274: 10800034                 ba      locret_F005A344
F005A278: b0102014                 mov     0x14, %i0
F005A27C: 90100019                 mov     %i1, %o0
F005A280: 94146001                 or      %l1, 1, %o2
F005A284: 400000a2                 call    _ipc_port_dnrequest
F005A288: 9607bfec                 add     %fp, var_14, %o3
F005A28C: 80a22000                 cmp     %o0, 0
F005A290: 02800016                 be      loc_F005A2E8
F005A294: d207bff4                 ld      [%fp+var_C], %o1
F005A298: d407bff0                 ld      [%fp+var_10], %o2
F005A29C: 7fffe6f7                 call    _ipc_entry_dealloc
F005A2A0: 90100011                 mov     %l1, %o0
F005A2A4: c0246008                 clr     [%l1+8]
F005A2A8: 400000ad                 call    _ipc_port_dngrow
F005A2AC: 90100019                 mov     %i1, %o0
F005A2B0: b0920000                 orcc    %o0, %g0, %i0
F005A2B4: 12800024                 bne     locret_F005A344
F005A2B8: a0046008                 add     %l1, 8, %l0
F005A2BC: d0040000                 ld      [%l0], %o0
F005A2C0: 80a22000                 cmp     %o0, 0
F005A2C4: 12bffffe                 bne     loc_F005A2BC
F005A2C8: 01000000                 nop
F005A2CC: 4000f2f7                 call    _simple_lock_try
F005A2D0: 90100010                 mov     %l0, %o0
F005A2D4: 80a22000                 cmp     %o0, 0
F005A2D8: 02bffff9                 be      loc_F005A2BC
F005A2DC: 01000000                 nop
F005A2E0: 10bfffb7                 ba      loc_F005A1BC
F005A2E4: d004600c                 ld      [%l1+0xC], %o0
F005A2E8: 40000ec8                 call    _ipc_space_reference
F005A2EC: 90100011                 mov     %l1, %o0
F005A2F0: d407bff0                 ld      [%fp+var_10], %o2
F005A2F4: d007bfec                 ld      [%fp+var_14], %o0
F005A2F8: 13001000                 sethi   0x400000, %o1
F005A2FC: d022a008                 st      %o0, [%o2+8]
F005A300: d0028000                 ld      [%o2], %o0
F005A304: f222a004                 st      %i1, [%o2+4]
F005A308: 90120009                 bset    %o1, %o0
F005A30C: d0228000                 st      %o0, [%o2]
F005A310: 90100011                 mov     %l1, %o0
F005A314: 9610001a                 mov     %i2, %o3
F005A318: d207bff4                 ld      [%fp+var_C], %o1
F005A31C: 98102001                 mov     1, %o4
F005A320: d407bff0                 ld      [%fp+var_10], %o2
F005A324: 40000c77                 call    _ipc_right_copyout
F005A328: 9a100019                 mov     %i1, %o5
F005A32C: b0100008                 mov     %o0, %i0
F005A330: c0246008                 clr     [%l1+8]
F005A334: 80a62000                 cmp     %i0, 0
F005A338: 12800003                 bne     locret_F005A344
F005A33C: d007bff4                 ld      [%fp+var_C], %o0
F005A340: d026c000                 st      %o0, [%i3]
F005A344: 81c7e008                 ret
F005A348: 81e80000                 restore
