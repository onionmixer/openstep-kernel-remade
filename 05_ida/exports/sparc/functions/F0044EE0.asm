F0044EE0: 9de3bf98                 save    %sp, -0x68, %sp
F0044EE4: e0062030                 ld      [%i0+0x30], %l0
F0044EE8: d0042008                 ld      [%l0+8], %o0
F0044EEC: 80a22000                 cmp     %o0, 0
F0044EF0: 22800005                 be,a    loc_F0044F04
F0044EF4: 90100010                 mov     %l0, %o0
F0044EF8: 7fff635b                 call    _m_freem
F0044EFC: 01000000                 nop
F0044F00: 90100010                 mov     %l0, %o0
F0044F04: 40008ca7                 call    _kfree
F0044F08: 921021cc                 mov     0x1CC, %o1
F0044F0C: d006202c                 ld      [%i0+0x2C], %o0
F0044F10: 13000008                 sethi   0x2000, %o1
F0044F14: 40008ca3                 call    _kfree
F0044F18: 92126260                 bset    0x260, %o1
F0044F1C: 90100018                 mov     %i0, %o0
F0044F20: 40008ca0                 call    _kfree
F0044F24: 92102034                 mov     0x34, %o1 ! '4'
F0044F28: 81c7e008                 ret
F0044F2C: 81e80000                 restore
