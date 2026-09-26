F00AF3E4: 9de3bf90                 save    %sp, -0x70, %sp
F00AF3E8: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF3EC: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AF3F0: 80a22000                 cmp     %o0, 0
F00AF3F4: 1280000a                 bne     loc_F00AF41C
F00AF3F8: f02fbff7                 stb     %i0, [%fp+var_9]
F00AF3FC: 113c000c                 sethi   %hi(_romp), %o0
F00AF400: d2022030                 ld      [%o0+%lo(_romp)], %o1
F00AF404: 912e2018                 sll     %i0, 24, %o0
F00AF408: d202605c                 ld      [%o1+0x5C], %o1
F00AF40C: 9fc24000                 call    %o1
F00AF410: 913a2018                 sra     %o0, 24, %o0
F00AF414: 1080000d                 ba      locret_F00AF448
F00AF418: b0100008                 mov     %o0, %i0
F00AF41C: 113c000c                 sethi   %hi(_romp), %o0
F00AF420: d4022030                 ld      [%o0+%lo(_romp)], %o2
F00AF424: d002a094                 ld      [%o2+0x94], %o0
F00AF428: d602a0b8                 ld      [%o2+0xB8], %o3
F00AF42C: 9207bff7                 add     %fp, var_9, %o1
F00AF430: d0020000                 ld      [%o0], %o0
F00AF434: 9fc2c000                 call    %o3
F00AF438: 94102001                 mov     1, %o2
F00AF43C: 901a2001                 btog    1, %o0
F00AF440: 80a00008                 cmp     %g0, %o0
F00AF444: b0602000                 subc    %g0, 0, %i0
F00AF448: 81c7e008                 ret
F00AF44C: 81e80000                 restore
