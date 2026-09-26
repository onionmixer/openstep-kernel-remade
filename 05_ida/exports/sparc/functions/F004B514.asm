F004B514: 9de3bf70                 save    %sp, -0x90, %sp
F004B518: a0100018                 mov     %i0, %l0
F004B51C: f827a054                 st      %i4, [%fp+arg_54]
F004B520: 92100019                 mov     %i1, %o1
F004B524: d04e4000                 ldsb    [%i1], %o0
F004B528: a2102000                 mov     0, %l1
F004B52C: 80a22000                 cmp     %o0, 0
F004B530: 0280000a                 be      loc_F004B558
F004B534: e607a05c                 ld      [%fp+arg_5C], %l3
F004B538: d04a4000                 ldsb    [%o1], %o0
F004B53C: 80a2202f                 cmp     %o0, 0x2F ! '/'
F004B540: 02800124                 be      loc_F004B9D0
F004B544: 92026001                 inc     %o1
F004B548: d04a4000                 ldsb    [%o1], %o0
F004B54C: 80a22000                 cmp     %o0, 0
F004B550: 12bffffb                 bne     loc_F004B53C
F004B554: a2046001                 inc     %l1
F004B558: 80a46000                 cmp     %l1, 0
F004B55C: 32800006                 bne,a   loc_F004B574
F004B560: d04e4000                 ldsb    [%i1], %o0
F004B564: 113c043a                 sethi   %hi(aDirenter), %o0! "direnter"
F004B568: 7fff2702                 call    _panic
F004B56C: 90122210                 bset    %lo(aDirenter), %o0! "direnter"
F004B570: d04e4000                 ldsb    [%i1], %o0
F004B574: 80a2202e                 cmp     %o0, 0x2E ! '.'
F004B578: 3280001a                 bne,a   loc_F004B5E0
F004B57C: c027bfe0                 clr     [%fp+var_20]
F004B580: 80a46001                 cmp     %l1, 1
F004B584: 02800008                 be      loc_F004B5A4
F004B588: 80a46002                 cmp     %l1, 2
F004B58C: 32800015                 bne,a   loc_F004B5E0
F004B590: c027bfe0                 clr     [%fp+var_20]
F004B594: d04e6001                 ldsb    [%i1+1], %o0
F004B598: 80a2202e                 cmp     %o0, 0x2E ! '.'
F004B59C: 32800011                 bne,a   loc_F004B5E0
F004B5A0: c027bfe0                 clr     [%fp+var_20]
F004B5A4: 80a6a002                 cmp     %i2, 2
F004B5A8: 12800004                 bne     loc_F004B5B8
F004B5AC: 80a4e000                 cmp     %l3, 0
F004B5B0: 1080012c                 ba      locret_F004BA60
F004B5B4: b0102042                 mov     0x42, %i0 ! 'B'
F004B5B8: 02800008                 be      loc_F004B5D8
F004B5BC: 90100010                 mov     %l0, %o0! unsigned int
F004B5C0: 92100019                 mov     %i1, %o1
F004B5C4: 7ffffed1                 call    _dirlook
F004B5C8: 94100013                 mov     %l3, %o2
F004B5CC: b0920000                 orcc    %o0, %g0, %i0
F004B5D0: 12800124                 bne     locret_F004BA60
F004B5D4: 01000000                 nop
F004B5D8: 10800122                 ba      locret_F004BA60
F004B5DC: b0102011                 mov     0x11, %i0
F004B5E0: 80a6a000                 cmp     %i2, 0
F004B5E4: 02800052                 be      loc_F004B72C
F004B5E8: c027bfec                 clr     [%fp+var_14]
F004B5EC: 10800008                 ba      loc_F004B60C
F004B5F0: d207a054                 ld      [%fp+arg_54], %o1
F004B5F4: d4122044                 lduh    [%o0+0x44], %o2
F004B5F8: 9210200a                 mov     0xA, %o1
F004B5FC: 9412a010                 bset    0x10, %o2
F004B600: 7fff1c1e                 call    _sleep
F004B604: d4322044                 sth     %o2, [%o0+0x44]
F004B608: d207a054                 ld      [%fp+arg_54], %o1
F004B60C: d0126044                 lduh    [%o1+0x44], %o0
F004B610: 808a2001                 btst    1, %o0
F004B614: 12bffff8                 bne     loc_F004B5F4
F004B618: 90100009                 mov     %o1, %o0
F004B61C: d207a054                 ld      [%fp+arg_54], %o1
F004B620: d0126044                 lduh    [%o1+0x44], %o0
F004B624: d8526066                 ldsh    [%o1+0x66], %o4
F004B628: 94122001                 or      %o0, 1, %o2
F004B62C: d4326044                 sth     %o2, [%o1+0x44]
F004B630: 80a32000                 cmp     %o4, 0
F004B634: 12800010                 bne     loc_F004B674
F004B638: 9610000c                 mov     %o4, %o3
F004B63C: 1100003f901223fe         set     0xFFFE, %o0
F004B644: 960a8008                 and     %o2, %o0, %o3
F004B648: 808aa010                 btst    0x10, %o2
F004B64C: 02800008                 be      loc_F004B66C
F004B650: d6326044                 sth     %o3, [%o1+0x44]
F004B654: 1100003f901223ef         set     0xFFEF, %o0
F004B65C: 900ac008                 and     %o3, %o0, %o0
F004B660: d0326044                 sth     %o0, [%o1+0x44]
F004B664: 7fff1de1                 call    _wakeup
F004B668: 90100009                 mov     %o1, %o0
F004B66C: 108000fd                 ba      locret_F004BA60
F004B670: b0102002                 mov     2, %i0
F004B674: 1100001f901223ff         set     0x7FFF, %o0
F004B67C: 80a30008                 cmp     %o4, %o0
F004B680: 12800010                 bne     loc_F004B6C0
F004B684: 9002e001                 add     %o3, 1, %o0
F004B688: 1100003f901223fe         set     0xFFFE, %o0
F004B690: 960a8008                 and     %o2, %o0, %o3
F004B694: 808aa010                 btst    0x10, %o2
F004B698: 02800008                 be      loc_F004B6B8
F004B69C: d6326044                 sth     %o3, [%o1+0x44]
F004B6A0: 1100003f901223ef         set     0xFFEF, %o0
F004B6A8: 900ac008                 and     %o3, %o0, %o0
F004B6AC: d0326044                 sth     %o0, [%o1+0x44]
F004B6B0: 7fff1dce                 call    _wakeup
F004B6B4: 90100009                 mov     %o1, %o0
F004B6B8: 108000ea                 ba      locret_F004BA60
F004B6BC: b010201f                 mov     0x1F, %i0
F004B6C0: d0326066                 sth     %o0, [%o1+0x66]
F004B6C4: 90100009                 mov     %o1, %o0
F004B6C8: d4122044                 lduh    [%o0+0x44], %o2
F004B6CC: 92102001                 mov     1, %o1
F004B6D0: 9412a040                 bset    0x40, %o2 ! '@'
F004B6D4: 40000b9c                 call    _iupdat
F004B6D8: d4322044                 sth     %o2, [%o0+0x44]
F004B6DC: d407a054                 ld      [%fp+arg_54], %o2
F004B6E0: 1100003f                 sethi   0xFC00, %o0
F004B6E4: d212a044                 lduh    [%o2+0x44], %o1
F004B6E8: 901223fe                 bset    0x3FE, %o0
F004B6EC: 920a4008                 and     %o1, %o0, %o1
F004B6F0: 808a6010                 btst    0x10, %o1
F004B6F4: 0280000e                 be      loc_F004B72C
F004B6F8: d232a044                 sth     %o1, [%o2+0x44]
F004B6FC: 1100003f901223ef         set     0xFFEF, %o0
F004B704: 900a4008                 and     %o1, %o0, %o0
F004B708: d032a044                 sth     %o0, [%o2+0x44]
F004B70C: 7fff1db7                 call    _wakeup
F004B710: 9010000a                 mov     %o2, %o0
F004B714: 10800007                 ba      loc_F004B730
F004B718: d0142044                 lduh    [%l0+0x44], %o0
F004B71C: d0342044                 sth     %o0, [%l0+0x44]
F004B720: 90100010                 mov     %l0, %o0! unsigned int
F004B724: 7fff1bd5                 call    _sleep
F004B728: 9210200a                 mov     0xA, %o1
F004B72C: d0142044                 lduh    [%l0+0x44], %o0
F004B730: 808a2001                 btst    1, %o0
F004B734: 12bffffa                 bne     loc_F004B71C
F004B738: 90122010                 bset    0x10, %o0
F004B73C: d0142044                 lduh    [%l0+0x44], %o0
F004B740: 90122001                 bset    1, %o0
F004B744: d0342044                 sth     %o0, [%l0+0x44]
F004B748: d0142064                 lduh    [%l0+0x64], %o0
F004B74C: 2500003c                 sethi   0xF000, %l2
F004B750: b80a0012                 and     %o0, %l2, %i4
F004B754: 11000010                 sethi   0x4000, %o0
F004B758: 80a70008                 cmp     %i4, %o0
F004B75C: 128000a3                 bne     loc_F004B9E8
F004B760: b0102014                 mov     0x14, %i0
F004B764: d0542066                 ldsh    [%l0+0x66], %o0
F004B768: 80a22000                 cmp     %o0, 0
F004B76C: 12800004                 bne     loc_F004B77C
F004B770: 90100010                 mov     %l0, %o0
F004B774: 1080009d                 ba      loc_F004B9E8
F004B778: b0102002                 mov     2, %i0
F004B77C: 40000e63                 call    _iaccess
F004B780: 92102040                 mov     0x40, %o1 ! '@'
F004B784: b0920000                 orcc    %o0, %g0, %i0
F004B788: 32800099                 bne,a   loc_F004B9EC
F004B78C: d007bfec                 ld      [%fp+var_14], %o0
F004B790: 80a6a002                 cmp     %i2, 2
F004B794: 12800017                 bne     loc_F004B7F0
F004B798: 90100010                 mov     %l0, %o0
F004B79C: d207a054                 ld      [%fp+arg_54], %o1
F004B7A0: d0126064                 lduh    [%o1+0x64], %o0
F004B7A4: 900a0012                 and     %o0, %l2, %o0
F004B7A8: 80a2001c                 cmp     %o0, %i4
F004B7AC: 32800011                 bne,a   loc_F004B7F0
F004B7B0: 90100010                 mov     %l0, %o0
F004B7B4: 80a6c010                 cmp     %i3, %l0
F004B7B8: 0280000d                 be      loc_F004B7EC
F004B7BC: 90100009                 mov     %o1, %o0
F004B7C0: 40000e52                 call    _iaccess
F004B7C4: 92102080                 mov     0x80, %o1
F004B7C8: b0920000                 orcc    %o0, %g0, %i0
F004B7CC: 12800088                 bne     loc_F004B9EC
F004B7D0: d007bfec                 ld      [%fp+var_14], %o0
F004B7D4: d007a054                 ld      [%fp+arg_54], %o0
F004B7D8: 400005b5                 call    sub_F004CEAC
F004B7DC: 92100010                 mov     %l0, %o1
F004B7E0: b0920000                 orcc    %o0, %g0, %i0
F004B7E4: 12800082                 bne     loc_F004B9EC
F004B7E8: d007bfec                 ld      [%fp+var_14], %o0
F004B7EC: 90100010                 mov     %l0, %o0
F004B7F0: 92100019                 mov     %i1, %o1
F004B7F4: 94100011                 mov     %l1, %o2
F004B7F8: b807bfe0                 add     %fp, var_20, %i4
F004B7FC: 9610001c                 mov     %i4, %o3
F004B800: 4000009a                 call    sub_F004BA68
F004B804: 9807bfdc                 add     %fp, var_24, %o4
F004B808: b0920000                 orcc    %o0, %g0, %i0
F004B80C: 32800078                 bne,a   loc_F004B9EC
F004B810: d007bfec                 ld      [%fp+var_14], %o0
F004B814: da07bfdc                 ld      [%fp+var_24], %o5
F004B818: 80a36000                 cmp     %o5, 0
F004B81C: 0280002a                 be      loc_F004B8C4
F004B820: 80a6a001                 cmp     %i2, 1
F004B824: 02800024                 be      loc_F004B8B4
F004B828: 01000000                 nop
F004B82C: 0a800006                 bcs     loc_F004B844
F004B830: 80a6a002                 cmp     %i2, 2
F004B834: 2280000e                 be,a    loc_F004B86C
F004B838: f823a05c                 st      %i4, [%sp+0x90+var_34]
F004B83C: 1080006c                 ba      loc_F004B9EC
F004B840: d007bfec                 ld      [%fp+var_14], %o0
F004B844: 80a4e000                 cmp     %l3, 0
F004B848: 02800005                 be      loc_F004B85C
F004B84C: 01000000                 nop
F004B850: da24c000                 st      %o5, [%l3]
F004B854: 10800065                 ba      loc_F004B9E8
F004B858: b0102011                 mov     0x11, %i0
F004B85C: 40000a4f                 call    _iput
F004B860: 9010000d                 mov     %o5, %o0
F004B864: 10800062                 ba      loc_F004B9EC
F004B868: d007bfec                 ld      [%fp+var_14], %o0
F004B86C: 9010001b                 mov     %i3, %o0
F004B870: 94100010                 mov     %l0, %o2
F004B874: 96100019                 mov     %i1, %o3
F004B878: d207a054                 ld      [%fp+arg_54], %o1
F004B87C: 40000121                 call    sub_F004BD00
F004B880: 98100011                 mov     %l1, %o4
F004B884: b0100008                 mov     %o0, %i0
F004B888: 40000a44                 call    _iput
F004B88C: d007bfdc                 ld      [%fp+var_24], %o0
F004B890: d207bfdc                 ld      [%fp+var_24], %o1
F004B894: d0526066                 ldsh    [%o1+0x66], %o0
F004B898: 80a22000                 cmp     %o0, 0
F004B89C: 12800054                 bne     loc_F004B9EC
F004B8A0: d007bfec                 ld      [%fp+var_14], %o0
F004B8A4: 40010247                 call    _vnode_uncache
F004B8A8: 9002600c                 add     %o1, 0xC, %o0
F004B8AC: 10800050                 ba      loc_F004B9EC
F004B8B0: d007bfec                 ld      [%fp+var_14], %o0
F004B8B4: 40000a39                 call    _iput
F004B8B8: 9010000d                 mov     %o5, %o0
F004B8BC: 1080004b                 ba      loc_F004B9E8
F004B8C0: b0102011                 mov     0x11, %i0
F004B8C4: 90100010                 mov     %l0, %o0
F004B8C8: 40000e10                 call    _iaccess
F004B8CC: 92102080                 mov     0x80, %o1
F004B8D0: b0920000                 orcc    %o0, %g0, %i0
F004B8D4: 32800046                 bne,a   loc_F004B9EC
F004B8D8: d007bfec                 ld      [%fp+var_14], %o0
F004B8DC: 80a6a000                 cmp     %i2, 0
F004B8E0: 12800009                 bne     loc_F004B904
F004B8E4: 90100010                 mov     %l0, %o0
F004B8E8: 9207a054                 add     %fp, arg_54, %o1
F004B8EC: 40000316                 call    sub_F004C544
F004B8F0: 9410001d                 mov     %i5, %o2
F004B8F4: b0920000                 orcc    %o0, %g0, %i0
F004B8F8: 1280003d                 bne     loc_F004B9EC
F004B8FC: d007bfec                 ld      [%fp+var_14], %o0
F004B900: 90100010                 mov     %l0, %o0
F004B904: 92100019                 mov     %i1, %o1
F004B908: 94100011                 mov     %l1, %o2
F004B90C: 9610001c                 mov     %i4, %o3
F004B910: d807a054                 ld      [%fp+arg_54], %o4
F004B914: 4000024b                 call    _diraddentry
F004B918: 9a10001b                 mov     %i3, %o5
F004B91C: b0920000                 orcc    %o0, %g0, %i0
F004B920: 02800017                 be      loc_F004B97C
F004B924: 80a6a000                 cmp     %i2, 0
F004B928: 12800031                 bne     loc_F004B9EC
F004B92C: d007bfec                 ld      [%fp+var_14], %o0
F004B930: d007a054                 ld      [%fp+arg_54], %o0
F004B934: d0122064                 lduh    [%o0+0x64], %o0
F004B938: 1300003c                 sethi   0xF000, %o1
F004B93C: 900a0009                 and     %o0, %o1, %o0
F004B940: 13000010                 sethi   0x4000, %o1
F004B944: 80a20009                 cmp     %o0, %o1
F004B948: 12800006                 bne     loc_F004B960
F004B94C: d007a054                 ld      [%fp+arg_54], %o0
F004B950: d0142066                 lduh    [%l0+0x66], %o0
F004B954: 90023fff                 inc     -1, %o0
F004B958: d0342066                 sth     %o0, [%l0+0x66]
F004B95C: d007a054                 ld      [%fp+arg_54], %o0! unsigned int
F004B960: d2122044                 lduh    [%o0+0x44], %o1
F004B964: c0322066                 clrh    [%o0+0x66]
F004B968: 92126040                 bset    0x40, %o1 ! '@'
F004B96C: 40000a42                 call    _irele
F004B970: d2322044                 sth     %o1, [%o0+0x44]
F004B974: 1080001d                 ba      loc_F004B9E8
F004B978: c027a054                 clr     [%fp+arg_54]
F004B97C: 80a4e000                 cmp     %l3, 0
F004B980: 02800016                 be      loc_F004B9D8
F004B984: 80a6a000                 cmp     %i2, 0
F004B988: 10800008                 ba      loc_F004B9A8
F004B98C: d207a054                 ld      [%fp+arg_54], %o1
F004B990: d4122044                 lduh    [%o0+0x44], %o2
F004B994: 9210200a                 mov     0xA, %o1
F004B998: 9412a010                 bset    0x10, %o2
F004B99C: 7fff1b37                 call    _sleep
F004B9A0: d4322044                 sth     %o2, [%o0+0x44]
F004B9A4: d207a054                 ld      [%fp+arg_54], %o1
F004B9A8: d0126044                 lduh    [%o1+0x44], %o0
F004B9AC: 808a2001                 btst    1, %o0
F004B9B0: 12bffff8                 bne     loc_F004B990
F004B9B4: 90100009                 mov     %o1, %o0
F004B9B8: d207a054                 ld      [%fp+arg_54], %o1
F004B9BC: d0126044                 lduh    [%o1+0x44], %o0
F004B9C0: 90122001                 bset    1, %o0
F004B9C4: d0326044                 sth     %o0, [%o1+0x44]
F004B9C8: 10800008                 ba      loc_F004B9E8
F004B9CC: d224c000                 st      %o1, [%l3]
F004B9D0: 10800024                 ba      locret_F004BA60
F004B9D4: b010200d                 mov     0xD, %i0
F004B9D8: 12800005                 bne     loc_F004B9EC
F004B9DC: d007bfec                 ld      [%fp+var_14], %o0
F004B9E0: 40000a25                 call    _irele
F004B9E4: d007a054                 ld      [%fp+arg_54], %o0
F004B9E8: d007bfec                 ld      [%fp+var_14], %o0
F004B9EC: 80a22000                 cmp     %o0, 0
F004B9F0: 02800005                 be      loc_F004BA04
F004B9F4: 80a62000                 cmp     %i0, 0
F004B9F8: 7fff639c                 call    _brelse
F004B9FC: 01000000                 nop
F004BA00: 80a62000                 cmp     %i0, 0
F004BA04: 0280000a                 be      loc_F004BA2C
F004BA08: 80a6a000                 cmp     %i2, 0
F004BA0C: 02800008                 be      loc_F004BA2C
F004BA10: d007a054                 ld      [%fp+arg_54], %o0
F004BA14: d2122066                 lduh    [%o0+0x66], %o1
F004BA18: d4122044                 lduh    [%o0+0x44], %o2
F004BA1C: 92027fff                 inc     -1, %o1
F004BA20: d2322066                 sth     %o1, [%o0+0x66]
F004BA24: 9412a040                 bset    0x40, %o2 ! '@'
F004BA28: d4322044                 sth     %o2, [%o0+0x44]
F004BA2C: d2142044                 lduh    [%l0+0x44], %o1
F004BA30: 1100003f901223fe         set     0xFFFE, %o0
F004BA38: 920a4008                 and     %o1, %o0, %o1
F004BA3C: 808a6010                 btst    0x10, %o1
F004BA40: 02800008                 be      locret_F004BA60
F004BA44: d2342044                 sth     %o1, [%l0+0x44]
F004BA48: 1100003f901223ef         set     0xFFEF, %o0
F004BA50: 900a4008                 and     %o1, %o0, %o0
F004BA54: d0342044                 sth     %o0, [%l0+0x44]
F004BA58: 7fff1ce4                 call    _wakeup
F004BA5C: 90100010                 mov     %l0, %o0
F004BA60: 81c7e008                 ret
F004BA64: 81e80000                 restore
