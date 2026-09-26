F00B8980: 9de3bf98                 save    %sp, -0x68, %sp
F00B8984: aa100018                 mov     %i0, %l5
F00B8988: a2102000                 mov     0, %l1
F00B898C: a0102000                 mov     0, %l0
F00B8990: 2d3c047d                 sethi   -0xFEE0C00, %l6
F00B8994: 113c04fc                 sethi   %hi(_scsi_spl), %o0
F00B8998: d00220c0                 ld      [%o0+%lo(_scsi_spl)], %o0
F00B899C: 7fff78da                 call    _splr
F00B89A0: 273c047d                 sethi   -0xFEE0C00, %l3
F00B89A4: a8100008                 mov     %o0, %l4
F00B89A8: 113c04c5                 sethi   -0xFECEC00, %o0
F00B89AC: a4100008                 mov     %o0, %l2
F00B89B0: f004a39c                 ld      [%l2+0x39C], %i0
F00B89B4: 80a62000                 cmp     %i0, 0
F00B89B8: 1280001a                 bne     loc_F00B8A20
F00B89BC: 80a6600c                 cmp     %i1, 0xC
F00B89C0: 80a6e001                 cmp     %i3, 1
F00B89C4: 12800011                 bne     loc_F00B8A08
F00B89C8: 80a6e000                 cmp     %i3, 0
F00B89CC: 7fff791c                 call    _servicing_interrupt
F00B89D0: 01000000                 nop
F00B89D4: 80a22000                 cmp     %o0, 0
F00B89D8: 02800005                 be      loc_F00B89EC
F00B89DC: 9014a39c                 or      %l2, 0x39C, %o0! char *
F00B89E0: 7ffd71e4                 call    _panic
F00B89E4: 9015a0d0                 or      %l6, 0xD0, %o0
F00B89E8: 9014a39c                 or      %l2, 0x39C, %o0! unsigned int
F00B89EC: d404e0a4                 ld      [%l3+0xA4], %o2
F00B89F0: 92102014                 mov     0x14, %o1
F00B89F4: 9402a001                 inc     %o2
F00B89F8: 7ffd6720                 call    _sleep
F00B89FC: d424e0a4                 st      %o2, [%l3+0xA4]
F00B8A00: 10bfffed                 ba      loc_F00B89B4
F00B8A04: f004a39c                 ld      [%l2+0x39C], %i0
F00B8A08: 0280001d                 be      loc_F00B8A7C
F00B8A0C: 113c04c5                 sethi   %hi(dword_F01317A0), %o0
F00B8A10: 901223a0                 bset    %lo(dword_F01317A0), %o0
F00B8A14: 40000102                 call    sub_F00B8E1C
F00B8A18: 9210001b                 mov     %i3, %o1! size_t
F00B8A1C: 30800018                 ba,a    loc_F00B8A7C
F00B8A20: 0480000a                 ble     loc_F00B8A48
F00B8A24: 80a6a003                 cmp     %i2, 3
F00B8A28: 7ffebd92                 call    _kalloc
F00B8A2C: 90100019                 mov     %i1, %o0
F00B8A30: a0920000                 orcc    %o0, %g0, %l0
F00B8A34: 0280000c                 be      loc_F00B8A64
F00B8A38: 90100010                 mov     %l0, %o0! void *
F00B8A3C: 7fff7107                 call    _bzero
F00B8A40: 92100019                 mov     %i1, %o1! size_t
F00B8A44: 80a6a003                 cmp     %i2, 3
F00B8A48: 2480000c                 ble,a   loc_F00B8A78
F00B8A4C: d0060000                 ld      [%i0], %o0
F00B8A50: 7ffebd88                 call    _kalloc
F00B8A54: 9010001a                 mov     %i2, %o0
F00B8A58: a2920000                 orcc    %o0, %g0, %l1
F00B8A5C: 12800004                 bne     loc_F00B8A6C
F00B8A60: 90100011                 mov     %l1, %o0! void *
F00B8A64: 10bfffd4                 ba      loc_F00B89B4
F00B8A68: b0102000                 mov     0, %i0
F00B8A6C: 7fff70fb                 call    _bzero
F00B8A70: 9210001a                 mov     %i2, %o1! size_t
F00B8A74: d0060000                 ld      [%i0], %o0
F00B8A78: d024a39c                 st      %o0, [%l2+0x39C]
F00B8A7C: 7fff78aa                 call    _splx
F00B8A80: 90100014                 mov     %l4, %o0
F00B8A84: 80a62000                 cmp     %i0, 0
F00B8A88: 0280001c                 be      locret_F00B8AF8
F00B8A8C: 90100018                 mov     %i0, %o0! void *
F00B8A90: 7fff70f2                 call    _bzero
F00B8A94: 92102070                 mov     0x70, %o1 ! 'p'
F00B8A98: 80a42000                 cmp     %l0, 0
F00B8A9C: 02800007                 be      loc_F00B8AB8
F00B8AA0: 90062064                 add     %i0, 0x64, %o0 ! 'd'
F00B8AA4: d016205c                 lduh    [%i0+0x5C], %o0
F00B8AA8: e0262020                 st      %l0, [%i0+0x20]
F00B8AAC: 90122040                 bset    0x40, %o0 ! '@'
F00B8AB0: 10800003                 ba      loc_F00B8ABC
F00B8AB4: d036205c                 sth     %o0, [%i0+0x5C]
F00B8AB8: d0262020                 st      %o0, [%i0+0x20]
F00B8ABC: 80a46000                 cmp     %l1, 0
F00B8AC0: 02800007                 be      loc_F00B8ADC
F00B8AC4: 90062060                 add     %i0, 0x60, %o0 ! '`'
F00B8AC8: d016205c                 lduh    [%i0+0x5C], %o0
F00B8ACC: e226201c                 st      %l1, [%i0+0x1C]
F00B8AD0: 90122080                 bset    0x80, %o0
F00B8AD4: 10800003                 ba      loc_F00B8AE0
F00B8AD8: d036205c                 sth     %o0, [%i0+0x5C]
F00B8ADC: d026201c                 st      %o0, [%i0+0x1C]
F00B8AE0: f22e2063                 stb     %i1, [%i0+0x63]
F00B8AE4: f42e205f                 stb     %i2, [%i0+0x5F]
F00B8AE8: d0054000                 ld      [%l5], %o0
F00B8AEC: d0262004                 st      %o0, [%i0+4]
F00B8AF0: d0056004                 ld      [%l5+4], %o0
F00B8AF4: d0262008                 st      %o0, [%i0+8]
F00B8AF8: 81c7e008                 ret
F00B8AFC: 81e80000                 restore
