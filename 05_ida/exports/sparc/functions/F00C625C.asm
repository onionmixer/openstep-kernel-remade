F00C625C: 9de3bf98                 save    %sp, -0x68, %sp
F00C6260: 80a62000                 cmp     %i0, 0
F00C6264: 02800011                 be      locret_F00C62A8
F00C6268: 80a66000                 cmp     %i1, 0
F00C626C: 0280000f                 be      locret_F00C62A8
F00C6270: 80a60019                 cmp     %i0, %i1
F00C6274: 0280000d                 be      locret_F00C62A8
F00C6278: 80a6a000                 cmp     %i2, 0
F00C627C: 0280000b                 be      locret_F00C62A8
F00C6280: 86102000                 mov     0, %g3
F00C6284: 80a0c01a                 cmp     %g3, %i2
F00C6288: 1a800008                 bcc     locret_F00C62A8
F00C628C: 01000000                 nop
F00C6290: c40e0003                 ldub    [%i0+%g3], %g2
F00C6294: c42e4003                 stb     %g2, [%i1+%g3]
F00C6298: 8600e001                 inc     %g3
F00C629C: 80a0c01a                 cmp     %g3, %i2
F00C62A0: 2abffffd                 bcs,a   loc_F00C6294
F00C62A4: c40e0003                 ldub    [%i0+%g3], %g2
F00C62A8: 81c7e008                 ret
F00C62AC: 81e80000                 restore
