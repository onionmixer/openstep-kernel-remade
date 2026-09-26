F00AFC9C: 9de3bf98                 save    %sp, -0x68, %sp
F00AFCA0: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AFCA4: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AFCA8: 80a22000                 cmp     %o0, 0
F00AFCAC: 02800007                 be      locret_F00AFCC8
F00AFCB0: b0102000                 mov     0, %i0
F00AFCB4: 7ffffc50                 call    _prom_bootpath
F00AFCB8: 01000000                 nop
F00AFCBC: 40000c8d                 call    _path_to_devi
F00AFCC0: 01000000                 nop
F00AFCC4: b0100008                 mov     %o0, %i0
F00AFCC8: 81c7e008                 ret
F00AFCCC: 81e80000                 restore
