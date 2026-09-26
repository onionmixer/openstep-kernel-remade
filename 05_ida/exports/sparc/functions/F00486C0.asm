F00486C0: 9de3bf98                 save    %sp, -0x68, %sp
F00486C4: d0062030                 ld      [%i0+0x30], %o0
F00486C8: d0022038                 ld      [%o0+0x38], %o0
F00486CC: 80a22000                 cmp     %o0, 0
F00486D0: 32800004                 bne,a   loc_F00486E0
F00486D4: d202201c                 ld      [%o0+0x1C], %o1
F00486D8: 10800006                 ba      locret_F00486F0
F00486DC: b0102016                 mov     0x16, %i0
F00486E0: d4026064                 ld      [%o1+0x64], %o2
F00486E4: 9fc28000                 call    %o2
F00486E8: 92100019                 mov     %i1, %o1
F00486EC: b0100008                 mov     %o0, %i0
F00486F0: 81c7e008                 ret
F00486F4: 81e80000                 restore
