F0039BC8: 9de3bf98                 save    %sp, -0x68, %sp
F0039BCC: c4060000                 ld      [%i0], %g2
F0039BD0: c4264000                 st      %g2, [%i1]
F0039BD4: 0500003f                 sethi   0xFC00, %g2
F0039BD8: c6162004                 lduh    [%i0+4], %g3
F0039BDC: 8410a3ff                 bset    0x3FF, %g2
F0039BE0: 80a0c002                 cmp     %g3, %g2
F0039BE4: 32800004                 bne,a   loc_F0039BF4
F0039BE8: c6266004                 st      %g3, [%i1+4]
F0039BEC: 84103fff                 mov     -1, %g2
F0039BF0: c4266004                 st      %g2, [%i1+4]
F0039BF4: c4562006                 ldsh    [%i0+6], %g2
F0039BF8: c426600c                 st      %g2, [%i1+0xC]
F0039BFC: c4562008                 ldsh    [%i0+8], %g2
F0039C00: c4266010                 st      %g2, [%i1+0x10]
F0039C04: c406200c                 ld      [%i0+0xC], %g2
F0039C08: c4266024                 st      %g2, [%i1+0x24]
F0039C0C: c4062010                 ld      [%i0+0x10], %g2
F0039C10: c4266028                 st      %g2, [%i1+0x28]
F0039C14: c4562014                 ldsh    [%i0+0x14], %g2
F0039C18: c4266008                 st      %g2, [%i1+8]
F0039C1C: c4062018                 ld      [%i0+0x18], %g2
F0039C20: c4266014                 st      %g2, [%i1+0x14]
F0039C24: c4062020                 ld      [%i0+0x20], %g2
F0039C28: c426602c                 st      %g2, [%i1+0x2C]
F0039C2C: c4062024                 ld      [%i0+0x24], %g2
F0039C30: c4266030                 st      %g2, [%i1+0x30]
F0039C34: c4062028                 ld      [%i0+0x28], %g2
F0039C38: c4266034                 st      %g2, [%i1+0x34]
F0039C3C: c406202c                 ld      [%i0+0x2C], %g2
F0039C40: c4266038                 st      %g2, [%i1+0x38]
F0039C44: c4062030                 ld      [%i0+0x30], %g2
F0039C48: c426603c                 st      %g2, [%i1+0x3C]
F0039C4C: c4062034                 ld      [%i0+0x34], %g2
F0039C50: c4266040                 st      %g2, [%i1+0x40]
F0039C54: c4562038                 ldsh    [%i0+0x38], %g2
F0039C58: c426601c                 st      %g2, [%i1+0x1C]
F0039C5C: c406203c                 ld      [%i0+0x3C], %g2
F0039C60: c4266020                 st      %g2, [%i1+0x20]
F0039C64: c406201c                 ld      [%i0+0x1C], %g2
F0039C68: c4266018                 st      %g2, [%i1+0x18]
F0039C6C: c4060000                 ld      [%i0], %g2
F0039C70: 80a0a008                 cmp     %g2, 8
F0039C74: 1280000b                 bne     locret_F0039CA0
F0039C78: 84102004                 mov     4, %g2
F0039C7C: c4264000                 st      %g2, [%i1]
F0039C80: 84103fff                 mov     -1, %g2
F0039C84: c426601c                 st      %g2, [%i1+0x1C]
F0039C88: c6066004                 ld      [%i1+4], %g3
F0039C8C: 0500003c                 sethi   0xF000, %g2
F0039C90: 8428c002                 andn    %g3, %g2, %g2
F0039C94: 07000008                 sethi   0x2000, %g3
F0039C98: 84108003                 bset    %g3, %g2
F0039C9C: c4266004                 st      %g2, [%i1+4]
F0039CA0: 81c7e008                 ret
F0039CA4: 81e80000                 restore
