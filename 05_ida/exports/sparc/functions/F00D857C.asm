F00D857C: 9de3bf90                 save    %sp, -0x70, %sp
F00D8580: c6062174                 ld      [%i0+0x174], %g3
F00D8584: c448e010                 ldsb    [%g3+0x10], %g2
F00D8588: 80a0a000                 cmp     %g2, 0
F00D858C: 12800012                 bne     locret_F00D85D4
F00D8590: b010201e                 mov     0x1E, %i0
F00D8594: c448e011                 ldsb    [%g3+0x11], %g2
F00D8598: 80a0a000                 cmp     %g2, 0
F00D859C: 1280000e                 bne     locret_F00D85D4
F00D85A0: b0102021                 mov     0x21, %i0 ! '!'
F00D85A4: c448e012                 ldsb    [%g3+0x12], %g2
F00D85A8: 80a0a000                 cmp     %g2, 0
F00D85AC: 1280000a                 bne     locret_F00D85D4
F00D85B0: 01000000                 nop
F00D85B4: c448e013                 ldsb    [%g3+0x13], %g2
F00D85B8: 80a0a000                 cmp     %g2, 0
F00D85BC: 22800003                 be,a    loc_F00D85C8
F00D85C0: c448e014                 ldsb    [%g3+0x14], %g2
F00D85C4: 30800004                 ba,a    locret_F00D85D4
F00D85C8: 80a00002                 cmp     %g0, %g2
F00D85CC: b0602000                 subc    %g0, 0, %i0
F00D85D0: b00e2022                 and     %i0, 0x22, %i0
F00D85D4: 81c7e008                 ret
F00D85D8: 81e80000                 restore
