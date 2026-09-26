F00B0D84: 9de3bf98                 save    %sp, -0x68, %sp
F00B0D88: 053c04f8                 sethi   %hi(_cpu), %g2
F00B0D8C: c600a120                 ld      [%g2+%lo(_cpu)], %g3
F00B0D90: 80a0e072                 cmp     %g3, 0x72 ! 'r'
F00B0D94: 02800007                 be      loc_F00B0DB0
F00B0D98: 853e2014                 sra     %i0, 20, %g2
F00B0D9C: 80a0e080                 cmp     %g3, 0x80
F00B0DA0: 02800014                 be      loc_F00B0DF0
F00B0DA4: 853e2010                 sra     %i0, 16, %g2
F00B0DA8: 10800022                 ba      locret_F00B0E30
F00B0DAC: b0102001                 mov     1, %i0
F00B0DB0: 80a0a009                 cmp     %g2, 9
F00B0DB4: 0280001f                 be      locret_F00B0E30
F00B0DB8: b0102004                 mov     4, %i0
F00B0DBC: 18800006                 bgu     loc_F00B0DD4
F00B0DC0: 80a0a000                 cmp     %g2, 0
F00B0DC4: 0280001b                 be      locret_F00B0E30
F00B0DC8: b0102002                 mov     2, %i0
F00B0DCC: 10800019                 ba      locret_F00B0E30
F00B0DD0: b0102001                 mov     1, %i0
F00B0DD4: 80a0a00e                 cmp     %g2, 0xE
F00B0DD8: 02800013                 be      loc_F00B0E24
F00B0DDC: 80a0a00f                 cmp     %g2, 0xF
F00B0DE0: 02800014                 be      locret_F00B0E30
F00B0DE4: b0102003                 mov     3, %i0
F00B0DE8: 10800012                 ba      locret_F00B0E30
F00B0DEC: b0102001                 mov     1, %i0
F00B0DF0: 80a0a001                 cmp     %g2, 1
F00B0DF4: 2280000f                 be,a    locret_F00B0E30
F00B0DF8: b0102003                 mov     3, %i0
F00B0DFC: 0a800008                 bcs     loc_F00B0E1C
F00B0E00: 80a0a007                 cmp     %g2, 7
F00B0E04: 1880000a                 bgu     loc_F00B0E2C
F00B0E08: 80a0a003                 cmp     %g2, 3
F00B0E0C: 0a800009                 bcs     locret_F00B0E30
F00B0E10: b0102001                 mov     1, %i0
F00B0E14: 10800007                 ba      locret_F00B0E30
F00B0E18: b0102005                 mov     5, %i0
F00B0E1C: 10800005                 ba      locret_F00B0E30
F00B0E20: b0102002                 mov     2, %i0
F00B0E24: 10800003                 ba      locret_F00B0E30
F00B0E28: b0102005                 mov     5, %i0
F00B0E2C: b0102001                 mov     1, %i0
F00B0E30: 81c7e008                 ret
F00B0E34: 81e80000                 restore
