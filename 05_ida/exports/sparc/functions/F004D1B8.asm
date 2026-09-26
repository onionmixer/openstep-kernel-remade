F004D1B8: 9de3bf98                 save    %sp, -0x68, %sp
F004D1BC: 84100018                 mov     %i0, %g2
F004D1C0: f0008000                 ld      [%g2], %i0
F004D1C4: c6062038                 ld      [%i0+0x38], %g3
F004D1C8: 80a0c019                 cmp     %g3, %i1
F004D1CC: 36800014                 bge,a   loc_F004D21C
F004D1D0: c400a008                 ld      [%g2+8], %g2
F004D1D4: c406200c                 ld      [%i0+0xC], %g2
F004D1D8: 80a0a000                 cmp     %g2, 0
F004D1DC: 02800031                 be      locret_F004D2A0
F004D1E0: 01000000                 nop
F004D1E4: f406200c                 ld      [%i0+0xC], %i2
F004D1E8: c4062038                 ld      [%i0+0x38], %g2
F004D1EC: c606a038                 ld      [%i2+0x38], %g3
F004D1F0: 80a08003                 cmp     %g2, %g3
F004D1F4: 1480002b                 bg      locret_F004D2A0
F004D1F8: 80a0c019                 cmp     %g3, %i1
F004D1FC: 14800029                 bg      locret_F004D2A0
F004D200: 01000000                 nop
F004D204: b010001a                 mov     %i2, %i0
F004D208: c406a00c                 ld      [%i2+0xC], %g2
F004D20C: 80a0a000                 cmp     %g2, 0
F004D210: 32bffff6                 bne,a   loc_F004D1E8
F004D214: f406200c                 ld      [%i0+0xC], %i2
F004D218: 30800022                 ba,a    locret_F004D2A0
F004D21C: 80a0c002                 cmp     %g3, %g2
F004D220: 06800013                 bl      loc_F004D26C
F004D224: 80a0c019                 cmp     %g3, %i1
F004D228: c406200c                 ld      [%i0+0xC], %g2
F004D22C: 80a0a000                 cmp     %g2, 0
F004D230: 0280001a                 be      loc_F004D298
F004D234: 01000000                 nop
F004D238: f406200c                 ld      [%i0+0xC], %i2
F004D23C: c6062038                 ld      [%i0+0x38], %g3
F004D240: c406a038                 ld      [%i2+0x38], %g2
F004D244: 80a0c002                 cmp     %g3, %g2
F004D248: 34800013                 bg,a    loc_F004D294
F004D24C: c406200c                 ld      [%i0+0xC], %g2
F004D250: b010001a                 mov     %i2, %i0
F004D254: c406a00c                 ld      [%i2+0xC], %g2
F004D258: 80a0a000                 cmp     %g2, 0
F004D25C: 32bffff8                 bne,a   loc_F004D23C
F004D260: f406200c                 ld      [%i0+0xC], %i2
F004D264: 1080000c                 ba      loc_F004D294
F004D268: c406200c                 ld      [%i0+0xC], %g2
F004D26C: 2480000a                 ble,a   loc_F004D294
F004D270: c406200c                 ld      [%i0+0xC], %g2
F004D274: 1080000b                 ba      locret_F004D2A0
F004D278: b0102000                 mov     0, %i0
F004D27C: c400e038                 ld      [%g3+0x38], %g2
F004D280: 80a08019                 cmp     %g2, %i1
F004D284: 14800007                 bg      locret_F004D2A0
F004D288: 01000000                 nop
F004D28C: b0100003                 mov     %g3, %i0
F004D290: c400e00c                 ld      [%g3+0xC], %g2
F004D294: 80a0a000                 cmp     %g2, 0
F004D298: 32bffff9                 bne,a   loc_F004D27C
F004D29C: c606200c                 ld      [%i0+0xC], %g3
F004D2A0: 81c7e008                 ret
F004D2A4: 81e80000                 restore
