F008F194: 9de3bf90                 save    %sp, -0x70, %sp
F008F198: a0100018                 mov     %i0, %l0
F008F19C: d0042010                 ld      [%l0+0x10], %o0! id
F008F1A0: 133c0504                 sethi   %hi(paValueforkey), %o1
F008F1A4: d202606c                 ld      [%o1+%lo(paValueforkey)], %o1! SEL
F008F1A8: 400189b2                 call    _objc_msgSend
F008F1AC: 9410001a                 mov     %i2, %o2
F008F1B0: b0920000                 orcc    %o0, %g0, %i0
F008F1B4: 1280000e                 bne     locret_F008F1EC
F008F1B8: 133c0504                 sethi   %hi(paValueforstring), %o1
F008F1BC: d0042004                 ld      [%l0+4], %o0! id
F008F1C0: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F008F1C4: 400189ab                 call    _objc_msgSend
F008F1C8: 9410001a                 mov     %i2, %o2
F008F1CC: b0920000                 orcc    %o0, %g0, %i0
F008F1D0: 02800007                 be      locret_F008F1EC
F008F1D4: 9410001a                 mov     %i2, %o2
F008F1D8: d0042010                 ld      [%l0+0x10], %o0! id
F008F1DC: 133c0504                 sethi   %hi(paInsertkeyValue), %o1
F008F1E0: d2026068                 ld      [%o1+%lo(paInsertkeyValue)], %o1! SEL
F008F1E4: 400189a3                 call    _objc_msgSend
F008F1E8: 96100018                 mov     %i0, %o3
F008F1EC: 81c7e008                 ret
F008F1F0: 81e80000                 restore
