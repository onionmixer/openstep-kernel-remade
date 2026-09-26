F00C8AA4: 9de3bf98                 save    %sp, -0x68, %sp
F00C8AA8: 11000007                 sethi   0x1C00, %o0
F00C8AAC: 7ffff521                 call    _IOMalloc
F00C8AB0: 9012205c                 bset    0x5C, %o0 ! '\'! id
F00C8AB4: 133c0504                 sethi   %hi(paIsremovable), %o1
F00C8AB8: aa100008                 mov     %o0, %l5
F00C8ABC: d20261a8                 ld      [%o1+%lo(paIsremovable)], %o1! SEL
F00C8AC0: 4000a36c                 call    _objc_msgSend
F00C8AC4: 90100018                 mov     %i0, %o0
F00C8AC8: 912a2018                 sll     %o0, 24, %o0
F00C8ACC: 80a00008                 cmp     %g0, %o0
F00C8AD0: 113c0506                 sethi   %hi(paNextlogicaldis_0), %o0! id
F00C8AD4: d2022198                 ld      [%o0+%lo(paNextlogicaldis_0)], %o1! SEL
F00C8AD8: a8402000                 addc    %g0, 0, %l4
F00C8ADC: 4000a365                 call    _objc_msgSend
F00C8AE0: 90100018                 mov     %i0, %o0! id
F00C8AE4: 80a22000                 cmp     %o0, 0
F00C8AE8: 02800007                 be      loc_F00C8B04
F00C8AEC: 133c0504                 sethi   %hi(paReadlabel), %o1
F00C8AF0: d202619c                 ld      [%o1+%lo(paReadlabel)], %o1! SEL
F00C8AF4: 4000a35f                 call    _objc_msgSend
F00C8AF8: 94100015                 mov     %l5, %o2
F00C8AFC: 10800007                 ba      loc_F00C8B18
F00C8B00: 80a22000                 cmp     %o0, 0
F00C8B04: 113c03eb                 sethi   %hi(aVolcheckPhysde), %o0! "volCheck: physDev with no logicalDisk!!"...
F00C8B08: 7ffff57b                 call    _IOLog
F00C8B0C: 901223a8                 bset    %lo(aVolcheckPhysde), %o0! "volCheck: physDev with no logicalDisk!!"...
F00C8B10: 90103bb4                 mov     -0x44C, %o0
F00C8B14: 80a22000                 cmp     %o0, 0
F00C8B18: 32800004                 bne,a   loc_F00C8B28
F00C8B1C: 90100018                 mov     %i0, %o0! id
F00C8B20: 1080000a                 ba      loc_F00C8B48
F00C8B24: a6102000                 mov     0, %l3
F00C8B28: 133c0504                 sethi   %hi(paIsformatted), %o1
F00C8B2C: d2026178                 ld      [%o1+%lo(paIsformatted)], %o1! SEL
F00C8B30: 4000a350                 call    _objc_msgSend
F00C8B34: a6102002                 mov     2, %l3
F00C8B38: 912a2018                 sll     %o0, 24, %o0
F00C8B3C: 80a22000                 cmp     %o0, 0
F00C8B40: 32800002                 bne,a   loc_F00C8B48
F00C8B44: a6102001                 mov     1, %l3
F00C8B48: 113c0506                 sethi   %hi(paIswriteprotect), %o0! id
F00C8B4C: d20221bc                 ld      [%o0+%lo(paIswriteprotect)], %o1! SEL
F00C8B50: 4000a348                 call    _objc_msgSend
F00C8B54: 90100018                 mov     %i0, %o0
F00C8B58: 912a2018                 sll     %o0, 24, %o0
F00C8B5C: 80a22000                 cmp     %o0, 0
F00C8B60: 32800002                 bne,a   loc_F00C8B68
F00C8B64: a8152002                 bset    2, %l4
F00C8B68: 90100018                 mov     %i0, %o0! id
F00C8B6C: 133c0504                 sethi   %hi(paName), %o1
F00C8B70: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C8B74: a52e6010                 sll     %i1, 16, %l2
F00C8B78: a53ca010                 sra     %l2, 16, %l2
F00C8B7C: a32ea010                 sll     %i2, 16, %l1
F00C8B80: a33c6010                 sra     %l1, 16, %l1
F00C8B84: 213c03e9                 sethi   %hi(asc_F00FA528), %l0! ""
F00C8B88: 4000a33a                 call    _objc_msgSend
F00C8B8C: a0142128                 bset    %lo(asc_F00FA528), %l0! ""
F00C8B90: 98100008                 mov     %o0, %o4
F00C8B94: 90100012                 mov     %l2, %o0
F00C8B98: 92100011                 mov     %l1, %o1
F00C8B9C: 94100010                 mov     %l0, %o2
F00C8BA0: 96100013                 mov     %l3, %o3
F00C8BA4: 7fff2b42                 call    _vol_notify_dev
F00C8BA8: 9a100014                 mov     %l4, %o5
F00C8BAC: 90100015                 mov     %l5, %o0
F00C8BB0: 13000007                 sethi   0x1C00, %o1
F00C8BB4: 7ffff4e4                 call    _IOFree
F00C8BB8: 9212605c                 bset    0x5C, %o1 ! '\'
F00C8BBC: 81c7e008                 ret
F00C8BC0: 81e80000                 restore
