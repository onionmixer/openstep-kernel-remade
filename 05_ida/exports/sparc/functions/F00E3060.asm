F00E3060: 9de3bf98                 save    %sp, -0x68, %sp
F00E3064: d2062004                 ld      [%i0+4], %o1
F00E3068: 80a26028                 cmp     %o1, 0x28 ! '('
F00E306C: 12800005                 bne     loc_F00E3080
F00E3070: d00e2003                 ldub    [%i0+3], %o0
F00E3074: 80a22000                 cmp     %o0, 0
F00E3078: 22800005                 be,a    loc_F00E308C
F00E307C: d0062018                 ld      [%i0+0x18], %o0
F00E3080: 90103ed0                 mov     -0x130, %o0
F00E3084: 10800019                 ba      locret_F00E30E8
F00E3088: d026601c                 st      %o0, [%i1+0x1C]
F00E308C: 133c03e6                 sethi   %hi(dword_F00F99EC), %o1
F00E3090: d20261ec                 ld      [%o1+%lo(dword_F00F99EC)], %o1
F00E3094: 80a20009                 cmp     %o0, %o1
F00E3098: 1280000c                 bne     loc_F00E30C8
F00E309C: 90103ed0                 mov     -0x130, %o0
F00E30A0: d0062020                 ld      [%i0+0x20], %o0
F00E30A4: 133c03e6                 sethi   %hi(dword_F00F99F0), %o1
F00E30A8: d20261f0                 ld      [%o1+%lo(dword_F00F99F0)], %o1
F00E30AC: 80a20009                 cmp     %o0, %o1
F00E30B0: 12800006                 bne     loc_F00E30C8
F00E30B4: 90103ed0                 mov     -0x130, %o0
F00E30B8: d006200c                 ld      [%i0+0xC], %o0
F00E30BC: d206201c                 ld      [%i0+0x1C], %o1
F00E30C0: 7fffc926                 call    _EvSetSpecialKeyPort
F00E30C4: d4062024                 ld      [%i0+0x24], %o2
F00E30C8: d026601c                 st      %o0, [%i1+0x1C]
F00E30CC: d006601c                 ld      [%i1+0x1C], %o0
F00E30D0: 80a22000                 cmp     %o0, 0
F00E30D4: 12800005                 bne     locret_F00E30E8
F00E30D8: 92102020                 mov     0x20, %o1 ! ' '
F00E30DC: 90102001                 mov     1, %o0
F00E30E0: d02e6003                 stb     %o0, [%i1+3]
F00E30E4: d2266004                 st      %o1, [%i1+4]
F00E30E8: 81c7e008                 ret
F00E30EC: 81e80000                 restore
