F00BBD1C: 9de3bf98                 save    %sp, -0x68, %sp
F00BBD20: 113c04fd                 sethi   %hi(_kmId), %o0
F00BBD24: d4022240                 ld      [%o0+%lo(_kmId)], %o2
F00BBD28: 80a2a000                 cmp     %o2, 0
F00BBD2C: 12800006                 bne     loc_F00BBD44
F00BBD30: 113c0504                 sethi   -0xFEBF000, %o0! id
F00BBD34: 7fffcca2                 call    _prom_getchar
F00BBD38: 01000000                 nop
F00BBD3C: 10800006                 ba      loc_F00BBD54
F00BBD40: b0100008                 mov     %o0, %i0
F00BBD44: d202222c                 ld      [%o0+0x22C], %o1! SEL
F00BBD48: 4000d6ca                 call    _objc_msgSend
F00BBD4C: 9010000a                 mov     %o2, %o0
F00BBD50: b0100008                 mov     %o0, %i0
F00BBD54: 80a6200d                 cmp     %i0, 0xD
F00BBD58: 22800002                 be,a    loc_F00BBD60
F00BBD5C: b010200a                 mov     0xA, %i0
F00BBD60: 7fffd7a4                 call    _cnputc
F00BBD64: 90100018                 mov     %i0, %o0
F00BBD68: 81c7e008                 ret
F00BBD6C: 81e80000                 restore
