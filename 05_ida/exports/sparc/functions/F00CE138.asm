F00CE138: 9de3bf90                 save    %sp, -0x70, %sp
F00CE13C: a2100018                 mov     %i0, %l1
F00CE140: 90100011                 mov     %l1, %o0! id
F00CE144: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CE148: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CE14C: 40008dc9                 call    _objc_msgSend
F00CE150: 94102000                 mov     0, %o2
F00CE154: a0100008                 mov     %o0, %l0
F00CE158: 90102002                 mov     2, %o0
F00CE15C: d0240000                 st      %o0, [%l0]
F00CE160: f4242014                 st      %i2, [%l0+0x14]
F00CE164: f624200c                 st      %i3, [%l0+0xC]
F00CE168: f8242010                 st      %i4, [%l0+0x10]
F00CE16C: c0242018                 clr     [%l0+0x18]
F00CE170: 90100011                 mov     %l1, %o0! id
F00CE174: 133c0505                 sethi   %hi(paEnqueuesdbuf), %o1
F00CE178: 94100010                 mov     %l0, %o2
F00CE17C: d8042020                 ld      [%l0+0x20], %o4
F00CE180: 17200000                 sethi   0x80000000, %o3
F00CE184: d20263d0                 ld      [%o1+%lo(paEnqueuesdbuf)], %o1! SEL
F00CE188: 962b000b                 andn    %o4, %o3, %o3
F00CE18C: 40008db9                 call    _objc_msgSend
F00CE190: d6242020                 st      %o3, [%l0+0x20]
F00CE194: b0100008                 mov     %o0, %i0
F00CE198: 90100011                 mov     %l1, %o0! id
F00CE19C: 133c0505                 sethi   %hi(paFreesdbuf), %o1
F00CE1A0: d20263cc                 ld      [%o1+%lo(paFreesdbuf)], %o1! SEL
F00CE1A4: 40008db3                 call    _objc_msgSend
F00CE1A8: 94100010                 mov     %l0, %o2
F00CE1AC: 81c7e008                 ret
F00CE1B0: 81e80000                 restore
