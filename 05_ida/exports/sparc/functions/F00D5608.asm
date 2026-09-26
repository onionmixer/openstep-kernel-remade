F00D5608: 9de3bf98                 save    %sp, -0x68, %sp
F00D560C: 80a62003                 cmp     %i0, 3
F00D5610: 14800008                 bg      locret_F00D5630
F00D5614: 840e6003                 and     %i1, 3, %g2
F00D5618: 073c03e58610e2c0         set     unk_F00F96C0, %g3
F00D5620: 8528a002                 sll     %g2, 2, %g2
F00D5624: b00e2003                 and     %i0, 3, %i0
F00D5628: 84008003                 add     %g2, %g3, %g2
F00D562C: f0488018                 ldsb    [%g2+%i0], %i0
F00D5630: 81c7e008                 ret
F00D5634: 81e80000                 restore
