F00C8D8C: 9de3bf90                 save    %sp, -0x70, %sp
F00C8D90: e2062010                 ld      [%i0+0x10], %l1
F00C8D94: d0046004                 ld      [%l1+4], %o0
F00C8D98: 80a22000                 cmp     %o0, 0
F00C8D9C: 32800014                 bne,a   locret_F00C8DEC
F00C8DA0: f0044000                 ld      [%l1], %i0
F00C8DA4: 113c0506                 sethi   %hi(paDelegate), %o0
F00C8DA8: d2022118                 ld      [%o0+%lo(paDelegate)], %o1! SEL
F00C8DAC: 113c0506                 sethi   %hi(paFetchitemlistR), %o0! id
F00C8DB0: e0022114                 ld      [%o0+%lo(paFetchitemlistR)], %l0
F00C8DB4: 4000a2af                 call    _objc_msgSend
F00C8DB8: 90100018                 mov     %i0, %o0! id
F00C8DBC: 133c0504                 sethi   %hi(paResourcesforke), %o1
F00C8DC0: 153c03eb                 sethi   %hi(aIrqLevels), %o2! "IRQ Levels"
F00C8DC4: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F00C8DC8: 4000a2aa                 call    _objc_msgSend
F00C8DCC: 9412a3d8                 bset    %lo(aIrqLevels), %o2! "IRQ Levels"
F00C8DD0: 94100008                 mov     %o0, %o2
F00C8DD4: 90100018                 mov     %i0, %o0! id
F00C8DD8: 92100010                 mov     %l0, %o1! SEL
F00C8DDC: 4000a2a5                 call    _objc_msgSend
F00C8DE0: 96046004                 add     %l1, 4, %o3
F00C8DE4: d0244000                 st      %o0, [%l1]
F00C8DE8: f0044000                 ld      [%l1], %i0
F00C8DEC: 81c7e008                 ret
F00C8DF0: 81e80000                 restore
