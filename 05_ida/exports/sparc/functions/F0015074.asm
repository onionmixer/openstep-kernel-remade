F0015074: 9de3bf88                 save    %sp, -0x78, %sp
F0015078: 80a6600a                 cmp     %i1, 0xA
F001507C: 1280000b                 bne     loc_F00150A8
F0015080: a007bfe8                 add     %fp, var_18, %l0
F0015084: 80a62000                 cmp     %i0, 0
F0015088: 16800009                 bge     loc_F00150AC
F001508C: 113c042d                 sethi   -0xFEF4C00, %o0
F0015090: 9010202d                 mov     0x2D, %o0 ! '-'
F0015094: 9210001a                 mov     %i2, %o1
F0015098: 40000096                 call    sub_F00152F0
F001509C: 9410001b                 mov     %i3, %o2
F00150A0: b0200018                 neg     %i0
F00150A4: a007bfe8                 add     %fp, var_18, %l0
F00150A8: 113c042d                 sethi   -0xFEF4C00, %o0
F00150AC: a21220a8                 or      %o0, 0xA8, %l1
F00150B0: 90100018                 mov     %i0, %o0
F00150B4: 7fffc5fb                 call    _urem
F00150B8: 92100019                 mov     %i1, %o1
F00150BC: 92100008                 mov     %o0, %o1
F00150C0: d40a4011                 ldub    [%o1+%l1], %o2
F00150C4: 90100018                 mov     %i0, %o0
F00150C8: 92100019                 mov     %i1, %o1
F00150CC: d42c0000                 stb     %o2, [%l0]
F00150D0: 7fffc54c                 call    _udiv
F00150D4: a0042001                 inc     %l0
F00150D8: b0920000                 orcc    %o0, %g0, %i0
F00150DC: 32bffff6                 bne,a   loc_F00150B4
F00150E0: 90100018                 mov     %i0, %o0
F00150E4: 80a76000                 cmp     %i5, 0
F00150E8: 02800012                 be      loc_F0015130
F00150EC: 9007bfe8                 add     %fp, var_18, %o0
F00150F0: 90240008                 sub     %l0, %o0, %o0
F00150F4: ba274008                 sub     %i5, %o0, %i5
F00150F8: 80a76000                 cmp     %i5, 0
F00150FC: 2480000e                 ble,a   loc_F0015134
F0015100: b007bfe8                 add     %fp, var_18, %i0
F0015104: 80a72000                 cmp     %i4, 0
F0015108: 02800003                 be      loc_F0015114
F001510C: 90102020                 mov     0x20, %o0 ! ' '
F0015110: 90102030                 mov     0x30, %o0 ! '0'
F0015114: 9210001a                 mov     %i2, %o1
F0015118: 40000076                 call    sub_F00152F0
F001511C: 9410001b                 mov     %i3, %o2
F0015120: ba077fff                 inc     -1, %i5
F0015124: 80a76000                 cmp     %i5, 0
F0015128: 14bffff8                 bg      loc_F0015108
F001512C: 80a72000                 cmp     %i4, 0
F0015130: b007bfe8                 add     %fp, var_18, %i0
F0015134: a0043fff                 inc     -1, %l0
F0015138: d04c0000                 ldsb    [%l0], %o0
F001513C: 9210001a                 mov     %i2, %o1
F0015140: 4000006c                 call    sub_F00152F0
F0015144: 9410001b                 mov     %i3, %o2
F0015148: 80a40018                 cmp     %l0, %i0
F001514C: 18bffffb                 bgu     loc_F0015138
F0015150: a0043fff                 inc     -1, %l0
F0015154: 81c7e008                 ret
F0015158: 81e80000                 restore
