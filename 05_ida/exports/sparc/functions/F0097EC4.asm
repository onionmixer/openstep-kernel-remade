F0097EC4: 9de3bf98                 save    %sp, -0x68, %sp
F0097EC8: 86102000                 mov     0, %g3
F0097ECC: 80a0c01a                 cmp     %g3, %i2
F0097ED0: 1a800013                 bcc     loc_F0097F1C
F0097ED4: 80a6e000                 cmp     %i3, 0
F0097ED8: c40e0000                 ldub    [%i0], %g2
F0097EDC: c42e4000                 stb     %g2, [%i1]
F0097EE0: b0062001                 inc     %i0
F0097EE4: 80a0a000                 cmp     %g2, 0
F0097EE8: 12800008                 bne     loc_F0097F08
F0097EEC: b2066001                 inc     %i1
F0097EF0: 80a6e000                 cmp     %i3, 0
F0097EF4: 02800003                 be      loc_F0097F00
F0097EF8: 8400e001                 add     %g3, 1, %g2
F0097EFC: c426c000                 st      %g2, [%i3]
F0097F00: 1080000a                 ba      locret_F0097F28
F0097F04: b0102000                 mov     0, %i0
F0097F08: 8600e001                 inc     %g3
F0097F0C: 80a0c01a                 cmp     %g3, %i2
F0097F10: 2abffff3                 bcs,a   loc_F0097EDC
F0097F14: c40e0000                 ldub    [%i0], %g2
F0097F18: 80a6e000                 cmp     %i3, 0
F0097F1C: 32800002                 bne,a   loc_F0097F24
F0097F20: f426c000                 st      %i2, [%i3]
F0097F24: b0102002                 mov     2, %i0
F0097F28: 81c7e008                 ret
F0097F2C: 81e80000                 restore
