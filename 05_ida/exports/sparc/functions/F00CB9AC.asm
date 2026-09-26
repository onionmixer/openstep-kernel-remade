F00CB9AC: 9de3bf90                 save    %sp, -0x70, %sp
F00CB9B0: d04e2128                 ldsb    [%i0+0x128], %o0
F00CB9B4: 80a22000                 cmp     %o0, 0
F00CB9B8: 12800005                 bne     loc_F00CB9CC
F00CB9BC: 01000000                 nop
F00CB9C0: 7ffd8039                 call    _nb_free
F00CB9C4: 9010001a                 mov     %i2, %o0
F00CB9C8: 3080002b                 ba,a    locret_F00CBA74
F00CB9CC: 7ffd8032                 call    _nb_map
F00CB9D0: 9010001a                 mov     %i2, %o0
F00CB9D4: d40ec000                 ldub    [%i3], %o2
F00CB9D8: 92100008                 mov     %o0, %o1
F00CB9DC: d42a4000                 stb     %o2, [%o1]
F00CB9E0: d00ee001                 ldub    [%i3+1], %o0
F00CB9E4: d02a6001                 stb     %o0, [%o1+1]
F00CB9E8: d00ee002                 ldub    [%i3+2], %o0
F00CB9EC: d02a6002                 stb     %o0, [%o1+2]
F00CB9F0: d00ee003                 ldub    [%i3+3], %o0
F00CB9F4: d02a6003                 stb     %o0, [%o1+3]
F00CB9F8: d00ee004                 ldub    [%i3+4], %o0
F00CB9FC: d02a6004                 stb     %o0, [%o1+4]
F00CBA00: d00ee005                 ldub    [%i3+5], %o0
F00CBA04: d02a6005                 stb     %o0, [%o1+5]
F00CBA08: d00e2150                 ldub    [%i0+0x150], %o0
F00CBA0C: d02a6006                 stb     %o0, [%o1+6]
F00CBA10: d00e2151                 ldub    [%i0+0x151], %o0
F00CBA14: d02a6007                 stb     %o0, [%o1+7]
F00CBA18: d00e2152                 ldub    [%i0+0x152], %o0
F00CBA1C: d02a6008                 stb     %o0, [%o1+8]
F00CBA20: d00e2153                 ldub    [%i0+0x153], %o0
F00CBA24: d02a6009                 stb     %o0, [%o1+9]
F00CBA28: d00e2154                 ldub    [%i0+0x154], %o0
F00CBA2C: d02a600a                 stb     %o0, [%o1+0xA]
F00CBA30: d40e2155                 ldub    [%i0+0x155], %o2
F00CBA34: 9010001a                 mov     %i2, %o0
F00CBA38: 7ffd8028                 call    _nb_size
F00CBA3C: d42a600b                 stb     %o2, [%o1+0xB]
F00CBA40: 94100008                 mov     %o0, %o2
F00CBA44: 80a2a03b                 cmp     %o2, 0x3B ! ';'
F00CBA48: 14800007                 bg      loc_F00CBA64
F00CBA4C: 90100018                 mov     %i0, %o0
F00CBA50: 9010001a                 mov     %i2, %o0
F00CBA54: 9210203c                 mov     0x3C, %o1 ! '<'
F00CBA58: 7ffd805c                 call    _nb_grow_bot
F00CBA5C: 9222400a                 sub     %o1, %o2, %o1
F00CBA60: 90100018                 mov     %i0, %o0! id
F00CBA64: 133c0506                 sethi   %hi(paTransmit), %o1
F00CBA68: d2026050                 ld      [%o1+%lo(paTransmit)], %o1! SEL
F00CBA6C: 40009781                 call    _objc_msgSend
F00CBA70: 9410001a                 mov     %i2, %o2
F00CBA74: 81c7e008                 ret
F00CBA78: 91e82000                 restore %g0, 0, %o0
