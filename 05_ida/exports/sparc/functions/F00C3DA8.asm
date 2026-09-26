F00C3DA8: 9de3bf90                 save    %sp, -0x70, %sp
F00C3DAC: 113c0504                 sethi   %hi(paItem_0), %o0! id
F00C3DB0: d202211c                 ld      [%o0+%lo(paItem_0)], %o1! SEL
F00C3DB4: 4000b6af                 call    _objc_msgSend
F00C3DB8: 90100018                 mov     %i0, %o0
F00C3DBC: 80a6a000                 cmp     %i2, 0
F00C3DC0: 02800016                 be      loc_F00C3E18
F00C3DC4: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F00C3DC8: d006202c                 ld      [%i0+0x2C], %o0! id
F00C3DCC: 4000b6a9                 call    _objc_msgSend
F00C3DD0: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F00C3DD4: f6262030                 st      %i3, [%i0+0x30]
F00C3DD8: f027bff0                 st      %i0, [%fp+var_10]
F00C3DDC: 133c0507                 sethi   %hi(stru_F0141E1C.ext), %o1
F00C3DE0: d4026248                 ld      [%o1+%lo(stru_F0141E1C.ext)], %o2
F00C3DE4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C3DE8: 133c0504                 sethi   %hi(paAttachdevicein_0), %o1
F00C3DEC: d427bff4                 st      %o2, [%fp+var_C]
F00C3DF0: d20260a8                 ld      [%o1+%lo(paAttachdevicein_0)], %o1! SEL
F00C3DF4: 4000b6e2                 call    _objc_msgSendSuper
F00C3DF8: 9410001a                 mov     %i2, %o2
F00C3DFC: 133c0504                 sethi   %hi(paRelease), %o1
F00C3E00: d006202c                 ld      [%i0+0x2C], %o0! id
F00C3E04: 94102001                 mov     1, %o2
F00C3E08: d202609c                 ld      [%o1+%lo(paRelease)], %o1! SEL
F00C3E0C: 4000b699                 call    _objc_msgSend
F00C3E10: d42e2034                 stb     %o2, [%i0+0x34]
F00C3E14: 30800002                 ba,a    locret_F00C3E1C
F00C3E18: b0102000                 mov     0, %i0
F00C3E1C: 81c7e008                 ret
F00C3E20: 81e80000                 restore
