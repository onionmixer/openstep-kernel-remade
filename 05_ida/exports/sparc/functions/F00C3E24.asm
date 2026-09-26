F00C3E24: 9de3bf90                 save    %sp, -0x70, %sp
F00C3E28: 113c0504                 sethi   %hi(paItem_0), %o0! id
F00C3E2C: d202211c                 ld      [%o0+%lo(paItem_0)], %o1! SEL
F00C3E30: 4000b690                 call    _objc_msgSend
F00C3E34: 90100018                 mov     %i0, %o0
F00C3E38: d006202c                 ld      [%i0+0x2C], %o0! id
F00C3E3C: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F00C3E40: 4000b68c                 call    _objc_msgSend
F00C3E44: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F00C3E48: f027bff0                 st      %i0, [%fp+var_10]
F00C3E4C: 133c0507                 sethi   %hi(stru_F0141E1C.ext), %o1
F00C3E50: d4026248                 ld      [%o1+%lo(stru_F0141E1C.ext)], %o2
F00C3E54: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C3E58: 133c0504                 sethi   %hi(paDetachdevicein), %o1
F00C3E5C: d427bff4                 st      %o2, [%fp+var_C]
F00C3E60: d20260e0                 ld      [%o1+%lo(paDetachdevicein)], %o1! SEL
F00C3E64: 4000b6c6                 call    _objc_msgSendSuper
F00C3E68: 9410001a                 mov     %i2, %o2
F00C3E6C: d006202c                 ld      [%i0+0x2C], %o0! id
F00C3E70: 133c0504                 sethi   %hi(paRelease), %o1
F00C3E74: d202609c                 ld      [%o1+%lo(paRelease)], %o1! SEL
F00C3E78: 4000b67e                 call    _objc_msgSend
F00C3E7C: c02e2034                 clrb    [%i0+0x34]
F00C3E80: 81c7e008                 ret
F00C3E84: 81e80000                 restore
