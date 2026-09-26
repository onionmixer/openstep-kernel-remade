F00F20EC: 9de3bf98                 save    %sp, -0x68, %sp
F00F20F0: 7fffff05                 call    _objc_getClass
F00F20F4: d0062004                 ld      [%i0+4], %o0
F00F20F8: 94920000                 orcc    %o0, %g0, %o2
F00F20FC: 2280002d                 be,a    loc_F00F21B0
F00F2100: 113c03f4                 sethi   -0xFF03000, %o0
F00F2104: d2062008                 ld      [%i0+8], %o1
F00F2108: 80a26000                 cmp     %o1, 0
F00F210C: 22800007                 be,a    loc_F00F2128
F00F2110: d206200c                 ld      [%i0+0xC], %o1
F00F2114: d002a01c                 ld      [%o2+0x1C], %o0
F00F2118: d0224000                 st      %o0, [%o1]
F00F211C: d0062008                 ld      [%i0+8], %o0
F00F2120: d022a01c                 st      %o0, [%o2+0x1C]
F00F2124: d206200c                 ld      [%i0+0xC], %o1
F00F2128: 80a26000                 cmp     %o1, 0
F00F212C: 02800008                 be      loc_F00F214C
F00F2130: 80a66004                 cmp     %i1, 4
F00F2134: d0028000                 ld      [%o2], %o0
F00F2138: d002201c                 ld      [%o0+0x1C], %o0
F00F213C: d0224000                 st      %o0, [%o1]
F00F2140: d2028000                 ld      [%o2], %o1
F00F2144: d006200c                 ld      [%i0+0xC], %o0
F00F2148: d022601c                 st      %o0, [%o1+0x1C]
F00F214C: 04800020                 ble     loc_F00F21CC
F00F2150: 01000000                 nop
F00F2154: d2062010                 ld      [%i0+0x10], %o1
F00F2158: 80a26000                 cmp     %o1, 0
F00F215C: 0280001c                 be      loc_F00F21CC
F00F2160: 01000000                 nop
F00F2164: d0028000                 ld      [%o2], %o0
F00F2168: d002200c                 ld      [%o0+0xC], %o0
F00F216C: 80a22004                 cmp     %o0, 4
F00F2170: 0480000a                 ble     loc_F00F2198
F00F2174: 113c03f4                 sethi   -0xFF03000, %o0
F00F2178: d002a024                 ld      [%o2+0x24], %o0
F00F217C: d0224000                 st      %o0, [%o1]
F00F2180: d0062010                 ld      [%i0+0x10], %o0
F00F2184: d022a024                 st      %o0, [%o2+0x24]
F00F2188: d2028000                 ld      [%o2], %o1
F00F218C: d0062010                 ld      [%i0+0x10], %o0
F00F2190: 1080000f                 ba      loc_F00F21CC
F00F2194: d0226024                 st      %o0, [%o1+0x24]
F00F2198: 90122338                 bset    0x338, %o0
F00F219C: 7ffffa25                 call    __objc_inform
F00F21A0: d2060000                 ld      [%i0], %o1
F00F21A4: 113c03f4                 sethi   %hi(aClassSMustBeRe_0), %o0! "class `%s' must be recompiled\n"
F00F21A8: 10800007                 ba      loc_F00F21C4
F00F21AC: 90122368                 bset    %lo(aClassSMustBeRe_0), %o0! "class `%s' must be recompiled\n"
F00F21B0: 90122388                 bset    0x388, %o0
F00F21B4: 7ffffa1f                 call    __objc_inform
F00F21B8: d2060000                 ld      [%i0], %o1
F00F21BC: 113c03f490122310         set     aClassSNotLinke_0, %o0! "class `%s' not linked into application"...
F00F21C4: 7ffffa1b                 call    __objc_inform
F00F21C8: d2062004                 ld      [%i0+4], %o1
F00F21CC: 7ffffece                 call    _objc_getClass
F00F21D0: d0062004                 ld      [%i0+4], %o0! cls
F00F21D4: 7ffff4df                 call    __objc_flush_caches
F00F21D8: 01000000                 nop
F00F21DC: 81c7e008                 ret
F00F21E0: 81e80000                 restore
