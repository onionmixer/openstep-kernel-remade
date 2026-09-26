F0047840: 9de3bf98                 save    %sp, -0x68, %sp
F0047844: b52e6010                 sll     %i1, 16, %i2
F0047848: 8536a018                 srl     %i2, 24, %g2
F004784C: b20e60ff                 and     %i1, 0xFF, %i1
F0047850: 84008019                 add     %g2, %i1, %g2
F0047854: 8408a00f                 and     %g2, 0xF, %g2
F0047858: 073c04eb8610e130         set     _stable, %g3
F0047860: 8528a002                 sll     %g2, 2, %g2
F0047864: c6008003                 ld      [%g2+%g3], %g3
F0047868: 80a0e000                 cmp     %g3, 0
F004786C: 02800013                 be      loc_F00478B8
F0047870: b6100018                 mov     %i0, %i3
F0047874: b33ea010                 sra     %i2, 16, %i1
F0047878: c450e042                 ldsh    [%g3+0x42], %g2
F004787C: 80a08019                 cmp     %g2, %i1
F0047880: 3280000b                 bne,a   loc_F00478AC
F0047884: c600c000                 ld      [%g3], %g3
F0047888: c400e02c                 ld      [%g3+0x2C], %g2
F004788C: 80a0801b                 cmp     %g2, %i3
F0047890: 12800006                 bne     loc_F00478A8
F0047894: b000e004                 add     %g3, 4, %i0
F0047898: c410e00a                 lduh    [%g3+0xA], %g2
F004789C: 8400a001                 inc     %g2
F00478A0: 10800007                 ba      locret_F00478BC
F00478A4: c430e00a                 sth     %g2, [%g3+0xA]
F00478A8: c600c000                 ld      [%g3], %g3
F00478AC: 80a0e000                 cmp     %g3, 0
F00478B0: 32bffff3                 bne,a   loc_F004787C
F00478B4: c450e042                 ldsh    [%g3+0x42], %g2
F00478B8: b0102000                 mov     0, %i0
F00478BC: 81c7e008                 ret
F00478C0: 81e80000                 restore
