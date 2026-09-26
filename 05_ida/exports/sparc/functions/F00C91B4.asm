F00C91B4: 9de3bf90                 save    %sp, -0x70, %sp
F00C91B8: 110008c8a4122324         set     0x232324, %l2
F00C91C0: 110008c8ac122323         set     0x232323, %l6
F00C91C8: 110008c8aa122325         set     0x232325, %l5
F00C91D0: 110008c8a8122336         set     0x232336, %l4
F00C91D8: 113ff737a61220db         set     -0x232325, %l3
F00C91E0: 90100018                 mov     %i0, %o0! id
F00C91E4: 133c0506                 sethi   %hi(paWaitforinterru), %o1
F00C91E8: d20260a8                 ld      [%o1+%lo(paWaitforinterru)], %o1! SEL
F00C91EC: 4000a1a1                 call    _objc_msgSend
F00C91F0: 9407bff4                 add     %fp, var_C, %o2
F00C91F4: a2100008                 mov     %o0, %l1
F00C91F8: 80a47d1f                 cmp     %l1, -0x2E1
F00C91FC: 12800005                 bne     loc_F00C9210
F00C9200: 80a46000                 cmp     %l1, 0
F00C9204: 113c0506                 sethi   %hi(paReceivemsg), %o0
F00C9208: 1080002a                 ba      loc_F00C92B0
F00C920C: d20220a4                 ld      [%o0+%lo(paReceivemsg)], %o1
F00C9210: 02800012                 be      loc_F00C9258
F00C9214: 113c0504                 sethi   %hi(paName), %o0! id
F00C9218: d2022008                 ld      [%o0+%lo(paName)], %o1! SEL
F00C921C: 4000a195                 call    _objc_msgSend
F00C9220: 90100018                 mov     %i0, %o0! id
F00C9224: 133c0506                 sethi   %hi(paDevicekind_0), %o1
F00C9228: a0100008                 mov     %o0, %l0
F00C922C: d20261d0                 ld      [%o1+%lo(paDevicekind_0)], %o1! SEL
F00C9230: 4000a190                 call    _objc_msgSend
F00C9234: 90100018                 mov     %i0, %o0
F00C9238: 133c03ec                 sethi   %hi(aSSThreadWaitfo), %o1! "%s: %s thread: waitForInterrupt: return"...
F00C923C: 94100008                 mov     %o0, %o2
F00C9240: 90126038                 or      %o1, %lo(aSSThreadWaitfo), %o0! "%s: %s thread: waitForInterrupt: return"...
F00C9244: 92100010                 mov     %l0, %o1
F00C9248: 7ffff3ab                 call    _IOLog
F00C924C: 96100011                 mov     %l1, %o3
F00C9250: 10bfffe5                 ba      loc_F00C91E4
F00C9254: 90100018                 mov     %i0, %o0
F00C9258: d007bff4                 ld      [%fp+var_C], %o0
F00C925C: 80a20012                 cmp     %o0, %l2
F00C9260: 22800010                 be,a    loc_F00C92A0
F00C9264: 113c0506                 sethi   -0xFEBE800, %o0
F00C9268: 14800007                 bg      loc_F00C9284
F00C926C: 80a20015                 cmp     %o0, %l5
F00C9270: 80a20016                 cmp     %o0, %l6
F00C9274: 02800009                 be      loc_F00C9298
F00C9278: 113c0506                 sethi   -0xFEBE800, %o0
F00C927C: 10800015                 ba      loc_F00C92D0
F00C9280: d607bff4                 ld      [%fp+var_C], %o3
F00C9284: 02800009                 be      loc_F00C92A8
F00C9288: 80a20014                 cmp     %o0, %l4
F00C928C: 0280000d                 be      loc_F00C92C0
F00C9290: d607bff4                 ld      [%fp+var_C], %o3
F00C9294: 3080000f                 ba,a    loc_F00C92D0
F00C9298: 10800006                 ba      loc_F00C92B0
F00C929C: d20220a0                 ld      [%o0+0xA0], %o1
F00C92A0: 10800004                 ba      loc_F00C92B0
F00C92A4: d202209c                 ld      [%o0+0x9C], %o1
F00C92A8: 113c0506                 sethi   %hi(paInterruptoccur_0), %o0! id
F00C92AC: d2022098                 ld      [%o0+%lo(paInterruptoccur_0)], %o1! SEL
F00C92B0: 4000a170                 call    _objc_msgSend
F00C92B4: 90100018                 mov     %i0, %o0
F00C92B8: 10bfffcb                 ba      loc_F00C91E4
F00C92BC: 90100018                 mov     %i0, %o0
F00C92C0: 400003d7                 call    _IOExitThread
F00C92C4: 01000000                 nop
F00C92C8: 10bfffc7                 ba      loc_F00C91E4
F00C92CC: 90100018                 mov     %i0, %o0! id
F00C92D0: 9402c013                 add     %o3, %l3, %o2
F00C92D4: 80a2a00f                 cmp     %o2, 0xF
F00C92D8: 18800007                 bgu     loc_F00C92F4
F00C92DC: 133c0506                 sethi   %hi(paInterruptoccur), %o1
F00C92E0: d20260e0                 ld      [%o1+%lo(paInterruptoccur)], %o1! SEL
F00C92E4: 4000a163                 call    _objc_msgSend
F00C92E8: 90100018                 mov     %i0, %o0
F00C92EC: 10bfffbe                 ba      loc_F00C91E4
F00C92F0: 90100018                 mov     %i0, %o0
F00C92F4: 90100018                 mov     %i0, %o0! id
F00C92F8: 133c0506                 sethi   %hi(paOtheroccurred), %o1
F00C92FC: d2026094                 ld      [%o1+%lo(paOtheroccurred)], %o1! SEL
F00C9300: 4000a15c                 call    _objc_msgSend
F00C9304: 9410000b                 mov     %o3, %o2
F00C9308: 10bfffb7                 ba      loc_F00C91E4
F00C930C: 90100018                 mov     %i0, %o0
