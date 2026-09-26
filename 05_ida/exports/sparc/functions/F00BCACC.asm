F00BCACC: 9de3bf90                 save    %sp, -0x70, %sp
F00BCAD0: d0062114                 ld      [%i0+0x114], %o0
F00BCAD4: 80a22001                 cmp     %o0, 1
F00BCAD8: 02800004                 be      loc_F00BCAE8
F00BCADC: 80a22003                 cmp     %o0, 3
F00BCAE0: 12800028                 bne     locret_F00BCB80
F00BCAE4: 01000000                 nop
F00BCAE8: 173c042d                 sethi   %hi(_pmsgbuf), %o3
F00BCAEC: d402e08c                 ld      [%o3+%lo(_pmsgbuf)], %o2
F00BCAF0: 1100018c                 sethi   0x63000, %o0
F00BCAF4: d2028000                 ld      [%o2], %o1
F00BCAF8: 90122061                 bset    0x61, %o0 ! 'a'
F00BCAFC: 80a24008                 cmp     %o1, %o0
F00BCB00: 12800020                 bne     locret_F00BCB80
F00BCB04: 233c0504                 sethi   -0xFEBF000, %l1
F00BCB08: a610000b                 mov     %o3, %l3
F00BCB0C: d002a004                 ld      [%o2+4], %o0
F00BCB10: 25000004                 sethi   0x1000, %l2
F00BCB14: 9002200c                 inc     0xC, %o0
F00BCB18: a0028008                 add     %o2, %o0, %l0
F00BCB1C: d04c0000                 ldsb    [%l0], %o0
F00BCB20: 80a22000                 cmp     %o0, 0
F00BCB24: 0280000b                 be      loc_F00BCB50
F00BCB28: 80a2200a                 cmp     %o0, 0xA
F00BCB2C: 12800006                 bne     loc_F00BCB44
F00BCB30: d2046228                 ld      [%l1+0x228], %o1! SEL
F00BCB34: 90100018                 mov     %i0, %o0! id
F00BCB38: 4000d34e                 call    _objc_msgSend
F00BCB3C: 9410200d                 mov     0xD, %o2
F00BCB40: d2046228                 ld      [%l1+0x228], %o1! SEL
F00BCB44: d44c0000                 ldsb    [%l0], %o2
F00BCB48: 4000d34a                 call    _objc_msgSend
F00BCB4C: 90100018                 mov     %i0, %o0
F00BCB50: d204e08c                 ld      [%l3+0x8C], %o1
F00BCB54: a0042001                 inc     %l0
F00BCB58: 90024012                 add     %o1, %l2, %o0
F00BCB5C: 80a40008                 cmp     %l0, %o0
F00BCB60: 3a800002                 bcc,a   loc_F00BCB68
F00BCB64: a002600c                 add     %o1, 0xC, %l0
F00BCB68: d0026004                 ld      [%o1+4], %o0
F00BCB6C: 9002200c                 inc     0xC, %o0
F00BCB70: 90024008                 add     %o1, %o0, %o0
F00BCB74: 80a40008                 cmp     %l0, %o0
F00BCB78: 32bfffea                 bne,a   loc_F00BCB20
F00BCB7C: d04c0000                 ldsb    [%l0], %o0
F00BCB80: 81c7e008                 ret
F00BCB84: 91e82000                 restore %g0, 0, %o0
