F00EBA30: 9de3bf90                 save    %sp, -0x70, %sp
F00EBA34: 113c04bc                 sethi   %hi(__zoneCopy), %o0
F00EBA38: d6022108                 ld      [%o0+%lo(__zoneCopy)], %o3
F00EBA3C: 90100018                 mov     %i0, %o0
F00EBA40: 92102000                 mov     0, %o1
F00EBA44: 9fc2c000                 call    %o3
F00EBA48: 9410001a                 mov     %i2, %o2
F00EBA4C: 81c7e008                 ret
F00EBA50: 91e80008                 restore %g0, %o0, %o0
