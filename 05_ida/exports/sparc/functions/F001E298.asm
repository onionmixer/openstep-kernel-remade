F001E298: 9de3bf98                 save    %sp, -0x68, %sp
F001E29C: 4001e247                 call    _spltty
F001E2A0: 233c04d2                 sethi   %hi(_mclfree), %l1
F001E2A4: d2046358                 ld      [%l1+%lo(_mclfree)], %o1
F001E2A8: 80a26000                 cmp     %o1, 0
F001E2AC: 12800006                 bne     loc_F001E2C4
F001E2B0: a4100008                 mov     %o0, %l2
F001E2B4: 90102001                 mov     1, %o0
F001E2B8: 92102001                 mov     1, %o1
F001E2BC: 7ffffd19                 call    _m_clalloc
F001E2C0: 94102000                 mov     0, %o2
F001E2C4: e0046358                 ld      [%l1+0x358], %l0
F001E2C8: 80a42000                 cmp     %l0, 0
F001E2CC: 02800017                 be      loc_F001E328
F001E2D0: 113c04d2                 sethi   %hi(_mbutl), %o0
F001E2D4: 153c04d2                 sethi   %hi(_mclrefcnt), %o2
F001E2D8: d2022350                 ld      [%o0+%lo(_mbutl)], %o1
F001E2DC: 9412a360                 bset    %lo(_mclrefcnt), %o2
F001E2E0: 92240009                 sub     %l0, %o1, %o1
F001E2E4: 933a600a                 sra     %o1, 10, %o1
F001E2E8: d00a400a                 ldub    [%o1+%o2], %o0
F001E2EC: 90022001                 inc     %o0
F001E2F0: d02a400a                 stb     %o0, [%o1+%o2]
F001E2F4: 133c04d2921262f0         set     _mbstat, %o1
F001E2FC: d002600c                 ld      [%o1+0xC], %o0
F001E300: 90023fff                 inc     -1, %o0
F001E304: d022600c                 st      %o0, [%o1+0xC]
F001E308: d0040000                 ld      [%l0], %o0
F001E30C: d0246358                 st      %o0, [%l1+0x358]
F001E310: 90102400                 mov     0x400, %o0
F001E314: d0362008                 sth     %o0, [%i0+8]
F001E318: 90240018                 sub     %l0, %i0, %o0
F001E31C: d0262004                 st      %o0, [%i0+4]
F001E320: 90102001                 mov     1, %o0
F001E324: d036200c                 sth     %o0, [%i0+0xC]
F001E328: 4001e27f                 call    _splx
F001E32C: 90100012                 mov     %l2, %o0
F001E330: 80a00010                 cmp     %g0, %l0
F001E334: b0402000                 addc    %g0, 0, %i0
F001E338: 81c7e008                 ret
F001E33C: 81e80000                 restore
