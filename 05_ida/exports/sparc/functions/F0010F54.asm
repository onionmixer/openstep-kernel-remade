F0010F54: 9de3bf98                 save    %sp, -0x68, %sp
F0010F58: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0010F5C: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0010F60: a21421dc                 or      %l0, %lo(dword_F0133DDC), %l1
F0010F64: d0047ffc                 ld      [%l1-4], %o0
F0010F68: e4026024                 ld      [%o1+0x24], %l2
F0010F6C: 40021707                 call    _splusclock
F0010F70: e6020000                 ld      [%o0], %l3
F0010F74: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0010F78: d004e01c                 ld      [%l3+0x1C], %o0
F0010F7C: d0226030                 st      %o0, [%o1+0x30]
F0010F80: d0047ffc                 ld      [%l1-4], %o0
F0010F84: e4048000                 ld      [%l2], %l2
F0010F88: d0020000                 ld      [%o0], %o0
F0010F8C: d2022014                 ld      [%o0+0x14], %o1
F0010F90: 11000010                 sethi   0x4000, %o0
F0010F94: 808a4008                 btst    %o0, %o1
F0010F98: 02800005                 be      loc_F0010FAC
F0010F9C: d404e01c                 ld      [%l3+0x1C], %o2
F0010FA0: 113fffbf                 sethi   -0x10400, %o0
F0010FA4: 10800004                 ba      loc_F0010FB4
F0010FA8: 901222ff                 bset    0x2FF, %o0
F0010FAC: 113ffebf901222ff         set     -0x50101, %o0
F0010FB4: 900c8008                 and     %l2, %o0, %o0
F0010FB8: 90128008                 bset    %o2, %o0
F0010FBC: 40021749                 call    _spl0
F0010FC0: d024e01c                 st      %o0, [%l3+0x1C]
F0010FC4: 81c7e008                 ret
F0010FC8: 81e80000                 restore
