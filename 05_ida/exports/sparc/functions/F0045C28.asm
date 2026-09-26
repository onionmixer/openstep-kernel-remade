F0045C28: 9de3bf98                 save    %sp, -0x68, %sp
F0045C2C: f4260000                 st      %i2, [%i0]
F0045C30: 053c04388410a0b0         set     _xdrmbuf_ops, %g2
F0045C38: c4262004                 st      %g2, [%i0+4]
F0045C3C: f2262010                 st      %i1, [%i0+0x10]
F0045C40: c4066004                 ld      [%i1+4], %g2
F0045C44: 84064002                 add     %i1, %g2, %g2
F0045C48: c426200c                 st      %g2, [%i0+0xC]
F0045C4C: c0262008                 clr     [%i0+8]
F0045C50: c4566008                 ldsh    [%i1+8], %g2
F0045C54: c4262014                 st      %g2, [%i0+0x14]
F0045C58: 81c7e008                 ret
F0045C5C: 81e80000                 restore
