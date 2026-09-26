F0095E04: 8a0a200f                 and     %o0, 0xF, %g5
F0095E08: 90220005                 sub     %o0, %g5, %o0
F0095E0C: 92024005                 add     %o1, %g5, %o1
F0095E10: 92a26010                 deccc   0x10, %o1
F0095E14: c0a20200                 sta     %g0, [%o0]#ASI_AS_IF_USER_PRIMARY
F0095E18: 1abffffe                 bcc     loc_F0095E10
F0095E1C: 90022010                 inc     0x10, %o0
F0095E20: 81c3e008                 retl
F0095E24: 01000000                 nop
