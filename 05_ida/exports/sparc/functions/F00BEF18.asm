F00BEF18: 9de3bf98                 save    %sp, -0x68, %sp
F00BEF1C: 40001c05                 call    _IOMalloc
F00BEF20: 90102020                 mov     0x20, %o0 ! ' '
F00BEF24: b0920000                 orcc    %o0, %g0, %i0
F00BEF28: 22800023                 be,a    locret_F00BEFB4
F00BEF2C: b0102000                 mov     0, %i0
F00BEF30: 40001c00                 call    _IOMalloc
F00BEF34: 90102054                 mov     0x54, %o0 ! 'T'
F00BEF38: 80a22000                 cmp     %o0, 0
F00BEF3C: 0280001a                 be      loc_F00BEFA4
F00BEF40: d026201c                 st      %o0, [%i0+0x1C]
F00BEF44: 113c02fa901223e4         set     sub_F00BEBE4, %o0
F00BEF4C: d0260000                 st      %o0, [%i0]
F00BEF50: 113c02fb90122008         set     sub_F00BEC08, %o0
F00BEF58: d0262004                 st      %o0, [%i0+4]
F00BEF5C: 113c02fb90122134         set     sub_F00BED34, %o0
F00BEF64: d0262008                 st      %o0, [%i0+8]
F00BEF68: 113c02fb90122174         set     sub_F00BED74, %o0
F00BEF70: d026200c                 st      %o0, [%i0+0xC]
F00BEF74: 113c02fb901221fc         set     sub_F00BEDFC, %o0
F00BEF7C: d0262010                 st      %o0, [%i0+0x10]
F00BEF80: 113c02fb901222cc         set     sub_F00BEECC, %o0
F00BEF88: d0262014                 st      %o0, [%i0+0x14]
F00BEF8C: 113c02fb901222e8         set     sub_F00BEEE8, %o0
F00BEF94: d0262018                 st      %o0, [%i0+0x18]
F00BEF98: d006201c                 ld      [%i0+0x1C], %o0
F00BEF9C: 10800006                 ba      locret_F00BEFB4
F00BEFA0: c0222008                 clr     [%o0+8]
F00BEFA4: 90100018                 mov     %i0, %o0
F00BEFA8: 40001be7                 call    _IOFree
F00BEFAC: 92102020                 mov     0x20, %o1 ! ' '
F00BEFB0: b0102000                 mov     0, %i0
F00BEFB4: 81c7e008                 ret
F00BEFB8: 81e80000                 restore
