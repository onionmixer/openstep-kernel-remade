F0020880: 9de3bf98                 save    %sp, -0x68, %sp
F0020884: 80a6a000                 cmp     %i2, 0
F0020888: 12800005                 bne     loc_F002089C
F002088C: a0102000                 mov     0, %l0
F0020890: 113c042f                 sethi   %hi(aSbappendrights), %o0! "sbappendrights"
F0020894: 7fffd237                 call    _panic
F0020898: 901220a0                 bset    %lo(aSbappendrights), %o0! "sbappendrights"
F002089C: 94964000                 orcc    %i1, %g0, %o2
F00208A0: 22800008                 be,a    loc_F00208C0
F00208A4: d856a008                 ldsh    [%i2+8], %o4
F00208A8: d052a008                 ldsh    [%o2+8], %o0
F00208AC: d4028000                 ld      [%o2], %o2
F00208B0: 80a2a000                 cmp     %o2, 0
F00208B4: 12bffffd                 bne     loc_F00208A8
F00208B8: a0040008                 add     %l0, %o0, %l0
F00208BC: d856a008                 ldsh    [%i2+8], %o4
F00208C0: d6162006                 lduh    [%i0+6], %o3
F00208C4: d4162002                 lduh    [%i0+2], %o2
F00208C8: d2160000                 lduh    [%i0], %o1
F00208CC: d0162004                 lduh    [%i0+4], %o0
F00208D0: 94228009                 sub     %o2, %o1, %o2
F00208D4: 9622c008                 sub     %o3, %o0, %o3
F00208D8: 80a2800b                 cmp     %o2, %o3
F00208DC: 04800003                 ble     loc_F00208E8
F00208E0: a004000c                 add     %l0, %o4, %l0
F00208E4: 9410000b                 mov     %o3, %o2
F00208E8: 80a4000a                 cmp     %l0, %o2
F00208EC: 34800027                 bg,a    locret_F0020988
F00208F0: b0102000                 mov     0, %i0
F00208F4: 9010001a                 mov     %i2, %o0
F00208F8: 92102000                 mov     0, %o1
F00208FC: 7ffff512                 call    _m_copy
F0020900: 9410000c                 mov     %o4, %o2
F0020904: 94920000                 orcc    %o0, %g0, %o2
F0020908: 32800004                 bne,a   loc_F0020918
F002090C: d2160000                 lduh    [%i0], %o1
F0020910: 1080001e                 ba      locret_F0020988
F0020914: b0102000                 mov     0, %i0
F0020918: d012a008                 lduh    [%o2+8], %o0
F002091C: 92024008                 add     %o1, %o0, %o1
F0020920: d0162004                 lduh    [%i0+4], %o0
F0020924: d2360000                 sth     %o1, [%i0]
F0020928: 92022080                 add     %o0, 0x80, %o1
F002092C: d2362004                 sth     %o1, [%i0+4]
F0020930: d002a004                 ld      [%o2+4], %o0
F0020934: 80a2207c                 cmp     %o0, 0x7C ! '|'
F0020938: 08800003                 bleu    loc_F0020944
F002093C: 90026400                 add     %o1, 0x400, %o0
F0020940: d0362004                 sth     %o0, [%i0+4]
F0020944: d206200c                 ld      [%i0+0xC], %o1
F0020948: 80a26000                 cmp     %o1, 0
F002094C: 22800009                 be,a    loc_F0020970
F0020950: d426200c                 st      %o2, [%i0+0xC]
F0020954: 10800003                 ba      loc_F0020960
F0020958: d002607c                 ld      [%o1+0x7C], %o0
F002095C: d002607c                 ld      [%o1+0x7C], %o0
F0020960: 80a22000                 cmp     %o0, 0
F0020964: 32bffffe                 bne,a   loc_F002095C
F0020968: d202607c                 ld      [%o1+0x7C], %o1
F002096C: d422607c                 st      %o2, [%o1+0x7C]
F0020970: 80a66000                 cmp     %i1, 0
F0020974: 02800004                 be      loc_F0020984
F0020978: 90100018                 mov     %i0, %o0
F002097C: 40000005                 call    _sbcompress
F0020980: 92100019                 mov     %i1, %o1
F0020984: b0102001                 mov     1, %i0
F0020988: 81c7e008                 ret
F002098C: 81e80000                 restore
