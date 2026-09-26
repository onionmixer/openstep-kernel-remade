F00EF1BC: 9de3bf98                 save    %sp, -0x68, %sp
F00EF1C0: a0960000                 orcc    %i0, %g0, %l0
F00EF1C4: 32800008                 bne,a   loc_F00EF1E4
F00EF1C8: d0042014                 ld      [%l0+0x14], %o0
F00EF1CC: 90102000                 mov     0, %o0
F00EF1D0: 133c03e892126298         set     aAllocatingNilO, %o1! "allocating nil object"
F00EF1D8: 400005ca                 call    ___objc_error
F00EF1DC: 94102000                 mov     0, %o2
F00EF1E0: d0042014                 ld      [%l0+0x14], %o0
F00EF1E4: a2064008                 add     %i1, %o0, %l1
F00EF1E8: d406a004                 ld      [%i2+4], %o2
F00EF1EC: 9010001a                 mov     %i2, %o0
F00EF1F0: 9fc28000                 call    %o2
F00EF1F4: 92100011                 mov     %l1, %o1
F00EF1F8: b0920000                 orcc    %o0, %g0, %i0
F00EF1FC: 1280000a                 bne     loc_F00EF224
F00EF200: 90100018                 mov     %i0, %o0
F00EF204: 90100010                 mov     %l0, %o0! void *
F00EF208: 133c03e892126278         set     aFailedOutOfMem_0, %o1! "failed -- out of memory(%s, %u)"
F00EF210: d4042008                 ld      [%l0+8], %o2
F00EF214: 400005bb                 call    ___objc_error
F00EF218: 96100019                 mov     %i1, %o3
F00EF21C: 10800005                 ba      locret_F00EF230
F00EF220: b0102000                 mov     0, %i0
F00EF224: 7ffe970d                 call    _bzero
F00EF228: 92100011                 mov     %l1, %o1
F00EF22C: e0260000                 st      %l0, [%i0]
F00EF230: 81c7e008                 ret
F00EF234: 81e80000                 restore
