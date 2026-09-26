F00D81EC: 9de3bf90                 save    %sp, -0x70, %sp
F00D81F0: 90100018                 mov     %i0, %o0! id
F00D81F4: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D81F8: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D81FC: 4000659d                 call    _objc_msgSend
F00D8200: f42a216c                 stb     %i2, [%o0+0x16C]
F00D8204: 133c0506                 sethi   %hi(paSend), %o1
F00D8208: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00D820C: 40006599                 call    _objc_msgSend
F00D8210: 94102005                 mov     5, %o2
F00D8214: 81c7e008                 ret
F00D8218: 81e80000                 restore
