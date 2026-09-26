F00DAF48: 9de3bf90                 save    %sp, -0x70, %sp
F00DAF4C: d0062034                 ld      [%i0+0x34], %o0
F00DAF50: 80a22000                 cmp     %o0, 0
F00DAF54: 32800006                 bne,a   loc_F00DAF6C
F00DAF58: d2062034                 ld      [%i0+0x34], %o1
F00DAF5C: 7fffabf5                 call    _IOMalloc
F00DAF60: 11000008                 sethi   0x2000, %o0
F00DAF64: d0262034                 st      %o0, [%i0+0x34]
F00DAF68: d2062034                 ld      [%i0+0x34], %o1
F00DAF6C: 90102001                 mov     1, %o0
F00DAF70: d02a6003                 stb     %o0, [%o1+3]
F00DAF74: d2062034                 ld      [%i0+0x34], %o1
F00DAF78: 90102018                 mov     0x18, %o0
F00DAF7C: d0226004                 st      %o0, [%o1+4]
F00DAF80: d0062034                 ld      [%i0+0x34], %o0
F00DAF84: c0222008                 clr     [%o0+8]
F00DAF88: d0062034                 ld      [%i0+0x34], %o0
F00DAF8C: c022200c                 clr     [%o0+0xC]
F00DAF90: d0062034                 ld      [%i0+0x34], %o0
F00DAF94: c0222010                 clr     [%o0+0x10]
F00DAF98: d0062034                 ld      [%i0+0x34], %o0
F00DAF9C: c0222014                 clr     [%o0+0x14]
F00DAFA0: 81c7e008                 ret
F00DAFA4: 81e80000                 restore
