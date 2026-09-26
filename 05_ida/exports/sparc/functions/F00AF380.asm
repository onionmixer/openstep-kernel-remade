F00AF380: 9de3bf90                 save    %sp, -0x70, %sp
F00AF384: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF388: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AF38C: 80a22000                 cmp     %o0, 0
F00AF390: 12800008                 bne     loc_F00AF3B0
F00AF394: 113c000c                 sethi   %hi(_romp), %o0
F00AF398: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AF39C: d0022058                 ld      [%o0+0x58], %o0
F00AF3A0: 9fc20000                 call    %o0
F00AF3A4: 01000000                 nop
F00AF3A8: 1080000d                 ba      locret_F00AF3DC
F00AF3AC: b0100008                 mov     %o0, %i0
F00AF3B0: d4022030                 ld      [%o0+0x30], %o2
F00AF3B4: d002a090                 ld      [%o2+0x90], %o0
F00AF3B8: d602a0b4                 ld      [%o2+0xB4], %o3
F00AF3BC: 9207bff7                 add     %fp, var_9, %o1
F00AF3C0: d0020000                 ld      [%o0], %o0
F00AF3C4: 9fc2c000                 call    %o3
F00AF3C8: 94102001                 mov     1, %o2
F00AF3CC: 80a22001                 cmp     %o0, 1
F00AF3D0: 12800003                 bne     locret_F00AF3DC
F00AF3D4: b0103fff                 mov     -1, %i0
F00AF3D8: f04fbff7                 ldsb    [%fp+var_9], %i0
F00AF3DC: 81c7e008                 ret
F00AF3E0: 81e80000                 restore
