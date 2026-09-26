F0037798: 9de3bf98                 save    %sp, -0x68, %sp
F003779C: c6062020                 ld      [%i0+0x20], %g3
F00377A0: 80a0e000                 cmp     %g3, 0
F00377A4: 02800004                 be      locret_F00377B4
F00377A8: 01000000                 nop
F00377AC: c410e018                 lduh    [%g3+0x18], %g2
F00377B0: c430e054                 sth     %g2, [%g3+0x54]
F00377B4: 81c7e008                 ret
F00377B8: 81e80000                 restore
