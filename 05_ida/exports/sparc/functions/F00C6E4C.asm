F00C6E4C: 9de3bf90                 save    %sp, -0x70, %sp
F00C6E50: d0062184                 ld      [%i0+0x184], %o0! id
F00C6E54: 233c0506                 sethi   %hi(paNextlogicaldis_0), %l1
F00C6E58: 4000aa86                 call    _objc_msgSend
F00C6E5C: d2046198                 ld      [%l1+%lo(paNextlogicaldis_0)], %o1
F00C6E60: a0920000                 orcc    %o0, %g0, %l0
F00C6E64: 22800015                 be,a    locret_F00C6EB8
F00C6E68: b0102000                 mov     0, %i0
F00C6E6C: 253c0504                 sethi   -0xFEBF000, %l2
F00C6E70: 80a40018                 cmp     %l0, %i0
F00C6E74: 0280000a                 be      loc_F00C6E9C
F00C6E78: d204a174                 ld      [%l2+0x174], %o1! SEL
F00C6E7C: 4000aa7d                 call    _objc_msgSend
F00C6E80: 90100010                 mov     %l0, %o0
F00C6E84: 912a2018                 sll     %o0, 24, %o0! id
F00C6E88: 80a22000                 cmp     %o0, 0
F00C6E8C: 02800005                 be      loc_F00C6EA0
F00C6E90: d2046198                 ld      [%l1+0x198], %o1
F00C6E94: 10800009                 ba      locret_F00C6EB8
F00C6E98: b0102001                 mov     1, %i0
F00C6E9C: d2046198                 ld      [%l1+0x198], %o1! SEL
F00C6EA0: 4000aa74                 call    _objc_msgSend
F00C6EA4: 90100010                 mov     %l0, %o0
F00C6EA8: a0920000                 orcc    %o0, %g0, %l0
F00C6EAC: 12bffff2                 bne     loc_F00C6E74
F00C6EB0: 80a40018                 cmp     %l0, %i0
F00C6EB4: b0102000                 mov     0, %i0
F00C6EB8: 81c7e008                 ret
F00C6EBC: 81e80000                 restore
