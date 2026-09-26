F0090D74: 9de3bf98                 save    %sp, -0x68, %sp
F0090D78: f006600c                 ld      [%i1+0xC], %i0
F0090D7C: 80a62000                 cmp     %i0, 0
F0090D80: 12800004                 bne     loc_F0090D90
F0090D84: 90102000                 mov     0, %o0
F0090D88: 10800021                 ba      locret_F0090E0C
F0090D8C: b0103d38                 mov     -0x2C8, %i0
F0090D90: 133c0243                 sethi   %hi(sub_F0090D4C), %o1
F0090D94: 153c04d0                 sethi   %hi(_page_mask), %o2
F0090D98: da02a0d8                 ld      [%o2+%lo(_page_mask)], %o5
F0090D9C: 9212614c                 bset    %lo(sub_F0090D4C), %o1
F0090DA0: d606c000                 ld      [%i3], %o3
F0090DA4: 94102000                 mov     0, %o2
F0090DA8: 9806800d                 add     %i2, %o5, %o4
F0090DAC: b42b000d                 andn    %o4, %o5, %i2
F0090DB0: 7fffe57c                 call    _vm_object_special
F0090DB4: 9810001a                 mov     %i2, %o4
F0090DB8: b2100008                 mov     %o0, %i1
F0090DBC: 90100018                 mov     %i0, %o0
F0090DC0: 92100019                 mov     %i1, %o1
F0090DC4: 94102000                 mov     0, %o2
F0090DC8: 9610001b                 mov     %i3, %o3
F0090DCC: 9810001a                 mov     %i2, %o4
F0090DD0: 7fffce00                 call    _vm_map_find
F0090DD4: 9a102000                 mov     0, %o5
F0090DD8: 80a22000                 cmp     %o0, 0
F0090DDC: 0280000b                 be      loc_F0090E08
F0090DE0: 90100018                 mov     %i0, %o0
F0090DE4: 92100019                 mov     %i1, %o1
F0090DE8: 94102000                 mov     0, %o2
F0090DEC: 9610001b                 mov     %i3, %o3
F0090DF0: 9810001a                 mov     %i2, %o4
F0090DF4: 7fffcdf7                 call    _vm_map_find
F0090DF8: 9a102001                 mov     1, %o5
F0090DFC: 80a22000                 cmp     %o0, 0
F0090E00: 12800003                 bne     locret_F0090E0C
F0090E04: b0103d43                 mov     -0x2BD, %i0
F0090E08: b0102000                 mov     0, %i0
F0090E0C: 81c7e008                 ret
F0090E10: 81e80000                 restore
