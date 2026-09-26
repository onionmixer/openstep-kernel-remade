F00A9C44: 9de3bf88                 save    %sp, -0x78, %sp
F00A9C48: d0062004                 ld      [%i0+4], %o0
F00A9C4C: 7fff80ea                 call    _fuword
F00A9C50: a6102001                 mov     1, %l3
F00A9C54: a2100008                 mov     %o0, %l1
F00A9C58: 80a47fff                 cmp     %l1, -1
F00A9C5C: 228000a0                 be,a    locret_F00A9EDC
F00A9C60: b0102000                 mov     0, %i0
F00A9C64: 7fffeff5                 call    _flush_user_windows_to_stack
F00A9C68: 01000000                 nop
F00A9C6C: 11307e00                 sethi   -0x3E080000, %o0
F00A9C70: 900c4008                 and     %l1, %o0, %o0
F00A9C74: 13207600                 sethi   -0x7E280000, %o1
F00A9C78: 80a20009                 cmp     %o0, %o1
F00A9C7C: 12800004                 bne     loc_F00A9C8C
F00A9C80: 9134601e                 srl     %l1, 30, %o0
F00A9C84: 10800096                 ba      locret_F00A9EDC
F00A9C88: b0102001                 mov     1, %i0
F00A9C8C: 80a22002                 cmp     %o0, 2
F00A9C90: 32800093                 bne,a   locret_F00A9EDC
F00A9C94: b0102000                 mov     0, %i0
F00A9C98: aa06200c                 add     %i0, 0xC, %l5
F00A9C9C: 90100015                 mov     %l5, %o0
F00A9CA0: 9534600e                 srl     %l1, 14, %o2
F00A9CA4: 940aa01f                 and     %o2, 0x1F, %o2
F00A9CA8: e8062044                 ld      [%i0+0x44], %l4
F00A9CAC: a407bfec                 add     %fp, var_14, %l2
F00A9CB0: 96100012                 mov     %l2, %o3
F00A9CB4: 99346019                 srl     %l1, 25, %o4
F00A9CB8: ac0b201f                 and     %o4, 0x1F, %l6
F00A9CBC: 7ffffe8d                 call    sub_F00A96F0
F00A9CC0: 92100014                 mov     %l4, %o1
F00A9CC4: 80a22000                 cmp     %o0, 0
F00A9CC8: 32800085                 bne,a   locret_F00A9EDC
F00A9CCC: b0103fff                 mov     -1, %i0
F00A9CD0: 9134600d                 srl     %l1, 13, %o0
F00A9CD4: 808a2001                 btst    1, %o0
F00A9CD8: 02800005                 be      loc_F00A9CEC
F00A9CDC: e007bfec                 ld      [%fp+var_14], %l0
F00A9CE0: 932c6013                 sll     %l1, 19, %o1
F00A9CE4: 1080000b                 ba      loc_F00A9D10
F00A9CE8: 953a6013                 sra     %o1, 19, %o2
F00A9CEC: 90100015                 mov     %l5, %o0
F00A9CF0: 92100014                 mov     %l4, %o1
F00A9CF4: 940c601f                 and     %l1, 0x1F, %o2
F00A9CF8: 7ffffe7e                 call    sub_F00A96F0
F00A9CFC: 96100012                 mov     %l2, %o3
F00A9D00: 80a22000                 cmp     %o0, 0
F00A9D04: 32800076                 bne,a   locret_F00A9EDC
F00A9D08: b0103fff                 mov     -1, %i0
F00A9D0C: d407bfec                 ld      [%fp+var_14], %o2
F00A9D10: 91346013                 srl     %l1, 19, %o0
F00A9D14: 900a203f                 and     %o0, 0x3F, %o0
F00A9D18: 92023ff6                 add     %o0, -0xA, %o1
F00A9D1C: 80a26015                 cmp     %o1, 0x15! switch 22 cases
F00A9D20: 1880006e                 bgu     def_F00A9D34! jumptable F00A9D34 default case, cases 2,3,6-15,18,19
F00A9D24: 113c02a7                 sethi   %hi(jpt_F00A9D34), %o0
F00A9D28: 9012213c                 bset    %lo(jpt_F00A9D34), %o0
F00A9D2C: 932a6002                 sll     %o1, 2, %o1
F00A9D30: d0024008                 ld      [%o1+%o0], %o0
F00A9D34: 81c20000                 jmp     %o0! switch jump
F00A9D38: 01000000                 nop
F00A9D94: 90100010                 mov     %l0, %o0! jumptable F00A9D34 case 0
F00A9D98: 9210000a                 mov     %o2, %o1
F00A9D9C: 9407bff0                 add     %fp, var_10, %o2
F00A9DA0: 9606200c                 add     %i0, 0xC, %o3
F00A9DA4: 7ffd7387                 call    __ip_umul
F00A9DA8: 98100018                 mov     %i0, %o4
F00A9DAC: 1080003a                 ba      loc_F00A9E94
F00A9DB0: 80a22001                 cmp     %o0, 1
F00A9DB4: 90100010                 mov     %l0, %o0! jumptable F00A9D34 case 1
F00A9DB8: 9210000a                 mov     %o2, %o1
F00A9DBC: 9407bff0                 add     %fp, var_10, %o2
F00A9DC0: 9606200c                 add     %i0, 0xC, %o3
F00A9DC4: 7ffd7388                 call    __ip_mul
F00A9DC8: 98100018                 mov     %i0, %o4
F00A9DCC: 10800032                 ba      loc_F00A9E94
F00A9DD0: 80a22001                 cmp     %o0, 1
F00A9DD4: 90100010                 mov     %l0, %o0! jumptable F00A9D34 case 4
F00A9DD8: 9210000a                 mov     %o2, %o1
F00A9DDC: 9407bff0                 add     %fp, var_10, %o2
F00A9DE0: 9606200c                 add     %i0, 0xC, %o3
F00A9DE4: 7ffd73b0                 call    __ip_udiv
F00A9DE8: 98100018                 mov     %i0, %o4
F00A9DEC: 10800029                 ba      loc_F00A9E90
F00A9DF0: a6102000                 mov     0, %l3
F00A9DF4: 90100010                 mov     %l0, %o0! jumptable F00A9D34 case 5
F00A9DF8: 9210000a                 mov     %o2, %o1
F00A9DFC: 9407bff0                 add     %fp, var_10, %o2
F00A9E00: 9606200c                 add     %i0, 0xC, %o3
F00A9E04: 7ffd73b7                 call    __ip_div
F00A9E08: 98100018                 mov     %i0, %o4
F00A9E0C: 10800021                 ba      loc_F00A9E90
F00A9E10: a6102000                 mov     0, %l3
F00A9E14: 90100010                 mov     %l0, %o0! jumptable F00A9D34 case 16
F00A9E18: 9210000a                 mov     %o2, %o1
F00A9E1C: 9407bff0                 add     %fp, var_10, %o2
F00A9E20: 9606200c                 add     %i0, 0xC, %o3
F00A9E24: 7ffd7379                 call    __ip_umulcc
F00A9E28: 98100018                 mov     %i0, %o4
F00A9E2C: 1080001a                 ba      loc_F00A9E94
F00A9E30: 80a22001                 cmp     %o0, 1
F00A9E34: 90100010                 mov     %l0, %o0! jumptable F00A9D34 case 17
F00A9E38: 9210000a                 mov     %o2, %o1
F00A9E3C: 9407bff0                 add     %fp, var_10, %o2
F00A9E40: 9606200c                 add     %i0, 0xC, %o3
F00A9E44: 7ffd7381                 call    __ip_mulcc
F00A9E48: 98100018                 mov     %i0, %o4
F00A9E4C: 10800012                 ba      loc_F00A9E94
F00A9E50: 80a22001                 cmp     %o0, 1
F00A9E54: 90100010                 mov     %l0, %o0! jumptable F00A9D34 case 20
F00A9E58: 9210000a                 mov     %o2, %o1
F00A9E5C: 9407bff0                 add     %fp, var_10, %o2
F00A9E60: 9606200c                 add     %i0, 0xC, %o3
F00A9E64: 7ffd73c6                 call    __ip_udivcc
F00A9E68: 98100018                 mov     %i0, %o4
F00A9E6C: 10800009                 ba      loc_F00A9E90
F00A9E70: a6102000                 mov     0, %l3
F00A9E74: 90100010                 mov     %l0, %o0! jumptable F00A9D34 case 21
F00A9E78: 9210000a                 mov     %o2, %o1
F00A9E7C: 9407bff0                 add     %fp, var_10, %o2
F00A9E80: 9606200c                 add     %i0, 0xC, %o3
F00A9E84: 7ffd73d4                 call    __ip_divcc
F00A9E88: 98100018                 mov     %i0, %o4
F00A9E8C: a6102000                 mov     0, %l3
F00A9E90: 80a22001                 cmp     %o0, 1
F00A9E94: 22800004                 be,a    loc_F00A9EA4
F00A9E98: d007bff0                 ld      [%fp+var_10], %o0
F00A9E9C: 10800010                 ba      locret_F00A9EDC
F00A9EA0: b0100008                 mov     %o0, %i0
F00A9EA4: 92100015                 mov     %l5, %o1
F00A9EA8: 94100014                 mov     %l4, %o2
F00A9EAC: 7ffffe2c                 call    sub_F00A975C
F00A9EB0: 96100016                 mov     %l6, %o3
F00A9EB4: 80a22000                 cmp     %o0, 0
F00A9EB8: 02800004                 be      loc_F00A9EC8
F00A9EBC: 80a4e000                 cmp     %l3, 0
F00A9EC0: 10800007                 ba      locret_F00A9EDC
F00A9EC4: b0103fff                 mov     -1, %i0
F00A9EC8: 02bfff6f                 be      loc_F00A9C84
F00A9ECC: d007bff4                 ld      [%fp+var_C], %o0
F00A9ED0: 10bfff6d                 ba      loc_F00A9C84
F00A9ED4: d026200c                 st      %o0, [%i0+0xC]
F00A9ED8: b0102000                 mov     0, %i0! jumptable F00A9D34 default case, cases 2,3,6-15,18,19
F00A9EDC: 81c7e008                 ret
F00A9EE0: 81e80000                 restore
