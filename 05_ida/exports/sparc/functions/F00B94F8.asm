F00B94F8: 9de3bf98                 save    %sp, -0x68, %sp
F00B94FC: 213c04fc                 sethi   %hi(_dma_map), %l0
F00B9500: d0042080                 ld      [%l0+%lo(_dma_map)], %o0
F00B9504: 80a22000                 cmp     %o0, 0
F00B9508: 12800010                 bne     loc_F00B9548
F00B950C: 153c047e                 sethi   -0xFEE0800, %o2
F00B9510: 113c0474                 sethi   %hi(_ndma_map), %o0
F00B9514: d00221d8                 ld      [%o0+%lo(_ndma_map)], %o0
F00B9518: 7ffebad6                 call    _kalloc
F00B951C: 912a2004                 sll     %o0, 4, %o0
F00B9520: 80a22000                 cmp     %o0, 0
F00B9524: 12800006                 bne     loc_F00B953C
F00B9528: d0242080                 st      %o0, [%l0+%lo(_dma_map)]
F00B952C: d206202c                 ld      [%i0+0x2C], %o1! size_t
F00B9530: 113c047e                 sethi   %hi(aEspdmaDNoSpace), %o0! "espdma%d: No space for dma_map structur"...
F00B9534: 10800027                 ba      loc_F00B95D0
F00B9538: 90122230                 bset    %lo(aEspdmaDNoSpace), %o0! "espdma%d: No space for dma_map structur"...
F00B953C: 7fff6e47                 call    _bzero
F00B9540: 92102010                 mov     0x10, %o1
F00B9544: 153c047e                 sethi   -0xFEE0800, %o2
F00B9548: d00aa22f                 ldub    [%o2+0x22F], %o0
F00B954C: 92022001                 add     %o0, 1, %o1
F00B9550: d22aa22f                 stb     %o1, [%o2+0x22F]
F00B9554: 912a2018                 sll     %o0, 24, %o0
F00B9558: 933a2018                 sra     %o0, 24, %o1
F00B955C: 113c0474                 sethi   %hi(_ndma_map), %o0
F00B9560: d00221d8                 ld      [%o0+%lo(_ndma_map)], %o0
F00B9564: 80a24008                 cmp     %o1, %o0
F00B9568: 06800005                 bl      loc_F00B957C
F00B956C: d226202c                 st      %o1, [%i0+0x2C]
F00B9570: 113c047e                 sethi   %hi(aEspdmaDBadUnit), %o0! "espdma%d: bad unit number\n"
F00B9574: 10800017                 ba      loc_F00B95D0
F00B9578: 90122260                 bset    %lo(aEspdmaDBadUnit), %o0! "espdma%d: bad unit number\n"
F00B957C: d0062010                 ld      [%i0+0x10], %o0
F00B9580: 80a22002                 cmp     %o0, 2
F00B9584: 113c04fc                 sethi   %hi(_dma_map), %o0
F00B9588: e4022080                 ld      [%o0+%lo(_dma_map)], %l2
F00B958C: a32a6004                 sll     %o1, 4, %l1
F00B9590: 04800005                 ble     loc_F00B95A4
F00B9594: a0048011                 add     %l2, %l1, %l0
F00B9598: 113c047e                 sethi   %hi(aEspdmaDBadRegi), %o0! "espdma%d: bad register specification\n"
F00B959C: 1080000d                 ba      loc_F00B95D0
F00B95A0: 90122280                 bset    %lo(aEspdmaDBadRegi), %o0! "espdma%d: bad register specification\n"
F00B95A4: d4062014                 ld      [%i0+0x14], %o2
F00B95A8: d002a004                 ld      [%o2+4], %o0
F00B95AC: d202a008                 ld      [%o2+8], %o1
F00B95B0: 7fffe01b                 call    _map_regs
F00B95B4: d4028000                 ld      [%o2], %o2
F00B95B8: 80a22000                 cmp     %o0, 0
F00B95BC: 12800008                 bne     loc_F00B95DC
F00B95C0: d0248011                 st      %o0, [%l2+%l1]
F00B95C4: d206202c                 ld      [%i0+0x2C], %o1
F00B95C8: 113c047e901222a8         set     aEspdmaDUnableT, %o0! "espdma%d: unable to map registers\n"
F00B95D0: 7ffd6c22                 call    _printf
F00B95D4: b0103fff                 mov     -1, %i0
F00B95D8: 3080001a                 ba,a    locret_F00B9640
F00B95DC: d0062014                 ld      [%i0+0x14], %o0
F00B95E0: d0020000                 ld      [%o0], %o0
F00B95E4: d0242004                 st      %o0, [%l0+4]
F00B95E8: d0062014                 ld      [%i0+0x14], %o0
F00B95EC: d0022004                 ld      [%o0+4], %o0
F00B95F0: d0242008                 st      %o0, [%l0+8]
F00B95F4: 90102001                 mov     1, %o0
F00B95F8: d02c200c                 stb     %o0, [%l0+0xC]
F00B95FC: d0062018                 ld      [%i0+0x18], %o0
F00B9600: 80a22000                 cmp     %o0, 0
F00B9604: 0280000a                 be      loc_F00B962C
F00B9608: 133c02e5                 sethi   %hi(_espdmaintr), %o1
F00B960C: d406200c                 ld      [%i0+0xC], %o2
F00B9610: d006201c                 ld      [%i0+0x1C], %o0
F00B9614: 92126248                 bset    %lo(_espdmaintr), %o1
F00B9618: d606202c                 ld      [%i0+0x2C], %o3
F00B961C: 98102000                 mov     0, %o4
F00B9620: d0020000                 ld      [%o0], %o0
F00B9624: 7fff7e8e                 call    _addintr
F00B9628: 9a102000                 mov     0, %o5
F00B962C: 7fffde03                 call    _report_dev
F00B9630: 90100018                 mov     %i0, %o0
F00B9634: 7fffdd72                 call    _attach_devs
F00B9638: 90100018                 mov     %i0, %o0
F00B963C: b0102000                 mov     0, %i0
F00B9640: 81c7e008                 ret
F00B9644: 81e80000                 restore
