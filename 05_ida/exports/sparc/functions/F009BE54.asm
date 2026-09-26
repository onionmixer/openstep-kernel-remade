F009BE54: 9de3bf98                 save    %sp, -0x68, %sp
F009BE58: f226202c                 st      %i1, [%i0+0x2C]
F009BE5C: 80a6a000                 cmp     %i2, 0
F009BE60: 02800004                 be      loc_F009BE70
F009BE64: c6062028                 ld      [%i0+0x28], %g3
F009BE68: 8406bff8                 add     %i2, -8, %g2
F009BE6C: c420c000                 st      %g2, [%g3]
F009BE70: 0500000f8410a34b         set     0x3F4B, %g2
F009BE78: 84064002                 add     %i1, %g2, %g2
F009BE7C: 8408bff8                 and     %g2, -8, %g2
F009BE80: c420e004                 st      %g2, [%g3+4]
F009BE84: c420e2a0                 st      %g2, [%g3+0x2A0]
F009BE88: 81c7e008                 ret
F009BE8C: 81e80000                 restore
