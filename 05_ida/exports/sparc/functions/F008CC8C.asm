F008CC8C: 9de3bf90                 save    %sp, -0x70, %sp
F008CC90: f4062008                 ld      [%i0+8], %i2
F008CC94: 86102000                 mov     0, %g3
F008CC98: 80a0c01a                 cmp     %g3, %i2
F008CC9C: 1a80000b                 bcc     loc_F008CCC8
F008CCA0: f6062018                 ld      [%i0+0x18], %i3
F008CCA4: b2102000                 mov     0, %i1
F008CCA8: c406401b                 ld      [%i1+%i3], %g2
F008CCAC: 80a0a000                 cmp     %g2, 0
F008CCB0: 22800007                 be,a    locret_F008CCCC
F008CCB4: f006200c                 ld      [%i0+0xC], %i0
F008CCB8: 8600e001                 inc     %g3
F008CCBC: 80a0c01a                 cmp     %g3, %i2
F008CCC0: 0abffffa                 bcs     loc_F008CCA8
F008CCC4: b2066004                 inc     4, %i1
F008CCC8: f006200c                 ld      [%i0+0xC], %i0
F008CCCC: 81c7e008                 ret
F008CCD0: 91e8c018                 restore %g3, %i0, %o0
