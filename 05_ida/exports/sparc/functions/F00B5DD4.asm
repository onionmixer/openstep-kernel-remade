F00B5DD4: 9de3bf98                 save    %sp, -0x68, %sp
F00B5DD8: c606209c                 ld      [%i0+0x9C], %g3
F00B5DDC: b2102001                 mov     1, %i1
F00B5DE0: f228e00c                 stb     %i1, [%g3+0xC]
F00B5DE4: c40e2031                 ldub    [%i0+0x31], %g2
F00B5DE8: 80a0a000                 cmp     %g2, 0
F00B5DEC: 22800002                 be,a    loc_F00B5DF4
F00B5DF0: c028e00c                 clrb    [%g3+0xC]
F00B5DF4: 84102010                 mov     0x10, %g2
F00B5DF8: c428e00c                 stb     %g2, [%g3+0xC]
F00B5DFC: f22e205c                 stb     %i1, [%i0+0x5C]
F00B5E00: c40e2041                 ldub    [%i0+0x41], %g2
F00B5E04: c02e205d                 clrb    [%i0+0x5D]
F00B5E08: c42e2042                 stb     %g2, [%i0+0x42]
F00B5E0C: 84102007                 mov     7, %g2
F00B5E10: c42e2041                 stb     %g2, [%i0+0x41]
F00B5E14: 81c7e008                 ret
F00B5E18: 91e83fff                 restore %g0, -1, %o0
