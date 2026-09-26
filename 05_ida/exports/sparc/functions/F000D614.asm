F000D614: 9de3bf98                 save    %sp, -0x68, %sp
F000D618: 400008d5                 call    _suser
F000D61C: 01000000                 nop
F000D620: 80a22000                 cmp     %o0, 0
F000D624: 12800004                 bne     loc_F000D634
F000D628: 113c04cf                 sethi   -0xFECC400, %o0
F000D62C: 10800023                 ba      locret_F000D6B8
F000D630: b0102008                 mov     8, %i0
F000D634: d00221d8                 ld      [%o0+0x1D8], %o0
F000D638: f0020000                 ld      [%o0], %i0
F000D63C: d206204c                 ld      [%i0+0x4C], %o1
F000D640: 80a26000                 cmp     %o1, 0
F000D644: 22800005                 be,a    loc_F000D658
F000D648: d2062050                 ld      [%i0+0x50], %o1
F000D64C: d0062050                 ld      [%i0+0x50], %o0
F000D650: d0226050                 st      %o0, [%o1+0x50]
F000D654: d2062050                 ld      [%i0+0x50], %o1
F000D658: 80a26000                 cmp     %o1, 0
F000D65C: 22800005                 be,a    loc_F000D670
F000D660: d2062044                 ld      [%i0+0x44], %o1
F000D664: d006204c                 ld      [%i0+0x4C], %o0
F000D668: d022604c                 st      %o0, [%o1+0x4C]
F000D66C: d2062044                 ld      [%i0+0x44], %o1
F000D670: d0026048                 ld      [%o1+0x48], %o0
F000D674: 80a20018                 cmp     %o0, %i0
F000D678: 32800005                 bne,a   loc_F000D68C
F000D67C: f0262044                 st      %i0, [%i0+0x44]
F000D680: d006204c                 ld      [%i0+0x4C], %o0
F000D684: d0226048                 st      %o0, [%o1+0x48]
F000D688: f0262044                 st      %i0, [%i0+0x44]
F000D68C: d2562030                 ldsh    [%i0+0x30], %o1
F000D690: c026204c                 clr     [%i0+0x4C]
F000D694: d056202e                 ldsh    [%i0+0x2E], %o0
F000D698: 80a24008                 cmp     %o1, %o0
F000D69C: 02800005                 be      loc_F000D6B0
F000D6A0: c0262050                 clr     [%i0+0x50]
F000D6A4: 90100018                 mov     %i0, %o0
F000D6A8: 40000403                 call    _enterpgrp
F000D6AC: 94102000                 mov     0, %o2
F000D6B0: c0362032                 clrh    [%i0+0x32]
F000D6B4: b0102000                 mov     0, %i0
F000D6B8: 81c7e008                 ret
F000D6BC: 81e80000                 restore
