F00D81BC: 9de3bf90                 save    %sp, -0x70, %sp
F00D81C0: 90100018                 mov     %i0, %o0! id
F00D81C4: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D81C8: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D81CC: 400065a9                 call    _objc_msgSend
F00D81D0: f42a216b                 stb     %i2, [%o0+0x16B]
F00D81D4: 133c0506                 sethi   %hi(paSend), %o1
F00D81D8: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00D81DC: 400065a5                 call    _objc_msgSend
F00D81E0: 94102002                 mov     2, %o2
F00D81E4: 81c7e008                 ret
F00D81E8: 81e80000                 restore
