F00DC410: 9de3bf90                 save    %sp, -0x70, %sp
F00DC414: 7ffe7aa0                 call    _kern_serv_kernel_task_port
F00DC418: a0102000                 mov     0, %l0
F00DC41C: a8100008                 mov     %o0, %l4
F00DC420: d0062028                 ld      [%i0+0x28], %o0! id
F00DC424: 133c0504                 sethi   %hi(paLock), %o1
F00DC428: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00DC42C: 40005511                 call    _objc_msgSend
F00DC430: a2102000                 mov     0, %l1
F00DC434: d206202c                 ld      [%i0+0x2C], %o1
F00DC438: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F00DC43C: 80a20009                 cmp     %o0, %o1
F00DC440: 02800012                 be      loc_F00DC488
F00DC444: 80a46000                 cmp     %l1, 0
F00DC448: a0100009                 mov     %o1, %l0
F00DC44C: 94100008                 mov     %o0, %o2! __n
F00DC450: d204200c                 ld      [%l0+0xC], %o1
F00DC454: d0040000                 ld      [%l0], %o0
F00DC458: 80a24008                 cmp     %o1, %o0
F00DC45C: 28800007                 bleu,a  loc_F00DC478
F00DC460: e004203c                 ld      [%l0+0x3C], %l0
F00DC464: d0042004                 ld      [%l0+4], %o0
F00DC468: 80a24008                 cmp     %o1, %o0
F00DC46C: 2a800006                 bcs,a   loc_F00DC484
F00DC470: a2102001                 mov     1, %l1
F00DC474: e004203c                 ld      [%l0+0x3C], %l0
F00DC478: 80a28010                 cmp     %o2, %l0
F00DC47C: 32bffff6                 bne,a   loc_F00DC454
F00DC480: d204200c                 ld      [%l0+0xC], %o1
F00DC484: 80a46000                 cmp     %l1, 0
F00DC488: 12800004                 bne     loc_F00DC498
F00DC48C: 01000000                 nop
F00DC490: 1080001e                 ba      loc_F00DC508
F00DC494: d0062028                 ld      [%i0+0x28], %o0
F00DC498: 7fffa6a6                 call    _IOMalloc
F00DC49C: 90102044                 mov     0x44, %o0! __dst
F00DC4A0: a2100008                 mov     %o0, %l1
F00DC4A4: 92100010                 mov     %l0, %o1! __src
F00DC4A8: 7ffcab7e                 call    _memcpy
F00DC4AC: 94102044                 mov     0x44, %o2 ! 'D'
F00DC4B0: 90100014                 mov     %l4, %o0
F00DC4B4: da04200c                 ld      [%l0+0xC], %o5
F00DC4B8: 92100011                 mov     %l1, %o1
F00DC4BC: d4040000                 ld      [%l0], %o2
F00DC4C0: 96102001                 mov     1, %o3
F00DC4C4: d8042010                 ld      [%l0+0x10], %o4
F00DC4C8: a623400a                 sub     %o5, %o2, %l3
F00DC4CC: d4042008                 ld      [%l0+8], %o2
F00DC4D0: a4230013                 sub     %o4, %l3, %l2
F00DC4D4: aa22800d                 sub     %o2, %o5, %l5
F00DC4D8: 4000608d                 call    _vm_allocate_EXTERNAL
F00DC4DC: 94100013                 mov     %l3, %o2! size_t
F00DC4E0: 80a22000                 cmp     %o0, 0
F00DC4E4: 22800013                 be,a    loc_F00DC530
F00DC4E8: c0242020                 clr     [%l0+0x20]
F00DC4EC: 113c03f1                 sethi   %hi(aAudioCannotAll), %o0! "Audio: cannot allocate record memory\n"
F00DC4F0: 7fffa701                 call    _IOLog
F00DC4F4: 901221b8                 bset    %lo(aAudioCannotAll), %o0! "Audio: cannot allocate record memory\n"
F00DC4F8: 90100011                 mov     %l1, %o0
F00DC4FC: 7fffa692                 call    _IOFree
F00DC500: 92102044                 mov     0x44, %o1 ! 'D'
F00DC504: d0062028                 ld      [%i0+0x28], %o0! id
F00DC508: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DC50C: 400054d9                 call    _objc_msgSend
F00DC510: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DC514: 90102001                 mov     1, %o0
F00DC518: 10800042                 ba      locret_F00DC620
F00DC51C: d02e2078                 stb     %o0, [%i0+0x78]
F00DC520: e2262030                 st      %l1, [%i0+0x30]
F00DC524: d024603c                 st      %o0, [%l1+0x3C]
F00DC528: 10800039                 ba      loc_F00DC60C
F00DC52C: d0246040                 st      %o0, [%l1+0x40]
F00DC530: d0040000                 ld      [%l0], %o0! void *
F00DC534: c0242028                 clr     [%l0+0x28]
F00DC538: d2044000                 ld      [%l1], %o1! void *
F00DC53C: 7ffee175                 call    _bcopy
F00DC540: 94100013                 mov     %l3, %o2
F00DC544: d2040000                 ld      [%l0], %o1
F00DC548: d4042010                 ld      [%l0+0x10], %o2
F00DC54C: 40005f97                 call    _vm_deallocate_EXTERNAL
F00DC550: 90100014                 mov     %l4, %o0
F00DC554: 80a22000                 cmp     %o0, 0
F00DC558: 02800006                 be      loc_F00DC570
F00DC55C: 113c03f1                 sethi   %hi(aAudioVmDealloc), %o0! "Audio: vm_deallocate: %s\n"
F00DC560: 901221e0                 bset    %lo(aAudioVmDealloc), %o0! "Audio: vm_deallocate: %s\n"
F00DC564: 133c03f1                 sethi   %hi(aMachErr), %o1! "MACH ERR"
F00DC568: 7fffa6e3                 call    _IOLog
F00DC56C: 92126020                 bset    %lo(aMachErr), %o1! "MACH ERR"
F00DC570: 90100014                 mov     %l4, %o0
F00DC574: 92100010                 mov     %l0, %o1
F00DC578: 94100012                 mov     %l2, %o2
F00DC57C: 40006064                 call    _vm_allocate_EXTERNAL
F00DC580: 96102001                 mov     1, %o3
F00DC584: 80a22000                 cmp     %o0, 0
F00DC588: 02800006                 be      loc_F00DC5A0
F00DC58C: 113c03f1                 sethi   %hi(aAudioCannotAll), %o0! "Audio: cannot allocate record memory\n"
F00DC590: 7fffa6d9                 call    _IOLog
F00DC594: 901221b8                 bset    %lo(aAudioCannotAll), %o0! "Audio: cannot allocate record memory\n"
F00DC598: aa102000                 mov     0, %l5
F00DC59C: a4102000                 mov     0, %l2
F00DC5A0: d0040000                 ld      [%l0], %o0
F00DC5A4: e4242010                 st      %l2, [%l0+0x10]
F00DC5A8: d2040000                 ld      [%l0], %o1
F00DC5AC: 90020012                 add     %o0, %l2, %o0
F00DC5B0: d0242004                 st      %o0, [%l0+4]
F00DC5B4: d224200c                 st      %o1, [%l0+0xC]
F00DC5B8: d0040000                 ld      [%l0], %o0
F00DC5BC: 92102001                 mov     1, %o1
F00DC5C0: 90020015                 add     %o0, %l5, %o0
F00DC5C4: d0242008                 st      %o0, [%l0+8]
F00DC5C8: e6246010                 st      %l3, [%l1+0x10]
F00DC5CC: d2246030                 st      %o1, [%l1+0x30]
F00DC5D0: d0044000                 ld      [%l1], %o0
F00DC5D4: d224602c                 st      %o1, [%l1+0x2C]
F00DC5D8: 90020013                 add     %o0, %l3, %o0
F00DC5DC: d0246004                 st      %o0, [%l1+4]
F00DC5E0: d0246008                 st      %o0, [%l1+8]
F00DC5E4: d024600c                 st      %o0, [%l1+0xC]
F00DC5E8: 9206202c                 add     %i0, 0x2C, %o1 ! ','
F00DC5EC: d006202c                 ld      [%i0+0x2C], %o0
F00DC5F0: 80a24008                 cmp     %o1, %o0
F00DC5F4: 22bfffcb                 be,a    loc_F00DC520
F00DC5F8: e226202c                 st      %l1, [%i0+0x2C]
F00DC5FC: d2246040                 st      %o1, [%l1+0x40]
F00DC600: d024603c                 st      %o0, [%l1+0x3C]
F00DC604: e226202c                 st      %l1, [%i0+0x2C]
F00DC608: e2222040                 st      %l1, [%o0+0x40]
F00DC60C: d0062028                 ld      [%i0+0x28], %o0! id
F00DC610: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DC614: 40005497                 call    _objc_msgSend
F00DC618: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DC61C: c02e2078                 clrb    [%i0+0x78]
F00DC620: 81c7e008                 ret
F00DC624: 81e80000                 restore
