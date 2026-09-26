F0032F14: 9de3bf98                 save    %sp, -0x68, %sp
F0032F18: d00e0000                 ldub    [%i0], %o0
F0032F1C: a40e3f80                 and     %i0, -0x80, %l2
F0032F20: a0062014                 add     %i0, 0x14, %l0
F0032F24: 80a66000                 cmp     %i1, 0
F0032F28: 900a200f                 and     %o0, 0xF, %o0
F0032F2C: 912a2002                 sll     %o0, 2, %o0
F0032F30: 02800009                 be      loc_F0032F54
F0032F34: a2023fec                 add     %o0, -0x14, %l1
F0032F38: e2366008                 sth     %l1, [%i1+8]
F0032F3C: 9010200c                 mov     0xC, %o0
F0032F40: d0266004                 st      %o0, [%i1+4]
F0032F44: 90100010                 mov     %l0, %o0! void *
F0032F48: 9206600c                 add     %i1, 0xC, %o1! void *
F0032F4C: 400186f1                 call    _bcopy
F0032F50: 94100011                 mov     %l1, %o2
F0032F54: 90040011                 add     %l0, %l1, %o0! void *
F0032F58: d414a008                 lduh    [%l2+8], %o2
F0032F5C: 92100010                 mov     %l0, %o1! void *
F0032F60: 952aa010                 sll     %o2, 16, %o2
F0032F64: 953aa010                 sra     %o2, 16, %o2
F0032F68: 9402bfec                 inc     -0x14, %o2! size_t
F0032F6C: 400186e9                 call    _bcopy
F0032F70: 94228011                 sub     %o2, %l1, %o2
F0032F74: d014a008                 lduh    [%l2+8], %o0
F0032F78: 90220011                 sub     %o0, %l1, %o0
F0032F7C: d034a008                 sth     %o0, [%l2+8]
F0032F80: d2060000                 ld      [%i0], %o1
F0032F84: 1103c000                 sethi   0xF000000, %o0
F0032F88: 902a4008                 andn    %o1, %o0, %o0
F0032F8C: 13014000                 sethi   0x5000000, %o1
F0032F90: 90120009                 bset    %o1, %o0
F0032F94: d0260000                 st      %o0, [%i0]
F0032F98: 81c7e008                 ret
F0032F9C: 81e80000                 restore
