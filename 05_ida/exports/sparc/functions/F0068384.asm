F0068384: 9de3bf98                 save    %sp, -0x68, %sp
F0068388: c0262008                 clr     [%i0+8]
F006838C: 053c04bd                 sethi   %hi(dword_F012F674), %g2
F0068390: c600a274                 ld      [%g2+%lo(dword_F012F674)], %g3
F0068394: b210a274                 or      %g2, %lo(dword_F012F674), %i1
F0068398: 84067ffc                 add     %i1, -4, %g2
F006839C: 80a0c002                 cmp     %g3, %g2
F00683A0: 32800003                 bne,a   loc_F00683AC
F00683A4: f020c000                 st      %i0, [%g3]
F00683A8: f0267ffc                 st      %i0, [%i1-4]
F00683AC: c6262004                 st      %g3, [%i0+4]
F00683B0: 053c04bd8410a270         set     dword_F012F670, %g2
F00683B8: c4260000                 st      %g2, [%i0]
F00683BC: f020a004                 st      %i0, [%g2+4]
F00683C0: 333c043e                 sethi   %hi(dword_F010FB00), %i1
F00683C4: 073c04f0                 sethi   %hi(_stackStats), %g3
F00683C8: f0066300                 ld      [%i1+%lo(dword_F010FB00)], %i0
F00683CC: 8610e0c0                 bset    %lo(_stackStats), %g3
F00683D0: c400e008                 ld      [%g3+8], %g2
F00683D4: b0062001                 inc     %i0
F00683D8: f0266300                 st      %i0, [%i1+%lo(dword_F010FB00)]
F00683DC: 8400a001                 inc     %g2
F00683E0: c420e008                 st      %g2, [%g3+8]
F00683E4: 81c7e008                 ret
F00683E8: 81e80000                 restore
