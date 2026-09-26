F006B130: 9de3bf48                 save    %sp, -0xB8, %sp
F006B134: a2100018                 mov     %i0, %l1
F006B138: d0046008                 ld      [%l1+8], %o0
F006B13C: 96044008                 add     %l1, %o0, %o3
F006B140: d0046004                 ld      [%l1+4], %o0
F006B144: 9210000b                 mov     %o3, %o1
F006B148: 94044008                 add     %l1, %o0, %o2
F006B14C: 80a2400a                 cmp     %o1, %o2
F006B150: 1a800028                 bcc     locret_F006B1F0
F006B154: b0102002                 mov     2, %i0
F006B158: d04a4000                 ldsb    [%o1], %o0
F006B15C: 80a22000                 cmp     %o0, 0
F006B160: 12bffffb                 bne     loc_F006B14C
F006B164: 92026001                 inc     %o1
F006B168: 9010000b                 mov     %o3, %o0
F006B16C: a407bfd8                 add     %fp, var_28, %l2
F006B170: 92100012                 mov     %l2, %o1
F006B174: 9407bfbc                 add     %fp, var_44, %o2! __len
F006B178: 9607bfb8                 add     %fp, var_48, %o3
F006B17C: 40000094                 call    sub_F006B3CC
F006B180: 9807bfb4                 add     %fp, var_4C, %o4
F006B184: b0920000                 orcc    %o0, %g0, %i0
F006B188: 1280001a                 bne     locret_F006B1F0
F006B18C: a007bfc0                 add     %fp, __b, %l0
F006B190: 90100010                 mov     %l0, %o0! __b
F006B194: 92102000                 mov     0, %o1! __c
F006B198: 7ffe6c79                 call    _memset
F006B19C: 94102014                 mov     0x14, %o2
F006B1A0: c027bfc0                 clr     [%fp+__b]
F006B1A4: d007bfb4                 ld      [%fp+var_4C], %o0
F006B1A8: 92100019                 mov     %i1, %o1
F006B1AC: d607bfbc                 ld      [%fp+var_44], %o3
F006B1B0: 94100012                 mov     %l2, %o2
F006B1B4: d807bfb8                 ld      [%fp+var_48], %o4
F006B1B8: 9a07bfb0                 add     %fp, var_50, %o5
F006B1BC: da23a05c                 st      %o5, [%sp+0xB8+var_5C]
F006B1C0: e023a060                 st      %l0, [%sp+0xB8+var_58]
F006B1C4: 7ffffd9e                 call    sub_F006A83C
F006B1C8: 9a10001a                 mov     %i2, %o5
F006B1CC: b0920000                 orcc    %o0, %g0, %i0
F006B1D0: 12800006                 bne     loc_F006B1E8
F006B1D4: d207bfb0                 ld      [%fp+var_50], %o1
F006B1D8: d004600c                 ld      [%l1+0xC], %o0
F006B1DC: 80a24008                 cmp     %o1, %o0
F006B1E0: 2a800002                 bcs,a   loc_F006B1E8
F006B1E4: b0102003                 mov     3, %i0
F006B1E8: 7ffef65f                 call    _vn_rele
F006B1EC: d007bfb4                 ld      [%fp+var_4C], %o0
F006B1F0: 81c7e008                 ret
F006B1F4: 81e80000                 restore
