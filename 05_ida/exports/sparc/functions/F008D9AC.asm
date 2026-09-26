F008D9AC: 9de3bf90                 save    %sp, -0x70, %sp
F008D9B0: f0062004                 ld      [%i0+4], %i0
F008D9B4: 113c0504                 sethi   %hi(paIskey), %o0! id
F008D9B8: d202207c                 ld      [%o0+%lo(paIskey)], %o1! SEL
F008D9BC: 9410001b                 mov     %i3, %o2
F008D9C0: 40018fac                 call    _objc_msgSend
F008D9C4: 90100018                 mov     %i0, %o0
F008D9C8: 912a2018                 sll     %o0, 24, %o0
F008D9CC: 80a22000                 cmp     %o0, 0
F008D9D0: 32800009                 bne,a   locret_F008D9F4
F008D9D4: b0102000                 mov     0, %i0
F008D9D8: 90100018                 mov     %i0, %o0! id
F008D9DC: 133c0504                 sethi   %hi(paInsertkeyValue), %o1
F008D9E0: d2026068                 ld      [%o1+%lo(paInsertkeyValue)], %o1! SEL
F008D9E4: 9410001b                 mov     %i3, %o2
F008D9E8: 40018fa2                 call    _objc_msgSend
F008D9EC: 9610001a                 mov     %i2, %o3
F008D9F0: b010001a                 mov     %i2, %i0
F008D9F4: 81c7e008                 ret
F008D9F8: 81e80000                 restore
