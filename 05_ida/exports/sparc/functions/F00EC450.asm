F00EC450: 9de3bf98                 save    %sp, -0x68, %sp
F00EC454: 113c04bc                 sethi   %hi(__zoneRealloc), %o0
F00EC458: d602210c                 ld      [%o0+%lo(__zoneRealloc)], %o3
F00EC45C: 90100018                 mov     %i0, %o0
F00EC460: 92100019                 mov     %i1, %o1
F00EC464: 9fc2c000                 call    %o3
F00EC468: 9410001a                 mov     %i2, %o2
F00EC46C: 81c7e008                 ret
F00EC470: 91e80008                 restore %g0, %o0, %o0
