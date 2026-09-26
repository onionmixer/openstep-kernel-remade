F008F254: 9de3bf90                 save    %sp, -0x70, %sp
F008F258: 7fffff14                 call    sub_F008EEA8
F008F25C: 9010001b                 mov     %i3, %o0
F008F260: 912a2018                 sll     %o0, 24, %o0
F008F264: 80a22000                 cmp     %o0, 0
F008F268: 0280000a                 be      loc_F008F290
F008F26C: 133c0504                 sethi   %hi(paEmpty), %o1! SEL
F008F270: d0062014                 ld      [%i0+0x14], %o0! id
F008F274: 4001897f                 call    _objc_msgSend
F008F278: d20260fc                 ld      [%o1+%lo(paEmpty)], %o1
F008F27C: d0062014                 ld      [%i0+0x14], %o0! id
F008F280: 133c0504                 sethi   %hi(paAppendlist), %o1
F008F284: d2026100                 ld      [%o1+%lo(paAppendlist)], %o1! SEL
F008F288: 4001897a                 call    _objc_msgSend
F008F28C: 9410001a                 mov     %i2, %o2
F008F290: 9410001b                 mov     %i3, %o2
F008F294: d006200c                 ld      [%i0+0xC], %o0! id
F008F298: 133c0504                 sethi   %hi(paInsertkeyValue), %o1
F008F29C: d2026068                 ld      [%o1+%lo(paInsertkeyValue)], %o1! SEL
F008F2A0: 40018974                 call    _objc_msgSend
F008F2A4: 9610001a                 mov     %i2, %o3
F008F2A8: 80a22000                 cmp     %o0, 0
F008F2AC: 02800006                 be      locret_F008F2C4
F008F2B0: 80a2001a                 cmp     %o0, %i2
F008F2B4: 02800004                 be      locret_F008F2C4
F008F2B8: 01000000                 nop
F008F2BC: 7ffffef0                 call    sub_F008EE7C
F008F2C0: 01000000                 nop
F008F2C4: 81c7e008                 ret
F008F2C8: 81e80000                 restore
