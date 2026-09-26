F00D2F30: 9de3bf90                 save    %sp, -0x70, %sp
F00D2F34: c4062134                 ld      [%i0+0x134], %g2
F00D2F38: 80a68002                 cmp     %i2, %g2
F00D2F3C: 02800004                 be      loc_F00D2F4C
F00D2F40: 80a6e006                 cmp     %i3, 6
F00D2F44: 10800007                 ba      locret_F00D2F60
F00D2F48: b0103d3f                 mov     -0x2C1, %i0
F00D2F4C: 18800004                 bgu     loc_F00D2F5C
F00D2F50: 852ee002                 sll     %i3, 2, %g2
F00D2F54: 84008018                 add     %g2, %i0, %g2
F00D2F58: f820a118                 st      %i4, [%g2+0x118]
F00D2F5C: b0102000                 mov     0, %i0
F00D2F60: 81c7e008                 ret
F00D2F64: 81e80000                 restore
