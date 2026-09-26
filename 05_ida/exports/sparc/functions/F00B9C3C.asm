F00B9C3C: 9de3bf98                 save    %sp, -0x68, %sp
F00B9C40: b00e201f                 and     %i0, 0x1F, %i0
F00B9C44: 932e2004                 sll     %i0, 4, %o1
F00B9C48: 92024018                 add     %o1, %i0, %o1
F00B9C4C: 932a6003                 sll     %o1, 3, %o1
F00B9C50: 113c04fb90122260         set     _zs_tty, %o0
F00B9C58: 90024008                 add     %o1, %o0, %o0
F00B9C5C: 7ffd7795                 call    _ttselect
F00B9C60: 92100019                 mov     %i1, %o1
F00B9C64: 81c7e008                 ret
F00B9C68: 91e80008                 restore %g0, %o0, %o0
