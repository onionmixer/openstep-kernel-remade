F002B73C: 9de3bf98                 save    %sp, -0x68, %sp
F002B740: 400000d5                 call    _nb_map
F002B744: 9010001a                 mov     %i2, %o0
F002B748: a0100008                 mov     %o0, %l0
F002B74C: 400000e3                 call    _nb_size
F002B750: 9010001a                 mov     %i2, %o0
F002B754: 80a22002                 cmp     %o0, 2
F002B758: 28800077                 bleu,a  locret_F002B934
F002B75C: b010202f                 mov     0x2F, %i0 ! '/'
F002B760: d00c0000                 ldub    [%l0], %o0
F002B764: 80a22000                 cmp     %o0, 0
F002B768: 32800073                 bne,a   locret_F002B934
F002B76C: b010202f                 mov     0x2F, %i0 ! '/'
F002B770: d00ee001                 ldub    [%i3+1], %o0
F002B774: 900a20c0                 and     %o0, 0xC0, %o0
F002B778: 80a22040                 cmp     %o0, 0x40 ! '@'
F002B77C: 3280006e                 bne,a   locret_F002B934
F002B780: b010202f                 mov     0x2F, %i0 ! '/'
F002B784: d00c2002                 ldub    [%l0+2], %o0
F002B788: 920a20ef                 and     %o0, 0xEF, %o1
F002B78C: 80a260af                 cmp     %o1, 0xAF
F002B790: 12800034                 bne     loc_F002B860
F002B794: 80a260e3                 cmp     %o1, 0xE3
F002B798: d00c2001                 ldub    [%l0+1], %o0
F002B79C: 808a2001                 btst    1, %o0
F002B7A0: 12800030                 bne     loc_F002B860
F002B7A4: 80a260e3                 cmp     %o1, 0xE3
F002B7A8: 400001af                 call    _if_ipackets
F002B7AC: 90100018                 mov     %i0, %o0
F002B7B0: 92022001                 add     %o0, 1, %o1
F002B7B4: 400001c4                 call    _if_ipackets_set
F002B7B8: 90100018                 mov     %i0, %o0
F002B7BC: 9006e008                 add     %i3, 8, %o0! void *
F002B7C0: 9206e002                 add     %i3, 2, %o1! void *
F002B7C4: 4001a4d3                 call    _bcopy
F002B7C8: 94102006                 mov     6, %o2
F002B7CC: d00ee002                 ldub    [%i3+2], %o0
F002B7D0: d20ee008                 ldub    [%i3+8], %o1
F002B7D4: 900a207f                 and     %o0, 0x7F, %o0
F002B7D8: 808a6080                 btst    0x80, %o1
F002B7DC: 0280000c                 be      loc_F002B80C
F002B7E0: d02ee002                 stb     %o0, [%i3+2]
F002B7E4: d00ee00f                 ldub    [%i3+0xF], %o0
F002B7E8: 93322007                 srl     %o0, 7, %o1
F002B7EC: 92380009                 xnor    %g0, %o1, %o1
F002B7F0: 932a6007                 sll     %o1, 7, %o1
F002B7F4: 900a207f                 and     %o0, 0x7F, %o0
F002B7F8: 90120009                 bset    %o1, %o0
F002B7FC: d20ee00e                 ldub    [%i3+0xE], %o1
F002B800: d02ee00f                 stb     %o0, [%i3+0xF]
F002B804: 920a601f                 and     %o1, 0x1F, %o1
F002B808: d22ee00e                 stb     %o1, [%i3+0xE]
F002B80C: 4000004c                 call    sub_F002B93C
F002B810: 90100010                 mov     %l0, %o0
F002B814: d00c2003                 ldub    [%l0+3], %o0
F002B818: 80a22081                 cmp     %o0, 0x81
F002B81C: 1280000a                 bne     loc_F002B844
F002B820: 90100019                 mov     %i1, %o0
F002B824: 400000ad                 call    _nb_size
F002B828: 9010001a                 mov     %i2, %o0
F002B82C: 80a22005                 cmp     %o0, 5
F002B830: 08800004                 bleu    loc_F002B840
F002B834: 90102001                 mov     1, %o0
F002B838: d02c2004                 stb     %o0, [%l0+4]
F002B83C: c02c2005                 clrb    [%l0+5]
F002B840: 90100019                 mov     %i1, %o0
F002B844: 9210001a                 mov     %i2, %o1
F002B848: 40000044                 call    sub_F002B958
F002B84C: 9410001b                 mov     %i3, %o2! size_t
F002B850: 80a22000                 cmp     %o0, 0
F002B854: 02800032                 be      loc_F002B91C
F002B858: 01000000                 nop
F002B85C: 30800029                 ba,a    loc_F002B900
F002B860: 32800035                 bne,a   locret_F002B934
F002B864: b010202f                 mov     0x2F, %i0 ! '/'
F002B868: d00c2001                 ldub    [%l0+1], %o0
F002B86C: 808a2001                 btst    1, %o0
F002B870: 32800031                 bne,a   locret_F002B934
F002B874: b010202f                 mov     0x2F, %i0 ! '/'
F002B878: 4000017b                 call    _if_ipackets
F002B87C: 90100018                 mov     %i0, %o0
F002B880: 92022001                 add     %o0, 1, %o1
F002B884: 40000190                 call    _if_ipackets_set
F002B888: 90100018                 mov     %i0, %o0
F002B88C: 9006e008                 add     %i3, 8, %o0! void *
F002B890: 9206e002                 add     %i3, 2, %o1! void *
F002B894: 4001a49f                 call    _bcopy
F002B898: 94102006                 mov     6, %o2
F002B89C: d00ee002                 ldub    [%i3+2], %o0
F002B8A0: d20ee008                 ldub    [%i3+8], %o1
F002B8A4: 900a207f                 and     %o0, 0x7F, %o0
F002B8A8: 808a6080                 btst    0x80, %o1
F002B8AC: 0280000c                 be      loc_F002B8DC
F002B8B0: d02ee002                 stb     %o0, [%i3+2]
F002B8B4: d00ee00f                 ldub    [%i3+0xF], %o0
F002B8B8: 93322007                 srl     %o0, 7, %o1
F002B8BC: 92380009                 xnor    %g0, %o1, %o1
F002B8C0: 932a6007                 sll     %o1, 7, %o1
F002B8C4: 900a207f                 and     %o0, 0x7F, %o0
F002B8C8: 90120009                 bset    %o1, %o0
F002B8CC: d20ee00e                 ldub    [%i3+0xE], %o1
F002B8D0: d02ee00f                 stb     %o0, [%i3+0xF]
F002B8D4: 920a601f                 and     %o1, 0x1F, %o1
F002B8D8: d22ee00e                 stb     %o1, [%i3+0xE]
F002B8DC: 40000018                 call    sub_F002B93C
F002B8E0: 90100010                 mov     %l0, %o0
F002B8E4: 90100019                 mov     %i1, %o0
F002B8E8: 9210001a                 mov     %i2, %o1
F002B8EC: 4000001b                 call    sub_F002B958
F002B8F0: 9410001b                 mov     %i3, %o2
F002B8F4: 80a22000                 cmp     %o0, 0
F002B8F8: 02800009                 be      loc_F002B91C
F002B8FC: 01000000                 nop
F002B900: 4000015d                 call    _if_oerrors
F002B904: 90100018                 mov     %i0, %o0
F002B908: 92022001                 add     %o0, 1, %o1
F002B90C: 40000172                 call    _if_oerrors_set
F002B910: 90100018                 mov     %i0, %o0
F002B914: 10800008                 ba      locret_F002B934
F002B918: b0102000                 mov     0, %i0
F002B91C: 4000014e                 call    _if_opackets
F002B920: 90100018                 mov     %i0, %o0
F002B924: 92022001                 add     %o0, 1, %o1
F002B928: 40000163                 call    _if_opackets_set
F002B92C: 90100018                 mov     %i0, %o0
F002B930: b0102000                 mov     0, %i0
F002B934: 81c7e008                 ret
F002B938: 81e80000                 restore
