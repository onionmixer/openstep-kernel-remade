F00E99B0: 9de3bf78                 save    %sp, -0x88, %sp
F00E99B4: f027bff0                 st      %i0, [%fp+var_10.receiver]
F00E99B8: a207bff0                 add     %fp, var_10, %l1
F00E99BC: 90100011                 mov     %l1, %o0! objc_super *
F00E99C0: 133c0508                 sethi   %hi(stru_F014236C.super_class), %o1
F00E99C4: e0026370                 ld      [%o1+%lo(stru_F014236C.super_class)], %l0
F00E99C8: 9410001a                 mov     %i2, %o2
F00E99CC: 133c0504                 sethi   %hi(paInitfromdevice), %o1
F00E99D0: d20262fc                 ld      [%o1+%lo(paInitfromdevice)], %o1! SEL
F00E99D4: 40001fea                 call    _objc_msgSendSuper
F00E99D8: e027bff4                 st      %l0, [%fp+var_10.super_class]
F00E99DC: 80a22000                 cmp     %o0, 0
F00E99E0: 02800015                 be      loc_F00E9A34
F00E99E4: 133c03f2                 sethi   %hi(aDisplayD), %o1! "Display%d"
F00E99E8: a207bfd8                 add     %fp, var_28, %l1
F00E99EC: 90100011                 mov     %l1, %o0! char *
F00E99F0: 213c04bb                 sethi   %hi(dword_F012EF7C), %l0
F00E99F4: d404237c                 ld      [%l0+%lo(dword_F012EF7C)], %o2
F00E99F8: 7ffcab5c                 call    _sprintf
F00E99FC: 92126380                 bset    %lo(aDisplayD), %o1! "Display%d"
F00E9A00: 90100018                 mov     %i0, %o0! id
F00E9A04: d404237c                 ld      [%l0+%lo(dword_F012EF7C)], %o2
F00E9A08: 133c0504                 sethi   %hi(paSetunit), %o1
F00E9A0C: d2026248                 ld      [%o1+%lo(paSetunit)], %o1! SEL
F00E9A10: 9602a001                 add     %o2, 1, %o3
F00E9A14: 40001f97                 call    _objc_msgSend
F00E9A18: d624237c                 st      %o3, [%l0+%lo(dword_F012EF7C)]
F00E9A1C: 90100018                 mov     %i0, %o0! id
F00E9A20: 133c0504                 sethi   %hi(paSetname), %o1
F00E9A24: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00E9A28: 40001f92                 call    _objc_msgSend
F00E9A2C: 94100011                 mov     %l1, %o2
F00E9A30: 30800008                 ba,a    locret_F00E9A50
F00E9A34: f027bff0                 st      %i0, [%fp+var_10.receiver]
F00E9A38: 113c0503                 sethi   %hi(paFree), %o0! objc_super *
F00E9A3C: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00E9A40: e027bff4                 st      %l0, [%fp+var_10.super_class]
F00E9A44: 40001fce                 call    _objc_msgSendSuper
F00E9A48: 90100011                 mov     %l1, %o0
F00E9A4C: b0100008                 mov     %o0, %i0
F00E9A50: 81c7e008                 ret
F00E9A54: 81e80000                 restore
