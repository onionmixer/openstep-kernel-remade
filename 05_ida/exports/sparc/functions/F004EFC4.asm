F004EFC4: 9de3bf98                 save    %sp, -0x68, %sp
F004EFC8: 86100018                 mov     %i0, %g3
F004EFCC: 053c04d4                 sethi   %hi(_inode_list), %g2
F004EFD0: f200a140                 ld      [%g2+%lo(_inode_list)], %i1
F004EFD4: 80a66000                 cmp     %i1, 0
F004EFD8: 0280002a                 be      locret_F004F080
F004EFDC: b0102000                 mov     0, %i0
F004EFE0: 8528e010                 sll     %g3, 16, %g2
F004EFE4: b538a010                 sra     %g2, 16, %i2
F004EFE8: 3900003c                 sethi   0xF000, %i4
F004EFEC: 37000018                 sethi   0x6000, %i3
F004EFF0: c4566046                 ldsh    [%i1+0x46], %g2
F004EFF4: 80a0801a                 cmp     %g2, %i2
F004EFF8: 1280000f                 bne     loc_F004F034
F004EFFC: c4166044                 lduh    [%i1+0x44], %g2
F004F000: 8088a100                 btst    0x100, %g2
F004F004: 22800004                 be,a    loc_F004F014
F004F008: c6064000                 ld      [%i1], %g3
F004F00C: 10800019                 ba      loc_F004F070
F004F010: b0103fff                 mov     -1, %i0
F004F014: c4066004                 ld      [%i1+4], %g2
F004F018: c420e004                 st      %g2, [%g3+4]
F004F01C: c6066004                 ld      [%i1+4], %g3
F004F020: c4064000                 ld      [%i1], %g2
F004F024: c420c000                 st      %g2, [%g3]
F004F028: f2264000                 st      %i1, [%i1]
F004F02C: 10800011                 ba      loc_F004F070
F004F030: f2266004                 st      %i1, [%i1+4]
F004F034: 8088a100                 btst    0x100, %g2
F004F038: 2280000f                 be,a    loc_F004F074
F004F03C: f2066008                 ld      [%i1+8], %i1
F004F040: c4166064                 lduh    [%i1+0x64], %g2
F004F044: 8408801c                 and     %g2, %i4, %g2
F004F048: 80a0801b                 cmp     %g2, %i3
F004F04C: 3280000a                 bne,a   loc_F004F074
F004F050: f2066008                 ld      [%i1+8], %i1
F004F054: c406608c                 ld      [%i1+0x8C], %g2
F004F058: 80a0801a                 cmp     %g2, %i2
F004F05C: 32800006                 bne,a   loc_F004F074
F004F060: f2066008                 ld      [%i1+8], %i1
F004F064: 80a62000                 cmp     %i0, 0
F004F068: 36800002                 bge,a   loc_F004F070
F004F06C: b0062001                 inc     %i0
F004F070: f2066008                 ld      [%i1+8], %i1
F004F074: 80a66000                 cmp     %i1, 0
F004F078: 32bfffdf                 bne,a   loc_F004EFF4
F004F07C: c4566046                 ldsh    [%i1+0x46], %g2
F004F080: 81c7e008                 ret
F004F084: 81e80000                 restore
