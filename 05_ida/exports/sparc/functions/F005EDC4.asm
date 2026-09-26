F005EDC4: 9de3bf98                 save    %sp, -0x68, %sp
F005EDC8: b2100018                 mov     %i0, %i1
F005EDCC: f0064000                 ld      [%i1], %i0
F005EDD0: 80a62000                 cmp     %i0, 0
F005EDD4: 0280000d                 be      locret_F005EE08
F005EDD8: 01000000                 nop
F005EDDC: c6062090                 ld      [%i0+0x90], %g3
F005EDE0: 80a0c018                 cmp     %g3, %i0
F005EDE4: 32800004                 bne,a   loc_F005EDF4
F005EDE8: c4062094                 ld      [%i0+0x94], %g2
F005EDEC: 10800007                 ba      locret_F005EE08
F005EDF0: c0264000                 clr     [%i1]
F005EDF4: c6264000                 st      %g3, [%i1]
F005EDF8: c420e094                 st      %g2, [%g3+0x94]
F005EDFC: c620a090                 st      %g3, [%g2+0x90]
F005EE00: f0262090                 st      %i0, [%i0+0x90]
F005EE04: f0262094                 st      %i0, [%i0+0x94]
F005EE08: 81c7e008                 ret
F005EE0C: 81e80000                 restore
