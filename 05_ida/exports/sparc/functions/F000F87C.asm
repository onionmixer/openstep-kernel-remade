F000F87C: 9de3bf98                 save    %sp, -0x68, %sp
F000F880: 353c04cf                 sethi   %hi(_active_u), %i2
F000F884: c406a1d8                 ld      [%i2+%lo(_active_u)], %g2
F000F888: c400a01c                 ld      [%g2+0x1C], %g2
F000F88C: 8600a00a                 add     %g2, 0xA, %g3
F000F890: 8400a02a                 inc     0x2A, %g2 ! '*'
F000F894: 80a0c002                 cmp     %g3, %g2
F000F898: 1a800015                 bcc     loc_F000F8EC
F000F89C: b2100018                 mov     %i0, %i1
F000F8A0: 852e2010                 sll     %i0, 16, %g2
F000F8A4: b138a010                 sra     %g2, 16, %i0
F000F8A8: c450c000                 ldsh    [%g3], %g2
F000F8AC: 80a08018                 cmp     %g2, %i0
F000F8B0: 12800004                 bne     loc_F000F8C0
F000F8B4: 80a0bfff                 cmp     %g2, -1
F000F8B8: 1080000e                 ba      locret_F000F8F0
F000F8BC: b0102000                 mov     0, %i0
F000F8C0: 12800005                 bne     loc_F000F8D4
F000F8C4: c406a1d8                 ld      [%i2+0x1D8], %g2
F000F8C8: f230c000                 sth     %i1, [%g3]
F000F8CC: 10800009                 ba      locret_F000F8F0
F000F8D0: b0102000                 mov     0, %i0
F000F8D4: c400a01c                 ld      [%g2+0x1C], %g2
F000F8D8: 8600e002                 inc     2, %g3
F000F8DC: 8400a02a                 inc     0x2A, %g2 ! '*'
F000F8E0: 80a0c002                 cmp     %g3, %g2
F000F8E4: 2abffff2                 bcs,a   loc_F000F8AC
F000F8E8: c450c000                 ldsh    [%g3], %g2
F000F8EC: b0103fff                 mov     -1, %i0
F000F8F0: 81c7e008                 ret
F000F8F4: 81e80000                 restore
