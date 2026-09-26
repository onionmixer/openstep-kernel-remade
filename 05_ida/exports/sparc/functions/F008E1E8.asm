F008E1E8: 9de3bf90                 save    %sp, -0x70, %sp
F008E1EC: 90100018                 mov     %i0, %o0! id
F008E1F0: 133c0504                 sethi   %hi(paAttachdevicein_0), %o1
F008E1F4: d20260a8                 ld      [%o1+%lo(paAttachdevicein_0)], %o1! SEL
F008E1F8: 40018d9e                 call    _objc_msgSend
F008E1FC: 9410001a                 mov     %i2, %o2
F008E200: 81c7e008                 ret
F008E204: 91e80008                 restore %g0, %o0, %o0
