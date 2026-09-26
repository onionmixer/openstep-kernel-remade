F00DE1AC: 9de3bf98                 save    %sp, -0x68, %sp
F00DE1B0: 80a62000                 cmp     %i0, 0
F00DE1B4: 02800005                 be      loc_F00DE1C8
F00DE1B8: 94100019                 mov     %i1, %o2
F00DE1BC: 80a2a000                 cmp     %o2, 0
F00DE1C0: 12800004                 bne     loc_F00DE1D0
F00DE1C4: 133c0505                 sethi   -0xFEBEC00, %o1
F00DE1C8: 10800018                 ba      locret_F00DE228
F00DE1CC: b01020ca                 mov     0xCA, %i0
F00DE1D0: d2026018                 ld      [%o1+0x18], %o1! SEL
F00DE1D4: 40004da7                 call    _objc_msgSend
F00DE1D8: 90100018                 mov     %i0, %o0
F00DE1DC: 912a2018                 sll     %o0, 24, %o0
F00DE1E0: 80a22000                 cmp     %o0, 0
F00DE1E4: 12800004                 bne     loc_F00DE1F4
F00DE1E8: 80a6a001                 cmp     %i2, 1
F00DE1EC: 1080000f                 ba      locret_F00DE228
F00DE1F0: b01020c8                 mov     0xC8, %i0
F00DE1F4: 08800007                 bleu    loc_F00DE210
F00DE1F8: 9006bffe                 add     %i2, -2, %o0
F00DE1FC: 80a22001                 cmp     %o0, 1
F00DE200: 08800005                 bleu    loc_F00DE214
F00DE204: 90100018                 mov     %i0, %o0
F00DE208: 10800008                 ba      locret_F00DE228
F00DE20C: b01020ce                 mov     0xCE, %i0
F00DE210: 90100018                 mov     %i0, %o0! id
F00DE214: 133c0505                 sethi   %hi(paControlstreams), %o1
F00DE218: d2026014                 ld      [%o1+%lo(paControlstreams)], %o1! SEL
F00DE21C: 40004d95                 call    _objc_msgSend
F00DE220: 9410001a                 mov     %i2, %o2
F00DE224: b0102000                 mov     0, %i0
F00DE228: 81c7e008                 ret
F00DE22C: 81e80000                 restore
