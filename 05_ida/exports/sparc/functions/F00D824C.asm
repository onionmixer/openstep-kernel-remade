F00D824C: 9de3bf90                 save    %sp, -0x70, %sp
F00D8250: 90100018                 mov     %i0, %o0! id
F00D8254: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D8258: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D825C: 40006585                 call    _objc_msgSend
F00D8260: f422215c                 st      %i2, [%o0+0x15C]
F00D8264: 133c0506                 sethi   %hi(paSend), %o1
F00D8268: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00D826C: 40006581                 call    _objc_msgSend
F00D8270: 94102004                 mov     4, %o2
F00D8274: 81c7e008                 ret
F00D8278: 81e80000                 restore
