F005B564: 9de3bf98                 save    %sp, -0x68, %sp
F005B568: 80a62000                 cmp     %i0, 0
F005B56C: 02800004                 be      loc_F005B57C
F005B570: 80a63fff                 cmp     %i0, -1
F005B574: 12800004                 bne     loc_F005B584
F005B578: 01000000                 nop
F005B57C: 10800021                 ba      locret_F005B600
F005B580: b0102000                 mov     0, %i0
F005B584: d0060000                 ld      [%i0], %o0
F005B588: 80a22000                 cmp     %o0, 0
F005B58C: 12bffffe                 bne     loc_F005B584
F005B590: 01000000                 nop
F005B594: 4000ee45                 call    _simple_lock_try
F005B598: 90100018                 mov     %i0, %o0
F005B59C: 80a22000                 cmp     %o0, 0
F005B5A0: 02bffff9                 be      loc_F005B584
F005B5A4: 01000000                 nop
F005B5A8: d006200c                 ld      [%i0+0xC], %o0
F005B5AC: 80a20019                 cmp     %o0, %i1
F005B5B0: 12800003                 bne     loc_F005B5BC
F005B5B4: a0102000                 mov     0, %l0
F005B5B8: e0062010                 ld      [%i0+0x10], %l0
F005B5BC: d0062004                 ld      [%i0+4], %o0
F005B5C0: 90023fff                 inc     -1, %o0
F005B5C4: d0262004                 st      %o0, [%i0+4]
F005B5C8: c0260000                 clr     [%i0]
F005B5CC: 80a22000                 cmp     %o0, 0
F005B5D0: 3280000c                 bne,a   locret_F005B600
F005B5D4: b0100010                 mov     %l0, %i0
F005B5D8: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005B5DC: d0062008                 ld      [%i0+8], %o0
F005B5E0: 92126300                 bset    %lo(_ipc_object_zones), %o1
F005B5E4: 912a2001                 sll     %o0, 1, %o0
F005B5E8: 91322011                 srl     %o0, 17, %o0
F005B5EC: 912a2002                 sll     %o0, 2, %o0
F005B5F0: d0020009                 ld      [%o0+%o1], %o0
F005B5F4: 400076f7                 call    _zfree
F005B5F8: 92100018                 mov     %i0, %o1
F005B5FC: b0100010                 mov     %l0, %i0
F005B600: 81c7e008                 ret
F005B604: 81e80000                 restore
