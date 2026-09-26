F00DBCD8: 9de3bf90                 save    %sp, -0x70, %sp
F00DBCDC: d0062008                 ld      [%i0+8], %o0! id
F00DBCE0: 133c0505                 sethi   %hi(paOutputstarttim), %o1! SEL
F00DBCE4: 400056e3                 call    _objc_msgSend
F00DBCE8: d2026044                 ld      [%o1+%lo(paOutputstarttim)], %o1
F00DBCEC: d0062008                 ld      [%i0+8], %o0! id
F00DBCF0: 133c0505                 sethi   %hi(paLastinterruptt), %o1! SEL
F00DBCF4: 400056df                 call    _objc_msgSend
F00DBCF8: d2026040                 ld      [%o1+%lo(paLastinterruptt)], %o1
F00DBCFC: 80a22000                 cmp     %o0, 0
F00DBD00: 12800008                 bne     loc_F00DBD20
F00DBD04: 80a26000                 cmp     %o1, 0
F00DBD08: 12800006                 bne     loc_F00DBD20
F00DBD0C: 01000000                 nop
F00DBD10: c026c000                 clr     [%i3]
F00DBD14: c0268000                 clr     [%i2]
F00DBD18: 1080000c                 ba      locret_F00DBD48
F00DBD1C: b0102000                 mov     0, %i0
F00DBD20: 94102000                 mov     0, %o2
F00DBD24: 961023e8                 mov     0x3E8, %o3
F00DBD28: 7ffca832                 call    __udivdi3
F00DBD2C: 01000000                 nop
F00DBD30: 80a6e000                 cmp     %i3, 0
F00DBD34: 32800002                 bne,a   loc_F00DBD3C
F00DBD38: d226c000                 st      %o1, [%i3]
F00DBD3C: d0062020                 ld      [%i0+0x20], %o0
F00DBD40: b0102001                 mov     1, %i0
F00DBD44: d0268000                 st      %o0, [%i2]
F00DBD48: 81c7e008                 ret
F00DBD4C: 81e80000                 restore
