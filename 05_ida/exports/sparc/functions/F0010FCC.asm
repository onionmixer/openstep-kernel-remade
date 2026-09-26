F0010FCC: 9de3bf98                 save    %sp, -0x68, %sp
F0010FD0: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0010FD4: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0010FD8: a21421dc                 or      %l0, %lo(dword_F0133DDC), %l1
F0010FDC: d0047ffc                 ld      [%l1-4], %o0
F0010FE0: e4026024                 ld      [%o1+0x24], %l2
F0010FE4: 400216e9                 call    _splusclock
F0010FE8: e6020000                 ld      [%o0], %l3
F0010FEC: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0010FF0: d004e01c                 ld      [%l3+0x1C], %o0
F0010FF4: d0226030                 st      %o0, [%o1+0x30]
F0010FF8: d0047ffc                 ld      [%l1-4], %o0
F0010FFC: d0020000                 ld      [%o0], %o0
F0011000: d2022014                 ld      [%o0+0x14], %o1
F0011004: 11000010                 sethi   0x4000, %o0
F0011008: 808a4008                 btst    %o0, %o1
F001100C: 02800005                 be      loc_F0011020
F0011010: e4048000                 ld      [%l2], %l2
F0011014: 113fffbf                 sethi   -0x10400, %o0
F0011018: 10800004                 ba      loc_F0011028
F001101C: 901222ff                 bset    0x2FF, %o0
F0011020: 113ffebf901222ff         set     -0x50101, %o0
F0011028: a40c8008                 and     %l2, %o0, %l2
F001102C: 4002172d                 call    _spl0
F0011030: e424e01c                 st      %l2, [%l3+0x1C]
F0011034: 81c7e008                 ret
F0011038: 81e80000                 restore
