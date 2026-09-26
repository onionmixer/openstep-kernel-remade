F00AFC54: 9de3bf98                 save    %sp, -0x68, %sp
F00AFC58: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AFC5C: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AFC60: 80a22000                 cmp     %o0, 0
F00AFC64: 02800004                 be      loc_F00AFC74
F00AFC68: 80a22002                 cmp     %o0, 2
F00AFC6C: 32800006                 bne,a   loc_F00AFC84
F00AFC70: 113c000c                 sethi   -0xFFFD000, %o0
F00AFC74: 113c0470                 sethi   %hi(aPromStopcpu), %o0! "prom_stopcpu"
F00AFC78: 7ffd953e                 call    _panic
F00AFC7C: 90122340                 bset    %lo(aPromStopcpu), %o0! "prom_stopcpu"
F00AFC80: 113c000c                 sethi   -0xFFFD000, %o0
F00AFC84: d0022030                 ld      [%o0+0x30], %o0
F00AFC88: d202210c                 ld      [%o0+0x10C], %o1
F00AFC8C: 9fc24000                 call    %o1
F00AFC90: 90100018                 mov     %i0, %o0
F00AFC94: 81c7e008                 ret
F00AFC98: 91e80008                 restore %g0, %o0, %o0
