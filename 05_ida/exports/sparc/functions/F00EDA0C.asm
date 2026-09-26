F00EDA0C: 9de3bf98                 save    %sp, -0x68, %sp
F00EDA10: a6100018                 mov     %i0, %l3
F00EDA14: d004c000                 ld      [%l3], %o0
F00EDA18: d4020000                 ld      [%o0], %o2
F00EDA1C: d004e010                 ld      [%l3+0x10], %o0
F00EDA20: 9fc28000                 call    %o2
F00EDA24: 92100019                 mov     %i1, %o1
F00EDA28: 7ffc639e                 call    _urem
F00EDA2C: d204e008                 ld      [%l3+8], %o1
F00EDA30: a52a2003                 sll     %o0, 3, %l2
F00EDA34: e204e00c                 ld      [%l3+0xC], %l1
F00EDA38: a8048011                 add     %l2, %l1, %l4
F00EDA3C: e0048011                 ld      [%l2+%l1], %l0
F00EDA40: 40000c46                 call    _NXZoneFromPtr
F00EDA44: 90100013                 mov     %l3, %o0
F00EDA48: 80a42000                 cmp     %l0, 0
F00EDA4C: 1280000a                 bne     loc_F00EDA74
F00EDA50: aa100008                 mov     %o0, %l5
F00EDA54: d0048011                 ld      [%l2+%l1], %o0
F00EDA58: 90022001                 inc     %o0
F00EDA5C: d0248011                 st      %o0, [%l2+%l1]
F00EDA60: f2252004                 st      %i1, [%l4+4]
F00EDA64: d004e004                 ld      [%l3+4], %o0
F00EDA68: 90022001                 inc     %o0
F00EDA6C: 10800049                 ba      loc_F00EDB90
F00EDA70: d024e004                 st      %o0, [%l3+4]
F00EDA74: 80a42001                 cmp     %l0, 1
F00EDA78: 32800025                 bne,a   loc_F00EDB0C
F00EDA7C: f0052004                 ld      [%l4+4], %i0
F00EDA80: d4052004                 ld      [%l4+4], %o2
F00EDA84: 80a6400a                 cmp     %i1, %o2
F00EDA88: 22800043                 be,a    locret_F00EDB94
F00EDA8C: f0052004                 ld      [%l4+4], %i0
F00EDA90: d004c000                 ld      [%l3], %o0
F00EDA94: d6022004                 ld      [%o0+4], %o3
F00EDA98: d004e010                 ld      [%l3+0x10], %o0
F00EDA9C: 9fc2c000                 call    %o3
F00EDAA0: 92100019                 mov     %i1, %o1
F00EDAA4: 80a22000                 cmp     %o0, 0
F00EDAA8: 02800004                 be      loc_F00EDAB8
F00EDAAC: 90100015                 mov     %l5, %o0
F00EDAB0: 10800039                 ba      locret_F00EDB94
F00EDAB4: f0052004                 ld      [%l4+4], %i0
F00EDAB8: 92102002                 mov     2, %o1
F00EDABC: 40000c2f                 call    _NXZoneCalloc
F00EDAC0: 94102004                 mov     4, %o2
F00EDAC4: a0100008                 mov     %o0, %l0
F00EDAC8: d0052004                 ld      [%l4+4], %o0
F00EDACC: d0242004                 st      %o0, [%l0+4]
F00EDAD0: 10800023                 ba      loc_F00EDB5C
F00EDAD4: f2240000                 st      %i1, [%l0]
F00EDAD8: 80a6400a                 cmp     %i1, %o2
F00EDADC: 2280002e                 be,a    locret_F00EDB94
F00EDAE0: f0060000                 ld      [%i0], %i0
F00EDAE4: d004c000                 ld      [%l3], %o0
F00EDAE8: d6022004                 ld      [%o0+4], %o3
F00EDAEC: d004e010                 ld      [%l3+0x10], %o0
F00EDAF0: 9fc2c000                 call    %o3
F00EDAF4: 92100019                 mov     %i1, %o1
F00EDAF8: 80a22000                 cmp     %o0, 0
F00EDAFC: 22800004                 be,a    loc_F00EDB0C
F00EDB00: b0062004                 inc     4, %i0
F00EDB04: 10800024                 ba      locret_F00EDB94
F00EDB08: f0060000                 ld      [%i0], %i0
F00EDB0C: a0043fff                 inc     -1, %l0
F00EDB10: 80a43fff                 cmp     %l0, -1
F00EDB14: 32bffff1                 bne,a   loc_F00EDAD8
F00EDB18: d4060000                 ld      [%i0], %o2
F00EDB1C: d2050000                 ld      [%l4], %o1
F00EDB20: 90100015                 mov     %l5, %o0
F00EDB24: 92026001                 inc     %o1
F00EDB28: 40000c14                 call    _NXZoneCalloc
F00EDB2C: 94102004                 mov     4, %o2
F00EDB30: d4050000                 ld      [%l4], %o2! __len
F00EDB34: 80a2a000                 cmp     %o2, 0
F00EDB38: 02800006                 be      loc_F00EDB50
F00EDB3C: a0100008                 mov     %o0, %l0
F00EDB40: 90042004                 add     %l0, 4, %o0! void *
F00EDB44: d2052004                 ld      [%l4+4], %o1! __src
F00EDB48: 7ffc6922                 call    _memmove
F00EDB4C: 952aa002                 sll     %o2, 2, %o2
F00EDB50: f2240000                 st      %i1, [%l0]
F00EDB54: 7ffde9eb                 call    _free
F00EDB58: d0052004                 ld      [%l4+4], %o0
F00EDB5C: d0050000                 ld      [%l4], %o0
F00EDB60: 90022001                 inc     %o0
F00EDB64: d0250000                 st      %o0, [%l4]
F00EDB68: e0252004                 st      %l0, [%l4+4]
F00EDB6C: d004e004                 ld      [%l3+4], %o0
F00EDB70: 90022001                 inc     %o0
F00EDB74: d024e004                 st      %o0, [%l3+4]
F00EDB78: d204e008                 ld      [%l3+8], %o1
F00EDB7C: 80a20009                 cmp     %o0, %o1
F00EDB80: 08800005                 bleu    locret_F00EDB94
F00EDB84: b0100019                 mov     %i1, %i0
F00EDB88: 7fffff01                 call    sub_F00ED78C
F00EDB8C: 90100013                 mov     %l3, %o0
F00EDB90: b0100019                 mov     %i1, %i0
F00EDB94: 81c7e008                 ret
F00EDB98: 81e80000                 restore
