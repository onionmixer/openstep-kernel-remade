F00B14E4: 9de3bf98                 save    %sp, -0x68, %sp
F00B14E8: 113c04ba                 sethi   %hi(_pseudo_inits), %o0
F00B14EC: d20222ec                 ld      [%o0+%lo(_pseudo_inits)], %o1
F00B14F0: 80a26000                 cmp     %o1, 0
F00B14F4: 04800014                 ble     locret_F00B1544
F00B14F8: a21222ec                 or      %o0, %lo(_pseudo_inits), %l1
F00B14FC: d0044000                 ld      [%l1], %o0
F00B1500: a0102000                 mov     0, %l0
F00B1504: 80a40008                 cmp     %l0, %o0
F00B1508: 3680000b                 bge,a   loc_F00B1534
F00B150C: a2046008                 inc     8, %l1
F00B1510: d2046004                 ld      [%l1+4], %o1
F00B1514: 9fc24000                 call    %o1
F00B1518: 90100010                 mov     %l0, %o0
F00B151C: d0044000                 ld      [%l1], %o0
F00B1520: a0042001                 inc     %l0
F00B1524: 80a40008                 cmp     %l0, %o0
F00B1528: 26bffffb                 bl,a    loc_F00B1514
F00B152C: d2046004                 ld      [%l1+4], %o1
F00B1530: a2046008                 inc     8, %l1
F00B1534: d0044000                 ld      [%l1], %o0
F00B1538: 80a22000                 cmp     %o0, 0
F00B153C: 14bffff2                 bg      loc_F00B1504
F00B1540: a0102000                 mov     0, %l0
F00B1544: 81c7e008                 ret
F00B1548: 81e80000                 restore
