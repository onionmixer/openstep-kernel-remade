F001B6EC: 9de3bf98                 save    %sp, -0x68, %sp
F001B6F0: 113c04bc                 sethi   %hi(unk_F012F204), %o0
F001B6F4: d4162038                 lduh    [%i0+0x38], %o2
F001B6F8: 90122204                 bset    %lo(unk_F012F204), %o0
F001B6FC: 920aa0ff                 and     %o2, 0xFF, %o1
F001B700: 932a6004                 sll     %o1, 4, %o1
F001B704: 92024008                 add     %o1, %o0, %o1
F001B708: 80a2a000                 cmp     %o2, 0
F001B70C: 02800010                 be      locret_F001B74C
F001B710: d202600c                 ld      [%o1+0xC], %o1
F001B714: d0062040                 ld      [%i0+0x40], %o0
F001B718: 808a2100                 btst    0x100, %o0
F001B71C: 1280000c                 bne     locret_F001B74C
F001B720: 01000000                 nop
F001B724: d0024000                 ld      [%o1], %o0
F001B728: 808a2010                 btst    0x10, %o0
F001B72C: 02800005                 be      loc_F001B740
F001B730: 900a3fef                 and     %o0, -0x11, %o0
F001B734: d0224000                 st      %o0, [%o1]
F001B738: 90102008                 mov     8, %o0
F001B73C: d02a600c                 stb     %o0, [%o1+0xC]
F001B740: 90100018                 mov     %i0, %o0
F001B744: 40000004                 call    _ptcwakeup
F001B748: 92102001                 mov     1, %o1
F001B74C: 81c7e008                 ret
F001B750: 81e80000                 restore
