F000791C: 9de3bfc0                 save    %sp, -0x40, %sp
F0007920: 80a6a008                 cmp     %i2, 8
F0007924: 04800192                 ble     loc_F0007F6C
F0007928: ba100018                 mov     %i0, %i5
F000792C: b68e6003                 andcc   %i1, 3, %i3
F0007930: 0280001f                 be      loc_F00079AC
F0007934: 80a6e002                 cmp     %i3, 2
F0007938: 0280000b                 be      loc_F0007964
F000793C: 80a6e003                 cmp     %i3, 3
F0007940: f60e4000                 ldub    [%i1], %i3
F0007944: b2066001                 inc     %i1
F0007948: b426a001                 dec     %i2
F000794C: f62e0000                 stb     %i3, [%i0]
F0007950: 02800014                 be      loc_F00079A0
F0007954: 8096c000                 tst     %i3
F0007958: 12800003                 bne     loc_F0007964
F000795C: b0062001                 inc     %i0
F0007960: 3080018c                 ba,a    loc_F0007F90
F0007964: f6164000                 lduh    [%i1], %i3
F0007968: b2066002                 inc     2, %i1
F000796C: b426a002                 dec     2, %i2
F0007970: b936e008                 srl     %i3, 8, %i4
F0007974: 80970000                 tst     %i4
F0007978: f82e0000                 stb     %i4, [%i0]
F000797C: 32800005                 bne,a   loc_F0007990
F0007980: f62e2001                 stb     %i3, [%i0+1]
F0007984: b406a001                 inc     %i2
F0007988: b0062001                 inc     %i0
F000798C: 30800181                 ba,a    loc_F0007F90
F0007990: b68ee0ff                 andcc   %i3, 0xFF, %i3
F0007994: 12800006                 bne     loc_F00079AC
F0007998: b0062002                 inc     2, %i0
F000799C: 3080017d                 ba,a    loc_F0007F90
F00079A0: 12800003                 bne     loc_F00079AC
F00079A4: b0062001                 inc     %i0
F00079A8: 3080017a                 ba,a    loc_F0007F90
F00079AC: 211fbfbfa01422ff         set     0x7EFEFEFF, %l0
F00079B4: 23204040a2146100         set     -0x7EFEFF00, %l1
F00079BC: 253fc000                 sethi   -0x1000000, %l2
F00079C0: 27003fc0                 sethi   0xFF0000, %l3
F00079C4: b68e2003                 andcc   %i0, 3, %i3
F00079C8: 0280013f                 be      loc_F0007EC4
F00079CC: a934e008                 srl     %l3, 8, %l4
F00079D0: 80a6e002                 cmp     %i3, 2
F00079D4: 028000d6                 be      loc_F0007D2C
F00079D8: 80a6e003                 cmp     %i3, 3
F00079DC: f6064000                 ld      [%i1], %i3
F00079E0: b2066004                 inc     4, %i1
F00079E4: 02800063                 be      loc_F0007B70
F00079E8: 808ec012                 btst    %l2, %i3
F00079EC: 12800007                 bne     loc_F0007A08
F00079F0: 808ec013                 btst    %l3, %i3
F00079F4: c02e0000                 clrb    [%i0]
F00079F8: b0062001                 inc     %i0
F00079FC: b426a001                 dec     %i2
F0007A00: 10800164                 ba      loc_F0007F90
F0007A04: b2266003                 dec     3, %i1
F0007A08: 12800009                 bne     loc_F0007A2C
F0007A0C: 808ec014                 btst    %l4, %i3
F0007A10: b426a002                 dec     2, %i2
F0007A14: 9736e018                 srl     %i3, 24, %o3
F0007A18: d62e0000                 stb     %o3, [%i0]
F0007A1C: c02e2001                 clrb    [%i0+1]
F0007A20: b0062002                 inc     2, %i0
F0007A24: 1080015b                 ba      loc_F0007F90
F0007A28: b2266002                 dec     2, %i1
F0007A2C: 1280000a                 bne     loc_F0007A54
F0007A30: 808ee0ff                 btst    0xFF, %i3
F0007A34: 9736e008                 srl     %i3, 8, %o3
F0007A38: d6362001                 sth     %o3, [%i0+1]
F0007A3C: 9736e018                 srl     %i3, 24, %o3
F0007A40: d62e0000                 stb     %o3, [%i0]
F0007A44: b426a003                 dec     3, %i2
F0007A48: b0062003                 inc     3, %i0
F0007A4C: 10800151                 ba      loc_F0007F90
F0007A50: b2266001                 dec     %i1
F0007A54: 02800009                 be      loc_F0007A78
F0007A58: 9736e018                 srl     %i3, 24, %o3
F0007A5C: d62e0000                 stb     %o3, [%i0]
F0007A60: 9736e008                 srl     %i3, 8, %o3
F0007A64: d6362001                 sth     %o3, [%i0+1]
F0007A68: b0062003                 inc     3, %i0
F0007A6C: b426a003                 dec     3, %i2
F0007A70: 1080000b                 ba      loc_F0007A9C
F0007A74: 9610001b                 mov     %i3, %o3
F0007A78: 9736e018                 srl     %i3, 24, %o3
F0007A7C: d62e0000                 stb     %o3, [%i0]
F0007A80: 9736e008                 srl     %i3, 8, %o3
F0007A84: d6362001                 sth     %o3, [%i0+1]
F0007A88: c02e2003                 clrb    [%i0+3]
F0007A8C: b0062004                 inc     4, %i0
F0007A90: 10800140                 ba      loc_F0007F90
F0007A94: b426a004                 dec     4, %i2
F0007A98: b0062004                 inc     4, %i0
F0007A9C: b4a6a004                 deccc   4, %i2
F0007AA0: 16800005                 bge     loc_F0007AB4
F0007AA4: 952ae018                 sll     %o3, 24, %o2
F0007AA8: b2266001                 dec     %i1
F0007AAC: 10800130                 ba      loc_F0007F6C
F0007AB0: b406a004                 inc     4, %i2
F0007AB4: 808a8012                 btst    %l2, %o2
F0007AB8: 32800007                 bne,a   loc_F0007AD4
F0007ABC: 808a8012                 btst    %l2, %o2
F0007AC0: c02e0000                 clrb    [%i0]
F0007AC4: b0062001                 inc     %i0
F0007AC8: b406a003                 inc     3, %i2
F0007ACC: 10800131                 ba      loc_F0007F90
F0007AD0: b2266003                 dec     3, %i1
F0007AD4: d6064000                 ld      [%i1], %o3
F0007AD8: b2066004                 inc     4, %i1
F0007ADC: b732e008                 srl     %o3, 8, %i3
F0007AE0: b616c00a                 bset    %o2, %i3
F0007AE4: aa06c010                 add     %i3, %l0, %l5
F0007AE8: aa1d401b                 btog    %i3, %l5
F0007AEC: aa0d4011                 and     %l5, %l1, %l5
F0007AF0: 80a54011                 cmp     %l5, %l1
F0007AF4: 22bfffe9                 be,a    loc_F0007A98
F0007AF8: f6260000                 st      %i3, [%i0]
F0007AFC: 808ec012                 btst    %l2, %i3
F0007B00: 12800007                 bne     loc_F0007B1C
F0007B04: 808ec013                 btst    %l3, %i3
F0007B08: c02e0000                 clrb    [%i0]
F0007B0C: b0062001                 inc     %i0
F0007B10: b406a003                 inc     3, %i2
F0007B14: 1080011f                 ba      loc_F0007F90
F0007B18: b2266003                 dec     3, %i1
F0007B1C: 12800008                 bne     loc_F0007B3C
F0007B20: 808ec014                 btst    %l4, %i3
F0007B24: 9736e010                 srl     %i3, 16, %o3
F0007B28: d6360000                 sth     %o3, [%i0]
F0007B2C: b0062002                 inc     2, %i0
F0007B30: b406a002                 inc     2, %i2
F0007B34: 10800117                 ba      loc_F0007F90
F0007B38: b2266002                 dec     2, %i1
F0007B3C: 12800009                 bne     loc_F0007B60
F0007B40: 808ee0ff                 btst    0xFF, %i3
F0007B44: 9736e010                 srl     %i3, 16, %o3
F0007B48: d6360000                 sth     %o3, [%i0]
F0007B4C: c02e2002                 clrb    [%i0+2]
F0007B50: b0062003                 inc     3, %i0
F0007B54: b406a001                 inc     %i2
F0007B58: 1080010e                 ba      loc_F0007F90
F0007B5C: b2266001                 dec     %i1
F0007B60: f6260000                 st      %i3, [%i0]
F0007B64: 12bfffce                 bne     loc_F0007A9C
F0007B68: b0062004                 inc     4, %i0
F0007B6C: 30800109                 ba,a    loc_F0007F90
F0007B70: 12800007                 bne     loc_F0007B8C
F0007B74: 808ec013                 btst    %l3, %i3
F0007B78: c02e0000                 clrb    [%i0]
F0007B7C: b0062001                 inc     %i0
F0007B80: b426a001                 dec     %i2
F0007B84: 10800103                 ba      loc_F0007F90
F0007B88: b2266003                 dec     3, %i1
F0007B8C: 12800009                 bne     loc_F0007BB0
F0007B90: 808ec014                 btst    %l4, %i3
F0007B94: b426a002                 dec     2, %i2
F0007B98: 9736e018                 srl     %i3, 24, %o3
F0007B9C: d62e0000                 stb     %o3, [%i0]
F0007BA0: c02e2001                 clrb    [%i0+1]
F0007BA4: b0062002                 inc     2, %i0
F0007BA8: 108000fa                 ba      loc_F0007F90
F0007BAC: b2266002                 dec     2, %i1
F0007BB0: 1280000a                 bne     loc_F0007BD8
F0007BB4: 808ee0ff                 btst    0xFF, %i3
F0007BB8: 9736e008                 srl     %i3, 8, %o3
F0007BBC: d6362001                 sth     %o3, [%i0+1]
F0007BC0: 9736e018                 srl     %i3, 24, %o3
F0007BC4: d62e0000                 stb     %o3, [%i0]
F0007BC8: b426a003                 dec     3, %i2
F0007BCC: b0062003                 inc     3, %i0
F0007BD0: 108000f0                 ba      loc_F0007F90
F0007BD4: b2266001                 dec     %i1
F0007BD8: 02800007                 be      loc_F0007BF4
F0007BDC: 9736e018                 srl     %i3, 24, %o3
F0007BE0: d62e0000                 stb     %o3, [%i0]
F0007BE4: b0062001                 inc     %i0
F0007BE8: b426a001                 dec     %i2
F0007BEC: 1080000a                 ba      loc_F0007C14
F0007BF0: 9610001b                 mov     %i3, %o3
F0007BF4: d62e0000                 stb     %o3, [%i0]
F0007BF8: 9736e008                 srl     %i3, 8, %o3
F0007BFC: d6362001                 sth     %o3, [%i0+1]
F0007C00: c02e2003                 clrb    [%i0+3]
F0007C04: b0062004                 inc     4, %i0
F0007C08: 108000e2                 ba      loc_F0007F90
F0007C0C: b426a004                 dec     4, %i2
F0007C10: b0062004                 inc     4, %i0
F0007C14: b4a6a004                 deccc   4, %i2
F0007C18: 16800005                 bge     loc_F0007C2C
F0007C1C: 952ae008                 sll     %o3, 8, %o2
F0007C20: b2266003                 dec     3, %i1
F0007C24: 108000d2                 ba      loc_F0007F6C
F0007C28: b406a004                 inc     4, %i2
F0007C2C: 808a8012                 btst    %l2, %o2
F0007C30: 12800007                 bne     loc_F0007C4C
F0007C34: 808a8013                 btst    %l3, %o2
F0007C38: c02e0000                 clrb    [%i0]
F0007C3C: b0062001                 inc     %i0
F0007C40: b406a003                 inc     3, %i2
F0007C44: 108000d3                 ba      loc_F0007F90
F0007C48: b2266003                 dec     3, %i1
F0007C4C: 12800008                 bne     loc_F0007C6C
F0007C50: 808a8014                 btst    %l4, %o2
F0007C54: 9732a010                 srl     %o2, 16, %o3
F0007C58: d6360000                 sth     %o3, [%i0]
F0007C5C: b0062002                 inc     2, %i0
F0007C60: b406a002                 inc     2, %i2
F0007C64: 108000cb                 ba      loc_F0007F90
F0007C68: b2266002                 dec     2, %i1
F0007C6C: 32800009                 bne,a   loc_F0007C90
F0007C70: 808a8014                 btst    %l4, %o2
F0007C74: 9732a010                 srl     %o2, 16, %o3
F0007C78: d6360000                 sth     %o3, [%i0]
F0007C7C: c02e2002                 clrb    [%i0+2]
F0007C80: b0062003                 inc     3, %i0
F0007C84: b406a001                 inc     %i2
F0007C88: 108000c2                 ba      loc_F0007F90
F0007C8C: b2266001                 dec     %i1
F0007C90: d6064000                 ld      [%i1], %o3
F0007C94: b2066004                 inc     4, %i1
F0007C98: b732e018                 srl     %o3, 24, %i3
F0007C9C: b616c00a                 bset    %o2, %i3
F0007CA0: aa06c010                 add     %i3, %l0, %l5
F0007CA4: aa1d401b                 btog    %i3, %l5
F0007CA8: aa0d4011                 and     %l5, %l1, %l5
F0007CAC: 80a54011                 cmp     %l5, %l1
F0007CB0: 22bfffd8                 be,a    loc_F0007C10
F0007CB4: f6260000                 st      %i3, [%i0]
F0007CB8: 808ec012                 btst    %l2, %i3
F0007CBC: 12800007                 bne     loc_F0007CD8
F0007CC0: 808ec013                 btst    %l3, %i3
F0007CC4: c02e0000                 clrb    [%i0]
F0007CC8: b0062001                 inc     %i0
F0007CCC: b406a003                 inc     3, %i2
F0007CD0: 108000b0                 ba      loc_F0007F90
F0007CD4: b2266003                 dec     3, %i1
F0007CD8: 12800008                 bne     loc_F0007CF8
F0007CDC: 808ec014                 btst    %l4, %i3
F0007CE0: 9736e010                 srl     %i3, 16, %o3
F0007CE4: d6360000                 sth     %o3, [%i0]
F0007CE8: b0062002                 inc     2, %i0
F0007CEC: b406a002                 inc     2, %i2
F0007CF0: 108000a8                 ba      loc_F0007F90
F0007CF4: b2266002                 dec     2, %i1
F0007CF8: 12800009                 bne     loc_F0007D1C
F0007CFC: 808ee0ff                 btst    0xFF, %i3
F0007D00: 9736e010                 srl     %i3, 16, %o3
F0007D04: d6360000                 sth     %o3, [%i0]
F0007D08: c02e2002                 clrb    [%i0+2]
F0007D0C: b0062003                 inc     3, %i0
F0007D10: b406a001                 inc     %i2
F0007D14: 1080009f                 ba      loc_F0007F90
F0007D18: b2266001                 dec     %i1
F0007D1C: f6260000                 st      %i3, [%i0]
F0007D20: 12bfffbd                 bne     loc_F0007C14
F0007D24: b0062004                 inc     4, %i0
F0007D28: 3080009a                 ba,a    loc_F0007F90
F0007D2C: f6064000                 ld      [%i1], %i3
F0007D30: b2066004                 inc     4, %i1
F0007D34: 808ec012                 btst    %l2, %i3
F0007D38: 12800007                 bne     loc_F0007D54
F0007D3C: 808ec013                 btst    %l3, %i3
F0007D40: c02e0000                 clrb    [%i0]
F0007D44: b0062001                 inc     %i0
F0007D48: b426a001                 dec     %i2
F0007D4C: 10800091                 ba      loc_F0007F90
F0007D50: b2266003                 dec     3, %i1
F0007D54: 12800008                 bne     loc_F0007D74
F0007D58: 808ec014                 btst    %l4, %i3
F0007D5C: b936e010                 srl     %i3, 16, %i4
F0007D60: f8360000                 sth     %i4, [%i0]
F0007D64: b0062002                 inc     2, %i0
F0007D68: b426a002                 dec     2, %i2
F0007D6C: 10800089                 ba      loc_F0007F90
F0007D70: b2266002                 dec     2, %i1
F0007D74: 12800009                 bne     loc_F0007D98
F0007D78: 808ee0ff                 btst    0xFF, %i3
F0007D7C: b936e010                 srl     %i3, 16, %i4
F0007D80: f8360000                 sth     %i4, [%i0]
F0007D84: c02e2002                 clrb    [%i0+2]
F0007D88: b0062003                 inc     3, %i0
F0007D8C: b426a003                 dec     3, %i2
F0007D90: 10800080                 ba      loc_F0007F90
F0007D94: b2266003                 dec     3, %i1
F0007D98: 12800007                 bne     loc_F0007DB4
F0007D9C: 9736e010                 srl     %i3, 16, %o3
F0007DA0: d6360000                 sth     %o3, [%i0]
F0007DA4: f6362002                 sth     %i3, [%i0+2]
F0007DA8: b0062004                 inc     4, %i0
F0007DAC: 10800079                 ba      loc_F0007F90
F0007DB0: b426a004                 dec     4, %i2
F0007DB4: d6360000                 sth     %o3, [%i0]
F0007DB8: b0062002                 inc     2, %i0
F0007DBC: b426a002                 dec     2, %i2
F0007DC0: 10800003                 ba      loc_F0007DCC
F0007DC4: 9610001b                 mov     %i3, %o3
F0007DC8: b0062004                 inc     4, %i0
F0007DCC: b4a6a004                 deccc   4, %i2
F0007DD0: 36800005                 bge,a   loc_F0007DE4
F0007DD4: 952ae010                 sll     %o3, 16, %o2
F0007DD8: b2266002                 dec     2, %i1
F0007DDC: 10800064                 ba      loc_F0007F6C
F0007DE0: b406a004                 inc     4, %i2
F0007DE4: 808a8012                 btst    %l2, %o2
F0007DE8: 12800007                 bne     loc_F0007E04
F0007DEC: 808a8013                 btst    %l3, %o2
F0007DF0: c02e0000                 clrb    [%i0]
F0007DF4: b0062001                 inc     %i0
F0007DF8: b406a003                 inc     3, %i2
F0007DFC: 10800065                 ba      loc_F0007F90
F0007E00: b2266003                 dec     3, %i1
F0007E04: 32800008                 bne,a   loc_F0007E24
F0007E08: 808a8013                 btst    %l3, %o2
F0007E0C: b932a010                 srl     %o2, 16, %i4
F0007E10: f8360000                 sth     %i4, [%i0]
F0007E14: b0062002                 inc     2, %i0
F0007E18: b406a002                 inc     2, %i2
F0007E1C: 1080005d                 ba      loc_F0007F90
F0007E20: b2266002                 dec     2, %i1
F0007E24: d6064000                 ld      [%i1], %o3
F0007E28: b2066004                 inc     4, %i1
F0007E2C: b732e010                 srl     %o3, 16, %i3
F0007E30: b616c00a                 bset    %o2, %i3
F0007E34: aa06c010                 add     %i3, %l0, %l5
F0007E38: aa1d401b                 btog    %i3, %l5
F0007E3C: aa0d4011                 and     %l5, %l1, %l5
F0007E40: 80a54011                 cmp     %l5, %l1
F0007E44: 22bfffe1                 be,a    loc_F0007DC8
F0007E48: f6260000                 st      %i3, [%i0]
F0007E4C: 808ec012                 btst    %l2, %i3
F0007E50: 12800007                 bne     loc_F0007E6C
F0007E54: 808ec013                 btst    %l3, %i3
F0007E58: c02e0000                 clrb    [%i0]
F0007E5C: b0062001                 inc     %i0
F0007E60: b406a003                 inc     3, %i2
F0007E64: 1080004b                 ba      loc_F0007F90
F0007E68: b2266003                 dec     3, %i1
F0007E6C: 12800008                 bne     loc_F0007E8C
F0007E70: 808ec014                 btst    %l4, %i3
F0007E74: b936e010                 srl     %i3, 16, %i4
F0007E78: f8360000                 sth     %i4, [%i0]
F0007E7C: b0062002                 inc     2, %i0
F0007E80: b406a002                 inc     2, %i2
F0007E84: 10800043                 ba      loc_F0007F90
F0007E88: b2266002                 dec     2, %i1
F0007E8C: 12800009                 bne     loc_F0007EB0
F0007E90: 808ee0ff                 btst    0xFF, %i3
F0007E94: b936e010                 srl     %i3, 16, %i4
F0007E98: f8360000                 sth     %i4, [%i0]
F0007E9C: c02e2002                 clrb    [%i0+2]
F0007EA0: b0062003                 inc     3, %i0
F0007EA4: b406a001                 inc     %i2
F0007EA8: 1080003a                 ba      loc_F0007F90
F0007EAC: b2266001                 dec     %i1
F0007EB0: f6260000                 st      %i3, [%i0]
F0007EB4: 12bfffc6                 bne     loc_F0007DCC
F0007EB8: b0062004                 inc     4, %i0
F0007EBC: 30800035                 ba,a    loc_F0007F90
F0007EC0: b0062004                 inc     4, %i0
F0007EC4: b4a6a004                 deccc   4, %i2
F0007EC8: 24800029                 ble,a   loc_F0007F6C
F0007ECC: b406a004                 inc     4, %i2
F0007ED0: f6064000                 ld      [%i1], %i3
F0007ED4: b2066004                 inc     4, %i1
F0007ED8: aa06c010                 add     %i3, %l0, %l5
F0007EDC: aa1d401b                 btog    %i3, %l5
F0007EE0: aa0d4011                 and     %l5, %l1, %l5
F0007EE4: 80a54011                 cmp     %l5, %l1
F0007EE8: 22bffff6                 be,a    loc_F0007EC0
F0007EEC: f6260000                 st      %i3, [%i0]
F0007EF0: 808ec012                 btst    %l2, %i3
F0007EF4: 12800007                 bne     loc_F0007F10
F0007EF8: 808ec013                 btst    %l3, %i3
F0007EFC: c02e0000                 clrb    [%i0]
F0007F00: b0062001                 inc     %i0
F0007F04: b406a003                 inc     3, %i2
F0007F08: 10800022                 ba      loc_F0007F90
F0007F0C: b2266003                 dec     3, %i1
F0007F10: 12800008                 bne     loc_F0007F30
F0007F14: 808ec014                 btst    %l4, %i3
F0007F18: b936e010                 srl     %i3, 16, %i4
F0007F1C: f8360000                 sth     %i4, [%i0]
F0007F20: b0062002                 inc     2, %i0
F0007F24: b406a002                 inc     2, %i2
F0007F28: 1080001a                 ba      loc_F0007F90
F0007F2C: b2266002                 dec     2, %i1
F0007F30: 12800009                 bne     loc_F0007F54
F0007F34: 808ee0ff                 btst    0xFF, %i3
F0007F38: b936e010                 srl     %i3, 16, %i4
F0007F3C: f8360000                 sth     %i4, [%i0]
F0007F40: c02e2002                 clrb    [%i0+2]
F0007F44: b0062003                 inc     3, %i0
F0007F48: b406a001                 inc     %i2
F0007F4C: 10800011                 ba      loc_F0007F90
F0007F50: b2266001                 dec     %i1
F0007F54: f6260000                 st      %i3, [%i0]
F0007F58: 12bfffdb                 bne     loc_F0007EC4
F0007F5C: b0062004                 inc     4, %i0
F0007F60: 3080000c                 ba,a    loc_F0007F90
F0007F64: 81c7e008                 ret
F0007F68: 91ef4000                 restore %i5, %g0, %o0
F0007F6C: b4a6a001                 deccc   %i2
F0007F70: 2c80000e                 bneg,a  loc_F0007FA8
F0007F74: 81c7e008                 ret
F0007F78: f60e4000                 ldub    [%i1], %i3
F0007F7C: b2066001                 inc     %i1
F0007F80: f62e0000                 stb     %i3, [%i0]
F0007F84: 8096c000                 tst     %i3
F0007F88: 12bffff9                 bne     loc_F0007F6C
F0007F8C: b0062001                 inc     %i0
F0007F90: b4a6a001                 deccc   %i2
F0007F94: 2c800005                 bneg,a  loc_F0007FA8
F0007F98: 81c7e008                 ret
F0007F9C: c02e0000                 clrb    [%i0]
F0007FA0: 10bffffc                 ba      loc_F0007F90
F0007FA4: b0062001                 inc     %i0
F0007FA8: 91ef4000                 restore %i5, %g0, %o0
