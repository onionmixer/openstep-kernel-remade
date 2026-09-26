F00D3EFC: 9de3bf90                 save    %sp, -0x70, %sp
F00D3F00: 90102001                 mov     1, %o0
F00D3F04: 80a6a003                 cmp     %i2, 3
F00D3F08: 14800003                 bg      loc_F00D3F14
F00D3F0C: d2062168                 ld      [%i0+0x168], %o1
F00D3F10: 9010001a                 mov     %i2, %o0
F00D3F14: d022601c                 st      %o0, [%o1+0x1C]
F00D3F18: 113c0505                 sethi   %hi(paMovecursor), %o0! id
F00D3F1C: d202229c                 ld      [%o0+%lo(paMovecursor)], %o1! SEL
F00D3F20: 40007654                 call    _objc_msgSend
F00D3F24: 90100018                 mov     %i0, %o0
F00D3F28: 81c7e008                 ret
F00D3F2C: 81e80000                 restore
