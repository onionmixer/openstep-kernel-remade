F00A5528: 9de3bf98                 save    %sp, -0x68, %sp
F00A552C: 7fffc597                 call    _splusclock
F00A5530: b4102002                 mov     2, %i2
F00A5534: b8100008                 mov     %o0, %i4
F00A5538: 90100018                 mov     %i0, %o0! int
F00A553C: 13000054                 sethi   0x15000, %o1! int
F00A5540: 7ffd8432                 call    _div
F00A5544: 92126180                 bset    0x180, %o1
F00A5548: 90022002                 inc     2, %o0
F00A554C: 7ffd84d7                 call    _rem
F00A5550: 92102007                 mov     7, %o1
F00A5554: b6022001                 add     %o0, 1, %i3
F00A5558: 92100018                 mov     %i0, %o1
F00A555C: 1100784c9a122380         set     0x1E13380, %o5
F00A5564: 113f875e98122300         set     -0x1E28500, %o4
F00A556C: 113f87b396122080         set     -0x1E13380, %o3
F00A5574: 110078a194122100         set     0x1E28500, %o2
F00A557C: 80a2400d                 cmp     %o1, %o5
F00A5580: 0880000f                 bleu    loc_F00A55BC
F00A5584: 80a62000                 cmp     %i0, 0
F00A5588: 808ea003                 btst    3, %i2
F00A558C: 32800003                 bne,a   loc_F00A5598
F00A5590: b006000b                 add     %i0, %o3, %i0
F00A5594: b006000c                 add     %i0, %o4, %i0
F00A5598: 9006a001                 add     %i2, 1, %o0
F00A559C: b4100008                 mov     %o0, %i2
F00A55A0: 808a2003                 btst    3, %o0
F00A55A4: 12bffff6                 bne     loc_F00A557C
F00A55A8: 92100018                 mov     %i0, %o1
F00A55AC: 80a6000a                 cmp     %i0, %o2
F00A55B0: 18bffff7                 bgu     loc_F00A558C
F00A55B4: 808ea003                 btst    3, %i2
F00A55B8: 80a62000                 cmp     %i0, 0
F00A55BC: 06800016                 bl      loc_F00A5614
F00A55C0: b2102001                 mov     1, %i1
F00A55C4: 920ea003                 and     %i2, 3, %o1
F00A55C8: 113c046696122108         set     _clk_state, %o3
F00A55D0: 113ff67194122080         set     -0x263B80, %o2
F00A55D8: 80a26000                 cmp     %o1, 0
F00A55DC: 12800006                 bne     loc_F00A55F4
F00A55E0: 912e6010                 sll     %i1, 16, %o0
F00A55E4: 91322010                 srl     %o0, 16, %o0
F00A55E8: 80a22002                 cmp     %o0, 2
F00A55EC: 02800006                 be      loc_F00A5604
F00A55F0: 912e6010                 sll     %i1, 16, %o0
F00A55F4: 9132200e                 srl     %o0, 14, %o0
F00A55F8: d002000b                 ld      [%o0+%o3], %o0
F00A55FC: 10800003                 ba      loc_F00A5608
F00A5600: b0260008                 sub     %i0, %o0, %i0
F00A5604: b006000a                 add     %i0, %o2, %i0
F00A5608: 80a62000                 cmp     %i0, 0
F00A560C: 16bffff3                 bge     loc_F00A55D8
F00A5610: b2066001                 inc     %i1
F00A5614: 92067fff                 add     %i1, -1, %o1
F00A5618: 808ea003                 btst    3, %i2
F00A561C: 12800007                 bne     loc_F00A5638
F00A5620: b2100009                 mov     %o1, %i1
F00A5624: 912a6010                 sll     %o1, 16, %o0
F00A5628: 91322010                 srl     %o0, 16, %o0
F00A562C: 80a22002                 cmp     %o0, 2
F00A5630: 22800008                 be,a    loc_F00A5650
F00A5634: 1100098e                 sethi   0x263800, %o0
F00A5638: 912a6010                 sll     %o1, 16, %o0
F00A563C: 133c046692126108         set     _clk_state, %o1
F00A5644: 9132200e                 srl     %o0, 14, %o0
F00A5648: 10800003                 ba      loc_F00A5654
F00A564C: d0020009                 ld      [%o0+%o1], %o0
F00A5650: 90122380                 bset    0x380, %o0
F00A5654: b0060008                 add     %i0, %o0, %i0
F00A5658: 90100018                 mov     %i0, %o0
F00A565C: 7ffd8493                 call    _rem
F00A5660: 9210203c                 mov     0x3C, %o1 ! '<'! int
F00A5664: a2100008                 mov     %o0, %l1
F00A5668: 90100018                 mov     %i0, %o0! int
F00A566C: 7ffd83e7                 call    _div
F00A5670: 9210203c                 mov     0x3C, %o1 ! '<'
F00A5674: b0100008                 mov     %o0, %i0
F00A5678: 7ffd848c                 call    _rem
F00A567C: 9210203c                 mov     0x3C, %o1 ! '<'! int
F00A5680: a6100008                 mov     %o0, %l3
F00A5684: 90100018                 mov     %i0, %o0! int
F00A5688: 7ffd83e0                 call    _div
F00A568C: 9210203c                 mov     0x3C, %o1 ! '<'
F00A5690: b0100008                 mov     %o0, %i0
F00A5694: 7ffd8485                 call    _rem
F00A5698: 92102018                 mov     0x18, %o1! int
F00A569C: aa100008                 mov     %o0, %l5
F00A56A0: 90100018                 mov     %i0, %o0! int
F00A56A4: 7ffd83d9                 call    _div
F00A56A8: 92102018                 mov     0x18, %o1
F00A56AC: a4100008                 mov     %o0, %l2
F00A56B0: 2f3fbfff9015e3f8         set     -0x1000008, %o0
F00A56B8: 92102007                 mov     7, %o1
F00A56BC: 7fffdbc2                 call    _pmap_change_prot
F00A56C0: a404a001                 inc     %l2
F00A56C4: a32c6010                 sll     %l1, 16, %l1
F00A56C8: a3346010                 srl     %l1, 16, %l1
F00A56CC: 90100011                 mov     %l1, %o0
F00A56D0: ec0de3f8                 ldub    [%l7+0x3F8], %l6
F00A56D4: 9210200a                 mov     0xA, %o1
F00A56D8: ac15a080                 bset    0x80, %l6
F00A56DC: 7ffd83c9                 call    _udiv
F00A56E0: ec2de3f8                 stb     %l6, [%l7+0x3F8]
F00A56E4: a0100008                 mov     %o0, %l0
F00A56E8: 90100011                 mov     %l1, %o0
F00A56EC: 9210200a                 mov     0xA, %o1
F00A56F0: 7ffd846c                 call    _urem
F00A56F4: a12c2004                 sll     %l0, 4, %l0
F00A56F8: a815e3f8                 or      %l7, 0x3F8, %l4
F00A56FC: 90020010                 add     %o0, %l0, %o0
F00A5700: 900a207f                 and     %o0, 0x7F, %o0
F00A5704: d02d2001                 stb     %o0, [%l4+1]
F00A5708: a72ce010                 sll     %l3, 16, %l3
F00A570C: a734e010                 srl     %l3, 16, %l3
F00A5710: 90100013                 mov     %l3, %o0
F00A5714: 7ffd83bb                 call    _udiv
F00A5718: 9210200a                 mov     0xA, %o1
F00A571C: a0100008                 mov     %o0, %l0
F00A5720: 90100013                 mov     %l3, %o0
F00A5724: 9210200a                 mov     0xA, %o1
F00A5728: 7ffd845e                 call    _urem
F00A572C: a12c2004                 sll     %l0, 4, %l0
F00A5730: 90020010                 add     %o0, %l0, %o0
F00A5734: 900a207f                 and     %o0, 0x7F, %o0
F00A5738: d02d2002                 stb     %o0, [%l4+2]
F00A573C: ab2d6010                 sll     %l5, 16, %l5
F00A5740: ab356010                 srl     %l5, 16, %l5
F00A5744: 90100015                 mov     %l5, %o0
F00A5748: 7ffd83ae                 call    _udiv
F00A574C: 9210200a                 mov     0xA, %o1
F00A5750: a0100008                 mov     %o0, %l0
F00A5754: 90100015                 mov     %l5, %o0
F00A5758: 9210200a                 mov     0xA, %o1
F00A575C: 7ffd8451                 call    _urem
F00A5760: a12c2004                 sll     %l0, 4, %l0
F00A5764: 90020010                 add     %o0, %l0, %o0
F00A5768: 900a203f                 and     %o0, 0x3F, %o0
F00A576C: d02d2003                 stb     %o0, [%l4+3]
F00A5770: a12ee010                 sll     %i3, 16, %l0
F00A5774: a1342010                 srl     %l0, 16, %l0
F00A5778: 90100010                 mov     %l0, %o0
F00A577C: 7ffd83a1                 call    _udiv
F00A5780: 9210200a                 mov     0xA, %o1
F00A5784: a2100008                 mov     %o0, %l1
F00A5788: 90100010                 mov     %l0, %o0
F00A578C: 9210200a                 mov     0xA, %o1
F00A5790: 7ffd8444                 call    _urem
F00A5794: a32c6004                 sll     %l1, 4, %l1
F00A5798: 90020011                 add     %o0, %l1, %o0
F00A579C: 900a2007                 and     %o0, 7, %o0
F00A57A0: d02d2004                 stb     %o0, [%l4+4]
F00A57A4: a52ca010                 sll     %l2, 16, %l2
F00A57A8: a534a010                 srl     %l2, 16, %l2
F00A57AC: 90100012                 mov     %l2, %o0
F00A57B0: 7ffd8394                 call    _udiv
F00A57B4: 9210200a                 mov     0xA, %o1
F00A57B8: a0100008                 mov     %o0, %l0
F00A57BC: 90100012                 mov     %l2, %o0
F00A57C0: 9210200a                 mov     0xA, %o1
F00A57C4: 7ffd8437                 call    _urem
F00A57C8: a12c2004                 sll     %l0, 4, %l0
F00A57CC: 90020010                 add     %o0, %l0, %o0
F00A57D0: 900a203f                 and     %o0, 0x3F, %o0
F00A57D4: d02d2005                 stb     %o0, [%l4+5]
F00A57D8: a12e6010                 sll     %i1, 16, %l0
F00A57DC: a1342010                 srl     %l0, 16, %l0
F00A57E0: 90100010                 mov     %l0, %o0
F00A57E4: 7ffd8387                 call    _udiv
F00A57E8: 9210200a                 mov     0xA, %o1
F00A57EC: a2100008                 mov     %o0, %l1
F00A57F0: 90100010                 mov     %l0, %o0
F00A57F4: 9210200a                 mov     0xA, %o1
F00A57F8: 7ffd842a                 call    _urem
F00A57FC: a32c6004                 sll     %l1, 4, %l1
F00A5800: 90020011                 add     %o0, %l1, %o0
F00A5804: 900a201f                 and     %o0, 0x1F, %o0
F00A5808: d02d2006                 stb     %o0, [%l4+6]
F00A580C: a12ea010                 sll     %i2, 16, %l0
F00A5810: a1342010                 srl     %l0, 16, %l0
F00A5814: 90100010                 mov     %l0, %o0
F00A5818: 7ffd837a                 call    _udiv
F00A581C: 9210200a                 mov     0xA, %o1
F00A5820: a2100008                 mov     %o0, %l1
F00A5824: 90100010                 mov     %l0, %o0
F00A5828: 9210200a                 mov     0xA, %o1
F00A582C: 7ffd841d                 call    _urem
F00A5830: a32c6004                 sll     %l1, 4, %l1
F00A5834: 90020011                 add     %o0, %l1, %o0
F00A5838: d02d2007                 stb     %o0, [%l4+7]
F00A583C: ac0da07f                 and     %l6, 0x7F, %l6
F00A5840: ec2de3f8                 stb     %l6, [%l7+0x3F8]
F00A5844: 90100014                 mov     %l4, %o0
F00A5848: 7fffdb5f                 call    _pmap_change_prot
F00A584C: 92102001                 mov     1, %o1
F00A5850: 7fffc535                 call    _splx
F00A5854: 9010001c                 mov     %i4, %o0
F00A5858: 81c7e008                 ret
F00A585C: 81e80000                 restore
