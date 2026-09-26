F0093F7C: 9de3bf98                 save    %sp, -0x68, %sp
F0093F80: 7fff503c                 call    _kalloc
F0093F84: 11000008                 sethi   0x2000, %o0
F0093F88: a2100008                 mov     %o0, %l1
F0093F8C: 293c0449                 sethi   -0xFEEDC00, %l4
F0093F90: 27000008                 sethi   0x2000, %l3
F0093F94: 253c0449                 sethi   -0xFEEDC00, %l2
F0093F98: e6246004                 st      %l3, [%l1+4]
F0093F9C: 90100011                 mov     %l1, %o0! char *
F0093FA0: 92102000                 mov     0, %o1
F0093FA4: d605211c                 ld      [%l4+0x11C], %o3
F0093FA8: 94102000                 mov     0, %o2
F0093FAC: 7fff47ac                 call    _msg_receive
F0093FB0: d624600c                 st      %o3, [%l1+0xC]
F0093FB4: 92920000                 orcc    %o0, %g0, %o1
F0093FB8: 22800006                 be,a    loc_F0093FD0
F0093FBC: d2046014                 ld      [%l1+0x14], %o1
F0093FC0: 7ffe01a6                 call    _printf
F0093FC4: 9014a3f8                 or      %l2, 0x3F8, %o0
F0093FC8: 10bffff5                 ba      loc_F0093F9C
F0093FCC: e6246004                 st      %l3, [%l1+4]
F0093FD0: 80a26041                 cmp     %o1, 0x41 ! 'A'
F0093FD4: 02800016                 be      loc_F009402C
F0093FD8: 80a26357                 cmp     %o1, 0x357
F0093FDC: 12800018                 bne     loc_F009403C
F0093FE0: 113c044a                 sethi   -0xFEED800, %o0
F0093FE4: 4000001c                 call    sub_F0094054
F0093FE8: d004601c                 ld      [%l1+0x1C], %o0
F0093FEC: a0920000                 orcc    %o0, %g0, %l0
F0093FF0: 22bfffeb                 be,a    loc_F0093F9C
F0093FF4: e6246004                 st      %l3, [%l1+4]
F0093FF8: d604200c                 ld      [%l0+0xC], %o3
F0093FFC: 80a2e000                 cmp     %o3, 0
F0094000: 02800007                 be      loc_F009401C
F0094004: 90100010                 mov     %l0, %o0
F0094008: d0042010                 ld      [%l0+0x10], %o0
F009400C: d2042008                 ld      [%l0+8], %o1
F0094010: 9fc2c000                 call    %o3
F0094014: d4046020                 ld      [%l1+0x20], %o2
F0094018: 90100010                 mov     %l0, %o0
F009401C: 7fff5061                 call    _kfree
F0094020: 92102014                 mov     0x14, %o1
F0094024: 10bfffde                 ba      loc_F0093F9C
F0094028: e6246004                 st      %l3, [%l1+4]
F009402C: 4000002a                 call    sub_F00940D4
F0094030: 90100011                 mov     %l1, %o0! char *
F0094034: 10bfffda                 ba      loc_F0093F9C
F0094038: e6246004                 st      %l3, [%l1+4]
F009403C: 7ffe0187                 call    _printf
F0094040: 90122020                 bset    0x20, %o0 ! ' '
F0094044: 10bfffd6                 ba      loc_F0093F9C
F0094048: e6246004                 st      %l3, [%l1+4]
