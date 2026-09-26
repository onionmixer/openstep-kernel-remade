F009FB64: 9de3bf98                 save    %sp, -0x68, %sp
F009FB68: 113c0460                 sethi   %hi(aPmapUpdateInte), %o0! "pmap_update_interrupt: never be called"
F009FB6C: 7ffdd581                 call    _panic
F009FB70: 90122060                 bset    %lo(aPmapUpdateInte), %o0! "pmap_update_interrupt: never be called"
F009FB74: 81c7e008                 ret
F009FB78: 81e80000                 restore
