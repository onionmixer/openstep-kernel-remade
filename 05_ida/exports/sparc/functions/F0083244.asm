F0083244: 9de3bf98                 save    %sp, -0x68, %sp
F0083248: 133c04f092126240         set     _vm_stat, %o1
F0083250: d0026024                 ld      [%o1+0x24], %o0
F0083254: 90022001                 inc     %o0
F0083258: d0226024                 st      %o0, [%o1+0x24]
F008325C: d206a018                 ld      [%i2+0x18], %o1
F0083260: 11280000                 sethi   -0x60000000, %o0
F0083264: 808a4008                 btst    %o0, %o1
F0083268: 22800004                 be,a    loc_F0083278
F008326C: e406a01c                 ld      [%i2+0x1C], %l2
F0083270: 1080008e                 ba      locret_F00834A8
F0083274: b0102005                 mov     5, %i0
F0083278: d006a008                 ld      [%i2+8], %o0
F008327C: d206a014                 ld      [%i2+0x14], %o1
F0083280: 90264008                 sub     %i1, %o0, %o0
F0083284: f406a010                 ld      [%i2+0x10], %i2
F0083288: a2020009                 add     %o0, %o1, %l1
F008328C: a006a010                 add     %i2, 0x10, %l0
F0083290: d0040000                 ld      [%l0], %o0
F0083294: 80a22000                 cmp     %o0, 0
F0083298: 12bffffe                 bne     loc_F0083290
F008329C: 01000000                 nop
F00832A0: 40004f02                 call    _simple_lock_try
F00832A4: 90100010                 mov     %l0, %o0
F00832A8: 80a22000                 cmp     %o0, 0
F00832AC: 02bffff9                 be      loc_F0083290
F00832B0: 9010001a                 mov     %i2, %o0
F00832B4: d616a018                 lduh    [%i2+0x18], %o3
F00832B8: 92100011                 mov     %l1, %o1
F00832BC: d416a044                 lduh    [%i2+0x44], %o2
F00832C0: 9602e001                 inc     %o3
F00832C4: d636a018                 sth     %o3, [%i2+0x18]
F00832C8: 9402a001                 inc     %o2
F00832CC: 40001733                 call    _vm_page_lookup
F00832D0: d436a044                 sth     %o2, [%i2+0x44]
F00832D4: a2920000                 orcc    %o0, %g0, %l1
F00832D8: 02800041                 be      loc_F00833DC
F00832DC: 11210000                 sethi   -0x7C000000, %o0
F00832E0: d2046020                 ld      [%l1+0x20], %o1
F00832E4: 808a4008                 btst    %o0, %o1
F00832E8: 1280003d                 bne     loc_F00833DC
F00832EC: 01000000                 nop
F00832F0: d0046028                 ld      [%l1+0x28], %o0
F00832F4: 808c8008                 btst    %o0, %l2
F00832F8: 12800039                 bne     loc_F00833DC
F00832FC: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0083300: a0122230                 or      %o0, %lo(_vm_page_queue_lock), %l0
F0083304: d0040000                 ld      [%l0], %o0
F0083308: 80a22000                 cmp     %o0, 0
F008330C: 12bffffe                 bne     loc_F0083304
F0083310: 01000000                 nop
F0083314: 40004ee5                 call    _simple_lock_try
F0083318: 90100010                 mov     %l0, %o0
F008331C: 80a22000                 cmp     %o0, 0
F0083320: 02bffff9                 be      loc_F0083304
F0083324: 01000000                 nop
F0083328: 4000187a                 call    _vm_page_wire
F008332C: 90100011                 mov     %l1, %o0
F0083330: 153c04f0                 sethi   %hi(_vm_page_queue_lock), %o2
F0083334: c022a230                 clr     [%o2+%lo(_vm_page_queue_lock)]
F0083338: d0046020                 ld      [%l1+0x20], %o0
F008333C: 13200000                 sethi   0x80000000, %o1
F0083340: 90120009                 bset    %o1, %o0
F0083344: 13010000                 sethi   0x4000000, %o1
F0083348: 922a0009                 andn    %o0, %o1, %o1
F008334C: d2246020                 st      %o1, [%l1+0x20]
F0083350: d006a01c                 ld      [%i2+0x1C], %o0
F0083354: 80a22000                 cmp     %o0, 0
F0083358: 02800029                 be      loc_F00833FC
F008335C: a012a230                 or      %o2, %lo(_vm_page_queue_lock), %l0
F0083360: 808ca002                 btst    2, %l2
F0083364: 12800006                 bne     loc_F008337C
F0083368: 11200000                 sethi   0x80000000, %o0
F008336C: 1100080090124008         set     0x200000, %o0
F0083374: 10800023                 ba      loc_F0083400
F0083378: d0246020                 st      %o0, [%l1+0x20]
F008337C: 922a4008                 bclr    %o0, %o1
F0083380: 11100000                 sethi   0x40000000, %o0
F0083384: 808a4008                 btst    %o0, %o1
F0083388: 02800008                 be      loc_F00833A8
F008338C: d2246020                 st      %o1, [%l1+0x20]
F0083390: 902a4008                 andn    %o1, %o0, %o0
F0083394: d0246020                 st      %o0, [%l1+0x20]
F0083398: 90100011                 mov     %l1, %o0
F008339C: 92102000                 mov     0, %o1
F00833A0: 7fffb717                 call    _thread_wakeup_prim
F00833A4: 94102000                 mov     0, %o2
F00833A8: d0040000                 ld      [%l0], %o0
F00833AC: 80a22000                 cmp     %o0, 0
F00833B0: 12bffffe                 bne     loc_F00833A8
F00833B4: 01000000                 nop
F00833B8: 40004ebc                 call    _simple_lock_try
F00833BC: 90100010                 mov     %l0, %o0
F00833C0: 80a22000                 cmp     %o0, 0
F00833C4: 02bffff9                 be      loc_F00833A8
F00833C8: 01000000                 nop
F00833CC: 400018a1                 call    _vm_page_unwire
F00833D0: 90100011                 mov     %l1, %o0
F00833D4: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F00833D8: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F00833DC: c026a010                 clr     [%i2+0x10]
F00833E0: d216a044                 lduh    [%i2+0x44], %o1
F00833E4: 9010001a                 mov     %i2, %o0
F00833E8: 92027fff                 inc     -1, %o1
F00833EC: 40000d33                 call    _vm_object_deallocate
F00833F0: d2322044                 sth     %o1, [%o0+0x44]
F00833F4: 1080002d                 ba      locret_F00834A8
F00833F8: b0102005                 mov     5, %i0
F00833FC: 808ca002                 btst    2, %l2
F0083400: 02800005                 be      loc_F0083414
F0083404: 11000800                 sethi   0x200000, %o0
F0083408: d2046020                 ld      [%l1+0x20], %o1
F008340C: 902a4008                 andn    %o1, %o0, %o0
F0083410: d0246020                 st      %o0, [%l1+0x20]
F0083414: c026a010                 clr     [%i2+0x10]
F0083418: 92100019                 mov     %i1, %o1
F008341C: 9406a010                 add     %i2, 0x10, %o2
F0083420: a010000a                 mov     %o2, %l0
F0083424: d0062024                 ld      [%i0+0x24], %o0
F0083428: 96100012                 mov     %l2, %o3
F008342C: d4046024                 ld      [%l1+0x24], %o2
F0083430: 40006c1f                 call    _pmap_enter
F0083434: 98102001                 mov     1, %o4
F0083438: d0040000                 ld      [%l0], %o0
F008343C: 80a22000                 cmp     %o0, 0
F0083440: 12bffffe                 bne     loc_F0083438
F0083444: 01000000                 nop
F0083448: 40004e98                 call    _simple_lock_try
F008344C: 90100010                 mov     %l0, %o0
F0083450: 80a22000                 cmp     %o0, 0
F0083454: 02bffff9                 be      loc_F0083438
F0083458: 13200000                 sethi   0x80000000, %o1
F008345C: d0046020                 ld      [%l1+0x20], %o0
F0083460: 922a0009                 andn    %o0, %o1, %o1
F0083464: 11100000                 sethi   0x40000000, %o0
F0083468: 808a4008                 btst    %o0, %o1
F008346C: 02800008                 be      loc_F008348C
F0083470: d2246020                 st      %o1, [%l1+0x20]
F0083474: 902a4008                 andn    %o1, %o0, %o0
F0083478: d0246020                 st      %o0, [%l1+0x20]
F008347C: 90100011                 mov     %l1, %o0
F0083480: 92102000                 mov     0, %o1
F0083484: 7fffb6de                 call    _thread_wakeup_prim
F0083488: 94102000                 mov     0, %o2
F008348C: c026a010                 clr     [%i2+0x10]
F0083490: d216a044                 lduh    [%i2+0x44], %o1
F0083494: 9010001a                 mov     %i2, %o0
F0083498: 92027fff                 inc     -1, %o1
F008349C: 40000d07                 call    _vm_object_deallocate
F00834A0: d2322044                 sth     %o1, [%o0+0x44]
F00834A4: b0102000                 mov     0, %i0
F00834A8: 81c7e008                 ret
F00834AC: 81e80000                 restore
