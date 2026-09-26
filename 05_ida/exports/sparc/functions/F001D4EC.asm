F001D4EC: 9de3bf98                 save    %sp, -0x68, %sp
F001D4F0: 113c04d4                 sethi   %hi(_domains), %o0
F001D4F4: e20222b8                 ld      [%o0+%lo(_domains)], %l1
F001D4F8: 80a46000                 cmp     %l1, 0
F001D4FC: 02800018                 be      locret_F001D55C
F001D500: 01000000                 nop
F001D504: e0046014                 ld      [%l1+0x14], %l0
F001D508: d0046018                 ld      [%l1+0x18], %o0
F001D50C: 80a40008                 cmp     %l0, %o0
F001D510: 3a800010                 bcc,a   loc_F001D550
F001D514: e204601c                 ld      [%l1+0x1C], %l1
F001D518: d6042014                 ld      [%l0+0x14], %o3
F001D51C: 80a2e000                 cmp     %o3, 0
F001D520: 22800007                 be,a    loc_F001D53C
F001D524: d0046018                 ld      [%l1+0x18], %o0
F001D528: 90100018                 mov     %i0, %o0
F001D52C: 92100019                 mov     %i1, %o1
F001D530: 9fc2c000                 call    %o3
F001D534: 94102000                 mov     0, %o2
F001D538: d0046018                 ld      [%l1+0x18], %o0
F001D53C: a0042030                 inc     0x30, %l0 ! '0'
F001D540: 80a40008                 cmp     %l0, %o0
F001D544: 2abffff6                 bcs,a   loc_F001D51C
F001D548: d6042014                 ld      [%l0+0x14], %o3
F001D54C: e204601c                 ld      [%l1+0x1C], %l1
F001D550: 80a46000                 cmp     %l1, 0
F001D554: 32bfffed                 bne,a   loc_F001D508
F001D558: e0046014                 ld      [%l1+0x14], %l0
F001D55C: 81c7e008                 ret
F001D560: 81e80000                 restore
