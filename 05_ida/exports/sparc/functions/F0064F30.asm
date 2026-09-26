F0064F30: 9de3bf98                 save    %sp, -0x68, %sp
F0064F34: 80a62000                 cmp     %i0, 0
F0064F38: 02800005                 be      loc_F0064F4C
F0064F3C: 90100019                 mov     %i1, %o0
F0064F40: 80a22000                 cmp     %o0, 0
F0064F44: 12800005                 bne     loc_F0064F58
F0064F48: 01000000                 nop
F0064F4C: c0268000                 clr     [%i2]
F0064F50: 10800005                 ba      locret_F0064F64
F0064F54: b0102004                 mov     4, %i0
F0064F58: 40002891                 call    _pset_reference
F0064F5C: d0268000                 st      %o0, [%i2]
F0064F60: b0102000                 mov     0, %i0
F0064F64: 81c7e008                 ret
F0064F68: 81e80000                 restore
