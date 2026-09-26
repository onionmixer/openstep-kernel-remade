F00C496C: 9de3bf90                 save    %sp, -0x70, %sp
F00C4970: 40000570                 call    _IOMalloc
F00C4974: 9010201c                 mov     0x1C, %o0
F00C4978: a0100008                 mov     %o0, %l0
F00C497C: f4240000                 st      %i2, [%l0]
F00C4980: 90103fff                 mov     -1, %o0
F00C4984: d024200c                 st      %o0, [%l0+0xC]
F00C4988: d0242008                 st      %o0, [%l0+8]
F00C498C: 113c04cc                 sethi   %hi(dword_F013304C), %o0
F00C4990: d002204c                 ld      [%o0+%lo(dword_F013304C)], %o0! id
F00C4994: 133c0504                 sethi   %hi(paLock), %o1
F00C4998: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00C499C: 4000b3b5                 call    _objc_msgSend
F00C49A0: c0242010                 clr     [%l0+0x10]
F00C49A4: 133c04cc                 sethi   %hi(dword_F0133040), %o1
F00C49A8: d4026040                 ld      [%o1+%lo(dword_F0133040)], %o2
F00C49AC: 9002a001                 add     %o2, 1, %o0
F00C49B0: d0226040                 st      %o0, [%o1+%lo(dword_F0133040)]
F00C49B4: d4242004                 st      %o2, [%l0+4]
F00C49B8: 153c04cc                 sethi   %hi(dword_F0133044), %o2
F00C49BC: d002a044                 ld      [%o2+%lo(dword_F0133044)], %o0
F00C49C0: 9212a044                 or      %o2, %lo(dword_F0133044), %o1
F00C49C4: 80a20009                 cmp     %o0, %o1
F00C49C8: 32800007                 bne,a   loc_F00C49E4
F00C49CC: d0026004                 ld      [%o1+4], %o0
F00C49D0: e022a044                 st      %l0, [%o2+%lo(dword_F0133044)]
F00C49D4: e0226004                 st      %l0, [%o1+4]
F00C49D8: d2242014                 st      %o1, [%l0+0x14]
F00C49DC: 10800006                 ba      loc_F00C49F4
F00C49E0: d2242018                 st      %o1, [%l0+0x18]
F00C49E4: d0242018                 st      %o0, [%l0+0x18]
F00C49E8: d2242014                 st      %o1, [%l0+0x14]
F00C49EC: e0226004                 st      %l0, [%o1+4]
F00C49F0: e0222014                 st      %l0, [%o0+0x14]
F00C49F4: 113c04cc                 sethi   %hi(dword_F013304C), %o0
F00C49F8: d002204c                 ld      [%o0+%lo(dword_F013304C)], %o0! id
F00C49FC: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C4A00: 4000b39c                 call    _objc_msgSend
F00C4A04: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C4A08: 81c7e008                 ret
F00C4A0C: 81e80000                 restore
