F0062F34: 9de3bf98                 save    %sp, -0x68, %sp
F0062F38: 110007c0                 sethi   0x1F0000, %o0
F0062F3C: b00e0008                 and     %i0, %o0, %i0
F0062F40: 110000c0                 sethi   0x30000, %o0
F0062F44: 80a60008                 cmp     %i0, %o0
F0062F48: 2280001f                 be,a    locret_F0062FC4
F0062F4C: b0102007                 mov     7, %i0
F0062F50: 1880000a                 bgu     loc_F0062F78
F0062F54: 11000040                 sethi   0x10000, %o0
F0062F58: 80a60008                 cmp     %i0, %o0
F0062F5C: 02800016                 be      loc_F0062FB4
F0062F60: 11000080                 sethi   0x20000, %o0
F0062F64: 80a60008                 cmp     %i0, %o0
F0062F68: 02800017                 be      locret_F0062FC4
F0062F6C: b0102007                 mov     7, %i0
F0062F70: 10800013                 ba      loc_F0062FBC
F0062F74: 113c043e                 sethi   -0xFEF0800, %o0
F0062F78: 11000200                 sethi   0x80000, %o0
F0062F7C: 80a60008                 cmp     %i0, %o0
F0062F80: 22800011                 be,a    locret_F0062FC4
F0062F84: b0102009                 mov     9, %i0
F0062F88: 18800007                 bgu     loc_F0062FA4
F0062F8C: 11000100                 sethi   0x40000, %o0
F0062F90: 80a60008                 cmp     %i0, %o0
F0062F94: 0280000c                 be      locret_F0062FC4
F0062F98: b0102001                 mov     1, %i0
F0062F9C: 10800008                 ba      loc_F0062FBC
F0062FA0: 113c043e                 sethi   -0xFEF0800, %o0
F0062FA4: 11000400                 sethi   0x100000, %o0
F0062FA8: 80a60008                 cmp     %i0, %o0
F0062FAC: 12800004                 bne     loc_F0062FBC
F0062FB0: 113c043e                 sethi   -0xFEF0800, %o0! char *
F0062FB4: 10800004                 ba      locret_F0062FC4
F0062FB8: b0102001                 mov     1, %i0
F0062FBC: 7ffec86d                 call    _panic
F0062FC0: 90122060                 bset    0x60, %o0 ! '`'
F0062FC4: 81c7e008                 ret
F0062FC8: 81e80000                 restore
