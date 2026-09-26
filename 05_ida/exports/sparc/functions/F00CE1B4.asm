F00CE1B4: 9de3bf90                 save    %sp, -0x70, %sp
F00CE1B8: a2100018                 mov     %i0, %l1
F00CE1BC: 90100011                 mov     %l1, %o0! id
F00CE1C0: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CE1C4: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CE1C8: 40008daa                 call    _objc_msgSend
F00CE1CC: 94102000                 mov     0, %o2
F00CE1D0: a0100008                 mov     %o0, %l0
F00CE1D4: 90102003                 mov     3, %o0
F00CE1D8: d0240000                 st      %o0, [%l0]
F00CE1DC: f4242014                 st      %i2, [%l0+0x14]
F00CE1E0: f624200c                 st      %i3, [%l0+0xC]
F00CE1E4: f8242010                 st      %i4, [%l0+0x10]
F00CE1E8: c0242018                 clr     [%l0+0x18]
F00CE1EC: 90100011                 mov     %l1, %o0! id
F00CE1F0: 133c0505                 sethi   %hi(paEnqueuesdbuf), %o1
F00CE1F4: 94100010                 mov     %l0, %o2
F00CE1F8: d8042020                 ld      [%l0+0x20], %o4
F00CE1FC: 17200000                 sethi   0x80000000, %o3
F00CE200: d20263d0                 ld      [%o1+%lo(paEnqueuesdbuf)], %o1! SEL
F00CE204: 962b000b                 andn    %o4, %o3, %o3
F00CE208: 40008d9a                 call    _objc_msgSend
F00CE20C: d6242020                 st      %o3, [%l0+0x20]
F00CE210: b0100008                 mov     %o0, %i0
F00CE214: 90100011                 mov     %l1, %o0! id
F00CE218: 133c0505                 sethi   %hi(paFreesdbuf), %o1
F00CE21C: d20263cc                 ld      [%o1+%lo(paFreesdbuf)], %o1! SEL
F00CE220: 40008d94                 call    _objc_msgSend
F00CE224: 94100010                 mov     %l0, %o2
F00CE228: 81c7e008                 ret
F00CE22C: 81e80000                 restore
