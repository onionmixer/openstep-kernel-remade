F003D4D8: 9de3bf98                 save    %sp, -0x68, %sp
F003D4DC: 113c04eaa21222a0         set     _rtable, %l1
F003D4E4: 90046100                 add     %l1, 0x100, %o0
F003D4E8: 80a44008                 cmp     %l1, %o0
F003D4EC: 1a80001e                 bcc     locret_F003D564
F003D4F0: a4100008                 mov     %o0, %l2
F003D4F4: e0044000                 ld      [%l1], %l0
F003D4F8: 80a42000                 cmp     %l0, 0
F003D4FC: 22800017                 be,a    loc_F003D558
F003D500: a2046004                 inc     4, %l1
F003D504: d0142010                 lduh    [%l0+0x10], %o0
F003D508: 808a2080                 btst    0x80, %o0
F003D50C: 1280000e                 bne     loc_F003D544
F003D510: 9404200c                 add     %l0, 0xC, %o2
F003D514: d2042030                 ld      [%l0+0x30], %o1
F003D518: d002600c                 ld      [%o1+0xC], %o0
F003D51C: 808a2001                 btst    1, %o0
F003D520: 3280000a                 bne,a   loc_F003D548
F003D524: e0042008                 ld      [%l0+8], %l0
F003D528: 80a62000                 cmp     %i0, 0
F003D52C: 02800004                 be      loc_F003D53C
F003D530: 80a24018                 cmp     %o1, %i0
F003D534: 32800005                 bne,a   loc_F003D548
F003D538: e0042008                 ld      [%l0+8], %l0
F003D53C: 40000e0d                 call    _sync_vp
F003D540: 9010000a                 mov     %o2, %o0
F003D544: e0042008                 ld      [%l0+8], %l0
F003D548: 80a42000                 cmp     %l0, 0
F003D54C: 32bfffef                 bne,a   loc_F003D508
F003D550: d0142010                 lduh    [%l0+0x10], %o0
F003D554: a2046004                 inc     4, %l1
F003D558: 80a44012                 cmp     %l1, %l2
F003D55C: 2abfffe7                 bcs,a   loc_F003D4F8
F003D560: e0044000                 ld      [%l1], %l0
F003D564: 81c7e008                 ret
F003D568: 81e80000                 restore
