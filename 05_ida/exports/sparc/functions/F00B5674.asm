F00B5674: 9de3bf98                 save    %sp, -0x68, %sp
F00B5678: a0100018                 mov     %i0, %l0
F00B567C: e404209c                 ld      [%l0+0x9C], %l2
F00B5680: d05420b2                 ldsh    [%l0+0xB2], %o0
F00B5684: e20420a0                 ld      [%l0+0xA0], %l1
F00B5688: d20c2031                 ldub    [%l0+0x31], %o1
F00B568C: 912a2002                 sll     %o0, 2, %o0
F00B5690: 90020010                 add     %o0, %l0, %o0
F00B5694: 80a26000                 cmp     %o1, 0
F00B5698: 12800003                 bne     loc_F00B56A4
F00B569C: f00220b8                 ld      [%o0+0xB8], %i0
F00B56A0: c02ca00c                 clrb    [%l2+0xC]
F00B56A4: d016205c                 lduh    [%i0+0x5C], %o0
F00B56A8: 808a2001                 btst    1, %o0
F00B56AC: 12800008                 bne     loc_F00B56CC
F00B56B0: 19000004                 sethi   0x1000, %o4
F00B56B4: 90100010                 mov     %l0, %o0
F00B56B8: 133c0479                 sethi   %hi(aUnexpectedData), %o1! "unexpected data phase"
F00B56BC: 40000996                 call    _esp_printstate
F00B56C0: 921261f8                 bset    %lo(aUnexpectedData), %o1! "unexpected data phase"
F00B56C4: 10800066                 ba      loc_F00B585C
F00B56C8: 90102003                 mov     3, %o0
F00B56CC: 808a000c                 btst    %o4, %o0
F00B56D0: 91322001                 srl     %o0, 1, %o0
F00B56D4: 02800015                 be      loc_F00B5728
F00B56D8: a60a2001                 and     %o0, 1, %l3
F00B56DC: d6062054                 ld      [%i0+0x54], %o3
F00B56E0: d4062034                 ld      [%i0+0x34], %o2
F00B56E4: d202c000                 ld      [%o3], %o1
F00B56E8: 80a28009                 cmp     %o2, %o1
F00B56EC: 0a80000d                 bcs     loc_F00B5720
F00B56F0: 113c0479                 sethi   -0xFEE1C00, %o0
F00B56F4: d002e004                 ld      [%o3+4], %o0
F00B56F8: 90024008                 add     %o1, %o0, %o0
F00B56FC: 80a28008                 cmp     %o2, %o0
F00B5700: 1a800008                 bcc     loc_F00B5720
F00B5704: 113c0479                 sethi   -0xFEE1C00, %o0
F00B5708: 90228009                 sub     %o2, %o1, %o0
F00B570C: d022e004                 st      %o0, [%o3+4]
F00B5710: d016205c                 lduh    [%i0+0x5C], %o0
F00B5714: 901a000c                 btog    %o4, %o0! char *
F00B5718: 10800004                 ba      loc_F00B5728
F00B571C: d036205c                 sth     %o0, [%i0+0x5C]
F00B5720: 7ffd7e94                 call    _panic
F00B5724: 90122210                 bset    0x210, %o0
F00B5728: 90100018                 mov     %i0, %o0
F00B572C: 40000de4                 call    _scsi_chkdma
F00B5730: 13000040                 sethi   0x10000, %o1
F00B5734: 96920000                 orcc    %o0, %g0, %o3
F00B5738: 3280000d                 bne,a   loc_F00B576C
F00B573C: d62420a8                 st      %o3, [%l0+0xA8]
F00B5740: 90100010                 mov     %l0, %o0
F00B5744: 133c0479                 sethi   %hi(aDataTransferOv), %o1! "data transfer overrun"
F00B5748: 40000973                 call    _esp_printstate
F00B574C: 92126228                 bset    %lo(aDataTransferOv), %o1! "data transfer overrun"
F00B5750: 90102007                 mov     7, %o0
F00B5754: d02e2028                 stb     %o0, [%i0+0x28]
F00B5758: 90100010                 mov     %l0, %o0
F00B575C: 400007d7                 call    _esp_sync_backoff
F00B5760: 92100018                 mov     %i0, %o1
F00B5764: 1080004e                 ba      locret_F00B589C
F00B5768: b0102006                 mov     6, %i0
F00B576C: d016205c                 lduh    [%i0+0x5C], %o0
F00B5770: 808a2004                 btst    4, %o0
F00B5774: 0280000d                 be      loc_F00B57A8
F00B5778: 113c0464                 sethi   %hi(_dvmasize), %o0
F00B577C: d4062034                 ld      [%i0+0x34], %o2
F00B5780: d2022324                 ld      [%o0+%lo(_dvmasize)], %o1
F00B5784: 9132a00c                 srl     %o2, 12, %o0
F00B5788: 80a20009                 cmp     %o0, %o1
F00B578C: 3a800005                 bcc,a   loc_F00B57A0
F00B5790: d42420a4                 st      %o2, [%l0+0xA4]
F00B5794: d00420ac                 ld      [%l0+0xAC], %o0
F00B5798: 94128008                 bset    %o0, %o2
F00B579C: d42420a4                 st      %o2, [%l0+0xA4]
F00B57A0: 1080000a                 ba      loc_F00B57C8
F00B57A4: d4246004                 st      %o2, [%l1+4]
F00B57A8: d2062034                 ld      [%i0+0x34], %o1
F00B57AC: 9132600c                 srl     %o1, 12, %o0
F00B57B0: 80a225ff                 cmp     %o0, 0x5FF
F00B57B4: 18800003                 bgu     loc_F00B57C0
F00B57B8: 113fc000                 sethi   -0x1000000, %o0
F00B57BC: 92124008                 bset    %o0, %o1
F00B57C0: d22420a4                 st      %o1, [%l0+0xA4]
F00B57C4: d2246004                 st      %o1, [%l1+4]
F00B57C8: d00c2033                 ldub    [%l0+0x33], %o0
F00B57CC: 808a2040                 btst    0x40, %o0 ! '@'
F00B57D0: 02800007                 be      loc_F00B57EC
F00B57D4: 913ae008                 sra     %o3, 8, %o0
F00B57D8: d62c8000                 stb     %o3, [%l2]
F00B57DC: d02ca004                 stb     %o0, [%l2+4]
F00B57E0: 913ae010                 sra     %o3, 16, %o0
F00B57E4: 10800004                 ba      loc_F00B57F4
F00B57E8: d02ca038                 stb     %o0, [%l2+0x38]
F00B57EC: d62c8000                 stb     %o3, [%l2]
F00B57F0: d02ca004                 stb     %o0, [%l2+4]
F00B57F4: d0044000                 ld      [%l1], %o0
F00B57F8: 9132201c                 srl     %o0, 28, %o0
F00B57FC: 80a22004                 cmp     %o0, 4
F00B5800: 22800002                 be,a    loc_F00B5808
F00B5804: d6246008                 st      %o3, [%l1+8]
F00B5808: d00c2043                 ldub    [%l0+0x43], %o0
F00B580C: 808a2007                 btst    7, %o0
F00B5810: 1280000a                 bne     loc_F00B5838
F00B5814: 80a4e000                 cmp     %l3, 0
F00B5818: 32800018                 bne,a   loc_F00B5878
F00B581C: d0044000                 ld      [%l1], %o0
F00B5820: 90100010                 mov     %l0, %o0
F00B5824: 92102003                 mov     3, %o1
F00B5828: d6162008                 lduh    [%i0+8], %o3
F00B582C: 153c0479                 sethi   %hi(aUnwantedDataOu), %o2! "unwanted data out for Target %d"
F00B5830: 10800008                 ba      loc_F00B5850
F00B5834: 9412a240                 bset    %lo(aUnwantedDataOu), %o2! "unwanted data out for Target %d"
F00B5838: 0280000c                 be      loc_F00B5868
F00B583C: 90100010                 mov     %l0, %o0
F00B5840: 92102003                 mov     3, %o1
F00B5844: d6162008                 lduh    [%i0+8], %o3
F00B5848: 153c04799412a260         set     aUnwantedDataIn, %o2! "unwanted data in for Target %d"
F00B5850: 400008e7                 call    _esplog
F00B5854: 01000000                 nop
F00B5858: 90102002                 mov     2, %o0
F00B585C: d02e2028                 stb     %o0, [%i0+0x28]
F00B5860: 1080000f                 ba      locret_F00B589C
F00B5864: b0102006                 mov     6, %i0
F00B5868: d0044000                 ld      [%l1], %o0
F00B586C: 90122100                 bset    0x100, %o0
F00B5870: d0244000                 st      %o0, [%l1]
F00B5874: d0044000                 ld      [%l1], %o0
F00B5878: 90122210                 bset    0x210, %o0
F00B587C: d0244000                 st      %o0, [%l1]
F00B5880: 90102090                 mov     0x90, %o0
F00B5884: d02ca00c                 stb     %o0, [%l2+0xC]
F00B5888: d00c2041                 ldub    [%l0+0x41], %o0
F00B588C: b0103fff                 mov     -1, %i0
F00B5890: d02c2042                 stb     %o0, [%l0+0x42]
F00B5894: 9010200a                 mov     0xA, %o0
F00B5898: d02c2041                 stb     %o0, [%l0+0x41]
F00B589C: 81c7e008                 ret
F00B58A0: 81e80000                 restore
