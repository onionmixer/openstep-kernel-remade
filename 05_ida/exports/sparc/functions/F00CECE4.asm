F00CECE4: 9de3bf90                 save    %sp, -0x70, %sp
F00CECE8: a2100018                 mov     %i0, %l1
F00CECEC: 90100011                 mov     %l1, %o0! id
F00CECF0: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CECF4: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CECF8: 40008ade                 call    _objc_msgSend
F00CECFC: 94102000                 mov     0, %o2
F00CED00: a0100008                 mov     %o0, %l0
F00CED04: c0240000                 clr     [%l0]
F00CED08: f4242004                 st      %i2, [%l0+4]
F00CED0C: f6242008                 st      %i3, [%l0+8]
F00CED10: 7fffed4c                 call    _IOVmTaskSelf
F00CED14: f824200c                 st      %i4, [%l0+0xC]
F00CED18: d0242010                 st      %o0, [%l0+0x10]
F00CED1C: 90100011                 mov     %l1, %o0! id
F00CED20: 133c0505                 sethi   %hi(paEnqueuesdbuf), %o1
F00CED24: 94100010                 mov     %l0, %o2
F00CED28: d6042020                 ld      [%l0+0x20], %o3
F00CED2C: 19200000                 sethi   0x80000000, %o4
F00CED30: d20263d0                 ld      [%o1+%lo(paEnqueuesdbuf)], %o1! SEL
F00CED34: 9612c00c                 bset    %o4, %o3
F00CED38: 19100000                 sethi   0x40000000, %o4
F00CED3C: 9612c00c                 bset    %o4, %o3
F00CED40: 40008acc                 call    _objc_msgSend
F00CED44: d6242020                 st      %o3, [%l0+0x20]
F00CED48: b0100008                 mov     %o0, %i0
F00CED4C: 90100011                 mov     %l1, %o0! id
F00CED50: 133c0505                 sethi   %hi(paFreesdbuf), %o1
F00CED54: d20263cc                 ld      [%o1+%lo(paFreesdbuf)], %o1! SEL
F00CED58: 40008ac6                 call    _objc_msgSend
F00CED5C: 94100010                 mov     %l0, %o2
F00CED60: 81c7e008                 ret
F00CED64: 81e80000                 restore
