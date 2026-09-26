F008CFB0: 9de3bf88                 save    %sp, -0x78, %sp
F008CFB4: d4068000                 ld      [%i2], %o2
F008CFB8: a4062018                 add     %i0, 0x18, %l2
F008CFBC: d206a004                 ld      [%i2+4], %o1
F008CFC0: a2102000                 mov     0, %l1
F008CFC4: d427bfe8                 st      %o2, [%fp+var_18]
F008CFC8: d006a004                 ld      [%i2+4], %o0
F008CFCC: d027bfec                 st      %o0, [%fp+var_14]
F008CFD0: 90828008                 addcc   %o2, %o0, %o0
F008CFD4: 02800005                 be      loc_F008CFE8
F008CFD8: 92028009                 add     %o2, %o1, %o1
F008CFDC: 80a2000a                 cmp     %o0, %o2
F008CFE0: 08800003                 bleu    loc_F008CFEC
F008CFE4: 90102000                 mov     0, %o0
F008CFE8: 90102001                 mov     1, %o0
F008CFEC: 80a22000                 cmp     %o0, 0
F008CFF0: 22800038                 be,a    locret_F008D0D0
F008CFF4: b0102000                 mov     0, %i0
F008CFF8: d0062008                 ld      [%i0+8], %o0
F008CFFC: 80a28008                 cmp     %o2, %o0
F008D000: 2a800034                 bcs,a   locret_F008D0D0
F008D004: b0102000                 mov     0, %i0
F008D008: d006200c                 ld      [%i0+0xC], %o0
F008D00C: 80a22000                 cmp     %o0, 0
F008D010: 02800006                 be      loc_F008D028
F008D014: 80a24008                 cmp     %o1, %o0
F008D018: 08800005                 bleu    loc_F008D02C
F008D01C: 173c0503                 sethi   -0xFEBF400, %o3
F008D020: 1080002c                 ba      locret_F008D0D0
F008D024: b0102000                 mov     0, %i0
F008D028: 173c0503                 sethi   -0xFEBF400, %o3
F008D02C: 273c0504                 sethi   -0xFEBF000, %l3
F008D030: 293c0504                 sethi   -0xFEBF000, %l4
F008D034: e0048000                 ld      [%l2], %l0
F008D038: 80a42000                 cmp     %l0, 0
F008D03C: 22800007                 be,a    loc_F008D058
F008D040: d0068000                 ld      [%i2], %o0
F008D044: d004200c                 ld      [%l0+0xC], %o0
F008D048: 80a24008                 cmp     %o1, %o0
F008D04C: 3880001d                 bgu,a   loc_F008D0C0
F008D050: d0042010                 ld      [%l0+0x10], %o0
F008D054: d0068000                 ld      [%i2], %o0
F008D058: d027bfe8                 st      %o0, [%fp+var_18]
F008D05C: d006a004                 ld      [%i2+4], %o0! id
F008D060: d202e3f0                 ld      [%o3+0x3F0], %o1! SEL
F008D064: d027bfec                 st      %o0, [%fp+var_14]
F008D068: 40019202                 call    _objc_msgSend
F008D06C: d0062010                 ld      [%i0+0x10], %o0! id
F008D070: 94100018                 mov     %i0, %o2
F008D074: 9607bfe8                 add     %fp, var_18, %o3
F008D078: d204e050                 ld      [%l3+0x50], %o1! SEL
F008D07C: 400191fd                 call    _objc_msgSend
F008D080: 98102000                 mov     0, %o4
F008D084: a2920000                 orcc    %o0, %g0, %l1
F008D088: 22800012                 be,a    locret_F008D0D0
F008D08C: b0100011                 mov     %l1, %i0
F008D090: e0246004                 st      %l0, [%l1+4]
F008D094: e2248000                 st      %l1, [%l2]
F008D098: d0062014                 ld      [%i0+0x14], %o0
F008D09C: 90022001                 inc     %o0
F008D0A0: 80a22001                 cmp     %o0, 1
F008D0A4: 1280000a                 bne     loc_F008D0CC
F008D0A8: d0262014                 st      %o0, [%i0+0x14]
F008D0AC: d0062004                 ld      [%i0+4], %o0! id
F008D0B0: 400191f0                 call    _objc_msgSend
F008D0B4: d2052038                 ld      [%l4+0x38], %o1
F008D0B8: 10800006                 ba      locret_F008D0D0
F008D0BC: b0100011                 mov     %l1, %i0
F008D0C0: 80a2000a                 cmp     %o0, %o2
F008D0C4: 08bfffdc                 bleu    loc_F008D034
F008D0C8: a4042004                 add     %l0, 4, %l2
F008D0CC: b0100011                 mov     %l1, %i0
F008D0D0: 81c7e008                 ret
F008D0D4: 81e80000                 restore
