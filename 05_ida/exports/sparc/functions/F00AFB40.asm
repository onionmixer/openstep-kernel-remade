F00AFB40: 9de3bf98                 save    %sp, -0x68, %sp
F00AFB44: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AFB48: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AFB4C: 80a22000                 cmp     %o0, 0
F00AFB50: 02800004                 be      loc_F00AFB60
F00AFB54: 80a22002                 cmp     %o0, 2
F00AFB58: 32800006                 bne,a   loc_F00AFB70
F00AFB5C: 113c000c                 sethi   -0xFFFD000, %o0
F00AFB60: 113c0470                 sethi   %hi(aPromResumecpu), %o0! "prom_resumecpu"
F00AFB64: 7ffd9583                 call    _panic
F00AFB68: 90122320                 bset    %lo(aPromResumecpu), %o0! "prom_resumecpu"
F00AFB6C: 113c000c                 sethi   -0xFFFD000, %o0
F00AFB70: d0022030                 ld      [%o0+0x30], %o0
F00AFB74: d2022114                 ld      [%o0+0x114], %o1
F00AFB78: 9fc24000                 call    %o1
F00AFB7C: 90100018                 mov     %i0, %o0
F00AFB80: 81c7e008                 ret
F00AFB84: 91e80008                 restore %g0, %o0, %o0
