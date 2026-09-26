F002F78C: 9de3bf78                 save    %sp, -0x88, %sp
F002F790: 40019d41                 call    _splnet
F002F794: 01000000                 nop
F002F798: d206200c                 ld      [%i0+0xC], %o1
F002F79C: a0100008                 mov     %o0, %l0
F002F7A0: 92027fff                 inc     -1, %o1
F002F7A4: 80a26000                 cmp     %o1, 0
F002F7A8: 1280001c                 bne     loc_F002F818
F002F7AC: d226200c                 st      %o1, [%i0+0xC]
F002F7B0: 400026be                 call    _igmp_leavegroup
F002F7B4: 90100018                 mov     %i0, %o0
F002F7B8: d0062008                 ld      [%i0+8], %o0
F002F7BC: d2022044                 ld      [%o0+0x44], %o1
F002F7C0: 80a24018                 cmp     %o1, %i0
F002F7C4: 02800007                 be      loc_F002F7E0
F002F7C8: 94022044                 add     %o0, 0x44, %o2 ! 'D'
F002F7CC: d0028000                 ld      [%o2], %o0
F002F7D0: d2022014                 ld      [%o0+0x14], %o1
F002F7D4: 80a24018                 cmp     %o1, %i0
F002F7D8: 12bffffd                 bne     loc_F002F7CC
F002F7DC: 94022014                 add     %o0, 0x14, %o2
F002F7E0: d0028000                 ld      [%o2], %o0
F002F7E4: d0022014                 ld      [%o0+0x14], %o0
F002F7E8: 1320081a                 sethi   -0x7FDF9800, %o1
F002F7EC: d0228000                 st      %o0, [%o2]
F002F7F0: 90102002                 mov     2, %o0
F002F7F4: d037bfe8                 sth     %o0, [%fp+var_18]
F002F7F8: d0060000                 ld      [%i0], %o0
F002F7FC: 92126132                 bset    0x132, %o1
F002F800: d027bfec                 st      %o0, [%fp+var_14]
F002F804: d0062004                 ld      [%i0+4], %o0
F002F808: 7ffff112                 call    _if_ioctl
F002F80C: 9407bfd8                 add     %fp, var_28, %o2
F002F810: 7fffb8a9                 call    _m_free
F002F814: 900e3f80                 and     %i0, -0x80, %o0
F002F818: 40019d43                 call    _splx
F002F81C: 90100010                 mov     %l0, %o0
F002F820: 81c7e008                 ret
F002F824: 81e80000                 restore
