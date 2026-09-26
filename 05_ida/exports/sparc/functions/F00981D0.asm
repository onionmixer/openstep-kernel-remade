F00981D0: 9de3bed0                 save    %sp, -0x130, %sp
F00981D4: 40005cb2                 call    _prom_childnode
F00981D8: 90100018                 mov     %i0, %o0
F00981DC: a0920000                 orcc    %o0, %g0, %l0
F00981E0: 02800058                 be      locret_F0098340
F00981E4: a207bfd0                 add     %fp, var_30, %l1
F00981E8: 113c044ba6122160         set     _psrange, %l3! "ranges"
F00981F0: a407bf30                 add     %fp, var_D0, %l2
F00981F4: 113c044aa8122138         set     _sbus_basepage, %l4
F00981FC: 9407bfd0                 add     %fp, var_30, %o2
F0098200: 92102027                 mov     0x27, %o1 ! '''
F0098204: c02a8000                 clrb    [%o2]
F0098208: 9402a001                 inc     %o2
F009820C: 90924000                 orcc    %o1, %g0, %o0
F0098210: 14bffffd                 bg      loc_F0098204
F0098214: 92027fff                 inc     -1, %o1
F0098218: 90100010                 mov     %l0, %o0
F009821C: 133c044b92126148         set     _psname, %o1! "name"
F0098224: 40005b78                 call    _prom_getprop
F0098228: 94100011                 mov     %l1, %o2
F009822C: 80a23fff                 cmp     %o0, -1
F0098230: 02800006                 be      loc_F0098248
F0098234: 90100010                 mov     %l0, %o0
F0098238: 92100019                 mov     %i1, %o1
F009823C: 9410001a                 mov     %i2, %o2
F0098240: 40000042                 call    sub_F0098348
F0098244: 96100011                 mov     %l1, %o3
F0098248: 90100010                 mov     %l0, %o0
F009824C: 40005b64                 call    _prom_getproplen
F0098250: 92100013                 mov     %l3, %o1
F0098254: 7ffdb8eb                 call    _udiv
F0098258: 92102014                 mov     0x14, %o1
F009825C: b0100008                 mov     %o0, %i0
F0098260: 90063fff                 add     %i0, -1, %o0
F0098264: 80a22006                 cmp     %o0, 6
F0098268: 1880002c                 bgu     loc_F0098318
F009826C: 92100013                 mov     %l3, %o1
F0098270: 90100010                 mov     %l0, %o0
F0098274: 40005b64                 call    _prom_getprop
F0098278: 94100012                 mov     %l2, %o2
F009827C: 90100011                 mov     %l1, %o0
F0098280: 92100019                 mov     %i1, %o1
F0098284: 9410001a                 mov     %i2, %o2
F0098288: 96100018                 mov     %i0, %o3
F009828C: 4000612a                 call    _apply_range_to_range
F0098290: 98100012                 mov     %l2, %o4
F0098294: 90100011                 mov     %l1, %o0! __s1
F0098298: 133c044b                 sethi   %hi(aSbus), %o1! "sbus"
F009829C: 7ffdbfc4                 call    _strcmp
F00982A0: 921262d8                 bset    %lo(aSbus), %o1! "sbus"
F00982A4: 80a22000                 cmp     %o0, 0
F00982A8: 12800019                 bne     loc_F009830C
F00982AC: 90100010                 mov     %l0, %o0
F00982B0: 113c044a                 sethi   %hi(_sbus_numslots), %o0
F00982B4: 98102000                 mov     0, %o4
F00982B8: 80a30018                 cmp     %o4, %i0
F00982BC: 16800013                 bge     loc_F0098308
F00982C0: f0222134                 st      %i0, [%o0+%lo(_sbus_numslots)]
F00982C4: 113c044a9a1221b8         set     _sbus_slotsize, %o5
F00982CC: 96100012                 mov     %l2, %o3
F00982D0: 94102000                 mov     0, %o2
F00982D4: d002e008                 ld      [%o3+8], %o0
F00982D8: 98032001                 inc     %o4
F00982DC: d207bf3c                 ld      [%fp+var_C4], %o1
F00982E0: 912a2014                 sll     %o0, 20, %o0
F00982E4: 9332600c                 srl     %o1, 12, %o1
F00982E8: 90120009                 bset    %o1, %o0
F00982EC: d0228014                 st      %o0, [%o2+%l4]
F00982F0: d002e010                 ld      [%o3+0x10], %o0
F00982F4: 80a30018                 cmp     %o4, %i0
F00982F8: d022800d                 st      %o0, [%o2+%o5]
F00982FC: 9602e014                 inc     0x14, %o3
F0098300: 06bffff5                 bl      loc_F00982D4
F0098304: 9402a004                 inc     4, %o2
F0098308: 90100010                 mov     %l0, %o0
F009830C: 92100018                 mov     %i0, %o1
F0098310: 10800005                 ba      loc_F0098324
F0098314: 9407bf30                 add     %fp, var_D0, %o2
F0098318: 90100010                 mov     %l0, %o0
F009831C: 92100019                 mov     %i1, %o1
F0098320: 9410001a                 mov     %i2, %o2
F0098324: 7fffffab                 call    sub_F00981D0
F0098328: 01000000                 nop
F009832C: 40005c53                 call    _prom_nextnode
F0098330: 90100010                 mov     %l0, %o0
F0098334: a0920000                 orcc    %o0, %g0, %l0
F0098338: 12bfffb2                 bne     loc_F0098200
F009833C: 9407bfd0                 add     %fp, var_30, %o2
F0098340: 81c7e008                 ret
F0098344: 81e80000                 restore
