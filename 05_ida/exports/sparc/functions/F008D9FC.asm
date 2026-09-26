F008D9FC: 9de3bf90                 save    %sp, -0x70, %sp
F008DA00: e0062004                 ld      [%i0+4], %l0
F008DA04: 113c0504                 sethi   %hi(paValueforkey), %o0! id
F008DA08: d202206c                 ld      [%o0+%lo(paValueforkey)], %o1! SEL
F008DA0C: 9410001a                 mov     %i2, %o2
F008DA10: 40018f98                 call    _objc_msgSend
F008DA14: 90100010                 mov     %l0, %o0
F008DA18: b0920000                 orcc    %o0, %g0, %i0
F008DA1C: 02800007                 be      loc_F008DA38
F008DA20: 90100010                 mov     %l0, %o0! id
F008DA24: 133c0504                 sethi   %hi(paRemovekey), %o1
F008DA28: d2026080                 ld      [%o1+%lo(paRemovekey)], %o1! SEL
F008DA2C: 40018f91                 call    _objc_msgSend
F008DA30: 9410001a                 mov     %i2, %o2
F008DA34: 30800002                 ba,a    locret_F008DA3C
F008DA38: b0102000                 mov     0, %i0
F008DA3C: 81c7e008                 ret
F008DA40: 81e80000                 restore
