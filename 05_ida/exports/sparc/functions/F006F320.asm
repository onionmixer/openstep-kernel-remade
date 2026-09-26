F006F320: 9de3bf98                 save    %sp, -0x68, %sp
F006F324: d0062114                 ld      [%i0+0x114], %o0
F006F328: 80a22005                 cmp     %o0, 5
F006F32C: 02800004                 be      loc_F006F33C
F006F330: 80a22000                 cmp     %o0, 0
F006F334: 32800004                 bne,a   loc_F006F344
F006F338: d006212c                 ld      [%i0+0x12C], %o0
F006F33C: 10800005                 ba      locret_F006F350
F006F340: b0102005                 mov     5, %i0
F006F344: 7fffff96                 call    _pset_reference
F006F348: d0264000                 st      %o0, [%i1]
F006F34C: b0102000                 mov     0, %i0
F006F350: 81c7e008                 ret
F006F354: 81e80000                 restore
