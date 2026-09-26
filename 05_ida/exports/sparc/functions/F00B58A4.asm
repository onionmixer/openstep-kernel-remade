F00B58A4: 9de3bf98                 save    %sp, -0x68, %sp
F00B58A8: a2100018                 mov     %i0, %l1
F00B58AC: d05460b2                 ldsh    [%l1+0xB2], %o0
F00B58B0: ea0c6043                 ldub    [%l1+0x43], %l5
F00B58B4: e00460a0                 ld      [%l1+0xA0], %l0
F00B58B8: e404609c                 ld      [%l1+0x9C], %l2
F00B58BC: 912a2002                 sll     %o0, 2, %o0
F00B58C0: 90020011                 add     %o0, %l1, %o0
F00B58C4: e60220b8                 ld      [%o0+0xB8], %l3
F00B58C8: ae102000                 mov     0, %l7
F00B58CC: d2040000                 ld      [%l0], %o1
F00B58D0: ac102000                 mov     0, %l6
F00B58D4: d014e05c                 lduh    [%l3+0x5C], %o0
F00B58D8: 808a6002                 btst    2, %o1
F00B58DC: f20ce009                 ldub    [%l3+9], %i1
F00B58E0: 91322001                 srl     %o0, 1, %o0
F00B58E4: 900a2001                 and     %o0, 1, %o0
F00B58E8: 02800012                 be      loc_F00B5930
F00B58EC: b4100008                 mov     %o0, %i2
F00B58F0: 80a22000                 cmp     %o0, 0
F00B58F4: 113c0479                 sethi   %hi(aUnrecoverableD_0), %o0! "Unrecoverable DMA error on dma %s"
F00B58F8: 02800005                 be      loc_F00B590C
F00B58FC: 94122280                 or      %o0, %lo(aUnrecoverableD_0), %o2! "Unrecoverable DMA error on dma %s"
F00B5900: 113c0479                 sethi   %hi(aSend), %o0! "send"
F00B5904: 10800004                 ba      loc_F00B5914
F00B5908: 961222a8                 or      %o0, %lo(aSend), %o3! "send"
F00B590C: 113c0479961222b0         set     aReceive, %o3! "receive"
F00B5914: 90100011                 mov     %l1, %o0
F00B5918: 400008b5                 call    _esplog
F00B591C: 92102003                 mov     3, %o1
F00B5920: 90102003                 mov     3, %o0
F00B5924: d02ce028                 stb     %o0, [%l3+0x28]
F00B5928: 108000be                 ba      locret_F00B5C20
F00B592C: b0102008                 mov     8, %i0
F00B5930: 80a22000                 cmp     %o0, 0
F00B5934: 12800034                 bne     loc_F00B5A04
F00B5938: 133ffff7                 sethi   -0x2400, %o1
F00B593C: 808d6020                 btst    0x20, %l5 ! ' '
F00B5940: 0280000d                 be      loc_F00B5974
F00B5944: 90100011                 mov     %l1, %o0
F00B5948: 92102003                 mov     3, %o1
F00B594C: 153c0479                 sethi   %hi(aScsiBusDataInP), %o2! "SCSI bus DATA IN phase parity error"
F00B5950: 400008a7                 call    _esplog
F00B5954: 9412a2b8                 bset    %lo(aScsiBusDataInP), %o2! "SCSI bus DATA IN phase parity error"
F00B5958: 90102005                 mov     5, %o0
F00B595C: d02c604c                 stb     %o0, [%l1+0x4C]
F00B5960: 90102001                 mov     1, %o0
F00B5964: d02c6053                 stb     %o0, [%l1+0x53]
F00B5968: d00ce02a                 ldub    [%l3+0x2A], %o0
F00B596C: 90122004                 bset    4, %o0
F00B5970: d02ce02a                 stb     %o0, [%l3+0x2A]
F00B5974: d2040000                 ld      [%l0], %o1
F00B5978: 808a600c                 btst    0xC, %o1
F00B597C: 02800012                 be      loc_F00B59C4
F00B5980: b0102000                 mov     0, %i0
F00B5984: 293c0000                 sethi   -0x10000000, %l4
F00B5988: 80a62063                 cmp     %i0, 0x63 ! 'c'
F00B598C: 1880000f                 bgu     loc_F00B59C8
F00B5990: 01000000                 nop
F00B5994: 900a4014                 and     %o1, %l4, %o0
F00B5998: 9132201c                 srl     %o0, 28, %o0
F00B599C: 80a22004                 cmp     %o0, 4
F00B59A0: 02800003                 be      loc_F00B59AC
F00B59A4: 90126040                 or      %o1, 0x40, %o0
F00B59A8: d0240000                 st      %o0, [%l0]
F00B59AC: 7fff87ad                 call    _us_spin
F00B59B0: 901020c8                 mov     0xC8, %o0
F00B59B4: d2040000                 ld      [%l0], %o1
F00B59B8: 808a600c                 btst    0xC, %o1
F00B59BC: 12bffff3                 bne     loc_F00B5988
F00B59C0: b0062001                 inc     %i0
F00B59C4: 80a62063                 cmp     %i0, 0x63 ! 'c'
F00B59C8: 2880000f                 bleu,a  loc_F00B5A04
F00B59CC: 133ffff7                 sethi   -0x2400, %o1
F00B59D0: d0040000                 ld      [%l0], %o0
F00B59D4: 808a200c                 btst    0xC, %o0
F00B59D8: 0280000a                 be      loc_F00B5A00
F00B59DC: 90100011                 mov     %l1, %o0
F00B59E0: 92102003                 mov     3, %o1
F00B59E4: 153c0479                 sethi   %hi(aDmaGateArrayWo), %o2! "DMA gate array won't drain"
F00B59E8: 40000881                 call    _esplog
F00B59EC: 9412a2e0                 bset    %lo(aDmaGateArrayWo), %o2! "DMA gate array won't drain"
F00B59F0: 90102003                 mov     3, %o0
F00B59F4: d02ce028                 stb     %o0, [%l3+0x28]
F00B59F8: 1080008a                 ba      locret_F00B5C20
F00B59FC: b0102006                 mov     6, %i0
F00B5A00: 133ffff7                 sethi   -0x2400, %o1
F00B5A04: d0040000                 ld      [%l0], %o0
F00B5A08: 921260ff                 bset    0xFF, %o1
F00B5A0C: 90122020                 bset    0x20, %o0 ! ' '
F00B5A10: 900a0009                 and     %o0, %o1, %o0
F00B5A14: d0240000                 st      %o0, [%l0]
F00B5A18: d00c6044                 ldub    [%l1+0x44], %o0
F00B5A1C: 80a22010                 cmp     %o0, 0x10
F00B5A20: 02800007                 be      loc_F00B5A3C
F00B5A24: b0102002                 mov     2, %i0
F00B5A28: d00c6041                 ldub    [%l1+0x41], %o0
F00B5A2C: d02c6042                 stb     %o0, [%l1+0x42]
F00B5A30: 9010201a                 mov     0x1A, %o0
F00B5A34: 1080007b                 ba      locret_F00B5C20
F00B5A38: d02c6041                 stb     %o0, [%l1+0x41]
F00B5A3C: d00ca01c                 ldub    [%l2+0x1C], %o0
F00B5A40: 808d6010                 btst    0x10, %l5
F00B5A44: 02800004                 be      loc_F00B5A54
F00B5A48: 960a201f                 and     %o0, 0x1F, %o3
F00B5A4C: 10800012                 ba      loc_F00B5A94
F00B5A50: f00460a8                 ld      [%l1+0xA8], %i0
F00B5A54: d00c6033                 ldub    [%l1+0x33], %o0
F00B5A58: 808a2040                 btst    0x40, %o0 ! '@'
F00B5A5C: 02800009                 be      loc_F00B5A80
F00B5A60: d00ca004                 ldub    [%l2+4], %o0
F00B5A64: d40c8000                 ldub    [%l2], %o2
F00B5A68: d20ca038                 ldub    [%l2+0x38], %o1
F00B5A6C: 912a2008                 sll     %o0, 8, %o0
F00B5A70: 94128008                 bset    %o0, %o2
F00B5A74: 932a6010                 sll     %o1, 16, %o1
F00B5A78: 10800005                 ba      loc_F00B5A8C
F00B5A7C: b0128009                 or      %o2, %o1, %i0
F00B5A80: d20c8000                 ldub    [%l2], %o1
F00B5A84: 912a2008                 sll     %o0, 8, %o0
F00B5A88: b0124008                 or      %o1, %o0, %i0
F00B5A8C: d00460a8                 ld      [%l1+0xA8], %o0
F00B5A90: b0220018                 sub     %o0, %i0, %i0
F00B5A94: 94968000                 orcc    %i2, %g0, %o2
F00B5A98: 32800002                 bne,a   loc_F00B5AA0
F00B5A9C: b026000b                 sub     %i0, %o3, %i0
F00B5AA0: 90064011                 add     %i1, %l1, %o0
F00B5AA4: d00a205e                 ldub    [%o0+0x5E], %o0
F00B5AA8: 80a22000                 cmp     %o0, 0
F00B5AAC: 22800040                 be,a    loc_F00B5BAC
F00B5AB0: ae102001                 mov     1, %l7
F00B5AB4: d00ce02a                 ldub    [%l3+0x2A], %o0
F00B5AB8: 90122002                 bset    2, %o0
F00B5ABC: d02ce02a                 stb     %o0, [%l3+0x2A]
F00B5AC0: d0046098                 ld      [%l1+0x98], %o0
F00B5AC4: d20c6031                 ldub    [%l1+0x31], %o1
F00B5AC8: 90022001                 inc     %o0
F00B5ACC: 80a26000                 cmp     %o1, 0
F00B5AD0: 12800033                 bne     loc_F00B5B9C
F00B5AD4: d0246098                 st      %o0, [%l1+0x98]
F00B5AD8: ea0ca010                 ldub    [%l2+0x10], %l5
F00B5ADC: 900d6007                 and     %l5, 7, %o0
F00B5AE0: 80a22001                 cmp     %o0, 1
F00B5AE4: 12800008                 bne     loc_F00B5B04
F00B5AE8: ea2c6043                 stb     %l5, [%l1+0x43]
F00B5AEC: d00ca01c                 ldub    [%l2+0x1C], %o0
F00B5AF0: 808a201f                 btst    0x1F, %o0
F00B5AF4: 2280000b                 be,a    loc_F00B5B20
F00B5AF8: ac102001                 mov     1, %l6
F00B5AFC: 1080000a                 ba      loc_F00B5B24
F00B5B00: 912da018                 sll     %l6, 24, %o0
F00B5B04: 80a22000                 cmp     %o0, 0
F00B5B08: 12800007                 bne     loc_F00B5B24
F00B5B0C: 912da018                 sll     %l6, 24, %o0
F00B5B10: d00ca01c                 ldub    [%l2+0x1C], %o0
F00B5B14: 808a2020                 btst    0x20, %o0 ! ' '
F00B5B18: 22800002                 be,a    loc_F00B5B20
F00B5B1C: ac103fff                 mov     -1, %l6
F00B5B20: 912da018                 sll     %l6, 24, %o0
F00B5B24: 933a2018                 sra     %o0, 24, %o1
F00B5B28: 80a26000                 cmp     %o1, 0
F00B5B2C: 02800016                 be      loc_F00B5B84
F00B5B30: 90102012                 mov     0x12, %o0
F00B5B34: d02ca00c                 stb     %o0, [%l2+0xC]
F00B5B38: 113c0479                 sethi   %hi(off_F011E724), %o0! "Spurious %s phase from target %d\n"
F00B5B3C: 80a26000                 cmp     %o1, 0
F00B5B40: 16800005                 bge     loc_F00B5B54
F00B5B44: d4022324                 ld      [%o0+%lo(off_F011E724)], %o2! "Spurious %s phase from target %d\n"
F00B5B48: 113c0479                 sethi   %hi(aDataOut), %o0! "data out"
F00B5B4C: 10800004                 ba      loc_F00B5B5C
F00B5B50: 96122328                 or      %o0, %lo(aDataOut), %o3! "data out"
F00B5B54: 113c047996122338         set     aDataIn, %o3! "data in"
F00B5B5C: 90100011                 mov     %l1, %o0
F00B5B60: 92102003                 mov     3, %o1
F00B5B64: a00e60ff                 and     %i1, 0xFF, %l0
F00B5B68: 40000821                 call    _esplog
F00B5B6C: 98100010                 mov     %l0, %o4
F00B5B70: 90102001                 mov     1, %o0
F00B5B74: d20c6078                 ldub    [%l1+0x78], %o1
F00B5B78: 912a0010                 sll     %o0, %l0, %o0
F00B5B7C: 902a4008                 andn    %o1, %o0, %o0
F00B5B80: d02c6078                 stb     %o0, [%l1+0x78]
F00B5B84: 912da018                 sll     %l6, 24, %o0
F00B5B88: 80a22000                 cmp     %o0, 0
F00B5B8C: 12800009                 bne     loc_F00B5BB0
F00B5B90: 80a5e000                 cmp     %l7, 0
F00B5B94: 10800003                 ba      loc_F00B5BA0
F00B5B98: 80a6a000                 cmp     %i2, 0
F00B5B9C: 80a2a000                 cmp     %o2, 0
F00B5BA0: 02800004                 be      loc_F00B5BB0
F00B5BA4: 80a5e000                 cmp     %l7, 0
F00B5BA8: ae102001                 mov     1, %l7
F00B5BAC: 80a5e000                 cmp     %l7, 0
F00B5BB0: 02800003                 be      loc_F00B5BBC
F00B5BB4: 90102001                 mov     1, %o0
F00B5BB8: d02ca00c                 stb     %o0, [%l2+0xC]
F00B5BBC: d004e034                 ld      [%l3+0x34], %o0
F00B5BC0: d204e054                 ld      [%l3+0x54], %o1
F00B5BC4: 90020018                 add     %o0, %i0, %o0
F00B5BC8: d024e034                 st      %o0, [%l3+0x34]
F00B5BCC: d0026004                 ld      [%o1+4], %o0
F00B5BD0: 90020018                 add     %o0, %i0, %o0
F00B5BD4: d0226004                 st      %o0, [%o1+4]
F00B5BD8: d00ce029                 ldub    [%l3+0x29], %o0
F00B5BDC: 90122008                 bset    8, %o0
F00B5BE0: d02ce029                 stb     %o0, [%l3+0x29]
F00B5BE4: 912da018                 sll     %l6, 24, %o0
F00B5BE8: 80a22000                 cmp     %o0, 0
F00B5BEC: d20c6041                 ldub    [%l1+0x41], %o1
F00B5BF0: 9010201a                 mov     0x1A, %o0
F00B5BF4: d22c6042                 stb     %o1, [%l1+0x42]
F00B5BF8: 12800009                 bne     loc_F00B5C1C
F00B5BFC: d02c6041                 stb     %o0, [%l1+0x41]
F00B5C00: 900d6007                 and     %l5, 7, %o0
F00B5C04: 80a22001                 cmp     %o0, 1
F00B5C08: 18800003                 bgu     loc_F00B5C14
F00B5C0C: 90102009                 mov     9, %o0
F00B5C10: d02c6041                 stb     %o0, [%l1+0x41]
F00B5C14: 10800003                 ba      locret_F00B5C20
F00B5C18: b0102002                 mov     2, %i0
F00B5C1C: b0103fff                 mov     -1, %i0
F00B5C20: 81c7e008                 ret
F00B5C24: 81e80000                 restore
