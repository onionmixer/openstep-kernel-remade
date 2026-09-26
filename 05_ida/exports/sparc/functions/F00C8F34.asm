F00C8F34: 9de3bf90                 save    %sp, -0x70, %sp
F00C8F38: e2062010                 ld      [%i0+0x10], %l1
F00C8F3C: d004600c                 ld      [%l1+0xC], %o0
F00C8F40: 80a22000                 cmp     %o0, 0
F00C8F44: 32800014                 bne,a   locret_F00C8F94
F00C8F48: f004600c                 ld      [%l1+0xC], %i0
F00C8F4C: 113c0506                 sethi   %hi(paDelegate), %o0
F00C8F50: d2022118                 ld      [%o0+%lo(paDelegate)], %o1! SEL
F00C8F54: 113c0506                 sethi   %hi(paFetchrangelist), %o0! id
F00C8F58: e002210c                 ld      [%o0+%lo(paFetchrangelist)], %l0
F00C8F5C: 4000a245                 call    _objc_msgSend
F00C8F60: 90100018                 mov     %i0, %o0! id
F00C8F64: 133c0504                 sethi   %hi(paResourcesforke), %o1
F00C8F68: 153c03eb                 sethi   %hi(aMemoryMaps), %o2! "Memory Maps"
F00C8F6C: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F00C8F70: 4000a240                 call    _objc_msgSend
F00C8F74: 9412a3e8                 bset    %lo(aMemoryMaps), %o2! "Memory Maps"
F00C8F78: 94100008                 mov     %o0, %o2
F00C8F7C: 90100018                 mov     %i0, %o0! id
F00C8F80: 92100010                 mov     %l0, %o1! SEL
F00C8F84: 4000a23b                 call    _objc_msgSend
F00C8F88: 9604600c                 add     %l1, 0xC, %o3
F00C8F8C: d0246008                 st      %o0, [%l1+8]
F00C8F90: f004600c                 ld      [%l1+0xC], %i0
F00C8F94: 81c7e008                 ret
F00C8F98: 81e80000                 restore
