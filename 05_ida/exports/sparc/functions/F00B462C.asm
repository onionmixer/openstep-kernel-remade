F00B462C: 9de3bf98                 save    %sp, -0x68, %sp
F00B4630: a0100018                 mov     %i0, %l0
F00B4634: e2042048                 ld      [%l0+0x48], %l1
F00B4638: e404209c                 ld      [%l0+0x9C], %l2
F00B463C: d05420b2                 ldsh    [%l0+0xB2], %o0
F00B4640: e60420a0                 ld      [%l0+0xA0], %l3
F00B4644: 912a2002                 sll     %o0, 2, %o0
F00B4648: d204c000                 ld      [%l3], %o1
F00B464C: 90020010                 add     %o0, %l0, %o0
F00B4650: 808a6003                 btst    3, %o1
F00B4654: 128000be                 bne     loc_F00B494C
F00B4658: f00220b8                 ld      [%o0+0xB8], %i0
F00B465C: c02c2053                 clrb    [%l0+0x53]
F00B4660: c02c2046                 clrb    [%l0+0x46]
F00B4664: e80e2009                 ldub    [%i0+9], %l4
F00B4668: 90102001                 mov     1, %o0
F00B466C: d60e2063                 ldub    [%i0+0x63], %o3
F00B4670: 80a2e00a                 cmp     %o3, 0xA
F00B4674: 02800008                 be      loc_F00B4694
F00B4678: 932a0014                 sll     %o0, %l4, %o1
F00B467C: 80a2e00a                 cmp     %o3, 0xA
F00B4680: 14800003                 bg      loc_F00B468C
F00B4684: 80a2e00c                 cmp     %o3, 0xC
F00B4688: 80a2e006                 cmp     %o3, 6
F00B468C: 32800002                 bne,a   loc_F00B4694
F00B4690: 96102000                 mov     0, %o3
F00B4694: d00c207b                 ldub    [%l0+0x7B], %o0
F00B4698: 808a0009                 btst    %o1, %o0
F00B469C: 0280000f                 be      loc_F00B46D8
F00B46A0: 98102041                 mov     0x41, %o4 ! 'A'
F00B46A4: d00c2079                 ldub    [%l0+0x79], %o0
F00B46A8: 808a0009                 btst    %o1, %o0
F00B46AC: 12800048                 bne     loc_F00B47CC
F00B46B0: 9a102080                 mov     0x80, %o5
F00B46B4: d0062014                 ld      [%i0+0x14], %o0
F00B46B8: 808a2002                 btst    2, %o0
F00B46BC: 12800044                 bne     loc_F00B47CC
F00B46C0: 153c047c                 sethi   %hi(_scsi_options), %o2
F00B46C4: d002a158                 ld      [%o2+%lo(_scsi_options)], %o0
F00B46C8: 808a2008                 btst    8, %o0
F00B46CC: 32800005                 bne,a   loc_F00B46E0
F00B46D0: d00e200a                 ldub    [%i0+0xA], %o0
F00B46D4: 98102041                 mov     0x41, %o4 ! 'A'
F00B46D8: 1080003d                 ba      loc_F00B47CC
F00B46DC: 9a102080                 mov     0x80, %o5
F00B46E0: 901220c0                 bset    0xC0, %o0
F00B46E4: d02c4000                 stb     %o0, [%l1]
F00B46E8: d016205c                 lduh    [%i0+0x5C], %o0
F00B46EC: 808a2100                 btst    0x100, %o0
F00B46F0: 02800015                 be      loc_F00B4744
F00B46F4: a2046001                 inc     %l1
F00B46F8: d00e206c                 ldub    [%i0+0x6C], %o0
F00B46FC: 94102000                 mov     0, %o2
F00B4700: 80a28008                 cmp     %o2, %o0
F00B4704: 1680000b                 bge     loc_F00B4730
F00B4708: d02c2053                 stb     %o0, [%l0+0x53]
F00B470C: 9006000a                 add     %i0, %o2, %o0
F00B4710: d20a206d                 ldub    [%o0+0x6D], %o1
F00B4714: 9004000a                 add     %l0, %o2, %o0
F00B4718: d22a204c                 stb     %o1, [%o0+0x4C]
F00B471C: d00c2053                 ldub    [%l0+0x53], %o0
F00B4720: 9402a001                 inc     %o2
F00B4724: 80a28008                 cmp     %o2, %o0
F00B4728: 06bffffa                 bl      loc_F00B4710
F00B472C: 9006000a                 add     %i0, %o2, %o0
F00B4730: c02e206b                 clrb    [%i0+0x6B]
F00B4734: 98102043                 mov     0x43, %o4 ! 'C'
F00B4738: 9a102060                 mov     0x60, %o5 ! '`'
F00B473C: 10800024                 ba      loc_F00B47CC
F00B4740: 96102000                 mov     0, %o3
F00B4744: d00c2078                 ldub    [%l0+0x78], %o0
F00B4748: 808a0009                 btst    %o1, %o0
F00B474C: 12800007                 bne     loc_F00B4768
F00B4750: 80a2e000                 cmp     %o3, 0
F00B4754: d002a158                 ld      [%o2+0x158], %o0
F00B4758: 808a2020                 btst    0x20, %o0 ! ' '
F00B475C: 3280000a                 bne,a   loc_F00B4784
F00B4760: d00c207a                 ldub    [%l0+0x7A], %o0
F00B4764: 80a2e000                 cmp     %o3, 0
F00B4768: 02800004                 be      loc_F00B4778
F00B476C: 98102042                 mov     0x42, %o4 ! 'B'
F00B4770: 10800017                 ba      loc_F00B47CC
F00B4774: 9a102020                 mov     0x20, %o5 ! ' '
F00B4778: 98102043                 mov     0x43, %o4 ! 'C'
F00B477C: 10800014                 ba      loc_F00B47CC
F00B4780: 9a102040                 mov     0x40, %o5 ! '@'
F00B4784: 808a0009                 btst    %o1, %o0
F00B4788: 02800005                 be      loc_F00B479C
F00B478C: 90100010                 mov     %l0, %o0
F00B4790: 92102000                 mov     0, %o1
F00B4794: 10800004                 ba      loc_F00B47A4
F00B4798: 94102000                 mov     0, %o2
F00B479C: d20c2076                 ldub    [%l0+0x76], %o1
F00B47A0: 9410200f                 mov     0xF, %o2
F00B47A4: 40000b47                 call    _esp_make_sdtr
F00B47A8: 01000000                 nop
F00B47AC: 96102000                 mov     0, %o3
F00B47B0: 98102043                 mov     0x43, %o4 ! 'C'
F00B47B4: 9a102060                 mov     0x60, %o5 ! '`'
F00B47B8: 90102001                 mov     1, %o0
F00B47BC: d20c2078                 ldub    [%l0+0x78], %o1
F00B47C0: 912a0014                 sll     %o0, %l4, %o0
F00B47C4: 92124008                 bset    %o0, %o1
F00B47C8: d22c2078                 stb     %o1, [%l0+0x78]
F00B47CC: 94102000                 mov     0, %o2
F00B47D0: 80a2800b                 cmp     %o2, %o3
F00B47D4: 3680000a                 bge,a   loc_F00B47FC
F00B47D8: d0042048                 ld      [%l0+0x48], %o0
F00B47DC: d006202c                 ld      [%i0+0x2C], %o0
F00B47E0: d00a000a                 ldub    [%o0+%o2], %o0
F00B47E4: d02c4000                 stb     %o0, [%l1]
F00B47E8: 9402a001                 inc     %o2
F00B47EC: 80a2800b                 cmp     %o2, %o3
F00B47F0: 06bffffb                 bl      loc_F00B47DC
F00B47F4: a2046001                 inc     %l1
F00B47F8: d0042048                 ld      [%l0+0x48], %o0
F00B47FC: 94050010                 add     %l4, %l0, %o2
F00B4800: 90244008                 sub     %l1, %o0, %o0
F00B4804: d02420a8                 st      %o0, [%l0+0xA8]
F00B4808: e82ca010                 stb     %l4, [%l2+0x10]
F00B480C: d00aa066                 ldub    [%o2+0x66], %o0
F00B4810: 900a201f                 and     %o0, 0x1F, %o0
F00B4814: d02ca018                 stb     %o0, [%l2+0x18]
F00B4818: d00aa05e                 ldub    [%o2+0x5E], %o0
F00B481C: d20c2077                 ldub    [%l0+0x77], %o1
F00B4820: 90120009                 bset    %o1, %o0
F00B4824: d02ca01c                 stb     %o0, [%l2+0x1C]
F00B4828: d00c2031                 ldub    [%l0+0x31], %o0
F00B482C: 90023ffd                 inc     -3, %o0
F00B4830: 900a20ff                 and     %o0, 0xFF, %o0
F00B4834: 80a22001                 cmp     %o0, 1
F00B4838: 18800005                 bgu     loc_F00B484C
F00B483C: 113c047c                 sethi   -0xFEE1000, %o0
F00B4840: d00aa034                 ldub    [%o2+0x34], %o0
F00B4844: d02ca030                 stb     %o0, [%l2+0x30]
F00B4848: 113c047c                 sethi   -0xFEE1000, %o0
F00B484C: d0022158                 ld      [%o0+0x158], %o0
F00B4850: 808a2040                 btst    0x40, %o0 ! '@'
F00B4854: 2280000a                 be,a    loc_F00B487C
F00B4858: d00c2033                 ldub    [%l0+0x33], %o0
F00B485C: d0062014                 ld      [%i0+0x14], %o0
F00B4860: 808a2008                 btst    8, %o0
F00B4864: 22800006                 be,a    loc_F00B487C
F00B4868: d00c2033                 ldub    [%l0+0x33], %o0
F00B486C: d00c2032                 ldub    [%l0+0x32], %o0
F00B4870: 900a20ef                 and     %o0, 0xEF, %o0
F00B4874: d02ca020                 stb     %o0, [%l2+0x20]
F00B4878: d00c2033                 ldub    [%l0+0x33], %o0
F00B487C: 808a2040                 btst    0x40, %o0 ! '@'
F00B4880: 02800009                 be      loc_F00B48A4
F00B4884: d00420a8                 ld      [%l0+0xA8], %o0
F00B4888: d02c8000                 stb     %o0, [%l2]
F00B488C: d00420a8                 ld      [%l0+0xA8], %o0
F00B4890: 91322008                 srl     %o0, 8, %o0
F00B4894: d02ca004                 stb     %o0, [%l2+4]
F00B4898: d01420a8                 lduh    [%l0+0xA8], %o0
F00B489C: 10800006                 ba      loc_F00B48B4
F00B48A0: d02ca038                 stb     %o0, [%l2+0x38]
F00B48A4: d02c8000                 stb     %o0, [%l2]
F00B48A8: d00420a8                 ld      [%l0+0xA8], %o0
F00B48AC: 91322008                 srl     %o0, 8, %o0
F00B48B0: d02ca004                 stb     %o0, [%l2+4]
F00B48B4: d004c000                 ld      [%l3], %o0
F00B48B8: 9132201c                 srl     %o0, 28, %o0
F00B48BC: 80a22004                 cmp     %o0, 4
F00B48C0: 12800004                 bne     loc_F00B48D0
F00B48C4: 173c0000                 sethi   -0x10000000, %o3
F00B48C8: d00420a8                 ld      [%l0+0xA8], %o0
F00B48CC: d024e008                 st      %o0, [%l3+8]
F00B48D0: 113ffc00                 sethi   -0x100000, %o0
F00B48D4: d2042048                 ld      [%l0+0x48], %o1
F00B48D8: 90122000                 bset    0, %o0
F00B48DC: d40420ac                 ld      [%l0+0xAC], %o2
F00B48E0: 92224008                 sub     %o1, %o0, %o1
F00B48E4: 9212400a                 bset    %o2, %o1
F00B48E8: d22420a4                 st      %o1, [%l0+0xA4]
F00B48EC: d404c000                 ld      [%l3], %o2
F00B48F0: 900a800b                 and     %o2, %o3, %o0
F00B48F4: 9132201c                 srl     %o0, 28, %o0
F00B48F8: 80a22004                 cmp     %o0, 4
F00B48FC: 12800006                 bne     loc_F00B4914
F00B4900: d224e004                 st      %o1, [%l3+4]
F00B4904: 9012a210                 or      %o2, 0x210, %o0
F00B4908: 920abeff                 and     %o2, -0x101, %o1
F00B490C: 10800004                 ba      loc_F00B491C
F00B4910: 90120009                 bset    %o1, %o0
F00B4914: 900abeff                 and     %o2, -0x101, %o0
F00B4918: 90122210                 bset    0x210, %o0
F00B491C: d024c000                 st      %o0, [%l3]
F00B4920: d004c000                 ld      [%l3], %o0
F00B4924: 808a2003                 btst    3, %o0
F00B4928: 3280000a                 bne,a   loc_F00B4950
F00B492C: d00c2041                 ldub    [%l0+0x41], %o0
F00B4930: 90132080                 or      %o4, 0x80, %o0
F00B4934: d02ca00c                 stb     %o0, [%l2+0xC]
F00B4938: d00c2041                 ldub    [%l0+0x41], %o0
F00B493C: b0102001                 mov     1, %i0
F00B4940: d02c2042                 stb     %o0, [%l0+0x42]
F00B4944: 1080000e                 ba      locret_F00B497C
F00B4948: da2c2041                 stb     %o5, [%l0+0x41]
F00B494C: d00c2041                 ldub    [%l0+0x41], %o0
F00B4950: 92103fff                 mov     -1, %o1
F00B4954: d02c2042                 stb     %o0, [%l0+0x42]
F00B4958: d01420b2                 lduh    [%l0+0xB2], %o0
F00B495C: c02c2041                 clrb    [%l0+0x41]
F00B4960: d03420b0                 sth     %o0, [%l0+0xB0]
F00B4964: d004208c                 ld      [%l0+0x8C], %o0
F00B4968: d23420b2                 sth     %o1, [%l0+0xB2]
F00B496C: 90022001                 inc     %o0
F00B4970: 400000c1                 call    _esp_poll
F00B4974: d024208c                 st      %o0, [%l0+0x8C]
F00B4978: b0102000                 mov     0, %i0
F00B497C: 81c7e008                 ret
F00B4980: 81e80000                 restore
