F00BD294: 9de3bf90                 save    %sp, -0x70, %sp
F00BD298: d0062120                 ld      [%i0+0x120], %o0! id
F00BD29C: 133c0504                 sethi   %hi(paBecomeowner), %o1
F00BD2A0: d2026264                 ld      [%o1+%lo(paBecomeowner)], %o1! SEL
F00BD2A4: 4000d173                 call    _objc_msgSend
F00BD2A8: 94100018                 mov     %i0, %o2
F00BD2AC: 94920000                 orcc    %o0, %g0, %o2
F00BD2B0: 0280000a                 be      loc_F00BD2D8
F00BD2B4: 90100018                 mov     %i0, %o0! id
F00BD2B8: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00BD2BC: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1! SEL
F00BD2C0: 213c0481                 sethi   %hi(aKmCanbecomeown), %l0! "km canBecomeOwner: becomeOwner failed ("...
F00BD2C4: 4000d16b                 call    _objc_msgSend
F00BD2C8: a0142020                 bset    %lo(aKmCanbecomeown), %l0! "km canBecomeOwner: becomeOwner failed ("...
F00BD2CC: 92100008                 mov     %o0, %o1
F00BD2D0: 40002389                 call    _IOLog
F00BD2D4: 90100010                 mov     %l0, %o0
F00BD2D8: 133c0481                 sethi   %hi(word_F0120418), %o1
F00BD2DC: d0526018                 ldsh    [%o1+%lo(word_F0120418)], %o0
F00BD2E0: 80a22000                 cmp     %o0, 0
F00BD2E4: 32800041                 bne,a   loc_F00BD3E8
F00BD2E8: 113c0481                 sethi   -0xFEDFC00, %o0
F00BD2EC: a2102001                 mov     1, %l1
F00BD2F0: 113c0506                 sethi   %hi(paIoconfigtable), %o0
F00BD2F4: e0022298                 ld      [%o0+%lo(paIoconfigtable)], %l0
F00BD2F8: e2326018                 sth     %l1, [%o1+%lo(word_F0120418)]
F00BD2FC: 113c0504                 sethi   %hi(paNewfromsystemc), %o0! id
F00BD300: d2022274                 ld      [%o0+%lo(paNewfromsystemc)], %o1! SEL
F00BD304: 4000d15b                 call    _objc_msgSend
F00BD308: 90100010                 mov     %l0, %o0! id
F00BD30C: a6100008                 mov     %o0, %l3
F00BD310: 133c0504                 sethi   %hi(paValueforstring), %o1
F00BD314: 153c0481                 sethi   %hi(aShutdownGraphi), %o2! "Shutdown Graphics"
F00BD318: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00BD31C: 4000d155                 call    _objc_msgSend
F00BD320: 9412a050                 bset    %lo(aShutdownGraphi), %o2! "Shutdown Graphics"
F00BD324: a4920000                 orcc    %o0, %g0, %l2
F00BD328: 0280000e                 be      loc_F00BD360
F00BD32C: 133c0481                 sethi   %hi(aNo), %o1! "No"
F00BD330: 7ffd2b9f                 call    _strcmp
F00BD334: 92126068                 bset    %lo(aNo), %o1! "No"
F00BD338: 80a22000                 cmp     %o0, 0
F00BD33C: 12800005                 bne     loc_F00BD350
F00BD340: 90100010                 mov     %l0, %o0
F00BD344: 113c0481                 sethi   %hi(word_F012041A), %o0
F00BD348: e232201a                 sth     %l1, [%o0+%lo(word_F012041A)]
F00BD34C: 90100010                 mov     %l0, %o0! id
F00BD350: 133c0504                 sethi   %hi(paFreestring), %o1
F00BD354: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00BD358: 4000d146                 call    _objc_msgSend
F00BD35C: 94100012                 mov     %l2, %o2
F00BD360: 90100013                 mov     %l3, %o0! id
F00BD364: 133c0504                 sethi   %hi(paValueforstring), %o1
F00BD368: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00BD36C: 153c0481                 sethi   %hi(aLanguage), %o2! "Language"
F00BD370: 4000d140                 call    _objc_msgSend
F00BD374: 9412a070                 bset    %lo(aLanguage), %o2! "Language"
F00BD378: a4920000                 orcc    %o0, %g0, %l2
F00BD37C: 22800017                 be,a    loc_F00BD3D8
F00BD380: 113c0503                 sethi   -0xFEBF400, %o0! __s1
F00BD384: a0102000                 mov     0, %l0
F00BD388: 113c0480a81223bc         set     unk_F01203BC, %l4
F00BD390: a2102000                 mov     0, %l1
F00BD394: d2044014                 ld      [%l1+%l4], %o1! __s2
F00BD398: 7ffd2b85                 call    _strcmp
F00BD39C: 90100012                 mov     %l2, %o0
F00BD3A0: 80a22000                 cmp     %o0, 0
F00BD3A4: 22800027                 be,a    loc_F00BD440
F00BD3A8: 113c04fd                 sethi   -0xFEC0C00, %o0
F00BD3AC: a0042001                 inc     %l0
F00BD3B0: 80a42006                 cmp     %l0, 6
F00BD3B4: 04bffff8                 ble     loc_F00BD394
F00BD3B8: a2046004                 inc     4, %l1
F00BD3BC: 113c0506                 sethi   %hi(paIoconfigtable), %o0
F00BD3C0: d0022298                 ld      [%o0+%lo(paIoconfigtable)], %o0! id
F00BD3C4: 133c0504                 sethi   %hi(paFreestring), %o1
F00BD3C8: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00BD3CC: 4000d129                 call    _objc_msgSend
F00BD3D0: 94100012                 mov     %l2, %o2
F00BD3D4: 113c0503                 sethi   -0xFEBF400, %o0! id
F00BD3D8: d20223fc                 ld      [%o0+0x3FC], %o1! SEL
F00BD3DC: 4000d125                 call    _objc_msgSend
F00BD3E0: 90100013                 mov     %l3, %o0
F00BD3E4: 113c0481                 sethi   -0xFEDFC00, %o0
F00BD3E8: d052201a                 ldsh    [%o0+0x1A], %o0
F00BD3EC: 80a22000                 cmp     %o0, 0
F00BD3F0: 02800003                 be      loc_F00BD3FC
F00BD3F4: 113c04f7                 sethi   %hi(_prettyShutdown), %o0
F00BD3F8: c03221e8                 clrh    [%o0+%lo(_prettyShutdown)]
F00BD3FC: 113c04c8                 sethi   %hi(dword_F0132064), %o0
F00BD400: d4022064                 ld      [%o0+%lo(dword_F0132064)], %o2
F00BD404: 80a2a000                 cmp     %o2, 0
F00BD408: 02800008                 be      loc_F00BD428
F00BD40C: 113c0504                 sethi   -0xFEBF000, %o0
F00BD410: 113c04f7                 sethi   %hi(_prettyShutdown), %o0
F00BD414: d05221e8                 ldsh    [%o0+%lo(_prettyShutdown)], %o0
F00BD418: 80a22000                 cmp     %o0, 0
F00BD41C: 2280000b                 be,a    loc_F00BD448
F00BD420: 113c0504                 sethi   -0xFEBF000, %o0
F00BD424: 113c0504                 sethi   -0xFEBF000, %o0! id
F00BD428: d2022278                 ld      [%o0+0x278], %o1! SEL
F00BD42C: 4000d111                 call    _objc_msgSend
F00BD430: 90100018                 mov     %i0, %o0
F00BD434: 113c04fd                 sethi   %hi(_basicConsole), %o0
F00BD438: 10800007                 ba      loc_F00BD454
F00BD43C: d0022228                 ld      [%o0+%lo(_basicConsole)], %o0! id
F00BD440: 10bfffdf                 ba      loc_F00BD3BC
F00BD444: e0222248                 st      %l0, [%o0+0x248]
F00BD448: d202227c                 ld      [%o0+0x27C], %o1! SEL
F00BD44C: 4000d109                 call    _objc_msgSend
F00BD450: 9010000a                 mov     %o2, %o0
F00BD454: d026210c                 st      %o0, [%i0+0x10C]
F00BD458: 113c04f7                 sethi   %hi(_prettyShutdown), %o0
F00BD45C: d05221e8                 ldsh    [%o0+%lo(_prettyShutdown)], %o0
F00BD460: 80a22000                 cmp     %o0, 0
F00BD464: 12800003                 bne     loc_F00BD470
F00BD468: 90102002                 mov     2, %o0
F00BD46C: 90102001                 mov     1, %o0
F00BD470: 400006aa                 call    _FBAllocateConsole
F00BD474: d0262114                 st      %o0, [%i0+0x114]
F00BD478: 80a22000                 cmp     %o0, 0
F00BD47C: 12800005                 bne     loc_F00BD490
F00BD480: d026210c                 st      %o0, [%i0+0x10C]
F00BD484: 113c04fd                 sethi   %hi(_basicConsole), %o0
F00BD488: d0022228                 ld      [%o0+%lo(_basicConsole)], %o0
F00BD48C: d026210c                 st      %o0, [%i0+0x10C]
F00BD490: d006210c                 ld      [%i0+0x10C], %o0
F00BD494: d2062114                 ld      [%i0+0x114], %o1
F00BD498: 173c047f                 sethi   %hi(_mach_title), %o3
F00BD49C: d802e274                 ld      [%o3+%lo(_mach_title)], %o4
F00BD4A0: 94102001                 mov     1, %o2
F00BD4A4: da022004                 ld      [%o0+4], %o5
F00BD4A8: 9fc34000                 call    %o5
F00BD4AC: 96102001                 mov     1, %o3
F00BD4B0: 90100018                 mov     %i0, %o0! id
F00BD4B4: 133c0504                 sethi   %hi(paDrawgraphicpan), %o1
F00BD4B8: d2026230                 ld      [%o1+%lo(paDrawgraphicpan)], %o1! SEL
F00BD4BC: 4000d0ed                 call    _objc_msgSend
F00BD4C0: 94102001                 mov     1, %o2
F00BD4C4: 113c04f7                 sethi   %hi(_prettyShutdown), %o0
F00BD4C8: d05221e8                 ldsh    [%o0+%lo(_prettyShutdown)], %o0
F00BD4CC: 80a22001                 cmp     %o0, 1
F00BD4D0: 02800006                 be      loc_F00BD4E8
F00BD4D4: 80a22002                 cmp     %o0, 2
F00BD4D8: 0280000a                 be      loc_F00BD500
F00BD4DC: 90100018                 mov     %i0, %o0
F00BD4E0: 1080000d                 ba      loc_F00BD514
F00BD4E4: 133c0504                 sethi   -0xFEBF000, %o1
F00BD4E8: 90100018                 mov     %i0, %o0! id
F00BD4EC: 133c0504                 sethi   %hi(paGraphicpanelst), %o1
F00BD4F0: d2026234                 ld      [%o1+%lo(paGraphicpanelst)], %o1
F00BD4F4: 153c0481                 sethi   %hi(aRestartingTheC), %o2! "Restarting the computer...\n"
F00BD4F8: 1080000a                 ba      loc_F00BD520
F00BD4FC: 9412a080                 bset    %lo(aRestartingTheC), %o2! "Restarting the computer...\n"
F00BD500: 133c0504                 sethi   %hi(paGraphicpanelst), %o1
F00BD504: d2026234                 ld      [%o1+%lo(paGraphicpanelst)], %o1
F00BD508: 153c0481                 sethi   %hi(aPleaseWaitUnti_0), %o2! "Please wait until it's safe\nto turn of"...
F00BD50C: 10800005                 ba      loc_F00BD520
F00BD510: 9412a0a0                 bset    %lo(aPleaseWaitUnti_0), %o2! "Please wait until it's safe\nto turn of"...
F00BD514: d2026234                 ld      [%o1+0x234], %o1! SEL
F00BD518: 153c04819412a0d8         set     aPleaseWait, %o2! "Please wait..."
F00BD520: 4000d0d4                 call    _objc_msgSend
F00BD524: 01000000                 nop
F00BD528: 90100018                 mov     %i0, %o0! id
F00BD52C: 133c0504                 sethi   %hi(paAnimationctl), %o1
F00BD530: d202621c                 ld      [%o1+%lo(paAnimationctl)], %o1! SEL
F00BD534: 4000d0cf                 call    _objc_msgSend
F00BD538: 94102002                 mov     2, %o2
F00BD53C: 81c7e008                 ret
F00BD540: 91e82000                 restore %g0, 0, %o0
