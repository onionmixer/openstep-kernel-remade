F00C74B8: 9de3bf80                 save    %sp, -0x80, %sp
F00C74BC: aa100018                 mov     %i0, %l5
F00C74C0: b610001a                 mov     %i2, %i3
F00C74C4: 113c0506                 sethi   %hi(paPhysicaldisk_0), %o0! id
F00C74C8: d2022164                 ld      [%o0+%lo(paPhysicaldisk_0)], %o1! SEL
F00C74CC: ae102000                 mov     0, %l7
F00C74D0: 4000a8e8                 call    _objc_msgSend
F00C74D4: 90100015                 mov     %l5, %o0! id
F00C74D8: 133c0506                 sethi   %hi(paPhysicalblocks_0), %o1
F00C74DC: ac100008                 mov     %o0, %l6
F00C74E0: d2026160                 ld      [%o1+%lo(paPhysicalblocks_0)], %o1! SEL
F00C74E4: 4000a8e3                 call    _objc_msgSend
F00C74E8: 90100015                 mov     %l5, %o0! id
F00C74EC: 133c0504                 sethi   %hi(paName), %o1
F00C74F0: a0100008                 mov     %o0, %l0
F00C74F4: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C74F8: 4000a8de                 call    _objc_msgSend
F00C74FC: 90100015                 mov     %l5, %o0
F00C7500: a2100008                 mov     %o0, %l1
F00C7504: 90100016                 mov     %l6, %o0! id
F00C7508: 133c0504                 sethi   %hi(paIsdiskready), %o1
F00C750C: d2026164                 ld      [%o1+%lo(paIsdiskready)], %o1! SEL
F00C7510: 4000a8d8                 call    _objc_msgSend
F00C7514: 94102001                 mov     1, %o2
F00C7518: b0100008                 mov     %o0, %i0
F00C751C: 80a63bb2                 cmp     %i0, -0x44E
F00C7520: 02800006                 be      loc_F00C7538
F00C7524: 80a62000                 cmp     %i0, 0
F00C7528: 32800006                 bne,a   loc_F00C7540
F00C752C: 90100015                 mov     %l5, %o0
F00C7530: 1080000f                 ba      loc_F00C756C
F00C7534: 113c0504                 sethi   -0xFEBF000, %o0! id
F00C7538: 10800059                 ba      locret_F00C769C
F00C753C: b0103bb2                 mov     -0x44E, %i0
F00C7540: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00C7544: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1! SEL
F00C7548: 94100018                 mov     %i0, %o2
F00C754C: 213c03eb                 sethi   %hi(aSReadlabelBogu), %l0! "%s readLabel: bogus return from isDiskR"...
F00C7550: 4000a8c8                 call    _objc_msgSend
F00C7554: a0142158                 bset    %lo(aSReadlabelBogu), %l0! "%s readLabel: bogus return from isDiskR"...
F00C7558: 94100008                 mov     %o0, %o2
F00C755C: 90100010                 mov     %l0, %o0! id
F00C7560: 7ffffae5                 call    _IOLog
F00C7564: 92100011                 mov     %l1, %o1
F00C7568: 3080004d                 ba,a    locret_F00C769C
F00C756C: d2022178                 ld      [%o0+0x178], %o1! SEL
F00C7570: 4000a8c0                 call    _objc_msgSend
F00C7574: 90100016                 mov     %l6, %o0
F00C7578: 80a42000                 cmp     %l0, 0
F00C757C: 912a2018                 sll     %o0, 24, %o0
F00C7580: 02800005                 be      loc_F00C7594
F00C7584: 913a2018                 sra     %o0, 24, %o0
F00C7588: 80a22000                 cmp     %o0, 0
F00C758C: 12800006                 bne     loc_F00C75A4
F00C7590: 11000007                 sethi   0x1C00, %o0
F00C7594: 10800042                 ba      locret_F00C769C
F00C7598: b0103bb3                 mov     -0x44D, %i0
F00C759C: 10800031                 ba      loc_F00C7660
F00C75A0: ae05e001                 inc     %l7
F00C75A4: 90122047                 bset    0x47, %o0 ! 'G'
F00C75A8: 90040008                 add     %l0, %o0, %o0
F00C75AC: 7ffcfc15                 call    _udiv
F00C75B0: 92100010                 mov     %l0, %o1
F00C75B4: a8100008                 mov     %o0, %l4
F00C75B8: 7ffcfbd2                 call    _umul
F00C75BC: 92100010                 mov     %l0, %o1
F00C75C0: a2102000                 mov     0, %l1
F00C75C4: 353c0506                 sethi   -0xFEBE800, %i2
F00C75C8: a0102000                 mov     0, %l0
F00C75CC: 133c04d0                 sethi   %hi(_page_mask), %o1
F00C75D0: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F00C75D4: a4100008                 mov     %o0, %l2
F00C75D8: 90048009                 add     %l2, %o1, %o0
F00C75DC: b22a0009                 andn    %o0, %o1, %i1
F00C75E0: 7ffffa54                 call    _IOMalloc
F00C75E4: 90100019                 mov     %i1, %o0
F00C75E8: a6100008                 mov     %o0, %l3
F00C75EC: 40000b15                 call    _IOVmTaskSelf
F00C75F0: 01000000                 nop
F00C75F4: d023a05c                 st      %o0, [%sp+0x80+var_24]
F00C75F8: 90100016                 mov     %l6, %o0! id
F00C75FC: d206a1c0                 ld      [%i2+0x1C0], %o1! SEL
F00C7600: 94100010                 mov     %l0, %o2
F00C7604: 96100012                 mov     %l2, %o3
F00C7608: 98100013                 mov     %l3, %o4
F00C760C: 4000a899                 call    _objc_msgSend
F00C7610: 9a07bfec                 add     %fp, var_14, %o5
F00C7614: b0920000                 orcc    %o0, %g0, %i0
F00C7618: 1280000c                 bne     loc_F00C7648
F00C761C: 80a63bb2                 cmp     %i0, -0x44E
F00C7620: d007bfec                 ld      [%fp+var_14], %o0
F00C7624: 80a20012                 cmp     %o0, %l2
F00C7628: 12800008                 bne     loc_F00C7648
F00C762C: 80a63bb2                 cmp     %i0, -0x44E
F00C7630: 90100013                 mov     %l3, %o0
F00C7634: 4000674e                 call    _check_label
F00C7638: 92100010                 mov     %l0, %o1
F00C763C: 80a22000                 cmp     %o0, 0
F00C7640: 02bfffd7                 be      loc_F00C759C
F00C7644: 80a63bb2                 cmp     %i0, -0x44E
F00C7648: 02800007                 be      loc_F00C7664
F00C764C: 80a5e000                 cmp     %l7, 0
F00C7650: a2046001                 inc     %l1
F00C7654: 80a46003                 cmp     %l1, 3
F00C7658: 04bfffe5                 ble     loc_F00C75EC
F00C765C: a0040014                 add     %l0, %l4, %l0
F00C7660: 80a5e000                 cmp     %l7, 0
F00C7664: 02800008                 be      loc_F00C7684
F00C7668: 90102001                 mov     1, %o0
F00C766C: d02d61a8                 stb     %o0, [%l5+0x1A8]
F00C7670: 90100013                 mov     %l3, %o0
F00C7674: 4000644d                 call    _get_disk_label
F00C7678: 9210001b                 mov     %i3, %o1
F00C767C: 10800005                 ba      loc_F00C7690
F00C7680: b0102000                 mov     0, %i0
F00C7684: 80a63bb2                 cmp     %i0, -0x44E
F00C7688: 32800002                 bne,a   loc_F00C7690
F00C768C: b0103bb4                 mov     -0x44C, %i0
F00C7690: 90100013                 mov     %l3, %o0
F00C7694: 7ffffa2c                 call    _IOFree
F00C7698: 92100019                 mov     %i1, %o1
F00C769C: 81c7e008                 ret
F00C76A0: 81e80000                 restore
