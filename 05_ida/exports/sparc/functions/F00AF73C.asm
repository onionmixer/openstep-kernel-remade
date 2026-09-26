F00AF73C: 9de3bf98                 save    %sp, -0x68, %sp
F00AF740: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF744: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AF748: 80a22000                 cmp     %o0, 0
F00AF74C: 02800008                 be      loc_F00AF76C
F00AF750: 113c000c                 sethi   %hi(_romp), %o0
F00AF754: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AF758: d2022098                 ld      [%o0+0x98], %o1
F00AF75C: 9fc24000                 call    %o1
F00AF760: 90100018                 mov     %i0, %o0
F00AF764: 10800003                 ba      locret_F00AF770
F00AF768: b0100008                 mov     %o0, %i0
F00AF76C: b0103fff                 mov     -1, %i0
F00AF770: 81c7e008                 ret
F00AF774: 81e80000                 restore
