F0076DD0: 9de3bf98                 save    %sp, -0x68, %sp
F0076DD4: 40007f6d                 call    _splusclock
F0076DD8: 01000000                 nop
F0076DDC: a2100008                 mov     %o0, %l1
F0076DE0: 113c04c3a0122320         set     dword_F0130F20, %l0
F0076DE8: d0040000                 ld      [%l0], %o0
F0076DEC: 80a22000                 cmp     %o0, 0
F0076DF0: 12bffffe                 bne     loc_F0076DE8
F0076DF4: 01000000                 nop
F0076DF8: 4000802c                 call    _simple_lock_try
F0076DFC: 90100010                 mov     %l0, %o0
F0076E00: 80a22000                 cmp     %o0, 0
F0076E04: 02bffff9                 be      loc_F0076DE8
F0076E08: 90100018                 mov     %i0, %o0
F0076E0C: 92100019                 mov     %i1, %o1
F0076E10: 7ffffe72                 call    sub_F00767D8
F0076E14: 94102001                 mov     1, %o2
F0076E18: 90100018                 mov     %i0, %o0
F0076E1C: 92100019                 mov     %i1, %o1
F0076E20: 7ffffea2                 call    sub_F00768A8
F0076E24: 94102001                 mov     1, %o2
F0076E28: 113c04c3                 sethi   %hi(dword_F0130F20), %o0
F0076E2C: c0222320                 clr     [%o0+%lo(dword_F0130F20)]
F0076E30: 40007fbd                 call    _splx
F0076E34: 90100011                 mov     %l1, %o0
F0076E38: 81c7e008                 ret
F0076E3C: 81e80000                 restore
