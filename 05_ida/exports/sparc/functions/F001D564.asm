F001D564: 9de3bf98                 save    %sp, -0x68, %sp
F001D568: 113c04d4                 sethi   %hi(_domains), %o0
F001D56C: e20222b8                 ld      [%o0+%lo(_domains)], %l1
F001D570: 80a46000                 cmp     %l1, 0
F001D574: 02800017                 be      loc_F001D5D0
F001D578: 113c0075                 sethi   -0xFFE2C00, %o0
F001D57C: e0046014                 ld      [%l1+0x14], %l0
F001D580: d0046018                 ld      [%l1+0x18], %o0
F001D584: 80a40008                 cmp     %l0, %o0
F001D588: 3a80000e                 bcc,a   loc_F001D5C0
F001D58C: e204601c                 ld      [%l1+0x1C], %l1
F001D590: d0042028                 ld      [%l0+0x28], %o0
F001D594: 80a22000                 cmp     %o0, 0
F001D598: 22800005                 be,a    loc_F001D5AC
F001D59C: d0046018                 ld      [%l1+0x18], %o0
F001D5A0: 9fc20000                 call    %o0
F001D5A4: 01000000                 nop
F001D5A8: d0046018                 ld      [%l1+0x18], %o0
F001D5AC: a0042030                 inc     0x30, %l0 ! '0'
F001D5B0: 80a40008                 cmp     %l0, %o0
F001D5B4: 2abffff8                 bcs,a   loc_F001D594
F001D5B8: d0042028                 ld      [%l0+0x28], %o0
F001D5BC: e204601c                 ld      [%l1+0x1C], %l1
F001D5C0: 80a46000                 cmp     %l1, 0
F001D5C4: 32bfffef                 bne,a   loc_F001D580
F001D5C8: e0046014                 ld      [%l1+0x14], %l0
F001D5CC: 113c0075                 sethi   -0xFFE2C00, %o0
F001D5D0: 133c043e                 sethi   %hi(_hz), %o1
F001D5D4: d40263e0                 ld      [%o1+%lo(_hz)], %o2
F001D5D8: 90122164                 bset    0x164, %o0! int
F001D5DC: 9332a01f                 srl     %o2, 31, %o1
F001D5E0: 94028009                 add     %o2, %o1, %o2
F001D5E4: 92102000                 mov     0, %o1
F001D5E8: 7fffb290                 call    _timeout
F001D5EC: 953aa001                 sra     %o2, 1, %o2
F001D5F0: 81c7e008                 ret
F001D5F4: 81e80000                 restore
