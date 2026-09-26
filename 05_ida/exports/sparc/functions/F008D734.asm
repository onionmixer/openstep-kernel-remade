F008D734: 9de3bf90                 save    %sp, -0x70, %sp
F008D738: b010001a                 mov     %i2, %i0
F008D73C: 113c04c3                 sethi   %hi(dword_F0130FF8), %o0
F008D740: 133c0504                 sethi   %hi(paInsertkeyValue), %o1
F008D744: d00223f8                 ld      [%o0+%lo(dword_F0130FF8)], %o0! id
F008D748: 9410001b                 mov     %i3, %o2
F008D74C: d2026068                 ld      [%o1+%lo(paInsertkeyValue)], %o1! SEL
F008D750: 40019048                 call    _objc_msgSend
F008D754: 96100018                 mov     %i0, %o3
F008D758: 81c7e008                 ret
F008D75C: 81e80000                 restore
