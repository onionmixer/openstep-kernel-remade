F00A4DE4: 9de3bf98                 save    %sp, -0x68, %sp
F00A4DE8: 80a72001                 cmp     %i4, 1
F00A4DEC: 912f2003                 sll     %i4, 3, %o0
F00A4DF0: 1480000a                 bg      loc_F00A4E18
F00A4DF4: a0060008                 add     %i0, %o0, %l0
F00A4DF8: 113c046690122058         set     aRminitMapXMaps, %o0! "rminit: map %x, mapsize %d too small\n"
F00A4E00: 92100018                 mov     %i0, %o1
F00A4E04: 7ffdbe15                 call    _printf
F00A4E08: 9410001c                 mov     %i4, %o2
F00A4E0C: 113c0466                 sethi   %hi(aRminit), %o0! "rminit"
F00A4E10: 7ffdc0d8                 call    _panic
F00A4E14: 90122080                 bset    %lo(aRminit), %o0! "rminit"
F00A4E18: f6243ffc                 st      %i3, [%l0-4]
F00A4E1C: 80a72002                 cmp     %i4, 2
F00A4E20: 12800004                 bne     loc_F00A4E30
F00A4E24: c0243ff8                 clr     [%l0-8]
F00A4E28: 1080000c                 ba      locret_F00A4E58
F00A4E2C: c0260000                 clr     [%i0]
F00A4E30: 90073ffd                 add     %i4, -3, %o0
F00A4E34: d0260000                 st      %o0, [%i0]
F00A4E38: f2262008                 st      %i1, [%i0+8]
F00A4E3C: f426200c                 st      %i2, [%i0+0xC]
F00A4E40: 80a66000                 cmp     %i1, 0
F00A4E44: 12800005                 bne     locret_F00A4E58
F00A4E48: c0262010                 clr     [%i0+0x10]
F00A4E4C: d0060000                 ld      [%i0], %o0
F00A4E50: 90022001                 inc     %o0
F00A4E54: d0260000                 st      %o0, [%i0]
F00A4E58: 81c7e008                 ret
F00A4E5C: 81e80000                 restore
