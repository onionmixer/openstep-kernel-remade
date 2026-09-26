F00D815C: 9de3bf90                 save    %sp, -0x70, %sp
F00D8160: 90100018                 mov     %i0, %o0! id
F00D8164: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D8168: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D816C: 400065c1                 call    _objc_msgSend
F00D8170: f4222150                 st      %i2, [%o0+0x150]
F00D8174: 133c0506                 sethi   %hi(paSend), %o1
F00D8178: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00D817C: 400065bd                 call    _objc_msgSend
F00D8180: 94102000                 mov     0, %o2
F00D8184: 81c7e008                 ret
F00D8188: 81e80000                 restore
