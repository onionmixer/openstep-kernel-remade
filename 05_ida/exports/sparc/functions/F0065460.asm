F0065460: 9de3bf98                 save    %sp, -0x68, %sp
F0065464: 80a62000                 cmp     %i0, 0
F0065468: 0280001d                 be      locret_F00654DC
F006546C: a0102000                 mov     0, %l0
F0065470: 80a63fff                 cmp     %i0, -1
F0065474: 0280001a                 be      locret_F00654DC
F0065478: 01000000                 nop
F006547C: d0060000                 ld      [%i0], %o0
F0065480: 80a22000                 cmp     %o0, 0
F0065484: 12bffffe                 bne     loc_F006547C
F0065488: 01000000                 nop
F006548C: 4000c687                 call    _simple_lock_try
F0065490: 90100018                 mov     %i0, %o0
F0065494: 80a22000                 cmp     %o0, 0
F0065498: 02bffff9                 be      loc_F006547C
F006549C: 01000000                 nop
F00654A0: d2062008                 ld      [%i0+8], %o1
F00654A4: 80a26000                 cmp     %o1, 0
F00654A8: 1680000c                 bge     loc_F00654D8
F00654AC: 01000000                 nop
F00654B0: 1100003f901223ff         set     0xFFFF, %o0
F00654B8: 900a4008                 and     %o1, %o0, %o0
F00654BC: 90023ffa                 inc     -6, %o0
F00654C0: 80a22001                 cmp     %o0, 1
F00654C4: 18800005                 bgu     loc_F00654D8
F00654C8: 01000000                 nop
F00654CC: e0062014                 ld      [%i0+0x14], %l0
F00654D0: 40002733                 call    _pset_reference
F00654D4: 90100010                 mov     %l0, %o0
F00654D8: c0260000                 clr     [%i0]
F00654DC: 81c7e008                 ret
F00654E0: 91e80010                 restore %g0, %l0, %o0
