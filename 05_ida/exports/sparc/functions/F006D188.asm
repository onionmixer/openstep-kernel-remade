F006D188: 9de3bf98                 save    %sp, -0x68, %sp
F006D18C: f0060000                 ld      [%i0], %i0
F006D190: 80a62000                 cmp     %i0, 0
F006D194: 0280003e                 be      loc_F006D28C
F006D198: 11020000                 sethi   0x8000000, %o0
F006D19C: d2062038                 ld      [%i0+0x38], %o1
F006D1A0: 808a4008                 btst    %o0, %o1
F006D1A4: 0280003a                 be      loc_F006D28C
F006D1A8: 113c04f0                 sethi   %hi(_vm_info_lock_data), %o0
F006D1AC: a0122210                 or      %o0, %lo(_vm_info_lock_data), %l0
F006D1B0: d0040000                 ld      [%l0], %o0
F006D1B4: 80a22000                 cmp     %o0, 0
F006D1B8: 12bffffe                 bne     loc_F006D1B0
F006D1BC: 01000000                 nop
F006D1C0: 4000a73a                 call    _simple_lock_try
F006D1C4: 90100010                 mov     %l0, %o0
F006D1C8: 80a22000                 cmp     %o0, 0
F006D1CC: 02bffff9                 be      loc_F006D1B0
F006D1D0: 01000000                 nop
F006D1D4: d0062038                 ld      [%i0+0x38], %o0
F006D1D8: 80a22000                 cmp     %o0, 0
F006D1DC: 36800005                 bge,a   loc_F006D1F0
F006D1E0: d0162006                 lduh    [%i0+6], %o0
F006D1E4: 7ffffc26                 call    _vm_info_dequeue
F006D1E8: 90100018                 mov     %i0, %o0
F006D1EC: d0162006                 lduh    [%i0+6], %o0
F006D1F0: 808e6001                 btst    1, %i1
F006D1F4: 90022001                 inc     %o0
F006D1F8: d0362006                 sth     %o0, [%i0+6]
F006D1FC: 113c04f0                 sethi   %hi(_vm_info_lock_data), %o0
F006D200: c0222210                 clr     [%o0+%lo(_vm_info_lock_data)]
F006D204: 12800004                 bne     loc_F006D214
F006D208: a0122210                 or      %o0, %lo(_vm_info_lock_data), %l0
F006D20C: 400001b7                 call    _vmp_push_all
F006D210: 90100018                 mov     %i0, %o0
F006D214: 808e6002                 btst    2, %i1
F006D218: 12800007                 bne     loc_F006D234
F006D21C: 90100018                 mov     %i0, %o0
F006D220: d4062038                 ld      [%i0+0x38], %o2
F006D224: 13040000                 sethi   0x10000000, %o1
F006D228: 922a8009                 andn    %o2, %o1, %o1
F006D22C: 4000008d                 call    _vmp_invalidate
F006D230: d2262038                 st      %o1, [%i0+0x38]
F006D234: d0040000                 ld      [%l0], %o0
F006D238: 80a22000                 cmp     %o0, 0
F006D23C: 12bffffe                 bne     loc_F006D234
F006D240: 01000000                 nop
F006D244: 4000a719                 call    _simple_lock_try
F006D248: 90100010                 mov     %l0, %o0
F006D24C: 80a22000                 cmp     %o0, 0
F006D250: 02bffff9                 be      loc_F006D234
F006D254: 01000000                 nop
F006D258: d0162006                 lduh    [%i0+6], %o0
F006D25C: 90023fff                 inc     -1, %o0
F006D260: d0362006                 sth     %o0, [%i0+6]
F006D264: 912a2010                 sll     %o0, 16, %o0
F006D268: 80a22000                 cmp     %o0, 0
F006D26C: 12800005                 bne     loc_F006D280
F006D270: 113c04f0                 sethi   -0xFEC4000, %o0
F006D274: 7ffffbe5                 call    _vm_info_enqueue
F006D278: 90100018                 mov     %i0, %o0
F006D27C: 113c04f0                 sethi   -0xFEC4000, %o0
F006D280: c0222210                 clr     [%o0+0x210]
F006D284: 10800003                 ba      locret_F006D290
F006D288: f0062034                 ld      [%i0+0x34], %i0
F006D28C: b0102000                 mov     0, %i0
F006D290: 81c7e008                 ret
F006D294: 81e80000                 restore
