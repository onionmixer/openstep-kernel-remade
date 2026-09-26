F005E7E4: 9de3bf88                 save    %sp, -0x78, %sp
F005E7E8: d2062004                 ld      [%i0+4], %o1
F005E7EC: 80a26000                 cmp     %o1, 0
F005E7F0: 12800006                 bne     loc_F005E808
F005E7F4: d227bff4                 st      %o1, [%fp+var_C]
F005E7F8: 90103fff                 mov     -1, %o0
F005E7FC: d0268000                 st      %o0, [%i2]
F005E800: 10800032                 ba      locret_F005E8C8
F005E804: c026c000                 clr     [%i3]
F005E808: d0060000                 ld      [%i0], %o0
F005E80C: 80a20019                 cmp     %o0, %i1
F005E810: 02800015                 be      loc_F005E864
F005E814: 90100009                 mov     %o1, %o0
F005E818: a0062008                 add     %i0, 8, %l0
F005E81C: 92100010                 mov     %l0, %o1
F005E820: d406200c                 ld      [%i0+0xC], %o2
F005E824: a2062010                 add     %i0, 0x10, %l1
F005E828: d8062014                 ld      [%i0+0x14], %o4
F005E82C: 7ffffea7                 call    sub_F005E2C8
F005E830: 96100011                 mov     %l1, %o3
F005E834: 90100019                 mov     %i1, %o0
F005E838: 9407bff4                 add     %fp, var_C, %o2
F005E83C: 96100010                 mov     %l0, %o3
F005E840: 9806200c                 add     %i0, 0xC, %o4
F005E844: d207bff4                 ld      [%fp+var_C], %o1
F005E848: 9a062014                 add     %i0, 0x14, %o5
F005E84C: da23a05c                 st      %o5, [%sp+0x78+var_1C]
F005E850: 7ffffe55                 call    sub_F005E1A4
F005E854: 9a100011                 mov     %l1, %o5
F005E858: d007bff4                 ld      [%fp+var_C], %o0
F005E85C: f2260000                 st      %i1, [%i0]
F005E860: d0262004                 st      %o0, [%i0+4]
F005E864: d007bff4                 ld      [%fp+var_C], %o0
F005E868: d4022010                 ld      [%o0+0x10], %o2
F005E86C: 80a28019                 cmp     %o2, %i1
F005E870: 38800004                 bgu,a   loc_F005E880
F005E874: d206200c                 ld      [%i0+0xC], %o1
F005E878: 10800009                 ba      loc_F005E89C
F005E87C: d4268000                 st      %o2, [%i2]
F005E880: 90062008                 add     %i0, 8, %o0
F005E884: 80a24008                 cmp     %o1, %o0
F005E888: 32800003                 bne,a   loc_F005E894
F005E88C: d0027ff4                 ld      [%o1-0xC], %o0
F005E890: 90103fff                 mov     -1, %o0
F005E894: d0268000                 st      %o0, [%i2]
F005E898: 80a28019                 cmp     %o2, %i1
F005E89C: 2a800004                 bcs,a   loc_F005E8AC
F005E8A0: d2062014                 ld      [%i0+0x14], %o1
F005E8A4: 10800009                 ba      locret_F005E8C8
F005E8A8: d426c000                 st      %o2, [%i3]
F005E8AC: 90062010                 add     %i0, 0x10, %o0
F005E8B0: 80a24008                 cmp     %o1, %o0
F005E8B4: 32800004                 bne,a   loc_F005E8C4
F005E8B8: d0027ff8                 ld      [%o1-8], %o0
F005E8BC: 10800003                 ba      locret_F005E8C8
F005E8C0: c026c000                 clr     [%i3]
F005E8C4: d026c000                 st      %o0, [%i3]
F005E8C8: 81c7e008                 ret
F005E8CC: 81e80000                 restore
