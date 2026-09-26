F00E59F8: 9de3bf98                 save    %sp, -0x68, %sp
F00E59FC: 94103d39                 mov     -0x2C7, %o2
F00E5A00: 80a6200f                 cmp     %i0, 0xF
F00E5A04: 133c04bb                 sethi   %hi(_sparcfbs), %o1
F00E5A08: e2166006                 lduh    [%i1+6], %l1
F00E5A0C: 912e2004                 sll     %i0, 4, %o0
F00E5A10: e4164000                 lduh    [%i1], %l2
F00E5A14: 90020018                 add     %o0, %i0, %o0
F00E5A18: e0166002                 lduh    [%i1+2], %l0
F00E5A1C: 912a2002                 sll     %o0, 2, %o0
F00E5A20: d2026364                 ld      [%o1+%lo(_sparcfbs)], %o1
F00E5A24: 90022008                 inc     8, %o0
F00E5A28: f2166004                 lduh    [%i1+4], %i1
F00E5A2C: 18800006                 bgu     loc_F00E5A44
F00E5A30: b0024008                 add     %o1, %o0, %i0
F00E5A34: d0024008                 ld      [%o1+%o0], %o0
F00E5A38: 80a22000                 cmp     %o0, 0
F00E5A3C: 12800004                 bne     loc_F00E5A4C
F00E5A40: 9206bfff                 add     %i2, -1, %o1
F00E5A44: 108000cc                 ba      locret_F00E5D74
F00E5A48: b0103d40                 mov     -0x2C0, %i0
F00E5A4C: 80a26017                 cmp     %o1, 0x17! switch 24 cases
F00E5A50: 188000c8                 bgu     def_F00E5A64! jumptable F00E5A64 default case, cases 2-6,8-10,12-22
F00E5A54: 113c0396                 sethi   %hi(jpt_F00E5A64), %o0
F00E5A58: 9012226c                 bset    %lo(jpt_F00E5A64), %o0
F00E5A5C: 932a6002                 sll     %o1, 2, %o1
F00E5A60: d0024008                 ld      [%o1+%o0], %o0
F00E5A64: 81c20000                 jmp     %o0! switch jump
F00E5A68: 01000000                 nop
F00E5ACC: d0062038                 ld      [%i0+0x38], %o0! jumptable F00E5A64 case 0
F00E5AD0: d2062034                 ld      [%i0+0x34], %o1! int
F00E5AD4: 7ffc82cd                 call    _div
F00E5AD8: 01000000                 nop
F00E5ADC: d2062030                 ld      [%i0+0x30], %o1
F00E5AE0: 80a26018                 cmp     %o1, 0x18
F00E5AE4: 12800029                 bne     loc_F00E5B88
F00E5AE8: b4220019                 sub     %o0, %i1, %i2
F00E5AEC: d2062038                 ld      [%i0+0x38], %o1
F00E5AF0: 7ffc8284                 call    _umul
F00E5AF4: 90100010                 mov     %l0, %o0
F00E5AF8: 94100008                 mov     %o0, %o2
F00E5AFC: e0062018                 ld      [%i0+0x18], %l0
F00E5B00: 90100012                 mov     %l2, %o0
F00E5B04: d2062034                 ld      [%i0+0x34], %o1
F00E5B08: 7ffc827e                 call    _umul
F00E5B0C: a004000a                 add     %l0, %o2, %l0
F00E5B10: a0040008                 add     %l0, %o0, %l0
F00E5B14: 94102000                 mov     0, %o2
F00E5B18: a2847fff                 inccc   -1, %l1
F00E5B1C: 0c800095                 bneg    def_F00E5A64! jumptable F00E5A64 default case, cases 2-6,8-10,12-22
F00E5B20: 96102000                 mov     0, %o3
F00E5B24: 113c03e898122060         set     unk_F00FA060, %o4
F00E5B2C: 9b2ea002                 sll     %i2, 2, %o5
F00E5B30: 92867fff                 addcc   %i1, -1, %o1
F00E5B34: 2c800011                 bneg,a  loc_F00E5B78
F00E5B38: a2847fff                 inccc   -1, %l1
F00E5B3C: 9482bfff                 inccc   -1, %o2
F00E5B40: 1c800006                 bpos    loc_F00E5B58
F00E5B44: 913ac00a                 sra     %o3, %o2, %o0
F00E5B48: d60ec000                 ldub    [%i3], %o3
F00E5B4C: 94102007                 mov     7, %o2
F00E5B50: b606e001                 inc     %i3
F00E5B54: 913ac00a                 sra     %o3, %o2, %o0
F00E5B58: 900a2001                 and     %o0, 1, %o0
F00E5B5C: 912a2002                 sll     %o0, 2, %o0
F00E5B60: d002000c                 ld      [%o0+%o4], %o0
F00E5B64: 92827fff                 inccc   -1, %o1
F00E5B68: d0240000                 st      %o0, [%l0]
F00E5B6C: 1cbffff4                 bpos    loc_F00E5B3C
F00E5B70: a0042004                 inc     4, %l0
F00E5B74: a2847fff                 inccc   -1, %l1
F00E5B78: 1cbfffee                 bpos    loc_F00E5B30
F00E5B7C: a004000d                 add     %l0, %o5, %l0
F00E5B80: 1080007c                 ba      def_F00E5A64! jumptable F00E5A64 default case, cases 2-6,8-10,12-22
F00E5B84: 94102000                 mov     0, %o2
F00E5B88: d2062038                 ld      [%i0+0x38], %o1
F00E5B8C: 7ffc825d                 call    _umul
F00E5B90: 90100010                 mov     %l0, %o0
F00E5B94: 94100008                 mov     %o0, %o2
F00E5B98: e0062014                 ld      [%i0+0x14], %l0
F00E5B9C: 90100012                 mov     %l2, %o0
F00E5BA0: d2062034                 ld      [%i0+0x34], %o1
F00E5BA4: 7ffc8257                 call    _umul
F00E5BA8: a004000a                 add     %l0, %o2, %l0
F00E5BAC: a0040008                 add     %l0, %o0, %l0
F00E5BB0: 94102000                 mov     0, %o2
F00E5BB4: a2847fff                 inccc   -1, %l1
F00E5BB8: 0c80006e                 bneg    def_F00E5A64! jumptable F00E5A64 default case, cases 2-6,8-10,12-22
F00E5BBC: 96102000                 mov     0, %o3
F00E5BC0: 113c03e898122068         set     unk_F00FA068, %o4
F00E5BC8: 92867fff                 addcc   %i1, -1, %o1
F00E5BCC: 2c800010                 bneg,a  loc_F00E5C0C
F00E5BD0: a2847fff                 inccc   -1, %l1
F00E5BD4: 9482bfff                 inccc   -1, %o2
F00E5BD8: 1c800006                 bpos    loc_F00E5BF0
F00E5BDC: 913ac00a                 sra     %o3, %o2, %o0
F00E5BE0: d60ec000                 ldub    [%i3], %o3
F00E5BE4: 94102007                 mov     7, %o2
F00E5BE8: b606e001                 inc     %i3
F00E5BEC: 913ac00a                 sra     %o3, %o2, %o0
F00E5BF0: 900a2001                 and     %o0, 1, %o0
F00E5BF4: d00a000c                 ldub    [%o0+%o4], %o0
F00E5BF8: 92827fff                 inccc   -1, %o1
F00E5BFC: d02c0000                 stb     %o0, [%l0]
F00E5C00: 1cbffff5                 bpos    loc_F00E5BD4
F00E5C04: a0042001                 inc     %l0
F00E5C08: a2847fff                 inccc   -1, %l1
F00E5C0C: 1cbfffef                 bpos    loc_F00E5BC8
F00E5C10: a004001a                 add     %l0, %i2, %l0
F00E5C14: 10800057                 ba      def_F00E5A64! jumptable F00E5A64 default case, cases 2-6,8-10,12-22
F00E5C18: 94102000                 mov     0, %o2
F00E5C1C: d0062038                 ld      [%i0+0x38], %o0! jumptable F00E5A64 case 1
F00E5C20: d2062034                 ld      [%i0+0x34], %o1! int
F00E5C24: 7ffc8279                 call    _div
F00E5C28: 01000000                 nop
F00E5C2C: d2062030                 ld      [%i0+0x30], %o1
F00E5C30: 80a26018                 cmp     %o1, 0x18
F00E5C34: 12800029                 bne     loc_F00E5CD8
F00E5C38: b4220019                 sub     %o0, %i1, %i2
F00E5C3C: d2062038                 ld      [%i0+0x38], %o1
F00E5C40: 7ffc8230                 call    _umul
F00E5C44: 90100010                 mov     %l0, %o0
F00E5C48: 94100008                 mov     %o0, %o2
F00E5C4C: e0062018                 ld      [%i0+0x18], %l0
F00E5C50: 90100012                 mov     %l2, %o0
F00E5C54: d2062034                 ld      [%i0+0x34], %o1
F00E5C58: 7ffc822a                 call    _umul
F00E5C5C: a004000a                 add     %l0, %o2, %l0
F00E5C60: a0040008                 add     %l0, %o0, %l0
F00E5C64: 94102000                 mov     0, %o2
F00E5C68: a2847fff                 inccc   -1, %l1
F00E5C6C: 0c800041                 bneg    def_F00E5A64! jumptable F00E5A64 default case, cases 2-6,8-10,12-22
F00E5C70: 96102000                 mov     0, %o3
F00E5C74: 113c03e89812206c         set     unk_F00FA06C, %o4
F00E5C7C: 9b2ea002                 sll     %i2, 2, %o5
F00E5C80: 92867fff                 addcc   %i1, -1, %o1
F00E5C84: 2c800011                 bneg,a  loc_F00E5CC8
F00E5C88: a2847fff                 inccc   -1, %l1
F00E5C8C: 9482bffe                 inccc   -2, %o2
F00E5C90: 1c800006                 bpos    loc_F00E5CA8
F00E5C94: 913ac00a                 sra     %o3, %o2, %o0
F00E5C98: d60ec000                 ldub    [%i3], %o3
F00E5C9C: 94102006                 mov     6, %o2
F00E5CA0: b606e001                 inc     %i3
F00E5CA4: 913ac00a                 sra     %o3, %o2, %o0
F00E5CA8: 900a2003                 and     %o0, 3, %o0
F00E5CAC: 912a2002                 sll     %o0, 2, %o0
F00E5CB0: d002000c                 ld      [%o0+%o4], %o0
F00E5CB4: 92827fff                 inccc   -1, %o1
F00E5CB8: d0240000                 st      %o0, [%l0]
F00E5CBC: 1cbffff4                 bpos    loc_F00E5C8C
F00E5CC0: a0042004                 inc     4, %l0
F00E5CC4: a2847fff                 inccc   -1, %l1
F00E5CC8: 1cbfffee                 bpos    loc_F00E5C80
F00E5CCC: a004000d                 add     %l0, %o5, %l0
F00E5CD0: 10800028                 ba      def_F00E5A64! jumptable F00E5A64 default case, cases 2-6,8-10,12-22
F00E5CD4: 94102000                 mov     0, %o2
F00E5CD8: d2062038                 ld      [%i0+0x38], %o1
F00E5CDC: 7ffc8209                 call    _umul
F00E5CE0: 90100010                 mov     %l0, %o0
F00E5CE4: 94100008                 mov     %o0, %o2
F00E5CE8: e0062014                 ld      [%i0+0x14], %l0
F00E5CEC: 90100012                 mov     %l2, %o0
F00E5CF0: d2062034                 ld      [%i0+0x34], %o1
F00E5CF4: 7ffc8203                 call    _umul
F00E5CF8: a004000a                 add     %l0, %o2, %l0
F00E5CFC: a0040008                 add     %l0, %o0, %l0
F00E5D00: 94102000                 mov     0, %o2
F00E5D04: a2847fff                 inccc   -1, %l1
F00E5D08: 0c80001a                 bneg    def_F00E5A64! jumptable F00E5A64 default case, cases 2-6,8-10,12-22
F00E5D0C: 96102000                 mov     0, %o3
F00E5D10: 113c03e898122080         set     unk_F00FA080, %o4
F00E5D18: 92867fff                 addcc   %i1, -1, %o1
F00E5D1C: 2c800010                 bneg,a  loc_F00E5D5C
F00E5D20: a2847fff                 inccc   -1, %l1
F00E5D24: 9482bffe                 inccc   -2, %o2
F00E5D28: 1c800006                 bpos    loc_F00E5D40
F00E5D2C: 913ac00a                 sra     %o3, %o2, %o0
F00E5D30: d60ec000                 ldub    [%i3], %o3
F00E5D34: 94102006                 mov     6, %o2
F00E5D38: b606e001                 inc     %i3
F00E5D3C: 913ac00a                 sra     %o3, %o2, %o0
F00E5D40: 900a2003                 and     %o0, 3, %o0
F00E5D44: d00a000c                 ldub    [%o0+%o4], %o0
F00E5D48: 92827fff                 inccc   -1, %o1
F00E5D4C: d02c0000                 stb     %o0, [%l0]
F00E5D50: 1cbffff5                 bpos    loc_F00E5D24
F00E5D54: a0042001                 inc     %l0
F00E5D58: a2847fff                 inccc   -1, %l1
F00E5D5C: 1cbfffef                 bpos    loc_F00E5D18
F00E5D60: a004001a                 add     %l0, %i2, %l0
F00E5D64: 10800003                 ba      def_F00E5A64! jumptable F00E5A64 default case, cases 2-6,8-10,12-22
F00E5D68: 94102000                 mov     0, %o2
F00E5D6C: 94103d39                 mov     -0x2C7, %o2! jumptable F00E5A64 cases 7,11,23
F00E5D70: b010000a                 mov     %o2, %i0! jumptable F00E5A64 default case, cases 2-6,8-10,12-22
F00E5D74: 81c7e008                 ret
F00E5D78: 81e80000                 restore
