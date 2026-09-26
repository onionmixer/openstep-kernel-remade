F005B11C: 9de3bf98                 save    %sp, -0x68, %sp
F005B120: a0102000                 mov     0, %l0
F005B124: a2102000                 mov     0, %l1
F005B128: d0060000                 ld      [%i0], %o0
F005B12C: 80a22000                 cmp     %o0, 0
F005B130: 12bffffe                 bne     loc_F005B128
F005B134: 01000000                 nop
F005B138: 4000ef5c                 call    _simple_lock_try
F005B13C: 90100018                 mov     %i0, %o0
F005B140: 80a22000                 cmp     %o0, 0
F005B144: 02bffff9                 be      loc_F005B128
F005B148: 01000000                 nop
F005B14C: d0062004                 ld      [%i0+4], %o0
F005B150: 92023fff                 add     %o0, -1, %o1
F005B154: d2262004                 st      %o1, [%i0+4]
F005B158: d0062008                 ld      [%i0+8], %o0
F005B15C: 80a22000                 cmp     %o0, 0
F005B160: 2680000f                 bl,a    loc_F005B19C
F005B164: d006201c                 ld      [%i0+0x1C], %o0
F005B168: c0260000                 clr     [%i0]
F005B16C: 80a26000                 cmp     %o1, 0
F005B170: 1280001b                 bne     locret_F005B1DC
F005B174: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005B178: d0062008                 ld      [%i0+8], %o0
F005B17C: 92126300                 bset    %lo(_ipc_object_zones), %o1
F005B180: 912a2001                 sll     %o0, 1, %o0
F005B184: 91322011                 srl     %o0, 17, %o0
F005B188: 912a2002                 sll     %o0, 2, %o0
F005B18C: d0020009                 ld      [%o0+%o1], %o0
F005B190: 40007810                 call    _zfree
F005B194: 92100018                 mov     %i0, %o1
F005B198: 30800011                 ba,a    locret_F005B1DC
F005B19C: 90023fff                 inc     -1, %o0
F005B1A0: 80a22000                 cmp     %o0, 0
F005B1A4: 12800008                 bne     loc_F005B1C4
F005B1A8: d026201c                 st      %o0, [%i0+0x1C]
F005B1AC: e0062024                 ld      [%i0+0x24], %l0
F005B1B0: 80a42000                 cmp     %l0, 0
F005B1B4: 02800004                 be      loc_F005B1C4
F005B1B8: 01000000                 nop
F005B1BC: c0262024                 clr     [%i0+0x24]
F005B1C0: e2062018                 ld      [%i0+0x18], %l1
F005B1C4: c0260000                 clr     [%i0]
F005B1C8: 80a42000                 cmp     %l0, 0
F005B1CC: 02800004                 be      locret_F005B1DC
F005B1D0: 90100010                 mov     %l0, %o0
F005B1D4: 7ffff80c                 call    _ipc_notify_no_senders
F005B1D8: 92100011                 mov     %l1, %o1
F005B1DC: 81c7e008                 ret
F005B1E0: 81e80000                 restore
