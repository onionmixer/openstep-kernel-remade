F001D690: 9de3bf98                 save    %sp, -0x68, %sp
F001D694: 113c0447                 sethi   %hi(_page_size), %o0
F001D698: d202213c                 ld      [%o0+%lo(_page_size)], %o1
F001D69C: 80a26fff                 cmp     %o1, 0xFFF
F001D6A0: 18800005                 bgu     loc_F001D6B4
F001D6A4: a0102001                 mov     1, %l0
F001D6A8: 7fffa3d6                 call    _udiv
F001D6AC: 11000004                 sethi   0x1000, %o0
F001D6B0: a0100008                 mov     %o0, %l0
F001D6B4: 4001e541                 call    _spltty
F001D6B8: 01000000                 nop
F001D6BC: a2100008                 mov     %o0, %l1
F001D6C0: 912c2002                 sll     %l0, 2, %o0
F001D6C4: 90020010                 add     %o0, %l0, %o0
F001D6C8: a12a2001                 sll     %o0, 1, %l0
F001D6CC: 90100010                 mov     %l0, %o0
F001D6D0: 92102000                 mov     0, %o1
F001D6D4: 40000013                 call    _m_clalloc
F001D6D8: 94102000                 mov     0, %o2
F001D6DC: 80a22000                 cmp     %o0, 0
F001D6E0: 0280000b                 be      loc_F001D70C
F001D6E4: 92102001                 mov     1, %o1
F001D6E8: 90100010                 mov     %l0, %o0
F001D6EC: 4000000d                 call    _m_clalloc
F001D6F0: 94102000                 mov     0, %o2
F001D6F4: 80a22000                 cmp     %o0, 0
F001D6F8: 02800006                 be      loc_F001D710
F001D6FC: 113c042e                 sethi   -0xFEF4800, %o0
F001D700: 4001e589                 call    _splx
F001D704: 90100011                 mov     %l1, %o0
F001D708: 30800004                 ba,a    locret_F001D718
F001D70C: 113c042e                 sethi   -0xFEF4800, %o0! char *
F001D710: 7fffde98                 call    _panic
F001D714: 901222b0                 bset    0x2B0, %o0
F001D718: 81c7e008                 ret
F001D71C: 81e80000                 restore
