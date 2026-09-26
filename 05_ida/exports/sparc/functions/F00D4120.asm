F00D4120: 9de3bf90                 save    %sp, -0x70, %sp
F00D4124: 113c0505                 sethi   %hi(paSetbrightness_0), %o0! id
F00D4128: d20222a8                 ld      [%o0+%lo(paSetbrightness_0)], %o1! SEL
F00D412C: c02e21d3                 clrb    [%i0+0x1D3]
F00D4130: 400075d0                 call    _objc_msgSend
F00D4134: 90100018                 mov     %i0, %o0
F00D4138: 81c7e008                 ret
F00D413C: 81e80000                 restore
