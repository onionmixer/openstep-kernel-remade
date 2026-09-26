F005E6FC: 9de3bf88                 save    %sp, -0x78, %sp
F005E700: e4066004                 ld      [%i1+4], %l2
F005E704: 80a4a000                 cmp     %l2, 0
F005E708: 02800009                 be      loc_F005E72C
F005E70C: 90100012                 mov     %l2, %o0
F005E710: d406600c                 ld      [%i1+0xC], %o2
F005E714: 92066008                 add     %i1, 8, %o1
F005E718: d8066014                 ld      [%i1+0x14], %o4
F005E71C: 7ffffeeb                 call    sub_F005E2C8
F005E720: 96066010                 add     %i1, 0x10, %o3
F005E724: c0266004                 clr     [%i1+4]
F005E728: 80a4a000                 cmp     %l2, 0
F005E72C: 0280002c                 be      locret_F005E7DC
F005E730: 01000000                 nop
F005E734: d2062004                 ld      [%i0+4], %o1
F005E738: 80a26000                 cmp     %o1, 0
F005E73C: 12800004                 bne     loc_F005E74C
F005E740: d227bff4                 st      %o1, [%fp+var_C]
F005E744: 1080001e                 ba      loc_F005E7BC
F005E748: e427bff4                 st      %l2, [%fp+var_C]
F005E74C: d0060000                 ld      [%i0], %o0
F005E750: 80a22000                 cmp     %o0, 0
F005E754: 02800012                 be      loc_F005E79C
F005E758: 90100009                 mov     %o1, %o0
F005E75C: a0062008                 add     %i0, 8, %l0
F005E760: 92100010                 mov     %l0, %o1
F005E764: d406200c                 ld      [%i0+0xC], %o2
F005E768: a2062010                 add     %i0, 0x10, %l1
F005E76C: d8062014                 ld      [%i0+0x14], %o4
F005E770: 7ffffed6                 call    sub_F005E2C8
F005E774: 96100011                 mov     %l1, %o3
F005E778: 90102000                 mov     0, %o0
F005E77C: 9407bff4                 add     %fp, var_C, %o2
F005E780: 96100010                 mov     %l0, %o3
F005E784: 9806200c                 add     %i0, 0xC, %o4
F005E788: d207bff4                 ld      [%fp+var_C], %o1
F005E78C: 9a062014                 add     %i0, 0x14, %o5
F005E790: da23a05c                 st      %o5, [%sp+0x78+var_1C]
F005E794: 7ffffe84                 call    sub_F005E1A4
F005E798: 9a100011                 mov     %l1, %o5
F005E79C: d007bff4                 ld      [%fp+var_C], %o0
F005E7A0: d406200c                 ld      [%i0+0xC], %o2
F005E7A4: 92062008                 add     %i0, 8, %o1
F005E7A8: d8062014                 ld      [%i0+0x14], %o4
F005E7AC: 7ffffec7                 call    sub_F005E2C8
F005E7B0: 96062010                 add     %i0, 0x10, %o3
F005E7B4: d007bff4                 ld      [%fp+var_C], %o0
F005E7B8: e4222018                 st      %l2, [%o0+0x18]
F005E7BC: d007bff4                 ld      [%fp+var_C], %o0
F005E7C0: d0262004                 st      %o0, [%i0+4]
F005E7C4: d0022010                 ld      [%o0+0x10], %o0
F005E7C8: d0260000                 st      %o0, [%i0]
F005E7CC: 90062008                 add     %i0, 8, %o0
F005E7D0: d026200c                 st      %o0, [%i0+0xC]
F005E7D4: 90062010                 add     %i0, 0x10, %o0
F005E7D8: d0262014                 st      %o0, [%i0+0x14]
F005E7DC: 81c7e008                 ret
F005E7E0: 81e80000                 restore
