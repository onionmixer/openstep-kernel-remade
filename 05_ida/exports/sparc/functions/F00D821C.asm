F00D821C: 9de3bf90                 save    %sp, -0x70, %sp
F00D8220: 90100018                 mov     %i0, %o0! id
F00D8224: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D8228: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D822C: 40006591                 call    _objc_msgSend
F00D8230: f4222158                 st      %i2, [%o0+0x158]
F00D8234: 133c0506                 sethi   %hi(paSend), %o1
F00D8238: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00D823C: 4000658d                 call    _objc_msgSend
F00D8240: 94102003                 mov     3, %o2
F00D8244: 81c7e008                 ret
F00D8248: 81e80000                 restore
