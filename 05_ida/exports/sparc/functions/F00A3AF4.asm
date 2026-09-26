F00A3AF4: 9de3bf98                 save    %sp, -0x68, %sp
F00A3AF8: b12e2018                 sll     %i0, 24, %i0
F00A3AFC: b13e2018                 sra     %i0, 24, %i0
F00A3B00: 80a62020                 cmp     %i0, 0x20 ! ' '
F00A3B04: 02800008                 be      loc_F00A3B24
F00A3B08: 80a62000                 cmp     %i0, 0
F00A3B0C: 02800006                 be      loc_F00A3B24
F00A3B10: 80a62009                 cmp     %i0, 9
F00A3B14: 02800004                 be      loc_F00A3B24
F00A3B18: 80a6202c                 cmp     %i0, 0x2C ! ','
F00A3B1C: 12800003                 bne     locret_F00A3B28
F00A3B20: b0102000                 mov     0, %i0
F00A3B24: b0102001                 mov     1, %i0
F00A3B28: 81c7e008                 ret
F00A3B2C: 81e80000                 restore
