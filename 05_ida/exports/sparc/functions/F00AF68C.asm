F00AF68C: 9de3bf98                 save    %sp, -0x68, %sp
F00AF690: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF694: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AF698: 80a22000                 cmp     %o0, 0
F00AF69C: 1280000b                 bne     loc_F00AF6C8
F00AF6A0: 113c000c                 sethi   %hi(_romp), %o0
F00AF6A4: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AF6A8: d2022024                 ld      [%o0+0x24], %o1
F00AF6AC: 9fc24000                 call    %o1
F00AF6B0: 90100018                 mov     %i0, %o0
F00AF6B4: 80a22000                 cmp     %o0, 0
F00AF6B8: 12800009                 bne     locret_F00AF6DC
F00AF6BC: b0100008                 mov     %o0, %i0
F00AF6C0: 10800007                 ba      locret_F00AF6DC
F00AF6C4: b0103fff                 mov     -1, %i0
F00AF6C8: d0022030                 ld      [%o0+0x30], %o0
F00AF6CC: d20220ac                 ld      [%o0+0xAC], %o1
F00AF6D0: 9fc24000                 call    %o1
F00AF6D4: 90100018                 mov     %i0, %o0
F00AF6D8: b0100008                 mov     %o0, %i0
F00AF6DC: 81c7e008                 ret
F00AF6E0: 81e80000                 restore
