F00C0590: 9de3bf90                 save    %sp, -0x70, %sp
F00C0594: a0100018                 mov     %i0, %l0
F00C0598: d0042124                 ld      [%l0+0x124], %o0
F00C059C: 80a22000                 cmp     %o0, 0
F00C05A0: 3280000a                 bne,a   loc_F00C05C8
F00C05A4: 133c0504                 sethi   -0xFEBF000, %o1
F00C05A8: 113c0506                 sethi   %hi(paNxlock), %o0
F00C05AC: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00C05B0: 133c0504                 sethi   %hi(paNew), %o1! SEL
F00C05B4: 4000c4af                 call    _objc_msgSend
F00C05B8: d2026238                 ld      [%o1+%lo(paNew)], %o1
F00C05BC: d0242124                 st      %o0, [%l0+0x124]
F00C05C0: d0042124                 ld      [%l0+0x124], %o0! id
F00C05C4: 133c0504                 sethi   -0xFEBF000, %o1! SEL
F00C05C8: 4000c4aa                 call    _objc_msgSend
F00C05CC: d2026000                 ld      [%o1], %o1
F00C05D0: e027bff0                 st      %l0, [%fp+var_10]
F00C05D4: 133c0507                 sethi   %hi(stru_F0141D7C.super_class), %o1
F00C05D8: d4026180                 ld      [%o1+%lo(stru_F0141D7C.super_class)], %o2
F00C05DC: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C05E0: 133c0504                 sethi   %hi(paInit), %o1
F00C05E4: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00C05E8: 4000c4e5                 call    _objc_msgSendSuper
F00C05EC: d427bff4                 st      %o2, [%fp+var_C]
F00C05F0: c0242128                 clr     [%l0+0x128]
F00C05F4: 113c0504                 sethi   %hi(paInitpointer), %o0! id
F00C05F8: d20222f0                 ld      [%o0+%lo(paInitpointer)], %o1! SEL
F00C05FC: c0242134                 clr     [%l0+0x134]
F00C0600: 4000c49c                 call    _objc_msgSend
F00C0604: 90100010                 mov     %l0, %o0
F00C0608: b0100008                 mov     %o0, %i0
F00C060C: d0042128                 ld      [%l0+0x128], %o0! id
F00C0610: 133c0504                 sethi   %hi(paGetresolution), %o1! SEL
F00C0614: 4000c497                 call    _objc_msgSend
F00C0618: d20262f4                 ld      [%o1+%lo(paGetresolution)], %o1
F00C061C: d0242130                 st      %o0, [%l0+0x130]
F00C0620: d0042124                 ld      [%l0+0x124], %o0! id
F00C0624: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C0628: 4000c492                 call    _objc_msgSend
F00C062C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C0630: 90100010                 mov     %l0, %o0! id
F00C0634: 133c0504                 sethi   %hi(paSetpointerscal), %o1
F00C0638: 173c03e4                 sethi   %hi(unk_F00F91EC), %o3
F00C063C: 94102005                 mov     5, %o2
F00C0640: d20262e4                 ld      [%o1+%lo(paSetpointerscal)], %o1! SEL
F00C0644: 4000c48b                 call    _objc_msgSend
F00C0648: 9612e1ec                 bset    %lo(unk_F00F91EC), %o3
F00C064C: 81c7e008                 ret
F00C0650: 81e80000                 restore
