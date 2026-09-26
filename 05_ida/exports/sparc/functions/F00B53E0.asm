F00B53E0: 9de3bf98                 save    %sp, -0x68, %sp
F00B53E4: a0100018                 mov     %i0, %l0
F00B53E8: d05420b2                 ldsh    [%l0+0xB2], %o0
F00B53EC: d204209c                 ld      [%l0+0x9C], %o1
F00B53F0: d40c204c                 ldub    [%l0+0x4C], %o2
F00B53F4: 912a2002                 sll     %o0, 2, %o0
F00B53F8: 90020010                 add     %o0, %l0, %o0
F00B53FC: e40220b8                 ld      [%o0+0xB8], %l2
F00B5400: d00c2044                 ldub    [%l0+0x44], %o0
F00B5404: 80a22020                 cmp     %o0, 0x20 ! ' '
F00B5408: 1280001c                 bne     loc_F00B5478
F00B540C: e214a008                 lduh    [%l2+8], %l1
F00B5410: b00aa0ff                 and     %o2, 0xFF, %i0
F00B5414: 80a6200c                 cmp     %i0, 0xC
F00B5418: 02800004                 be      loc_F00B5428
F00B541C: 80a62006                 cmp     %i0, 6
F00B5420: 3280004d                 bne,a   loc_F00B5554
F00B5424: d42c2052                 stb     %o2, [%l0+0x52]
F00B5428: 4000080c                 call    _esp_chip_disconnect
F00B542C: 90100010                 mov     %l0, %o0
F00B5430: 80a6200c                 cmp     %i0, 0xC
F00B5434: 3280000a                 bne,a   loc_F00B545C
F00B5438: d014a05c                 lduh    [%l2+0x5C], %o0
F00B543C: 90040011                 add     %l0, %l1, %o0
F00B5440: c02a205e                 clrb    [%o0+0x5E]
F00B5444: 90102001                 mov     1, %o0
F00B5448: d20c2078                 ldub    [%l0+0x78], %o1
F00B544C: 912a0011                 sll     %o0, %l1, %o0
F00B5450: 902a4008                 andn    %o1, %o0, %o0
F00B5454: d02c2078                 stb     %o0, [%l0+0x78]
F00B5458: d014a05c                 lduh    [%l2+0x5C], %o0
F00B545C: 808a2100                 btst    0x100, %o0
F00B5460: 02800004                 be      loc_F00B5470
F00B5464: c02ca028                 clrb    [%l2+0x28]
F00B5468: 90102001                 mov     1, %o0
F00B546C: d02ca06b                 stb     %o0, [%l2+0x6B]
F00B5470: 1080003f                 ba      locret_F00B556C
F00B5474: b0102003                 mov     3, %i0
F00B5478: d00c2043                 ldub    [%l0+0x43], %o0
F00B547C: 960a2007                 and     %o0, 7, %o3
F00B5480: d00a601c                 ldub    [%o1+0x1C], %o0
F00B5484: 808a201f                 btst    0x1F, %o0
F00B5488: 0280000c                 be      loc_F00B54B8
F00B548C: c02a600c                 clrb    [%o1+0xC]
F00B5490: 80a2e001                 cmp     %o3, 1
F00B5494: 12800008                 bne     loc_F00B54B4
F00B5498: 90102001                 mov     1, %o0
F00B549C: 90040011                 add     %l0, %l1, %o0
F00B54A0: d00a205e                 ldub    [%o0+0x5E], %o0
F00B54A4: 80a22000                 cmp     %o0, 0
F00B54A8: 32800005                 bne,a   loc_F00B54BC
F00B54AC: d00c2044                 ldub    [%l0+0x44], %o0
F00B54B0: 90102001                 mov     1, %o0
F00B54B4: d02a600c                 stb     %o0, [%o1+0xC]
F00B54B8: d00c2044                 ldub    [%l0+0x44], %o0
F00B54BC: 808a2010                 btst    0x10, %o0
F00B54C0: 02800016                 be      loc_F00B5518
F00B54C4: 80a2e006                 cmp     %o3, 6
F00B54C8: 12800015                 bne     loc_F00B551C
F00B54CC: d00c2053                 ldub    [%l0+0x53], %o0
F00B54D0: 80a22001                 cmp     %o0, 1
F00B54D4: 28800005                 bleu,a  loc_F00B54E8
F00B54D8: 90100010                 mov     %l0, %o0
F00B54DC: 9010201a                 mov     0x1A, %o0
F00B54E0: d02a600c                 stb     %o0, [%o1+0xC]
F00B54E4: 90100010                 mov     %l0, %o0
F00B54E8: 153c0479                 sethi   %hi(aScsiBusMessage), %o2! "SCSI bus MESSAGE OUT phase parity error"
F00B54EC: 92102003                 mov     3, %o1
F00B54F0: 400009bf                 call    _esplog
F00B54F4: 9412a1a0                 bset    %lo(aScsiBusMessage), %o2! "SCSI bus MESSAGE OUT phase parity error"
F00B54F8: d00ca02a                 ldub    [%l2+0x2A], %o0
F00B54FC: 90122004                 bset    4, %o0
F00B5500: d02ca02a                 stb     %o0, [%l2+0x2A]
F00B5504: d00c2041                 ldub    [%l0+0x41], %o0
F00B5508: b0102002                 mov     2, %i0
F00B550C: d02c2042                 stb     %o0, [%l0+0x42]
F00B5510: 10800016                 ba      loc_F00B5568
F00B5514: 90102003                 mov     3, %o0
F00B5518: d00c2053                 ldub    [%l0+0x53], %o0
F00B551C: 80a22005                 cmp     %o0, 5
F00B5520: 3280000d                 bne,a   loc_F00B5554
F00B5524: d42c2052                 stb     %o2, [%l0+0x52]
F00B5528: 80a2a001                 cmp     %o2, 1
F00B552C: 3280000a                 bne,a   loc_F00B5554
F00B5530: d42c2052                 stb     %o2, [%l0+0x52]
F00B5534: d00c204e                 ldub    [%l0+0x4E], %o0
F00B5538: 80a22001                 cmp     %o0, 1
F00B553C: 32800006                 bne,a   loc_F00B5554
F00B5540: d42c2052                 stb     %o2, [%l0+0x52]
F00B5544: d00c2046                 ldub    [%l0+0x46], %o0
F00B5548: 90022001                 inc     %o0
F00B554C: d02c2046                 stb     %o0, [%l0+0x46]
F00B5550: d42c2052                 stb     %o2, [%l0+0x52]
F00B5554: c02c2053                 clrb    [%l0+0x53]
F00B5558: d00c2041                 ldub    [%l0+0x41], %o0
F00B555C: b0102002                 mov     2, %i0
F00B5560: d02c2042                 stb     %o0, [%l0+0x42]
F00B5564: 9010201a                 mov     0x1A, %o0
F00B5568: d02c2041                 stb     %o0, [%l0+0x41]
F00B556C: 81c7e008                 ret
F00B5570: 81e80000                 restore
