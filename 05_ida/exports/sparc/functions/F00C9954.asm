F00C9954: 9de3bf80                 save    %sp, -0x80, %sp
F00C9958: d0062108                 ld      [%i0+0x108], %o0! id
F00C995C: 133c0506                 sethi   %hi(paNuminterrupts), %o1
F00C9960: d20260dc                 ld      [%o1+%lo(paNuminterrupts)], %o1! SEL
F00C9964: 40009fc3                 call    _objc_msgSend
F00C9968: e206211c                 ld      [%i0+0x11C], %l1
F00C996C: 80a68008                 cmp     %i2, %o0
F00C9970: 2a800004                 bcs,a   loc_F00C9980
F00C9974: d0046004                 ld      [%l1+4], %o0
F00C9978: 1080005d                 ba      locret_F00C9AEC
F00C997C: b0103d3e                 mov     -0x2C2, %i0
F00C9980: 80a22000                 cmp     %o0, 0
F00C9984: 3280000e                 bne,a   loc_F00C99BC
F00C9988: d0046004                 ld      [%l1+4], %o0
F00C998C: 113c0506                 sethi   %hi(paHashtable), %o0
F00C9990: d002227c                 ld      [%o0+%lo(paHashtable)], %o0! id
F00C9994: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00C9998: 40009fb6                 call    _objc_msgSend
F00C999C: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00C99A0: 133c0504                 sethi   %hi(paInitkeydesc), %o1
F00C99A4: 153c03ec                 sethi   %hi(aI), %o2! "i"
F00C99A8: d2026064                 ld      [%o1+%lo(paInitkeydesc)], %o1! SEL
F00C99AC: 40009fb1                 call    _objc_msgSend
F00C99B0: 9412a030                 bset    %lo(aI), %o2! "i"
F00C99B4: d0246004                 st      %o0, [%l1+4]
F00C99B8: d0046004                 ld      [%l1+4], %o0! id
F00C99BC: 133c0504                 sethi   %hi(paValueforkey), %o1
F00C99C0: d202606c                 ld      [%o1+%lo(paValueforkey)], %o1! SEL
F00C99C4: 40009fab                 call    _objc_msgSend
F00C99C8: 9410001a                 mov     %i2, %o2
F00C99CC: a0920000                 orcc    %o0, %g0, %l0
F00C99D0: 1280003d                 bne     loc_F00C9AC4
F00C99D4: 912ee018                 sll     %i3, 24, %o0
F00C99D8: 90102003                 mov     3, %o0
F00C99DC: d027bfe8                 st      %o0, [%fp+var_18]
F00C99E0: d0062114                 ld      [%i0+0x114], %o0! id
F00C99E4: 133c0506                 sethi   %hi(paDevice_0), %o1
F00C99E8: d20260fc                 ld      [%o1+%lo(paDevice_0)], %o1! SEL
F00C99EC: 40009fa1                 call    _objc_msgSend
F00C99F0: c027bfe4                 clr     [%fp+var_1C]
F00C99F4: 133c0506                 sethi   %hi(paInterrupt), %o1
F00C99F8: d20260c8                 ld      [%o1+%lo(paInterrupt)], %o1! SEL
F00C99FC: 40009f9d                 call    _objc_msgSend
F00C9A00: 9410001a                 mov     %i2, %o2
F00C9A04: a0100008                 mov     %o0, %l0
F00C9A08: 9410001a                 mov     %i2, %o2
F00C9A0C: d0046004                 ld      [%l1+4], %o0! id
F00C9A10: 133c0504                 sethi   %hi(paInsertkeyValue), %o1
F00C9A14: d2026068                 ld      [%o1+%lo(paInsertkeyValue)], %o1! SEL
F00C9A18: 40009f96                 call    _objc_msgSend
F00C9A1C: 96100010                 mov     %l0, %o3
F00C9A20: 133c0504                 sethi   %hi(paResourcesforke), %o1
F00C9A24: d0062114                 ld      [%i0+0x114], %o0! id
F00C9A28: 153c03eb                 sethi   %hi(aIrqLevels), %o2! "IRQ Levels"
F00C9A2C: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F00C9A30: 40009f90                 call    _objc_msgSend
F00C9A34: 9412a3d8                 bset    %lo(aIrqLevels), %o2! "IRQ Levels"
F00C9A38: 133c0504                 sethi   %hi(paObjectat), %o1
F00C9A3C: d20260c8                 ld      [%o1+%lo(paObjectat)], %o1! SEL
F00C9A40: 40009f8c                 call    _objc_msgSend
F00C9A44: 9410001a                 mov     %i2, %o2
F00C9A48: a2100008                 mov     %o0, %l1
F00C9A4C: 90100018                 mov     %i0, %o0! id
F00C9A50: 9407bfec                 add     %fp, var_14, %o2
F00C9A54: 9607bfe8                 add     %fp, var_18, %o3
F00C9A58: 9807bfe4                 add     %fp, var_1C, %o4
F00C9A5C: 133c0506                 sethi   %hi(paGethandlerLeve), %o1
F00C9A60: d20260c4                 ld      [%o1+%lo(paGethandlerLeve)], %o1! SEL
F00C9A64: 40009f83                 call    _objc_msgSend
F00C9A68: 9a10001a                 mov     %i2, %o5
F00C9A6C: 912a2018                 sll     %o0, 24, %o0
F00C9A70: 80a22000                 cmp     %o0, 0
F00C9A74: 0280000b                 be      loc_F00C9AA0
F00C9A78: 113c0506                 sethi   %hi(paAttachtobusint), %o0! id
F00C9A7C: d20220c0                 ld      [%o0+%lo(paAttachtobusint)], %o1! SEL
F00C9A80: d607bfec                 ld      [%fp+var_14], %o3
F00C9A84: d807bfe4                 ld      [%fp+var_1C], %o4
F00C9A88: 94100011                 mov     %l1, %o2
F00C9A8C: da07bfe8                 ld      [%fp+var_18], %o5
F00C9A90: 40009f78                 call    _objc_msgSend
F00C9A94: 90100010                 mov     %l0, %o0
F00C9A98: 1080000b                 ba      loc_F00C9AC4
F00C9A9C: 912ee018                 sll     %i3, 24, %o0
F00C9AA0: 90100010                 mov     %l0, %o0! id
F00C9AA4: 133c0506                 sethi   %hi(paAttachtobusint_0), %o1
F00C9AA8: d20260bc                 ld      [%o1+%lo(paAttachtobusint_0)], %o1! SEL
F00C9AAC: 94100011                 mov     %l1, %o2
F00C9AB0: 170008c89612e325         set     0x232325, %o3
F00C9AB8: 40009f6e                 call    _objc_msgSend
F00C9ABC: 9606800b                 add     %i2, %o3, %o3
F00C9AC0: 912ee018                 sll     %i3, 24, %o0
F00C9AC4: 80a22000                 cmp     %o0, 0
F00C9AC8: 02800005                 be      loc_F00C9ADC
F00C9ACC: 113c0504                 sethi   -0xFEBF000, %o0
F00C9AD0: 113c0504                 sethi   %hi(paResume), %o0! id
F00C9AD4: 10800003                 ba      loc_F00C9AE0
F00C9AD8: d20220d8                 ld      [%o0+%lo(paResume)], %o1
F00C9ADC: d20220d4                 ld      [%o0+0xD4], %o1! SEL
F00C9AE0: 40009f64                 call    _objc_msgSend
F00C9AE4: 90100010                 mov     %l0, %o0
F00C9AE8: b0102000                 mov     0, %i0
F00C9AEC: 81c7e008                 ret
F00C9AF0: 81e80000                 restore
