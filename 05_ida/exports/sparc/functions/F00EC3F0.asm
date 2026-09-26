F00EC3F0: 9de3bf98                 save    %sp, -0x68, %sp
F00EC3F4: 113c04bc                 sethi   %hi(__zoneCopy), %o0
F00EC3F8: d6022108                 ld      [%o0+%lo(__zoneCopy)], %o3
F00EC3FC: 90100018                 mov     %i0, %o0
F00EC400: 92100019                 mov     %i1, %o1
F00EC404: 9fc2c000                 call    %o3
F00EC408: 9410001a                 mov     %i2, %o2
F00EC40C: 81c7e008                 ret
F00EC410: 91e80008                 restore %g0, %o0, %o0
