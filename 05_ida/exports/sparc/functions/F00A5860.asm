F00A5860: 9de3bf88                 save    %sp, -0x78, %sp
F00A5864: 213fbfff901423f8         set     -0x1000008, %o0
F00A586C: f007a040                 ld      [%fp+arg_40], %i0
F00A5870: 7fffdb55                 call    _pmap_change_prot
F00A5874: 92102007                 mov     7, %o1
F00A5878: da0c23f8                 ldub    [%l0+0x3F8], %o5
F00A587C: 901423f8                 or      %l0, 0x3F8, %o0
F00A5880: d40a2001                 ldub    [%o0+1], %o2
F00A5884: 9a136040                 bset    0x40, %o5 ! '@'
F00A5888: da2c23f8                 stb     %o5, [%l0+0x3F8]
F00A588C: 980aa00f                 and     %o2, 0xF, %o4
F00A5890: 940aa07f                 and     %o2, 0x7F, %o2
F00A5894: 9532a004                 srl     %o2, 4, %o2
F00A5898: 972aa002                 sll     %o2, 2, %o3
F00A589C: 9602c00a                 add     %o3, %o2, %o3
F00A58A0: 972ae001                 sll     %o3, 1, %o3
F00A58A4: d40a2002                 ldub    [%o0+2], %o2
F00A58A8: 9803000b                 add     %o4, %o3, %o4
F00A58AC: d82fbfe9                 stb     %o4, [%fp+var_17]
F00A58B0: 980aa00f                 and     %o2, 0xF, %o4
F00A58B4: 940aa07f                 and     %o2, 0x7F, %o2
F00A58B8: 9532a004                 srl     %o2, 4, %o2
F00A58BC: 972aa002                 sll     %o2, 2, %o3
F00A58C0: 9602c00a                 add     %o3, %o2, %o3
F00A58C4: 972ae001                 sll     %o3, 1, %o3
F00A58C8: d40a2003                 ldub    [%o0+3], %o2
F00A58CC: 9803000b                 add     %o4, %o3, %o4
F00A58D0: d82fbfea                 stb     %o4, [%fp+var_16]
F00A58D4: 980aa00f                 and     %o2, 0xF, %o4
F00A58D8: 940aa03f                 and     %o2, 0x3F, %o2
F00A58DC: 9532a004                 srl     %o2, 4, %o2
F00A58E0: 972aa002                 sll     %o2, 2, %o3
F00A58E4: 9602c00a                 add     %o3, %o2, %o3
F00A58E8: 972ae001                 sll     %o3, 1, %o3
F00A58EC: 9803000b                 add     %o4, %o3, %o4
F00A58F0: d60a2004                 ldub    [%o0+4], %o3
F00A58F4: 92102001                 mov     1, %o1
F00A58F8: d82fbfeb                 stb     %o4, [%fp+var_15]
F00A58FC: d40a2005                 ldub    [%o0+5], %o2
F00A5900: 960ae007                 and     %o3, 7, %o3
F00A5904: d62fbfec                 stb     %o3, [%fp+var_14]
F00A5908: 980aa00f                 and     %o2, 0xF, %o4
F00A590C: 940aa03f                 and     %o2, 0x3F, %o2
F00A5910: 9532a004                 srl     %o2, 4, %o2
F00A5914: 972aa002                 sll     %o2, 2, %o3
F00A5918: 9602c00a                 add     %o3, %o2, %o3
F00A591C: 972ae001                 sll     %o3, 1, %o3
F00A5920: d40a2006                 ldub    [%o0+6], %o2
F00A5924: 9803000b                 add     %o4, %o3, %o4
F00A5928: d82fbfed                 stb     %o4, [%fp+var_13]
F00A592C: 980aa00f                 and     %o2, 0xF, %o4
F00A5930: 940aa01f                 and     %o2, 0x1F, %o2
F00A5934: 9532a004                 srl     %o2, 4, %o2
F00A5938: 972aa002                 sll     %o2, 2, %o3
F00A593C: 9602c00a                 add     %o3, %o2, %o3
F00A5940: 972ae001                 sll     %o3, 1, %o3
F00A5944: 9803000b                 add     %o4, %o3, %o4
F00A5948: d60a2007                 ldub    [%o0+7], %o3
F00A594C: 9a0b60bf                 and     %o5, 0xBF, %o5
F00A5950: d82fbfee                 stb     %o4, [%fp+var_12]
F00A5954: 980ae00f                 and     %o3, 0xF, %o4
F00A5958: 9732e004                 srl     %o3, 4, %o3
F00A595C: 952ae002                 sll     %o3, 2, %o2
F00A5960: 9402800b                 add     %o2, %o3, %o2
F00A5964: 952aa001                 sll     %o2, 1, %o2
F00A5968: 9803000a                 add     %o4, %o2, %o4
F00A596C: d82fbfef                 stb     %o4, [%fp+var_11]
F00A5970: 7fffdb15                 call    _pmap_change_prot
F00A5974: da2c23f8                 stb     %o5, [%l0+0x3F8]
F00A5978: d00fbfee                 ldub    [%fp+var_12], %o0
F00A597C: 80a22000                 cmp     %o0, 0
F00A5980: 02800013                 be      loc_F00A59CC
F00A5984: a0102000                 mov     0, %l0
F00A5988: 80a2200c                 cmp     %o0, 0xC
F00A598C: 18800010                 bgu     loc_F00A59CC
F00A5990: d00fbfed                 ldub    [%fp+var_13], %o0
F00A5994: 80a22000                 cmp     %o0, 0
F00A5998: 0280000d                 be      loc_F00A59CC
F00A599C: 80a2201f                 cmp     %o0, 0x1F
F00A59A0: 1880000b                 bgu     loc_F00A59CC
F00A59A4: d00fbfea                 ldub    [%fp+var_16], %o0
F00A59A8: 80a2203b                 cmp     %o0, 0x3B ! ';'
F00A59AC: 18800008                 bgu     loc_F00A59CC
F00A59B0: d00fbfe9                 ldub    [%fp+var_17], %o0
F00A59B4: 80a2203b                 cmp     %o0, 0x3B ! ';'
F00A59B8: 18800005                 bgu     loc_F00A59CC
F00A59BC: d00fbfef                 ldub    [%fp+var_11], %o0
F00A59C0: 80a22001                 cmp     %o0, 1
F00A59C4: 18800006                 bgu     loc_F00A59DC
F00A59C8: 92100008                 mov     %o0, %o1
F00A59CC: c027bff0                 clr     [%fp+var_10]
F00A59D0: c027bff4                 clr     [%fp+var_C]
F00A59D4: 10800049                 ba      loc_F00A5AF8
F00A59D8: c0260000                 clr     [%i0]
F00A59DC: 80a26002                 cmp     %o1, 2
F00A59E0: 08800011                 bleu    loc_F00A5A24
F00A59E4: 94102002                 mov     2, %o2
F00A59E8: 110078a198122100         set     0x1E28500, %o4
F00A59F0: 1100784c96122380         set     0x1E13380, %o3
F00A59F8: 808aa003                 btst    3, %o2
F00A59FC: 32800003                 bne,a   loc_F00A5A08
F00A5A00: a004000b                 add     %l0, %o3, %l0
F00A5A04: a004000c                 add     %l0, %o4, %l0
F00A5A08: 9002a001                 add     %o2, 1, %o0
F00A5A0C: 94100008                 mov     %o0, %o2
F00A5A10: 912a2010                 sll     %o0, 16, %o0
F00A5A14: 91322010                 srl     %o0, 16, %o0
F00A5A18: 80a20009                 cmp     %o0, %o1
F00A5A1C: 0abffff8                 bcs     loc_F00A59FC
F00A5A20: 808aa003                 btst    3, %o2
F00A5A24: d60fbfee                 ldub    [%fp+var_12], %o3
F00A5A28: 92102001                 mov     1, %o1
F00A5A2C: 80a2400b                 cmp     %o1, %o3
F00A5A30: 16800015                 bge     loc_F00A5A84
F00A5A34: d00fbfed                 ldub    [%fp+var_13], %o0
F00A5A38: 980aa003                 and     %o2, 3, %o4
F00A5A3C: 113c046684122108         set     _clk_state, %g2
F00A5A44: 1100098e9a122380         set     0x263B80, %o5
F00A5A4C: 94102004                 mov     4, %o2
F00A5A50: 80a32000                 cmp     %o4, 0
F00A5A54: 32800006                 bne,a   loc_F00A5A6C
F00A5A58: d0028002                 ld      [%o2+%g2], %o0
F00A5A5C: 80a26002                 cmp     %o1, 2
F00A5A60: 22800004                 be,a    loc_F00A5A70
F00A5A64: a004000d                 add     %l0, %o5, %l0
F00A5A68: d0028002                 ld      [%o2+%g2], %o0
F00A5A6C: a0040008                 add     %l0, %o0, %l0
F00A5A70: 92026001                 inc     %o1
F00A5A74: 80a2400b                 cmp     %o1, %o3
F00A5A78: 06bffff6                 bl      loc_F00A5A50
F00A5A7C: 9402a004                 inc     4, %o2
F00A5A80: d00fbfed                 ldub    [%fp+var_13], %o0
F00A5A84: d40fbfeb                 ldub    [%fp+var_15], %o2
F00A5A88: 90023fff                 inc     -1, %o0
F00A5A8C: 932a2001                 sll     %o0, 1, %o1
F00A5A90: 92024008                 add     %o1, %o0, %o1
F00A5A94: 912a6004                 sll     %o1, 4, %o0
F00A5A98: 90220009                 sub     %o0, %o1, %o0
F00A5A9C: 932a2004                 sll     %o0, 4, %o1
F00A5AA0: 92224008                 sub     %o1, %o0, %o1
F00A5AA4: 932a6007                 sll     %o1, 7, %o1
F00A5AA8: a0040009                 add     %l0, %o1, %l0
F00A5AAC: 912aa003                 sll     %o2, 3, %o0
F00A5AB0: 9022000a                 sub     %o0, %o2, %o0
F00A5AB4: 912a2005                 sll     %o0, 5, %o0
F00A5AB8: 9002000a                 add     %o0, %o2, %o0
F00A5ABC: 912a2004                 sll     %o0, 4, %o0
F00A5AC0: d20fbfea                 ldub    [%fp+var_16], %o1
F00A5AC4: a0040008                 add     %l0, %o0, %l0
F00A5AC8: 912a6004                 sll     %o1, 4, %o0
F00A5ACC: 90220009                 sub     %o0, %o1, %o0
F00A5AD0: 912a2002                 sll     %o0, 2, %o0
F00A5AD4: d20fbfe9                 ldub    [%fp+var_17], %o1
F00A5AD8: a0040008                 add     %l0, %o0, %l0
F00A5ADC: a0840009                 addcc   %l0, %o1, %l0
F00A5AE0: 3c800003                 bpos,a  loc_F00A5AEC
F00A5AE4: e027bff0                 st      %l0, [%fp+var_10]
F00A5AE8: c027bff0                 clr     [%fp+var_10]
F00A5AEC: c027bff4                 clr     [%fp+var_C]
F00A5AF0: d007bff0                 ld      [%fp+var_10], %o0
F00A5AF4: d0260000                 st      %o0, [%i0]
F00A5AF8: d007bff4                 ld      [%fp+var_C], %o0
F00A5AFC: d0262004                 st      %o0, [%i0+4]
F00A5B00: 81c7e00c                 jmp     %i7+0xC
F00A5B04: 81e80000                 restore
