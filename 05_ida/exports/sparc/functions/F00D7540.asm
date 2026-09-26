F00D7540: 9de3bf90                 save    %sp, -0x70, %sp
F00D7544: 213c04bb                 sethi   %hi(dword_F012EF0C), %l0
F00D7548: d004230c                 ld      [%l0+%lo(dword_F012EF0C)], %o0
F00D754C: 80a22000                 cmp     %o0, 0
F00D7550: 3280000d                 bne,a   loc_F00D7584
F00D7554: 133c0504                 sethi   -0xFEBF000, %o1
F00D7558: 113c0506                 sethi   %hi(paList), %o0
F00D755C: d0022288                 ld      [%o0+%lo(paList)], %o0! id
F00D7560: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00D7564: 400068c3                 call    _objc_msgSend
F00D7568: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00D756C: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00D7570: 400068c0                 call    _objc_msgSend
F00D7574: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00D7578: d024230c                 st      %o0, [%l0+%lo(dword_F012EF0C)]
F00D757C: d004230c                 ld      [%l0+%lo(dword_F012EF0C)], %o0! id
F00D7580: 133c0504                 sethi   -0xFEBF000, %o1
F00D7584: d20260a4                 ld      [%o1+0xA4], %o1! SEL
F00D7588: 400068ba                 call    _objc_msgSend
F00D758C: 9410001a                 mov     %i2, %o2
F00D7590: 81c7e008                 ret
F00D7594: 81e80000                 restore
