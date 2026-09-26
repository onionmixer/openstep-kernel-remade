F00C0074: 9de3bf90                 save    %sp, -0x70, %sp
F00C0078: f027bff0                 st      %i0, [%fp+var_10.receiver]
F00C007C: a607bff0                 add     %fp, var_10, %l3
F00C0080: 90100013                 mov     %l3, %o0! objc_super *
F00C0084: 133c0507                 sethi   %hi(stru_F0141D2C.ext), %o1
F00C0088: e4026158                 ld      [%o1+%lo(stru_F0141D2C.ext)], %l2
F00C008C: 9410001a                 mov     %i2, %o2
F00C0090: 133c0504                 sethi   %hi(paBecomeowner), %o1! SEL
F00C0094: e2026264                 ld      [%o1+%lo(paBecomeowner)], %l1
F00C0098: e427bff4                 st      %l2, [%fp+var_10.super_class]
F00C009C: 4000c638                 call    _objc_msgSendSuper
F00C00A0: 92100011                 mov     %l1, %o1
F00C00A4: a0100008                 mov     %o0, %l0
F00C00A8: 113c0504                 sethi   %hi(paOwnerlock), %o0! id
F00C00AC: d20222b0                 ld      [%o0+%lo(paOwnerlock)], %o1! SEL
F00C00B0: 4000c5f0                 call    _objc_msgSend
F00C00B4: 90100018                 mov     %i0, %o0! id
F00C00B8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C00BC: 4000c5ed                 call    _objc_msgSend
F00C00C0: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C00C4: 80a42000                 cmp     %l0, 0
F00C00C8: 12800022                 bne     loc_F00C0150
F00C00CC: 113c0504                 sethi   -0xFEBF000, %o0
F00C00D0: d04e2130                 ldsb    [%i0+0x130], %o0
F00C00D4: 80a22000                 cmp     %o0, 0
F00C00D8: 1280001e                 bne     loc_F00C0150
F00C00DC: 113c0504                 sethi   -0xFEBF000, %o0
F00C00E0: d006212c                 ld      [%i0+0x12C], %o0! id
F00C00E4: 92100011                 mov     %l1, %o1! SEL
F00C00E8: 4000c5e2                 call    _objc_msgSend
F00C00EC: 94100018                 mov     %i0, %o2
F00C00F0: 80a22000                 cmp     %o0, 0
F00C00F4: 32800008                 bne,a   loc_F00C0114
F00C00F8: d006212c                 ld      [%i0+0x12C], %o0
F00C00FC: 90102001                 mov     1, %o0
F00C0100: d02e2130                 stb     %o0, [%i0+0x130]
F00C0104: 133c0482                 sethi   %hi(_wserver_on), %o1
F00C0108: 90102001                 mov     1, %o0! id
F00C010C: 10800010                 ba      loc_F00C014C
F00C0110: d02262ec                 st      %o0, [%o1+%lo(_wserver_on)]
F00C0114: 133c0504                 sethi   %hi(paDesireownershi), %o1
F00C0118: d2026268                 ld      [%o1+%lo(paDesireownershi)], %o1! SEL
F00C011C: 4000c5d5                 call    _objc_msgSend
F00C0120: 94100018                 mov     %i0, %o2
F00C0124: 80a22000                 cmp     %o0, 0
F00C0128: 02800009                 be      loc_F00C014C
F00C012C: 9410001a                 mov     %i2, %o2
F00C0130: f027bff0                 st      %i0, [%fp+var_10.receiver]
F00C0134: e427bff4                 st      %l2, [%fp+var_10.super_class]
F00C0138: 90100013                 mov     %l3, %o0! objc_super *
F00C013C: 133c0504                 sethi   %hi(paRelinquishowne_0), %o1
F00C0140: d20262b8                 ld      [%o1+%lo(paRelinquishowne_0)], %o1! SEL
F00C0144: 4000c60e                 call    _objc_msgSendSuper
F00C0148: a0103d2b                 mov     -0x2D5, %l0
F00C014C: 113c0504                 sethi   -0xFEBF000, %o0! id
F00C0150: d20222b0                 ld      [%o0+0x2B0], %o1! SEL
F00C0154: 4000c5c7                 call    _objc_msgSend
F00C0158: 90100018                 mov     %i0, %o0! id
F00C015C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C0160: 4000c5c4                 call    _objc_msgSend
F00C0164: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C0168: 81c7e008                 ret
F00C016C: 91e80010                 restore %g0, %l0, %o0
