F00EB508: 9de3bf90                 save    %sp, -0x70, %sp
F00EB50C: 90100018                 mov     %i0, %o0! id
F00EB510: d4022008                 ld      [%o0+8], %o2
F00EB514: 80a2a000                 cmp     %o2, 0
F00EB518: 02800007                 be      loc_F00EB534
F00EB51C: 133c0506                 sethi   %hi(paRemoveobjectat), %o1
F00EB520: d2026230                 ld      [%o1+%lo(paRemoveobjectat)], %o1! SEL
F00EB524: 400018d3                 call    _objc_msgSend
F00EB528: 9402bfff                 inc     -1, %o2
F00EB52C: 10800003                 ba      locret_F00EB538
F00EB530: b0100008                 mov     %o0, %i0
F00EB534: b0102000                 mov     0, %i0
F00EB538: 81c7e008                 ret
F00EB53C: 81e80000                 restore
