F003EEEC: 9de3bf58                 save    %sp, -0xA8, %sp
F003EEF0: d0062028                 ld      [%i0+0x28], %o0
F003EEF4: 80a22001                 cmp     %o0, 1
F003EEF8: 02800004                 be      loc_F003EF08
F003EEFC: a0102000                 mov     0, %l0
F003EF00: 1080003e                 ba      locret_F003EFF8
F003EF04: b0102015                 mov     0x15, %i0
F003EF08: 80a6a001                 cmp     %i2, 1
F003EF0C: 02800009                 be      loc_F003EF30
F003EF10: e2062030                 ld      [%i0+0x30], %l1
F003EF14: 80a6a000                 cmp     %i2, 0
F003EF18: 12800018                 bne     loc_F003EF78
F003EF1C: 808ee002                 btst    2, %i3
F003EF20: d0046070                 ld      [%l1+0x70], %o0
F003EF24: 80a22000                 cmp     %o0, 0
F003EF28: 12800014                 bne     loc_F003EF78
F003EF2C: 808ee002                 btst    2, %i3
F003EF30: d0170000                 lduh    [%i4], %o0
F003EF34: 90022001                 inc     %o0
F003EF38: d0370000                 sth     %o0, [%i4]
F003EF3C: d0046070                 ld      [%l1+0x70], %o0
F003EF40: 80a22000                 cmp     %o0, 0
F003EF44: 22800005                 be,a    loc_F003EF58
F003EF48: f8246070                 st      %i4, [%l1+0x70]
F003EF4C: 7fff42b3                 call    _crfree
F003EF50: 01000000                 nop
F003EF54: f8246070                 st      %i4, [%l1+0x70]
F003EF58: d0060000                 ld      [%i0], %o0
F003EF5C: d0020000                 ld      [%o0], %o0
F003EF60: 80a22000                 cmp     %o0, 0
F003EF64: 02800005                 be      loc_F003EF78
F003EF68: 808ee002                 btst    2, %i3
F003EF6C: 40013495                 call    _vnode_uncache
F003EF70: 90100018                 mov     %i0, %o0
F003EF74: 808ee002                 btst    2, %i3
F003EF78: 0280000e                 be      loc_F003EFB0
F003EF7C: 80a6a001                 cmp     %i2, 1
F003EF80: 1280000d                 bne     loc_F003EFB4
F003EF84: 80a42000                 cmp     %l0, 0
F003EF88: 7ffff9a7                 call    _rlock
F003EF8C: 90100011                 mov     %l1, %o0
F003EF90: 90100018                 mov     %i0, %o0
F003EF94: 9207bfb8                 add     %fp, var_48, %o1
F003EF98: 400001e6                 call    sub_F003F730
F003EF9C: 9410001c                 mov     %i4, %o2
F003EFA0: a0920000                 orcc    %o0, %g0, %l0
F003EFA4: 12800004                 bne     loc_F003EFB4
F003EFA8: d007bfd0                 ld      [%fp+var_30], %o0
F003EFAC: d0266008                 st      %o0, [%i1+8]
F003EFB0: 80a42000                 cmp     %l0, 0
F003EFB4: 1280000a                 bne     loc_F003EFDC
F003EFB8: 808ee002                 btst    2, %i3
F003EFBC: 90100018                 mov     %i0, %o0
F003EFC0: 92100019                 mov     %i1, %o1
F003EFC4: 9410001a                 mov     %i2, %o2
F003EFC8: 9610001b                 mov     %i3, %o3
F003EFCC: 4000000d                 call    sub_F003F000
F003EFD0: 9810001c                 mov     %i4, %o4
F003EFD4: a0100008                 mov     %o0, %l0
F003EFD8: 808ee002                 btst    2, %i3
F003EFDC: 02800006                 be      loc_F003EFF4
F003EFE0: 80a6a001                 cmp     %i2, 1
F003EFE4: 12800005                 bne     locret_F003EFF8
F003EFE8: b0100010                 mov     %l0, %i0
F003EFEC: 7ffff9ac                 call    _runlock
F003EFF0: 90100011                 mov     %l1, %o0
F003EFF4: b0100010                 mov     %l0, %i0
F003EFF8: 81c7e008                 ret
F003EFFC: 81e80000                 restore
