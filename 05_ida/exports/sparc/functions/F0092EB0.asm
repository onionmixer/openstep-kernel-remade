F0092EB0: 9de3bf98                 save    %sp, -0x68, %sp
F0092EB4: b00e20ff                 and     %i0, 0xFF, %i0
F0092EB8: b1362003                 srl     %i0, 3, %i0
F0092EBC: 80a62010                 cmp     %i0, 0x10
F0092EC0: 34800008                 bg,a    locret_F0092EE0
F0092EC4: b0102000                 mov     0, %i0
F0092EC8: 872e2003                 sll     %i0, 3, %g3
F0092ECC: 8600c018                 add     %g3, %i0, %g3
F0092ED0: 8728e002                 sll     %g3, 2, %g3
F0092ED4: 053c04c48410a000         set     unk_F0131000, %g2
F0092EDC: f000c002                 ld      [%g3+%g2], %i0
F0092EE0: 81c7e008                 ret
F0092EE4: 81e80000                 restore
