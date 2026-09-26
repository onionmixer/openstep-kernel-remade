F00BB4D0: 9de3bfa0                 save    %sp, -0x60, %sp
F00BB4D4: 033c04fd821061f0         set     _zscurr, %g1
F00BB4DC: e0004000                 ld      [%g1], %l0
F00BB4E0: 84102002                 mov     2, %g2
F00BB4E4: e2042010                 ld      [%l0+0x10], %l1
F00BB4E8: c42c4000                 stb     %g2, [%l1]
F00BB4EC: e40c4000                 ldub    [%l1], %l2
F00BB4F0: 808ca008                 btst    8, %l2
F00BB4F4: 32800002                 bne,a   loc_F00BB4FC
F00BB4F8: a0242040                 dec     0x40, %l0 ! '@'
F00BB4FC: 033c04fd821061e0         set     _zsNcurr, %g1
F00BB504: e0204000                 st      %l0, [%g1]
F00BB508: a40ca006                 and     %l2, 6, %l2
F00BB50C: a4048012                 add     %l2, %l2, %l2
F00BB510: c2040012                 ld      [%l0+%l2], %g1
F00BB514: 9fc04000                 call    %g1
F00BB518: 90100010                 mov     %l0, %o0
F00BB51C: 033c04fd821061e0         set     _zsNcurr, %g1
F00BB524: e0004000                 ld      [%g1], %l0
F00BB528: e2042010                 ld      [%l0+0x10], %l1
F00BB52C: 84102038                 mov     0x38, %g2 ! '8'
F00BB530: c42c4000                 stb     %g2, [%l1]
F00BB534: b0002001                 add     %g0, 1, %i0
F00BB538: 81c7e008                 ret
F00BB53C: 81e80000                 restore
