F002CE24: 9de3bf98                 save    %sp, -0x68, %sp
F002CE28: 80a62000                 cmp     %i0, 0
F002CE2C: 32800006                 bne,a   loc_F002CE44
F002CE30: d0162026                 lduh    [%i0+0x26], %o0
F002CE34: 113c0430                 sethi   %hi(aRtfree), %o0! "rtfree"
F002CE38: 7fffa0ce                 call    _panic
F002CE3C: 90122340                 bset    %lo(aRtfree), %o0! "rtfree"
F002CE40: d0162026                 lduh    [%i0+0x26], %o0
F002CE44: 90023fff                 inc     -1, %o0
F002CE48: d0362026                 sth     %o0, [%i0+0x26]
F002CE4C: d2062024                 ld      [%i0+0x24], %o1
F002CE50: 113fff80                 sethi   -0x20000, %o0
F002CE54: 80aa4008                 andncc  %o1, %o0, %g0
F002CE58: 12800007                 bne     locret_F002CE74
F002CE5C: 153c04d9                 sethi   %hi(_rttrash), %o2
F002CE60: d202a050                 ld      [%o2+%lo(_rttrash)], %o1
F002CE64: 900e3f80                 and     %i0, -0x80, %o0
F002CE68: 92027fff                 inc     -1, %o1
F002CE6C: 7fffc312                 call    _m_free
F002CE70: d222a050                 st      %o1, [%o2+%lo(_rttrash)]
F002CE74: 81c7e008                 ret
F002CE78: 81e80000                 restore
