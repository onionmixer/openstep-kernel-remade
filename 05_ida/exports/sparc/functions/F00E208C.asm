F00E208C: 9de3bf98                 save    %sp, -0x68, %sp
F00E2090: 9210001b                 mov     %i3, %o1
F00E2094: 80a6a000                 cmp     %i2, 0
F00E2098: 12800004                 bne     loc_F00E20A8
F00E209C: b6102000                 mov     0, %i3
F00E20A0: 1080008f                 ba      locret_F00E22DC
F00E20A4: b0102000                 mov     0, %i0
F00E20A8: 80a72000                 cmp     %i4, 0
F00E20AC: 02800019                 be      loc_F00E2110
F00E20B0: 80a26003                 cmp     %o1, 3
F00E20B4: 12800012                 bne     loc_F00E20FC
F00E20B8: 90100018                 mov     %i0, %o0
F00E20BC: 9406bfff                 add     %i2, -1, %o2
F00E20C0: 80a2bfff                 cmp     %o2, -1
F00E20C4: 22800086                 be,a    locret_F00E22DC
F00E20C8: b010001b                 mov     %i3, %i0
F00E20CC: 9402bfff                 inc     -1, %o2! size_t
F00E20D0: d20e0000                 ldub    [%i0], %o1
F00E20D4: 80a2bfff                 cmp     %o2, -1
F00E20D8: 901a7f80                 xor     %o1, -0x80, %o0
F00E20DC: 920a607f                 and     %o1, 0x7F, %o1
F00E20E0: 90120009                 bset    %o1, %o0! void *
F00E20E4: d02e4000                 stb     %o0, [%i1]
F00E20E8: b2066001                 inc     %i1
F00E20EC: 12bffff8                 bne     loc_F00E20CC
F00E20F0: b0062001                 inc     %i0
F00E20F4: 1080007a                 ba      locret_F00E22DC
F00E20F8: b010001b                 mov     %i3, %i0
F00E20FC: 92100019                 mov     %i1, %o1! void *
F00E2100: 7ffeca84                 call    _bcopy
F00E2104: 9410001a                 mov     %i2, %o2
F00E2108: 10800075                 ba      locret_F00E22DC
F00E210C: b010001b                 mov     %i3, %i0
F00E2110: 80a26001                 cmp     %o1, 1
F00E2114: 2280004a                 be,a    loc_F00E223C
F00E2118: b406bfff                 inc     -1, %i2
F00E211C: 14800007                 bg      loc_F00E2138
F00E2120: 80a26003                 cmp     %o1, 3
F00E2124: 80a26000                 cmp     %o1, 0
F00E2128: 02800008                 be      loc_F00E2148
F00E212C: b536a001                 srl     %i2, 1, %i2
F00E2130: 10800068                 ba      loc_F00E22D0
F00E2134: 113c03f2                 sethi   -0xFF03800, %o0
F00E2138: 02800020                 be      loc_F00E21B8
F00E213C: b406bfff                 inc     -1, %i2
F00E2140: 10800064                 ba      loc_F00E22D0
F00E2144: 113c03f2                 sethi   -0xFF03800, %o0
F00E2148: b406bfff                 inc     -1, %i2
F00E214C: 80a6bfff                 cmp     %i2, -1
F00E2150: 02800062                 be      loc_F00E22D8
F00E2154: 153fffe0                 sethi   -0x8000, %o2
F00E2158: 1100001f961223ff         set     0x7FFF, %o3
F00E2160: d2564000                 ldsh    [%i1], %o1
F00E2164: d0560000                 ldsh    [%i0], %o0
F00E2168: 92024008                 add     %o1, %o0, %o1
F00E216C: 80a2400b                 cmp     %o1, %o3
F00E2170: 04800004                 ble     loc_F00E2180
F00E2174: b0062002                 inc     2, %i0
F00E2178: 10800006                 ba      loc_F00E2190
F00E217C: d6364000                 sth     %o3, [%i1]
F00E2180: 80a2400a                 cmp     %o1, %o2
F00E2184: 36800006                 bge,a   loc_F00E219C
F00E2188: d2364000                 sth     %o1, [%i1]
F00E218C: d4364000                 sth     %o2, [%i1]
F00E2190: b2066002                 inc     2, %i1
F00E2194: 10800003                 ba      loc_F00E21A0
F00E2198: b606e001                 inc     %i3
F00E219C: b2066002                 inc     2, %i1
F00E21A0: b406bfff                 inc     -1, %i2
F00E21A4: 80a6bfff                 cmp     %i2, -1
F00E21A8: 32bfffef                 bne,a   loc_F00E2164
F00E21AC: d2564000                 ldsh    [%i1], %o1
F00E21B0: 1080004b                 ba      locret_F00E22DC
F00E21B4: b010001b                 mov     %i3, %i0
F00E21B8: 80a6bfff                 cmp     %i2, -1
F00E21BC: 02800047                 be      loc_F00E22D8
F00E21C0: 94103fff                 mov     -1, %o2
F00E21C4: d00e4000                 ldub    [%i1], %o0
F00E21C8: 921a3f80                 xor     %o0, -0x80, %o1
F00E21CC: 900a207f                 and     %o0, 0x7F, %o0
F00E21D0: 92124008                 bset    %o0, %o1
F00E21D4: 932a6018                 sll     %o1, 24, %o1
F00E21D8: d04e0000                 ldsb    [%i0], %o0
F00E21DC: 933a6018                 sra     %o1, 24, %o1
F00E21E0: 92024008                 add     %o1, %o0, %o1
F00E21E4: 80a2607f                 cmp     %o1, 0x7F
F00E21E8: 04800004                 ble     loc_F00E21F8
F00E21EC: b0062001                 inc     %i0
F00E21F0: 10800006                 ba      loc_F00E2208
F00E21F4: d42e4000                 stb     %o2, [%i1]
F00E21F8: 80a27f80                 cmp     %o1, -0x80
F00E21FC: 16800006                 bge     loc_F00E2214
F00E2200: 901a7f80                 xor     %o1, -0x80, %o0
F00E2204: c02e4000                 clrb    [%i1]
F00E2208: b2066001                 inc     %i1
F00E220C: 10800006                 ba      loc_F00E2224
F00E2210: b606e001                 inc     %i3
F00E2214: 920a607f                 and     %o1, 0x7F, %o1
F00E2218: 90120009                 bset    %o1, %o0
F00E221C: d02e4000                 stb     %o0, [%i1]
F00E2220: b2066001                 inc     %i1
F00E2224: b406bfff                 inc     -1, %i2
F00E2228: 80a6bfff                 cmp     %i2, -1
F00E222C: 32bfffe7                 bne,a   loc_F00E21C8
F00E2230: d00e4000                 ldub    [%i1], %o0
F00E2234: 1080002a                 ba      locret_F00E22DC
F00E2238: b010001b                 mov     %i3, %i0
F00E223C: 80a6bfff                 cmp     %i2, -1
F00E2240: 02800026                 be      loc_F00E22D8
F00E2244: a2102080                 mov     0x80, %l1
F00E2248: 113c03e5b81223c4         set     _audio_muLaw, %i4
F00E2250: 1100001fa41223ff         set     0x7FFF, %l2
F00E2258: 213fffe0                 sethi   -0x8000, %l0
F00E225C: d00e4000                 ldub    [%i1], %o0
F00E2260: d20e0000                 ldub    [%i0], %o1
F00E2264: 912a2001                 sll     %o0, 1, %o0
F00E2268: d452001c                 ldsh    [%o0+%i4], %o2
F00E226C: 932a6001                 sll     %o1, 1, %o1
F00E2270: d052401c                 ldsh    [%o1+%i4], %o0
F00E2274: 92028008                 add     %o2, %o0, %o1
F00E2278: 80a24012                 cmp     %o1, %l2
F00E227C: 04800004                 ble     loc_F00E228C
F00E2280: b0062001                 inc     %i0
F00E2284: 10800006                 ba      loc_F00E229C
F00E2288: e22e4000                 stb     %l1, [%i1]
F00E228C: 80a24010                 cmp     %o1, %l0
F00E2290: 16800006                 bge     loc_F00E22A8
F00E2294: 912a6010                 sll     %o1, 16, %o0
F00E2298: c02e4000                 clrb    [%i1]
F00E229C: b2066001                 inc     %i1
F00E22A0: 10800006                 ba      loc_F00E22B8
F00E22A4: b606e001                 inc     %i3
F00E22A8: 40000156                 call    _audio_shortToMulaw
F00E22AC: 913a2010                 sra     %o0, 16, %o0
F00E22B0: d02e4000                 stb     %o0, [%i1]
F00E22B4: b2066001                 inc     %i1
F00E22B8: b406bfff                 inc     -1, %i2
F00E22BC: 80a6bfff                 cmp     %i2, -1
F00E22C0: 32bfffe8                 bne,a   loc_F00E2260
F00E22C4: d00e4000                 ldub    [%i1], %o0
F00E22C8: 10800005                 ba      locret_F00E22DC
F00E22CC: b010001b                 mov     %i3, %i0
F00E22D0: 7fff8f89                 call    _IOLog
F00E22D4: 90122268                 bset    0x268, %o0
F00E22D8: b010001b                 mov     %i3, %i0
F00E22DC: 81c7e008                 ret
F00E22E0: 81e80000                 restore
