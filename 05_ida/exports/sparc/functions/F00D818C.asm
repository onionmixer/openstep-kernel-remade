F00D818C: 9de3bf90                 save    %sp, -0x70, %sp
F00D8190: 90100018                 mov     %i0, %o0! id
F00D8194: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D8198: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D819C: 400065b5                 call    _objc_msgSend
F00D81A0: f4222154                 st      %i2, [%o0+0x154]
F00D81A4: 133c0506                 sethi   %hi(paSend), %o1
F00D81A8: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00D81AC: 400065b1                 call    _objc_msgSend
F00D81B0: 94102001                 mov     1, %o2
F00D81B4: 81c7e008                 ret
F00D81B8: 81e80000                 restore
