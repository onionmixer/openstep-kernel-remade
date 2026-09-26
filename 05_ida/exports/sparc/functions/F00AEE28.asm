F00AEE28: 9de3bf98                 save    %sp, -0x68, %sp
F00AEE2C: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AEE30: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AEE34: 80a22000                 cmp     %o0, 0
F00AEE38: 02800005                 be      loc_F00AEE4C
F00AEE3C: 113c000c                 sethi   %hi(_romp), %o0
F00AEE40: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AEE44: 10800004                 ba      loc_F00AEE54
F00AEE48: d20220b0                 ld      [%o0+0xB0], %o1
F00AEE4C: d0022030                 ld      [%o0+0x30], %o0
F00AEE50: d2022028                 ld      [%o0+0x28], %o1
F00AEE54: 9fc24000                 call    %o1
F00AEE58: 90100018                 mov     %i0, %o0
F00AEE5C: 81c7e008                 ret
F00AEE60: 91e80008                 restore %g0, %o0, %o0
