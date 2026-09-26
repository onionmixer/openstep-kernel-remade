F00ACB40: 9de3bf98                 save    %sp, -0x68, %sp
F00ACB44: c406a080                 ld      [%i2+0x80], %g2
F00ACB48: f0060000                 ld      [%i0], %i0
F00ACB4C: b530a00a                 srl     %g2, 10, %i2
F00ACB50: b40ea003                 and     %i2, 3, %i2
F00ACB54: 85362019                 srl     %i0, 25, %g2
F00ACB58: b608a00f                 and     %g2, 0xF, %i3
F00ACB5C: 80a6e00f                 cmp     %i3, 0xF! switch 16 cases
F00ACB60: 18800053                 bgu     def_F00ACB78! jumptable F00ACB78 default case
F00ACB64: b808a010                 and     %g2, 0x10, %i4
F00ACB68: 053c02b28410a380         set     jpt_F00ACB78, %g2
F00ACB70: 872ee002                 sll     %i3, 2, %g3
F00ACB74: c400c002                 ld      [%g3+%g2], %g2
F00ACB78: 81c08000                 jmp     %g2! switch jump
F00ACB7C: 01000000                 nop
F00ACBC0: 1080003b                 ba      def_F00ACB78! jumptable F00ACB78 case 0
F00ACBC4: 86102000                 mov     0, %g3
F00ACBC8: 10800005                 ba      loc_F00ACBDC! jumptable F00ACB78 case 4
F00ACBCC: 841ea001                 xor     %i2, 1, %g2
F00ACBD0: 10800003                 ba      loc_F00ACBDC! jumptable F00ACB78 case 6
F00ACBD4: 841ea002                 xor     %i2, 2, %g2
F00ACBD8: 841ea003                 xor     %i2, 3, %g2! jumptable F00ACB78 case 7
F00ACBDC: 80a00002                 cmp     %g0, %g2
F00ACBE0: 10800033                 ba      def_F00ACB78! jumptable F00ACB78 default case
F00ACBE4: 86603fff                 subc    %g0, -1, %g3
F00ACBE8: 80a0001a                 cmp     %g0, %i2! jumptable F00ACB78 case 9
F00ACBEC: 10800030                 ba      def_F00ACB78! jumptable F00ACB78 default case
F00ACBF0: 86603fff                 subc    %g0, -1, %g3
F00ACBF4: 1080000b                 ba      loc_F00ACC20! jumptable F00ACB78 case 2
F00ACBF8: 8606bfff                 add     %i2, -1, %g3
F00ACBFC: 80a6a003                 cmp     %i2, 3! jumptable F00ACB78 case 3
F00ACC00: 0280002a                 be      loc_F00ACCA8! jumptable F00ACB78 case 8
F00ACC04: 86102000                 mov     0, %g3
F00ACC08: 80a6a001                 cmp     %i2, 1
F00ACC0C: 12800029                 bne     loc_F00ACCB0
F00ACC10: 80a0e000                 cmp     %g3, 0
F00ACC14: 10800026                 ba      def_F00ACB78! jumptable F00ACB78 default case
F00ACC18: 86102001                 mov     1, %g3
F00ACC1C: 8606bffe                 add     %i2, -2, %g3! jumptable F00ACB78 case 5
F00ACC20: 80a0e001                 cmp     %g3, 1
F00ACC24: 28800003                 bleu,a  loc_F00ACC30
F00ACC28: 86102001                 mov     1, %g3
F00ACC2C: 86102000                 mov     0, %g3
F00ACC30: 10800020                 ba      loc_F00ACCB0
F00ACC34: 80a0e000                 cmp     %g3, 0
F00ACC38: 86102000                 mov     0, %g3! jumptable F00ACB78 case 10
F00ACC3C: 10800004                 ba      loc_F00ACC4C
F00ACC40: 80a6a003                 cmp     %i2, 3
F00ACC44: 86102000                 mov     0, %g3! jumptable F00ACB78 case 11
F00ACC48: 80a6a002                 cmp     %i2, 2
F00ACC4C: 02800017                 be      loc_F00ACCA8! jumptable F00ACB78 case 8
F00ACC50: 80a6a000                 cmp     %i2, 0
F00ACC54: 12800017                 bne     loc_F00ACCB0
F00ACC58: 80a0e000                 cmp     %g3, 0
F00ACC5C: 10800014                 ba      def_F00ACB78! jumptable F00ACB78 default case
F00ACC60: 86102001                 mov     1, %g3
F00ACC64: 80a6a001                 cmp     %i2, 1! jumptable F00ACB78 case 13
F00ACC68: 28800003                 bleu,a  loc_F00ACC74
F00ACC6C: 86102001                 mov     1, %g3
F00ACC70: 86102000                 mov     0, %g3
F00ACC74: 1080000f                 ba      loc_F00ACCB0
F00ACC78: 80a0e000                 cmp     %g3, 0
F00ACC7C: 80a0001a                 cmp     %g0, %i2! jumptable F00ACB78 case 1
F00ACC80: 1080000b                 ba      def_F00ACB78! jumptable F00ACB78 default case
F00ACC84: 86402000                 addc    %g0, 0, %g3
F00ACC88: 10800005                 ba      loc_F00ACC9C! jumptable F00ACB78 case 12
F00ACC8C: 841ea001                 xor     %i2, 1, %g2
F00ACC90: 10800003                 ba      loc_F00ACC9C! jumptable F00ACB78 case 14
F00ACC94: 841ea002                 xor     %i2, 2, %g2
F00ACC98: 841ea003                 xor     %i2, 3, %g2! jumptable F00ACB78 case 15
F00ACC9C: 80a00002                 cmp     %g0, %g2
F00ACCA0: 10800003                 ba      def_F00ACB78! jumptable F00ACB78 default case
F00ACCA4: 86402000                 addc    %g0, 0, %g3
F00ACCA8: 86102001                 mov     1, %g3! jumptable F00ACB78 case 8
F00ACCAC: 80a0e000                 cmp     %g3, 0! jumptable F00ACB78 default case
F00ACCB0: 02800012                 be      loc_F00ACCF8
F00ACCB4: 80a72000                 cmp     %i4, 0
F00ACCB8: 0280000a                 be      loc_F00ACCE0
F00ACCBC: c6066004                 ld      [%i1+4], %g3
F00ACCC0: 80a6e008                 cmp     %i3, 8
F00ACCC4: 32800008                 bne,a   loc_F00ACCE4
F00ACCC8: c4066008                 ld      [%i1+8], %g2
F00ACCCC: 852e200a                 sll     %i0, 10, %g2
F00ACCD0: 8538a008                 sra     %g2, 8, %g2
F00ACCD4: 8400c002                 add     %g3, %g2, %g2
F00ACCD8: 10800012                 ba      loc_F00ACD20
F00ACCDC: c4266004                 st      %g2, [%i1+4]
F00ACCE0: c4066008                 ld      [%i1+8], %g2
F00ACCE4: c4266004                 st      %g2, [%i1+4]
F00ACCE8: 852e200a                 sll     %i0, 10, %g2
F00ACCEC: 8538a008                 sra     %g2, 8, %g2
F00ACCF0: 1080000d                 ba      loc_F00ACD24
F00ACCF4: 8400c002                 add     %g3, %g2, %g2
F00ACCF8: 02800008                 be      loc_F00ACD18
F00ACCFC: c6066008                 ld      [%i1+8], %g3
F00ACD00: c4066008                 ld      [%i1+8], %g2
F00ACD04: 8400a004                 inc     4, %g2
F00ACD08: c4266004                 st      %g2, [%i1+4]
F00ACD0C: 8600e008                 inc     8, %g3
F00ACD10: 10800006                 ba      locret_F00ACD28
F00ACD14: c6266008                 st      %g3, [%i1+8]
F00ACD18: c4066008                 ld      [%i1+8], %g2
F00ACD1C: c6266004                 st      %g3, [%i1+4]
F00ACD20: 8400a004                 inc     4, %g2
F00ACD24: c4266008                 st      %g2, [%i1+8]
F00ACD28: 81c7e008                 ret
F00ACD2C: 91e82000                 restore %g0, 0, %o0
