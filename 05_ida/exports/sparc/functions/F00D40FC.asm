F00D40FC: 9de3bf90                 save    %sp, -0x70, %sp
F00D4100: 90102001                 mov     1, %o0
F00D4104: d02e21d3                 stb     %o0, [%i0+0x1D3]
F00D4108: 113c0505                 sethi   %hi(paSetbrightness_0), %o0! id
F00D410C: d20222a8                 ld      [%o0+%lo(paSetbrightness_0)], %o1! SEL
F00D4110: 400075d8                 call    _objc_msgSend
F00D4114: 90100018                 mov     %i0, %o0
F00D4118: 81c7e008                 ret
F00D411C: 81e80000                 restore
