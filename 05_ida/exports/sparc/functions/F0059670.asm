F0059670: 9de3bf98                 save    %sp, -0x68, %sp
F0059674: d0060000                 ld      [%i0], %o0
F0059678: 80a22000                 cmp     %o0, 0
F005967C: 12bffffe                 bne     loc_F0059674
F0059680: 01000000                 nop
F0059684: 4000f609                 call    _simple_lock_try
F0059688: 90100018                 mov     %i0, %o0
F005968C: 80a22000                 cmp     %o0, 0
F0059690: 02bffff9                 be      loc_F0059674
F0059694: 01000000                 nop
F0059698: d0062004                 ld      [%i0+4], %o0
F005969C: 90023fff                 inc     -1, %o0
F00596A0: d0262004                 st      %o0, [%i0+4]
F00596A4: c0260000                 clr     [%i0]
F00596A8: 80a22000                 cmp     %o0, 0
F00596AC: 1280000a                 bne     locret_F00596D4
F00596B0: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F00596B4: d0062008                 ld      [%i0+8], %o0
F00596B8: 92126300                 bset    %lo(_ipc_object_zones), %o1
F00596BC: 912a2001                 sll     %o0, 1, %o0
F00596C0: 91322011                 srl     %o0, 17, %o0
F00596C4: 912a2002                 sll     %o0, 2, %o0
F00596C8: d0020009                 ld      [%o0+%o1], %o0
F00596CC: 40007ec1                 call    _zfree
F00596D0: 92100018                 mov     %i0, %o1
F00596D4: 81c7e008                 ret
F00596D8: 81e80000                 restore
