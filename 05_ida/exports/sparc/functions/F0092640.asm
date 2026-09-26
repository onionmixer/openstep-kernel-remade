F0092640: 9de3bef0                 save    %sp, -0x110, %sp! int
F0092644: a8102000                 mov     0, %l4
F0092648: a6102000                 mov     0, %l3
F009264C: 900e20ff                 and     %i0, 0xFF, %o0
F0092650: 95322003                 srl     %o0, 3, %o2
F0092654: 80a2a010                 cmp     %o2, 0x10
F0092658: e4068000                 ld      [%i2], %l2
F009265C: 148001da                 bg      loc_F0092DC4
F0092660: 98100018                 mov     %i0, %o4! int
F0092664: 912e2010                 sll     %i0, 16, %o0
F0092668: 133c04c4                 sethi   %hi(dword_F0131244), %o1
F009266C: d2026244                 ld      [%o1+%lo(dword_F0131244)], %o1
F0092670: 91322018                 srl     %o0, 24, %o0
F0092674: 80a20009                 cmp     %o0, %o1
F0092678: 328001d4                 bne,a   locret_F0092DC8
F009267C: b0102006                 mov     6, %i0
F0092680: 1108001996122015         set     0x20006415, %o3! int
F0092688: 80a6400b                 cmp     %i1, %o3
F009268C: 932aa003                 sll     %o2, 3, %o1
F0092690: 9202400a                 add     %o1, %o2, %o1
F0092694: 932a6002                 sll     %o1, 2, %o1
F0092698: 113c04c490122000         set     unk_F0131000, %o0
F00926A0: 02800032                 be      loc_F0092768
F00926A4: 92024008                 add     %o1, %o0, %o1
F00926A8: 80a6400b                 cmp     %i1, %o3
F00926AC: 14800015                 bg      loc_F0092700
F00926B0: 11100119                 sethi   0x40046400, %o0
F00926B4: 1130161c90122301         set     -0x3FA78CFF, %o0
F00926BC: 80a64008                 cmp     %i1, %o0
F00926C0: 22800033                 be,a    loc_F009278C
F00926C4: e2024000                 ld      [%o1], %l1
F00926C8: 34800005                 bg,a    loc_F00926DC
F00926CC: 11080019                 sethi   0x20006400, %o0
F00926D0: 11200119                 sethi   -0x7FFB9C00, %o0
F00926D4: 10800016                 ba      loc_F009272C
F00926D8: 90122017                 bset    0x17, %o0
F00926DC: 90122001                 bset    1, %o0
F00926E0: 80a64008                 cmp     %i1, %o0
F00926E4: 148001b9                 bg      locret_F0092DC8
F00926E8: b0102016                 mov     0x16, %i0
F00926EC: 11080019                 sethi   0x20006400, %o0
F00926F0: 80a64008                 cmp     %i1, %o0
F00926F4: 068001b5                 bl      locret_F0092DC8
F00926F8: 900b2007                 and     %o4, 7, %o0
F00926FC: 3080001c                 ba,a    loc_F009276C
F0092700: 90122019                 bset    0x19, %o0
F0092704: 80a64008                 cmp     %i1, %o0
F0092708: 1480000e                 bg      loc_F0092740
F009270C: 1110021c                 sethi   0x40087000, %o0
F0092710: 1110011990122018         set     0x40046418, %o0
F0092718: 80a64008                 cmp     %i1, %o0
F009271C: 3680001c                 bge,a   loc_F009278C
F0092720: e2024000                 ld      [%o1], %l1
F0092724: 1110011990122017         set     0x40046417, %o0
F009272C: 80a64008                 cmp     %i1, %o0
F0092730: 0280000f                 be      loc_F009276C
F0092734: 900b2007                 and     %o4, 7, %o0
F0092738: 108001a4                 ba      locret_F0092DC8
F009273C: b0102016                 mov     0x16, %i0
F0092740: 90122305                 bset    0x305, %o0
F0092744: 80a64008                 cmp     %i1, %o0
F0092748: 02800010                 be      loc_F0092788
F009274C: 11100c19                 sethi   0x40306400, %o0
F0092750: 90122005                 bset    5, %o0
F0092754: 80a64008                 cmp     %i1, %o0
F0092758: 2280000d                 be,a    loc_F009278C
F009275C: e2024000                 ld      [%o1], %l1
F0092760: 1080019a                 ba      locret_F0092DC8
F0092764: b0102016                 mov     0x16, %i0
F0092768: 900b2007                 and     %o4, 7, %o0
F009276C: 80a22007                 cmp     %o0, 7
F0092770: 22800002                 be,a    loc_F0092778
F0092774: 90102000                 mov     0, %o0
F0092778: 912a2002                 sll     %o0, 2, %o0
F009277C: 90020009                 add     %o0, %o1, %o0
F0092780: 10800003                 ba      loc_F009278C
F0092784: e2022004                 ld      [%o0+4], %l1
F0092788: e2024000                 ld      [%o1], %l1
F009278C: 80a46000                 cmp     %l1, 0
F0092790: 0280018d                 be      loc_F0092DC4
F0092794: 11080019                 sethi   0x20006400, %o0
F0092798: 90122015                 bset    0x15, %o0
F009279C: 80a64008                 cmp     %i1, %o0
F00927A0: 228000a6                 be,a    loc_F0092A38
F00927A4: 113c0504                 sethi   -0xFEBF000, %o0
F00927A8: 14800019                 bg      loc_F009280C
F00927AC: 11100119                 sethi   0x40046400, %o0
F00927B0: 1130161c90122301         set     -0x3FA78CFF, %o0
F00927B8: 80a64008                 cmp     %i1, %o0
F00927BC: 228000b2                 be,a    loc_F0092A84
F00927C0: d006a014                 ld      [%i2+0x14], %o0
F00927C4: 14800009                 bg      loc_F00927E8
F00927C8: 11080019                 sethi   0x20006400, %o0
F00927CC: 1120011990122017         set     -0x7FFB9BE9, %o0
F00927D4: 80a64008                 cmp     %i1, %o0
F00927D8: 02800029                 be      loc_F009287C
F00927DC: 113c0504                 sethi   -0xFEBF000, %o0
F00927E0: 1080017a                 ba      locret_F0092DC8
F00927E4: b0102016                 mov     0x16, %i0
F00927E8: 80a64008                 cmp     %i1, %o0
F00927EC: 02800032                 be      loc_F00928B4
F00927F0: 11080019                 sethi   0x20006400, %o0
F00927F4: 90122001                 bset    1, %o0
F00927F8: 80a64008                 cmp     %i1, %o0
F00927FC: 0280003f                 be      loc_F00928F8
F0092800: 33000007                 sethi   0x1C00, %i1
F0092804: 10800171                 ba      locret_F0092DC8
F0092808: b0102016                 mov     0x16, %i0
F009280C: 90122019                 bset    0x19, %o0
F0092810: 80a64008                 cmp     %i1, %o0
F0092814: 22800097                 be,a    loc_F0092A70
F0092818: 113c0504                 sethi   -0xFEBF000, %o0
F009281C: 1480000d                 bg      loc_F0092850
F0092820: 1110021c                 sethi   0x40087000, %o0
F0092824: 1110011990122017         set     0x40046417, %o0
F009282C: 80a64008                 cmp     %i1, %o0
F0092830: 02800019                 be      loc_F0092894
F0092834: 11100119                 sethi   0x40046400, %o0
F0092838: 90122018                 bset    0x18, %o0
F009283C: 80a64008                 cmp     %i1, %o0
F0092840: 0280008a                 be      loc_F0092A68
F0092844: 113c0504                 sethi   -0xFEBF000, %o0
F0092848: 10800160                 ba      locret_F0092DC8
F009284C: b0102016                 mov     0x16, %i0
F0092850: 90122305                 bset    0x305, %o0
F0092854: 80a64008                 cmp     %i1, %o0
F0092858: 02800140                 be      loc_F0092D58
F009285C: 113c0504                 sethi   -0xFEBF000, %o0
F0092860: 11100c1990122005         set     0x40306405, %o0! id
F0092868: 80a64008                 cmp     %i1, %o0
F009286C: 02800038                 be      loc_F009294C
F0092870: a007bf68                 add     %fp, var_98, %l0
F0092874: 10800155                 ba      locret_F0092DC8
F0092878: b0102016                 mov     0x16, %i0
F009287C: d2022198                 ld      [%o0+0x198], %o1! SEL
F0092880: d44ea003                 ldsb    [%i2+3], %o2
F0092884: 40017bfb                 call    _objc_msgSend
F0092888: 90100011                 mov     %l1, %o0
F009288C: 10800144                 ba      loc_F0092D9C
F0092890: a6100008                 mov     %o0, %l3
F0092894: 113c0504                 sethi   %hi(paIsformatted), %o0! id
F0092898: d2022178                 ld      [%o0+%lo(paIsformatted)], %o1! SEL
F009289C: 40017bf5                 call    _objc_msgSend
F00928A0: 90100011                 mov     %l1, %o0
F00928A4: 912a2018                 sll     %o0, 24, %o0
F00928A8: 913a2018                 sra     %o0, 24, %o0
F00928AC: 1080013c                 ba      loc_F0092D9C
F00928B0: d0268000                 st      %o0, [%i2]
F00928B4: 33000007                 sethi   0x1C00, %i1
F00928B8: 4000cd9e                 call    _IOMalloc
F00928BC: 9016605c                 or      %i1, 0x5C, %o0
F00928C0: a0100008                 mov     %o0, %l0
F00928C4: 90100011                 mov     %l1, %o0! id
F00928C8: 133c0504                 sethi   %hi(paReadlabel), %o1
F00928CC: d202619c                 ld      [%o1+%lo(paReadlabel)], %o1! SEL
F00928D0: 40017be8                 call    _objc_msgSend
F00928D4: 94100010                 mov     %l0, %o2! int
F00928D8: a6920000                 orcc    %o0, %g0, %l3
F00928DC: 12800018                 bne     loc_F009293C
F00928E0: 90100010                 mov     %l0, %o0! int
F00928E4: 92100012                 mov     %l2, %o1! int
F00928E8: 400015f9                 call    _copyout
F00928EC: 9416605c                 or      %i1, 0x5C, %o2! int
F00928F0: 10800012                 ba      loc_F0092938
F00928F4: a8100008                 mov     %o0, %l4
F00928F8: 4000cd8e                 call    _IOMalloc
F00928FC: 9016605c                 or      %i1, 0x5C, %o0
F0092900: a0100008                 mov     %o0, %l0
F0092904: 90100012                 mov     %l2, %o0! int
F0092908: 92100010                 mov     %l0, %o1! int
F009290C: 400015d3                 call    _copyin
F0092910: 9416605c                 or      %i1, 0x5C, %o2
F0092914: a8920000                 orcc    %o0, %g0, %l4
F0092918: 12800009                 bne     loc_F009293C
F009291C: 90100010                 mov     %l0, %o0
F0092920: 90100011                 mov     %l1, %o0! id
F0092924: 133c0504                 sethi   %hi(paWritelabel_0), %o1
F0092928: d20261a0                 ld      [%o1+%lo(paWritelabel_0)], %o1! SEL
F009292C: 40017bd1                 call    _objc_msgSend
F0092930: 94100010                 mov     %l0, %o2
F0092934: a6100008                 mov     %o0, %l3
F0092938: 90100010                 mov     %l0, %o0
F009293C: 4000cd82                 call    _IOFree
F0092940: 9216605c                 or      %i1, 0x5C, %o1! size_t
F0092944: 10800117                 ba      loc_F0092DA0
F0092948: 80a4e000                 cmp     %l3, 0
F009294C: 90100010                 mov     %l0, %o0! void *
F0092950: 40000942                 call    _bzero
F0092954: 92102030                 mov     0x30, %o1 ! '0'
F0092958: 113c0504                 sethi   %hi(paDrivename), %o0! id
F009295C: d20221a4                 ld      [%o0+%lo(paDrivename)], %o1! SEL
F0092960: 40017bc4                 call    _objc_msgSend
F0092964: 90100011                 mov     %l1, %o0! __dst
F0092968: 92100008                 mov     %o0, %o1! __src
F009296C: 7ffdd2ef                 call    _strcpy
F0092970: 90100010                 mov     %l0, %o0
F0092974: 113c0504                 sethi   %hi(paBlocksize), %o0! id
F0092978: d2022188                 ld      [%o0+%lo(paBlocksize)], %o1! SEL
F009297C: 40017bbd                 call    _objc_msgSend
F0092980: 90100011                 mov     %l1, %o0
F0092984: 92100008                 mov     %o0, %o1
F0092988: d227bf90                 st      %o1, [%fp+var_70]
F009298C: 113c04c4                 sethi   %hi(dword_F0131248), %o0
F0092990: d0022248                 ld      [%o0+%lo(dword_F0131248)], %o0
F0092994: 80a26000                 cmp     %o1, 0
F0092998: 0280000f                 be      loc_F00929D4
F009299C: d027bf94                 st      %o0, [%fp+var_6C]
F00929A0: 110000079012205b         set     0x1C5B, %o0
F00929A8: 7ffdcf16                 call    _udiv
F00929AC: 90024008                 add     %o1, %o0, %o0
F00929B0: 96102000                 mov     0, %o3
F00929B4: 94102000                 mov     0, %o2
F00929B8: 9207bff8                 add     %fp, var_8, %o1
F00929BC: d4227f88                 st      %o2, [%o1-0x78]
F00929C0: 94028008                 add     %o2, %o0, %o2
F00929C4: 9602e001                 inc     %o3
F00929C8: 80a2e003                 cmp     %o3, 3
F00929CC: 04bffffc                 ble     loc_F00929BC
F00929D0: 92026004                 inc     4, %o1
F00929D4: d007bf68                 ld      [%fp+var_98], %o0
F00929D8: d0268000                 st      %o0, [%i2]
F00929DC: d007bf6c                 ld      [%fp+var_94], %o0
F00929E0: d026a004                 st      %o0, [%i2+4]
F00929E4: d007bf70                 ld      [%fp+var_90], %o0
F00929E8: d026a008                 st      %o0, [%i2+8]
F00929EC: d007bf74                 ld      [%fp+var_8C], %o0
F00929F0: d026a00c                 st      %o0, [%i2+0xC]
F00929F4: d007bf78                 ld      [%fp+var_88], %o0
F00929F8: d026a010                 st      %o0, [%i2+0x10]
F00929FC: d007bf7c                 ld      [%fp+var_84], %o0
F0092A00: d026a014                 st      %o0, [%i2+0x14]
F0092A04: d007bf80                 ld      [%fp+var_80], %o0
F0092A08: d026a018                 st      %o0, [%i2+0x18]
F0092A0C: d007bf84                 ld      [%fp+var_7C], %o0
F0092A10: d026a01c                 st      %o0, [%i2+0x1C]
F0092A14: d007bf88                 ld      [%fp+var_78], %o0
F0092A18: d026a020                 st      %o0, [%i2+0x20]
F0092A1C: d007bf8c                 ld      [%fp+var_74], %o0
F0092A20: d026a024                 st      %o0, [%i2+0x24]
F0092A24: d007bf90                 ld      [%fp+var_70], %o0
F0092A28: d026a028                 st      %o0, [%i2+0x28]
F0092A2C: d007bf94                 ld      [%fp+var_6C], %o0! id
F0092A30: 108000db                 ba      loc_F0092D9C
F0092A34: d026a02c                 st      %o0, [%i2+0x2C]
F0092A38: d20221a8                 ld      [%o0+0x1A8], %o1! SEL
F0092A3C: 40017b8d                 call    _objc_msgSend
F0092A40: 90100011                 mov     %l1, %o0
F0092A44: 912a2018                 sll     %o0, 24, %o0
F0092A48: 80a22000                 cmp     %o0, 0
F0092A4C: 028000d4                 be      loc_F0092D9C
F0092A50: 113c0504                 sethi   %hi(paEject_1), %o0! id
F0092A54: d20221ac                 ld      [%o0+%lo(paEject_1)], %o1! SEL
F0092A58: 40017b86                 call    _objc_msgSend
F0092A5C: 90100011                 mov     %l1, %o0! id
F0092A60: 108000cf                 ba      loc_F0092D9C
F0092A64: a6100008                 mov     %o0, %l3
F0092A68: 10800003                 ba      loc_F0092A74
F0092A6C: d2022188                 ld      [%o0+0x188], %o1
F0092A70: d20221b0                 ld      [%o0+0x1B0], %o1! SEL
F0092A74: 40017b7f                 call    _objc_msgSend
F0092A78: 90100011                 mov     %l1, %o0
F0092A7C: 108000c8                 ba      loc_F0092D9C
F0092A80: d0268000                 st      %o0, [%i2]
F0092A84: 80a22000                 cmp     %o0, 0
F0092A88: 0280002d                 be      loc_F0092B3C
F0092A8C: a010001a                 mov     %i2, %l0
F0092A90: d0024000                 ld      [%o1], %o0! id
F0092A94: 133c0504                 sethi   %hi(paController), %o1! SEL
F0092A98: 40017b76                 call    _objc_msgSend
F0092A9C: d202617c                 ld      [%o1+%lo(paController)], %o1
F0092AA0: a4100008                 mov     %o0, %l2
F0092AA4: 133c0504                 sethi   %hi(paGetdmaalignmen), %o1
F0092AA8: d2026180                 ld      [%o1+%lo(paGetdmaalignmen)], %o1! SEL
F0092AAC: 40017b71                 call    _objc_msgSend
F0092AB0: 9407bf58                 add     %fp, var_A8, %o2
F0092AB4: d006a00c                 ld      [%i2+0xC], %o0
F0092AB8: 80a22001                 cmp     %o0, 1
F0092ABC: 12800003                 bne     loc_F0092AC8
F0092AC0: d207bf60                 ld      [%fp+var_A0], %o1
F0092AC4: d207bf64                 ld      [%fp+var_9C], %o1
F0092AC8: 80a26001                 cmp     %o1, 1
F0092ACC: 28800007                 bleu,a  loc_F0092AE8
F0092AD0: f2042014                 ld      [%l0+0x14], %i1
F0092AD4: d0042014                 ld      [%l0+0x14], %o0
F0092AD8: 90020009                 add     %o0, %o1, %o0
F0092ADC: 90023fff                 inc     -1, %o0
F0092AE0: 92200009                 neg     %o1
F0092AE4: b20a0009                 and     %o0, %o1, %i1
F0092AE8: 90100012                 mov     %l2, %o0! id
F0092AEC: 94100019                 mov     %i1, %o2
F0092AF0: 9607bf54                 add     %fp, var_AC, %o3! int
F0092AF4: 133c0504                 sethi   %hi(paAllocatebuffer), %o1
F0092AF8: d2026184                 ld      [%o1+%lo(paAllocatebuffer)], %o1! SEL
F0092AFC: 40017b5d                 call    _objc_msgSend
F0092B00: 9807bf50                 add     %fp, var_B0, %o4! int
F0092B04: d204200c                 ld      [%l0+0xC], %o1! int
F0092B08: 80a26001                 cmp     %o1, 1
F0092B0C: 1280000e                 bne     loc_F0092B44
F0092B10: b4100008                 mov     %o0, %i2
F0092B14: d0042010                 ld      [%l0+0x10], %o0! int
F0092B18: d4042014                 ld      [%l0+0x14], %o2! int
F0092B1C: 4000154f                 call    _copyin
F0092B20: 9210001a                 mov     %i2, %o1! size_t
F0092B24: a8920000                 orcc    %o0, %g0, %l4
F0092B28: 02800008                 be      loc_F0092B48
F0092B2C: a407bf98                 add     %fp, var_68, %l2
F0092B30: 90102009                 mov     9, %o0
F0092B34: 10800081                 ba      loc_F0092D38
F0092B38: d024201c                 st      %o0, [%l0+0x1C]
F0092B3C: b2102000                 mov     0, %i1
F0092B40: b4102000                 mov     0, %i2
F0092B44: a407bf98                 add     %fp, var_68, %l2
F0092B48: 90100012                 mov     %l2, %o0! void *
F0092B4C: 400008c3                 call    _bzero
F0092B50: 92102060                 mov     0x60, %o1 ! '`'
F0092B54: 113c0504                 sethi   %hi(paTarget), %o0! id
F0092B58: d20221b4                 ld      [%o0+%lo(paTarget)], %o1! SEL
F0092B5C: 40017b45                 call    _objc_msgSend
F0092B60: 90100011                 mov     %l1, %o0
F0092B64: d02fbf98                 stb     %o0, [%fp+var_68]
F0092B68: 113c0504                 sethi   %hi(paLun), %o0! id
F0092B6C: d20221b8                 ld      [%o0+%lo(paLun)], %o1! SEL
F0092B70: 40017b40                 call    _objc_msgSend
F0092B74: 90100011                 mov     %l1, %o0
F0092B78: d02fbf99                 stb     %o0, [%fp+var_67]
F0092B7C: d0040000                 ld      [%l0], %o0
F0092B80: d027bf9c                 st      %o0, [%fp+var_64]
F0092B84: d0042004                 ld      [%l0+4], %o0
F0092B88: d027bfa0                 st      %o0, [%fp+var_60]
F0092B8C: d0042008                 ld      [%l0+8], %o0
F0092B90: d027bfa4                 st      %o0, [%fp+var_5C]
F0092B94: d004200c                 ld      [%l0+0xC], %o0
F0092B98: 13200000                 sethi   0x80000000, %o1
F0092B9C: d407bfb4                 ld      [%fp+var_4C], %o2
F0092BA0: 80a00008                 cmp     %g0, %o0
F0092BA4: 90603fff                 subc    %g0, -1, %o0
F0092BA8: d02fbfa8                 stb     %o0, [%fp+var_58]
F0092BAC: f227bfac                 st      %i1, [%fp+var_54]
F0092BB0: d0042018                 ld      [%l0+0x18], %o0
F0092BB4: 922a8009                 andn    %o2, %o1, %o1
F0092BB8: d027bfb0                 st      %o0, [%fp+var_50]
F0092BBC: d004204c                 ld      [%l0+0x4C], %o0
F0092BC0: 15100000                 sethi   0x40000000, %o2
F0092BC4: 91322017                 srl     %o0, 23, %o0
F0092BC8: 901a2001                 btog    1, %o0
F0092BCC: 912a201f                 sll     %o0, 31, %o0
F0092BD0: 92124008                 bset    %o0, %o1
F0092BD4: d227bfb4                 st      %o1, [%fp+var_4C]
F0092BD8: 942a400a                 andn    %o1, %o2, %o2
F0092BDC: d004204c                 ld      [%l0+0x4C], %o0
F0092BE0: 13080000                 sethi   0x20000000, %o1
F0092BE4: 91322016                 srl     %o0, 22, %o0
F0092BE8: 900a2001                 and     %o0, 1, %o0
F0092BEC: 912a201e                 sll     %o0, 30, %o0
F0092BF0: 94128008                 bset    %o0, %o2
F0092BF4: d427bfb4                 st      %o2, [%fp+var_4C]
F0092BF8: d004204c                 ld      [%l0+0x4C], %o0
F0092BFC: 922a8009                 andn    %o2, %o1, %o1
F0092C00: 91322015                 srl     %o0, 21, %o0
F0092C04: 900a2001                 and     %o0, 1, %o0
F0092C08: 912a201d                 sll     %o0, 29, %o0
F0092C0C: 92124008                 bset    %o0, %o1
F0092C10: d227bfb4                 st      %o1, [%fp+var_4C]
F0092C14: d00c204c                 ldub    [%l0+0x4C], %o0
F0092C18: 920a7ff0                 and     %o1, -0x10, %o1
F0092C1C: 900a200f                 and     %o0, 0xF, %o0
F0092C20: 92124008                 bset    %o0, %o1
F0092C24: d227bfb4                 st      %o1, [%fp+var_4C]
F0092C28: d004200c                 ld      [%l0+0xC], %o0
F0092C2C: 80a22001                 cmp     %o0, 1
F0092C30: 12800008                 bne     loc_F0092C50
F0092C34: 90100011                 mov     %l1, %o0! id
F0092C38: 94100012                 mov     %l2, %o2
F0092C3C: 173c04d1                 sethi   %hi(_kernel_map), %o3
F0092C40: d802e340                 ld      [%o3+%lo(_kernel_map)], %o4
F0092C44: 133c0504                 sethi   %hi(paSdcdbwriteBuff), %o1
F0092C48: 10800007                 ba      loc_F0092C64
F0092C4C: d20261bc                 ld      [%o1+%lo(paSdcdbwriteBuff)], %o1
F0092C50: 94100012                 mov     %l2, %o2
F0092C54: 173c04d1                 sethi   %hi(_kernel_map), %o3
F0092C58: d802e340                 ld      [%o3+%lo(_kernel_map)], %o4! int
F0092C5C: 133c0504                 sethi   %hi(paSdcdbreadBuffe), %o1
F0092C60: d20261c0                 ld      [%o1+%lo(paSdcdbreadBuffe)], %o1! SEL
F0092C64: 40017b03                 call    _objc_msgSend
F0092C68: 9610001a                 mov     %i2, %o3! int
F0092C6C: a6100008                 mov     %o0, %l3
F0092C70: d007bfb8                 ld      [%fp+var_48], %o0
F0092C74: 80a2200d                 cmp     %o0, 0xD
F0092C78: 12800008                 bne     loc_F0092C98
F0092C7C: d024201c                 st      %o0, [%l0+0x1C]
F0092C80: d00fbfbc                 ldub    [%fp+var_44], %o0
F0092C84: 80a22002                 cmp     %o0, 2
F0092C88: 12800005                 bne     loc_F0092C9C
F0092C8C: d00fbfbc                 ldub    [%fp+var_44], %o0
F0092C90: 90102003                 mov     3, %o0
F0092C94: d024201c                 st      %o0, [%l0+0x1C]
F0092C98: d00fbfbc                 ldub    [%fp+var_44], %o0
F0092C9C: d02c2020                 stb     %o0, [%l0+0x20]
F0092CA0: d007bfc0                 ld      [%fp+var_40], %o0
F0092CA4: d2042014                 ld      [%l0+0x14], %o1
F0092CA8: 80a20009                 cmp     %o0, %o1
F0092CAC: 04800003                 ble     loc_F0092CB8
F0092CB0: d0242040                 st      %o0, [%l0+0x40]
F0092CB4: d2242040                 st      %o1, [%l0+0x40]
F0092CB8: c0242048                 clr     [%l0+0x48]
F0092CBC: d004200c                 ld      [%l0+0xC], %o0
F0092CC0: 80a22000                 cmp     %o0, 0
F0092CC4: 1280000b                 bne     loc_F0092CF0
F0092CC8: c0242044                 clr     [%l0+0x44]
F0092CCC: d007bfc0                 ld      [%fp+var_40], %o0
F0092CD0: 80a22000                 cmp     %o0, 0
F0092CD4: 22800008                 be,a    loc_F0092CF4
F0092CD8: d004201c                 ld      [%l0+0x1C], %o0! int
F0092CDC: d2042010                 ld      [%l0+0x10], %o1! int
F0092CE0: d4042040                 ld      [%l0+0x40], %o2! int
F0092CE4: 400014fa                 call    _copyout
F0092CE8: 9010001a                 mov     %i2, %o0
F0092CEC: a8100008                 mov     %o0, %l4
F0092CF0: d004201c                 ld      [%l0+0x1C], %o0
F0092CF4: 80a22002                 cmp     %o0, 2
F0092CF8: 32800011                 bne,a   loc_F0092D3C
F0092CFC: d0042014                 ld      [%l0+0x14], %o0
F0092D00: d007bfd8                 ld      [%fp+var_28], %o0
F0092D04: d0242024                 st      %o0, [%l0+0x24]
F0092D08: d007bfdc                 ld      [%fp+var_24], %o0
F0092D0C: d0242028                 st      %o0, [%l0+0x28]
F0092D10: d007bfe0                 ld      [%fp+var_20], %o0
F0092D14: d024202c                 st      %o0, [%l0+0x2C]
F0092D18: d007bfe4                 ld      [%fp+var_1C], %o0
F0092D1C: d0242030                 st      %o0, [%l0+0x30]
F0092D20: d007bfe8                 ld      [%fp+var_18], %o0
F0092D24: d0242034                 st      %o0, [%l0+0x34]
F0092D28: d007bfec                 ld      [%fp+var_14], %o0
F0092D2C: d0242038                 st      %o0, [%l0+0x38]
F0092D30: d007bff0                 ld      [%fp+var_10], %o0
F0092D34: d024203c                 st      %o0, [%l0+0x3C]
F0092D38: d0042014                 ld      [%l0+0x14], %o0
F0092D3C: 80a22000                 cmp     %o0, 0
F0092D40: 02800017                 be      loc_F0092D9C
F0092D44: d007bf54                 ld      [%fp+var_AC], %o0! id
F0092D48: 4000cc7f                 call    _IOFree
F0092D4C: d207bf50                 ld      [%fp+var_B0], %o1
F0092D50: 10800014                 ba      loc_F0092DA0
F0092D54: 80a4e000                 cmp     %l3, 0
F0092D58: d20221c4                 ld      [%o0+0x1C4], %o1! SEL
F0092D5C: 40017ac5                 call    _objc_msgSend
F0092D60: 90100011                 mov     %l1, %o0
F0092D64: a6920000                 orcc    %o0, %g0, %l3
F0092D68: 1280000e                 bne     loc_F0092DA0
F0092D6C: 113c0504                 sethi   %hi(paBlocksize), %o0! id
F0092D70: d2022188                 ld      [%o0+%lo(paBlocksize)], %o1! SEL
F0092D74: 40017abf                 call    _objc_msgSend
F0092D78: 90100011                 mov     %l1, %o0! id
F0092D7C: 133c0504                 sethi   %hi(paDisksize), %o1
F0092D80: a0100008                 mov     %o0, %l0
F0092D84: d20261b0                 ld      [%o1+%lo(paDisksize)], %o1! SEL
F0092D88: 40017aba                 call    _objc_msgSend
F0092D8C: 90100011                 mov     %l1, %o0
F0092D90: e026a004                 st      %l0, [%i2+4]
F0092D94: 90023fff                 inc     -1, %o0
F0092D98: d0268000                 st      %o0, [%i2]
F0092D9C: 80a4e000                 cmp     %l3, 0
F0092DA0: 02800007                 be      loc_F0092DBC
F0092DA4: 90100011                 mov     %l1, %o0! id
F0092DA8: 133c0504                 sethi   %hi(paErrnofromretur), %o1
F0092DAC: d2026194                 ld      [%o1+%lo(paErrnofromretur)], %o1! SEL
F0092DB0: 40017ab0                 call    _objc_msgSend
F0092DB4: 94100013                 mov     %l3, %o2
F0092DB8: a8100008                 mov     %o0, %l4
F0092DBC: 10800003                 ba      locret_F0092DC8
F0092DC0: b0100014                 mov     %l4, %i0
F0092DC4: b0102006                 mov     6, %i0
F0092DC8: 81c7e008                 ret
F0092DCC: 81e80000                 restore
