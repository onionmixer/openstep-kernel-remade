F00B8EBC: 9de3bf98                 save    %sp, -0x68, %sp
F00B8EC0: c6062034                 ld      [%i0+0x34], %g3
F00B8EC4: f406203c                 ld      [%i0+0x3C], %i2
F00B8EC8: 80a0c01a                 cmp     %g3, %i2
F00B8ECC: 2a80000d                 bcs,a   locret_F00B8F00
F00B8ED0: b0102000                 mov     0, %i0
F00B8ED4: c4062040                 ld      [%i0+0x40], %g2
F00B8ED8: b0068002                 add     %i2, %g2, %i0
F00B8EDC: 80a0c018                 cmp     %g3, %i0
F00B8EE0: 0a800004                 bcs     loc_F00B8EF0
F00B8EE4: 8400c019                 add     %g3, %i1, %g2
F00B8EE8: 10800006                 ba      locret_F00B8F00
F00B8EEC: b0102000                 mov     0, %i0
F00B8EF0: 80a08018                 cmp     %g2, %i0
F00B8EF4: 1a800003                 bcc     locret_F00B8F00
F00B8EF8: b0260003                 sub     %i0, %g3, %i0
F00B8EFC: b0100019                 mov     %i1, %i0
F00B8F00: 81c7e008                 ret
F00B8F04: 81e80000                 restore
