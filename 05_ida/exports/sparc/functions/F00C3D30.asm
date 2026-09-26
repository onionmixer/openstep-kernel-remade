F00C3D30: 9de3bf90                 save    %sp, -0x70, %sp
F00C3D34: 113c0504                 sethi   %hi(paItem_0), %o0! id
F00C3D38: d202211c                 ld      [%o0+%lo(paItem_0)], %o1! SEL
F00C3D3C: 4000b6cd                 call    _objc_msgSend
F00C3D40: 90100018                 mov     %i0, %o0
F00C3D44: 80a6a000                 cmp     %i2, 0
F00C3D48: 02800015                 be      loc_F00C3D9C
F00C3D4C: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F00C3D50: d006202c                 ld      [%i0+0x2C], %o0! id
F00C3D54: 4000b6c7                 call    _objc_msgSend
F00C3D58: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F00C3D5C: f027bff0                 st      %i0, [%fp+var_10]
F00C3D60: 133c0507                 sethi   %hi(stru_F0141E1C.ext), %o1
F00C3D64: d4026248                 ld      [%o1+%lo(stru_F0141E1C.ext)], %o2
F00C3D68: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C3D6C: 133c0504                 sethi   %hi(paAttachdevicein_0), %o1
F00C3D70: d427bff4                 st      %o2, [%fp+var_C]
F00C3D74: d20260a8                 ld      [%o1+%lo(paAttachdevicein_0)], %o1! SEL
F00C3D78: 4000b701                 call    _objc_msgSendSuper
F00C3D7C: 9410001a                 mov     %i2, %o2
F00C3D80: 133c0504                 sethi   %hi(paRelease), %o1
F00C3D84: d006202c                 ld      [%i0+0x2C], %o0! id
F00C3D88: 94102001                 mov     1, %o2
F00C3D8C: d202609c                 ld      [%o1+%lo(paRelease)], %o1! SEL
F00C3D90: 4000b6b8                 call    _objc_msgSend
F00C3D94: d42e2034                 stb     %o2, [%i0+0x34]
F00C3D98: 30800002                 ba,a    locret_F00C3DA0
F00C3D9C: b0102000                 mov     0, %i0
F00C3DA0: 81c7e008                 ret
F00C3DA4: 81e80000                 restore
