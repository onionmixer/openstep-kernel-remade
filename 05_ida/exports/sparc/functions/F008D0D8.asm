F008D0D8: 9de3bf88                 save    %sp, -0x78, %sp
F008D0DC: a2100018                 mov     %i0, %l1
F008D0E0: d4068000                 ld      [%i2], %o2
F008D0E4: a4046018                 add     %l1, 0x18, %l2
F008D0E8: d206a004                 ld      [%i2+4], %o1
F008D0EC: b0102000                 mov     0, %i0
F008D0F0: d427bfe8                 st      %o2, [%fp+var_18]
F008D0F4: d006a004                 ld      [%i2+4], %o0
F008D0F8: d027bfec                 st      %o0, [%fp+var_14]
F008D0FC: 90828008                 addcc   %o2, %o0, %o0
F008D100: 02800005                 be      loc_F008D114
F008D104: 92028009                 add     %o2, %o1, %o1
F008D108: 80a2000a                 cmp     %o0, %o2
F008D10C: 08800003                 bleu    loc_F008D118
F008D110: 90102000                 mov     0, %o0
F008D114: 90102001                 mov     1, %o0
F008D118: 80a22000                 cmp     %o0, 0
F008D11C: 22800040                 be,a    locret_F008D21C
F008D120: b0102000                 mov     0, %i0
F008D124: d0046008                 ld      [%l1+8], %o0
F008D128: 80a28008                 cmp     %o2, %o0
F008D12C: 2a80003c                 bcs,a   locret_F008D21C
F008D130: b0102000                 mov     0, %i0
F008D134: d004600c                 ld      [%l1+0xC], %o0! id
F008D138: 80a22000                 cmp     %o0, 0
F008D13C: 0280000b                 be      loc_F008D168
F008D140: 80a24008                 cmp     %o1, %o0
F008D144: 0880000a                 bleu    loc_F008D16C
F008D148: 173c0503                 sethi   -0xFEBF400, %o3
F008D14C: 10800034                 ba      locret_F008D21C
F008D150: b0102000                 mov     0, %i0
F008D154: d202203c                 ld      [%o0+0x3C], %o1! SEL
F008D158: 400191c6                 call    _objc_msgSend
F008D15C: 90100010                 mov     %l0, %o0
F008D160: 1080002f                 ba      locret_F008D21C
F008D164: b0100008                 mov     %o0, %i0
F008D168: 173c0503                 sethi   -0xFEBF400, %o3
F008D16C: 273c0504                 sethi   -0xFEBF000, %l3
F008D170: 293c0504                 sethi   -0xFEBF000, %l4
F008D174: e0048000                 ld      [%l2], %l0
F008D178: 80a42000                 cmp     %l0, 0
F008D17C: 22800007                 be,a    loc_F008D198
F008D180: d0068000                 ld      [%i2], %o0
F008D184: d004200c                 ld      [%l0+0xC], %o0
F008D188: 80a24008                 cmp     %o1, %o0
F008D18C: 1880001c                 bgu     loc_F008D1FC
F008D190: 80a28008                 cmp     %o2, %o0
F008D194: d0068000                 ld      [%i2], %o0
F008D198: d027bfe8                 st      %o0, [%fp+var_18]
F008D19C: d006a004                 ld      [%i2+4], %o0! id
F008D1A0: d202e3f0                 ld      [%o3+0x3F0], %o1! SEL
F008D1A4: d027bfec                 st      %o0, [%fp+var_14]
F008D1A8: 400191b2                 call    _objc_msgSend
F008D1AC: d0046010                 ld      [%l1+0x10], %o0! id
F008D1B0: 94100011                 mov     %l1, %o2
F008D1B4: 9607bfe8                 add     %fp, var_18, %o3
F008D1B8: d204e050                 ld      [%l3+0x50], %o1! SEL
F008D1BC: 400191ad                 call    _objc_msgSend
F008D1C0: 98102001                 mov     1, %o4
F008D1C4: b0920000                 orcc    %o0, %g0, %i0
F008D1C8: 02800015                 be      locret_F008D21C
F008D1CC: 01000000                 nop
F008D1D0: e0262004                 st      %l0, [%i0+4]
F008D1D4: f0248000                 st      %i0, [%l2]
F008D1D8: d0046014                 ld      [%l1+0x14], %o0
F008D1DC: 90022001                 inc     %o0
F008D1E0: 80a22001                 cmp     %o0, 1
F008D1E4: 1280000e                 bne     locret_F008D21C
F008D1E8: d0246014                 st      %o0, [%l1+0x14]
F008D1EC: d0046004                 ld      [%l1+4], %o0! id
F008D1F0: 400191a0                 call    _objc_msgSend
F008D1F4: d2052038                 ld      [%l4+0x38], %o1
F008D1F8: 30800009                 ba,a    locret_F008D21C
F008D1FC: 0a800005                 bcs     loc_F008D210
F008D200: d0042010                 ld      [%l0+0x10], %o0
F008D204: 80a24008                 cmp     %o1, %o0
F008D208: 28bfffd3                 bleu,a  loc_F008D154
F008D20C: 113c0504                 sethi   -0xFEBF000, %o0
F008D210: 80a2000a                 cmp     %o0, %o2
F008D214: 08bfffd8                 bleu    loc_F008D174
F008D218: a4042004                 add     %l0, 4, %l2
F008D21C: 81c7e008                 ret
F008D220: 81e80000                 restore
