F005DFC4: 9de3bf98                 save    %sp, -0x68, %sp
F005DFC8: a0062008                 add     %i0, 8, %l0
F005DFCC: d0040000                 ld      [%l0], %o0
F005DFD0: 80a22000                 cmp     %o0, 0
F005DFD4: 12bffffe                 bne     loc_F005DFCC
F005DFD8: 01000000                 nop
F005DFDC: 4000e3b3                 call    _simple_lock_try
F005DFE0: 90100010                 mov     %l0, %o0
F005DFE4: 80a22000                 cmp     %o0, 0
F005DFE8: 02bffff9                 be      loc_F005DFCC
F005DFEC: 01000000                 nop
F005DFF0: d006200c                 ld      [%i0+0xC], %o0
F005DFF4: c0262008                 clr     [%i0+8]
F005DFF8: c026200c                 clr     [%i0+0xC]
F005DFFC: 80a22000                 cmp     %o0, 0
F005E000: 02800067                 be      locret_F005E19C
F005E004: 90062008                 add     %i0, 8, %o0
F005E008: a0100008                 mov     %o0, %l0
F005E00C: d0040000                 ld      [%l0], %o0
F005E010: 80a22000                 cmp     %o0, 0
F005E014: 12bffffe                 bne     loc_F005E00C
F005E018: 01000000                 nop
F005E01C: 4000e3a3                 call    _simple_lock_try
F005E020: 90100010                 mov     %l0, %o0
F005E024: 80a22000                 cmp     %o0, 0
F005E028: 02bffff9                 be      loc_F005E00C
F005E02C: 01000000                 nop
F005E030: d0062010                 ld      [%i0+0x10], %o0
F005E034: 80a22000                 cmp     %o0, 0
F005E038: 02800015                 be      loc_F005E08C
F005E03C: 90100018                 mov     %i0, %o0
F005E040: a0062008                 add     %i0, 8, %l0
F005E044: 40004b24                 call    _assert_wait
F005E048: 92102000                 mov     0, %o1
F005E04C: c0262008                 clr     [%i0+8]
F005E050: 40004dbc                 call    _thread_block_with_continuation
F005E054: 90102000                 mov     0, %o0
F005E058: d0040000                 ld      [%l0], %o0
F005E05C: 80a22000                 cmp     %o0, 0
F005E060: 12bffffe                 bne     loc_F005E058
F005E064: 01000000                 nop
F005E068: 4000e390                 call    _simple_lock_try
F005E06C: 90100010                 mov     %l0, %o0
F005E070: 80a22000                 cmp     %o0, 0
F005E074: 02bffff9                 be      loc_F005E058
F005E078: 01000000                 nop
F005E07C: d0062010                 ld      [%i0+0x10], %o0
F005E080: 80a22000                 cmp     %o0, 0
F005E084: 12bffff0                 bne     loc_F005E044
F005E088: 90100018                 mov     %i0, %o0
F005E08C: c0262008                 clr     [%i0+8]
F005E090: e4062018                 ld      [%i0+0x18], %l2
F005E094: a2102000                 mov     0, %l1
F005E098: 80a44012                 cmp     %l1, %l2
F005E09C: 1a800014                 bcc     loc_F005E0EC
F005E0A0: e6062014                 ld      [%i0+0x14], %l3
F005E0A4: 2b0007c0                 sethi   0x1F0000, %l5
F005E0A8: 293fc000                 sethi   -0x1000000, %l4
F005E0AC: a0100013                 mov     %l3, %l0
F005E0B0: d2040000                 ld      [%l0], %o1
F005E0B4: 808a4015                 btst    %l5, %o1
F005E0B8: 2280000a                 be,a    loc_F005E0E0
F005E0BC: a2046001                 inc     %l1
F005E0C0: 90100018                 mov     %i0, %o0
F005E0C4: 952c6008                 sll     %l1, 8, %o2
F005E0C8: 920a4014                 and     %o1, %l4, %o1
F005E0CC: 93326018                 srl     %o1, 24, %o1
F005E0D0: 92128009                 bset    %o2, %o1
F005E0D4: 7ffff7b1                 call    _ipc_right_clean
F005E0D8: 94100010                 mov     %l0, %o2
F005E0DC: a2046001                 inc     %l1
F005E0E0: 80a44012                 cmp     %l1, %l2
F005E0E4: 0abffff3                 bcs     loc_F005E0B0
F005E0E8: a0042010                 inc     0x10, %l0
F005E0EC: d006201c                 ld      [%i0+0x1C], %o0
F005E0F0: d0023ffc                 ld      [%o0-4], %o0
F005E0F4: 92100013                 mov     %l3, %o1
F005E0F8: 40000316                 call    _ipc_table_free
F005E0FC: 912a2004                 sll     %o0, 4, %o0
F005E100: 400001f4                 call    _ipc_splay_traverse_start
F005E104: 90062020                 add     %i0, 0x20, %o0 ! ' '
F005E108: a0920000                 orcc    %o0, %g0, %l0
F005E10C: 02800018                 be      loc_F005E16C
F005E110: 01000000                 nop
F005E114: 270007c0                 sethi   0x1F0000, %l3
F005E118: 25000040                 sethi   0x10000, %l2
F005E11C: d0040000                 ld      [%l0], %o0
F005E120: 900a0013                 and     %o0, %l3, %o0
F005E124: 80a20012                 cmp     %o0, %l2
F005E128: 12800007                 bne     loc_F005E144
F005E12C: e2042010                 ld      [%l0+0x10], %l1
F005E130: 90100018                 mov     %i0, %o0
F005E134: d2042004                 ld      [%l0+4], %o1
F005E138: 94100011                 mov     %l1, %o2
F005E13C: 7fffd98a                 call    _ipc_hash_global_delete
F005E140: 96100010                 mov     %l0, %o3
F005E144: 90100018                 mov     %i0, %o0
F005E148: 92100011                 mov     %l1, %o1
F005E14C: 7ffff793                 call    _ipc_right_clean
F005E150: 94100010                 mov     %l0, %o2
F005E154: 90062020                 add     %i0, 0x20, %o0 ! ' '
F005E158: 400001f9                 call    _ipc_splay_traverse_next
F005E15C: 92102001                 mov     1, %o1
F005E160: a0920000                 orcc    %o0, %g0, %l0
F005E164: 32bfffef                 bne,a   loc_F005E120
F005E168: d0040000                 ld      [%l0], %o0
F005E16C: 40000272                 call    _ipc_splay_traverse_finish
F005E170: 90062020                 add     %i0, 0x20, %o0 ! ' '
F005E174: d0062044                 ld      [%i0+0x44], %o0
F005E178: 80a22000                 cmp     %o0, 0
F005E17C: 02800006                 be      loc_F005E194
F005E180: 80a23fff                 cmp     %o0, -1
F005E184: 02800004                 be      loc_F005E194
F005E188: 01000000                 nop
F005E18C: 7ffff3e4                 call    _ipc_port_release_send
F005E190: 01000000                 nop
F005E194: 7fffff2d                 call    _ipc_space_release
F005E198: 90100018                 mov     %i0, %o0
F005E19C: 81c7e008                 ret
F005E1A0: 81e80000                 restore
