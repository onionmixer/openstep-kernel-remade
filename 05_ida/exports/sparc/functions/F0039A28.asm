F0039A28: 9de3bf98                 save    %sp, -0x68, %sp
F0039A2C: d0064000                 ld      [%i1], %o0
F0039A30: e0062030                 ld      [%i0+0x30], %l0
F0039A34: d0268000                 st      %o0, [%i2]
F0039A38: d0066004                 ld      [%i1+4], %o0
F0039A3C: d036a004                 sth     %o0, [%i2+4]
F0039A40: d006600c                 ld      [%i1+0xC], %o0
F0039A44: d036a006                 sth     %o0, [%i2+6]
F0039A48: d0066010                 ld      [%i1+0x10], %o0
F0039A4C: d036a008                 sth     %o0, [%i2+8]
F0039A50: 7fffaa5a                 call    _vfs_fixedmajor
F0039A54: d0062024                 ld      [%i0+0x24], %o0
F0039A58: d2062024                 ld      [%i0+0x24], %o1
F0039A5C: d2026128                 ld      [%o1+0x128], %o1
F0039A60: d20a602b                 ldub    [%o1+0x2B], %o1
F0039A64: 912a2008                 sll     %o0, 8, %o0
F0039A68: 90120009                 bset    %o1, %o0
F0039A6C: 912a2010                 sll     %o0, 16, %o0
F0039A70: 913a2010                 sra     %o0, 16, %o0
F0039A74: 1300003f921263ff         set     0xFFFF, %o1
F0039A7C: 900a0009                 and     %o0, %o1, %o0
F0039A80: d026a00c                 st      %o0, [%i2+0xC]
F0039A84: d0066028                 ld      [%i1+0x28], %o0
F0039A88: d026a010                 st      %o0, [%i2+0x10]
F0039A8C: d0066008                 ld      [%i1+8], %o0
F0039A90: d036a014                 sth     %o0, [%i2+0x14]
F0039A94: f0060000                 ld      [%i0], %i0
F0039A98: d0066014                 ld      [%i1+0x14], %o0
F0039A9C: d4062014                 ld      [%i0+0x14], %o2
F0039AA0: 80a2000a                 cmp     %o0, %o2
F0039AA4: 1a80000c                 bcc     loc_F0039AD4
F0039AA8: 11100000                 sethi   0x40000000, %o0
F0039AAC: d2062038                 ld      [%i0+0x38], %o1
F0039AB0: 808a4008                 btst    %o0, %o1
F0039AB4: 3280000a                 bne,a   loc_F0039ADC
F0039AB8: d426a018                 st      %o2, [%i2+0x18]
F0039ABC: d0142060                 lduh    [%l0+0x60], %o0
F0039AC0: 808a2010                 btst    0x10, %o0
F0039AC4: 22800005                 be,a    loc_F0039AD8
F0039AC8: d0066014                 ld      [%i1+0x14], %o0
F0039ACC: 10800004                 ba      loc_F0039ADC
F0039AD0: d426a018                 st      %o2, [%i2+0x18]
F0039AD4: d0066014                 ld      [%i1+0x14], %o0
F0039AD8: d026a018                 st      %o0, [%i2+0x18]
F0039ADC: d0042098                 ld      [%l0+0x98], %o0
F0039AE0: d206a018                 ld      [%i2+0x18], %o1
F0039AE4: 80a20009                 cmp     %o0, %o1
F0039AE8: 2a800007                 bcs,a   loc_F0039B04
F0039AEC: d2242098                 st      %o1, [%l0+0x98]
F0039AF0: d0142060                 lduh    [%l0+0x60], %o0
F0039AF4: 808a2010                 btst    0x10, %o0
F0039AF8: 32800004                 bne,a   loc_F0039B08
F0039AFC: d006602c                 ld      [%i1+0x2C], %o0
F0039B00: d2242098                 st      %o1, [%l0+0x98]
F0039B04: d006602c                 ld      [%i1+0x2C], %o0
F0039B08: d026a020                 st      %o0, [%i2+0x20]
F0039B0C: d0066030                 ld      [%i1+0x30], %o0
F0039B10: d026a024                 st      %o0, [%i2+0x24]
F0039B14: d0066034                 ld      [%i1+0x34], %o0
F0039B18: d026a028                 st      %o0, [%i2+0x28]
F0039B1C: d0066038                 ld      [%i1+0x38], %o0
F0039B20: d026a02c                 st      %o0, [%i2+0x2C]
F0039B24: d006603c                 ld      [%i1+0x3C], %o0
F0039B28: d026a030                 st      %o0, [%i2+0x30]
F0039B2C: d0066040                 ld      [%i1+0x40], %o0
F0039B30: d026a034                 st      %o0, [%i2+0x34]
F0039B34: d006601c                 ld      [%i1+0x1C], %o0
F0039B38: d036a038                 sth     %o0, [%i2+0x38]
F0039B3C: d0066020                 ld      [%i1+0x20], %o0
F0039B40: d026a03c                 st      %o0, [%i2+0x3C]
F0039B44: d0064000                 ld      [%i1], %o0
F0039B48: 80a22003                 cmp     %o0, 3
F0039B4C: 02800006                 be      loc_F0039B64
F0039B50: 80a22004                 cmp     %o0, 4
F0039B54: 02800005                 be      loc_F0039B68
F0039B58: 11000008                 sethi   0x2000, %o0
F0039B5C: 10800003                 ba      loc_F0039B68
F0039B60: d0066018                 ld      [%i1+0x18], %o0
F0039B64: 90102800                 mov     0x800, %o0
F0039B68: d026a01c                 st      %o0, [%i2+0x1C]
F0039B6C: d0064000                 ld      [%i1], %o0
F0039B70: 80a22004                 cmp     %o0, 4
F0039B74: 1280000f                 bne     locret_F0039BB0
F0039B78: 01000000                 nop
F0039B7C: d006601c                 ld      [%i1+0x1C], %o0
F0039B80: 80a23fff                 cmp     %o0, -1
F0039B84: 1280000b                 bne     locret_F0039BB0
F0039B88: 90102008                 mov     8, %o0
F0039B8C: d0268000                 st      %o0, [%i2]
F0039B90: c036a038                 clrh    [%i2+0x38]
F0039B94: d016a004                 lduh    [%i2+4], %o0
F0039B98: 13000004                 sethi   0x1000, %o1
F0039B9C: 900a2fff                 and     %o0, 0xFFF, %o0
F0039BA0: 90120009                 bset    %o1, %o0
F0039BA4: d036a004                 sth     %o0, [%i2+4]
F0039BA8: d0066018                 ld      [%i1+0x18], %o0
F0039BAC: d026a01c                 st      %o0, [%i2+0x1C]
F0039BB0: 81c7e008                 ret
F0039BB4: 81e80000                 restore
