F00D9DFC: 9de3bf90                 save    %sp, -0x70, %sp
F00D9E00: 213c04bb                 sethi   %hi(dword_F012EF2C), %l0
F00D9E04: d004232c                 ld      [%l0+%lo(dword_F012EF2C)], %o0
F00D9E08: 80a22000                 cmp     %o0, 0
F00D9E0C: 3280000d                 bne,a   loc_F00D9E40
F00D9E10: 133c0504                 sethi   -0xFEBF000, %o1
F00D9E14: 113c0506                 sethi   %hi(paList), %o0
F00D9E18: d0022288                 ld      [%o0+%lo(paList)], %o0! id
F00D9E1C: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00D9E20: 40005e94                 call    _objc_msgSend
F00D9E24: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00D9E28: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00D9E2C: 40005e91                 call    _objc_msgSend
F00D9E30: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00D9E34: d024232c                 st      %o0, [%l0+%lo(dword_F012EF2C)]
F00D9E38: d004232c                 ld      [%l0+%lo(dword_F012EF2C)], %o0! id
F00D9E3C: 133c0504                 sethi   -0xFEBF000, %o1
F00D9E40: d20260a4                 ld      [%o1+0xA4], %o1! SEL
F00D9E44: 40005e8b                 call    _objc_msgSend
F00D9E48: 9410001a                 mov     %i2, %o2
F00D9E4C: 81c7e008                 ret
F00D9E50: 81e80000                 restore
