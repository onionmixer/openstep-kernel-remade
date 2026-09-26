F005B230: 9de3bf98                 save    %sp, -0x68, %sp
F005B234: d0060000                 ld      [%i0], %o0
F005B238: 80a22000                 cmp     %o0, 0
F005B23C: 12bffffe                 bne     loc_F005B234
F005B240: 01000000                 nop
F005B244: 4000ef19                 call    _simple_lock_try
F005B248: 90100018                 mov     %i0, %o0
F005B24C: 80a22000                 cmp     %o0, 0
F005B250: 02bffff9                 be      loc_F005B234
F005B254: 01000000                 nop
F005B258: d0062004                 ld      [%i0+4], %o0
F005B25C: 92023fff                 add     %o0, -1, %o1
F005B260: d2262004                 st      %o1, [%i0+4]
F005B264: d0062008                 ld      [%i0+8], %o0
F005B268: 80a22000                 cmp     %o0, 0
F005B26C: 2680000f                 bl,a    loc_F005B2A8
F005B270: d0062020                 ld      [%i0+0x20], %o0
F005B274: c0260000                 clr     [%i0]
F005B278: 80a26000                 cmp     %o1, 0
F005B27C: 1280000e                 bne     locret_F005B2B4
F005B280: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005B284: d0062008                 ld      [%i0+8], %o0
F005B288: 92126300                 bset    %lo(_ipc_object_zones), %o1
F005B28C: 912a2001                 sll     %o0, 1, %o0
F005B290: 91322011                 srl     %o0, 17, %o0
F005B294: 912a2002                 sll     %o0, 2, %o0
F005B298: d0020009                 ld      [%o0+%o1], %o0
F005B29C: 400077cd                 call    _zfree
F005B2A0: 92100018                 mov     %i0, %o1
F005B2A4: 30800004                 ba,a    locret_F005B2B4
F005B2A8: c0260000                 clr     [%i0]
F005B2AC: 90023fff                 inc     -1, %o0
F005B2B0: d0262020                 st      %o0, [%i0+0x20]
F005B2B4: 81c7e008                 ret
F005B2B8: 81e80000                 restore
