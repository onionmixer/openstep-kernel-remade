F00CA72C: 9de3bf98                 save    %sp, -0x68, %sp
F00CA730: 7ffd85ad                 call    _if_private
F00CA734: 90100018                 mov     %i0, %o0! id
F00CA738: 80a22000                 cmp     %o0, 0
F00CA73C: 02800008                 be      loc_F00CA75C
F00CA740: 133c0506                 sethi   %hi(paPerformcommand), %o1
F00CA744: d202607c                 ld      [%o1+%lo(paPerformcommand)], %o1! SEL
F00CA748: 94100019                 mov     %i1, %o2
F00CA74C: 40009c49                 call    _objc_msgSend
F00CA750: 9610001a                 mov     %i2, %o3
F00CA754: 10800003                 ba      locret_F00CA760
F00CA758: b0100008                 mov     %o0, %i0
F00CA75C: b0103fff                 mov     -1, %i0
F00CA760: 81c7e008                 ret
F00CA764: 81e80000                 restore
