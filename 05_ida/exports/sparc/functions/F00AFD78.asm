F00AFD78: 9de3bf98                 save    %sp, -0x68, %sp
F00AFD7C: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AFD80: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AFD84: 80a22000                 cmp     %o0, 0
F00AFD88: 12800007                 bne     loc_F00AFDA4
F00AFD8C: 113c000c                 sethi   %hi(_romp), %o0
F00AFD90: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AFD94: d0022080                 ld      [%o0+0x80], %o0
F00AFD98: d0020000                 ld      [%o0], %o0
F00AFD9C: 10800009                 ba      locret_F00AFDC0
F00AFDA0: f002208c                 ld      [%o0+0x8C], %i0
F00AFDA4: 7ffffc14                 call    _prom_bootpath
F00AFDA8: b0102000                 mov     0, %i0
F00AFDAC: 40000c51                 call    _path_to_devi
F00AFDB0: 01000000                 nop
F00AFDB4: 80a22000                 cmp     %o0, 0
F00AFDB8: 32800002                 bne,a   locret_F00AFDC0
F00AFDBC: f002202c                 ld      [%o0+0x2C], %i0
F00AFDC0: 81c7e008                 ret
F00AFDC4: 81e80000                 restore
