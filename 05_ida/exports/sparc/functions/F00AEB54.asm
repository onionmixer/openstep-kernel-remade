F00AEB54: 9de3bf98                 save    %sp, -0x68, %sp
F00AEB58: 80a6e000                 cmp     %i3, 0
F00AEB5C: 02800007                 be      loc_F00AEB78
F00AEB60: 8426401a                 sub     %i1, %i2, %g2
F00AEB64: 8400bfff                 inc     -1, %g2
F00AEB68: c4260000                 st      %g2, [%i0]
F00AEB6C: 80a08019                 cmp     %g2, %i1
F00AEB70: 10800005                 ba      locret_F00AEB84
F00AEB74: b0603fff                 subc    %g0, -1, %i0
F00AEB78: c4260000                 st      %g2, [%i0]
F00AEB7C: 80a64002                 cmp     %i1, %g2
F00AEB80: b0402000                 addc    %g0, 0, %i0
F00AEB84: 81c7e008                 ret
F00AEB88: 81e80000                 restore
