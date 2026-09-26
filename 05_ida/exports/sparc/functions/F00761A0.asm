F00761A0: 9de3bf80                 save    %sp, -0x80, %sp
F00761A4: f227bff4                 st      %i1, [%fp+var_C]
F00761A8: f427bfec                 st      %i2, [%fp+var_14]
F00761AC: 80a62000                 cmp     %i0, 0
F00761B0: 12800007                 bne     loc_F00761CC
F00761B4: f627bfe4                 st      %i3, [%fp+var_1C]
F00761B8: 1080007d                 ba      locret_F00763AC
F00761BC: b0102004                 mov     4, %i0
F00761C0: c0262158                 clr     [%i0+0x158]
F00761C4: 1080007a                 ba      locret_F00763AC
F00761C8: b0102004                 mov     4, %i0
F00761CC: a8102000                 mov     0, %l4
F00761D0: aa102000                 mov     0, %l5
F00761D4: a2062158                 add     %i0, 0x158, %l1
F00761D8: d0044000                 ld      [%l1], %o0
F00761DC: 80a22000                 cmp     %o0, 0
F00761E0: 12bffffe                 bne     loc_F00761D8
F00761E4: 01000000                 nop
F00761E8: 40008330                 call    _simple_lock_try
F00761EC: 90100011                 mov     %l1, %o0
F00761F0: 80a22000                 cmp     %o0, 0
F00761F4: 02bffff9                 be      loc_F00761D8
F00761F8: 01000000                 nop
F00761FC: d0062154                 ld      [%i0+0x154], %o0
F0076200: 80a22000                 cmp     %o0, 0
F0076204: 02bfffef                 be      loc_F00761C0
F0076208: 01000000                 nop
F007620C: e6062140                 ld      [%i0+0x140], %l3
F0076210: a12ce002                 sll     %l3, 2, %l0
F0076214: 80a40014                 cmp     %l0, %l4
F0076218: 08800010                 bleu    loc_F0076258
F007621C: a4102000                 mov     0, %l2
F0076220: c0262158                 clr     [%i0+0x158]
F0076224: 80a52000                 cmp     %l4, 0
F0076228: 02800004                 be      loc_F0076238
F007622C: 90100015                 mov     %l5, %o0
F0076230: 7fffc7dc                 call    _kfree
F0076234: 92100014                 mov     %l4, %o1
F0076238: a8100010                 mov     %l0, %l4
F007623C: 7fffc78d                 call    _kalloc
F0076240: 90100014                 mov     %l4, %o0
F0076244: aa920000                 orcc    %o0, %g0, %l5
F0076248: 12bfffe4                 bne     loc_F00761D8
F007624C: 01000000                 nop
F0076250: 10800057                 ba      locret_F00763AC
F0076254: b0102006                 mov     6, %i0
F0076258: e0062138                 ld      [%i0+0x138], %l0
F007625C: 80a48013                 cmp     %l2, %l3
F0076260: 1a80000b                 bcc     loc_F007628C
F0076264: ae100015                 mov     %l5, %l7
F0076268: a2102000                 mov     0, %l1
F007626C: 7ffff972                 call    _thread_reference
F0076270: 90100010                 mov     %l0, %o0
F0076274: e0244017                 st      %l0, [%l1+%l7]
F0076278: a2046004                 inc     4, %l1
F007627C: a404a001                 inc     %l2
F0076280: 80a48013                 cmp     %l2, %l3
F0076284: 0abffffa                 bcs     loc_F007626C
F0076288: e0042018                 ld      [%l0+0x18], %l0
F007628C: c0262158                 clr     [%i0+0x158]
F0076290: a2102000                 mov     0, %l1
F0076294: ac102000                 mov     0, %l6
F0076298: b2102000                 mov     0, %i1
F007629C: 80a64013                 cmp     %i1, %l3
F00762A0: 1a80002c                 bcc     loc_F0076350
F00762A4: a4102000                 mov     0, %l2
F00762A8: 113c04d0b6122260         set     _active_threads, %i3
F00762B0: 113c04f0b4122058         set     _active_stacks, %i2
F00762B8: b0102000                 mov     0, %i0
F00762BC: e0060017                 ld      [%i0+%l7], %l0
F00762C0: d004204c                 ld      [%l0+0x4C], %o0
F00762C4: 808a2100                 btst    0x100, %o0
F00762C8: 1280000e                 bne     loc_F0076300
F00762CC: 96102000                 mov     0, %o3
F00762D0: d604202c                 ld      [%l0+0x2C], %o3
F00762D4: 94102000                 mov     0, %o2
F00762D8: 92102000                 mov     0, %o1
F00762DC: d002401b                 ld      [%o1+%i3], %o0
F00762E0: 80a20010                 cmp     %o0, %l0
F00762E4: 32800004                 bne,a   loc_F00762F4
F00762E8: 9402a001                 inc     %o2
F00762EC: 10800005                 ba      loc_F0076300
F00762F0: d602401a                 ld      [%o1+%i2], %o3
F00762F4: 80a2a000                 cmp     %o2, 0
F00762F8: 04bffff9                 ble     loc_F00762DC
F00762FC: 92026004                 inc     4, %o1
F0076300: 80a2e000                 cmp     %o3, 0
F0076304: 0280000d                 be      loc_F0076338
F0076308: 113c0442                 sethi   %hi(_stack_check_usage), %o0
F007630C: d0022290                 ld      [%o0+%lo(_stack_check_usage)], %o0
F0076310: 80a22000                 cmp     %o0, 0
F0076314: 02800009                 be      loc_F0076338
F0076318: a2046001                 inc     %l1
F007631C: 7fffff35                 call    _stack_usage
F0076320: 9010000b                 mov     %o3, %o0
F0076324: 80a20016                 cmp     %o0, %l6
F0076328: 08800004                 bleu    loc_F0076338
F007632C: 01000000                 nop
F0076330: ac100008                 mov     %o0, %l6
F0076334: b2100010                 mov     %l0, %i1
F0076338: 7ffff81d                 call    _thread_deallocate
F007633C: 90100010                 mov     %l0, %o0
F0076340: a404a001                 inc     %l2
F0076344: 80a48013                 cmp     %l2, %l3
F0076348: 0abfffdd                 bcs     loc_F00762BC
F007634C: b0062004                 inc     4, %i0
F0076350: 80a52000                 cmp     %l4, 0
F0076354: 02800004                 be      loc_F0076364
F0076358: 90100015                 mov     %l5, %o0
F007635C: 7fffc791                 call    _kfree
F0076360: 92100014                 mov     %l4, %o1
F0076364: 912c600a                 sll     %l1, 10, %o0
F0076368: 90220011                 sub     %o0, %l1, %o0
F007636C: 912a2002                 sll     %o0, 2, %o0
F0076370: 90020011                 add     %o0, %l1, %o0
F0076374: d807bff4                 ld      [%fp+var_C], %o4
F0076378: 133c04d0                 sethi   %hi(_page_mask), %o1
F007637C: e2230000                 st      %l1, [%o4]
F0076380: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F0076384: 912a2002                 sll     %o0, 2, %o0
F0076388: d807bfec                 ld      [%fp+var_14], %o4
F007638C: 90020009                 add     %o0, %o1, %o0
F0076390: 922a0009                 andn    %o0, %o1, %o1
F0076394: d2230000                 st      %o1, [%o4]
F0076398: d807bfe4                 ld      [%fp+var_1C], %o4
F007639C: b0102000                 mov     0, %i0
F00763A0: d2230000                 st      %o1, [%o4]
F00763A4: ec270000                 st      %l6, [%i4]
F00763A8: f2274000                 st      %i1, [%i5]
F00763AC: 81c7e008                 ret
F00763B0: 81e80000                 restore
