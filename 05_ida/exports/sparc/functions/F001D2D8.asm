F001D2D8: 9de3bf98                 save    %sp, -0x68, %sp
F001D2DC: 133c042e921263b8         set     _unixdomain, %o1
F001D2E4: 113c0431901222f0         set     _inetdomain, %o0
F001D2EC: d222201c                 st      %o1, [%o0+0x1C]
F001D2F0: a2100008                 mov     %o0, %l1
F001D2F4: 113c04d4                 sethi   %hi(_domains), %o0
F001D2F8: d40222b8                 ld      [%o0+%lo(_domains)], %o2
F001D2FC: 80a46000                 cmp     %l1, 0
F001D300: d422601c                 st      %o2, [%o1+0x1C]
F001D304: d22222b8                 st      %o1, [%o0+%lo(_domains)]
F001D308: 0280001c                 be      loc_F001D378
F001D30C: e22222b8                 st      %l1, [%o0+%lo(_domains)]
F001D310: d0046008                 ld      [%l1+8], %o0
F001D314: 80a22000                 cmp     %o0, 0
F001D318: 22800005                 be,a    loc_F001D32C
F001D31C: e0046014                 ld      [%l1+0x14], %l0
F001D320: 9fc20000                 call    %o0
F001D324: 01000000                 nop
F001D328: e0046014                 ld      [%l1+0x14], %l0
F001D32C: d0046018                 ld      [%l1+0x18], %o0
F001D330: 80a40008                 cmp     %l0, %o0
F001D334: 3a80000e                 bcc,a   loc_F001D36C
F001D338: e204601c                 ld      [%l1+0x1C], %l1
F001D33C: d0042020                 ld      [%l0+0x20], %o0
F001D340: 80a22000                 cmp     %o0, 0
F001D344: 22800005                 be,a    loc_F001D358
F001D348: d0046018                 ld      [%l1+0x18], %o0
F001D34C: 9fc20000                 call    %o0
F001D350: 01000000                 nop
F001D354: d0046018                 ld      [%l1+0x18], %o0
F001D358: a0042030                 inc     0x30, %l0 ! '0'
F001D35C: 80a40008                 cmp     %l0, %o0
F001D360: 2abffff8                 bcs,a   loc_F001D340
F001D364: d0042020                 ld      [%l0+0x20], %o0
F001D368: e204601c                 ld      [%l1+0x1C], %l1
F001D36C: 80a46000                 cmp     %l1, 0
F001D370: 32bfffe9                 bne,a   loc_F001D314
F001D374: d0046008                 ld      [%l1+8], %o0
F001D378: 40003137                 call    _null_init
F001D37C: 01000000                 nop
F001D380: 4000009e                 call    _pffasttimo
F001D384: 01000000                 nop
F001D388: 40000077                 call    _pfslowtimo
F001D38C: 01000000                 nop
F001D390: 81c7e008                 ret
F001D394: 81e80000                 restore
