F007B0F4: 9de3bf98                 save    %sp, -0x68, %sp
F007B0F8: d2062014                 ld      [%i0+0x14], %o1
F007B0FC: 110001d990122143         set     0x76543, %o0
F007B104: 80a24008                 cmp     %o1, %o0
F007B108: 12800019                 bne     loc_F007B16C
F007B10C: 113c0443                 sethi   -0xFEEF400, %o0
F007B110: 7fffb3d8                 call    _kalloc
F007B114: 90102014                 mov     0x14, %o0
F007B118: d206201c                 ld      [%i0+0x1C], %o1
F007B11C: 94100008                 mov     %o0, %o2
F007B120: d222a008                 st      %o1, [%o2+8]
F007B124: d0062020                 ld      [%i0+0x20], %o0
F007B128: d022a00c                 st      %o0, [%o2+0xC]
F007B12C: d0062028                 ld      [%i0+0x28], %o0
F007B130: d022a010                 st      %o0, [%o2+0x10]
F007B134: 113c04c3                 sethi   %hi(dword_F0130F58), %o0
F007B138: d2022358                 ld      [%o0+%lo(dword_F0130F58)], %o1
F007B13C: 96122358                 or      %o0, %lo(dword_F0130F58), %o3
F007B140: 9002fffc                 add     %o3, -4, %o0
F007B144: 80a24008                 cmp     %o1, %o0
F007B148: 32800003                 bne,a   loc_F007B154
F007B14C: d4224000                 st      %o2, [%o1]
F007B150: d422fffc                 st      %o2, [%o3-4]
F007B154: d222a004                 st      %o1, [%o2+4]
F007B158: 113c04c390122354         set     dword_F0130F54, %o0! char *
F007B160: d0228000                 st      %o0, [%o2]
F007B164: 10800004                 ba      locret_F007B174
F007B168: d4222004                 st      %o2, [%o0+4]
F007B16C: 7ffe653b                 call    _printf
F007B170: 90122380                 bset    0x380, %o0
F007B174: 81c7e008                 ret
F007B178: 81e80000                 restore
