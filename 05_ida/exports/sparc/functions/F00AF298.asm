F00AF298: 9de3bf98                 save    %sp, -0x68, %sp
F00AF29C: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF2A0: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AF2A4: 80a22000                 cmp     %o0, 0
F00AF2A8: 02800004                 be      loc_F00AF2B8
F00AF2AC: 80a22002                 cmp     %o0, 2
F00AF2B0: 12800009                 bne     loc_F00AF2D4
F00AF2B4: 113c000c                 sethi   -0xFFFD000, %o0
F00AF2B8: 113c000c                 sethi   %hi(_romp), %o0
F00AF2BC: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AF2C0: d0022048                 ld      [%o0+0x48], %o0
F00AF2C4: d00a0000                 ldub    [%o0], %o0
F00AF2C8: 80a00008                 cmp     %g0, %o0
F00AF2CC: 1080000c                 ba      locret_F00AF2FC
F00AF2D0: b0603fff                 subc    %g0, -1, %i0
F00AF2D4: d0022030                 ld      [%o0+0x30], %o0
F00AF2D8: d0022090                 ld      [%o0+0x90], %o0
F00AF2DC: 40000118                 call    _prom_getphandle
F00AF2E0: d0020000                 ld      [%o0], %o0
F00AF2E4: 133c0470                 sethi   %hi(aKeyboard), %o1! "keyboard"
F00AF2E8: 7fffff3d                 call    _prom_getproplen
F00AF2EC: 921262a8                 bset    %lo(aKeyboard), %o1! "keyboard"
F00AF2F0: 90380008                 xnor    %g0, %o0, %o0
F00AF2F4: 80a00008                 cmp     %g0, %o0
F00AF2F8: b0402000                 addc    %g0, 0, %i0
F00AF2FC: 81c7e008                 ret
F00AF300: 81e80000                 restore
