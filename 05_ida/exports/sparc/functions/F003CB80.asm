F003CB80: 9de3bf98                 save    %sp, -0x68, %sp
F003CB84: c6162004                 lduh    [%i0+4], %g3
F003CB88: 0500003f8410a3ff         set     0xFFFF, %g2
F003CB90: 80a0c002                 cmp     %g3, %g2
F003CB94: 32800004                 bne,a   loc_F003CBA4
F003CB98: c6264000                 st      %g3, [%i1]
F003CB9C: 84103fff                 mov     -1, %g2
F003CBA0: c4264000                 st      %g2, [%i1]
F003CBA4: c4562006                 ldsh    [%i0+6], %g2
F003CBA8: c4266004                 st      %g2, [%i1+4]
F003CBAC: c4562008                 ldsh    [%i0+8], %g2
F003CBB0: c4266008                 st      %g2, [%i1+8]
F003CBB4: c4062018                 ld      [%i0+0x18], %g2
F003CBB8: c426600c                 st      %g2, [%i1+0xC]
F003CBBC: c4062020                 ld      [%i0+0x20], %g2
F003CBC0: c4266010                 st      %g2, [%i1+0x10]
F003CBC4: c4062024                 ld      [%i0+0x24], %g2
F003CBC8: c4266014                 st      %g2, [%i1+0x14]
F003CBCC: c4062028                 ld      [%i0+0x28], %g2
F003CBD0: c4266018                 st      %g2, [%i1+0x18]
F003CBD4: c406202c                 ld      [%i0+0x2C], %g2
F003CBD8: c426601c                 st      %g2, [%i1+0x1C]
F003CBDC: 81c7e008                 ret
F003CBE0: 81e80000                 restore
