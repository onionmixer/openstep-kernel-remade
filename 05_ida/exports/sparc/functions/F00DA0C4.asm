F00DA0C4: 9de3bf90                 save    %sp, -0x70, %sp
F00DA0C8: a0100018                 mov     %i0, %l0
F00DA0CC: b010001a                 mov     %i2, %i0
F00DA0D0: 113c0505                 sethi   %hi(paDmasize), %o0
F00DA0D4: f40220a8                 ld      [%o0+%lo(paDmasize)], %i2
F00DA0D8: 90100010                 mov     %l0, %o0! id
F00DA0DC: 40005de5                 call    _objc_msgSend
F00DA0E0: 9210001a                 mov     %i2, %o1
F00DA0E4: 7ffcb147                 call    _udiv
F00DA0E8: 92100018                 mov     %i0, %o1! SEL
F00DA0EC: d024203c                 st      %o0, [%l0+0x3C]
F00DA0F0: 90023ffc                 inc     -4, %o0
F00DA0F4: 80a2200c                 cmp     %o0, 0xC
F00DA0F8: 08800009                 bleu    loc_F00DA11C
F00DA0FC: 90102008                 mov     8, %o0
F00DA100: d024203c                 st      %o0, [%l0+0x3C]
F00DA104: 90100010                 mov     %l0, %o0! id
F00DA108: 40005dda                 call    _objc_msgSend
F00DA10C: 9210001a                 mov     %i2, %o1
F00DA110: 7ffcb13c                 call    _udiv
F00DA114: d204203c                 ld      [%l0+0x3C], %o1
F00DA118: b0100008                 mov     %o0, %i0
F00DA11C: f0242040                 st      %i0, [%l0+0x40]
F00DA120: 81c7e008                 ret
F00DA124: 81e80000                 restore
