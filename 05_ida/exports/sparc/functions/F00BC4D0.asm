F00BC4D0: 9de3bf90                 save    %sp, -0x70, %sp
F00BC4D4: a0100018                 mov     %i0, %l0
F00BC4D8: d0062108                 ld      [%i0+0x108], %o0! id
F00BC4DC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BC4E0: 4000d4e4                 call    _objc_msgSend
F00BC4E4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BC4E8: c026216c                 clr     [%i0+0x16C]
F00BC4EC: c0262168                 clr     [%i0+0x168]
F00BC4F0: c026211c                 clr     [%i0+0x11C]
F00BC4F4: f6262114                 st      %i3, [%i0+0x114]
F00BC4F8: c0262170                 clr     [%i0+0x170]
F00BC4FC: b52ea018                 sll     %i2, 24, %i2
F00BC500: 80a6a000                 cmp     %i2, 0
F00BC504: d2062124                 ld      [%i0+0x124], %o1
F00BC508: 11200000                 sethi   0x80000000, %o0
F00BC50C: 902a4008                 andn    %o1, %o0, %o0
F00BC510: 0280000c                 be      loc_F00BC540
F00BC514: d0262124                 st      %o0, [%i0+0x124]
F00BC518: 113c0504                 sethi   %hi(paInitkb), %o0! id
F00BC51C: d2022258                 ld      [%o0+%lo(paInitkb)], %o1! SEL
F00BC520: 4000d4d4                 call    _objc_msgSend
F00BC524: 90100018                 mov     %i0, %o0
F00BC528: 80a22000                 cmp     %o0, 0
F00BC52C: 32800006                 bne,a   loc_F00BC544
F00BC530: e027bff0                 st      %l0, [%fp+var_10]
F00BC534: 113c047f                 sethi   %hi(aKmdeviceNoKeyb), %o0! "kmDevice: No Keyboard Found\n"
F00BC538: 400026ef                 call    _IOLog
F00BC53C: 901222e0                 bset    %lo(aKmdeviceNoKeyb), %o0! "kmDevice: No Keyboard Found\n"
F00BC540: e027bff0                 st      %l0, [%fp+var_10]
F00BC544: 133c0507                 sethi   %hi(stru_F0141D2C.super_class), %o1
F00BC548: d4026130                 ld      [%o1+%lo(stru_F0141D2C.super_class)], %o2
F00BC54C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00BC550: 133c0504                 sethi   %hi(paInit), %o1
F00BC554: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00BC558: 4000d509                 call    _objc_msgSendSuper
F00BC55C: d427bff4                 st      %o2, [%fp+var_C]
F00BC560: d04c2174                 ldsb    [%l0+0x174], %o0
F00BC564: 80a22000                 cmp     %o0, 0
F00BC568: 32800009                 bne,a   loc_F00BC58C
F00BC56C: d0042108                 ld      [%l0+0x108], %o0
F00BC570: 113c0504                 sethi   %hi(paRegisterdevice), %o0! id
F00BC574: d202225c                 ld      [%o0+%lo(paRegisterdevice)], %o1! SEL
F00BC578: 4000d4be                 call    _objc_msgSend
F00BC57C: 90100010                 mov     %l0, %o0
F00BC580: 90102001                 mov     1, %o0
F00BC584: d02c2174                 stb     %o0, [%l0+0x174]
F00BC588: d0042108                 ld      [%l0+0x108], %o0! id
F00BC58C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00BC590: 4000d4b8                 call    _objc_msgSend
F00BC594: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00BC598: 81c7e008                 ret
F00BC59C: 81e80000                 restore
