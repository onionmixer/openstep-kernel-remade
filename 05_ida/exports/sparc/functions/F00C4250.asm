F00C4250: 9de3bf90                 save    %sp, -0x70, %sp
F00C4254: 113c0504                 sethi   %hi(paAreresourcesac), %o0! id
F00C4258: d2022388                 ld      [%o0+%lo(paAreresourcesac)], %o1! SEL
F00C425C: 4000b585                 call    _objc_msgSend
F00C4260: 90100018                 mov     %i0, %o0
F00C4264: 912a2018                 sll     %o0, 24, %o0
F00C4268: 80a22000                 cmp     %o0, 0
F00C426C: 1280001b                 bne     locret_F00C42D8
F00C4270: 90100018                 mov     %i0, %o0! id
F00C4274: 133c0504                 sethi   %hi(paDeleteresource), %o1! SEL
F00C4278: 153c04ba                 sethi   %hi(aIrqLevels_4), %o2! "IRQ Levels"
F00C427C: e202638c                 ld      [%o1+%lo(paDeleteresource)], %l1
F00C4280: 9412a220                 bset    %lo(aIrqLevels_4), %o2! "IRQ Levels"
F00C4284: 4000b57b                 call    _objc_msgSend
F00C4288: 92100011                 mov     %l1, %o1
F00C428C: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00C4290: e00263fc                 ld      [%o1+%lo(paFree)], %l0
F00C4294: 4000b577                 call    _objc_msgSend
F00C4298: 92100010                 mov     %l0, %o1
F00C429C: 90100018                 mov     %i0, %o0! id
F00C42A0: 92100011                 mov     %l1, %o1! SEL
F00C42A4: 153c04ba                 sethi   %hi(aMemoryMaps_4), %o2! "Memory Maps"
F00C42A8: 4000b572                 call    _objc_msgSend
F00C42AC: 9412a230                 bset    %lo(aMemoryMaps_4), %o2! "Memory Maps"
F00C42B0: 4000b570                 call    _objc_msgSend
F00C42B4: 92100010                 mov     %l0, %o1
F00C42B8: f027bff0                 st      %i0, [%fp+var_10]
F00C42BC: 133c0507                 sethi   %hi(stru_F0141E1C.super_class), %o1
F00C42C0: d4026220                 ld      [%o1+%lo(stru_F0141E1C.super_class)], %o2
F00C42C4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C42C8: 92100010                 mov     %l0, %o1! SEL
F00C42CC: 4000b5ac                 call    _objc_msgSendSuper
F00C42D0: d427bff4                 st      %o2, [%fp+var_C]
F00C42D4: b0100008                 mov     %o0, %i0
F00C42D8: 81c7e008                 ret
F00C42DC: 81e80000                 restore
