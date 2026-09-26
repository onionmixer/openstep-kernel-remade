F00AF0C8: 9de3bf98                 save    %sp, -0x68, %sp
F00AF0CC: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF0D0: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AF0D4: 80a22000                 cmp     %o0, 0
F00AF0D8: 02800004                 be      loc_F00AF0E8
F00AF0DC: 80a22002                 cmp     %o0, 2
F00AF0E0: 32800006                 bne,a   loc_F00AF0F8
F00AF0E4: 113c000c                 sethi   -0xFFFD000, %o0
F00AF0E8: 113c0470                 sethi   %hi(aPromIdlecpu), %o0! "prom_idlecpu"
F00AF0EC: 7ffd9821                 call    _panic
F00AF0F0: 901221e0                 bset    %lo(aPromIdlecpu), %o0! "prom_idlecpu"
F00AF0F4: 113c000c                 sethi   -0xFFFD000, %o0
F00AF0F8: d0022030                 ld      [%o0+0x30], %o0
F00AF0FC: d2022110                 ld      [%o0+0x110], %o1
F00AF100: 9fc24000                 call    %o1
F00AF104: 90100018                 mov     %i0, %o0
F00AF108: 81c7e008                 ret
F00AF10C: 91e80008                 restore %g0, %o0, %o0
