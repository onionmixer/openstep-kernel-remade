F0067974: 9de3bf98                 save    %sp, -0x68, %sp
F0067978: 80a62000                 cmp     %i0, 0
F006797C: 0280001d                 be      locret_F00679F0
F0067980: a0102000                 mov     0, %l0
F0067984: 80a63fff                 cmp     %i0, -1
F0067988: 0280001a                 be      locret_F00679F0
F006798C: 01000000                 nop
F0067990: d0060000                 ld      [%i0], %o0
F0067994: 80a22000                 cmp     %o0, 0
F0067998: 12bffffe                 bne     loc_F0067990
F006799C: 01000000                 nop
F00679A0: 4000bd42                 call    _simple_lock_try
F00679A4: 90100018                 mov     %i0, %o0
F00679A8: 80a22000                 cmp     %o0, 0
F00679AC: 02bffff9                 be      loc_F0067990
F00679B0: 01000000                 nop
F00679B4: d2062008                 ld      [%i0+8], %o1
F00679B8: 80a26000                 cmp     %o1, 0
F00679BC: 1680000c                 bge     loc_F00679EC
F00679C0: 01000000                 nop
F00679C4: 1100003f901223ff         set     0xFFFF, %o0
F00679CC: 900a4008                 and     %o1, %o0, %o0
F00679D0: 80a22002                 cmp     %o0, 2
F00679D4: 12800006                 bne     loc_F00679EC
F00679D8: 01000000                 nop
F00679DC: d0062014                 ld      [%i0+0x14], %o0
F00679E0: e0022088                 ld      [%o0+0x88], %l0
F00679E4: 7fffd909                 call    _ipc_space_reference
F00679E8: 90100010                 mov     %l0, %o0
F00679EC: c0260000                 clr     [%i0]
F00679F0: 81c7e008                 ret
F00679F4: 91e80010                 restore %g0, %l0, %o0
