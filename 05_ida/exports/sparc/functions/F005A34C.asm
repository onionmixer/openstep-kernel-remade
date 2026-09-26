F005A34C: 9de3bf88                 save    %sp, -0x78, %sp
F005A350: 90100018                 mov     %i0, %o0
F005A354: 9210001b                 mov     %i3, %o1
F005A358: 7fffe614                 call    _ipc_entry_alloc_name
F005A35C: 9407bff4                 add     %fp, var_C, %o2
F005A360: 80a22000                 cmp     %o0, 0
F005A364: 32800055                 bne,a   locret_F005A4B8
F005A368: b0100008                 mov     %o0, %i0
F005A36C: 90100018                 mov     %i0, %o0
F005A370: d407bff4                 ld      [%fp+var_C], %o2
F005A374: 40000690                 call    _ipc_right_inuse
F005A378: 9210001b                 mov     %i3, %o1
F005A37C: 80a22000                 cmp     %o0, 0
F005A380: 02800004                 be      loc_F005A390
F005A384: 80a6a012                 cmp     %i2, 0x12
F005A388: 1080004c                 ba      locret_F005A4B8
F005A38C: b010200d                 mov     0xD, %i0
F005A390: 02800011                 be      loc_F005A3D4
F005A394: 90100018                 mov     %i0, %o0
F005A398: 92100019                 mov     %i1, %o1
F005A39C: 9407bff0                 add     %fp, var_10, %o2
F005A3A0: 400005d5                 call    _ipc_right_reverse
F005A3A4: 9607bfec                 add     %fp, var_14, %o3
F005A3A8: 80a22000                 cmp     %o0, 0
F005A3AC: 0280000a                 be      loc_F005A3D4
F005A3B0: 01000000                 nop
F005A3B4: c0264000                 clr     [%i1]
F005A3B8: 90100018                 mov     %i0, %o0
F005A3BC: d407bff4                 ld      [%fp+var_C], %o2
F005A3C0: 7fffe6ae                 call    _ipc_entry_dealloc
F005A3C4: 9210001b                 mov     %i3, %o1
F005A3C8: c0262008                 clr     [%i0+8]
F005A3CC: 1080003b                 ba      locret_F005A4B8
F005A3D0: b0102015                 mov     0x15, %i0
F005A3D4: d0064000                 ld      [%i1], %o0
F005A3D8: 80a22000                 cmp     %o0, 0
F005A3DC: 12bffffe                 bne     loc_F005A3D4
F005A3E0: 01000000                 nop
F005A3E4: 4000f2b1                 call    _simple_lock_try
F005A3E8: 90100019                 mov     %i1, %o0
F005A3EC: 80a22000                 cmp     %o0, 0
F005A3F0: 02bffff9                 be      loc_F005A3D4
F005A3F4: 01000000                 nop
F005A3F8: d0066008                 ld      [%i1+8], %o0
F005A3FC: 80a22000                 cmp     %o0, 0
F005A400: 0680000a                 bl      loc_F005A428
F005A404: 90100019                 mov     %i1, %o0
F005A408: c0264000                 clr     [%i1]
F005A40C: 90100018                 mov     %i0, %o0
F005A410: d407bff4                 ld      [%fp+var_C], %o2
F005A414: 7fffe699                 call    _ipc_entry_dealloc
F005A418: 9210001b                 mov     %i3, %o1
F005A41C: c0262008                 clr     [%i0+8]
F005A420: 10800026                 ba      locret_F005A4B8
F005A424: b0102014                 mov     0x14, %i0
F005A428: 9210001b                 mov     %i3, %o1
F005A42C: 94162001                 or      %i0, 1, %o2
F005A430: 40000037                 call    _ipc_port_dnrequest
F005A434: 9607bfe8                 add     %fp, var_18, %o3
F005A438: 80a22000                 cmp     %o0, 0
F005A43C: 12800015                 bne     loc_F005A490
F005A440: 90100018                 mov     %i0, %o0
F005A444: 40000e71                 call    _ipc_space_reference
F005A448: 90100018                 mov     %i0, %o0
F005A44C: 90100018                 mov     %i0, %o0
F005A450: 9210001b                 mov     %i3, %o1
F005A454: d407bff4                 ld      [%fp+var_C], %o2
F005A458: 9610001a                 mov     %i2, %o3
F005A45C: d807bfe8                 ld      [%fp+var_18], %o4
F005A460: 1b001000                 sethi   0x400000, %o5
F005A464: d822a008                 st      %o4, [%o2+8]
F005A468: d8028000                 ld      [%o2], %o4
F005A46C: f222a004                 st      %i1, [%o2+4]
F005A470: 9813000d                 bset    %o5, %o4
F005A474: d8228000                 st      %o4, [%o2]
F005A478: 98102001                 mov     1, %o4
F005A47C: 40000c21                 call    _ipc_right_copyout
F005A480: 9a100019                 mov     %i1, %o5
F005A484: c0262008                 clr     [%i0+8]
F005A488: 1080000c                 ba      locret_F005A4B8
F005A48C: b0100008                 mov     %o0, %i0
F005A490: d407bff4                 ld      [%fp+var_C], %o2
F005A494: 7fffe679                 call    _ipc_entry_dealloc
F005A498: 9210001b                 mov     %i3, %o1
F005A49C: c0262008                 clr     [%i0+8]
F005A4A0: 4000002f                 call    _ipc_port_dngrow
F005A4A4: 90100019                 mov     %i1, %o0
F005A4A8: 80a22000                 cmp     %o0, 0
F005A4AC: 22bfffaa                 be,a    loc_F005A354
F005A4B0: 90100018                 mov     %i0, %o0
F005A4B4: b0100008                 mov     %o0, %i0
F005A4B8: 81c7e008                 ret
F005A4BC: 81e80000                 restore
