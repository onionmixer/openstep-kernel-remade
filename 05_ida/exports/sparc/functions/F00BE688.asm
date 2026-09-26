F00BE688: 9de3bf90                 save    %sp, -0x70, %sp
F00BE68C: ea062024                 ld      [%i0+0x24], %l5
F00BE690: ec062028                 ld      [%i0+0x28], %l6
F00BE694: 7ffd2369                 call    _strlen
F00BE698: 90100019                 mov     %i1, %o0
F00BE69C: a2920000                 orcc    %o0, %g0, %l1
F00BE6A0: 02800006                 be      loc_F00BE6B8
F00BE6A4: 113c0482                 sethi   -0xFEDF800, %o0
F00BE6A8: d0062014                 ld      [%i0+0x14], %o0
F00BE6AC: 80a44008                 cmp     %l1, %o0
F00BE6B0: 04800006                 ble     loc_F00BE6C8
F00BE6B4: 113c0482                 sethi   -0xFEDF800, %o0
F00BE6B8: 901221d0                 bset    0x1D0, %o0
F00BE6BC: 40001e8e                 call    _IOLog
F00BE6C0: 92100011                 mov     %l1, %o1
F00BE6C4: 3080009c                 ba,a    locret_F00BE934
F00BE6C8: 7ffffe15                 call    sub_F00BDF1C
F00BE6CC: 90100018                 mov     %i0, %o0
F00BE6D0: d0062040                 ld      [%i0+0x40], %o0
F00BE6D4: 80a22000                 cmp     %o0, 0
F00BE6D8: 2280000d                 be,a    loc_F00BE70C
F00BE6DC: d206200c                 ld      [%i0+0xC], %o1
F00BE6E0: d0062010                 ld      [%i0+0x10], %o0
F00BE6E4: aa056002                 inc     2, %l5
F00BE6E8: d206201c                 ld      [%i0+0x1C], %o1
F00BE6EC: 90023fe8                 inc     -0x18, %o0
F00BE6F0: d0262010                 st      %o0, [%i0+0x10]
F00BE6F4: 92026002                 inc     2, %o1
F00BE6F8: d0062020                 ld      [%i0+0x20], %o0
F00BE6FC: d226201c                 st      %o1, [%i0+0x1C]
F00BE700: 90022018                 inc     0x18, %o0
F00BE704: d0262020                 st      %o0, [%i0+0x20]
F00BE708: d206200c                 ld      [%i0+0xC], %o1
F00BE70C: c0262024                 clr     [%i0+0x24]
F00BE710: d4062010                 ld      [%i0+0x10], %o2
F00BE714: 90100018                 mov     %i0, %o0
F00BE718: d6062014                 ld      [%i0+0x14], %o3
F00BE71C: 98102016                 mov     0x16, %o4
F00BE720: da062034                 ld      [%i0+0x34], %o5
F00BE724: 7ffffe1b                 call    sub_F00BDF90
F00BE728: 972ae003                 sll     %o3, 3, %o3
F00BE72C: e4062010                 ld      [%i0+0x10], %l2
F00BE730: d2062014                 ld      [%i0+0x14], %o1
F00BE734: 90100018                 mov     %i0, %o0
F00BE738: e6062024                 ld      [%i0+0x24], %l3
F00BE73C: 9404a006                 add     %l2, 6, %o2
F00BE740: d4262010                 st      %o2, [%i0+0x10]
F00BE744: 92224011                 sub     %o1, %l1, %o1
F00BE748: 9532601f                 srl     %o1, 31, %o2
F00BE74C: 9202400a                 add     %o1, %o2, %o1
F00BE750: 933a6001                 sra     %o1, 1, %o1
F00BE754: d2262028                 st      %o1, [%i0+0x28]
F00BE758: 7ffffdf1                 call    sub_F00BDF1C
F00BE75C: a8100009                 mov     %o1, %l4
F00BE760: 10800008                 ba      loc_F00BE780
F00BE764: d04e4000                 ldsb    [%i1], %o0
F00BE768: b2066001                 inc     %i1
F00BE76C: 90100018                 mov     %i0, %o0
F00BE770: 932a6018                 sll     %o1, 24, %o1
F00BE774: 7ffffe7a                 call    sub_F00BE15C
F00BE778: 933a6018                 sra     %o1, 24, %o1
F00BE77C: d04e4000                 ldsb    [%i1], %o0
F00BE780: 80a22000                 cmp     %o0, 0
F00BE784: 12bffff9                 bne     loc_F00BE768
F00BE788: d20e4000                 ldub    [%i1], %o1
F00BE78C: 7ffffde4                 call    sub_F00BDF1C
F00BE790: 90100018                 mov     %i0, %o0
F00BE794: 90102000                 mov     0, %o0
F00BE798: 9207bff0                 add     %fp, var_10, %o1
F00BE79C: b2102000                 mov     0, %i1
F00BE7A0: 952ce001                 sll     %l3, 1, %o2
F00BE7A4: 94028013                 add     %o2, %l3, %o2
F00BE7A8: d6062010                 ld      [%i0+0x10], %o3
F00BE7AC: 952aa002                 sll     %o2, 2, %o2
F00BE7B0: 9602c00a                 add     %o3, %o2, %o3
F00BE7B4: d637bff2                 sth     %o3, [%fp+var_E]
F00BE7B8: d406200c                 ld      [%i0+0xC], %o2
F00BE7BC: 972d2003                 sll     %l4, 3, %o3
F00BE7C0: 9402800b                 add     %o2, %o3, %o2
F00BE7C4: d437bff0                 sth     %o2, [%fp+var_10]
F00BE7C8: 952c6003                 sll     %l1, 3, %o2
F00BE7CC: d437bff4                 sth     %o2, [%fp+var_C]
F00BE7D0: 9410200c                 mov     0xC, %o2
F00BE7D4: 40009ea2                 call    _sparcfbInvertRect
F00BE7D8: d437bff6                 sth     %o2, [%fp+var_A]
F00BE7DC: e4262010                 st      %l2, [%i0+0x10]
F00BE7E0: 90100018                 mov     %i0, %o0
F00BE7E4: da06203c                 ld      [%i0+0x3C], %o5
F00BE7E8: 9404bffe                 add     %l2, -2, %o2
F00BE7EC: d206200c                 ld      [%i0+0xC], %o1
F00BE7F0: 98102002                 mov     2, %o4
F00BE7F4: d6062018                 ld      [%i0+0x18], %o3
F00BE7F8: 92027ffe                 inc     -2, %o1
F00BE7FC: 7ffffde5                 call    sub_F00BDF90
F00BE800: 9602e004                 inc     4, %o3
F00BE804: da062038                 ld      [%i0+0x38], %o5
F00BE808: a0102017                 mov     0x17, %l0
F00BE80C: d206200c                 ld      [%i0+0xC], %o1
F00BE810: 90100018                 mov     %i0, %o0
F00BE814: d4062010                 ld      [%i0+0x10], %o2
F00BE818: 98102002                 mov     2, %o4
F00BE81C: d6062018                 ld      [%i0+0x18], %o3
F00BE820: 92027ffe                 inc     -2, %o1
F00BE824: 9402a013                 inc     0x13, %o2
F00BE828: 7ffffdda                 call    sub_F00BDF90
F00BE82C: 9602e004                 inc     4, %o3
F00BE830: 90100018                 mov     %i0, %o0
F00BE834: 96102001                 mov     1, %o3
F00BE838: 98100010                 mov     %l0, %o4
F00BE83C: a0043ffe                 inc     -2, %l0
F00BE840: da06203c                 ld      [%i0+0x3C], %o5
F00BE844: 84067ffe                 add     %i1, -2, %g2
F00BE848: d206200c                 ld      [%i0+0xC], %o1
F00BE84C: b2066001                 inc     %i1
F00BE850: d4062010                 ld      [%i0+0x10], %o2
F00BE854: 92024002                 add     %o1, %g2, %o1
F00BE858: 7ffffdce                 call    sub_F00BDF90
F00BE85C: 94028002                 add     %o2, %g2, %o2
F00BE860: 80a66001                 cmp     %i1, 1
F00BE864: 04bffff4                 ble     loc_F00BE834
F00BE868: 90100018                 mov     %i0, %o0
F00BE86C: b2102001                 mov     1, %i1
F00BE870: a2102002                 mov     2, %l1
F00BE874: a0102017                 mov     0x17, %l0
F00BE878: 96102001                 mov     1, %o3
F00BE87C: 98244019                 sub     %l1, %i1, %o4
F00BE880: d206200c                 ld      [%i0+0xC], %o1
F00BE884: 992b2001                 sll     %o4, 1, %o4
F00BE888: d4062018                 ld      [%i0+0x18], %o2
F00BE88C: 9824000c                 sub     %l0, %o4, %o4
F00BE890: da062038                 ld      [%i0+0x38], %o5
F00BE894: 9202400a                 add     %o1, %o2, %o1
F00BE898: 92024019                 add     %o1, %i1, %o1
F00BE89C: d4062010                 ld      [%i0+0x10], %o2
F00BE8A0: 92027fff                 inc     -1, %o1
F00BE8A4: 7ffffdbb                 call    sub_F00BDF90
F00BE8A8: 94228019                 sub     %o2, %i1, %o2
F00BE8AC: b2066001                 inc     %i1
F00BE8B0: 80a66002                 cmp     %i1, 2
F00BE8B4: 04bffff1                 ble     loc_F00BE878
F00BE8B8: 90100018                 mov     %i0, %o0
F00BE8BC: da062034                 ld      [%i0+0x34], %o5
F00BE8C0: d206200c                 ld      [%i0+0xC], %o1
F00BE8C4: d4062010                 ld      [%i0+0x10], %o2
F00BE8C8: 98102001                 mov     1, %o4
F00BE8CC: d6062018                 ld      [%i0+0x18], %o3
F00BE8D0: 92027ffd                 inc     -3, %o1
F00BE8D4: 9402a015                 inc     0x15, %o2
F00BE8D8: 7ffffdae                 call    sub_F00BDF90
F00BE8DC: 9602e006                 inc     6, %o3
F00BE8E0: ec262028                 st      %l6, [%i0+0x28]
F00BE8E4: d0062010                 ld      [%i0+0x10], %o0
F00BE8E8: 80a56000                 cmp     %l5, 0
F00BE8EC: d206201c                 ld      [%i0+0x1C], %o1
F00BE8F0: 90022018                 inc     0x18, %o0
F00BE8F4: d0262010                 st      %o0, [%i0+0x10]
F00BE8F8: 92027ffe                 inc     -2, %o1
F00BE8FC: d0062020                 ld      [%i0+0x20], %o0
F00BE900: d226201c                 st      %o1, [%i0+0x1C]
F00BE904: 90023fe8                 inc     -0x18, %o0
F00BE908: 04800005                 ble     loc_F00BE91C
F00BE90C: d0262020                 st      %o0, [%i0+0x20]
F00BE910: 90057ffe                 add     %l5, -2, %o0
F00BE914: 10800004                 ba      loc_F00BE924
F00BE918: d0262024                 st      %o0, [%i0+0x24]
F00BE91C: 7ffffdc7                 call    sub_F00BE038
F00BE920: 90100018                 mov     %i0, %o0
F00BE924: 7ffffd7e                 call    sub_F00BDF1C
F00BE928: 90100018                 mov     %i0, %o0
F00BE92C: 90102001                 mov     1, %o0
F00BE930: d0262040                 st      %o0, [%i0+0x40]
F00BE934: 81c7e008                 ret
F00BE938: 81e80000                 restore
