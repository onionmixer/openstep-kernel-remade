F00476A8: 9de3bf98                 save    %sp, -0x68, %sp
F00476AC: b72e2010                 sll     %i0, 16, %i3
F00476B0: 8536e018                 srl     %i3, 24, %g2
F00476B4: b00e20ff                 and     %i0, 0xFF, %i0
F00476B8: 84008018                 add     %g2, %i0, %g2
F00476BC: 8408a00f                 and     %g2, 0xF, %g2
F00476C0: 073c04eb8610e130         set     _stable, %g3
F00476C8: 8528a002                 sll     %g2, 2, %g2
F00476CC: c6008003                 ld      [%g2+%g3], %g3
F00476D0: 80a0e000                 cmp     %g3, 0
F00476D4: 02800011                 be      loc_F0047718
F00476D8: b4102000                 mov     0, %i2
F00476DC: b13ee010                 sra     %i3, 16, %i0
F00476E0: c450e042                 ldsh    [%g3+0x42], %g2
F00476E4: 80a08018                 cmp     %g2, %i0
F00476E8: 32800009                 bne,a   loc_F004770C
F00476EC: c600c000                 ld      [%g3], %g3
F00476F0: c400e02c                 ld      [%g3+0x2C], %g2
F00476F4: 80a08019                 cmp     %g2, %i1
F00476F8: 32800005                 bne,a   loc_F004770C
F00476FC: c600c000                 ld      [%g3], %g3
F0047700: c400e064                 ld      [%g3+0x64], %g2
F0047704: b4068002                 add     %i2, %g2, %i2
F0047708: c600c000                 ld      [%g3], %g3
F004770C: 80a0e000                 cmp     %g3, 0
F0047710: 32bffff5                 bne,a   loc_F00476E4
F0047714: c450e042                 ldsh    [%g3+0x42], %g2
F0047718: 80a0001a                 cmp     %g0, %i2
F004771C: b0402000                 addc    %g0, 0, %i0
F0047720: 81c7e008                 ret
F0047724: 81e80000                 restore
