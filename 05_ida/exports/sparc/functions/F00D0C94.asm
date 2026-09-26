F00D0C94: 9de3bf90                 save    %sp, -0x70, %sp
F00D0C98: 113c0504                 sethi   %hi(paDevicedescript_1), %o0! id
F00D0C9C: d2022158                 ld      [%o0+%lo(paDevicedescript_1)], %o1! SEL
F00D0CA0: 400082f4                 call    _objc_msgSend
F00D0CA4: 90100018                 mov     %i0, %o0! id
F00D0CA8: 133c0505                 sethi   %hi(paDeviceport_0), %o1! SEL
F00D0CAC: 400082f1                 call    _objc_msgSend
F00D0CB0: d202635c                 ld      [%o1+%lo(paDeviceport_0)], %o1
F00D0CB4: 81c7e008                 ret
F00D0CB8: 91e80008                 restore %g0, %o0, %o0
