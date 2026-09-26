F004D864: 9de3bf98                 save    %sp, -0x68, %sp
F004D868: 7ffffe2d                 call    sub_F004D11C
F004D86C: 90100018                 mov     %i0, %o0
F004D870: d006200c                 ld      [%i0+0xC], %o0
F004D874: 80a22000                 cmp     %o0, 0
F004D878: 16800008                 bge     loc_F004D898
F004D87C: 133c04eb                 sethi   %hi(dword_F013AD90), %o1
F004D880: d4026190                 ld      [%o1+%lo(dword_F013AD90)], %o2
F004D884: 90100018                 mov     %i0, %o0
F004D888: 9fc28000                 call    %o2
F004D88C: 92100019                 mov     %i1, %o1
F004D890: 1080006c                 ba      locret_F004DA40
F004D894: b0100008                 mov     %o0, %i0
F004D898: 400124c8                 call    _spltty
F004D89C: a0062024                 add     %i0, 0x24, %l0 ! '$'
F004D8A0: a4100008                 mov     %o0, %l2
F004D8A4: d0040000                 ld      [%l0], %o0
F004D8A8: 80a22000                 cmp     %o0, 0
F004D8AC: 12bffffe                 bne     loc_F004D8A4
F004D8B0: 01000000                 nop
F004D8B4: 4001257d                 call    _simple_lock_try
F004D8B8: 90100010                 mov     %l0, %o0
F004D8BC: 80a22000                 cmp     %o0, 0
F004D8C0: 02bffff9                 be      loc_F004D8A4
F004D8C4: 92062010                 add     %i0, 0x10, %o1
F004D8C8: d0062010                 ld      [%i0+0x10], %o0
F004D8CC: 80a24008                 cmp     %o1, %o0
F004D8D0: 12800007                 bne     loc_F004D8EC
F004D8D4: 94100008                 mov     %o0, %o2
F004D8D8: c0262024                 clr     [%i0+0x24]
F004D8DC: 40012512                 call    _splx
F004D8E0: 90100012                 mov     %l2, %o0
F004D8E4: 10800057                 ba      locret_F004DA40
F004D8E8: b0102000                 mov     0, %i0
F004D8EC: 113bffff961223ff         set     -0x10000001, %o3
F004D8F4: e0028000                 ld      [%o2], %l0
F004D8F8: 80a40019                 cmp     %l0, %i1
F004D8FC: 12800011                 bne     loc_F004D940
F004D900: d004200c                 ld      [%l0+0xC], %o0
F004D904: d0228000                 st      %o0, [%o2]
F004D908: d0062010                 ld      [%i0+0x10], %o0
F004D90C: 80a28008                 cmp     %o2, %o0
F004D910: 1280001d                 bne     loc_F004D984
F004D914: d006200c                 ld      [%i0+0xC], %o0
F004D918: 900a000b                 and     %o0, %o3, %o0
F004D91C: d026200c                 st      %o0, [%i0+0xC]
F004D920: d0042038                 ld      [%l0+0x38], %o0
F004D924: 10800017                 ba      loc_F004D980
F004D928: d026201c                 st      %o0, [%i0+0x1C]
F004D92C: 80a20019                 cmp     %o0, %i1
F004D930: 02800008                 be      loc_F004D950
F004D934: 80a22000                 cmp     %o0, 0
F004D938: a0100008                 mov     %o0, %l0
F004D93C: d004200c                 ld      [%l0+0xC], %o0
F004D940: 80a22000                 cmp     %o0, 0
F004D944: 12bffffa                 bne     loc_F004D92C
F004D948: d004200c                 ld      [%l0+0xC], %o0
F004D94C: 80a22000                 cmp     %o0, 0
F004D950: 22800009                 be,a    loc_F004D974
F004D954: d402a010                 ld      [%o2+0x10], %o2
F004D958: d006600c                 ld      [%i1+0xC], %o0
F004D95C: 80a22000                 cmp     %o0, 0
F004D960: 12800003                 bne     loc_F004D96C
F004D964: d024200c                 st      %o0, [%l0+0xC]
F004D968: e022a004                 st      %l0, [%o2+4]
F004D96C: 10800005                 ba      loc_F004D980
F004D970: a0100019                 mov     %i1, %l0
F004D974: 80a2400a                 cmp     %o1, %o2
F004D978: 32bfffe0                 bne,a   loc_F004D8F8
F004D97C: e0028000                 ld      [%o2], %l0
F004D980: d006200c                 ld      [%i0+0xC], %o0
F004D984: 13040000                 sethi   0x10000000, %o1
F004D988: 808a0009                 btst    %o1, %o0
F004D98C: 12800029                 bne     loc_F004DA30
F004D990: d4062010                 ld      [%i0+0x10], %o2
F004D994: 96062010                 add     %i0, 0x10, %o3
F004D998: 80a2c00a                 cmp     %o3, %o2
F004D99C: 02800025                 be      loc_F004DA30
F004D9A0: 01000000                 nop
F004D9A4: d0028000                 ld      [%o2], %o0
F004D9A8: 80a22000                 cmp     %o0, 0
F004D9AC: 12800021                 bne     loc_F004DA30
F004D9B0: 01000000                 nop
F004D9B4: b210000b                 mov     %o3, %i1
F004D9B8: a2100009                 mov     %o1, %l1
F004D9BC: d202a010                 ld      [%o2+0x10], %o1
F004D9C0: 80a2c009                 cmp     %o3, %o1
F004D9C4: 12800004                 bne     loc_F004D9D4
F004D9C8: d002a014                 ld      [%o2+0x14], %o0
F004D9CC: 10800003                 ba      loc_F004D9D8
F004D9D0: d0262014                 st      %o0, [%i0+0x14]
F004D9D4: d0226014                 st      %o0, [%o1+0x14]
F004D9D8: 80a64008                 cmp     %i1, %o0
F004D9DC: 32800003                 bne,a   loc_F004D9E8
F004D9E0: d2222010                 st      %o1, [%o0+0x10]
F004D9E4: d2262010                 st      %o1, [%i0+0x10]
F004D9E8: 9010000a                 mov     %o2, %o0
F004D9EC: 400069ed                 call    _kfree
F004D9F0: 92102018                 mov     0x18, %o1
F004D9F4: d0062018                 ld      [%i0+0x18], %o0
F004D9F8: d4062010                 ld      [%i0+0x10], %o2
F004D9FC: d206200c                 ld      [%i0+0xC], %o1
F004DA00: 90022001                 inc     %o0
F004DA04: 808a4011                 btst    %l1, %o1
F004DA08: 1280000a                 bne     loc_F004DA30
F004DA0C: d0262018                 st      %o0, [%i0+0x18]
F004DA10: 96062010                 add     %i0, 0x10, %o3
F004DA14: 80a2c00a                 cmp     %o3, %o2
F004DA18: 02800006                 be      loc_F004DA30
F004DA1C: 01000000                 nop
F004DA20: d0028000                 ld      [%o2], %o0
F004DA24: 80a22000                 cmp     %o0, 0
F004DA28: 22bfffe6                 be,a    loc_F004D9C0
F004DA2C: d202a010                 ld      [%o2+0x10], %o1
F004DA30: c0262024                 clr     [%i0+0x24]
F004DA34: 400124bc                 call    _splx
F004DA38: 90100012                 mov     %l2, %o0
F004DA3C: b0100010                 mov     %l0, %i0
F004DA40: 81c7e008                 ret
F004DA44: 81e80000                 restore
