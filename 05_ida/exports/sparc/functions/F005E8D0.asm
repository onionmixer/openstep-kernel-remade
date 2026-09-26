F005E8D0: 9de3bf98                 save    %sp, -0x68, %sp
F005E8D4: a0100018                 mov     %i0, %l0
F005E8D8: f0042004                 ld      [%l0+4], %i0
F005E8DC: 80a62000                 cmp     %i0, 0
F005E8E0: 02800015                 be      locret_F005E934
F005E8E4: 90100018                 mov     %i0, %o0
F005E8E8: d404200c                 ld      [%l0+0xC], %o2
F005E8EC: 92042008                 add     %l0, 8, %o1
F005E8F0: d8042014                 ld      [%l0+0x14], %o4
F005E8F4: 7ffffe75                 call    sub_F005E2C8
F005E8F8: 96042010                 add     %l0, 0x10, %o3
F005E8FC: d0062018                 ld      [%i0+0x18], %o0
F005E900: 80a22000                 cmp     %o0, 0
F005E904: 0280000a                 be      loc_F005E92C
F005E908: 92102000                 mov     0, %o1
F005E90C: d0062018                 ld      [%i0+0x18], %o0
F005E910: d2262018                 st      %o1, [%i0+0x18]
F005E914: 92100018                 mov     %i0, %o1
F005E918: b0100008                 mov     %o0, %i0
F005E91C: d0062018                 ld      [%i0+0x18], %o0
F005E920: 80a22000                 cmp     %o0, 0
F005E924: 32bffffc                 bne,a   loc_F005E914
F005E928: d2262018                 st      %o1, [%i0+0x18]
F005E92C: f0242008                 st      %i0, [%l0+8]
F005E930: d2242010                 st      %o1, [%l0+0x10]
F005E934: 81c7e008                 ret
F005E938: 81e80000                 restore
