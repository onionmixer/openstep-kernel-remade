F004F98C: 9de3bf98                 save    %sp, -0x68, %sp
F004F990: 80a62000                 cmp     %i0, 0
F004F994: 12800006                 bne     loc_F004F9AC
F004F998: f0270000                 st      %i0, [%i4]
F004F99C: 10800072                 ba      locret_F004FB64
F004F9A0: b0102000                 mov     0, %i0
F004F9A4: 10800070                 ba      locret_F004FB64
F004F9A8: b0102001                 mov     1, %i0
F004F9AC: e2066004                 ld      [%i1+4], %l1
F004F9B0: e0066008                 ld      [%i1+8], %l0
F004F9B4: 808ea001                 btst    1, %i2
F004F9B8: 02800008                 be      loc_F004F9D8
F004F9BC: 808ea002                 btst    2, %i2
F004F9C0: d206200c                 ld      [%i0+0xC], %o1
F004F9C4: d006600c                 ld      [%i1+0xC], %o0
F004F9C8: 80a24008                 cmp     %o1, %o0
F004F9CC: 12800020                 bne     loc_F004FA4C
F004F9D0: 90062014                 add     %i0, 0x14, %o0
F004F9D4: 808ea002                 btst    2, %i2
F004F9D8: 22800008                 be,a    loc_F004F9F8
F004F9DC: d0062008                 ld      [%i0+8], %o0
F004F9E0: d206200c                 ld      [%i0+0xC], %o1
F004F9E4: d006600c                 ld      [%i1+0xC], %o0
F004F9E8: 80a24008                 cmp     %o1, %o0
F004F9EC: 02800018                 be      loc_F004FA4C
F004F9F0: 90062014                 add     %i0, 0x14, %o0
F004F9F4: d0062008                 ld      [%i0+8], %o0
F004F9F8: 80a23fff                 cmp     %o0, -1
F004F9FC: 02800004                 be      loc_F004FA0C
F004FA00: 80a44008                 cmp     %l1, %o0
F004FA04: 18800009                 bgu     loc_F004FA28
F004FA08: 808ea001                 btst    1, %i2
F004FA0C: 80a43fff                 cmp     %l0, -1
F004FA10: 22800014                 be,a    loc_F004FA60
F004FA14: d2062004                 ld      [%i0+4], %o1
F004FA18: d0062004                 ld      [%i0+4], %o0
F004FA1C: 80a20010                 cmp     %o0, %l0
F004FA20: 0880000f                 bleu    loc_F004FA5C
F004FA24: 808ea001                 btst    1, %i2
F004FA28: 02800008                 be      loc_F004FA48
F004FA2C: 80a43fff                 cmp     %l0, -1
F004FA30: 02800007                 be      loc_F004FA4C
F004FA34: 90062014                 add     %i0, 0x14, %o0
F004FA38: d0062004                 ld      [%i0+4], %o0
F004FA3C: 80a20010                 cmp     %o0, %l0
F004FA40: 38800049                 bgu,a   locret_F004FB64
F004FA44: b0102000                 mov     0, %i0
F004FA48: 90062014                 add     %i0, 0x14, %o0
F004FA4C: d026c000                 st      %o0, [%i3]
F004FA50: f0062014                 ld      [%i0+0x14], %i0
F004FA54: 10800040                 ba      loc_F004FB54
F004FA58: f0270000                 st      %i0, [%i4]
F004FA5C: d2062004                 ld      [%i0+4], %o1
F004FA60: 80a24011                 cmp     %o1, %l1
F004FA64: 12800006                 bne     loc_F004FA7C
F004FA68: 01000000                 nop
F004FA6C: d0062008                 ld      [%i0+8], %o0
F004FA70: 80a20010                 cmp     %o0, %l0
F004FA74: 02bfffcc                 be      loc_F004F9A4
F004FA78: 80a24011                 cmp     %o1, %l1
F004FA7C: 1880000c                 bgu     loc_F004FAAC
F004FA80: 80a43fff                 cmp     %l0, -1
F004FA84: 2280000b                 be,a    loc_F004FAB0
F004FA88: d0062004                 ld      [%i0+4], %o0
F004FA8C: d0062008                 ld      [%i0+8], %o0
F004FA90: 80a20010                 cmp     %o0, %l0
F004FA94: 1a800004                 bcc     loc_F004FAA4
F004FA98: 80a23fff                 cmp     %o0, -1
F004FA9C: 32800005                 bne,a   loc_F004FAB0
F004FAA0: d0062004                 ld      [%i0+4], %o0
F004FAA4: 10800030                 ba      locret_F004FB64
F004FAA8: b0102002                 mov     2, %i0
F004FAAC: d0062004                 ld      [%i0+4], %o0
F004FAB0: 80a44008                 cmp     %l1, %o0
F004FAB4: 1880000c                 bgu     loc_F004FAE4
F004FAB8: 80a43fff                 cmp     %l0, -1
F004FABC: 2280002a                 be,a    locret_F004FB64
F004FAC0: b0102003                 mov     3, %i0
F004FAC4: d0062008                 ld      [%i0+8], %o0
F004FAC8: 80a23fff                 cmp     %o0, -1
F004FACC: 02800006                 be      loc_F004FAE4
F004FAD0: 80a40008                 cmp     %l0, %o0
F004FAD4: 2a800005                 bcs,a   loc_F004FAE8
F004FAD8: d0062004                 ld      [%i0+4], %o0
F004FADC: 10800022                 ba      locret_F004FB64
F004FAE0: b0102003                 mov     3, %i0
F004FAE4: d0062004                 ld      [%i0+4], %o0
F004FAE8: 80a20011                 cmp     %o0, %l1
F004FAEC: 3a80000a                 bcc,a   loc_F004FB14
F004FAF0: d0062004                 ld      [%i0+4], %o0
F004FAF4: d0062008                 ld      [%i0+8], %o0
F004FAF8: 80a20011                 cmp     %o0, %l1
F004FAFC: 1a800004                 bcc     loc_F004FB0C
F004FB00: 80a23fff                 cmp     %o0, -1
F004FB04: 32800004                 bne,a   loc_F004FB14
F004FB08: d0062004                 ld      [%i0+4], %o0
F004FB0C: 10800016                 ba      locret_F004FB64
F004FB10: b0102004                 mov     4, %i0
F004FB14: 80a20011                 cmp     %o0, %l1
F004FB18: 0880000c                 bleu    loc_F004FB48
F004FB1C: 80a43fff                 cmp     %l0, -1
F004FB20: 0280000b                 be      loc_F004FB4C
F004FB24: 113c043b                 sethi   -0xFEF1400, %o0
F004FB28: d0062008                 ld      [%i0+8], %o0
F004FB2C: 80a20010                 cmp     %o0, %l0
F004FB30: 18800004                 bgu     loc_F004FB40
F004FB34: 80a23fff                 cmp     %o0, -1
F004FB38: 12800005                 bne     loc_F004FB4C
F004FB3C: 113c043b                 sethi   -0xFEF1400, %o0
F004FB40: 10800009                 ba      locret_F004FB64
F004FB44: b0102005                 mov     5, %i0
F004FB48: 113c043b                 sethi   -0xFEF1400, %o0! char *
F004FB4C: 7fff1589                 call    _panic
F004FB50: 90122110                 bset    0x110, %o0
F004FB54: 80a62000                 cmp     %i0, 0
F004FB58: 12bfff98                 bne     loc_F004F9B8
F004FB5C: 808ea001                 btst    1, %i2
F004FB60: b0102000                 mov     0, %i0
F004FB64: 81c7e008                 ret
F004FB68: 81e80000                 restore
