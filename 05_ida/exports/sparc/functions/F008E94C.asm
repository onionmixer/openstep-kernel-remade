F008E94C: 9de3bf90                 save    %sp, -0x70, %sp
F008E950: d0062008                 ld      [%i0+8], %o0! id
F008E954: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F008E958: 40018bc6                 call    _objc_msgSend
F008E95C: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F008E960: e2062004                 ld      [%i0+4], %l1
F008E964: 80a46000                 cmp     %l1, 0
F008E968: 12800007                 bne     loc_F008E984
F008E96C: d0062008                 ld      [%i0+8], %o0! id
F008E970: 133c0504                 sethi   %hi(paRelease), %o1! SEL
F008E974: 40018bbf                 call    _objc_msgSend
F008E978: d202609c                 ld      [%o1+%lo(paRelease)], %o1
F008E97C: 10800018                 ba      locret_F008E9DC
F008E980: b0102000                 mov     0, %i0
F008E984: c0262004                 clr     [%i0+4]
F008E988: e00e2018                 ldub    [%i0+0x18], %l0
F008E98C: 133c0504                 sethi   %hi(paRelease), %o1
F008E990: d202609c                 ld      [%o1+%lo(paRelease)], %o1! SEL
F008E994: 40018bb7                 call    _objc_msgSend
F008E998: c02e2018                 clrb    [%i0+0x18]
F008E99C: 80a42000                 cmp     %l0, 0
F008E9A0: 32800007                 bne,a   loc_F008E9BC
F008E9A4: 90100011                 mov     %l1, %o0
F008E9A8: 113c0504                 sethi   %hi(paSuspend), %o0! id
F008E9AC: d20220d4                 ld      [%o0+%lo(paSuspend)], %o1! SEL
F008E9B0: 40018bb0                 call    _objc_msgSend
F008E9B4: 90100011                 mov     %l1, %o0
F008E9B8: 90100011                 mov     %l1, %o0! id
F008E9BC: 133c0504                 sethi   %hi(paDetachdevicein), %o1
F008E9C0: d20260e0                 ld      [%o1+%lo(paDetachdevicein)], %o1! SEL
F008E9C4: 40018bab                 call    _objc_msgSend
F008E9C8: 94100018                 mov     %i0, %o2
F008E9CC: 113c0504                 sethi   %hi(paResume), %o0! id
F008E9D0: d20220d8                 ld      [%o0+%lo(paResume)], %o1! SEL
F008E9D4: 40018ba7                 call    _objc_msgSend
F008E9D8: 90100011                 mov     %l1, %o0
F008E9DC: 81c7e008                 ret
F008E9E0: 81e80000                 restore
