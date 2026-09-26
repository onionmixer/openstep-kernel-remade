F00E31DC: 9de3bf90                 save    %sp, -0x70, %sp
F00E31E0: d2062004                 ld      [%i0+4], %o1
F00E31E4: 80a2606c                 cmp     %o1, 0x6C ! 'l'
F00E31E8: 12800005                 bne     loc_F00E31FC
F00E31EC: d00e2003                 ldub    [%i0+3], %o0
F00E31F0: 80a22001                 cmp     %o0, 1
F00E31F4: 22800005                 be,a    loc_F00E3208
F00E31F8: d0062018                 ld      [%i0+0x18], %o0
F00E31FC: 90103ed0                 mov     -0x130, %o0
F00E3200: 10800030                 ba      locret_F00E32C0
F00E3204: d026601c                 st      %o0, [%i1+0x1C]
F00E3208: 133c03e6                 sethi   %hi(dword_F00F9A04), %o1
F00E320C: d2026204                 ld      [%o1+%lo(dword_F00F9A04)], %o1
F00E3210: 80a20009                 cmp     %o0, %o1
F00E3214: 12800017                 bne     loc_F00E3270
F00E3218: 90103ed0                 mov     -0x130, %o0
F00E321C: d0062020                 ld      [%i0+0x20], %o0
F00E3220: 133c03e6                 sethi   %hi(dword_F00F9A08), %o1
F00E3224: d2026208                 ld      [%o1+%lo(dword_F00F9A08)], %o1
F00E3228: 80a20009                 cmp     %o0, %o1
F00E322C: 12800011                 bne     loc_F00E3270
F00E3230: 90103ed0                 mov     -0x130, %o0
F00E3234: d0062064                 ld      [%i0+0x64], %o0
F00E3238: 133c03e6                 sethi   %hi(dword_F00F9A0C), %o1
F00E323C: d202620c                 ld      [%o1+%lo(dword_F00F9A0C)], %o1
F00E3240: 80a20009                 cmp     %o0, %o1
F00E3244: 1280000b                 bne     loc_F00E3270
F00E3248: 90103ed0                 mov     -0x130, %o0
F00E324C: 11000004                 sethi   0x1000, %o0
F00E3250: d027bff4                 st      %o0, [%fp+var_C]
F00E3254: d006200c                 ld      [%i0+0xC], %o0
F00E3258: 94062024                 add     %i0, 0x24, %o2 ! '$'
F00E325C: d206201c                 ld      [%i0+0x1C], %o1
F00E3260: 9806602c                 add     %i1, 0x2C, %o4 ! ','
F00E3264: d6062068                 ld      [%i0+0x68], %o3
F00E3268: 7fffc844                 call    _EvGetParameterChar
F00E326C: 9a07bff4                 add     %fp, var_C, %o5
F00E3270: d026601c                 st      %o0, [%i1+0x1C]
F00E3274: d006601c                 ld      [%i1+0x1C], %o0
F00E3278: 80a22000                 cmp     %o0, 0
F00E327C: 12800011                 bne     locret_F00E32C0
F00E3280: 113c03e6                 sethi   %hi(dword_F00F9A10), %o0
F00E3284: d2022210                 ld      [%o0+%lo(dword_F00F9A10)], %o1
F00E3288: 90122210                 bset    %lo(dword_F00F9A10), %o0
F00E328C: d4022004                 ld      [%o0+4], %o2
F00E3290: d2266020                 st      %o1, [%i1+0x20]
F00E3294: d2022008                 ld      [%o0+8], %o1
F00E3298: d4266024                 st      %o2, [%i1+0x24]
F00E329C: d007bff4                 ld      [%fp+var_C], %o0
F00E32A0: d2266028                 st      %o1, [%i1+0x28]
F00E32A4: d0266028                 st      %o0, [%i1+0x28]
F00E32A8: 90022003                 inc     3, %o0
F00E32AC: 900a3ffc                 and     %o0, -4, %o0
F00E32B0: 9202202c                 add     %o0, 0x2C, %o1 ! ','
F00E32B4: 90102001                 mov     1, %o0
F00E32B8: d02e6003                 stb     %o0, [%i1+3]
F00E32BC: d2266004                 st      %o1, [%i1+4]
F00E32C0: 81c7e008                 ret
F00E32C4: 81e80000                 restore
