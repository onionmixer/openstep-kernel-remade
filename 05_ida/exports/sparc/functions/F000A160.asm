F000A160: 9de3bf98                 save    %sp, -0x68, %sp
F000A164: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000A168: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000A16C: d2026024                 ld      [%o1+0x24], %o1
F000A170: 901221dc                 bset    %lo(dword_F0133DDC), %o0
F000A174: e0023ffc                 ld      [%o0-4], %l0
F000A178: d0024000                 ld      [%o1], %o0
F000A17C: d024224c                 st      %o0, [%l0+0x24C]
F000A180: d0026004                 ld      [%o1+4], %o0
F000A184: d0242250                 st      %o0, [%l0+0x250]
F000A188: d0026008                 ld      [%o1+8], %o0
F000A18C: a2042244                 add     %l0, 0x244, %l1
F000A190: d4042244                 ld      [%l0+0x244], %o2
F000A194: d0242254                 st      %o0, [%l0+0x254]
F000A198: d002600c                 ld      [%o1+0xC], %o0
F000A19C: 80a2a000                 cmp     %o2, 0
F000A1A0: 12800006                 bne     loc_F000A1B8
F000A1A4: d0242258                 st      %o0, [%l0+0x258]
F000A1A8: 40017ac2                 call    _simple_lock_alloc
F000A1AC: 01000000                 nop
F000A1B0: d0242244                 st      %o0, [%l0+0x244]
F000A1B4: c0220000                 clr     [%o0]
F000A1B8: d0042248                 ld      [%l0+0x248], %o0
F000A1BC: 80a22000                 cmp     %o0, 0
F000A1C0: 22800009                 be,a    locret_F000A1E4
F000A1C4: c0246004                 clr     [%l1+4]
F000A1C8: e0022004                 ld      [%o0+4], %l0
F000A1CC: 400177f5                 call    _kfree
F000A1D0: 92102018                 mov     0x18, %o1
F000A1D4: 90940000                 orcc    %l0, %g0, %o0
F000A1D8: 32bffffd                 bne,a   loc_F000A1CC
F000A1DC: e0022004                 ld      [%o0+4], %l0
F000A1E0: c0246004                 clr     [%l1+4]
F000A1E4: 81c7e008                 ret
F000A1E8: 81e80000                 restore
