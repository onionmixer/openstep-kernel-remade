F005C1B8: 9de3bf98                 save    %sp, -0x68, %sp
F005C1BC: e4068000                 ld      [%i2], %l2
F005C1C0: 110007c0                 sethi   0x1F0000, %o0
F005C1C4: a20c8008                 and     %l2, %o0, %l1
F005C1C8: 110000c0                 sethi   0x30000, %o0
F005C1CC: 80a44008                 cmp     %l1, %o0
F005C1D0: 02800032                 be      loc_F005C298
F005C1D4: a6102000                 mov     0, %l3
F005C1D8: 18800007                 bgu     loc_F005C1F4
F005C1DC: 11000040                 sethi   0x10000, %o0
F005C1E0: 80a44008                 cmp     %l1, %o0
F005C1E4: 0280002d                 be      loc_F005C298
F005C1E8: 11000080                 sethi   0x20000, %o0
F005C1EC: 10800009                 ba      loc_F005C210
F005C1F0: 80a44008                 cmp     %l1, %o0
F005C1F4: 11000200                 sethi   0x80000, %o0
F005C1F8: 80a44008                 cmp     %l1, %o0
F005C1FC: 22800014                 be,a    loc_F005C24C
F005C200: 90100018                 mov     %i0, %o0
F005C204: 18800007                 bgu     loc_F005C220
F005C208: 11000100                 sethi   0x40000, %o0
F005C20C: 80a44008                 cmp     %l1, %o0
F005C210: 02800022                 be      loc_F005C298
F005C214: a6102000                 mov     0, %l3
F005C218: 10800099                 ba      loc_F005C47C
F005C21C: 113c043d                 sethi   -0xFEF0C00, %o0
F005C220: 11000400                 sethi   0x100000, %o0
F005C224: 80a44008                 cmp     %l1, %o0
F005C228: 12800095                 bne     loc_F005C47C
F005C22C: 113c043d                 sethi   -0xFEF0C00, %o0
F005C230: 90100018                 mov     %i0, %o0
F005C234: 92100019                 mov     %i1, %o1
F005C238: 7fffdf10                 call    _ipc_entry_dealloc
F005C23C: 9410001a                 mov     %i2, %o2
F005C240: c0262008                 clr     [%i0+8]
F005C244: 10800091                 ba      locret_F005C488
F005C248: b0102000                 mov     0, %i0
F005C24C: 92100019                 mov     %i1, %o1
F005C250: e006a004                 ld      [%i2+4], %l0
F005C254: 9410001a                 mov     %i2, %o2
F005C258: 7fffdf08                 call    _ipc_entry_dealloc
F005C25C: c022a004                 clr     [%o2+4]
F005C260: d0040000                 ld      [%l0], %o0
F005C264: 80a22000                 cmp     %o0, 0
F005C268: 12bffffe                 bne     loc_F005C260
F005C26C: 01000000                 nop
F005C270: 4000eb0e                 call    _simple_lock_try
F005C274: 90100010                 mov     %l0, %o0
F005C278: 80a22000                 cmp     %o0, 0
F005C27C: 02bffff9                 be      loc_F005C260
F005C280: 01000000                 nop
F005C284: c0262008                 clr     [%i0+8]
F005C288: 7ffffdd9                 call    _ipc_pset_destroy
F005C28C: 90100010                 mov     %l0, %o0
F005C290: 1080007e                 ba      locret_F005C488
F005C294: b0102000                 mov     0, %i0
F005C298: a8102000                 mov     0, %l4
F005C29C: 11000800                 sethi   0x200000, %o0
F005C2A0: 808c8008                 btst    %o0, %l2
F005C2A4: 02800005                 be      loc_F005C2B8
F005C2A8: e006a004                 ld      [%i2+4], %l0
F005C2AC: 90100018                 mov     %i0, %o0
F005C2B0: 7fffef30                 call    _ipc_marequest_cancel
F005C2B4: 92100019                 mov     %i1, %o1
F005C2B8: 11000040                 sethi   0x10000, %o0
F005C2BC: 80a44008                 cmp     %l1, %o0
F005C2C0: 12800006                 bne     loc_F005C2D8
F005C2C4: 90100018                 mov     %i0, %o0
F005C2C8: 92100010                 mov     %l0, %o1
F005C2CC: 94100019                 mov     %i1, %o2
F005C2D0: 7fffe0b8                 call    _ipc_hash_delete
F005C2D4: 9610001a                 mov     %i2, %o3
F005C2D8: d0040000                 ld      [%l0], %o0
F005C2DC: 80a22000                 cmp     %o0, 0
F005C2E0: 12bffffe                 bne     loc_F005C2D8
F005C2E4: 01000000                 nop
F005C2E8: 4000eaf0                 call    _simple_lock_try
F005C2EC: 90100010                 mov     %l0, %o0
F005C2F0: 80a22000                 cmp     %o0, 0
F005C2F4: 02bffff9                 be      loc_F005C2D8
F005C2F8: 01000000                 nop
F005C2FC: d0042008                 ld      [%l0+8], %o0
F005C300: 80a22000                 cmp     %o0, 0
F005C304: 2680001d                 bl,a    loc_F005C378
F005C308: d006a008                 ld      [%i2+8], %o0
F005C30C: d0042004                 ld      [%l0+4], %o0
F005C310: 90023fff                 inc     -1, %o0
F005C314: d0242004                 st      %o0, [%l0+4]
F005C318: c0240000                 clr     [%l0]
F005C31C: 80a22000                 cmp     %o0, 0
F005C320: 1280000a                 bne     loc_F005C348
F005C324: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005C328: d0042008                 ld      [%l0+8], %o0
F005C32C: 92126300                 bset    %lo(_ipc_object_zones), %o1
F005C330: 912a2001                 sll     %o0, 1, %o0
F005C334: 91322011                 srl     %o0, 17, %o0
F005C338: 912a2002                 sll     %o0, 2, %o0
F005C33C: d0020009                 ld      [%o0+%o1], %o0
F005C340: 400073a4                 call    _zfree
F005C344: 92100010                 mov     %l0, %o1
F005C348: c026a008                 clr     [%i2+8]
F005C34C: c026a004                 clr     [%i2+4]
F005C350: 90100018                 mov     %i0, %o0
F005C354: 92100019                 mov     %i1, %o1
F005C358: 7fffdec8                 call    _ipc_entry_dealloc
F005C35C: 9410001a                 mov     %i2, %o2
F005C360: c0262008                 clr     [%i0+8]
F005C364: 11001000                 sethi   0x400000, %o0
F005C368: 808c8008                 btst    %o0, %l2
F005C36C: 02800046                 be      loc_F005C484
F005C370: b010200f                 mov     0xF, %i0
F005C374: 30800045                 ba,a    locret_F005C488
F005C378: 80a22000                 cmp     %o0, 0
F005C37C: 02800008                 be      loc_F005C39C
F005C380: 90100018                 mov     %i0, %o0
F005C384: 92100010                 mov     %l0, %o1
F005C388: 94100019                 mov     %i1, %o2
F005C38C: 7ffffe78                 call    _ipc_right_dncancel
F005C390: 9610001a                 mov     %i2, %o3
F005C394: 10800003                 ba      loc_F005C3A0
F005C398: a4100008                 mov     %o0, %l2
F005C39C: a4102000                 mov     0, %l2
F005C3A0: c026a004                 clr     [%i2+4]
F005C3A4: 90100018                 mov     %i0, %o0
F005C3A8: 92100019                 mov     %i1, %o1
F005C3AC: 7fffdeb3                 call    _ipc_entry_dealloc
F005C3B0: 9410001a                 mov     %i2, %o2
F005C3B4: c0262008                 clr     [%i0+8]
F005C3B8: 11000040                 sethi   0x10000, %o0
F005C3BC: 808c4008                 btst    %o0, %l1
F005C3C0: 0280000e                 be      loc_F005C3F8
F005C3C4: 11000080                 sethi   0x20000, %o0
F005C3C8: d004201c                 ld      [%l0+0x1C], %o0
F005C3CC: 90023fff                 inc     -1, %o0
F005C3D0: 80a22000                 cmp     %o0, 0
F005C3D4: 12800008                 bne     loc_F005C3F4
F005C3D8: d024201c                 st      %o0, [%l0+0x1C]
F005C3DC: e6042024                 ld      [%l0+0x24], %l3
F005C3E0: 80a4e000                 cmp     %l3, 0
F005C3E4: 02800005                 be      loc_F005C3F8
F005C3E8: 11000080                 sethi   0x20000, %o0
F005C3EC: c0242024                 clr     [%l0+0x24]
F005C3F0: e8042018                 ld      [%l0+0x18], %l4
F005C3F4: 11000080                 sethi   0x20000, %o0
F005C3F8: 808c4008                 btst    %o0, %l1
F005C3FC: 02800008                 be      loc_F005C41C
F005C400: 11000100                 sethi   0x40000, %o0
F005C404: 7ffff949                 call    _ipc_port_clear_receiver
F005C408: 90100010                 mov     %l0, %o0
F005C40C: 7ffff9e2                 call    _ipc_port_destroy
F005C410: 90100010                 mov     %l0, %o0
F005C414: 1080000e                 ba      loc_F005C44C
F005C418: 80a4e000                 cmp     %l3, 0
F005C41C: 808c4008                 btst    %o0, %l1
F005C420: 22800007                 be,a    loc_F005C43C
F005C424: d0042004                 ld      [%l0+4], %o0
F005C428: c0240000                 clr     [%l0]
F005C42C: 7ffff3a2                 call    _ipc_notify_send_once
F005C430: 90100010                 mov     %l0, %o0
F005C434: 10800006                 ba      loc_F005C44C
F005C438: 80a4e000                 cmp     %l3, 0
F005C43C: 90023fff                 inc     -1, %o0
F005C440: d0242004                 st      %o0, [%l0+4]
F005C444: c0240000                 clr     [%l0]
F005C448: 80a4e000                 cmp     %l3, 0
F005C44C: 02800004                 be      loc_F005C45C
F005C450: 90100013                 mov     %l3, %o0
F005C454: 7ffff36c                 call    _ipc_notify_no_senders
F005C458: 92100014                 mov     %l4, %o1
F005C45C: 80a4a000                 cmp     %l2, 0
F005C460: 0280000a                 be      locret_F005C488
F005C464: b0102000                 mov     0, %i0
F005C468: 90100012                 mov     %l2, %o0! char *
F005C46C: 7ffff2e0                 call    _ipc_notify_port_deleted
F005C470: 92100019                 mov     %i1, %o1
F005C474: 10800005                 ba      locret_F005C488
F005C478: b0102000                 mov     0, %i0
F005C47C: 7ffee33d                 call    _panic
F005C480: 901222b8                 bset    0x2B8, %o0
F005C484: b0102000                 mov     0, %i0
F005C488: 81c7e008                 ret
F005C48C: 81e80000                 restore
