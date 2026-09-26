F00C8ECC: 9de3bf90                 save    %sp, -0x70, %sp
F00C8ED0: e2062010                 ld      [%i0+0x10], %l1
F00C8ED4: d004600c                 ld      [%l1+0xC], %o0
F00C8ED8: 80a22000                 cmp     %o0, 0
F00C8EDC: 32800014                 bne,a   locret_F00C8F2C
F00C8EE0: f0046008                 ld      [%l1+8], %i0
F00C8EE4: 113c0506                 sethi   %hi(paDelegate), %o0
F00C8EE8: d2022118                 ld      [%o0+%lo(paDelegate)], %o1! SEL
F00C8EEC: 113c0506                 sethi   %hi(paFetchrangelist), %o0! id
F00C8EF0: e002210c                 ld      [%o0+%lo(paFetchrangelist)], %l0
F00C8EF4: 4000a25f                 call    _objc_msgSend
F00C8EF8: 90100018                 mov     %i0, %o0! id
F00C8EFC: 133c0504                 sethi   %hi(paResourcesforke), %o1
F00C8F00: 153c03eb                 sethi   %hi(aMemoryMaps), %o2! "Memory Maps"
F00C8F04: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F00C8F08: 4000a25a                 call    _objc_msgSend
F00C8F0C: 9412a3e8                 bset    %lo(aMemoryMaps), %o2! "Memory Maps"
F00C8F10: 94100008                 mov     %o0, %o2
F00C8F14: 90100018                 mov     %i0, %o0! id
F00C8F18: 92100010                 mov     %l0, %o1! SEL
F00C8F1C: 4000a255                 call    _objc_msgSend
F00C8F20: 9604600c                 add     %l1, 0xC, %o3
F00C8F24: d0246008                 st      %o0, [%l1+8]
F00C8F28: f0046008                 ld      [%l1+8], %i0
F00C8F2C: 81c7e008                 ret
F00C8F30: 81e80000                 restore
