F00AF1D4: 9de3bf98                 save    %sp, -0x68, %sp
F00AF1D8: 213c000c                 sethi   %hi(_romp), %l0
F00AF1DC: d0042030                 ld      [%l0+%lo(_romp)], %o0
F00AF1E0: 13040041                 sethi   0x10010400, %o1
F00AF1E4: d0020000                 ld      [%o0], %o0
F00AF1E8: 92126007                 bset    7, %o1
F00AF1EC: 80a20009                 cmp     %o0, %o1
F00AF1F0: 02800006                 be      loc_F00AF208
F00AF1F4: 113c0470                 sethi   %hi(aPromMagicNumbe), %o0! "PROM Magic Number"
F00AF1F8: 40000160                 call    _prom_printf
F00AF1FC: 90122280                 bset    %lo(aPromMagicNumbe), %o0! "PROM Magic Number"
F00AF200: 7fffff31                 call    _prom_enter_mon
F00AF204: 01000000                 nop
F00AF208: d0042030                 ld      [%l0+0x30], %o0
F00AF20C: d2022004                 ld      [%o0+4], %o1
F00AF210: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF214: d2222278                 st      %o1, [%o0+%lo(_obp_romvec_version)]
F00AF218: 81c7e008                 ret
F00AF21C: 81e80000                 restore
