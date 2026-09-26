F004CD8C: 9de3bf98                 save    %sp, -0x68, %sp
F004CD90: 113c043a90122358         set     aSBadDirInoDAtO, %o0! "%s: bad dir ino %d at offset %d: %s\n"
F004CD98: 9610001a                 mov     %i2, %o3
F004CD9C: d2062050                 ld      [%i0+0x50], %o1
F004CDA0: 98100019                 mov     %i1, %o4
F004CDA4: d4062048                 ld      [%i0+0x48], %o2
F004CDA8: 7fff1e2c                 call    _printf
F004CDAC: 920260d4                 inc     0xD4, %o1
F004CDB0: 81c7e008                 ret
F004CDB4: 81e80000                 restore
