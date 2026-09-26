F005E330: 9de3bf88                 save    %sp, -0x78, %sp
F005E334: d2062004                 ld      [%i0+4], %o1
F005E338: 80a26000                 cmp     %o1, 0
F005E33C: 0280001e                 be      loc_F005E3B4
F005E340: d227bff4                 st      %o1, [%fp+var_C]
F005E344: d0060000                 ld      [%i0], %o0
F005E348: 80a20019                 cmp     %o0, %i1
F005E34C: 02800015                 be      loc_F005E3A0
F005E350: 90100009                 mov     %o1, %o0
F005E354: a0062008                 add     %i0, 8, %l0
F005E358: 92100010                 mov     %l0, %o1
F005E35C: d406200c                 ld      [%i0+0xC], %o2
F005E360: a2062010                 add     %i0, 0x10, %l1
F005E364: d8062014                 ld      [%i0+0x14], %o4
F005E368: 7fffffd8                 call    sub_F005E2C8
F005E36C: 96100011                 mov     %l1, %o3
F005E370: 90100019                 mov     %i1, %o0
F005E374: 9407bff4                 add     %fp, var_C, %o2
F005E378: 96100010                 mov     %l0, %o3
F005E37C: 9806200c                 add     %i0, 0xC, %o4
F005E380: d207bff4                 ld      [%fp+var_C], %o1
F005E384: 9a062014                 add     %i0, 0x14, %o5
F005E388: da23a05c                 st      %o5, [%sp+0x78+var_1C]
F005E38C: 7fffff86                 call    sub_F005E1A4
F005E390: 9a100011                 mov     %l1, %o5
F005E394: d007bff4                 ld      [%fp+var_C], %o0
F005E398: f2260000                 st      %i1, [%i0]
F005E39C: d0262004                 st      %o0, [%i0+4]
F005E3A0: d007bff4                 ld      [%fp+var_C], %o0
F005E3A4: d0022010                 ld      [%o0+0x10], %o0
F005E3A8: 80a64008                 cmp     %i1, %o0
F005E3AC: 32800002                 bne,a   loc_F005E3B4
F005E3B0: c027bff4                 clr     [%fp+var_C]
F005E3B4: f007bff4                 ld      [%fp+var_C], %i0
F005E3B8: 81c7e008                 ret
F005E3BC: 81e80000                 restore
