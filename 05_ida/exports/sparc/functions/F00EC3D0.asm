F00EC3D0: 9de3bf98                 save    %sp, -0x68, %sp
F00EC3D4: 113c04bc                 sethi   %hi(__copy), %o0
F00EC3D8: d40220ec                 ld      [%o0+%lo(__copy)], %o2
F00EC3DC: 90100018                 mov     %i0, %o0
F00EC3E0: 9fc28000                 call    %o2
F00EC3E4: 92100019                 mov     %i1, %o1
F00EC3E8: 81c7e008                 ret
F00EC3EC: 91e80008                 restore %g0, %o0, %o0
