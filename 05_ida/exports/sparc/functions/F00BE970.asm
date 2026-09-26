F00BE970: 9de3bf88                 save    %sp, -0x78, %sp
F00BE974: 80a66000                 cmp     %i1, 0
F00BE978: 16800003                 bge     loc_F00BE984
F00BE97C: 90100019                 mov     %i1, %o0
F00BE980: 90066007                 add     %i1, 7, %o0
F00BE984: b33a2003                 sra     %o0, 3, %i1
F00BE988: 9010001a                 mov     %i2, %o0! int
F00BE98C: 7ffd1f1f                 call    _div
F00BE990: 9210200c                 mov     0xC, %o1
F00BE994: b4100008                 mov     %o0, %i2
F00BE998: b32e6003                 sll     %i1, 3, %i1
F00BE99C: 912ea001                 sll     %i2, 1, %o0
F00BE9A0: 9002001a                 add     %o0, %i2, %o0
F00BE9A4: d2060000                 ld      [%i0], %o1
F00BE9A8: b52a2002                 sll     %o0, 2, %i2
F00BE9AC: 90027ffa                 add     %o1, -6, %o0
F00BE9B0: 80a64008                 cmp     %i1, %o0
F00BE9B4: 38800002                 bgu,a   loc_F00BE9BC
F00BE9B8: b2100008                 mov     %o0, %i1
F00BE9BC: d0062004                 ld      [%i0+4], %o0
F00BE9C0: 90023ffa                 inc     -6, %o0
F00BE9C4: 80a68008                 cmp     %i2, %o0
F00BE9C8: 38800002                 bgu,a   loc_F00BE9D0
F00BE9CC: b4100008                 mov     %o0, %i2
F00BE9D0: 90224019                 sub     %o1, %i1, %o0
F00BE9D4: 91322001                 srl     %o0, 1, %o0
F00BE9D8: d026200c                 st      %o0, [%i0+0xC]
F00BE9DC: f2262018                 st      %i1, [%i0+0x18]
F00BE9E0: f4262020                 st      %i2, [%i0+0x20]
F00BE9E4: d4062004                 ld      [%i0+4], %o2
F00BE9E8: 90100018                 mov     %i0, %o0
F00BE9EC: d206200c                 ld      [%i0+0xC], %o1
F00BE9F0: 9422801a                 sub     %o2, %i2, %o2
F00BE9F4: 9532a001                 srl     %o2, 1, %o2
F00BE9F8: d4262010                 st      %o2, [%i0+0x10]
F00BE9FC: 920a7ff8                 and     %o1, -8, %o1
F00BEA00: 7fffffcf                 call    sub_F00BE93C
F00BEA04: d226200c                 st      %o1, [%i0+0xC]
F00BEA08: c0262028                 clr     [%i0+0x28]
F00BEA0C: 80a72000                 cmp     %i4, 0
F00BEA10: 0280006a                 be      loc_F00BEBB8
F00BEA14: c0262040                 clr     [%i0+0x40]
F00BEA18: 80a76000                 cmp     %i5, 0
F00BEA1C: 0280000f                 be      loc_F00BEA58
F00BEA20: 90102000                 mov     0, %o0
F00BEA24: d206200c                 ld      [%i0+0xC], %o1
F00BEA28: 92027ff6                 inc     -0xA, %o1
F00BEA2C: d237bfe8                 sth     %o1, [%fp+var_18]
F00BEA30: d4062010                 ld      [%i0+0x10], %o2
F00BEA34: 9207bfe8                 add     %fp, var_18, %o1
F00BEA38: 9402bff6                 inc     -0xA, %o2
F00BEA3C: d437bfea                 sth     %o2, [%fp+var_16]
F00BEA40: 94066014                 add     %i1, 0x14, %o2
F00BEA44: d437bfec                 sth     %o2, [%fp+var_14]
F00BEA48: 9406a018                 add     %i2, 0x18, %o2
F00BEA4C: 40009ccc                 call    _sparcfbSaveRect
F00BEA50: d437bfee                 sth     %o2, [%fp+var_12]
F00BEA54: d0262050                 st      %o0, [%i0+0x50]
F00BEA58: c0262024                 clr     [%i0+0x24]
F00BEA5C: c0262040                 clr     [%i0+0x40]
F00BEA60: 90100018                 mov     %i0, %o0
F00BEA64: a2066006                 add     %i1, 6, %l1
F00BEA68: da062034                 ld      [%i0+0x34], %o5
F00BEA6C: 96100011                 mov     %l1, %o3
F00BEA70: d206200c                 ld      [%i0+0xC], %o1
F00BEA74: 98102001                 mov     1, %o4
F00BEA78: d4062010                 ld      [%i0+0x10], %o2
F00BEA7C: 92027ffd                 inc     -3, %o1
F00BEA80: 7ffffd44                 call    sub_F00BDF90
F00BEA84: 9402bffd                 inc     -3, %o2
F00BEA88: 90100018                 mov     %i0, %o0
F00BEA8C: a0066004                 add     %i1, 4, %l0
F00BEA90: da062034                 ld      [%i0+0x34], %o5
F00BEA94: 96100010                 mov     %l0, %o3
F00BEA98: d206200c                 ld      [%i0+0xC], %o1
F00BEA9C: 98102002                 mov     2, %o4
F00BEAA0: d4062010                 ld      [%i0+0x10], %o2
F00BEAA4: 92027ffe                 inc     -2, %o1
F00BEAA8: 7ffffd3a                 call    sub_F00BDF90
F00BEAAC: 9402bffe                 inc     -2, %o2
F00BEAB0: 90100018                 mov     %i0, %o0
F00BEAB4: da062030                 ld      [%i0+0x30], %o5
F00BEAB8: 96100010                 mov     %l0, %o3
F00BEABC: d206200c                 ld      [%i0+0xC], %o1
F00BEAC0: 98102002                 mov     2, %o4
F00BEAC4: d4062010                 ld      [%i0+0x10], %o2
F00BEAC8: 92027ffe                 inc     -2, %o1
F00BEACC: 7ffffd31                 call    sub_F00BDF90
F00BEAD0: 9402801a                 add     %o2, %i2, %o2
F00BEAD4: 90100018                 mov     %i0, %o0
F00BEAD8: da062034                 ld      [%i0+0x34], %o5
F00BEADC: 96100011                 mov     %l1, %o3
F00BEAE0: d206200c                 ld      [%i0+0xC], %o1
F00BEAE4: 98102001                 mov     1, %o4
F00BEAE8: d4062010                 ld      [%i0+0x10], %o2
F00BEAEC: 92027ffd                 inc     -3, %o1
F00BEAF0: 9402801a                 add     %o2, %i2, %o2
F00BEAF4: 7ffffd27                 call    sub_F00BDF90
F00BEAF8: 9402a002                 inc     2, %o2
F00BEAFC: 90100018                 mov     %i0, %o0
F00BEB00: 96102001                 mov     1, %o3
F00BEB04: da062034                 ld      [%i0+0x34], %o5
F00BEB08: a206a006                 add     %i2, 6, %l1
F00BEB0C: d206200c                 ld      [%i0+0xC], %o1
F00BEB10: 98100011                 mov     %l1, %o4
F00BEB14: d4062010                 ld      [%i0+0x10], %o2
F00BEB18: 92027ffd                 inc     -3, %o1
F00BEB1C: 7ffffd1d                 call    sub_F00BDF90
F00BEB20: 9402bffd                 inc     -3, %o2
F00BEB24: 90100018                 mov     %i0, %o0
F00BEB28: 96102002                 mov     2, %o3
F00BEB2C: da062030                 ld      [%i0+0x30], %o5
F00BEB30: a006a004                 add     %i2, 4, %l0
F00BEB34: d206200c                 ld      [%i0+0xC], %o1
F00BEB38: 98100010                 mov     %l0, %o4
F00BEB3C: d4062010                 ld      [%i0+0x10], %o2
F00BEB40: 92027ffe                 inc     -2, %o1
F00BEB44: 7ffffd13                 call    sub_F00BDF90
F00BEB48: 9402bffe                 inc     -2, %o2
F00BEB4C: 90100018                 mov     %i0, %o0
F00BEB50: da062030                 ld      [%i0+0x30], %o5
F00BEB54: 96102002                 mov     2, %o3
F00BEB58: d206200c                 ld      [%i0+0xC], %o1
F00BEB5C: 98100010                 mov     %l0, %o4
F00BEB60: d4062010                 ld      [%i0+0x10], %o2
F00BEB64: 92024019                 add     %o1, %i1, %o1
F00BEB68: 7ffffd0a                 call    sub_F00BDF90
F00BEB6C: 9402bffe                 inc     -2, %o2
F00BEB70: 90100018                 mov     %i0, %o0
F00BEB74: d206200c                 ld      [%i0+0xC], %o1
F00BEB78: 96102001                 mov     1, %o3
F00BEB7C: da062034                 ld      [%i0+0x34], %o5
F00BEB80: 98100011                 mov     %l1, %o4
F00BEB84: d4062010                 ld      [%i0+0x10], %o2
F00BEB88: 92024019                 add     %o1, %i1, %o1
F00BEB8C: 92026002                 inc     2, %o1
F00BEB90: 7ffffd00                 call    sub_F00BDF90
F00BEB94: 9402bffd                 inc     -3, %o2
F00BEB98: 7ffffd19                 call    sub_F00BDFFC
F00BEB9C: 90100018                 mov     %i0, %o0
F00BEBA0: 7ffffcdf                 call    sub_F00BDF1C
F00BEBA4: 90100018                 mov     %i0, %o0
F00BEBA8: 90100018                 mov     %i0, %o0
F00BEBAC: 7ffffeb7                 call    sub_F00BE688
F00BEBB0: 9210001b                 mov     %i3, %o1
F00BEBB4: 3080000a                 ba,a    locret_F00BEBDC
F00BEBB8: 90100018                 mov     %i0, %o0
F00BEBBC: d406201c                 ld      [%i0+0x1C], %o2
F00BEBC0: 9210001b                 mov     %i3, %o1
F00BEBC4: 9402bfff                 inc     -1, %o2
F00BEBC8: 7ffffeb0                 call    sub_F00BE688
F00BEBCC: d4262024                 st      %o2, [%i0+0x24]
F00BEBD0: 90100018                 mov     %i0, %o0
F00BEBD4: 7ffffd62                 call    sub_F00BE15C
F00BEBD8: 9210200a                 mov     0xA, %o1
F00BEBDC: 81c7e008                 ret
F00BEBE0: 81e80000                 restore
