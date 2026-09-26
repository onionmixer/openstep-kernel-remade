F00B01CC: 9de3bf98                 save    %sp, -0x68, %sp
F00B01D0: 7ffffd45                 call    _prom_stdoutpath
F00B01D4: 01000000                 nop
F00B01D8: 80a22000                 cmp     %o0, 0
F00B01DC: 22800006                 be,a    loc_F00B01F4
F00B01E0: 113c0470                 sethi   -0xFEE4000, %o0
F00B01E4: 7fffff0b                 call    _prom_get_path_option
F00B01E8: 01000000                 nop
F00B01EC: 10800020                 ba      locret_F00B026C
F00B01F0: b0100008                 mov     %o0, %i0
F00B01F4: d0022278                 ld      [%o0+0x278], %o0
F00B01F8: 80a22000                 cmp     %o0, 0
F00B01FC: 02800004                 be      loc_F00B020C
F00B0200: 80a22002                 cmp     %o0, 2
F00B0204: 1280001a                 bne     locret_F00B026C
F00B0208: b0102000                 mov     0, %i0
F00B020C: 113c000c                 sethi   %hi(_romp), %o0
F00B0210: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00B0214: d0022048                 ld      [%o0+0x48], %o0
F00B0218: d00a0000                 ldub    [%o0], %o0
F00B021C: 80a22002                 cmp     %o0, 2
F00B0220: 02800012                 be      loc_F00B0268
F00B0224: 313c0470                 sethi   -0xFEE4000, %i0
F00B0228: 14800007                 bg      loc_F00B0244
F00B022C: 80a22003                 cmp     %o0, 3
F00B0230: 80a22001                 cmp     %o0, 1
F00B0234: 0280000b                 be      loc_F00B0260
F00B0238: 313c0470                 sethi   -0xFEE4000, %i0
F00B023C: 1080000c                 ba      locret_F00B026C
F00B0240: b0102000                 mov     0, %i0
F00B0244: 02800006                 be      loc_F00B025C
F00B0248: 80a22004                 cmp     %o0, 4
F00B024C: 02800007                 be      loc_F00B0268
F00B0250: 313c0470                 sethi   -0xFEE4000, %i0
F00B0254: 10800006                 ba      locret_F00B026C
F00B0258: b0102000                 mov     0, %i0
F00B025C: 313c0470                 sethi   -0xFEE4000, %i0
F00B0260: 10800003                 ba      locret_F00B026C
F00B0264: b0162370                 bset    0x370, %i0
F00B0268: b0162378                 bset    0x378, %i0
F00B026C: 81c7e008                 ret
F00B0270: 81e80000                 restore
