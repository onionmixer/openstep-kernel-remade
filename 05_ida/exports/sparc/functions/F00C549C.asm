F00C549C: 9de3bf90                 save    %sp, -0x70, %sp
F00C54A0: 80a6bd39                 cmp     %i2, -0x2C7
F00C54A4: 0280003d                 be      locret_F00C5598
F00C54A8: b010202d                 mov     0x2D, %i0 ! '-'
F00C54AC: 1480001f                 bg      loc_F00C5528
F00C54B0: 80a6bd3f                 cmp     %i2, -0x2C1
F00C54B4: 80a6bd2f                 cmp     %i2, -0x2D1
F00C54B8: 02800038                 be      locret_F00C5598
F00C54BC: b0102005                 mov     5, %i0
F00C54C0: 14800010                 bg      loc_F00C5500
F00C54C4: 80a6bd34                 cmp     %i2, -0x2CC
F00C54C8: 80a6bd2c                 cmp     %i2, -0x2D4
F00C54CC: 02800033                 be      locret_F00C5598
F00C54D0: 01000000                 nop
F00C54D4: 14800007                 bg      loc_F00C54F0
F00C54D8: 80a6bd2e                 cmp     %i2, -0x2D2
F00C54DC: 80a6bd2b                 cmp     %i2, -0x2D5
F00C54E0: 0280002e                 be      locret_F00C5598
F00C54E4: b0102010                 mov     0x10, %i0
F00C54E8: 1080002c                 ba      locret_F00C5598
F00C54EC: b0102005                 mov     5, %i0
F00C54F0: 0280002a                 be      locret_F00C5598
F00C54F4: b0102010                 mov     0x10, %i0
F00C54F8: 10800028                 ba      locret_F00C5598
F00C54FC: b0102005                 mov     5, %i0
F00C5500: 14800026                 bg      locret_F00C5598
F00C5504: b0102005                 mov     5, %i0
F00C5508: 80a6bd32                 cmp     %i2, -0x2CE
F00C550C: 16800023                 bge     locret_F00C5598
F00C5510: b010200d                 mov     0xD, %i0
F00C5514: 80a6bd31                 cmp     %i2, -0x2CF
F00C5518: 02800020                 be      locret_F00C5598
F00C551C: b010201e                 mov     0x1E, %i0
F00C5520: 1080001e                 ba      locret_F00C5598
F00C5524: b0102005                 mov     5, %i0
F00C5528: 02800019                 be      loc_F00C558C
F00C552C: 80a6bd3f                 cmp     %i2, -0x2C1
F00C5530: 14800009                 bg      loc_F00C5554
F00C5534: 80a6bd43                 cmp     %i2, -0x2BD
F00C5538: 80a6bd3b                 cmp     %i2, -0x2C5
F00C553C: 06800016                 bl      loc_F00C5594
F00C5540: 80a6bd3d                 cmp     %i2, -0x2C3
F00C5544: 04800015                 ble     locret_F00C5598
F00C5548: b010200d                 mov     0xD, %i0
F00C554C: 10800013                 ba      locret_F00C5598
F00C5550: b0102016                 mov     0x16, %i0
F00C5554: 1480000a                 bg      loc_F00C557C
F00C5558: 80a6a000                 cmp     %i2, 0
F00C555C: 80a6bd42                 cmp     %i2, -0x2BE
F00C5560: 1680000e                 bge     locret_F00C5598
F00C5564: b010200c                 mov     0xC, %i0
F00C5568: 80a6bd40                 cmp     %i2, -0x2C0
F00C556C: 0280000b                 be      locret_F00C5598
F00C5570: b0102006                 mov     6, %i0
F00C5574: 10800009                 ba      locret_F00C5598
F00C5578: b0102005                 mov     5, %i0
F00C557C: 12800007                 bne     locret_F00C5598
F00C5580: b0102005                 mov     5, %i0
F00C5584: 10800005                 ba      locret_F00C5598
F00C5588: b0102000                 mov     0, %i0
F00C558C: 10800003                 ba      locret_F00C5598
F00C5590: b010200d                 mov     0xD, %i0
F00C5594: b0102005                 mov     5, %i0
F00C5598: 81c7e008                 ret
F00C559C: 81e80000                 restore
