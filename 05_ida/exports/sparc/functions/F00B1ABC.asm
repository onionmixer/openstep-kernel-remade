F00B1ABC: 9de3bf98                 save    %sp, -0x68, %sp
F00B1AC0: 1108001d90122071         set     0x20007471, %o0
F00B1AC8: 80a64008                 cmp     %i1, %o0
F00B1ACC: 1280001b                 bne     loc_F00B1B38
F00B1AD0: 9410001a                 mov     %i2, %o2
F00B1AD4: 113c04cf                 sethi   %hi(_active_u), %o0
F00B1AD8: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00B1ADC: f2020000                 ld      [%o0], %i1
F00B1AE0: 7ffd7410                 call    _get_posix_proc
F00B1AE4: d0566030                 ldsh    [%i1+0x30], %o0
F00B1AE8: 98100008                 mov     %o0, %o4
F00B1AEC: 153c04d4                 sethi   %hi(_cons_tp), %o2
F00B1AF0: d2032010                 ld      [%o4+0x10], %o1
F00B1AF4: 113c04d4                 sethi   %hi(_cons), %o0
F00B1AF8: d6026008                 ld      [%o1+8], %o3
F00B1AFC: 90122190                 bset    %lo(_cons), %o0
F00B1B00: d202e004                 ld      [%o3+4], %o1
F00B1B04: 80a24019                 cmp     %o1, %i1
F00B1B08: 12800006                 bne     loc_F00B1B20
F00B1B0C: d022a290                 st      %o0, [%o2+%lo(_cons_tp)]
F00B1B10: c022e008                 clr     [%o3+8]
F00B1B14: d0032010                 ld      [%o4+0x10], %o0
F00B1B18: d0022008                 ld      [%o0+8], %o0
F00B1B1C: c032200c                 clrh    [%o0+0xC]
F00B1B20: b0102000                 mov     0, %i0
F00B1B24: d2066028                 ld      [%i1+0x28], %o1
F00B1B28: 11100000                 sethi   0x40000000, %o0
F00B1B2C: 902a4008                 andn    %o1, %o0, %o0
F00B1B30: 10800015                 ba      locret_F00B1B84
F00B1B34: d0266028                 st      %o0, [%i1+0x28]
F00B1B38: 113c04d4                 sethi   %hi(_cons_tp), %o0
F00B1B3C: d0022290                 ld      [%o0+%lo(_cons_tp)], %o0
F00B1B40: d2122038                 lduh    [%o0+0x38], %o1
F00B1B44: 932a6010                 sll     %o1, 16, %o1
F00B1B48: 913a6010                 sra     %o1, 16, %o0
F00B1B4C: 93326018                 srl     %o1, 24, %o1
F00B1B50: 972a6001                 sll     %o1, 1, %o3
F00B1B54: 9602c009                 add     %o3, %o1, %o3
F00B1B58: 972ae002                 sll     %o3, 2, %o3
F00B1B5C: 9622c009                 sub     %o3, %o1, %o3
F00B1B60: 972ae002                 sll     %o3, 2, %o3
F00B1B64: 133c0472921261f0         set     _cdevsw, %o1
F00B1B6C: 9602c009                 add     %o3, %o1, %o3
F00B1B70: d802e010                 ld      [%o3+0x10], %o4
F00B1B74: 92100019                 mov     %i1, %o1
F00B1B78: 9fc30000                 call    %o4
F00B1B7C: 9610001b                 mov     %i3, %o3
F00B1B80: b0100008                 mov     %o0, %i0
F00B1B84: 81c7e008                 ret
F00B1B88: 81e80000                 restore
