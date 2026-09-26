F000885C: 9de3bf98                 save    %sp, -0x68, %sp
F0008860: 053c04cf                 sethi   %hi(dword_F0133DDC), %g2
F0008864: c400a1dc                 ld      [%g2+%lo(dword_F0133DDC)], %g2
F0008868: f000a024                 ld      [%g2+0x24], %i0
F000886C: c4060000                 ld      [%i0], %g2
F0008870: 80a0a01c                 cmp     %g2, 0x1C
F0008874: 12800020                 bne     loc_F00088F4
F0008878: 053c04cf                 sethi   -0xFECC400, %g2
F000887C: c6062004                 ld      [%i0+4], %g3
F0008880: 051fffff8410a3ff         set     0x7FFFFFFF, %g2
F0008888: 80a0c002                 cmp     %g3, %g2
F000888C: 1280001a                 bne     loc_F00088F4
F0008890: 053c04cf                 sethi   -0xFECC400, %g2
F0008894: b4102008                 mov     8, %i2
F0008898: 053c04cf                 sethi   %hi(_active_u), %g2
F000889C: f200a1d8                 ld      [%g2+%lo(_active_u)], %i1
F00088A0: c4062008                 ld      [%i0+8], %g2
F00088A4: c60e625c                 ldub    [%i1+0x25C], %g3
F00088A8: 80a0a001                 cmp     %g2, 1
F00088AC: 0280000f                 be      loc_F00088E8
F00088B0: b008c01a                 and     %g3, %i2, %i0
F00088B4: 80a0a001                 cmp     %g2, 1
F00088B8: 14800007                 bg      loc_F00088D4
F00088BC: 80a0a002                 cmp     %g2, 2
F00088C0: 80a0a000                 cmp     %g2, 0
F00088C4: 02800011                 be      loc_F0008908
F00088C8: 053c04cf                 sethi   %hi(dword_F0133DDC), %g2
F00088CC: 1080000b                 ba      loc_F00088F8
F00088D0: c600a1dc                 ld      [%g2+%lo(dword_F0133DDC)], %g3
F00088D4: 12800008                 bne     loc_F00088F4
F00088D8: 053c04cf                 sethi   -0xFECC400, %g2
F00088DC: 8410c01a                 or      %g3, %i2, %g2
F00088E0: 10800009                 ba      loc_F0008904
F00088E4: c42e625c                 stb     %g2, [%i1+0x25C]
F00088E8: 8428c01a                 andn    %g3, %i2, %g2
F00088EC: 10800006                 ba      loc_F0008904
F00088F0: c42e625c                 stb     %g2, [%i1+0x25C]
F00088F4: c600a1dc                 ld      [%g2+0x1DC], %g3
F00088F8: 84102016                 mov     0x16, %g2
F00088FC: 1080000b                 ba      locret_F0008928
F0008900: c428e038                 stb     %g2, [%g3+0x38]
F0008904: 053c04cf                 sethi   -0xFECC400, %g2
F0008908: 80a62000                 cmp     %i0, 0
F000890C: 02800006                 be      loc_F0008924
F0008910: c600a1dc                 ld      [%g2+0x1DC], %g3
F0008914: 051fffff8410a3ff         set     0x7FFFFFFF, %g2
F000891C: 10800003                 ba      locret_F0008928
F0008920: c420e030                 st      %g2, [%g3+0x30]
F0008924: c020e030                 clr     [%g3+0x30]
F0008928: 81c7e008                 ret
F000892C: 81e80000                 restore
