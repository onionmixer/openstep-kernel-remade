F00EB130: 9de3bf90                 save    %sp, -0x70, %sp
F00EB134: a2100018                 mov     %i0, %l1
F00EB138: 213c0504                 sethi   %hi(paIskindof), %l0
F00EB13C: 133c0504                 sethi   %hi(paClass), %o1! SEL
F00EB140: 90100011                 mov     %l1, %o0! id
F00EB144: 400019cb                 call    _objc_msgSend
F00EB148: d2026014                 ld      [%o1+%lo(paClass)], %o1! SEL
F00EB14C: 94100008                 mov     %o0, %o2
F00EB150: 9010001a                 mov     %i2, %o0! id
F00EB154: 400019c7                 call    _objc_msgSend
F00EB158: d2042040                 ld      [%l0+%lo(paIskindof)], %o1
F00EB15C: 912a2018                 sll     %o0, 24, %o0
F00EB160: 80a22000                 cmp     %o0, 0
F00EB164: 32800004                 bne,a   loc_F00EB174
F00EB168: d4046008                 ld      [%l1+8], %o2! __n
F00EB16C: 1080000c                 ba      locret_F00EB19C
F00EB170: b0102000                 mov     0, %i0
F00EB174: d006a008                 ld      [%i2+8], %o0
F00EB178: 80a28008                 cmp     %o2, %o0
F00EB17C: 12800008                 bne     locret_F00EB19C
F00EB180: b0102000                 mov     0, %i0
F00EB184: d0046004                 ld      [%l1+4], %o0! __s1
F00EB188: d206a004                 ld      [%i2+4], %o1! __s2
F00EB18C: 7ffc6beb                 call    _memcmp
F00EB190: 952aa002                 sll     %o2, 2, %o2
F00EB194: 80a00008                 cmp     %g0, %o0
F00EB198: b0603fff                 subc    %g0, -1, %i0
F00EB19C: 81c7e008                 ret
F00EB1A0: 81e80000                 restore
