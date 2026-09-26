F00EFAD4: 9de3bf98                 save    %sp, -0x68, %sp
F00EFAD8: e0060000                 ld      [%i0], %l0
F00EFADC: f224200c                 st      %i1, [%l0+0xC]
F00EFAE0: d0062004                 ld      [%i0+4], %o0! name
F00EFAE4: 80a22000                 cmp     %o0, 0
F00EFAE8: 02800008                 be      loc_F00EFB08
F00EFAEC: a2102000                 mov     0, %l1
F00EFAF0: 40000885                 call    _objc_getClass
F00EFAF4: 01000000                 nop
F00EFAF8: 80a22000                 cmp     %o0, 0
F00EFAFC: 22800003                 be,a    loc_F00EFB08
F00EFB00: a2102001                 mov     1, %l1
F00EFB04: d0262004                 st      %o0, [%i0+4]
F00EFB08: 4000087f                 call    _objc_getClass
F00EFB0C: d0040000                 ld      [%l0], %o0
F00EFB10: 80a22000                 cmp     %o0, 0
F00EFB14: 22800004                 be,a    loc_F00EFB24
F00EFB18: a2102001                 mov     1, %l1
F00EFB1C: d0020000                 ld      [%o0], %o0
F00EFB20: d0240000                 st      %o0, [%l0]
F00EFB24: d0042004                 ld      [%l0+4], %o0! name
F00EFB28: 80a22000                 cmp     %o0, 0
F00EFB2C: 22800009                 be,a    loc_F00EFB50
F00EFB30: f0242004                 st      %i0, [%l0+4]
F00EFB34: 40000874                 call    _objc_getClass
F00EFB38: 01000000                 nop
F00EFB3C: 80a22000                 cmp     %o0, 0
F00EFB40: 22800004                 be,a    loc_F00EFB50
F00EFB44: a2102001                 mov     1, %l1
F00EFB48: d0020000                 ld      [%o0], %o0
F00EFB4C: d0242004                 st      %o0, [%l0+4]
F00EFB50: d0062020                 ld      [%i0+0x20], %o0
F00EFB54: 80a22000                 cmp     %o0, 0
F00EFB58: 32800006                 bne,a   loc_F00EFB70
F00EFB5C: d0042020                 ld      [%l0+0x20], %o0
F00EFB60: 113c03e890122354         set     _emptyCache, %o0
F00EFB68: d0262020                 st      %o0, [%i0+0x20]
F00EFB6C: d0042020                 ld      [%l0+0x20], %o0
F00EFB70: 80a22000                 cmp     %o0, 0
F00EFB74: 12800005                 bne     loc_F00EFB88
F00EFB78: 80a46000                 cmp     %l1, 0
F00EFB7C: 113c03e890122354         set     _emptyCache, %o0
F00EFB84: d0242020                 st      %o0, [%l0+0x20]
F00EFB88: 02800004                 be      locret_F00EFB98
F00EFB8C: 113c03f4                 sethi   %hi(aPleaseLinkAppr), %o0! "please link appropriate classes in your"...
F00EFB90: 4000039e                 call    __objc_fatal
F00EFB94: 901220e0                 bset    %lo(aPleaseLinkAppr), %o0! "please link appropriate classes in your"...
F00EFB98: 81c7e008                 ret
F00EFB9C: 81e80000                 restore
