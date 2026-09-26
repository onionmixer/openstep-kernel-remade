F00477AC: 9de3bf98                 save    %sp, -0x68, %sp
F00477B0: b4100018                 mov     %i0, %i2
F00477B4: c406a030                 ld      [%i2+0x30], %g2
F00477B8: c610a042                 lduh    [%g2+0x42], %g3
F00477BC: b128e010                 sll     %g3, 16, %i0
F00477C0: 85362018                 srl     %i0, 24, %g2
F00477C4: 8608e0ff                 and     %g3, 0xFF, %g3
F00477C8: 84008003                 add     %g2, %g3, %g2
F00477CC: 8408a00f                 and     %g2, 0xF, %g2
F00477D0: 073c04eb8610e130         set     _stable, %g3
F00477D8: 8528a002                 sll     %g2, 2, %g2
F00477DC: f2008003                 ld      [%g2+%g3], %i1
F00477E0: 80a66000                 cmp     %i1, 0
F00477E4: 22800015                 be,a    locret_F0047838
F00477E8: b0102000                 mov     0, %i0
F00477EC: b73e2010                 sra     %i0, 16, %i3
F00477F0: c4566042                 ldsh    [%i1+0x42], %g2
F00477F4: 80a0801b                 cmp     %g2, %i3
F00477F8: 3280000c                 bne,a   loc_F0047828
F00477FC: f2064000                 ld      [%i1], %i1
F0047800: b0066004                 add     %i1, 4, %i0
F0047804: 80a6001a                 cmp     %i0, %i2
F0047808: 22800008                 be,a    loc_F0047828
F004780C: f2064000                 ld      [%i1], %i1
F0047810: c606602c                 ld      [%i1+0x2C], %g3
F0047814: c406a028                 ld      [%i2+0x28], %g2
F0047818: 80a0c002                 cmp     %g3, %g2
F004781C: 02800007                 be      locret_F0047838
F0047820: 01000000                 nop
F0047824: f2064000                 ld      [%i1], %i1
F0047828: 80a66000                 cmp     %i1, 0
F004782C: 32bffff2                 bne,a   loc_F00477F4
F0047830: c4566042                 ldsh    [%i1+0x42], %g2
F0047834: b0102000                 mov     0, %i0
F0047838: 81c7e008                 ret
F004783C: 81e80000                 restore
