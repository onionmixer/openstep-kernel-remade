F005524C: 9de3bf98                 save    %sp, -0x68, %sp
F0055250: 80a66017                 cmp     %i1, 0x17
F0055254: 08800007                 bleu    loc_F0055270
F0055258: 808e6003                 btst    3, %i1
F005525C: 32800006                 bne,a   loc_F0055274
F0055260: 31040000                 sethi   0x10000000, %i0
F0055264: 80a6a000                 cmp     %i2, 0
F0055268: 04800005                 ble     loc_F005527C
F005526C: 80a660ec                 cmp     %i1, 0xEC
F0055270: 31040000                 sethi   0x10000000, %i0
F0055274: 10800033                 ba      locret_F0055340
F0055278: b0162008                 bset    8, %i0
F005527C: 1880000f                 bgu     loc_F00552B8
F0055280: 113c04ef                 sethi   %hi(_ipc_kmsg_cache), %o0
F0055284: e0022348                 ld      [%o0+%lo(_ipc_kmsg_cache)], %l0
F0055288: 80a42000                 cmp     %l0, 0
F005528C: 02800004                 be      loc_F005529C
F0055290: 01000000                 nop
F0055294: 10800017                 ba      loc_F00552F0
F0055298: c0222348                 clr     [%o0+%lo(_ipc_kmsg_cache)]
F005529C: 40004b75                 call    _kalloc
F00552A0: 90102100                 mov     0x100, %o0
F00552A4: a0920000                 orcc    %o0, %g0, %l0
F00552A8: 0280000a                 be      loc_F00552D0
F00552AC: 90102100                 mov     0x100, %o0
F00552B0: 1080000f                 ba      loc_F00552EC
F00552B4: d0242008                 st      %o0, [%l0+8]
F00552B8: a2066014                 add     %i1, 0x14, %l1
F00552BC: 40004b6d                 call    _kalloc
F00552C0: 90100011                 mov     %l1, %o0
F00552C4: a0920000                 orcc    %o0, %g0, %l0
F00552C8: 32800009                 bne,a   loc_F00552EC
F00552CC: e2242008                 st      %l1, [%l0+8]
F00552D0: 31040000                 sethi   0x10000000, %i0
F00552D4: 1080001b                 ba      locret_F0055340
F00552D8: b016200d                 bset    0xD, %i0
F00552DC: 40004bb1                 call    _kfree
F00552E0: 90100010                 mov     %l0, %o0
F00552E4: 10800012                 ba      loc_F005532C
F00552E8: 31040000                 sethi   0x10000000, %i0
F00552EC: c024200c                 clr     [%l0+0xC]
F00552F0: c0242010                 clr     [%l0+0x10]
F00552F4: 90100018                 mov     %i0, %o0
F00552F8: 92042014                 add     %l0, 0x14, %o1
F00552FC: 40010b6d                 call    _copyinmsg
F0055300: 9406401a                 add     %i1, %i2, %o2
F0055304: 80a22000                 cmp     %o0, 0
F0055308: 2280000b                 be,a    loc_F0055334
F005530C: f4242010                 st      %i2, [%l0+0x10]
F0055310: d2042008                 ld      [%l0+8], %o1
F0055314: 80a26000                 cmp     %o1, 0
F0055318: 14bffff1                 bg      loc_F00552DC
F005531C: 01000000                 nop
F0055320: 7fffffb8                 call    _ipc_kmsg_free
F0055324: 90100010                 mov     %l0, %o0
F0055328: 31040000                 sethi   0x10000000, %i0
F005532C: 10800005                 ba      locret_F0055340
F0055330: b0162002                 bset    2, %i0
F0055334: f2242018                 st      %i1, [%l0+0x18]
F0055338: e026c000                 st      %l0, [%i3]
F005533C: b0102000                 mov     0, %i0
F0055340: 81c7e008                 ret
F0055344: 81e80000                 restore
