F00A1178: 9de3bf98                 save    %sp, -0x68, %sp
F00A117C: 80a6e001                 cmp     %i3, 1
F00A1180: 02800004                 be      loc_F00A1190
F00A1184: 80a62000                 cmp     %i0, 0
F00A1188: 10800030                 ba      locret_F00A1248
F00A118C: b0102004                 mov     4, %i0
F00A1190: 12800004                 bne     loc_F00A11A0
F00A1194: a0102000                 mov     0, %l0
F00A1198: 1080002c                 ba      locret_F00A1248
F00A119C: b0102000                 mov     0, %i0
F00A11A0: 113c04d0                 sethi   %hi(_page_mask), %o0
F00A11A4: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F00A11A8: b6062018                 add     %i0, 0x18, %i3
F00A11AC: 7fffd6d4                 call    _splvm
F00A11B0: b22e4008                 bclr    %o0, %i1
F00A11B4: a2100008                 mov     %o0, %l1
F00A11B8: d006c000                 ld      [%i3], %o0
F00A11BC: 80a22000                 cmp     %o0, 0
F00A11C0: 12bffffe                 bne     loc_F00A11B8
F00A11C4: 01000000                 nop
F00A11C8: 7fffd738                 call    _simple_lock_try
F00A11CC: 9010001b                 mov     %i3, %o0
F00A11D0: 80a22000                 cmp     %o0, 0
F00A11D4: 02bffff9                 be      loc_F00A11B8
F00A11D8: 01000000                 nop
F00A11DC: f8070000                 ld      [%i4], %i4
F00A11E0: 80a72008                 cmp     %i4, 8
F00A11E4: 34800015                 bg,a    loc_F00A1238
F00A11E8: a0102004                 mov     4, %l0
F00A11EC: 80a72006                 cmp     %i4, 6
F00A11F0: 26800012                 bl,a    loc_F00A1238
F00A11F4: a0102004                 mov     4, %l0
F00A11F8: 40000016                 call    _get_context
F00A11FC: 90100018                 mov     %i0, %o0
F00A1200: b6100008                 mov     %o0, %i3
F00A1204: 80a6ffff                 cmp     %i3, -1
F00A1208: 0280000c                 be      loc_F00A1238
F00A120C: b406401a                 add     %i1, %i2, %i2
F00A1210: 80a6401a                 cmp     %i1, %i2
F00A1214: 1a800009                 bcc     loc_F00A1238
F00A1218: 39000004                 sethi   0x1000, %i4
F00A121C: 90100019                 mov     %i1, %o0
F00A1220: 7fffd1d1                 call    _vac_pagectxflush
F00A1224: 9210001b                 mov     %i3, %o1
F00A1228: b206401c                 add     %i1, %i4, %i1
F00A122C: 80a6401a                 cmp     %i1, %i2
F00A1230: 0abffffc                 bcs     loc_F00A1220
F00A1234: 90100019                 mov     %i1, %o0
F00A1238: c0262018                 clr     [%i0+0x18]
F00A123C: 7fffd6ba                 call    _splx
F00A1240: 90100011                 mov     %l1, %o0
F00A1244: b0100010                 mov     %l0, %i0
F00A1248: 81c7e008                 ret
F00A124C: 81e80000                 restore
