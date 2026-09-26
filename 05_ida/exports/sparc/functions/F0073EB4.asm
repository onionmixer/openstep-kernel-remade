F0073EB4: 9de3bf98                 save    %sp, -0x68, %sp
F0073EB8: d0062008                 ld      [%i0+8], %o0
F0073EBC: 80a22000                 cmp     %o0, 0
F0073EC0: 22800006                 be,a    locret_F0073ED8
F0073EC4: b0102005                 mov     5, %i0
F0073EC8: d006202c                 ld      [%i0+0x2C], %o0
F0073ECC: 7fffecb4                 call    _pset_reference
F0073ED0: d0264000                 st      %o0, [%i1]
F0073ED4: b0102000                 mov     0, %i0
F0073ED8: 81c7e008                 ret
F0073EDC: 81e80000                 restore
