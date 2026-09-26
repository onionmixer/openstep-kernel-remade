F00B2DB8: 9de3bf98                 save    %sp, -0x68, %sp
F00B2DBC: a0100018                 mov     %i0, %l0
F00B2DC0: f006600c                 ld      [%i1+0xC], %i0
F00B2DC4: 80a62000                 cmp     %i0, 0
F00B2DC8: 12800031                 bne     locret_F00B2E8C
F00B2DCC: 113c0477                 sethi   %hi(dword_F011DDA0), %o0
F00B2DD0: d00221a0                 ld      [%o0+%lo(dword_F011DDA0)], %o0
F00B2DD4: 80a22000                 cmp     %o0, 0
F00B2DD8: 02800005                 be      loc_F00B2DEC
F00B2DDC: 113c0477                 sethi   %hi(aCheckingS), %o0! "\tchecking %s\n"
F00B2DE0: d204200c                 ld      [%l0+0xC], %o1
F00B2DE4: 7ffd861d                 call    _printf
F00B2DE8: 901221d0                 bset    %lo(aCheckingS), %o0! "\tchecking %s\n"
F00B2DEC: d0064000                 ld      [%i1], %o0! __s1
F00B2DF0: 133c0477                 sethi   %hi(aSd), %o1! "sd"
F00B2DF4: 7ffd54ee                 call    _strcmp
F00B2DF8: 921261e0                 bset    %lo(aSd), %o1! "sd"
F00B2DFC: 80a22000                 cmp     %o0, 0
F00B2E00: 12800009                 bne     loc_F00B2E24
F00B2E04: d004200c                 ld      [%l0+0xC], %o0! __s1
F00B2E08: 133c0477                 sethi   %hi(aSr), %o1! "sr"
F00B2E0C: 7ffd54e8                 call    _strcmp
F00B2E10: 921261e8                 bset    %lo(aSr), %o1! "sr"
F00B2E14: 80a22000                 cmp     %o0, 0
F00B2E18: 22800009                 be,a    loc_F00B2E3C
F00B2E1C: d0066004                 ld      [%i1+4], %o0
F00B2E20: d004200c                 ld      [%l0+0xC], %o0! __s1
F00B2E24: 7ffd54e2                 call    _strcmp
F00B2E28: d2064000                 ld      [%i1], %o1
F00B2E2C: 80a22000                 cmp     %o0, 0
F00B2E30: 12800017                 bne     locret_F00B2E8C
F00B2E34: b0102000                 mov     0, %i0
F00B2E38: d0066004                 ld      [%i1+4], %o0
F00B2E3C: d04a0000                 ldsb    [%o0], %o0
F00B2E40: 80a22000                 cmp     %o0, 0
F00B2E44: 22800011                 be,a    loc_F00B2E88
F00B2E48: e026600c                 st      %l0, [%i1+0xC]
F00B2E4C: 7fffffae                 call    _path_getmatchfunc
F00B2E50: d0040000                 ld      [%l0], %o0
F00B2E54: 94920000                 orcc    %o0, %g0, %o2
F00B2E58: 12800004                 bne     loc_F00B2E68
F00B2E5C: d2066004                 ld      [%i1+4], %o1
F00B2E60: 113c02cd94122250         set     _obio_match, %o2
F00B2E68: 9fc28000                 call    %o2
F00B2E6C: 90100010                 mov     %l0, %o0
F00B2E70: 80a22000                 cmp     %o0, 0
F00B2E74: 32800005                 bne,a   loc_F00B2E88
F00B2E78: e026600c                 st      %l0, [%i1+0xC]
F00B2E7C: c026600c                 clr     [%i1+0xC]
F00B2E80: 10800003                 ba      locret_F00B2E8C
F00B2E84: b0102000                 mov     0, %i0
F00B2E88: b0100010                 mov     %l0, %i0
F00B2E8C: 81c7e008                 ret
F00B2E90: 81e80000                 restore
