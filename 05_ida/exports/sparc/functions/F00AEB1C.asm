F00AEB1C: 9de3bf98                 save    %sp, -0x68, %sp
F00AEB20: 80a6e000                 cmp     %i3, 0
F00AEB24: 02800007                 be      loc_F00AEB40
F00AEB28: 8406401a                 add     %i1, %i2, %g2
F00AEB2C: 8400a001                 inc     %g2
F00AEB30: c4260000                 st      %g2, [%i0]
F00AEB34: 80a68002                 cmp     %i2, %g2
F00AEB38: 10800005                 ba      locret_F00AEB4C
F00AEB3C: b0603fff                 subc    %g0, -1, %i0
F00AEB40: c4260000                 st      %g2, [%i0]
F00AEB44: 80a0801a                 cmp     %g2, %i2
F00AEB48: b0402000                 addc    %g0, 0, %i0
F00AEB4C: 81c7e008                 ret
F00AEB50: 81e80000                 restore
