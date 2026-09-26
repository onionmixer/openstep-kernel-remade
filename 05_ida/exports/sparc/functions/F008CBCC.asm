F008CBCC: 9de3bf90                 save    %sp, -0x70, %sp
F008CBD0: d206200c                 ld      [%i0+0xC], %o1
F008CBD4: 80a68009                 cmp     %i2, %o1
F008CBD8: 0a800007                 bcs     loc_F008CBF4
F008CBDC: e2062018                 ld      [%i0+0x18], %l1
F008CBE0: d0062008                 ld      [%i0+8], %o0
F008CBE4: 90024008                 add     %o1, %o0, %o0
F008CBE8: 80a68008                 cmp     %i2, %o0
F008CBEC: 0a800004                 bcs     loc_F008CBFC
F008CBF0: 90268009                 sub     %i2, %o1, %o0
F008CBF4: 10800024                 ba      locret_F008CC84
F008CBF8: b0102000                 mov     0, %i0
F008CBFC: a12a2002                 sll     %o0, 2, %l0
F008CC00: d4044010                 ld      [%l1+%l0], %o2
F008CC04: 80a2a000                 cmp     %o2, 0
F008CC08: 02800008                 be      loc_F008CC28
F008CC0C: a4044010                 add     %l1, %l0, %l2
F008CC10: 113c0504                 sethi   %hi(paShare), %o0! id
F008CC14: d202203c                 ld      [%o0+%lo(paShare)], %o1! SEL
F008CC18: 40019316                 call    _objc_msgSend
F008CC1C: 9010000a                 mov     %o2, %o0
F008CC20: 10800019                 ba      locret_F008CC84
F008CC24: b0100008                 mov     %o0, %i0
F008CC28: d0062010                 ld      [%i0+0x10], %o0! id
F008CC2C: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F008CC30: 40019310                 call    _objc_msgSend
F008CC34: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F008CC38: 133c0504                 sethi   %hi(paInitforresourc_0), %o1
F008CC3C: 94100018                 mov     %i0, %o2
F008CC40: 9610001a                 mov     %i2, %o3
F008CC44: d2026034                 ld      [%o1+%lo(paInitforresourc_0)], %o1! SEL
F008CC48: 4001930a                 call    _objc_msgSend
F008CC4C: 98102001                 mov     1, %o4
F008CC50: 80a22000                 cmp     %o0, 0
F008CC54: 0280000b                 be      loc_F008CC80
F008CC58: d0244010                 st      %o0, [%l1+%l0]
F008CC5C: d0062014                 ld      [%i0+0x14], %o0
F008CC60: 90022001                 inc     %o0
F008CC64: 80a22001                 cmp     %o0, 1
F008CC68: 12800006                 bne     loc_F008CC80
F008CC6C: d0262014                 st      %o0, [%i0+0x14]
F008CC70: d0062004                 ld      [%i0+4], %o0! id
F008CC74: 133c0504                 sethi   %hi(paResourceactive), %o1! SEL
F008CC78: 400192fe                 call    _objc_msgSend
F008CC7C: d2026038                 ld      [%o1+%lo(paResourceactive)], %o1
F008CC80: f0048000                 ld      [%l2], %i0
F008CC84: 81c7e008                 ret
F008CC88: 81e80000                 restore
