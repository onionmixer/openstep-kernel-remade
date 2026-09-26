F00B6434: 9de3bf98                 save    %sp, -0x68, %sp
F00B6438: d05620b2                 ldsh    [%i0+0xB2], %o0
F00B643C: ea06209c                 ld      [%i0+0x9C], %l5
F00B6440: e20e2056                 ldub    [%i0+0x56], %l1
F00B6444: 912a2002                 sll     %o0, 2, %o0
F00B6448: 90020018                 add     %o0, %i0, %o0
F00B644C: d80220b8                 ld      [%o0+0xB8], %o4
F00B6450: a8102000                 mov     0, %l4
F00B6454: 80a46001                 cmp     %l1, 1
F00B6458: 128000be                 bne     loc_F00B6750
F00B645C: e6132008                 lduh    [%o4+8], %l3
F00B6460: e00e2057                 ldub    [%i0+0x57], %l0
F00B6464: d00e2031                 ldub    [%i0+0x31], %o0
F00B6468: e40e2058                 ldub    [%i0+0x58], %l2
F00B646C: 90023ffd                 inc     -3, %o0
F00B6470: 900a20ff                 and     %o0, 0xFF, %o0
F00B6474: 80a22001                 cmp     %o0, 1
F00B6478: 0880000d                 bleu    loc_F00B64AC
F00B647C: d216203e                 lduh    [%i0+0x3E], %o1
F00B6480: d00e2032                 ldub    [%i0+0x32], %o0
F00B6484: 808a2080                 btst    0x80, %o0
F00B6488: 22800007                 be,a    loc_F00B64A4
F00B648C: 90100009                 mov     %o1, %o0
F00B6490: 912a6001                 sll     %o1, 1, %o0
F00B6494: 90020009                 add     %o0, %o1, %o0
F00B6498: 912a2001                 sll     %o0, 1, %o0
F00B649C: 10800006                 ba      loc_F00B64B4
F00B64A0: 921023e8                 mov     0x3E8, %o1
F00B64A4: 10800004                 ba      loc_F00B64B4
F00B64A8: 921020c8                 mov     0xC8, %o1
F00B64AC: 90100009                 mov     %o1, %o0! int
F00B64B0: 921020fa                 mov     0xFA, %o1! int
F00B64B4: 7ffd4055                 call    _div
F00B64B8: 01000000                 nop
F00B64BC: 90022003                 inc     3, %o0
F00B64C0: a33a2002                 sra     %o0, 2, %l1
F00B64C4: d416203e                 lduh    [%i0+0x3E], %o2
F00B64C8: 921023e8                 mov     0x3E8, %o1! int
F00B64CC: 912aa003                 sll     %o2, 3, %o0
F00B64D0: 9002000a                 add     %o0, %o2, %o0
F00B64D4: 912a2002                 sll     %o0, 2, %o0! int
F00B64D8: 7ffd404c                 call    _div
F00B64DC: 9022000a                 sub     %o0, %o2, %o0
F00B64E0: d20e2046                 ldub    [%i0+0x46], %o1
F00B64E4: 90022003                 inc     3, %o0
F00B64E8: 92026001                 inc     %o1
F00B64EC: d22e2046                 stb     %o1, [%i0+0x46]
F00B64F0: 808a6001                 btst    1, %o1
F00B64F4: 0280001b                 be      loc_F00B6560
F00B64F8: 933a2002                 sra     %o0, 2, %o1
F00B64FC: d00e207a                 ldub    [%i0+0x7A], %o0
F00B6500: 913a0013                 sra     %o0, %l3, %o0
F00B6504: 808a2001                 btst    1, %o0
F00B6508: 12800007                 bne     loc_F00B6524
F00B650C: a8102001                 mov     1, %l4
F00B6510: 113c047c                 sethi   %hi(_scsi_options), %o0
F00B6514: d0022158                 ld      [%o0+%lo(_scsi_options)], %o0
F00B6518: 808a2020                 btst    0x20, %o0 ! ' '
F00B651C: 12800012                 bne     loc_F00B6564
F00B6520: 80a4a00f                 cmp     %l2, 0xF
F00B6524: d00e2031                 ldub    [%i0+0x31], %o0
F00B6528: 90023ffd                 inc     -3, %o0
F00B652C: 900a20ff                 and     %o0, 0xFF, %o0
F00B6530: 80a22001                 cmp     %o0, 1
F00B6534: 18800006                 bgu     loc_F00B654C
F00B6538: 80a42063                 cmp     %l0, 0x63 ! 'c'
F00B653C: 28800041                 bleu,a  loc_F00B6640
F00B6540: a0102064                 mov     0x64, %l0 ! 'd'
F00B6544: 10800040                 ba      loc_F00B6644
F00B6548: 90100018                 mov     %i0, %o0
F00B654C: 80a420b3                 cmp     %l0, 0xB3
F00B6550: 2880003c                 bleu,a  loc_F00B6640
F00B6554: a01020b4                 mov     0xB4, %l0
F00B6558: 1080003b                 ba      loc_F00B6644
F00B655C: 90100018                 mov     %i0, %o0
F00B6560: 80a4a00f                 cmp     %l2, 0xF
F00B6564: 08800003                 bleu    loc_F00B6570
F00B6568: 94102000                 mov     0, %o2
F00B656C: a410200f                 mov     0xF, %l2
F00B6570: 80a4a000                 cmp     %l2, 0
F00B6574: 02800004                 be      loc_F00B6584
F00B6578: 80a40009                 cmp     %l0, %o1
F00B657C: 38800031                 bgu,a   loc_F00B6640
F00B6580: a8102001                 mov     1, %l4
F00B6584: 80a4a000                 cmp     %l2, 0
F00B6588: 02800012                 be      loc_F00B65D0
F00B658C: 80a40011                 cmp     %l0, %l1
F00B6590: 1a800011                 bcc     loc_F00B65D4
F00B6594: 80a4a000                 cmp     %l2, 0
F00B6598: d00e2031                 ldub    [%i0+0x31], %o0
F00B659C: 90023ffd                 inc     -3, %o0
F00B65A0: 900a20ff                 and     %o0, 0xFF, %o0
F00B65A4: 80a22001                 cmp     %o0, 1
F00B65A8: 08800008                 bleu    loc_F00B65C8
F00B65AC: a0100011                 mov     %l1, %l0
F00B65B0: d00e2032                 ldub    [%i0+0x32], %o0
F00B65B4: 808a2080                 btst    0x80, %o0
F00B65B8: 02800028                 be      loc_F00B6658
F00B65BC: 94102005                 mov     5, %o2
F00B65C0: 10800026                 ba      loc_F00B6658
F00B65C4: 94102006                 mov     6, %o2
F00B65C8: 10800024                 ba      loc_F00B6658
F00B65CC: 94102004                 mov     4, %o2
F00B65D0: 80a4a000                 cmp     %l2, 0
F00B65D4: 02800022                 be      loc_F00B665C
F00B65D8: 80a4a000                 cmp     %l2, 0
F00B65DC: d016203e                 lduh    [%i0+0x3E], %o0
F00B65E0: 7ffd4008                 call    _udiv
F00B65E4: 921023e8                 mov     0x3E8, %o1
F00B65E8: 92060013                 add     %i0, %l3, %o1
F00B65EC: 912a2010                 sll     %o0, 16, %o0
F00B65F0: d20a606e                 ldub    [%o1+0x6E], %o1
F00B65F4: 80a26000                 cmp     %o1, 0
F00B65F8: 02800008                 be      loc_F00B6618
F00B65FC: a3322010                 srl     %o0, 16, %l1
F00B6600: 912c2004                 sll     %l0, 4, %o0
F00B6604: 90220010                 sub     %o0, %l0, %o0
F00B6608: 912a2003                 sll     %o0, 3, %o0
F00B660C: 7ffd3ffd                 call    _udiv
F00B6610: 92102064                 mov     0x64, %o1 ! 'd'
F00B6614: a0100008                 mov     %o0, %l0
F00B6618: 912c2002                 sll     %l0, 2, %o0
F00B661C: 90020011                 add     %o0, %l1, %o0
F00B6620: 90023fff                 inc     -1, %o0
F00B6624: 7ffd3ff7                 call    _udiv
F00B6628: 92100011                 mov     %l1, %o1
F00B662C: 94100008                 mov     %o0, %o2
F00B6630: 80a2a023                 cmp     %o2, 0x23 ! '#'
F00B6634: 0880000a                 bleu    loc_F00B665C
F00B6638: 80a4a000                 cmp     %l2, 0
F00B663C: a8102001                 mov     1, %l4
F00B6640: 90100018                 mov     %i0, %o0
F00B6644: 92100010                 mov     %l0, %o1
F00B6648: 4000039e                 call    _esp_make_sdtr
F00B664C: 94102000                 mov     0, %o2
F00B6650: 1080007b                 ba      loc_F00B683C
F00B6654: d00e2041                 ldub    [%i0+0x41], %o0
F00B6658: 80a4a000                 cmp     %l2, 0
F00B665C: 0280002a                 be      loc_F00B6704
F00B6660: 92060013                 add     %i0, %l3, %o1
F00B6664: d42a6066                 stb     %o2, [%o1+0x66]
F00B6668: 900aa01f                 and     %o2, 0x1F, %o0
F00B666C: d02d6018                 stb     %o0, [%l5+0x18]
F00B6670: d00e2077                 ldub    [%i0+0x77], %o0
F00B6674: 90120012                 bset    %l2, %o0
F00B6678: d02a605e                 stb     %o0, [%o1+0x5E]
F00B667C: d02d601c                 stb     %o0, [%l5+0x1C]
F00B6680: d60e2031                 ldub    [%i0+0x31], %o3
F00B6684: 9002fffd                 add     %o3, -3, %o0
F00B6688: 900a20ff                 and     %o0, 0xFF, %o0
F00B668C: 80a22001                 cmp     %o0, 1
F00B6690: 1880000d                 bgu     loc_F00B66C4
F00B6694: 80a42031                 cmp     %l0, 0x31 ! '1'
F00B6698: 18800008                 bgu     loc_F00B66B8
F00B669C: 80a2e003                 cmp     %o3, 3
F00B66A0: 12800004                 bne     loc_F00B66B0
F00B66A4: d00a6034                 ldub    [%o1+0x34], %o0
F00B66A8: 10800003                 ba      loc_F00B66B4
F00B66AC: 90122010                 bset    0x10, %o0
F00B66B0: 90122002                 bset    2, %o0
F00B66B4: d02a6034                 stb     %o0, [%o1+0x34]
F00B66B8: 90060013                 add     %i0, %l3, %o0
F00B66BC: d00a2034                 ldub    [%o0+0x34], %o0
F00B66C0: d02d6030                 stb     %o0, [%l5+0x30]
F00B66C4: d216203e                 lduh    [%i0+0x3E], %o1
F00B66C8: 7ffd3f8e                 call    _umul
F00B66CC: 9010000a                 mov     %o2, %o0
F00B66D0: 7ffd3fcc                 call    _udiv
F00B66D4: 921023e8                 mov     0x3E8, %o1
F00B66D8: 92100008                 mov     %o0, %o1
F00B66DC: 110ee6b2                 sethi   0x3B9AC800, %o0
F00B66E0: 7ffd3fc8                 call    _udiv
F00B66E4: 90122200                 bset    0x200, %o0
F00B66E8: 900223e7                 inc     0x3E7, %o0
F00B66EC: 7ffd3fc5                 call    _udiv
F00B66F0: 921023e8                 mov     0x3E8, %o1
F00B66F4: 7ffd406b                 call    _urem
F00B66F8: 921023e8                 mov     0x3E8, %o1
F00B66FC: 1080000a                 ba      loc_F00B6724
F00B6700: 80a52000                 cmp     %l4, 0
F00B6704: d00a605e                 ldub    [%o1+0x5E], %o0
F00B6708: 80a22000                 cmp     %o0, 0
F00B670C: 02800006                 be      loc_F00B6724
F00B6710: 80a52000                 cmp     %l4, 0
F00B6714: c02a6066                 clrb    [%o1+0x66]
F00B6718: c02d6018                 clrb    [%l5+0x18]
F00B671C: c02a605e                 clrb    [%o1+0x5E]
F00B6720: c02d601c                 clrb    [%l5+0x1C]
F00B6724: 02800005                 be      loc_F00B6738
F00B6728: 90100018                 mov     %i0, %o0
F00B672C: 92100010                 mov     %l0, %o1
F00B6730: 40000364                 call    _esp_make_sdtr
F00B6734: 94100012                 mov     %l2, %o2
F00B6738: 90102001                 mov     1, %o0
F00B673C: d20e2078                 ldub    [%i0+0x78], %o1
F00B6740: 912a0013                 sll     %o0, %l3, %o0
F00B6744: 92124008                 bset    %o0, %o1
F00B6748: 1080003c                 ba      loc_F00B6838
F00B674C: d22e2078                 stb     %o1, [%i0+0x78]
F00B6750: 80a46000                 cmp     %l1, 0
F00B6754: 1280002e                 bne     loc_F00B680C
F00B6758: 90102001                 mov     1, %o0
F00B675C: d013205c                 lduh    [%o4+0x5C], %o0
F00B6760: 808a2001                 btst    1, %o0
F00B6764: 22800035                 be,a    loc_F00B6838
F00B6768: a8102007                 mov     7, %l4
F00B676C: d00e2057                 ldub    [%i0+0x57], %o0
F00B6770: d20e2058                 ldub    [%i0+0x58], %o1
F00B6774: d40e2059                 ldub    [%i0+0x59], %o2
F00B6778: d60e205a                 ldub    [%i0+0x5A], %o3
F00B677C: 912a2018                 sll     %o0, 24, %o0
F00B6780: 932a6010                 sll     %o1, 16, %o1
F00B6784: 90120009                 bset    %o1, %o0
F00B6788: 952aa008                 sll     %o2, 8, %o2
F00B678C: 9012000a                 bset    %o2, %o0
F00B6790: d2032034                 ld      [%o4+0x34], %o1
F00B6794: 9612000b                 bset    %o0, %o3
F00B6798: d403203c                 ld      [%o4+0x3C], %o2
F00B679C: 9202400b                 add     %o1, %o3, %o1
F00B67A0: 80a2400a                 cmp     %o1, %o2
F00B67A4: 0a800007                 bcs     loc_F00B67C0
F00B67A8: d2232034                 st      %o1, [%o4+0x34]
F00B67AC: d0032040                 ld      [%o4+0x40], %o0
F00B67B0: 90028008                 add     %o2, %o0, %o0
F00B67B4: 80a24008                 cmp     %o1, %o0
F00B67B8: 2a800005                 bcs,a   loc_F00B67CC
F00B67BC: d0032054                 ld      [%o4+0x54], %o0
F00B67C0: 9022400b                 sub     %o1, %o3, %o0
F00B67C4: 1080001c                 ba      loc_F00B6834
F00B67C8: d0232034                 st      %o0, [%o4+0x34]
F00B67CC: d4022004                 ld      [%o0+4], %o2
F00B67D0: 80a2a000                 cmp     %o2, 0
F00B67D4: 2280001a                 be,a    loc_F00B683C
F00B67D8: d00e2041                 ldub    [%i0+0x41], %o0
F00B67DC: d0020000                 ld      [%o0], %o0
F00B67E0: 80a24008                 cmp     %o1, %o0
F00B67E4: 0a800005                 bcs     loc_F00B67F8
F00B67E8: 9002000a                 add     %o0, %o2, %o0
F00B67EC: 80a24008                 cmp     %o1, %o0
F00B67F0: 2a800013                 bcs,a   loc_F00B683C
F00B67F4: d00e2041                 ldub    [%i0+0x41], %o0
F00B67F8: d013205c                 lduh    [%o4+0x5C], %o0
F00B67FC: 13000004                 sethi   0x1000, %o1
F00B6800: 90120009                 bset    %o1, %o0
F00B6804: 1080000d                 ba      loc_F00B6838
F00B6808: d033205c                 sth     %o0, [%o4+0x5C]
F00B680C: 213c047a                 sethi   %hi(aRejectingMessa_0), %l0! "Rejecting message %s 0x%x from Target %"...
F00B6810: 40000af2                 call    _scsi_mname
F00B6814: a0142170                 bset    %lo(aRejectingMessa_0), %l0! "Rejecting message %s 0x%x from Target %"...
F00B6818: 96100008                 mov     %o0, %o3
F00B681C: 90100018                 mov     %i0, %o0
F00B6820: 92102005                 mov     5, %o1
F00B6824: 94100010                 mov     %l0, %o2
F00B6828: 98100011                 mov     %l1, %o4
F00B682C: 400004f0                 call    _esplog
F00B6830: 9a100013                 mov     %l3, %o5
F00B6834: a8102007                 mov     7, %l4
F00B6838: d00e2041                 ldub    [%i0+0x41], %o0
F00B683C: d02e2042                 stb     %o0, [%i0+0x42]
F00B6840: 9010201a                 mov     0x1A, %o0
F00B6844: d02e2041                 stb     %o0, [%i0+0x41]
F00B6848: 81c7e008                 ret
F00B684C: 91e80014                 restore %g0, %l4, %o0
