F00274A0: 9de3bf98                 save    %sp, -0x68, %sp
F00274A4: c4062008                 ld      [%i0+8], %g2
F00274A8: 80a0a000                 cmp     %g2, 0
F00274AC: 0280000d                 be      locret_F00274E0
F00274B0: 01000000                 nop
F00274B4: c6062004                 ld      [%i0+4], %g3
F00274B8: c448c000                 ldsb    [%g3], %g2
F00274BC: 80a0a02f                 cmp     %g2, 0x2F ! '/'
F00274C0: 12800008                 bne     locret_F00274E0
F00274C4: 8600e001                 inc     %g3
F00274C8: c4062008                 ld      [%i0+8], %g2
F00274CC: c6262004                 st      %g3, [%i0+4]
F00274D0: 8400bfff                 inc     -1, %g2
F00274D4: 80a0a000                 cmp     %g2, 0
F00274D8: 12bffff7                 bne     loc_F00274B4
F00274DC: c4262008                 st      %g2, [%i0+8]
F00274E0: 81c7e008                 ret
F00274E4: 81e80000                 restore
