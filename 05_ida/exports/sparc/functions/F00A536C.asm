F00A536C: 9de3bf98                 save    %sp, -0x68, %sp
F00A5370: 113c0464                 sethi   %hi(_small_4m), %o0
F00A5374: d00222b0                 ld      [%o0+%lo(_small_4m)], %o0
F00A5378: 80a22000                 cmp     %o0, 0
F00A537C: 02800003                 be      loc_F00A5388
F00A5380: a0102004                 mov     4, %l0
F00A5384: a0102001                 mov     1, %l0
F00A5388: 7fffc5ed                 call    _splaudio
F00A538C: 01000000                 nop
F00A5390: 173c0466                 sethi   %hi(_clk_state), %o3
F00A5394: d202e108                 ld      [%o3+%lo(_clk_state)], %o1
F00A5398: b02e0009                 bclr    %o1, %i0
F00A539C: b20e4009                 and     %i1, %o1, %i1
F00A53A0: 941e0019                 xor     %i0, %i1, %o2
F00A53A4: 921a400a                 btog    %o2, %o1
F00A53A8: d222e108                 st      %o1, [%o3+%lo(_clk_state)]
F00A53AC: 13000200                 sethi   0x80000, %o1
F00A53B0: 808e4009                 btst    %o1, %i1
F00A53B4: 02800008                 be      loc_F00A53D4
F00A53B8: 84100008                 mov     %o0, %g2
F00A53BC: 173fbfe4                 sethi   -0x1007000, %o3
F00A53C0: 15000010                 sethi   0x4000, %o2
F00A53C4: d202c00a                 ld      [%o3+%o2], %o1
F00A53C8: 113c0466                 sethi   %hi(_clk10_limit), %o0
F00A53CC: d2222100                 st      %o1, [%o0+%lo(_clk10_limit)]
F00A53D0: c022c00a                 clr     [%o3+%o2]
F00A53D4: 808e6080                 btst    0x80, %i1
F00A53D8: 02800028                 be      loc_F00A5478
F00A53DC: 11000010                 sethi   0x4000, %o0
F00A53E0: 94102000                 mov     0, %o2
F00A53E4: 173fbfe4                 sethi   -0x1007000, %o3
F00A53E8: 90122010                 bset    0x10, %o0
F00A53EC: d202c008                 ld      [%o3+%o0], %o1
F00A53F0: 80a28010                 cmp     %o2, %l0
F00A53F4: 113c0466                 sethi   %hi(_clk14_config), %o0
F00A53F8: 1680000f                 bge     loc_F00A5434
F00A53FC: d2222104                 st      %o1, [%o0+%lo(_clk14_config)]
F00A5400: 113c04f99a122260         set     _clk14_lim, %o5
F00A5408: 9810000b                 mov     %o3, %o4
F00A540C: 96102000                 mov     0, %o3
F00A5410: 92102000                 mov     0, %o1
F00A5414: 9402a001                 inc     %o2
F00A5418: d002c00c                 ld      [%o3+%o4], %o0
F00A541C: 80a28010                 cmp     %o2, %l0
F00A5420: d022400d                 st      %o0, [%o1+%o5]
F00A5424: 11000004                 sethi   0x1000, %o0
F00A5428: 9602c008                 add     %o3, %o0, %o3
F00A542C: 06bffffa                 bl      loc_F00A5414
F00A5430: 92026004                 inc     4, %o1
F00A5434: 193fbfe4                 sethi   -0x1007000, %o4
F00A5438: 1100001090122010         set     0x4010, %o0
F00A5440: 9210200f                 mov     0xF, %o1
F00A5444: 94102000                 mov     0, %o2
F00A5448: 80a28010                 cmp     %o2, %l0
F00A544C: 1680000b                 bge     loc_F00A5478
F00A5450: d2230008                 st      %o1, [%o4+%o0]
F00A5454: 1710a400                 sethi   0x42900000, %o3
F00A5458: 9210000c                 mov     %o4, %o1
F00A545C: c0226004                 clr     [%o1+4]
F00A5460: d6224000                 st      %o3, [%o1]
F00A5464: 11000004                 sethi   0x1000, %o0
F00A5468: 9402a001                 inc     %o2
F00A546C: 80a28010                 cmp     %o2, %l0
F00A5470: 06bffffb                 bl      loc_F00A545C
F00A5474: 92024008                 add     %o1, %o0, %o1
F00A5478: 90102000                 mov     0, %o0
F00A547C: 80a20010                 cmp     %o0, %l0
F00A5480: 36800007                 bge,a   loc_F00A549C
F00A5484: 11000200                 sethi   0x80000, %o0
F00A5488: 90022001                 inc     %o0
F00A548C: 80a20010                 cmp     %o0, %l0
F00A5490: 06bfffff                 bl      loc_F00A548C
F00A5494: 90022001                 inc     %o0
F00A5498: 11000200                 sethi   0x80000, %o0
F00A549C: 808e0008                 btst    %o0, %i0
F00A54A0: 02800006                 be      loc_F00A54B8
F00A54A4: 113c0466                 sethi   %hi(_clk10_limit), %o0
F00A54A8: d2022100                 ld      [%o0+%lo(_clk10_limit)], %o1
F00A54AC: 153fbfe4                 sethi   -0x1007000, %o2
F00A54B0: 11000010                 sethi   0x4000, %o0
F00A54B4: d2228008                 st      %o1, [%o2+%o0]
F00A54B8: 808e2080                 btst    0x80, %i0
F00A54BC: 02800017                 be      loc_F00A5518
F00A54C0: 94102000                 mov     0, %o2
F00A54C4: 80a28010                 cmp     %o2, %l0
F00A54C8: 173fbfe4                 sethi   -0x1007000, %o3
F00A54CC: 11000010                 sethi   0x4000, %o0
F00A54D0: 133c0466                 sethi   %hi(_clk14_config), %o1
F00A54D4: d2026104                 ld      [%o1+%lo(_clk14_config)], %o1
F00A54D8: 90122010                 bset    0x10, %o0
F00A54DC: 1680000f                 bge     loc_F00A5518
F00A54E0: d222c008                 st      %o1, [%o3+%o0]
F00A54E4: 9a10000b                 mov     %o3, %o5
F00A54E8: 113c04f998122260         set     _clk14_lim, %o4
F00A54F0: 96102000                 mov     0, %o3
F00A54F4: 92102000                 mov     0, %o1
F00A54F8: 9402a001                 inc     %o2
F00A54FC: d002c00c                 ld      [%o3+%o4], %o0
F00A5500: 80a28010                 cmp     %o2, %l0
F00A5504: d022400d                 st      %o0, [%o1+%o5]
F00A5508: 9602e004                 inc     4, %o3
F00A550C: 11000004                 sethi   0x1000, %o0
F00A5510: 06bffffa                 bl      loc_F00A54F8
F00A5514: 92024008                 add     %o1, %o0, %o1
F00A5518: 7fffc603                 call    _splx
F00A551C: 90100002                 mov     %g2, %o0
F00A5520: 81c7e008                 ret
F00A5524: 81e80000                 restore
