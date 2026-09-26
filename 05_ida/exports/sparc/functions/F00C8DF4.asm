F00C8DF4: 9de3bf90                 save    %sp, -0x70, %sp
F00C8DF8: e2062010                 ld      [%i0+0x10], %l1
F00C8DFC: d0046004                 ld      [%l1+4], %o0
F00C8E00: 80a22000                 cmp     %o0, 0
F00C8E04: 32800014                 bne,a   locret_F00C8E54
F00C8E08: f0046004                 ld      [%l1+4], %i0
F00C8E0C: 113c0506                 sethi   %hi(paDelegate), %o0
F00C8E10: d2022118                 ld      [%o0+%lo(paDelegate)], %o1! SEL
F00C8E14: 113c0506                 sethi   %hi(paFetchitemlistR), %o0! id
F00C8E18: e0022114                 ld      [%o0+%lo(paFetchitemlistR)], %l0
F00C8E1C: 4000a295                 call    _objc_msgSend
F00C8E20: 90100018                 mov     %i0, %o0! id
F00C8E24: 133c0504                 sethi   %hi(paResourcesforke), %o1
F00C8E28: 153c03eb                 sethi   %hi(aIrqLevels), %o2! "IRQ Levels"
F00C8E2C: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F00C8E30: 4000a290                 call    _objc_msgSend
F00C8E34: 9412a3d8                 bset    %lo(aIrqLevels), %o2! "IRQ Levels"
F00C8E38: 94100008                 mov     %o0, %o2
F00C8E3C: 90100018                 mov     %i0, %o0! id
F00C8E40: 92100010                 mov     %l0, %o1! SEL
F00C8E44: 4000a28b                 call    _objc_msgSend
F00C8E48: 96046004                 add     %l1, 4, %o3
F00C8E4C: d0244000                 st      %o0, [%l1]
F00C8E50: f0046004                 ld      [%l1+4], %i0
F00C8E54: 81c7e008                 ret
F00C8E58: 81e80000                 restore
