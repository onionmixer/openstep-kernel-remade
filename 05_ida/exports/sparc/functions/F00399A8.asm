F00399A8: 9de3bf90                 save    %sp, -0x70, %sp
F00399AC: 90100018                 mov     %i0, %o0
F00399B0: 7fffffa2                 call    sub_F0039838
F00399B4: 92100019                 mov     %i1, %o1
F00399B8: 80a22000                 cmp     %o0, 0
F00399BC: 02800004                 be      loc_F00399CC
F00399C0: 90100018                 mov     %i0, %o0
F00399C4: 10800014                 ba      loc_F0039A14
F00399C8: b4102000                 mov     0, %i2
F00399CC: 92100019                 mov     %i1, %o1
F00399D0: 7fffffc7                 call    _nfs_getattr_otw
F00399D4: 9410001a                 mov     %i2, %o2
F00399D8: b4920000                 orcc    %o0, %g0, %i2
F00399DC: 3280000f                 bne,a   loc_F0039A18
F00399E0: d0062030                 ld      [%i0+0x30], %o0
F00399E4: d2066028                 ld      [%i1+0x28], %o1
F00399E8: 90100018                 mov     %i0, %o0
F00399EC: d227bff0                 st      %o1, [%fp+var_10]
F00399F0: d406602c                 ld      [%i1+0x2C], %o2
F00399F4: 9610001b                 mov     %i3, %o3
F00399F8: d427bff4                 st      %o2, [%fp+var_C]
F00399FC: d4066018                 ld      [%i1+0x18], %o2
F0039A00: 7fffff25                 call    _nfs_cache_check
F0039A04: 9207bff0                 add     %fp, var_10, %o1
F0039A08: 90100018                 mov     %i0, %o0
F0039A0C: 7fffff4e                 call    _nfs_attrcache_va
F0039A10: 92100019                 mov     %i1, %o1
F0039A14: d0062030                 ld      [%i0+0x30], %o0
F0039A18: d0022098                 ld      [%o0+0x98], %o0
F0039A1C: d0266018                 st      %o0, [%i1+0x18]
F0039A20: 81c7e008                 ret
F0039A24: 91e8001a                 restore %g0, %i2, %o0
