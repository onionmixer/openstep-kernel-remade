F0064ED4: 9de3bf98                 save    %sp, -0x68, %sp
F0064ED8: 80a62000                 cmp     %i0, 0
F0064EDC: 02800013                 be      locret_F0064F28
F0064EE0: b0102004                 mov     4, %i0
F0064EE4: 40000c63                 call    _kalloc
F0064EE8: 90102004                 mov     4, %o0
F0064EEC: b0920000                 orcc    %o0, %g0, %i0
F0064EF0: 0280000d                 be      loc_F0064F24
F0064EF4: 213c04d3                 sethi   %hi(_default_pset), %l0
F0064EF8: a01423c0                 bset    %lo(_default_pset), %l0
F0064EFC: 400028a8                 call    _pset_reference
F0064F00: 90100010                 mov     %l0, %o0
F0064F04: 40000199                 call    _convert_pset_name_to_port
F0064F08: 90100010                 mov     %l0, %o0
F0064F0C: d0260000                 st      %o0, [%i0]
F0064F10: f0264000                 st      %i0, [%i1]
F0064F14: 90102001                 mov     1, %o0
F0064F18: d0268000                 st      %o0, [%i2]
F0064F1C: 10800003                 ba      locret_F0064F28
F0064F20: b0102000                 mov     0, %i0
F0064F24: b0102006                 mov     6, %i0
F0064F28: 81c7e008                 ret
F0064F2C: 81e80000                 restore
