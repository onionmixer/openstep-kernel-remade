F00AFC00: 9de3bf98                 save    %sp, -0x68, %sp
F00AFC04: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AFC08: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AFC0C: 80a22000                 cmp     %o0, 0
F00AFC10: 02800004                 be      loc_F00AFC20
F00AFC14: 80a22002                 cmp     %o0, 2
F00AFC18: 32800006                 bne,a   loc_F00AFC30
F00AFC1C: 90100018                 mov     %i0, %o0
F00AFC20: 113c0470                 sethi   %hi(aPromStartcpu), %o0! "prom_startcpu"
F00AFC24: 7ffd9553                 call    _panic
F00AFC28: 90122330                 bset    %lo(aPromStartcpu), %o0! "prom_startcpu"
F00AFC2C: 90100018                 mov     %i0, %o0
F00AFC30: 153c000c                 sethi   %hi(_romp), %o2
F00AFC34: d602a030                 ld      [%o2+%lo(_romp)], %o3
F00AFC38: 92100019                 mov     %i1, %o1
F00AFC3C: d802e108                 ld      [%o3+0x108], %o4
F00AFC40: 9410001a                 mov     %i2, %o2
F00AFC44: 9fc30000                 call    %o4
F00AFC48: 9610001b                 mov     %i3, %o3
F00AFC4C: 81c7e008                 ret
F00AFC50: 91e80008                 restore %g0, %o0, %o0
