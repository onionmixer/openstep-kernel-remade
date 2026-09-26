F0047728: 9de3bf98                 save    %sp, -0x68, %sp
F004772C: b52e2010                 sll     %i0, 16, %i2
F0047730: 8536a018                 srl     %i2, 24, %g2
F0047734: b00e20ff                 and     %i0, 0xFF, %i0
F0047738: 84008018                 add     %g2, %i0, %g2
F004773C: 8408a00f                 and     %g2, 0xF, %g2
F0047740: 073c04eb8610e130         set     _stable, %g3
F0047748: 8528a002                 sll     %g2, 2, %g2
F004774C: c6008003                 ld      [%g2+%g3], %g3
F0047750: 80a0e000                 cmp     %g3, 0
F0047754: 02800013                 be      loc_F00477A0
F0047758: b13ea010                 sra     %i2, 16, %i0
F004775C: c450e042                 ldsh    [%g3+0x42], %g2
F0047760: 80a08018                 cmp     %g2, %i0
F0047764: 3280000c                 bne,a   loc_F0047794
F0047768: c600c000                 ld      [%g3], %g3
F004776C: c400e02c                 ld      [%g3+0x2C], %g2
F0047770: 80a08019                 cmp     %g2, %i1
F0047774: 32800008                 bne,a   loc_F0047794
F0047778: c600c000                 ld      [%g3], %g3
F004777C: c410e040                 lduh    [%g3+0x40], %g2
F0047780: 8088a008                 btst    8, %g2
F0047784: 22800004                 be,a    loc_F0047794
F0047788: c600c000                 ld      [%g3], %g3
F004778C: 10800006                 ba      locret_F00477A4
F0047790: b0102001                 mov     1, %i0
F0047794: 80a0e000                 cmp     %g3, 0
F0047798: 32bffff2                 bne,a   loc_F0047760
F004779C: c450e042                 ldsh    [%g3+0x42], %g2
F00477A0: b0102000                 mov     0, %i0
F00477A4: 81c7e008                 ret
F00477A8: 81e80000                 restore
